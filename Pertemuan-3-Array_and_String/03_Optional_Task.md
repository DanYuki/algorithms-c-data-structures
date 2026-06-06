# Pertemuan 3 — Optional Task

**Topik:** Array & String
**Sifat:** Opsional — dikerjakan di luar kelas sebagai latihan tambahan

---

## Petunjuk Umum

- Untuk setiap soal, **buat dulu pseudocode** sebelum menulis kode C.
- Buat file jawaban kamu sendiri (`03_OT1.c`, `03_OT2.c`, `03_OT3.c`).
- Compile dan tes dengan beberapa input berbeda.
- Coba sendiri minimal 15 menit sebelum minta bantuan AI.

---

## Soal 1 — Level Mudah: Penjumlahan Dua Matriks

**Problem Statement:**

Buat program C yang:
1. Mendefinisikan dua matriks 3×3 secara langsung di kode (tidak perlu input).
2. Menghitung dan menyimpan hasil **penjumlahan** kedua matriks ke matriks ketiga.
3. Menampilkan ketiga matriks (Matriks A, Matriks B, Hasil A+B) dengan format rapi.

**Contoh data (bebas diubah):**
```
Matriks A:       Matriks B:
 1  2  3          9  8  7
 4  5  6          6  5  4
 7  8  9          3  2  1
```

**Contoh output:**
```
Matriks A:
  1  2  3
  4  5  6
  7  8  9

Matriks B:
  9  8  7
  6  5  4
  3  2  1

Hasil A + B:
 10 10 10
 10 10 10
 10 10 10
```

<details>
<summary>Panduan (klik jika butuh)</summary>

- Penjumlahan matriks: `hasil[i][j] = A[i][j] + B[i][j]` untuk setiap `i` dan `j`.
- Kamu butuh tiga nested loop: satu untuk mengisi hasil, satu untuk mencetak masing-masing matriks.
- Atau kamu bisa buat fungsi `cetak_matriks(int m[3][3])` agar tidak perlu menulis loop cetak tiga kali.

**Pertanyaan pemandu:**
- Bisakah kamu membuat fungsi `jumlah_matriks` yang menerima dua matriks dan mengisi matriks hasil?
- Apa yang terjadi jika dua matriks berukuran berbeda? Apakah penjumlahan masih valid?

</details>

---

## Soal 2 — Level Menantang: Cek Palindrom

**Problem Statement:**

Sebuah kata disebut **palindrom** jika dibaca dari depan dan dari belakang menghasilkan kata yang sama. Contoh: "katak", "radar", "level", "madam".

Buat program C yang:
1. Meminta pengguna memasukkan sebuah kata (satu kata, tanpa spasi, huruf kecil semua).
2. Menentukan apakah kata tersebut palindrom atau bukan.
3. Menampilkan hasilnya.

**Contoh output:**
```
Masukkan kata: katak
"katak" adalah PALINDROM.
```
```
Masukkan kata: buku
"buku" bukan palindrom.
```

**Batasan:** asumsikan input hanya huruf kecil, panjang maksimal 50 karakter.

<details>
<summary>Panduan (klik jika butuh)</summary>

**Pendekatan 1 — Dua pointer:**
- Gunakan dua indeks: `kiri = 0` dan `kanan = strlen(kata) - 1`.
- Bandingkan `kata[kiri]` dan `kata[kanan]`.
- Jika berbeda → bukan palindrom. Jika sama → maju `kiri++`, mundur `kanan--`.
- Ulangi sampai `kiri >= kanan`.

**Pendekatan 2 — Buat salinan terbalik:**
- Salin string ke array baru, lalu balik urutannya.
- Bandingkan string asli dan string terbalik dengan `strcmp`.

**Pertanyaan pemandu:**
- Apa yang terjadi jika panjang string ganjil (mis. "katak" panjang 5)? Apakah karakter tengah perlu dicek?
- Bagaimana cara menangani input dengan huruf besar? (Petunjuk: cek fungsi `tolower` di `<ctype.h>`)

</details>

---

## Soal 3 — Level Lanjutan: Frekuensi Kemunculan Huruf

**Problem Statement:**

Buat program C yang:
1. Meminta pengguna memasukkan sebuah kalimat (boleh mengandung spasi, maksimal 100 karakter).
2. Menghitung berapa kali **setiap huruf alfabet** (a–z) muncul dalam kalimat tersebut (tidak case-sensitive: 'A' dan 'a' dihitung sama).
3. Menampilkan hanya huruf yang muncul minimal 1 kali, beserta jumlahnya, **diurutkan dari huruf yang paling sering muncul** ke yang paling jarang.

**Contoh output:**
```
Masukkan kalimat: Belajar C itu seru!

Frekuensi huruf:
  r : 3
  a : 2
  e : 2
  u : 2
  b : 1
  c : 1
  i : 1
  j : 1
  l : 1
  s : 1
  t : 1
```

*(Urutan huruf dengan frekuensi sama bebas)*

<details>
<summary>Panduan (klik jika butuh)</summary>

**Langkah-langkah:**

1. Buat array `int frekuensi[26] = {0}` — indeks 0 untuk 'a', indeks 25 untuk 'z'.
2. Loop tiap karakter kalimat:
   - Jika huruf (cek dengan `isalpha` dari `<ctype.h>`), ubah ke lowercase dengan `tolower`.
   - Tambahkan `frekuensi[c - 'a']++`. (Kenapa `c - 'a'`? Karena nilai ASCII 'a' = 97, 'b' = 98, dst. Jadi `'b' - 'a' = 1` → indeks 1.)
3. Untuk mengurutkan: gunakan sorting sederhana (bubble sort atau selection sort) pada array frekuensi, sambil ikut memindahkan "label" hurufnya.
   - Atau: buat array pasangan `{huruf, frekuensi}` lalu sort berdasarkan frekuensi.

**Pertanyaan pemandu:**
- Bagaimana cara menggunakan `fgets` untuk membaca kalimat yang mengandung spasi?
- Mengapa `c - 'a'` bisa dipakai sebagai indeks? Coba lihat tabel ASCII untuk memahami polanya.
- Bisakah kamu melakukannya tanpa sorting — cukup loop dari frekuensi tertinggi ke terendah?

</details>
