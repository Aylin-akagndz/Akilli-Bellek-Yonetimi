/*
 * ============================================================
 *  RAM Kurtarıcıları – Hafta 5
 *  Gereksiz Nesne Oluşturulmasının Engellenmesi
 *  Sorumlu: Aylin Akagündüz
 * ============================================================
 *
 *  Derleme:
 *    g++ -O2 -std=c++17 -o nesne_havuzu nesne_havuzu.cpp
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <memory>
#include <string>

// ─── Analiz Sonuç Nesnesi ─────────────────────────────────
// Uygulamada sık oluşturulan kısa ömürlü nesne örneği
struct AnalizSonucu {
    int    pid        = 0;
    double ram_mb     = 0.0;
    bool   sizinti    = false;
    std::string mesaj = "";

    void sifirla() {
        pid     = 0;
        ram_mb  = 0.0;
        sizinti = false;
        mesaj   = "";
    }
};

// ─── Nesne Havuzu (Object Pool) ───────────────────────────
// Nesneleri yok etmek yerine havuza geri alır,
// ihtiyaç duyulduğunda yeniden kullanır.
class NesneHavuzu {
public:
    explicit NesneHavuzu(size_t baslangic_boyutu = 5) {
        for (size_t i = 0; i < baslangic_boyutu; ++i)
            havuz_.push_back(std::make_unique<AnalizSonucu>());
        std::cout << "[Havuz] " << baslangic_boyutu
                  << " nesne önceden oluşturuldu.\n";
    }

    // Havuzdan nesne al
    AnalizSonucu* al() {
        if (!havuz_.empty()) {
            AnalizSonucu* nesne = havuz_.back().release();
            havuz_.pop_back();
            std::cout << "[Havuz] Mevcut nesne yeniden kullanıldı. "
                      << "Kalan: " << havuz_.size() << "\n";
            return nesne;
        }
        // Havuz boşsa yeni oluştur
        std::cout << "[Havuz] Havuz boş, yeni nesne oluşturuluyor.\n";
        return new AnalizSonucu();
    }

    // Nesneyi havuza geri koy
    void geriKoy(AnalizSonucu* nesne) {
        nesne->sifirla();  // temizle, bir sonraki kullanıma hazırla
        havuz_.push_back(std::unique_ptr<AnalizSonucu>(nesne));
        std::cout << "[Havuz] Nesne iade edildi. "
                  << "Havuz boyutu: " << havuz_.size() << "\n";
    }

    size_t boyut() const { return havuz_.size(); }

private:
    std::vector<std::unique_ptr<AnalizSonucu>> havuz_;
};

// ─── Move Semantics Örneği ────────────────────────────────
// Büyük veriyi kopyalamak yerine taşıyarak bellek tasarrufu
std::vector<uint8_t> veriOlustur(size_t boyut) {
    std::vector<uint8_t> veri(boyut, 0xAB);
    return veri;  // NRVO / move semantics devreye girer
}

// ─── Ana Program ──────────────────────────────────────────
int main() {
    std::cout << "=== Gereksiz Nesne Oluşturulmasının Engellenmesi ===\n\n";

    // ── Senaryo 1: Object Pool ─────────────────────────────
    std::cout << "--- Senaryo 1: Nesne Havuzu ---\n";
    NesneHavuzu havuz(3);

    // 1. analiz
    AnalizSonucu* s1 = havuz.al();
    s1->pid    = 1234;
    s1->ram_mb = 45.6;
    s1->sizinti = false;
    std::cout << "Analiz 1 → PID: " << s1->pid
              << ", RAM: " << s1->ram_mb << " MB\n";
    havuz.geriKoy(s1);  // yok etme, havuza iade et

    // 2. analiz — aynı nesne yeniden kullanılır
    AnalizSonucu* s2 = havuz.al();
    s2->pid    = 5678;
    s2->ram_mb = 120.3;
    s2->sizinti = true;
    s2->mesaj  = "Kritik bellek sızıntısı tespit edildi!";
    std::cout << "Analiz 2 → PID: " << s2->pid
              << ", Sızıntı: " << (s2->sizinti ? "VAR" : "YOK") << "\n";
    havuz.geriKoy(s2);

    // ── Senaryo 2: Move Semantics ──────────────────────────
    std::cout << "\n--- Senaryo 2: Move Semantics ---\n";
    auto v1 = veriOlustur(1024 * 1024);  // 1 MB, kopyalama yok
    std::cout << "v1 boyutu: " << v1.size() / 1024 << " KB\n";

    auto v2 = std::move(v1);  // taşı, kopyalama yok
    std::cout << "v2 boyutu: " << v2.size() / 1024 << " KB\n";
    std::cout << "v1 boyutu (taşındıktan sonra): " << v1.size() << " byte\n";

    std::cout << "\n[Tüm senaryolar tamamlandı — sıfır gereksiz nesne oluşturuldu]\n";
    return 0;
}
