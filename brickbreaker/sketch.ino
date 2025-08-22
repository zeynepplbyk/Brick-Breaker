#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_SIFIRLA    -1
#define yukseklik_ekran 64
#define genislik_ekran 128

Adafruit_SSD1306 display(genislik_ekran, yukseklik_ekran, &Wire, OLED_SIFIRLA);

#define POT_PIN A0
#define btn_up 11
#define btn_d 12
#define btn_select 13

int EP=46;
int C=47;
int D=48;
int E=49;
int G=50;
int F=51;
int A=52;
int B=53;

#define palet_genislik 30
#define palet_yukseklik 4
#define PALET_Y yukseklik_ekran - 2. //45

#define Ball_r 2
#define tugla_genislik 21
#define tugla_yukseklik 7
#define tugla_sayi 6

#define Can 6 

float hiz_artis_faktoru = 1.2; // Her seviyede hızın %20 artması için
int skor = 0; // Oyunun başında skor sıfırdır

struct Tugla {
  int x;
  int y;
};
struct DusenNesne {
  int x;
  int y;
  bool aktif;
};

DusenNesne dusenNesne;

Tugla tuglalar[tugla_sayi];

int potansiyometre; // Potansiyometre değeri
int paletHizi = 5; // Palet hareket hızı
bool oyunBasladi = false; // Oyun başladı mı kontrol et

int topHizX = 2;
int topHizY = -2;
int topX = genislik_ekran / 2;
int topY = yukseklik_ekran / 2;
int paletX = (genislik_ekran - palet_genislik) / 2;
int baslangicTopHizX = 2;
int baslangicTopHizY = -2;

int canSayisi = Can;

int tugla_kirilan = 0;
int secilenmenu= 0; // menüden komut seç
bool sec = false; // Seçim yapıldı mı kontrol et

