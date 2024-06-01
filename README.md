# Brick-Breaker

Bu projenin amacı, çeşitli araçlar kullanarak
mikrodenetleyici tabanlı bir oyun makinesi geliştirildi. Oyuncu,
bir fiziksel palet kontrol cihazını kullanarak bir topu yansıtarak
OLED ekrandaki tuğlaları kırmaya çalışacaktır. Oyuncu, özel bir
fiziksel "palet kontrol cihazı" kullanarak oyunu kontrol edecek.
Cihaz, potansiyometreyle yönlendirilecek. OLED ekran, oyun
alanını canlı olarak gösterecek. Oyun alanı, üstte tuğlalar, altta
oyuncunun kontrol ettiği palet ve zıplayan bir top içerecek.
Oyuncunun amacı, topu kullanarak tuğlaları kırmak ve puan
kazanmak olacak. Puan, 7 segment display'de gösterilir. Top,
palet veya duvarlara çarpınca yön değiştirir. Ekranın sağ ve sol
kenarları topun sınırları var. Oyun başarıyla tamamlandığında,
topun önceki hızının %20 daha fazlasıyla bir sonraki oyun
başlayacak. Seviye atlandığında skorbord sıfırlanmayacak ve
önceki puan korunacak. Oyun, topun alt kısmına düşmesiyle
sona erecek. Bu proje, wokwi kullanılarak geliştirildi ve
mikrodenetleyici ve sensörlerin etkin kullanımını içerecek.
Anahtar Kelimeler — Led, 7segment, palet kontrol, tuğla…


## DENEY SONUÇLARI
OLED Ekran: Oyunun başlangıç ekranı, oyun alanı ve
diğer grafikler sorunsuz bir şekilde gösterilmiştir.
Yedi Segment Gösterge: Skor artışını doğru bir şekilde
göstermiştir.
LED'ler: Oyuncunun kalan canlarını doğru şekilde
göstermiştir.
Potansiyometre: Paletin hareket kontrolü, hassas bir şekilde
çalışmıştır.
Palet Kontrolü: Potansiyometre ile paletin sağa ve sola
hareketi, istenilen şekilde çalışmıştır.
Top Hareketi: Topun çarpma ve yön değiştirme mekaniği,
fiziksel kurallara uygun şekilde çalışmıştır. Top, paletle temas
ettiğinde, yönünü doğru şekilde değiştirmiştir.
Tuğlalar ve Skor: Her tuğla kırıldığında, yedi segment
gösterge üzerindeki skor artmış ve OLED ekranda tuğla
kaybolmuştur.
Can Sistemi: Oyuncu topu kaçırdığında, LED'ler ile
gösterilen can sayısı düşmüştür.
Obje Düşürme ve Can Artışı: Tuğla kırıldığında %10 şans
ile obje düşme mekaniği doğru şekilde çalışmış ve paletle
yakalandığında can artışı doğru şekilde gerçekleşmiştir.
Bölüm Değişimi ve Hız Artışı: Tüm tuğlalar kırıldığında,
oyun 5 saniyelik bir ara ekran göstermiş ve ardından topun hızı
%20 artarak yeni bir bölüm başlamıştır. Skor, önceki turdan
devam etmiştir.
Oyunun başlangıcı ve bitiş mekanikleri de test edilmiştir.
Başlangıç menüsünde "Başlat" ve "Çıkış" seçenekleri sorunsuz
şekilde çalışmıştır. Oyun bitiminde, oyuncu 3 canını
kaybettiğinde, skor 3 saniye boyunca gösterilmiş ve ardından
ana menüye dönülmüştür. Çıkış seçeneği seçildiğinde, uygun
bir teşekkür mesajı görüntülenmiştir.

<img width="640" alt="Ekran Resmi 2024-06-01 11 20 10" src="https://github.com/zeynepplbyk/Brick-Breaker/assets/125740535/3fb4315a-71c5-47d9-8e20-e8ab9615b57a">
