# Pertemuan 2 — Optional Task

**Topik:** Control Flow & Functions
**Sifat:** Opsional — dikerjakan di luar kelas sebagai latihan tambahan

---

## Petunjuk Umum

- Untuk setiap soal, **buat dulu pseudocode-nya** sebelum menulis kode C.
- Buat file jawaban kamu sendiri (mis. `02_OT1.c`, `02_OT2.c`, `02_OT3.c`).
- Compile dan tes dengan beberapa input berbeda untuk memastikan program benar.
- Coba sendiri minimal 15 menit sebelum minta bantuan AI.

---

## Soal 1 — Level Mudah: Tabel Proyeksi Tabungan

**Problem Statement:**

Bayangkan kamu ingin membandingkan berapa saldo tabungan yang terkumpul jika menabung dengan
nominal berbeda setiap bulan (tanpa bunga). Buat program C yang:

1. Menampilkan **tabel proyeksi tabungan** dalam bentuk grid rapi.
2. **Baris** mewakili bulan ke-1 sampai bulan ke-6.
3. **Kolom** mewakili pilihan setoran per bulan: 100.000, 200.000, 300.000, 400.000, 500.000.
4. Isi setiap sel adalah `setoran_per_bulan × nomor_bulan` (total tabungan sampai bulan itu).
5. Setiap angka ditampilkan dengan lebar kolom yang sama (gunakan `%9d`) agar rapi.

**Contoh output yang diharapkan:**
```
Setoran/bln ->    100000   200000   300000   400000   500000
Bulan 1     :     100000   200000   300000   400000   500000
Bulan 2     :     200000   400000   600000   800000  1000000
Bulan 3     :     300000   600000   900000  1200000  1500000
Bulan 4     :     400000   800000  1200000  1600000  2000000
Bulan 5     :     500000  1000000  1500000  2000000  2500000
Bulan 6     :     600000  1200000  1800000  2400000  3000000
```

**Panduan:**

<details>
<summary>Klik untuk melihat panduan</summary>

- Ini pada dasarnya tabel perkalian, tapi dengan konteks nyata: setoran × bulan.
- Kamu butuh **dua loop yang bersarang** (*nested loop*): loop luar untuk baris (bulan), loop dalam untuk kolom (setoran).
- Loop luar: `for (bulan = 1; bulan <= 6; bulan++)`
- Loop dalam: `for (setoran = 100000; setoran <= 500000; setoran += 100000)`
- Isi setiap sel adalah `setoran * bulan`.
- Pindah baris setelah loop dalam selesai dengan `printf("\n")`.

**Pertanyaan pemandu:**
- Mengapa `%9d` membuat kolom terlihat rapi, sementara `%d` tidak?
- Bisakah kamu memisahkan logika "cetak satu baris bulan" ke dalam sebuah fungsi `void cetak_baris(int bulan)`?

</details>

---

## Soal 2 — Level Menantang: Faktorial — Loop vs Rekursi

**Problem Statement:**

Buat program C yang:
1. Meminta pengguna memasukkan sebuah bilangan bulat **N** (0 ≤ N ≤ 12).
2. Menghitung faktorial N menggunakan **dua cara**:
   - Fungsi `faktorial_loop(int n)` — menggunakan perulangan.
   - Fungsi `faktorial_rekursi(int n)` — menggunakan rekursi.
3. Menampilkan hasil dari kedua fungsi dan memastikan hasilnya sama.
4. Jika N di luar rentang 0–12, tampilkan pesan error (bukan crash).

> **Mengapa batas N = 12?** Faktorial(13) = 6.227.020.800 yang melebihi kapasitas `int` (max ~2.1 miliar). Untuk N > 12, tipe `int` tidak cukup.

**Contoh output:**
```
Masukkan N (0-12): 6
Faktorial(6) via loop    : 720
Faktorial(6) via rekursi : 720
Kedua metode menghasilkan nilai yang sama.
```

```
Masukkan N (0-12): 15
Error: N harus berada di rentang 0 hingga 12.
```

**Panduan:**

<details>
<summary>Klik untuk melihat panduan</summary>

**Fungsi loop:**
```
hasil = 1
UNTUK i dari 1 sampai n:
    hasil = hasil * i
KEMBALIKAN hasil
```

**Fungsi rekursi:**
```
JIKA n == 0 MAKA kembalikan 1   ← base case
SELAIN ITU kembalikan n * faktorial_rekursi(n - 1)
```

**Pertanyaan pemandu:**
- Apa yang terjadi jika kamu memanggil `faktorial_rekursi(-1)`? Bagaimana mencegahnya?
- Mengapa base case rekursi adalah `n == 0` dan bukan `n == 1`?

</details>

---

## Soal 3 — Level Lanjutan: FizzBuzz dengan Fungsi

**Problem Statement:**

FizzBuzz adalah latihan klasik pemrograman. Buat program C yang:

1. Menerima input **N** dari pengguna.
2. Untuk setiap bilangan dari 1 sampai N, cetak:
   - `"FizzBuzz"` jika bilangan habis dibagi **3 DAN 5**
   - `"Fizz"` jika bilangan habis dibagi **3** saja
   - `"Buzz"` jika bilangan habis dibagi **5** saja
   - Bilangan itu sendiri jika tidak memenuhi kondisi di atas

3. **Wajib** menggunakan **minimal satu fungsi** (selain `main`) untuk memisahkan logika.

**Contoh output (N = 15):**
```
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
```

**Batasan tambahan:**
- Jika N ≤ 0, tampilkan pesan: `"N harus bilangan positif."` dan jangan cetak apa-apa.

**Panduan:**

<details>
<summary>Klik untuk melihat panduan</summary>

Kamu bisa memisahkan logika dengan berbagai cara, misalnya:

**Opsi A — Fungsi yang menentukan label:**
```c
/* Fungsi mengembalikan string label yang sesuai */
/* Petunjuk: ini butuh pengetahuan tentang string/array yang akan dipelajari P3.
   Untuk sekarang, coba Opsi B. */
```

**Opsi B — Fungsi yang langsung mencetak:**
```c
void cetak_fizzbuzz(int angka) {
    /* cek kondisi dan printf di sini */
}
```

**Urutan pengecekan kondisi penting!** Cek `% 3 == 0 && % 5 == 0` *dulu* sebelum cek `% 3` atau `% 5` sendiri-sendiri. Mengapa?

**Pertanyaan pemandu:**
- Apa yang terjadi jika kamu cek `% 3` dulu, baru `% 5`, baru `% 3 && % 5`?
- Bisakah kamu menulis seluruh logika FizzBuzz dengan `switch-case`? Apakah lebih mudah atau lebih sulit dibanding `if-else`?

</details>