void led(int can) {
  if (can == 6) {
    digitalWrite(14, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
  } else if (can == 4) {
    digitalWrite(14, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  } else if (can == 2) {
    digitalWrite(14, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  } else if (can == 0) {
    digitalWrite(14, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
}
void nums(int sayi) 
{
   switch(sayi)
   {
   case 0 :  
     digitalWrite(E,LOW);
     digitalWrite(D,LOW); 
     digitalWrite(C,LOW); 
     digitalWrite(B,LOW); 
     digitalWrite(A,LOW); 
     digitalWrite(F,LOW); 
     digitalWrite(G,HIGH); 
   break;
   case 1:  
     digitalWrite(E,HIGH);
     digitalWrite(D,HIGH); 
     digitalWrite(C,LOW); 
     digitalWrite(B,LOW); 
     digitalWrite(A,HIGH); 
     digitalWrite(F,HIGH); 
     digitalWrite(G,HIGH); 
   break;
   case 2: 
     digitalWrite(E,LOW);
     digitalWrite(D,LOW); 
     digitalWrite(C,HIGH); 
     digitalWrite(B,LOW); 
     digitalWrite(A,LOW); 
     digitalWrite(F,HIGH); 
     digitalWrite(G,LOW); 
   break;
   case 3:  
     digitalWrite(E,HIGH);
     digitalWrite(D,LOW); 
     digitalWrite(C,LOW); 
     digitalWrite(B,LOW); 
     digitalWrite(A,LOW); 
     digitalWrite(F,HIGH); 
     digitalWrite(G,LOW); 
   break;
   case 4:  
     digitalWrite(E,HIGH);
     digitalWrite(D,HIGH); 
     digitalWrite(C,LOW); 
     digitalWrite(B,LOW); 
     digitalWrite(A,HIGH); 
     digitalWrite(F,LOW); 
     digitalWrite(G,LOW); 
   break;
   case 5:  
     digitalWrite(E,HIGH);
     digitalWrite(D,LOW); 
     digitalWrite(C,LOW); 
     digitalWrite(B,HIGH); 
     digitalWrite(A,LOW); 
     digitalWrite(F,LOW); 
     digitalWrite(G,LOW); 
   break;
   case 6: 
     digitalWrite(E,LOW);
     digitalWrite(D,LOW); 
     digitalWrite(C,LOW); 
     digitalWrite(B,HIGH); 
     digitalWrite(A,LOW); 
     digitalWrite(F,LOW); 
     digitalWrite(G,LOW); 
   break;
   case 7: 
     digitalWrite(E,HIGH);
     digitalWrite(D,HIGH); 
     digitalWrite(C,LOW); 
     digitalWrite(B,LOW); 
     digitalWrite(A,LOW); 
     digitalWrite(F,HIGH); 
     digitalWrite(G,HIGH); 
   break;
   case 8: 
     digitalWrite(E,LOW);
     digitalWrite(D,LOW); 
     digitalWrite(C,LOW); 
     digitalWrite(B,LOW); 
     digitalWrite(A,LOW); 
     digitalWrite(F,LOW); 
     digitalWrite(G,LOW); 
   break;
   case 9:  
     digitalWrite(E,HIGH);
     digitalWrite(D,LOW); 
     digitalWrite(C,LOW); 
     digitalWrite(B,LOW); 
     digitalWrite(A,LOW); 
     digitalWrite(F,LOW); 
     digitalWrite(G,LOW); 
   break;
   }
}
void setup() {
   pinMode(E, OUTPUT); 
  pinMode(D, OUTPUT); 
  pinMode(C, OUTPUT);
  pinMode(A, OUTPUT); 
  pinMode(B, OUTPUT);
  pinMode(F, OUTPUT); 
  pinMode(G, OUTPUT); 
  pinMode(EP, OUTPUT); 

  pinMode(14, OUTPUT); // 1. LED
  pinMode(2, OUTPUT); // 2. LED
  pinMode(3, OUTPUT); // 3. LED

  pinMode(btn_up, INPUT_PULLUP);
  pinMode(btn_d, INPUT_PULLUP);
  pinMode(btn_select, INPUT_PULLUP);

  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("fail"));
    for(;;);
  }

  display.display();
  delay(1800);  

  display.clearDisplay();
  display.setTextSize(1);

  display.setTextColor(SSD1306_WHITE);

  display.setCursor(10,10);

  display.println("Tugla Kirma");

  display.setCursor(10,25);

  display.println(">Baslat");

  display.setCursor(10,40);

  display.println("Cik");

  display.display();
  randomSeed(analogRead(0)); 
  TuglaDizayn();
}

void loop() {
    // Potansiyometre değerini oku
  potansiyometre = analogRead(POT_PIN);
  nums(tugla_kirilan); 
  if (!oyunBasladi) {
    menusecim();
  } else {
    // paletin hareket etmesini sağla
    paletX = map(potansiyometre, 0, 1023, 0, genislik_ekran - palet_genislik);
    
    Kontrol_oyun();
    PaletiCiz();
  }
 
}

void OyunBaslat() {
 
  topX = paletX + palet_genislik / 2;
  topY = PALET_Y - Ball_r;
  oyunBasladi = true;

  // Tuğlaların dizaynı
  TuglaDizayn();
// Düşen nesneyi başlat
  dusenNesne.x = tuglalar[0].x + tugla_genislik / 2; // Örnek olarak ilk tuğla pozisyonu
  dusenNesne.y = tuglalar[0].y + tugla_yukseklik; // Tuğlanın altında başlat
  dusenNesne.aktif = false; // Başlangıçta nesne aktif değil

//gerekli düzenlemeleri yap
  display.clearDisplay();
  PaletiCiz();
  TopuCiz();
  TuglaCiz();
  display.display();
}
 

void menusecim() {
  // menü seçimi
  if (digitalRead(btn_up) == LOW) {
    if (secilenmenu > 0) {
      secilenmenu--; 
       SecimGuncelle();
    }
    delay(200); 
  }

  if (digitalRead(btn_d) == LOW) {
    if (secilenmenu < 1) {
      secilenmenu++;
       SecimGuncelle();
    }
    delay(200); 
  }

  if (digitalRead(btn_select) == LOW) {
    sec = true;
  }

  if (sec) {

    if (secilenmenu == 0) {
      OyunBaslat(); //başlarsa
    }
     else if (secilenmenu == 1) {// çıkarsa
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 10);
       display.println("Cikis yaptiniz.");
      display.println("Tesekkurler!");
      display.display();
      while(true);
    }
  }
}


void SecimGuncelle() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10,10);
  display.println("OYUNA HOS GELDINIZ");
  display.setCursor(10,25);

  if (secilenmenu == 0) {
    display.println("> Baslat");
    display.setCursor(10,40);
    display.println("Cik");
  } 
  else if (secilenmenu == 1) {
    display.println("Baslat");
    display.setCursor(10,40);
    display.println("> Cik");
  }

  display.display();
}

