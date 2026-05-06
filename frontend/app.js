async function analiziBaslat() {
    // 1. Kullanıcının yazdığı uygulama adını al
    const uygulamaAdi = document.getElementById("uygulama-adi").value || "Uygulama";
    
    // 2. Ekranlar arası geçiş yap
    document.getElementById("ekran-1").style.display = "none";
    document.getElementById("ekran-2").style.display = "block";
    
    // 3. Başlık ve tarihi güncelle
    document.getElementById("sonuc-baslik").innerText = "Analiz Sonucu: " + uygulamaAdi;
    const bugun = new Date();
    document.getElementById("sonuc-tarih").innerText = "Tarih: " + bugun.toLocaleString('tr-TR');

    try {
        // Sümeyra'nın backend'inden veriyi çekiyoruz
        const response = await fetch("http://127.0.0.1:8000/api/v1/sistem/profil");
        const data = await response.json();

        // Gelen veriyi (anlık kullanım) kırmızı halkanın içine ve uyarılara yazıyoruz
        document.getElementById("sizinti-miktari").innerText = data.anlik_kullanim_kb;
        
        document.getElementById("uyari-1").innerText = `[UYARI] ${data.anlik_kullanim_kb} KB sızıntı tespit edildi - main.cpp (Satır 45)`;
        document.getElementById("uyari-2").innerText = `[BİLGİ] Zirve kullanım: ${data.zirve_kullanim_kb} KB - utils.cpp (Satır 112)`;

    } catch (error) {
        // Eğer backend çalışmıyorsa örnek Valgrind tasarımı görünsün (Tasarım testi için)
        document.getElementById("sizinti-miktari").innerText = "16";
        document.getElementById("uyari-1").innerText = "[UYARI] 12 Bayt sızıntı tespit edildi - main.cpp (Satır 45)";
        document.getElementById("uyari-2").innerText = "[UYARI] 4 Bayt dolaylı sızıntı - utils.cpp (Satır 112)";
        console.log("Backend bağlantı hatası, sahte veri gösteriliyor.");
    }
}

// Geri dön butonuna basılınca ilk ekrana dön
function geriDon() {
    document.getElementById("ekran-2").style.display = "none";
    document.getElementById("ekran-1").style.display = "block";
    document.getElementById("uygulama-adi").value = "";
}
