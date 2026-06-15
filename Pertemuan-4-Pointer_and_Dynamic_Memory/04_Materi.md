# Pertemuan 4 — Pointer & Dynamic Memory

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Konsep Pointer](#1-konsep-pointer)
2. [Dereference & Modifikasi Nilai](#2-dereference--modifikasi-nilai)
3. [Pointer & Fungsi: Pass-by-Reference](#3-pointer--fungsi-pass-by-reference)
4. [Pointer & Array](#4-pointer--array)
5. [Dynamic Memory: malloc & calloc](#5-dynamic-memory-malloc--calloc)
6. [Memory Leak & Dangling Pointer](#6-memory-leak--dangling-pointer)
7. [AI untuk Pointer & Deteksi Leak](#7-ai-untuk-pointer--deteksi-leak)

---

## 1. Konsep Pointer

Selama ini, variabel menyimpan **nilai**. Pointer menyimpan sesuatu yang berbeda: **alamat memori** tempat sebuah nilai disimpan.

Analogi: bayangkan memori komputer sebagai deretan kotak di gudang, masing-masing dengan nomor alamat. Variabel biasa adalah *isi kotak*. Pointer adalah *selembar kertas yang mencatat nomor alamat kotak tersebut*.

### Operator `&` dan `*`

| Operator | Nama | Kegunaan |
|----------|------|----------|
| `&variabel` | Address-of | Mendapatkan **alamat memori** dari variabel |
| `*pointer` | Dereference | Mengakses **nilai** yang disimpan di alamat yang ditunjuk pointer |

```c
#include <stdio.h>

int main() {
    int angka = 42;

    /* & memberi tahu kita: "di alamat berapa angka disimpan?" */
    printf("Nilai angka   : %d\n",  angka);   /* 42 */
    printf("Alamat angka  : %p\n", &angka);   /* mis. 0x7ffeabcd1234 */

    return 0;
}
```

> `%p` adalah format specifier untuk mencetak alamat memori (pointer). Nilainya berbeda di setiap komputer dan setiap kali program dijalankan.

### Deklarasi Pointer

```c
/* tipe_data *nama_pointer; */
int *ptr_angka;    /* pointer ke int — bisa menyimpan alamat variabel int */
float *ptr_nilai;  /* pointer ke float */
char *ptr_karakter;/* pointer ke char */
```

> ⚠️ **`*` saat deklarasi ≠ `*` saat dereference.** Saat `int *ptr` ditulis, `*` hanya menandai bahwa `ptr` adalah pointer. Saat `*ptr` digunakan di dalam kode, `*` berarti "akses nilai di alamat yang ditunjuk ptr". Ini sumber kebingungan paling umum di topik pointer.

### Menghubungkan Pointer ke Variabel

```c
#include <stdio.h>

int main() {
    int angka = 42;
    int *ptr;          /* deklarasi pointer ke int */

    ptr = &angka;      /* ptr sekarang menyimpan alamat variabel angka */

    printf("Nilai angka        : %d\n",  angka);  /* 42 */
    printf("Alamat angka       : %p\n", &angka);  /* mis. 0x7ffeabcd1234 */
    printf("Isi ptr (alamat)   : %p\n",  ptr);    /* sama dengan &angka */
    printf("Nilai via ptr (*ptr): %d\n", *ptr);   /* 42 — dereference */

    return 0;
}
```

Visualisasi memori:

```
Variabel angka:                 Variabel ptr:
┌─────────────┐                ┌──────────────────────┐
│     42      │  ← alamat:     │    0x7ffeabcd1234    │
│             │ 0x7ffeabcd1234 │  (alamat dari angka) │
└─────────────┘                └──────────────────────┘
      ↑                                   │
      └───────────────────────────────────┘
                    ptr menunjuk ke angka
```

---

## 2. Dereference & Modifikasi Nilai

Dengan pointer, kita bisa **membaca** dan **mengubah** nilai variabel lain melalui alamatnya.

```c
#include <stdio.h>

int main() {
    int suhu = 30;
    int *ptr = &suhu;

    printf("Suhu sebelum : %d\n", suhu);   /* 30 */

    /* Mengubah nilai suhu melalui pointer */
    *ptr = 35;

    printf("Suhu sesudah : %d\n", suhu);   /* 35 — berubah! */

    return 0;
}
```

`*ptr = 35` artinya: "pergi ke alamat yang disimpan di `ptr`, lalu tulis nilai 35 di sana." Karena `ptr` menunjuk ke `suhu`, maka `suhu` yang berubah.

---

## 3. Pointer & Fungsi: Pass-by-Reference

Di C, semua argumen fungsi dikirim **by value** — artinya fungsi mendapat salinan nilai, bukan nilai aslinya. Ini berarti fungsi tidak bisa mengubah variabel di `main` secara langsung.

### Masalah: Pass-by-Value

```c
#include <stdio.h>

void coba_ubah(int x) {
    x = 999;   /* hanya mengubah salinan lokal, tidak memengaruhi variabel di main */
}

int main() {
    int angka = 10;
    coba_ubah(angka);
    printf("%d\n", angka);  /* tetap 10 */
    return 0;
}
```

### Solusi: Pass-by-Reference dengan Pointer

```c
#include <stdio.h>

void ubah_via_pointer(int *px) {
    *px = 999;   /* dereference: ubah nilai di alamat yang ditunjuk px */
}

int main() {
    int angka = 10;
    ubah_via_pointer(&angka);   /* kirim alamat angka, bukan nilai angka */
    printf("%d\n", angka);      /* 999 — berhasil diubah! */
    return 0;
}
```

### Contoh Kasus: Fungsi Swap

**Problem:** Buat fungsi `swap` yang menukar nilai dua variabel.

```c
#include <stdio.h>

/* Fungsi swap menggunakan pointer */
void swap(int *pa, int *pb) {
    int temp;

    temp = *pa;   /* simpan nilai di alamat pa ke temp */
    *pa  = *pb;   /* tulis nilai dari alamat pb ke alamat pa */
    *pb  = temp;  /* tulis nilai temp ke alamat pb */
}

int main() {
    int x = 5, y = 10;

    printf("Sebelum swap: x = %d, y = %d\n", x, y);

    swap(&x, &y);   /* kirim alamat x dan y */

    printf("Sesudah swap: x = %d, y = %d\n", x, y);

    return 0;
}
```

Output:
```
Sebelum swap: x = 5, y = 10
Sesudah swap: x = 10, y = 5
```

---

## 4. Pointer & Array

Di C, nama array sebenarnya adalah **pointer ke elemen pertamanya**. Ini berarti array dan pointer erat kaitannya.

```c
#include <stdio.h>

int main() {
    int data[4] = {10, 20, 30, 40};
    int *ptr = data;   /* ptr menunjuk ke elemen pertama — tidak perlu & */

    /* Dua cara mengakses elemen yang setara */
    printf("data[0]   = %d\n", data[0]);  /* notasi array */
    printf("*ptr      = %d\n", *ptr);     /* notasi pointer */

    printf("data[2]   = %d\n", data[2]);  /* notasi array */
    printf("*(ptr+2)  = %d\n", *(ptr+2)); /* pointer arithmetic: maju 2 elemen */

    return 0;
}
```

**Pointer arithmetic:** `ptr + 1` tidak menambah 1 byte ke alamat, melainkan maju **1 elemen** (sesuai ukuran tipe data). Jika `ptr` adalah `int*` dan `int` berukuran 4 byte, maka `ptr + 1` maju 4 byte.

> Untuk pemula, cukup pahami bahwa `data[i]` dan `*(ptr+i)` adalah hal yang sama. Detail pointer arithmetic akan lebih berguna saat mempelajari linked list dan struktur data lainnya.

---

## 5. Dynamic Memory: malloc & calloc

Sejauh ini, ukuran array harus ditentukan saat **compile time** (saat menulis kode). Bagaimana jika kita baru tahu ukurannya saat program berjalan — misalnya tergantung input pengguna?

**Dynamic memory allocation** memungkinkan kita meminta memori dari sistem saat **runtime**, sebesar yang kita butuhkan.

Fungsi-fungsi ini ada di `<stdlib.h>`:

| Fungsi | Kegunaan |
|--------|----------|
| `malloc(n)` | Alokasi `n` byte; isi memori **tidak diinisialisasi** (berisi nilai acak) |
| `calloc(k, s)` | Alokasi `k` elemen masing-masing `s` byte; isi **diinisialisasi ke 0** |
| `free(ptr)` | Bebaskan memori yang sudah dialokasikan — **wajib dipanggil setelah selesai** |

### malloc — Alokasi Array Dinamis

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int i;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    /* Minta memori untuk n elemen int */
    /* sizeof(int) memberi tahu ukuran satu int dalam byte */
    arr = (int *) malloc(n * sizeof(int));

    /* WAJIB: cek apakah alokasi berhasil */
    if (arr == NULL) {
        printf("Alokasi memori gagal!\n");
        return 1;
    }

    /* Isi array */
    for (i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;   /* 10, 20, 30, ... */
    }

    /* Tampilkan */
    printf("Isi array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Bebaskan memori setelah selesai digunakan */
    free(arr);
    arr = NULL;   /* set ke NULL agar tidak jadi dangling pointer */

    return 0;
}
```

### calloc — Alokasi dengan Inisialisasi Nol

```c
/* calloc(jumlah_elemen, ukuran_per_elemen) */
int *arr = (int *) calloc(n, sizeof(int));

/* Semua elemen otomatis bernilai 0 setelah calloc */
```

**Kapan pilih `malloc` vs `calloc`?**
- Gunakan `calloc` jika kamu perlu semua elemen dimulai dari 0 (mis. array hitungan/frekuensi).
- Gunakan `malloc` jika kamu akan langsung mengisi semua elemen — tidak perlu inisialisasi nol dulu.

### Wajib: Selalu Cek NULL

`malloc` dan `calloc` mengembalikan `NULL` jika alokasi gagal (mis. memori sistem habis). Jika kamu langsung pakai pointer tanpa cek, program akan crash dengan cara yang tidak terduga.

```c
arr = malloc(n * sizeof(int));
if (arr == NULL) {
    /* tangani error — jangan lanjutkan menggunakan arr */
    return 1;
}
```

---

## 6. Memory Leak & Dangling Pointer

### Memory Leak

**Memory leak** terjadi ketika memori yang dialokasikan dengan `malloc`/`calloc` tidak pernah dibebaskan dengan `free`. Memori itu "hilang" — tidak bisa dipakai lagi oleh program, tapi juga tidak dikembalikan ke sistem.

```c
void contoh_leak() {
    int *ptr = (int *) malloc(10 * sizeof(int));
    /* ... pakai ptr ... */
    /* LUPA free(ptr) — ini memory leak! */
}
/* Setelah fungsi selesai, ptr tidak bisa diakses lagi,
   tapi memori yang dialokasikan masih "diklaim" */
```

Untuk program singkat, memory leak tidak terlihat dampaknya. Tapi untuk program yang berjalan lama (server, game), leak yang kecil pun akan terakumulasi dan akhirnya menghabiskan seluruh memori.

**Aturan sederhana:** setiap `malloc`/`calloc` harus berpasangan dengan tepat satu `free`.

### Dangling Pointer

**Dangling pointer** adalah pointer yang masih menyimpan alamat memori yang sudah dibebaskan. Mengakses dangling pointer adalah *undefined behavior* — bisa crash atau menghasilkan nilai tidak terduga.

```c
int *ptr = (int *) malloc(sizeof(int));
*ptr = 42;

free(ptr);      /* memori dibebaskan */
*ptr = 99;      /* BAHAYA: ptr adalah dangling pointer — memori sudah tidak valid! */
```

**Solusi:** setelah `free`, selalu set pointer ke `NULL`:

```c
free(ptr);
ptr = NULL;     /* sekarang aman — dereferencing NULL akan crash dengan pesan jelas */
```

Crash akibat dereference `NULL` jauh lebih mudah di-debug daripada *undefined behavior* dari dangling pointer.

### Rangkuman Safe Practice

```c
/* 1. Alokasi */
int *arr = (int *) malloc(n * sizeof(int));

/* 2. Cek NULL */
if (arr == NULL) { return 1; }

/* 3. Gunakan */
arr[0] = 10;

/* 4. Bebaskan */
free(arr);

/* 5. Set NULL */
arr = NULL;
```

---

## 7. AI untuk Pointer & Deteksi Leak

Pointer adalah salah satu topik paling sulit di C — bahkan programmer berpengalaman sering membuat bug pointer. AI bisa membantu melacak alur pointer dan mendeteksi potensi leak.

### Contoh Prompt: Lacak Alur Pointer

> *"Saya belajar pointer di C. Tolong lacak alur pointer di kode berikut baris per baris dan jelaskan nilai dari setiap variabel dan pointer di tiap langkahnya:*
> ```c
> int a = 5, b = 10;
> int *p = &a;
> *p = 20;
> p = &b;
> *p = *p + 5;
> ```
> *Apa nilai akhir dari `a` dan `b`?"*

### Contoh Prompt: Deteksi Memory Leak

> *"Tolong tinjau kode C berikut dan identifikasi apakah ada memory leak atau dangling pointer. Jelaskan di baris mana masalahnya dan bagaimana memperbaikinya:*
> ```c
> int *buat_array(int n) {
>     int *arr = malloc(n * sizeof(int));
>     return arr;
> }
> int main() {
>     int *data = buat_array(5);
>     data = buat_array(3);
>     free(data);
>     return 0;
> }
> ```"*

### Yang Perlu Kamu Verifikasi dari Output AI

1. **Apakah AI menemukan semua leak?** Pada contoh di atas, ada dua alokasi tapi hanya satu `free` — array berukuran 5 pernah dialokasikan tapi tidak pernah dibebaskan (pointer-nya di-overwrite).
2. **Apakah saran perbaikan AI benar-benar menyelesaikan masalah** atau hanya memindahkan masalah?
3. **Coba jalankan dengan Valgrind** (tool deteksi memory leak di Linux/Mac) untuk verifikasi independen dari AI.

---

## Ringkasan Pertemuan 4

| Konsep | Inti |
|--------|------|
| Pointer | Variabel yang menyimpan **alamat memori**; deklarasi `int *ptr` |
| `&` (address-of) | Mendapatkan alamat variabel: `ptr = &x` |
| `*` (dereference) | Mengakses nilai di alamat: `*ptr` baca/tulis nilai yang ditunjuk |
| Pass-by-reference | Kirim `&x` ke fungsi agar fungsi bisa mengubah `x` |
| Pointer & array | Nama array = pointer ke elemen pertama; `arr[i]` ≡ `*(arr+i)` |
| `malloc(n)` | Alokasi `n` byte; isi acak; perlu `free` |
| `calloc(k, s)` | Alokasi `k×s` byte; isi nol; perlu `free` |
| Cek `NULL` | Selalu cek hasil `malloc`/`calloc` sebelum digunakan |
| `free(ptr)` | Bebaskan memori; lalu set `ptr = NULL` |
| Memory leak | `malloc` tanpa pasangan `free` → memori terbuang |
| Dangling pointer | Pointer ke memori yang sudah di-`free` → set ke `NULL` setelah free |

**Preview Pertemuan 5:** Struct & Modular Programming — mengelompokkan data terkait menjadi satu tipe data buatan sendiri.