void PaletiCiz() {
  display.fillRect(paletX, PALET_Y, palet_genislik, palet_yukseklik, SSD1306_WHITE);
  
  if ((digitalRead(btn_up) == LOW || digitalRead(btn_d) == LOW)&& oyunBasladi) {
    // oyun başladığında top paletin ortasında
    topX = paletX + palet_genislik / 2;
  }
}

void TopuCiz() {
  display.fillCircle(topX, topY, Ball_r, SSD1306_WHITE);
  
}

void TopunHareketi() {
 
  topX += topHizX;
  topY += topHizY;

  if (topX >= genislik_ekran - Ball_r || topX <= Ball_r) {
    topHizX = -topHizX;
  }
  if (topY <= Ball_r) {
    topHizY = -topHizY;
  }
  // topun palette sekmesi
  if (topY >= PALET_Y - Ball_r && topX >= paletX && topX <= paletX + palet_genislik) {
    topHizY = -topHizY;
    topHizY = -abs(topHizY);
  }

  
}

void TuglaCiz() {
  for (int i = 0; i < tugla_sayi; i++) {
    display.fillRect(tuglalar[i].x, tuglalar[i].y, tugla_genislik, tugla_yukseklik, SSD1306_WHITE);
  }
   // Düşen nesneyi çiz
  if (dusenNesne.aktif) {
    display.fillRect(dusenNesne.x, dusenNesne.y, 5, 5, SSD1306_WHITE); // Örneğin 5x5 bir dikdörtgen
  }
}

void TuglaDizayn() {
  int BricksnumPr = 5; // 
  int Rowsnum = (tugla_sayi + BricksnumPr - 1) / BricksnumPr; // Calculate number of rows needed
  
  int bWidthGap = tugla_genislik + 2; // Brick width including gap
  int rHeightGap = tugla_yukseklik + 2; // Row height including gap
  
  int Xstart = (genislik_ekran - BricksnumPr * bWidthGap) / 2; // Starting x position for the bricks
  int Ystart = 10; // Starting y position for the first row of bricks

  // Create an array to track used positions to avoid overlaps
  bool pozisyon[BricksnumPr][Rowsnum] = {false};

  for (int i = 0; i < tugla_sayi; i++) {
    int row, col;
    bool pozisyonbulundu = false;

    // Find a random position that hasn't been used yet
    while (!pozisyonbulundu) {
       row = random(0, Rowsnum); // Random row index
      col = random(0, BricksnumPr); // Random column index
     
      if (!pozisyon[col][row]) {
        pozisyonbulundu = true;
         pozisyon[col][row] = true;
      }
    }

    // Calculate x and y positions for the brick
    int randomX = Xstart + col * bWidthGap;
    int randomY = Ystart + row * rHeightGap;

    // Set brick position
    tuglalar[i].x = randomX;
    tuglalar[i].y = randomY;
  }
}

