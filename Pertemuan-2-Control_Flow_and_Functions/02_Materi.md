# Pertemuan 2 — Control Flow & Functions

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Percabangan (Branching)](#1-percabangan-branching)
2. [switch-case](#2-switch-case)
3. [Perulangan (Looping)](#3-perulangan-looping)
4. [break & continue](#4-break--continue)
5. [Fungsi (Functions)](#5-fungsi-functions)
6. [Rekursi Dasar](#6-rekursi-dasar)
7. [AI untuk Boilerplate](#7-ai-untuk-boilerplate)

---

## 1. Percabangan (Branching)

Program nyata jarang berjalan lurus dari atas ke bawah. Seringkali program perlu **membuat keputusan** — mengerjakan ini *jika* kondisi tertentu terpenuhi, atau mengerjakan itu *jika tidak*. Inilah fungsi percabangan.

### Operator Relasional & Logika

Sebelum masuk ke `if`, kamu perlu mengenal operator yang dipakai dalam kondisi:

**Operator Relasional** — membandingkan dua nilai, hasilnya benar (`1`) atau salah (`0`):

| Operator | Arti | Contoh | Hasil |
|----------|------|--------|-------|
| `==` | Sama dengan | `5 == 5` | Benar |
| `!=` | Tidak sama dengan | `5 != 3` | Benar |
| `<` | Kurang dari | `3 < 5` | Benar |
| `>` | Lebih dari | `3 > 5` | Salah |
| `<=` | Kurang dari atau sama | `5 <= 5` | Benar |
| `>=` | Lebih dari atau sama | `3 >= 5` | Salah |

> ⚠️ **Jangan tertukar `=` dan `==`!** `=` adalah *penugasan* (assign nilai), `==` adalah *perbandingan*. Menulis `if (nilai = 60)` tidak akan membandingkan — ia akan *mengisi* nilai dengan 60, lalu selalu bernilai benar.

**Operator Logika** — menggabungkan beberapa kondisi:

| Operator | Arti | Contoh | Hasil |
|----------|------|--------|-------|
| `&&` | DAN (AND) — semua harus benar | `nilai >= 60 && nilai <= 100` | Benar jika nilai di antara 60–100 |
| `\|\|` | ATAU (OR) — cukup satu benar | `nilai < 0 \|\| nilai > 100` | Benar jika nilai di luar 0–100 |
| `!` | BUKAN (NOT) — membalik kondisi | `!lulus` | Benar jika `lulus` salah |

---

### if / else if / else

```c
if (kondisi_pertama) {
    /* dikerjakan jika kondisi_pertama benar */
} else if (kondisi_kedua) {
    /* dikerjakan jika kondisi_pertama salah, tapi kondisi_kedua benar */
} else {
    /* dikerjakan jika semua kondisi di atas salah */
}
```

---

### Contoh Kasus: Cek Kelulusan dengan Kategori

**Problem:** Program menerima nilai ujian (0–100), lalu menampilkan:
- "Lulus dengan Pujian" jika nilai ≥ 85
- "Lulus" jika nilai ≥ 60
- "Tidak Lulus" jika nilai < 60

**Pseudocode:**
```
BACA nilai

JIKA nilai >= 85 MAKA
    TAMPILKAN "Lulus dengan Pujian"
SELAIN ITU JIKA nilai >= 60 MAKA
    TAMPILKAN "Lulus"
SELAIN ITU
    TAMPILKAN "Tidak Lulus"
AKHIR JIKA
```

**Kode C:**
```c
#include <stdio.h>

int main() {
    int nilai;

    printf("Masukkan nilai ujian (0-100): ");
    scanf("%d", &nilai);

    /* Cek dari kondisi paling ketat dulu (>=85),
       baru turun ke kondisi yang lebih longgar (>=60).
       Urutan ini penting! */
    if (nilai >= 85) {
        printf("Lulus dengan Pujian\n");
    } else if (nilai >= 60) {
        printf("Lulus\n");
    } else {
        printf("Tidak Lulus\n");
    }

    return 0;
}
```

> **Kenapa urutan kondisi penting?** Jika kamu menulis `if (nilai >= 60)` dulu, maka nilai 92 akan masuk ke blok itu dan tidak pernah sampai ke pengecekan `>= 85`. Selalu cek kondisi yang **lebih spesifik / ketat** terlebih dahulu.

---

## 2. switch-case

`switch` adalah alternatif `if-else` yang lebih bersih ketika kamu ingin membandingkan **satu variabel dengan banyak nilai tetap** (biasanya `int` atau `char`).

```c
switch (ekspresi) {
    case nilai_1:
        /* dikerjakan jika ekspresi == nilai_1 */
        break;
    case nilai_2:
        /* dikerjakan jika ekspresi == nilai_2 */
        break;
    default:
        /* dikerjakan jika tidak ada case yang cocok */
}
```

> ⚠️ **Jangan lupa `break`!** Tanpa `break`, program akan terus mengeksekusi case berikutnya (*fall-through*), yang biasanya bukan yang kamu inginkan.

**Contoh — Menu Pilihan:**
```c
#include <stdio.h>

int main() {
    int pilihan;

    printf("=== Menu ===\n");
    printf("1. Hitung luas persegi\n");
    printf("2. Hitung keliling persegi\n");
    printf("3. Keluar\n");
    printf("Pilih (1-3): ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            printf("Kamu memilih: Hitung luas persegi\n");
            break;
        case 2:
            printf("Kamu memilih: Hitung keliling persegi\n");
            break;
        case 3:
            printf("Sampai jumpa!\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }

    return 0;
}
```

**Kapan pakai `switch` vs `if-else`?**

| Situasi | Rekomendasi |
|---------|-------------|
| Membandingkan satu variabel dengan banyak nilai tetap | `switch` — lebih bersih dan mudah dibaca |
| Kondisi melibatkan rentang nilai (mis. `>= 60`) | `if-else` — `switch` tidak bisa menangani rentang |
| Kondisi melibatkan beberapa variabel sekaligus | `if-else` |

---

## 3. Perulangan (Looping)

Perulangan dipakai ketika kamu perlu mengeksekusi sekelompok instruksi **berkali-kali**. C punya tiga jenis loop.

### for — ketika jumlah iterasi sudah diketahui

Gunakan `for` saat kamu tahu persis berapa kali loop harus berjalan.

```c
for (inisialisasi; kondisi; perubahan) {
    /* blok yang diulang selama kondisi benar */
}
```

**Contoh — cetak angka 1 sampai 5:**
```c
#include <stdio.h>

int main() {
    int i;

    /* i mulai dari 1, loop selama i <= 5, tambah i sebesar 1 setiap putaran */
    for (i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    return 0;
}
```

Output:
```
1
2
3
4
5
```

---

### while — ketika kondisi berhenti tidak pasti

Gunakan `while` saat kamu tidak tahu pasti berapa kali loop harus berjalan — hanya tahu *kapan harus berhenti*.

```c
while (kondisi) {
    /* blok yang diulang selama kondisi benar */
}
```

**Contoh — minta input valid dari pengguna:**
```c
#include <stdio.h>

int main() {
    int angka;

    printf("Masukkan angka positif: ");
    scanf("%d", &angka);

    /* Terus minta input selama angka yang dimasukkan tidak positif */
    while (angka <= 0) {
        printf("Angka harus positif! Coba lagi: ");
        scanf("%d", &angka);
    }

    printf("Angka yang diterima: %d\n", angka);

    return 0;
}
```

---

### do-while — minimal satu kali dijalankan

`do-while` hampir sama dengan `while`, perbedaannya: blok kode **selalu dijalankan minimal satu kali** — kondisi dicek *setelah* iterasi pertama.

```c
do {
    /* blok yang diulang */
} while (kondisi);
```

**Contoh — tampilkan menu minimal sekali:**
```c
#include <stdio.h>

int main() {
    int pilihan;

    /* Menu pasti ditampilkan minimal sekali, lalu ulangi selama pilihan bukan 3 */
    do {
        printf("\n=== Menu ===\n");
        printf("1. Opsi A\n");
        printf("2. Opsi B\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
    } while (pilihan != 3);

    printf("Keluar dari program.\n");
    return 0;
}
```

**Perbandingan ketiga loop:**

| | `for` | `while` | `do-while` |
|---|---|---|---|
| Kondisi dicek | Sebelum tiap iterasi | Sebelum tiap iterasi | Setelah tiap iterasi |
| Minimal dijalankan | 0 kali | 0 kali | **1 kali** |
| Paling cocok untuk | Iterasi dengan jumlah tetap | Kondisi berhenti tidak pasti | Harus jalan dulu, cek kondisi kemudian |

---

## 4. break & continue

Dua kata kunci ini mengubah alur normal sebuah loop.

### break — keluar dari loop seketika

```c
#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 10; i++) {
        if (i == 6) {
            break;  /* keluar dari loop saat i mencapai 6 */
        }
        printf("%d\n", i);
    }

    /* Output: 1 2 3 4 5 (berhenti sebelum 6) */
    return 0;
}
```

### continue — lewati iterasi ini, lanjut ke berikutnya

```c
#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  /* lewati angka genap, lanjut ke i berikutnya */
        }
        printf("%d\n", i);
    }

    /* Output: 1 3 5 7 9 (hanya angka ganjil) */
    return 0;
}
```

> **Gunakan `break` dan `continue` dengan hemat.** Terlalu banyak `break`/`continue` membuat alur program sulit diikuti. Jika kondisi berhenti sudah bisa dituliskan di header `while`, lebih baik di sana saja.

---

## 5. Fungsi (Functions)

Bayangkan kamu perlu menghitung luas persegi panjang di sepuluh tempat berbeda dalam satu program. Apakah kamu harus menulis `panjang * lebar` sepuluh kali? Tidak — kamu bisa membungkusnya dalam sebuah **fungsi**.

**Fungsi** adalah blok kode yang diberi nama dan bisa dipanggil kapan saja. Dua manfaat utamanya:
- **DRY** (*Don't Repeat Yourself*) — tulis sekali, pakai berkali-kali.
- **Keterbacaan** — program jadi lebih mudah dibaca dan di-debug.

### Anatomi Fungsi

```c
tipe_kembalian nama_fungsi(tipe param1, tipe param2) {
    /* isi fungsi */
    return nilai;   /* kembalikan hasil */
}
```

| Bagian | Penjelasan |
|--------|-----------|
| `tipe_kembalian` | Tipe data nilai yang dikembalikan. Gunakan `void` jika tidak mengembalikan apa-apa. |
| `nama_fungsi` | Nama yang mendeskripsikan apa yang dilakukan fungsi. |
| `param1, param2` | Input yang diterima fungsi. Boleh tidak ada parameter. |
| `return nilai` | Mengembalikan hasil ke pemanggil. Wajib ada jika tipe kembalian bukan `void`. |

---

### Contoh 1 — Fungsi dengan Nilai Kembalian

```c
#include <stdio.h>

/* Definisi fungsi: menerima panjang dan lebar, mengembalikan luas */
int hitung_luas(int panjang, int lebar) {
    int luas = panjang * lebar;
    return luas;
}

int main() {
    int hasil;

    /* Memanggil fungsi dan menyimpan hasilnya */
    hasil = hitung_luas(5, 3);
    printf("Luas: %d\n", hasil);         /* Output: Luas: 15 */

    /* Fungsi yang sama dipanggil lagi dengan nilai berbeda */
    hasil = hitung_luas(10, 4);
    printf("Luas: %d\n", hasil);         /* Output: Luas: 40 */

    return 0;
}
```

---

### Contoh 2 — Fungsi void (tanpa nilai kembalian)

Jika fungsi hanya melakukan sesuatu (seperti mencetak) tanpa perlu mengembalikan nilai, gunakan `void`.

```c
#include <stdio.h>

/* Fungsi void: mencetak garis pemisah — tidak mengembalikan nilai */
void cetak_garis() {
    printf("--------------------\n");
}

int main() {
    cetak_garis();
    printf("Laporan Nilai Siswa\n");
    cetak_garis();

    return 0;
}
```

Output:
```
--------------------
Laporan Nilai Siswa
--------------------
```

---

### Urutan Definisi & Prototype

Di C, fungsi harus **didefinisikan sebelum dipanggil** — atau kamu bisa mendeklarasikan *prototype*-nya di atas, lalu definisi lengkapnya di bawah:

```c
#include <stdio.h>

/* Prototype: memberitahu compiler bahwa fungsi ini ada */
int hitung_luas(int panjang, int lebar);

int main() {
    printf("Luas: %d\n", hitung_luas(5, 3));
    return 0;
}

/* Definisi lengkap di bawah main */
int hitung_luas(int panjang, int lebar) {
    return panjang * lebar;
}
```

---

## 6. Rekursi Dasar (Optional/Cukup tahu saja)

**Rekursi** adalah teknik di mana sebuah fungsi **memanggil dirinya sendiri**. Konsep ini terdengar membingungkan, tapi sangat berguna untuk masalah yang bisa dipecah menjadi sub-masalah yang lebih kecil dari bentuk yang sama.

Setiap fungsi rekursif wajib punya dua bagian:

| Bagian | Penjelasan |
|--------|-----------|
| **Base case** | Kondisi berhenti — *tanpa ini, rekursi tidak pernah berhenti* dan program akan crash. |
| **Recursive case** | Fungsi memanggil dirinya sendiri dengan input yang *lebih kecil / lebih sederhana*. |

---

### Contoh: Faktorial

Faktorial didefinisikan sebagai:
- `faktorial(0) = 1` ← **base case**
- `faktorial(n) = n × faktorial(n - 1)` ← **recursive case**

```c
#include <stdio.h>

/* Versi REKURSI */
int faktorial_rekursi(int n) {
    /* Base case: hentikan rekursi saat n mencapai 0 */
    if (n == 0) {
        return 1;
    }

    /* Recursive case: n dikali hasil faktorial dari (n-1) */
    return n * faktorial_rekursi(n - 1);
}

/* Versi LOOP — untuk perbandingan */
int faktorial_loop(int n) {
    int hasil = 1;
    int i;

    for (i = 1; i <= n; i++) {
        hasil = hasil * i;
    }

    return hasil;
}

int main() {
    int angka = 5;

    printf("Faktorial(%d) via rekursi : %d\n", angka, faktorial_rekursi(angka));
    printf("Faktorial(%d) via loop    : %d\n", angka, faktorial_loop(angka));

    return 0;
}
```

Output:
```
Faktorial(5) via rekursi : 120
Faktorial(5) via loop    : 120
```

**Bagaimana rekursi faktorial(5) bekerja:**
```
faktorial(5)
  = 5 * faktorial(4)
  = 5 * 4 * faktorial(3)
  = 5 * 4 * 3 * faktorial(2)
  = 5 * 4 * 3 * 2 * faktorial(1)
  = 5 * 4 * 3 * 2 * 1 * faktorial(0)
  = 5 * 4 * 3 * 2 * 1 * 1   ← base case tercapai, mulai balik
  = 120
```

> ⚠️ **Lupa base case = program crash.** Jika base case tidak ada atau tidak pernah tercapai, fungsi akan terus memanggil dirinya sampai memori habis (*stack overflow*). Selalu pastikan recursive case membawa n *menuju* base case.

**Loop vs Rekursi — kapan pakai yang mana?**

| | Loop | Rekursi |
|---|---|---|
| Performa | Lebih efisien (tidak ada overhead pemanggilan fungsi) | Sedikit lebih lambat |
| Keterbacaan | Lebih familiar untuk pemula | Lebih elegan untuk masalah yang secara alami rekursif (pohon, graf) |
| Risiko | Lebih aman | Risiko stack overflow jika base case salah |

Untuk sekarang, yang paling penting adalah **memahami konsep base case dan recursive case**. Rekursi akan banyak dipakai saat mempelajari Tree dan Graph nanti.

---

## 7. AI untuk Boilerplate

**Boilerplate** adalah kode yang polanya repetitif dan bisa diprediksi — misalnya fungsi-fungsi yang melakukan operasi serupa pada berbagai tipe data. AI sangat efektif untuk menghasilkan kode seperti ini.

### Contoh: Minta AI Generate Fungsi

**Prompt yang baik:**
> *"Saya belajar bahasa C untuk pemula. Tolong buatkan fungsi bernama `cetak_info_siswa` yang menerima parameter: `nama` (string), `usia` (int), dan `nilai` (float). Fungsi ini mencetak ketiga informasi itu dalam format yang rapi, tipe kembalian void. Tambahkan komentar singkat untuk tiap baris yang penting."*

**Output AI (contoh):**
```c
/* Mencetak informasi satu siswa ke layar */
void cetak_info_siswa(char nama[], int usia, float nilai) {
    printf("Nama  : %s\n", nama);    /* cetak nama sebagai string */
    printf("Usia  : %d tahun\n", usia); /* cetak usia sebagai integer */
    printf("Nilai : %.2f\n", nilai); /* cetak nilai dengan 2 desimal */
}
```

### Yang Harus Kamu Lakukan Setelah Dapat Kode dari AI

1. **Baca setiap baris** — pastikan kamu mengerti apa yang dilakukan tiap baris.
2. **Cek tipe data** — apakah tipe parameter sudah sesuai? `char[]` untuk string? `float` untuk desimal?
3. **Kompilasi dan tes** — jangan anggap kode AI selalu benar. Compile, jalankan, dan cek outputnya.
4. **Modifikasi sendiri** — coba ubah satu hal kecil (nama parameter, format cetak) untuk memastikan kamu benar-benar mengerti.

> **AI yang baik menghasilkan kode yang *masuk akal*, bukan kode yang *pasti benar*.** Tugasmu adalah memvalidasi — dan untuk itu, kamu butuh pemahaman yang solid.

---

## Ringkasan Pertemuan 2

| Konsep | Inti |
|--------|------|
| `if / else if / else` | Percabangan berdasarkan kondisi; cek kondisi paling ketat dulu |
| `switch-case` | Alternatif if-else untuk nilai tetap; jangan lupa `break` |
| `for` | Loop dengan jumlah iterasi tetap |
| `while` | Loop selama kondisi benar; bisa 0 kali |
| `do-while` | Seperti `while` tapi selalu jalan minimal 1 kali |
| `break` / `continue` | Keluar dari loop / lewati iterasi saat ini |
| Fungsi | Bungkus kode berulang; `return` untuk nilai kembalian, `void` jika tidak ada |
| Rekursi | Fungsi memanggil dirinya sendiri; wajib punya base case |
| AI untuk boilerplate | Generate fungsi repetitif, lalu **validasi sendiri** |

**Preview Pertemuan 3:** Array & String — menyimpan banyak data dalam satu variabel.
