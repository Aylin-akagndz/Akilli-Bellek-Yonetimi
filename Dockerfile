# 1. Temel İşletim Sistemi (Python 3.10 yüklü hafif Linux)
FROM python:3.10-slim

# 2. Sistem bağımlılıklarını kur (C++ derleyicisi ve Valgrind)
RUN apt-get update && apt-get install -y \
    g++ \
    valgrind \
    make \
    && rm -rf /var/lib/apt/lists/*

# 3. Çalışma klasörünü belirle
WORKDIR /app

# 4. Bağımlılık dosyasını kopyala ve kütüphaneleri kur
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# 5. Projedeki tüm dosyaları çalışma klasörüne kopyala
COPY . .

# 6. Dışarıya açılacak port
EXPOSE 8000

# 7. Motoru (Backend) Çalıştır!
# Klasör yapına uygun olarak src.api.main yolunu kullanıyoruz
CMD ["uvicorn", "src.api.main:app", "--host", "0.0.0.0", "--port", "8000"]