void toptuglacarp() {
  for (int i = 0; i < tugla_sayi; i++) {
      
    int TuglaSol = tuglalar[i].x;
    int TuglaSag = tuglalar[i].x + tugla_genislik;
    int TuglaUst = tuglalar[i].y;
    int TuglaAlt = tuglalar[i].y + tugla_yukseklik;
  
    int TopSol = topX - Ball_r;
    int TopSag = topX + Ball_r;
    int TopUst = topY - Ball_r;
    int TopAlt = topY + Ball_r;
 
    if (TopSag >= TuglaSol && TopSol <= TuglaSag && TopAlt >= TuglaUst && TopUst <= TuglaAlt) {
     
       tugla_kirilan++;
       skor += 1;
       tuglalar[i].y = -tugla_yukseklik;
      tuglalar[i].x = -tugla_genislik; 
       topHizY = -topHizY;
   
      break; 
    }
  }
}

void Kontrol_oyun() {
  TopunHareketi();

  display.clearDisplay();
  PaletiCiz();
  TopuCiz();
  TuglaCiz();
  display.display();

  // Skoru ekranda göster
  display.setCursor(10, 0);
  display.print("Skor: ");
  display.print(skor); 

// Düşen nesne kontrolü
  if (!dusenNesne.aktif && random(0, 10) == 0) { // %10 şansla nesne düşsün
    dusenNesne.aktif = true;
  }

  if (dusenNesne.aktif) {
    dusenNesne.y++; // Nesneyi aşağı hareket ettir
    if (dusenNesne.y > yukseklik_ekran) {
      dusenNesne.aktif = false; // Nesne ekranın dışına çıktıysa devre dışı bırak
    }
  }
   yanarsa();

  toptuglacarp();

  oyunbittimi();

  led(canSayisi);
  delay(20);
}

void oyunbittimi() {
  if (tugla_kirilan == tugla_sayi) {
    
    display.clearDisplay(); // Ekranı temizleyin
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    
    display.setCursor(10, 10); // Skoru ekranda göster
    display.print("Tum Tuglalar Kirildi.");
    display.println("Tebrikler");
    
    display.setCursor(10, 30); // Son skor bilgisi
    display.print("Son Skor: ");
    display.println(skor);
    
    display.setCursor(10, 50); // Yeni seviyeye geçiş mesajı
    display.println("Yeni seviyeye");
    display.println("geciliyor...");
    
    display.display(); // Değişiklikleri ekranda göster
    
    delay(3000); // Mesajı 3 saniye boyunca göster

    yeniSeviyeBaslat(); // Yeni seviyeyi başlat
  }
}

void yeniSeviyeBaslat() {
  oyunBasladi = true;

  tugla_kirilan = 0;
  TuglaDizayn();

  topX = paletX + palet_genislik / 2;
  topY = PALET_Y - Ball_r;

  // Top hızını %20 artır
  topHizX *= hiz_artis_faktoru;
  topHizY *= hiz_artis_faktoru;

  display.clearDisplay(); 

  PaletiCiz(); 
  TopuCiz(); 
  TuglaCiz(); 

  display.display(); 
  // Değişiklikleri ekranda göster
}

void yanarsa() {
  // top alt trafa giderse
  if (topY >= yukseklik_ekran - Ball_r) {
    canSayisi--;
    topY = PALET_Y - Ball_r;
    topX = paletX + palet_genislik / 2;

    if (canSayisi <= 0) {
      Oyunu_Bitir(); // can yoksa oyun bitsin
    }
  }
}


void Oyunu_Bitir() {
    // Top hızını başlangıç hızlarına geri döndür
  topHizX = baslangicTopHizX;
  topHizY = baslangicTopHizY;
  skor=0;
  oyunBasladi = false; // Oyun durdurulur
  sec = false; // Seçim yapılmadı
  tugla_kirilan = 0; // Kırılan tuğla sayısını sıfırla
  secilenmenu = 0; // Ana menüdeki başlangıç seçimi
  canSayisi = Can; // Canları başlangıç değerine sıfırla
  
  // Oyunun bittiğini belirtin ve ana menüye dönün
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.println("Hic Canin Kalmadi.");
  display.println("Ana Menuye Donuluyor...");
  display.display();

  delay(3000); // Birkaç saniye bekleyin

  SecimGuncelle(); // Ana menüyü göster
}