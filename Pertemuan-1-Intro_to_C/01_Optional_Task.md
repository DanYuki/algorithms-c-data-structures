# Pertemuan 1 — Optional Task

**Topik:** Intro to C, Problem Solving & AI Engineering
**Sifat:** Opsional — dikerjakan di luar kelas sebagai latihan tambahan

---

## Petunjuk Umum

- Untuk setiap soal, **buat dulu flowchart dan pseudocode-nya** sebelum menulis kode C.
- Buat file jawaban kamu sendiri (mis. `01_OT1.c`, `01_OT2.c`).
- Compile dan tes dengan beberapa input yang berbeda untuk memastikan program benar.
- Kamu boleh menggunakan AI (ChatGPT / Claude) sebagai bantuan, tapi **coba sendiri dulu minimal 10 menit** sebelum minta bantuan AI.

---

## Soal 1 — Level Mudah: Nilai Terbesar dari Tiga Bilangan

**Problem Statement:**

Buat program C yang:
1. Meminta pengguna memasukkan **tiga bilangan bulat**.
2. Menampilkan bilangan yang **paling besar** di antara ketiganya.

**Contoh output yang diharapkan:**
```
Masukkan bilangan pertama  : 15
Masukkan bilangan kedua    : 42
Masukkan bilangan ketiga   : 27
Bilangan terbesar adalah   : 42
```

**Contoh output lain (untuk tes):**
```
Masukkan bilangan pertama  : 8
Masukkan bilangan kedua    : 8
Masukkan bilangan ketiga   : 3
Bilangan terbesar adalah   : 8
```

**Panduan langkah (jangan langsung buka jika belum coba sendiri):**

<details>
<summary>Klik untuk melihat panduan</summary>

1. Flowchart: kamu butuh dua buah belah ketupat (dua percabangan).
2. Pseudocode: bandingkan bilangan pertama dengan kedua, simpan yang terbesar, lalu bandingkan hasilnya dengan bilangan ketiga.
3. Di C: gunakan `if-else` bertingkat atau `if` biasa dengan variabel pembantu `terbesar`.

**Pertanyaan pemandu:**
- Bagaimana jika dua bilangan sama besar? Apakah programmu menangani kasus itu?
- Bisakah kamu selesaikan soal ini hanya dengan dua buah `if`?

</details>

---

## Soal 2 — Level Menantang: Konversi Nilai ke Grade

**Problem Statement:**

Buat program C yang:
1. Meminta pengguna memasukkan **nilai ujian** (bilangan bulat, rentang 0–100).
2. Menampilkan **grade** berdasarkan tabel berikut:

| Rentang Nilai | Grade |
|---------------|-------|
| 85 – 100 | A |
| 70 – 84 | B |
| 60 – 69 | C |
| 50 – 59 | D |
| 0 – 49 | E |

3. Jika nilai yang dimasukkan di luar rentang 0–100, tampilkan pesan: `"Nilai tidak valid. Masukkan nilai antara 0 dan 100."`

**Contoh output yang diharapkan:**
```
Masukkan nilai (0-100): 92
Grade kamu: A
```

```
Masukkan nilai (0-100): 67
Grade kamu: C
```

```
Masukkan nilai (0-100): 105
Nilai tidak valid. Masukkan nilai antara 0 dan 100.
```

**Panduan langkah (jangan langsung buka jika belum coba sendiri):**

<details>
<summary>Klik untuk melihat panduan</summary>

1. Flowchart: kamu akan punya lebih dari dua jalur keputusan — coba gambar semua percabangannya.
2. Pseudocode: gunakan `if → else if → else if → ... → else`.
3. Di C: urutan kondisi penting! Periksa dari rentang nilai tertinggi ke terendah, atau sebaliknya — tapi jangan sampai ada rentang yang terlewat atau tumpang tindih.

**Pertanyaan pemandu:**
- Berapa banyak kondisi yang kamu butuhkan?
- Bagaimana cara mengecek apakah nilai di luar 0–100?
- Apa yang terjadi jika kamu menulis `if (nilai >= 85)` tanpa batas atas? Apakah ini masalah?

</details>

---

## Tantangan Tambahan (Opsional dari Opsional)

Jika kamu sudah selesai kedua soal di atas dan ingin tantangan lebih:

Modifikasi Soal 2 agar program **terus meminta input** sampai pengguna memasukkan nilai yang valid (0–100), alih-alih langsung menampilkan pesan error dan berhenti.

> Petunjuk: kamu membutuhkan konsep *loop* yang akan dipelajari di Pertemuan 2. Coba pelajari `do-while` lebih awal!
