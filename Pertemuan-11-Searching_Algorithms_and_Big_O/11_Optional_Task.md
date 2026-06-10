# Pertemuan 11 — Optional Task: Searching & Big-O

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` sendiri sebagai jawabanmu.

---

## Optional Task 1 — Linear Search pada Array of Struct (Level: Mudah)

### Latar Belakang

Di dunia nyata, kita jarang mencari dalam array integer biasa. Lebih sering kita mencari dalam array berisi data kompleks — misalnya, mencari mahasiswa berdasarkan NIM, atau mencari produk berdasarkan kode barang.

### Yang Harus Dibuat

Buat file **`optional1_search_struct.c`** yang melakukan hal berikut:

1. Definisikan struct `Mahasiswa`:
   ```c
   typedef struct {
       int    nim;
       char   nama[50];
       float  ipk;
   } Mahasiswa;
   ```

2. Implementasikan dua fungsi pencarian:

   ```c
   /* Cari berdasarkan NIM — kembalikan indeks, -1 jika tidak ada */
   int cari_nim(Mahasiswa mhs[], int n, int nim_target);

   /* Cari berdasarkan nama — kembalikan indeks pertama yang cocok, -1 jika tidak ada */
   /* Gunakan strcmp() dari <string.h> untuk membandingkan string */
   int cari_nama(Mahasiswa mhs[], int n, const char *nama_target);
   ```

3. Tambahkan fungsi bonus:
   ```c
   /* Cari mahasiswa dengan IPK tertinggi — kembalikan indeksnya */
   int cari_ipk_tertinggi(Mahasiswa mhs[], int n);
   ```

4. Di `main()`, buat array 5 mahasiswa dan uji semua fungsi:

   ```c
   Mahasiswa data[] = {
       {2021001, "Andi Pratama",   3.75},
       {2021002, "Budi Santoso",   3.40},
       {2021003, "Citra Dewi",     3.90},
       {2021004, "Dinda Rahayu",   3.55},
       {2021005, "Eko Widodo",     3.20}
   };
   ```

### Contoh Output

```
=== Cari NIM ===
NIM 2021003 → ditemukan: Citra Dewi (IPK 3.90) di indeks 2
NIM 9999999 → tidak ditemukan

=== Cari Nama ===
"Budi Santoso"  → ditemukan di indeks 1 (NIM: 2021002)
"Zahira Putri"  → tidak ditemukan

=== IPK Tertinggi ===
IPK tertinggi: Citra Dewi (IPK 3.90)
```

### Petunjuk

- Tambahkan `#include <string.h>` untuk `strcmp`.
- `strcmp(a, b)` mengembalikan 0 jika kedua string sama.
- Untuk `cari_ipk_tertinggi`: simpan indeks kandidat terbaik (`int idx_maks = 0`), lalu loop dari 1 sampai n-1, update `idx_maks` jika `mhs[i].ipk > mhs[idx_maks].ipk`.

---

## Optional Task 2 — Binary Search Rekursif: Bukti Empiris O(log n) (Level: Menantang)

### Latar Belakang

Di Task B Soal 2, kamu sudah mengimplementasikan binary search rekursif yang menghitung kedalaman rekursi. Sekarang kita akan **membuktikan secara empiris** bahwa kedalaman rekursi tumbuh seperti `log₂(n)` — bukan secara linear.

### Yang Harus Dibuat

Buat file **`optional2_bigo_empiris.c`** yang melakukan hal berikut:

1. Implementasikan binary search rekursif yang menghitung kedalaman (dari Task B Soal 2):
   ```c
   int binsearch(int arr[], int left, int right, int target, int *kedalaman);
   ```

2. Buat fungsi `cetak_tabel_bigo` yang:
   - Membuat array terurut `{0, 2, 4, ..., 2*(n-1)}` untuk berbagai nilai n.
   - Mencari nilai yang **tidak ada** di array (yaitu `2*n + 1`) untuk mengukur **worst case**.
   - Mencatat kedalaman rekursi untuk setiap n.
   - Mencetak tabel perbandingan kedalaman aktual vs `⌈log₂(n)⌉`.

   ```c
   void cetak_tabel_bigo();
   ```

3. Di `main()`, panggil `cetak_tabel_bigo()`.

### Contoh Output yang Diharapkan

```
=== Bukti Empiris O(log n) — Binary Search ===

n         | Kedalaman | ceil(log2(n)) | Selisih
----------|-----------|---------------|--------
        8 |         3 |             3 |       0
       16 |         4 |             4 |       0
       32 |         5 |             5 |       0
       64 |         6 |             6 |       0
      128 |         7 |             7 |       0
      256 |         8 |             8 |       0
      512 |         9 |             9 |       0
     1024 |        10 |            10 |       0
     2048 |        11 |            11 |       0
  1000000 |        20 |            20 |       0

Kesimpulan: kedalaman rekursi selalu ≈ log₂(n).
Saat n naik 1000x (dari 1024 ke 1.000.000), kedalaman hanya naik 10 langkah!
```

### Petunjuk

- Gunakan `#include <stdlib.h>` untuk `malloc` dan `free`.
- Gunakan `#include <math.h>` untuk `ceil(log2(n))`. Kompilasi dengan flag `-lm`:
  ```
  gcc optional2_bigo_empiris.c -o optional2 -lm
  ```
- Untuk menghitung `⌈log₂(n)⌉` secara integer tanpa `math.h` (alternatif):
  ```c
  int ceil_log2(int n) {
      int hasil = 0;
      int sisa = n - 1;
      while (sisa > 0) { hasil++; sisa >>= 1; }
      return hasil;
  }
  ```
- Alokasikan array dinamis: `int *arr = malloc(n * sizeof(int))`, isi dengan loop, lalu `free(arr)` setelah selesai.

### Pertanyaan Refleksi (tidak perlu dikodekan — cukup dipikirkan)

1. Jika n = 1 miliar (10⁹), berapa langkah maksimal binary search?
2. Jika linear search membutuhkan rata-rata n/2 langkah, dan binary search ⌈log₂(n)⌉ langkah, berapa perbandingan langkah keduanya untuk n = 1.000.000?
3. Dalam kasus apa binary search *tidak* lebih baik dari linear search?
