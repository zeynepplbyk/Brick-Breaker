## 🧱 Brick Breaker - Mikrodenetleyici Tabanlı Oyun Makinesi


---

## 🎯 Proje Özeti
Bu projenin amacı, bir mikrodenetleyici tabanlı oyun makinesi geliştirmektir. Oyuncu, özel bir fiziksel **palet kontrol cihazı** ile topu yönlendirerek OLED ekranda bulunan tuğlaları kırmayı hedefler.  

Oyun mekanikleri:
- Top, palet, tuğlalar ve duvarlara çarptığında yön değiştirir.  
- Oyuncunun amacı, tuğlaları kırarak puan kazanmaktır.  
- Skor, 7 segment display üzerinde gösterilir.  
- Oyuncunun 3 canı vardır; canlar LED ile gösterilir.  
- Tuğlalar kırıldığında %10 şansla obje düşer ve paletle yakalanırsa can artar.  
- Tüm tuğlalar kırıldığında 5 saniyelik ara ekran sonrası yeni bölüm başlar, top hızı %20 artar.  
- Işık sensörüne göre arka plan ve tuğlalar ters renkli gösterilebilir.  

---

## 🕹️ Oyun Mekaniği

### Başlatma ve Kontrol
- "Başlat" tuşuna basıldığında oyun ekranı açılır ve oyun başlar.  
- Potansiyometre ile paletin sağa ve sola hareketi kontrol edilir.  

### Top ve Tuğlalar
- Top, çarpma mekaniğine göre yön değiştirir.  
- Tuğlalar kırıldığında skor 1 artar ve OLED ekranda tuğla kaybolur.  

### Can Sistemi
- Top paletle kurtarılamayıp düşerse, oyuncunun canı 1 azalır.  
- LED’ler ile kalan can sayısı gösterilir.  

### Bölüm ve Hız
- Tüm tuğlalar kırıldığında 5 saniyelik ara ekran gösterilir.  
- Yeni bölümde tuğla düzeni farklıdır ve top hızı önceki turdan %20 daha hızlıdır.  
- Skor önceki turdan devam eder.  

---

## 🛠️ Kullanılan Donanım ve Yazılım

**Donanım:**
- Arduino mikrodenetleyici  
- OLED ekran (oyun alanı için)  
- 7 segment display (skor takibi)  
- LED’ler (can durumu)  
- Potansiyometre (palet kontrol)  

**Yazılım:**
- Arduino IDE  
- Oyun mekaniği, top hareketi, palet kontrolü, tuğla kırılması, skor ve can sistemi kodlandı  
- Başlat/Çıkış tuşları ile temel kullanıcı etkileşimi  

---

## 📊 Deneysel Sonuçlar
- OLED ekran: Başlangıç ve oyun ekranı sorunsuz çalıştı.  
- 7 segment display: Skor doğru gösterildi.  
- LED’ler: Can sayısı doğru şekilde güncellendi.  
- Potansiyometre: Palet kontrolü hassas ve doğru çalıştı.  
- Top hareketi: Çarpma ve yön değiştirme fizik kurallarına uygun çalıştı.  
- Tuğlalar ve skor: Tuğla kırıldığında OLED ve skor göstergesi doğru güncellendi.  
- Bölüm değişimi ve hız artışı doğru çalıştı.  
- Oyunun başlangıç ve bitiş menüleri sorunsuz çalıştı.  

---

## 📌 Sonuç
Bu proje ile mikrodenetleyici tabanlı bir oyun makinesi başarılı bir şekilde geliştirilmiştir. Oyun mekanikleri, elektronik bileşenler ve kontrol sistemi beklenen şekilde çalışmıştır. Bölüm geçişleri, hız artışı, can artırma ve skor mekanikleri sorunsuz uygulanmıştır.  

---

## 📚 Kaynakça
1. [Arduino Dokümantasyonu](https://docs.arduino.cc)  
2. [Wokwi Platformu](https://wokwi.com)  
3. [YouTube - Arduino Brick Breaker Örnek](https://www.youtube.com/watch?v=WhUbsy1s0Vs&t=1280s)  
4. [YouTube - Tuğla Oyunu Geliştirme](https://www.youtube.com/watch?v=SMh4sbidbaA&list=PLFOSdDqm35feuJXiWzI64TAmnLJ0y29-W)  

---

## 🎮 Oyun Akışı
