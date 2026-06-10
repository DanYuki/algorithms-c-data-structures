# Pertemuan 5 — Struct & Modular Programming

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Mengapa Struct?](#1-mengapa-struct)
2. [Mendefinisikan & Menggunakan Struct](#2-mendefinisikan--menggunakan-struct)
3. [typedef: Menyederhanakan Nama Tipe](#3-typedef-menyederhanakan-nama-tipe)
4. [Pointer ke Struct & Operator `->`](#4-pointer-ke-struct--operator--)
5. [Struct sebagai Parameter Fungsi](#5-struct-sebagai-parameter-fungsi)
6. [Array of Struct](#6-array-of-struct)
7. [Modular Programming: Header & Implementasi](#7-modular-programming-header--implementasi)
8. [AI untuk Kerangka Modular](#8-ai-untuk-kerangka-modular)

---

## 1. Mengapa Struct?

Bayangkan kamu ingin menyimpan data satu mahasiswa: nama, NIM, dan IPK. Cara paling sederhana adalah membuat tiga variabel terpisah:

```c
char nama[50];
char nim[15];
float ipk;
```

Ini masih oke untuk satu mahasiswa. Tapi bagaimana kalau ada 30 mahasiswa? Kamu akan punya 90 variabel yang sulit dikelola dan mudah tercampur.

**Struct** (structure) menyelesaikan masalah ini. Struct memungkinkan kamu mengelompokkan beberapa variabel yang saling berkaitan ke dalam satu tipe data baru.

Analogi: bayangkan formulir mahasiswa. Satu formulir berisi beberapa kolom (nama, NIM, IPK). Struct adalah cetakan formulirnya — sekali mendefinisikan cetakan, kamu bisa membuat banyak salinan formulir yang terisi.

---

## 2. Mendefinisikan & Menggunakan Struct

### Mendefinisikan Struct

```c
struct Mahasiswa {
    char nama[50];   /* anggota 1: nama */
    char nim[15];    /* anggota 2: nomor induk mahasiswa */
    float ipk;       /* anggota 3: indeks prestasi kumulatif */
};
```

`struct Mahasiswa` adalah tipe data baru. Kurung kurawal berisi daftar **anggota** (members) beserta tipe datanya masing-masing.

### Membuat Variabel Struct

```c
struct Mahasiswa mhs1;         /* satu variabel bertipe struct Mahasiswa */
struct Mahasiswa mhs2, mhs3;   /* bisa langsung buat beberapa sekaligus */
```

### Mengakses Anggota: Operator `.`

Gunakan operator titik (`.`) untuk membaca atau menulis anggota struct.

```c
#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    char nim[15];
    float ipk;
};

int main() {
    struct Mahasiswa mhs1;

    /* mengisi anggota struct */
    strcpy(mhs1.nama, "Andi Pratama");  /* string harus pakai strcpy */
    strcpy(mhs1.nim,  "2024001");
    mhs1.ipk = 3.75;

    /* membaca anggota struct */
    printf("Nama : %s\n", mhs1.nama);
    printf("NIM  : %s\n", mhs1.nim);
    printf("IPK  : %.2f\n", mhs1.ipk);

    return 0;
}
```

Output:
```
Nama : Andi Pratama
NIM  : 2024001
IPK  : 3.75
```

### Inisialisasi Langsung

Kamu juga bisa mengisi nilai saat variabel dibuat, dengan urutan sesuai urutan anggota:

```c
struct Mahasiswa mhs2 = {"Budi Santoso", "2024002", 3.50};
```

---

## 3. typedef: Menyederhanakan Nama Tipe

Menulis `struct Mahasiswa` setiap kali terasa panjang. `typedef` memungkinkan kamu membuat **alias** (nama lain) untuk tipe data.

### Pola Umum

```c
typedef struct {
    char nama[50];
    char nim[15];
    float ipk;
} Mahasiswa;   /* Mahasiswa adalah alias untuk struct ini */
```

Sekarang kamu bisa menulis `Mahasiswa` saja, tanpa kata `struct` di depannya:

```c
Mahasiswa mhs1;              /* sama dengan: struct Mahasiswa mhs1 */
Mahasiswa mhs2, mhs3;
```

> **Catatan:** Jika struct perlu mereferensikan dirinya sendiri (seperti pada linked list nanti), kamu tetap harus memberi nama struct-nya. Untuk sekarang, pola `typedef struct { ... } NamaTipe;` sudah cukup.

### Contoh Lengkap dengan typedef

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[50];
    char nim[15];
    float ipk;
} Mahasiswa;

int main() {
    Mahasiswa mhs1;

    strcpy(mhs1.nama, "Citra Dewi");
    strcpy(mhs1.nim,  "2024003");
    mhs1.ipk = 3.90;

    printf("Nama : %s\n", mhs1.nama);
    printf("NIM  : %s\n", mhs1.nim);
    printf("IPK  : %.2f\n", mhs1.ipk);

    return 0;
}
```

---

## 4. Pointer ke Struct & Operator `->`

Ketika kamu punya **pointer yang menunjuk ke sebuah struct**, ada dua cara mengakses anggotanya:

| Cara | Sintaks | Keterangan |
|------|---------|------------|
| Via dereference | `(*ptr).nama` | Dereference dulu, baru akses anggota |
| Via `->` (shortcut) | `ptr->nama` | Cara ringkas yang sama hasilnya |

`ptr->nama` persis sama dengan `(*ptr).nama`. Tanda kurung di `(*ptr)` wajib ada karena `.` punya prioritas lebih tinggi dari `*`.

> Dalam praktik, **selalu gunakan `->` saat bekerja dengan pointer ke struct** — lebih bersih dan jarang keliru.

### Contoh

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[50];
    char nim[15];
    float ipk;
} Mahasiswa;

int main() {
    Mahasiswa mhs1;
    Mahasiswa *ptr = &mhs1;   /* ptr menunjuk ke mhs1 */

    /* mengisi via pointer */
    strcpy(ptr->nama, "Dani Firmansyah");
    strcpy(ptr->nim,  "2024004");
    ptr->ipk = 3.60;

    /* membaca — dua cara yang setara */
    printf("Nama (via ->)       : %s\n", ptr->nama);
    printf("Nama (via (*ptr).)  : %s\n", (*ptr).nama);  /* sama saja */
    printf("IPK                 : %.2f\n", ptr->ipk);

    return 0;
}
```

Output:
```
Nama (via ->)       : Dani Firmansyah
Nama (via (*ptr).)  : Dani Firmansyah
IPK                 : 3.60
```

---

## 5. Struct sebagai Parameter Fungsi

### By Value vs By Pointer

Ada dua cara mengoper struct ke fungsi:

**By Value** — struct disalin seluruhnya. Perubahan di dalam fungsi **tidak** berdampak ke variabel asli.

```c
void tampilkan_mahasiswa(Mahasiswa mhs) {
    printf("Nama : %s | IPK : %.2f\n", mhs.nama, mhs.ipk);
}
```

**By Pointer** — hanya alamat yang dikirim. Perubahan di dalam fungsi **berdampak** ke variabel asli. Lebih efisien untuk struct besar.

```c
void update_ipk(Mahasiswa *mhs, float ipk_baru) {
    mhs->ipk = ipk_baru;   /* langsung ubah struct asli */
}
```

### Kapan Pakai Yang Mana?

- **By value:** saat fungsi hanya *membaca* data dan struct-nya kecil.
- **By pointer:** saat fungsi perlu *mengubah* data, atau struct-nya besar (efisiensi memori).

### Contoh Lengkap

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[50];
    char nim[15];
    float ipk;
} Mahasiswa;

/* by value — hanya baca, tidak ubah */
void tampilkan(Mahasiswa mhs) {
    printf("%-20s | %-10s | %.2f\n", mhs.nama, mhs.nim, mhs.ipk);
}

/* by pointer — bisa ubah isi struct asli */
void update_ipk(Mahasiswa *mhs, float ipk_baru) {
    mhs->ipk = ipk_baru;
}

int main() {
    Mahasiswa mhs1 = {"Eka Saputra", "2024005", 3.20};

    printf("%-20s | %-10s | IPK\n", "Nama", "NIM");
    printf("--------------------------------------\n");

    tampilkan(mhs1);            /* tampilkan sebelum update */
    update_ipk(&mhs1, 3.55);   /* kirim alamat agar bisa diubah */
    tampilkan(mhs1);            /* tampilkan sesudah update */

    return 0;
}
```

Output:
```
Nama                 | NIM        | IPK
--------------------------------------
Eka Saputra          | 2024005    | 3.20
Eka Saputra          | 2024005    | 3.55
```

---

## 6. Array of Struct

Untuk menyimpan banyak data sejenis, gunakan array of struct — seperti tabel dengan baris-baris data mahasiswa.

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[50];
    char nim[15];
    float ipk;
} Mahasiswa;

int main() {
    /* array berisi 3 struct Mahasiswa */
    Mahasiswa kelas[3] = {
        {"Andi Pratama",   "2024001", 3.75},
        {"Budi Santoso",   "2024002", 3.50},
        {"Citra Dewi",     "2024003", 3.90}
    };

    printf("%-20s | %-10s | IPK\n", "Nama", "NIM");
    printf("--------------------------------------\n");

    /* iterasi seperti array biasa */
    for (int i = 0; i < 3; i++) {
        printf("%-20s | %-10s | %.2f\n",
               kelas[i].nama, kelas[i].nim, kelas[i].ipk);
    }

    return 0;
}
```

Output:
```
Nama                 | NIM        | IPK
--------------------------------------
Andi Pratama         | 2024001    | 3.75
Budi Santoso         | 2024002    | 3.50
Citra Dewi           | 2024003    | 3.90
```

> `kelas[i].nama` — akses anggota `nama` dari elemen ke-`i` pada array `kelas`.

---

## 7. Modular Programming: Header & Implementasi

Sejauh ini semua kode ditulis dalam satu file. Untuk program yang lebih besar, memecah kode ke beberapa file membuat proyek lebih rapi, mudah dibaca, dan mudah dirawat. Inilah yang disebut **modular programming**.

### Peran Masing-masing File

| File | Isi | Analogi |
|------|-----|---------|
| `.h` (header) | Deklarasi: struct, tipe, prototipe fungsi | Daftar isi / kontrak |
| `.c` (implementasi) | Definisi: isi fungsi yang sebenarnya | Isi bukunya |
| `main.c` | Titik masuk program, memanggil fungsi | Pembaca yang menggunakan buku |

### Include Guard

Setiap file header **harus** memiliki include guard untuk mencegah header yang sama di-include lebih dari sekali (yang akan menyebabkan error "redefinition"):

```c
#ifndef MAHASISWA_H   /* jika MAHASISWA_H belum didefinisikan... */
#define MAHASISWA_H   /* ...definisikan sekarang */

/* isi header di sini */

#endif                /* akhir dari blok #ifndef */
```

Nama makro (`MAHASISWA_H`) biasanya ditulis besar mengikuti nama file (`mahasiswa.h`).

### Contoh: Modul Mahasiswa

Kita pecah program mahasiswa menjadi tiga file:

**`mahasiswa.h`** — deklarasi struct dan prototipe fungsi:

```c
#ifndef MAHASISWA_H
#define MAHASISWA_H

typedef struct {
    char nama[50];
    char nim[15];
    float ipk;
} Mahasiswa;

/* prototipe fungsi — hanya tanda tangan, belum ada isinya */
void tampilkan(Mahasiswa mhs);
void update_ipk(Mahasiswa *mhs, float ipk_baru);

#endif
```

**`mahasiswa.c`** — implementasi (isi) fungsi:

```c
#include <stdio.h>
#include "mahasiswa.h"   /* include header sendiri, pakai tanda kutip */

void tampilkan(Mahasiswa mhs) {
    printf("%-20s | %-10s | %.2f\n", mhs.nama, mhs.nim, mhs.ipk);
}

void update_ipk(Mahasiswa *mhs, float ipk_baru) {
    mhs->ipk = ipk_baru;
}
```

**`main.c`** — program utama:

```c
#include <stdio.h>
#include <string.h>
#include "mahasiswa.h"   /* cukup include header-nya */

int main() {
    Mahasiswa mhs1 = {"Andi Pratama", "2024001", 3.75};

    printf("%-20s | %-10s | IPK\n", "Nama", "NIM");
    printf("--------------------------------------\n");

    tampilkan(mhs1);
    update_ipk(&mhs1, 3.85);
    tampilkan(mhs1);

    return 0;
}
```

### Kompilasi Multi-file

Kompilasi semua file `.c` sekaligus (file `.h` tidak dikompilasi secara langsung — ia di-include oleh `.c`):

```bash
gcc mahasiswa.c main.c -o program
./program
```

Atau kompilasi terpisah lalu link:

```bash
gcc -c mahasiswa.c -o mahasiswa.o   /* kompilasi jadi object file */
gcc -c main.c      -o main.o
gcc mahasiswa.o main.o -o program   /* linking */
./program
```

> 💡 Perbedaan `#include "file.h"` vs `#include <file.h>`:
> - Tanda kutip `"..."` → cari di folder proyek saat ini (untuk header buatan sendiri).
> - Tanda kurung sudut `<...>` → cari di direktori sistem (untuk header standar seperti `stdio.h`).

---

## 8. AI untuk Kerangka Modular

AI bisa membantu meng-generate kerangka modular (header + implementasi + main) dengan cepat, tapi **kamu harus memvalidasinya** sebelum digunakan.

### Contoh Prompt yang Efektif

```
Buatkan kerangka modular program C untuk modul "Buku Perpustakaan".
Satu buku memiliki: judul (string 100 char), pengarang (string 50 char),
dan tahun_terbit (int).

Sediakan:
1. buku.h — struct Buku dengan typedef, include guard, prototipe fungsi
   tambah_buku() dan tampilkan_semua()
2. buku.c — implementasi fungsi tersebut (gunakan array statis maks 20 buku)
3. main.c — contoh penggunaan: tambah 2 buku lalu tampilkan semua

Gunakan C standar (C99), komentar bahasa Indonesia.
```

### Apa yang Perlu Divalidasi

Setelah AI menghasilkan kode, periksa:

- [ ] Include guard ada dan namanya konsisten dengan nama file `.h`
- [ ] Prototipe di `.h` cocok persis dengan definisi di `.c` (nama, tipe parameter, tipe return)
- [ ] `main.c` meng-include header yang benar dengan tanda kutip, bukan `<>`
- [ ] Kode bisa dikompilasi tanpa error (`gcc buku.c main.c -o program`)
- [ ] Output sesuai yang diharapkan

> ⚠️ AI kadang lupa include guard, salah menulis nama parameter, atau menggunakan fitur yang belum dipelajari. Selalu baca kode yang dihasilkan baris per baris sebelum menyimpulkan bahwa kode tersebut benar.
