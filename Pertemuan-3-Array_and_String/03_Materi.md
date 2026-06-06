# Pertemuan 3 — Array & String

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Array 1D](#1-array-1d)
2. [Operasi Dasar Array](#2-operasi-dasar-array)
3. [Array 2D (Matriks)](#3-array-2d-matriks)
4. [String di C](#4-string-di-c)
5. [Library string.h](#5-library-stringh)
6. [Catatan Keamanan: Ukuran Buffer](#6-catatan-keamanan-ukuran-buffer)
7. [AI untuk Optimasi String](#7-ai-untuk-optimasi-string)

---

## 1. Array 1D

Sejauh ini, setiap variabel yang kamu buat hanya menyimpan **satu nilai**. Bagaimana jika kamu perlu menyimpan nilai ujian 30 siswa? Apakah kamu harus menulis `nilai1`, `nilai2`, ..., `nilai30`?

**Array** adalah solusinya — sebuah variabel yang menyimpan **banyak nilai bertipe sama** secara berurutan di memori, dan bisa diakses lewat satu nama dengan indeks.

### Deklarasi & Inisialisasi

```c
/* Deklarasi: tipe_data nama_array[ukuran]; */
int nilai[5];              /* array kosong, 5 elemen bertipe int */

/* Inisialisasi langsung saat deklarasi */
int suhu[5] = {31, 29, 33, 30, 28};

/* Jika ukuran tidak disebutkan, compiler hitung otomatis */
int angka[] = {10, 20, 30, 40, 50};   /* ukuran = 5 */
```

### Indexing — Dimulai dari 0

Di C, indeks array **selalu dimulai dari 0**, bukan 1. Array berukuran `N` punya indeks dari `0` sampai `N-1`.

```
suhu[0] suhu[1] suhu[2] suhu[3] suhu[4]
  31      29      33      30      28
  ↑                               ↑
indeks 0                      indeks 4 (bukan 5!)
```

```c
#include <stdio.h>

int main() {
    int suhu[5] = {31, 29, 33, 30, 28};

    printf("Suhu hari pertama  : %d\n", suhu[0]);  /* 31 */
    printf("Suhu hari terakhir : %d\n", suhu[4]);  /* 28 */

    /* Ubah nilai elemen tertentu */
    suhu[2] = 35;
    printf("Suhu hari ketiga (baru) : %d\n", suhu[2]);  /* 35 */

    return 0;
}
```

> ⚠️ **Out-of-bounds: kesalahan paling umum dengan array.** Jika array berukuran 5, mengakses `suhu[5]` adalah *undefined behavior* — program bisa crash atau menghasilkan nilai acak. Compiler tidak selalu memberi peringatan. Selalu pastikan indeks berada di rentang `0` hingga `ukuran - 1`.

### Iterasi Array dengan Loop

```c
#include <stdio.h>

int main() {
    int nilai[6] = {75, 88, 60, 92, 70, 85};
    int ukuran = 6;
    int i;

    /* Iterasi dari indeks 0 sampai ukuran-1 */
    for (i = 0; i < ukuran; i++) {
        printf("nilai[%d] = %d\n", i, nilai[i]);
    }

    return 0;
}
```

Output:
```
nilai[0] = 75
nilai[1] = 88
nilai[2] = 60
nilai[3] = 92
nilai[4] = 70
nilai[5] = 85
```

---

## 2. Operasi Dasar Array

### Contoh Kasus: Statistik Sederhana

**Problem:** Program menerima 5 bilangan ke dalam array, lalu menampilkan total, rata-rata, nilai terbesar, dan nilai terkecil.

```c
#include <stdio.h>

int main() {
    int data[5];
    int i;
    int total   = 0;
    int terbesar;
    int terkecil;

    /* Isi array dari input pengguna */
    printf("Masukkan 5 bilangan:\n");
    for (i = 0; i < 5; i++) {
        printf("  data[%d] = ", i);
        scanf("%d", &data[i]);
    }

    /* Inisialisasi terbesar & terkecil dari elemen pertama */
    terbesar = data[0];
    terkecil = data[0];

    /* Satu kali iterasi untuk hitung semua sekaligus */
    for (i = 0; i < 5; i++) {
        total = total + data[i];

        if (data[i] > terbesar) {
            terbesar = data[i];
        }
        if (data[i] < terkecil) {
            terkecil = data[i];
        }
    }

    printf("\nTotal    : %d\n", total);
    printf("Rata-rata: %.1f\n", (float)total / 5);  /* cast ke float agar tidak dibulatkan */
    printf("Terbesar : %d\n", terbesar);
    printf("Terkecil : %d\n", terkecil);

    return 0;
}
```

Contoh output:
```
Masukkan 5 bilangan:
  data[0] = 70
  data[1] = 85
  data[2] = 60
  data[3] = 92
  data[4] = 78

Total    : 385
Rata-rata: 77.0
Terbesar : 92
Terkecil : 60
```

> **Kenapa `(float)total / 5`?** Di C, pembagian dua integer menghasilkan integer (sisa dibuang). `385 / 5 = 77` — kebetulan pas. Tapi `383 / 5 = 76`, bukan `76.6`. Dengan `(float)total`, kita "paksa" total menjadi float dulu sebelum dibagi, sehingga hasilnya desimal.

---

## 3. Array 2D (Matriks)

Array 2D adalah "array of arrays" — bayangkan sebuah tabel dengan baris dan kolom.

```
         kolom 0   kolom 1   kolom 2
baris 0 [   1    ][   2    ][   3    ]
baris 1 [   4    ][   5    ][   6    ]
baris 2 [   7    ][   8    ][   9    ]
```

### Deklarasi & Akses

```c
/* tipe_data nama[jumlah_baris][jumlah_kolom]; */
int matriks[3][3] = {
    {1, 2, 3},   /* baris 0 */
    {4, 5, 6},   /* baris 1 */
    {7, 8, 9}    /* baris 2 */
};

/* Akses elemen: nama[baris][kolom] */
printf("%d\n", matriks[0][0]);  /* 1 — baris 0, kolom 0 */
printf("%d\n", matriks[1][2]);  /* 6 — baris 1, kolom 2 */
printf("%d\n", matriks[2][1]);  /* 8 — baris 2, kolom 1 */
```

### Iterasi dengan Nested Loop

Untuk memproses seluruh elemen array 2D, kita butuh dua loop bersarang: loop luar untuk baris, loop dalam untuk kolom.

```c
#include <stdio.h>

int main() {
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int baris, kolom;

    printf("Isi matriks 3x3:\n");

    for (baris = 0; baris < 3; baris++) {
        for (kolom = 0; kolom < 3; kolom++) {
            printf("%3d", matriks[baris][kolom]);  /* %3d: lebar kolom 3 agar rapi */
        }
        printf("\n");  /* pindah baris setelah loop kolom selesai */
    }

    return 0;
}
```

Output:
```
Isi matriks 3x3:
  1  2  3
  4  5  6
  7  8  9
```

---

## 4. String di C

Di bahasa lain, string adalah tipe data tersendiri. Di C, **string adalah array of char** yang diakhiri dengan karakter khusus: **null terminator `\0`**.

```
String "Halo" disimpan sebagai:
 'H'  'a'  'l'  'o'  '\0'
[0]  [1]  [2]  [3]  [4]
```

Karakter `\0` (nilai ASCII 0) menandai akhir string. Tanpa `\0`, fungsi-fungsi string tidak tahu di mana string berakhir.

### Deklarasi String

```c
/* Cara 1: inisialisasi dengan string literal (null terminator otomatis ditambahkan) */
char nama[10] = "Budi";     /* ukuran 10, isi: 'B','u','d','i','\0',0,0,0,0,0 */

/* Cara 2: inisialisasi karakter per karakter (harus tambah \0 sendiri!) */
char kota[6] = {'J','a','k','a','r','t','a','\0'};  /* perhatikan ukuran cukup */

/* Cara 3: string tanpa ukuran eksplisit (compiler hitung otomatis) */
char judul[] = "Belajar C";  /* ukuran = 10 (9 karakter + 1 null terminator) */
```

> ⚠️ **Selalu siapkan ruang untuk `\0`.** String "Budi" butuh array berukuran minimal 5 (4 huruf + 1 null terminator). Jika kamu deklarasikan `char nama[4] = "Budi"`, null terminator tidak akan masuk dan akan terjadi bug.

### Input & Output String

```c
#include <stdio.h>

int main() {
    char nama[50];

    /* printf dengan %s untuk mencetak string */
    printf("Masukkan nama kamu: ");

    /* scanf dengan %s membaca sampai spasi — tidak cocok untuk nama dengan spasi */
    scanf("%s", nama);     /* perhatikan: tidak perlu & karena nama sudah berupa alamat */

    printf("Halo, %s!\n", nama);

    return 0;
}
```

**Bagaimana jika nama mengandung spasi?** Gunakan `fgets`:

```c
#include <stdio.h>

int main() {
    char nama_lengkap[50];

    printf("Masukkan nama lengkap: ");

    /* fgets(array, ukuran_maks, stdin) — membaca satu baris termasuk spasi */
    fgets(nama_lengkap, 50, stdin);

    printf("Halo, %s", nama_lengkap);  /* fgets sudah menyimpan '\n', tidak perlu tambah \n */

    return 0;
}
```

> `fgets` menyimpan karakter newline (`\n`) di akhir string jika ada. Ini kadang menyebabkan baris kosong ekstra saat dicetak. Untuk sementara, ini bisa diabaikan — kita akan belajar cara membersihkannya nanti.

---

## 5. Library `<string.h>`

C menyediakan fungsi-fungsi siap pakai untuk manipulasi string di library `<string.h>`. Tambahkan `#include <string.h>` untuk menggunakannya.

### Fungsi-fungsi Utama

#### `strlen` — panjang string

```c
#include <stdio.h>
#include <string.h>

int main() {
    char kata[] = "Halo";
    int panjang = strlen(kata);   /* menghitung karakter sampai \0, tidak termasuk \0 */

    printf("Panjang '%s' = %d\n", kata, panjang);  /* Output: Panjang 'Halo' = 4 */

    return 0;
}
```

#### `strcpy` — salin string

```c
#include <stdio.h>
#include <string.h>

int main() {
    char sumber[] = "Selamat pagi";
    char tujuan[20];   /* pastikan ukuran tujuan cukup menampung isi sumber + \0 */

    strcpy(tujuan, sumber);   /* salin isi sumber ke tujuan */

    printf("Tujuan: %s\n", tujuan);   /* Output: Tujuan: Selamat pagi */

    return 0;
}
```

> ⚠️ **Jangan gunakan `tujuan = sumber`** untuk menyalin string — di C, assignment `=` pada array tidak menyalin isi, melainkan mencoba menyalin alamat, yang akan menyebabkan error kompilasi. Selalu gunakan `strcpy`.

#### `strcmp` — bandingkan dua string

```c
#include <stdio.h>
#include <string.h>

int main() {
    char kata1[] = "apel";
    char kata2[] = "pisang";
    char kata3[] = "apel";

    int hasil1 = strcmp(kata1, kata2);  /* negatif: kata1 < kata2 secara alfabetis */
    int hasil2 = strcmp(kata1, kata3);  /* 0: kata1 == kata3 */
    int hasil3 = strcmp(kata2, kata1);  /* positif: kata2 > kata1 secara alfabetis */

    /* Yang paling sering dipakai: cek apakah dua string sama */
    if (strcmp(kata1, kata3) == 0) {
        printf("'%s' dan '%s' adalah sama.\n", kata1, kata3);
    }

    return 0;
}
```

> ⚠️ **Jangan bandingkan string dengan `==`.** `kata1 == kata2` membandingkan *alamat memori*, bukan isinya — hasilnya hampir selalu salah. Selalu gunakan `strcmp`.

#### `strcat` — gabungkan dua string

```c
#include <stdio.h>
#include <string.h>

int main() {
    char salam[30] = "Selamat ";    /* pastikan ukuran cukup untuk hasil gabungan */
    char waktu[]   = "pagi!";

    strcat(salam, waktu);   /* tambahkan isi waktu ke akhir salam */

    printf("%s\n", salam);  /* Output: Selamat pagi! */

    return 0;
}
```

### Ringkasan Fungsi `<string.h>`

| Fungsi | Kegunaan | Contoh |
|--------|----------|--------|
| `strlen(s)` | Panjang string `s` | `strlen("Halo")` → `4` |
| `strcpy(dst, src)` | Salin `src` ke `dst` | `strcpy(tujuan, sumber)` |
| `strcmp(s1, s2)` | Bandingkan `s1` dan `s2`; 0 jika sama | `strcmp("a","a")` → `0` |
| `strcat(dst, src)` | Tambahkan `src` ke akhir `dst` | `strcat(hasil, tambahan)` |

---

## 6. Catatan Keamanan: Ukuran Buffer

Ini adalah pengantar untuk topik yang akan lebih dalam di Pertemuan 4 (Pointer & Dynamic Memory).

**Buffer overflow** terjadi ketika data yang ditulis ke array melebihi ukurannya. Ini adalah salah satu bug paling berbahaya dalam C — bisa menyebabkan crash, data korup, atau celah keamanan.

```c
char nama[5];
strcpy(nama, "Alexander");  /* BAHAYA! "Alexander" = 9 karakter + \0 = 10 byte,
                                tapi nama hanya muat 5 byte.
                                Kode ini akan menulis ke memori di luar array! */
```

**Aturan sederhana untuk sekarang:**
1. Selalu beri ukuran array yang cukup — lebih besar dari yang kamu perkirakan butuhkan.
2. Sebelum `strcpy` atau `strcat`, pastikan array tujuan muat untuk isi sumber + null terminator.
3. Gunakan `fgets(buffer, ukuran, stdin)` dan bukan `gets()` — `gets()` tidak mengecek ukuran sama sekali.

---

## 7. AI untuk Optimasi String

Operasi manipulasi string — seperti membalik string, mengubah huruf besar/kecil, atau memecah string berdasarkan pemisah — sering bersifat repetitif dan rawan salah. AI berguna untuk menghasilkan kerangka kode ini dengan cepat.

### Contoh Prompt yang Baik

> *"Saya belajar bahasa C dan sedang berlatih manipulasi string. Tolong buatkan fungsi `balik_string(char str[])` yang membalik isi string di tempat (in-place), tanpa menggunakan array tambahan. Fungsi bertipe void. Tambahkan komentar yang menjelaskan logika tiap langkah, dan sertakan contoh cara memanggilnya dari main."*

### Contoh Output AI

```c
#include <stdio.h>
#include <string.h>

/* Membalik isi string str secara in-place (langsung di array yang sama) */
void balik_string(char str[]) {
    int kiri  = 0;
    int kanan = strlen(str) - 1;  /* indeks karakter terakhir */
    char temp;

    /* Tukar karakter dari ujung kiri dan kanan, maju ke tengah */
    while (kiri < kanan) {
        temp      = str[kiri];   /* simpan sementara */
        str[kiri] = str[kanan];  /* tukar */
        str[kanan]= temp;
        kiri++;
        kanan--;
    }
}

int main() {
    char kata[] = "Halo";
    balik_string(kata);
    printf("%s\n", kata);  /* Output: olaH */
    return 0;
}
```

### Yang Harus Kamu Verifikasi

1. **Apakah logikanya benar?** Trace manual: untuk "Halo" (panjang 4), `kiri=0`, `kanan=3` → tukar H↔o, lalu `kiri=1`, `kanan=2` → tukar a↔l → "olaH". ✓
2. **Apakah ada potensi out-of-bounds?** Kondisi `kiri < kanan` memastikan tidak ada akses di luar string. ✓
3. **Bagaimana untuk string kosong atau panjang 1?** `strlen("") = 0` → `kanan = -1` → kondisi `kiri < kanan` langsung salah, loop tidak jalan. ✓

---

## Ringkasan Pertemuan 3

| Konsep | Inti |
|--------|------|
| Array 1D | `tipe nama[ukuran]`; indeks 0-based; akses `nama[i]`; iterasi dengan `for` |
| Out-of-bounds | Indeks valid: 0 sampai `ukuran-1`; melebihi batas → undefined behavior |
| Array 2D | `tipe nama[baris][kolom]`; akses `nama[b][k]`; iterasi dengan nested loop |
| String | Array of char diakhiri `\0`; selalu siapkan ruang untuk null terminator |
| Input string | `scanf("%s", s)` untuk kata tunggal; `fgets(s, n, stdin)` untuk kalimat |
| `strlen` | Hitung panjang string (tidak termasuk `\0`) |
| `strcpy` | Salin string; jangan pakai `=` untuk string |
| `strcmp` | Bandingkan string; jangan pakai `==` untuk string; hasil 0 = sama |
| `strcat` | Gabungkan string; pastikan buffer tujuan cukup besar |
| Buffer safety | Selalu beri ukuran array cukup; hindari `gets()` |

**Preview Pertemuan 4:** Pointer & Dynamic Memory — memahami alamat memori, pointer, dan `malloc`/`free`.
