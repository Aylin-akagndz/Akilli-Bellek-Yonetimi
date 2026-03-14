# 1. HAFTA ÇALIŞMALARI (6 Mart - 12 Mart 2026)
---

## 1.1 Proje Analizi ve Kapsam Tanımlama

**Sorumlu:** Mustafa Şahingöz

**1. Projenin Temel Hedefleri**

*Elde edilen teknik verileri yapılandırılmış bir formatta işleyerek arayüz üzerinden kullanıcıya raporlamak.
* Arka planda çalışan analiz motorunun ürettiği karmaşık terminal çıktılarını, Python tabanlı kullanıcı dostu bir grafik arayüz (GUI) ile görselleştirerek (grafikler, metrikler ve uyarılar halinde) raporlamak.

**2. Proje Kapsamı**

* **Kapsam İçi:** Hedef uygulamanın Linux ortamında bellek yönetim araçlarıyla (Valgrind) çalıştırılması, anlık/periyodik bellek tüketim verilerinin toplanması ve bu verilerin Python arayüzünde anlamlı raporlara dönüştürülmesi.
* **Kapsam Dışı:** Tespit edilen bellek sızıntılarının sistem tarafından otomatik olarak düzeltilmesi veya kaynak kodun değiştirilmesi (Uygulama yalnızca tespit ve raporlama yapacaktır). Ayrıca uygulamanın ilk sürümü Linux/WSL ortamına odaklanacak olup, doğrudan Windows (native) desteği kapsam dışıdır.

**3. Potansiyel Zorluklar ve Risk Analizi**

* **Performans Yükü (Overhead):** Dinamik analiz araçlarının (özellikle Valgrind'in) hedef programın çalışma hızını yavaşlatması ve sistem kaynaklarını fazladan tüketmesi.
* **Veri Ayrıştırma (Parsing) Zorluğu:** Valgrind'in ürettiği standart dışı, karmaşık metin çıktıların Python tarafına aktarılırken veri kaybı yaşanmadan hatasız bir şekilde ayrıştırılması.
* **Sistemler Arası İletişim:** Veriyi toplayan arka uç (C++) ile veriyi gösteren ön uç (Python) arasındaki iletişimin sorunsuz, düşük gecikmeli ve kopmadan sağlanması.

**4. Mevcut Bellek Optimizasyonu Yaklaşımları ve Araç Araştırması**

* **Manuel Yaklaşımlar:** Geliştiricilerin bellek tahsislerini (`malloc/free` veya `new/delete`) manuel loglamasıdır. İnsan hatasına açıktır ve büyük projelerde sürdürülebilir değildir.




