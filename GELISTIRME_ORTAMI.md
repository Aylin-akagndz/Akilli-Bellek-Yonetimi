Geliştirme Ortamı Yapılandırma Raporu
Sorumlu: Semanur Buhan
Görev: Geliştirme Ortamı Kurulumu (1. Hafta)

1. Özet ve Amaç
Akıllı Bellek Yönetimi Uygulaması projesinin teknik gereksinimleri doğrultusunda, geliştirme süreçlerinin sağlıklı yürütülebilmesi için gerekli olan araç zinciri (toolchain) ve çalışma ortamı yapılandırılmıştır. Bu rapor, kurulumu yapılan sistem bileşenlerini ve doğrulama adımlarını içermektedir.

2. Teknik Altyapı ve Kurulumlar
2.1. İşletim Sistemi Katmanı (Linux/WSL)
Uygulamanın bellek analizi süreçlerinde Linux çekirdeğine ait /proc sanal dosya sistemini kullanacak olması nedeniyle, geliştirme ortamı olarak WSL2 (Windows Subsystem for Linux) üzerine kurulu Ubuntu dağıtımı tercih edilmiş ve kurulumu tamamlanmıştır.

2.2. C++ Geliştirme ve Analiz Araçları
Arka uç (backend) motorunun geliştirilmesi için gerekli araçlar sisteme dahil edilmiştir:

Derleyici (GCC/G++): C++ kodlarının derlenmesi için build-essential paketi kuruldu.

Dinamik Analiz (Valgrind): Bellek sızıntılarının tespiti ve analizi için Valgrind araç seti yapılandırıldı.

Hata Ayıklayıcı (GDB): Çalışma zamanı hatalarının tespiti için debugger entegrasyonu sağlandı.

2.3. Python ve Arayüz Çalışma Alanı
Ön yüz (frontend) ve raporlama sistemleri için gerekli Python altyapısı kurulmuştur:

Python 3.x güncel sürüm kurulumu doğrulandı.

Modüller arası çakışmaları önlemek adına izole sanal ortam (venv) yapısı hazırlandı.

2.4. IDE ve Geliştirici Eklentileri
Geliştirme arayüzü olarak VS Code üzerinde aşağıdaki konfigürasyonlar yapılmıştır:

WSL Remote Extension: Linux dosya sistemine doğrudan erişim sağlandı.

C/C++ & Python Extension Pack: Akıllı kod tamamlama ve derleme desteği aktif edildi.

3. Doğrulama ve Test
Yapılan kurulumlar terminal üzerinden test edilerek derleyici ve analiz araçlarının (Valgrind, G++ ve Python) sorunsuz çalıştığı teyit edilmiştir. Geliştirme ortamı, projenin tasarım ve kodlama aşamaları için hazır durumdadır.
