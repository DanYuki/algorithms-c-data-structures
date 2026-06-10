# Pertemuan 5 — Optional Task: Struct & Modular Programming

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` (dan `.h` jika diminta) sendiri sebagai jawabanmu.

---

## Optional Task 1 — Inventory Toko (Level: Mudah)

### Latar Belakang

Sebuah toko kecil ingin mencatat stok barangnya secara digital. Kamu diminta membuat program sederhana menggunakan struct untuk menyimpan dan menampilkan data barang.

### Yang Harus Dibuat

Buat file **`optional1_toko.c`** yang melakukan hal berikut:

1. Definisikan `typedef struct` bernama `Barang` dengan anggota:
   - `nama` — string maksimal 50 karakter
   - `kode` — string maksimal 10 karakter (contoh: `"BRG001"`)
   - `harga` — angka desimal (float)
   - `stok` — bilangan bulat (int)

2. Buat fungsi `void tampilkan_barang(Barang b)` yang mencetak data satu barang dalam format:
   ```
   [BRG001] Pensil              | Harga: Rp  2500.00 | Stok:  50
   ```

3. Di `main()`:
   - Buat array of struct `Barang` berisi **3 barang** (data bebas).
   - Tampilkan semua barang menggunakan fungsi `tampilkan_barang`.
   - Hitung dan tampilkan **total nilai stok** (jumlah dari `harga × stok` semua barang).

### Contoh Output

```
=== Daftar Barang ===
[BRG001] Pensil              | Harga: Rp  2500.00 | Stok:  50
[BRG002] Buku Tulis          | Harga: Rp  8000.00 | Stok:  30
[BRG003] Penggaris           | Harga: Rp  5000.00 | Stok:  20

Total nilai stok: Rp 605000.00
```

### Petunjuk

- Gunakan `strcpy` untuk mengisi anggota string.
- Gunakan `%10.2f` untuk menyelaraskan tampilan angka desimal.
- Total nilai stok = `harga[0]*stok[0] + harga[1]*stok[1] + ...` — hitung dalam loop.

---

## Optional Task 2 — Sistem Nilai Mahasiswa (Level: Menantang)

### Latar Belakang

Sebuah program perlu mengelola nilai mahasiswa dan menghasilkan laporan ringkas berdasarkan data yang tersimpan.

### Yang Harus Dibuat

Buat file **`optional2_nilai.c`** yang melakukan hal berikut:

1. Definisikan `typedef struct` bernama `MahasiswaNilai` dengan anggota:
   - `nama` — string maksimal 50 karakter
   - `nim` — string maksimal 15 karakter
   - `nilai_tugas` — float
   - `nilai_uts` — float
   - `nilai_uas` — float

2. Buat fungsi-fungsi berikut:
   - `float hitung_nilai_akhir(MahasiswaNilai *mhs)` — mengembalikan nilai akhir dengan bobot: tugas 30%, UTS 35%, UAS 35%.
   - `char tentukan_grade(float nilai_akhir)` — mengembalikan karakter grade: A (≥85), B (≥70), C (≥60), D (≥50), E (<50).
   - `void cetak_laporan(MahasiswaNilai kelas[], int jumlah)` — mencetak tabel lengkap termasuk nilai akhir dan grade setiap mahasiswa, lalu rata-rata kelas di bawahnya.

3. Di `main()`:
   - Buat array berisi **4 mahasiswa** dengan nilai yang bervariasi (pilih sendiri agar menghasilkan setidaknya 3 grade berbeda).
   - Panggil `cetak_laporan`.

### Contoh Output

```
=== Laporan Nilai Kelas ===
No | Nama                 | NIM        | Tugas | UTS   | UAS   | Akhir | Grade
--------------------------------------------------------------------------------
 1 | Andi Pratama         | 2024001    | 85.00 | 78.00 | 80.00 | 80.80 | B
 2 | Budi Santoso         | 2024002    | 60.00 | 55.00 | 50.00 | 54.75 | D
 3 | Citra Dewi           | 2024003    | 95.00 | 90.00 | 92.00 | 92.20 | A
 4 | Dani Firmansyah      | 2024004    | 70.00 | 65.00 | 68.00 | 67.55 | C

