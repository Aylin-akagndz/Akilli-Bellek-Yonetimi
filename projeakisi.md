# 🛡️ Bellek Optimizasyonu
## İçin Potansiyel Teknolojiler ve Stratejik Seçim Raporu

**Proje Adı:** Akıllı Bellek Yönetim Uygulaması  
**Ekip:** RAM Kurtarıcıları  
**Hazırlayan:** Yusuf Tuğra Deveci  
**Tarih:** 6 Mart 2026

---

**1. GİRİŞ VE ARAŞTIRMA KAPSAMI**
Bu rapor, "RAM Kurtarıcıları" ekibinin geliştireceği uygulamanın teknolojik altyapısını belirlemek amacıyla hazırlanmıştır. Projemizin temel odağı; sistem kaynaklarını en az seviyede tüketen (minimum memory footprint) ve anlık tepki verebilen yüksek performanslı bir bellek yönetim aracı inşa etmektir.

**🛠️ 2. SEÇİLEN TEKNOLOJİ YIĞINI (TECH STACK) VE ANALİZİ**

**2.1. Sistem Motoru (Backend): C++ ve Rust Karşılaştırması**
Araştırmalarımız sonucunda projenin çekirdek motoru için **C++** dili seçilmiştir.
* **Neden C++?:** Donanım seviyesinde doğrudan bellek yönetimi (malloc/free) yapmamıza olanak tanıyan en güçlü dildir.
* **Neden Rust Değil?:** Rust güvenli bir alternatif olsa da, projemizin "bellek üzerinde tam hakimiyet" hedefi için C++'ın esnekliği daha uygun görülmüştür.

**2.2. Kullanıcı Paneli (Frontend): Python Hibrit Modeli**
Kullanıcının sistemi izleyeceği arayüz için **Python** tercih edilmiştir. C++ motoru ağır işleri yaparken, Python verileri görselleştirecektir.

**2.3. Veri Kaynağı: Linux /proc Sanal Dosya Sistemi**
Sistem verilerini toplamak için Linux çekirdeğinin (kernel) sunduğu `/proc` sistemi kullanılacaktır.
* **Teknik Üstünlük:** `/proc/meminfo` gibi dosyalar diskte yer kaplamayan, doğrudan RAM'deki canlı veriyi yansıtan sanal dosyalardır.
* **Çapraz Platform (Cross-Platform) Uyumluluğu:** /proc mimarisi Linux çekirdeğine özgü olsa da, projenin Windows ve macOS gibi farklı işletim sistemlerinde de çalışabilmesi güvence altına alınmıştır. Bu uyumluluğu sağlamak için; C++ tabanlı arka uç (backend) kodları Windows ortamında **WSL2**, macOS ortamında ise **sanallaştırma (Docker/VM)** teknolojileri kullanılarak izole bir Linux çekirdeğinde çalıştırılacaktır. Python tabanlı kullanıcı arayüzü ise işletim sisteminden bağımsız çalışacaktır.

**2.4. Denetim Aracı: Valgrind (Memcheck)**
Yazılımın kalitesini garanti altına almak için **Valgrind** kullanılacaktır. Manuel bellek yönetiminde oluşabilecek en küçük bellek sızıntılarını bile tespit edecektir.

**🚫 3. DİĞER TEKNOLOJİLERİN ELENME GEREKÇELERİ**

**3.1. Java ve .NET Ekosisteminin Riskleri**
Java ve C# gibi diller, kendi çalışma ortamları için başlangıçta yüksek miktarda RAM tüketirler ve Garbage Collector mekanizması sistemi yavaşlatabilir.

**3.2. Saf Python Yaklaşımının Verimsizliği**
Tüm projeyi Python ile yazmak, basit bir veri için bile C++'a göre 5-10 kat daha fazla yer harcanmasına neden olur.

**🏁 4. SONUÇ**
Seçilen C++ backend ve Python frontend mimarisi, projemizin hem profesyonel bir sistem aracı gibi çalışmasını hem de modern bir kullanıcı arayüzüne sahip olmasını sağlayacaktır.

---
**Fonksiyonel Gereksinim Notu:** Sistem geliştiricilere bellek kullanımını iyileştirmeye yönelik öneriler sunabilir.
