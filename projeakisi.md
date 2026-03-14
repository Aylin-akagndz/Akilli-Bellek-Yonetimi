# 1.2 🛡️ Bellek Optimizasyonu İçin Potansiyel Teknolojiler ve Stratejik Seçim Raporu

**Proje Adı:** Akıllı Bellek Yönetim Uygulaması  
**Ekip:** RAM Kurtarıcıları  
**Hazırlayan:** Yusuf Tuğra Deveci  
**Tarih:** 6 Mart 2026

---

### 🎯 1. GİRİŞ VE ARAŞTIRMA KAPSAMI
Bu rapor, **"RAM Kurtarıcıları"** ekibinin geliştireceği uygulamanın teknolojik altyapısını belirlemek amacıyla hazırlanmıştır. Projemizin temel odağı; sistem kaynaklarını en az seviyede tüketen (*minimum memory footprint*) ve anlık tepki verebilen yüksek performanslı bir bellek yönetim aracı inşa etmektir.

---

### 🛠️ 2. SEÇİLEN TEKNOLOJİ YIĞINI (TECH STACK) VE ANALİZİ

#### 2.1. Sistem Motoru (Backend): C++ ve Rust Karşılaştırması
Araştırmalarımız sonucunda projenin çekirdek motoru için **C++** dili seçilmiştir.
* **Neden C++?:** C++, donanım seviyesinde doğrudan bellek yönetimi (malloc/free) yapmamıza olanak tanıyan en güçlü dildir.
* **"Milimetrik" Optimizasyon:** Belleğin her bir byte'ını manuel olarak kontrol etme imkanını sadece bu seviyedeki diller sunar.
* **Neden Rust Değil?:** Rust güvenli bir alternatif olsa da, projemizin "bellek üzerinde tam hakimiyet" ve "geleneksel sistem araçlarıyla uyum" hedefi için C++'ın esnekliği daha uygun görülmüştür.

#### 2.2. Kullanıcı Paneli (Frontend): Python Hibrit Modeli
Kullanıcının sistemi izleyeceği arayüz için **Python** tercih edilmiştir.
* **Stratejik Sebep:** Bellek yönetimi gibi ağır işleri C++ motoru yaparken, bu verileri görselleştirmek için Python'ın zengin grafik kütüphanelerinden faydalanılacaktır.

#### 2.3. Veri Kaynağı: Linux /proc Sanal Dosya Sistemi
Sistem verilerini toplamak için dış kütüphaneler yerine Linux çekirdeğinin (kernel) sunduğu **/proc** sistemi kullanılacaktır.
* **Teknik Üstünlük:** `/proc/meminfo` gibi dosyalar diskte yer kaplamayan, doğrudan RAM'deki canlı veriyi yansıtan sanal dosyalardır. Bu dosyaları okuyarak sistemin o anki "gerçek röntgenini" en hızlı haliyle çekmiş olacağız.
* **Çapraz Platform (Cross-Platform) Uyumluluğu:** `/proc` mimarisi yalnızca Linux çekirdeğine özgü olsa da, projenin Windows ve macOS gibi farklı işletim sistemlerinde de çalışabilmesi güvence altına alınmıştır. Bu uyumluluğu sağlamak için; C++ tabanlı arka uç (backend) kodları Windows ortamında **WSL2**, macOS ortamında ise **sanallaştırma (Docker/VM)** teknolojileri kullanılarak izole bir Linux çekirdeğinde çalıştırılacaktır. Python tabanlı kullanıcı arayüzü (frontend) ise işletim sisteminden bağımsız olarak çalışarak bu verileri ekrana yansıtacaktır.



#### 2.4. Denetim Aracı: Valgrind (Memcheck)
Yazılımın kalitesini garanti altına almak için **Valgrind** analiz aracı kullanılacaktır.
* **Kritik Görev:** Manuel bellek yönetiminde oluşabilecek en küçük **bellek sızıntılarını** (*memory leaks*) bile tespit ederek, programın RAM tüketiminin sabit kalmasını sağlayacaktır.

---

### 🚫 3. DİĞER TEKNOLOJİLERİN ELENME GEREKÇELERİ

#### 3.1. Java ve .NET Ekosisteminin Riskleri
Java ve C# gibi diller, kendi çalışma ortamları (*Virtual Machine*) için başlangıçta yüksek miktarda RAM tüketirler. Ayrıca **Garbage Collector** (Çöp Toplayıcı) mekanizması, sistemi öngörülemez zamanlarda durdurabilir.

#### 3.2. Saf Python Yaklaşımının Verimsizliği
Eğer tüm projeyi Python ile yazsaydık, dilin kendi iç yapısı nedeniyle basit bir tam sayıyı saklamak için bile C++'a göre **5-10 kat daha fazla** yer harcardık. Bu durum, projemizin "bellek kurtarma" misyonuyla çelişmektedir.

---

### 🏁 4. SONUÇ
Seçilen **C++ tabanlı backend** ve **Python tabanlı frontend** mimarisi, projemizin hem profesyonel bir sistem aracı gibi çalışmasını hem de modern bir kullanıcı arayüzüne sahip olmasını sağlayacaktır.

Sistem kaynaklarını sömüren değil, onları özgürleştiren bir yazılımın temeli atılmıştır.