Rata-rata kelas: 73.83
```

### Petunjuk

- `hitung_nilai_akhir` menerima **pointer** ke struct (lebih efisien, tidak menyalin seluruh struct).
- Gunakan `if-else if` untuk menentukan grade.
- Hitung rata-rata kelas di dalam `cetak_laporan` dengan menjumlahkan nilai akhir semua mahasiswa dibagi jumlah.

---

## Optional Task 3 — Modul Buku Perpustakaan (Level: Lanjutan — Multi-file)

### Latar Belakang

Latihan ini mensimulasikan proyek nyata dengan pemisahan file header dan implementasi. Kamu akan membuat **3 file terpisah** yang bisa dikompilasi bersama.

### Yang Harus Dibuat

Buat **3 file** berikut:

#### `buku.h` — Header
- Include guard dengan nama makro `BUKU_H`.
- `typedef struct` bernama `Buku` dengan anggota:
  - `judul` — string 100 karakter
  - `pengarang` — string 50 karakter
  - `tahun_terbit` — int
  - `tersedia` — int (1 = tersedia, 0 = dipinjam)
- Prototipe fungsi:
  - `void tambah_buku(Buku koleksi[], int *jumlah, Buku buku_baru)`
  - `void tampilkan_semua(Buku koleksi[], int jumlah)`
  - `int cari_buku(Buku koleksi[], int jumlah, const char *judul)`
  - `void pinjam_buku(Buku koleksi[], int jumlah, const char *judul)`

#### `buku.c` — Implementasi
- `#include "buku.h"` (bukan `<buku.h>`).
- Implementasi semua fungsi:
  - `tambah_buku` — tambah `buku_baru` ke array `koleksi` dan increment `*jumlah`.
  - `tampilkan_semua` — cetak semua buku dalam tabel, termasuk status tersedia/dipinjam.
  - `cari_buku` — cari berdasarkan judul (case-sensitive, menggunakan `strcmp`). Kembalikan indeks jika ditemukan, `-1` jika tidak.
  - `pinjam_buku` — cari buku, jika ditemukan dan tersedia ubah `tersedia` menjadi 0; jika tidak ditemukan atau sedang dipinjam, tampilkan pesan yang sesuai.

#### `main.c` — Program Utama
- `#include "buku.h"`.
- Buat array `Buku koleksi[20]` dan variabel `int jumlah_buku = 0`.
- Tambahkan **3 buku** menggunakan `tambah_buku`.
- Tampilkan semua buku.
- Pinjam salah satu buku.
- Tampilkan semua buku lagi (untuk melihat perubahan status).

### Cara Kompilasi

```bash
gcc buku.c main.c -o perpustakaan
./perpustakaan
```

### Contoh Output

```
=== Koleksi Perpustakaan ===
No | Judul                              | Pengarang          | Tahun | Status
-------------------------------------------------------------------------------
 1 | The C Programming Language         | Kernighan & Ritchie | 1988  | Tersedia
 2 | Clean Code                         | Robert C. Martin   | 2008  | Tersedia
 3 | Introduction to Algorithms         | Cormen et al.      | 2009  | Tersedia

Meminjam: "Clean Code"... Berhasil dipinjam.

=== Koleksi Perpustakaan ===
No | Judul                              | Pengarang          | Tahun | Status
-------------------------------------------------------------------------------
 1 | The C Programming Language         | Kernighan & Ritchie | 1988  | Tersedia
 2 | Clean Code                         | Robert C. Martin   | 2008  | Dipinjam
 3 | Introduction to Algorithms         | Cormen et al.      | 2009  | Tersedia
```

### Petunjuk

- Include guard di `buku.h`: `#ifndef BUKU_H` / `#define BUKU_H` / `#endif`.
- Di `buku.c`, gunakan `strcmp(koleksi[i].judul, judul) == 0` untuk mencocokkan judul.
- `tambah_buku` menerima `int *jumlah` (pointer) agar bisa mengubah nilai jumlah di `main`.
- Mulai dari `buku.h` dulu, lalu `buku.c`, lalu `main.c` — urutan ini mencegah kebingungan.
