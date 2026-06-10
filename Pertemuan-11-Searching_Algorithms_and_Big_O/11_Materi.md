# Pertemuan 11 — Searching Algorithms & Big-O

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Linear Search](#1-linear-search)
2. [Binary Search](#2-binary-search)
3. [Big-O Notation: Mengukur Efisiensi Algoritma](#3-big-o-notation-mengukur-efisiensi-algoritma)
4. [Membaca Big-O dari Struktur Kode](#4-membaca-big-o-dari-struktur-kode)
5. [Perbandingan: Linear Search vs Binary Search](#5-perbandingan-linear-search-vs-binary-search)
6. [AI untuk Analisis Big-O](#6-ai-untuk-analisis-big-o)

---

## 1. Linear Search

### Cara Kerja

Linear search memeriksa elemen satu per satu dari awal hingga akhir array sampai nilai yang dicari ditemukan (atau array habis).

```
Array: [15, 3, 42, 8, 27, 11]
Cari: 8

Langkah 1: cek 15 → bukan 8
Langkah 2: cek 3  → bukan 8
Langkah 3: cek 42 → bukan 8
Langkah 4: cek 8  → DITEMUKAN di indeks 3!
```

### Implementasi

```c
#include <stdio.h>

/*
 * Kembalikan indeks pertama di mana arr[i] == target.
 * Kembalikan -1 jika tidak ditemukan.
 */
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int data[] = {15, 3, 42, 8, 27, 11};
    int n = 6;

    int idx = linear_search(data, n, 8);
    if (idx != -1)
        printf("8 ditemukan di indeks %d\n", idx);   /* indeks 3 */
    else
        printf("8 tidak ditemukan.\n");

    idx = linear_search(data, n, 99);
    printf("99: indeks %d (tidak ditemukan)\n", idx); /* -1 */

    return 0;
}
```

### Analisis Kompleksitas

| Kasus | Kondisi | Jumlah perbandingan |
|---|---|---|
| Terbaik (best) | Target ada di indeks 0 | 1 |
| Rata-rata (avg) | Target ada di tengah | n/2 |
| Terburuk (worst) | Target di akhir atau tidak ada | n |

**Kompleksitas waktu: O(n)** — semakin besar array, semakin banyak langkah yang dibutuhkan secara proporsional.

**Keunggulan:** tidak memerlukan data terurut — bisa dipakai pada array apa saja.
**Kelemahan:** lambat untuk array besar.

---

## 2. Binary Search

### Prasyarat: Data Harus Terurut

Binary search hanya bekerja jika array sudah **terurut** (ascending atau descending). Jika array tidak terurut, binary search bisa melewati elemen yang dicari.

### Cara Kerja

Setiap langkah, periksa elemen **tengah** (mid). Jika:
- `arr[mid] == target` → ditemukan!
- `arr[mid] < target` → target ada di **kanan**, persempit ke `[mid+1, right]`
- `arr[mid] > target` → target ada di **kiri**, persempit ke `[left, mid-1]`

```
Array terurut: [3, 8, 11, 15, 27, 42]   (indeks 0–5)
Cari: 27

Langkah 1: left=0, right=5, mid=2 → arr[2]=11 < 27 → kanan
Langkah 2: left=3, right=5, mid=4 → arr[4]=27 == 27 → DITEMUKAN!

Hanya 2 langkah untuk 6 elemen!
```

### Implementasi Iteratif

```c
int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;   /* hindari overflow */

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left  = mid + 1;
        else                        right = mid - 1;
    }
    return -1;   /* tidak ditemukan */
}
```

> **Kenapa `mid = left + (right - left) / 2` bukan `(left + right) / 2`?**
> Jika `left` dan `right` keduanya sangat besar (mendekati INT_MAX), `left + right` bisa overflow. Rumus `left + (right - left) / 2` secara matematis ekuivalen tapi aman.

### Implementasi Rekursif

```c
int binary_search_rekursif(int arr[], int left, int right, int target) {
    if (left > right) return -1;   /* base case: rentang kosong */

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] < target)  return binary_search_rekursif(arr, mid + 1, right, target);
    else                    return binary_search_rekursif(arr, left, mid - 1, target);
}
/* Panggil: binary_search_rekursif(arr, 0, n-1, target) */
```

### Visualisasi: Berapa Langkah yang Dibutuhkan?

| Ukuran array (n) | Maksimum langkah (log₂ n) |
|---|---|
| 8 | 3 |
| 64 | 6 |
| 1.000 | ~10 |
| 1.000.000 | ~20 |
| 1.000.000.000 | ~30 |

Binary search mencari 1 miliar elemen hanya dalam **30 langkah** — inilah kekuatan O(log n).

**Kompleksitas waktu: O(log n)**

---

## 3. Big-O Notation: Mengukur Efisiensi Algoritma

### Apa Itu Big-O?

Big-O adalah cara matematis untuk menggambarkan **bagaimana waktu eksekusi tumbuh** seiring ukuran input (`n`) membesar. Kita hanya peduli pada **pertumbuhan dominan** — konstanta dan suku-suku kecil diabaikan.

```
T(n) = 5n² + 3n + 100  →  O(n²)
       ^^^        ^^^
       dominan    diabaikan
```

### Kelas Big-O yang Umum

| Notasi | Nama | Contoh |
|---|---|---|
| **O(1)** | Konstant | Akses elemen array dengan indeks |
| **O(log n)** | Logaritmik | Binary search |
| **O(n)** | Linear | Linear search |
| **O(n log n)** | Linearitmik | Merge sort, quicksort (avg) |
| **O(n²)** | Kuadratik | Bubble sort, selection sort |
| **O(2ⁿ)** | Eksponensial | Fibonacci rekursif murni |

### Perbandingan Visual (n = 1000)

```
O(1)      →          1 operasi
O(log n)  →         10 operasi
O(n)      →      1.000 operasi
O(n log n)→     10.000 operasi
O(n²)     →  1.000.000 operasi
O(2ⁿ)     →  lebih dari atom di alam semesta
```

### Aturan Penyederhanaan Big-O

1. **Buang konstanta:** `O(3n)` → `O(n)`, `O(500)` → `O(1)`
2. **Ambil suku terbesar:** `O(n² + n)` → `O(n²)`
3. **Loop dalam loop = kalikan:** dua loop bersarang masing-masing O(n) → `O(n²)`
4. **Loop berurutan = tambahkan lalu sederhanakan:** `O(n) + O(n)` → `O(2n)` → `O(n)`

---

## 4. Membaca Big-O dari Struktur Kode

### Satu Loop → O(n)

```c
/* O(n) — loop jalan n kali */
for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
}
```

### Loop Bagi Dua → O(log n)

```c
/* O(log n) — i dibagi 2 setiap iterasi */
int i = n;
while (i > 1) {
    printf("%d\n", i);
    i = i / 2;
}
/* untuk n=8: i = 8 → 4 → 2 → (1, stop) = 3 langkah = log₂(8) */
```

### Loop Bersarang → O(n²)

```c
/* O(n²) — loop luar n kali × loop dalam n kali */
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        printf("(%d,%d) ", i, j);
    }
}
```

### Loop Bersarang Asimetris → O(n × m)

```c
/* O(n × m) — baris n, kolom m */
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        /* ... */
    }
}
/* Jika n == m, ini menjadi O(n²) */
```

### Operasi Sederhana → O(1)

```c
/* O(1) — tidak ada loop, jumlah operasi tetap */
int pertama = arr[0];
int jumlah  = a + b;
int maks    = (a > b) ? a : b;
```

### Latihan Singkat: Tebak Big-O

```c
/* Potongan 1 */
for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
        hasil++;

/* Potongan 2 */
int x = arr[n/2];

/* Potongan 3 */
for (int i = 1; i < n; i *= 2)
    printf("%d ", i);
```

Jawaban: Potongan 1 = O(n²), Potongan 2 = O(1), Potongan 3 = O(log n).

---

## 5. Perbandingan: Linear Search vs Binary Search

### Kapan Masing-Masing Dipakai?

| Kondisi | Pilihan | Alasan |
|---|---|---|
| Data tidak terurut | Linear search | Binary search tidak bisa dipakai |
| Data terurut, cari sekali | Tergantung ukuran | Untuk n kecil (<20), perbedaan tidak terasa |
| Data terurut, n besar | Binary search | Jauh lebih cepat |
| Data terurut, cari berkali-kali | Binary search | Amortisasi biaya sorting |
| Data sering berubah | Linear search | Sorting ulang setiap perubahan = mahal |

### Contoh Perbandingan Langkah

```c
#include <stdio.h>

int main() {
    /* Array terurut 100 elemen */
    int arr[100];
    for (int i = 0; i < 100; i++) arr[i] = i * 2;  /* 0,2,4,...,198 */

    int target = 150;  /* indeks 75 */

    /* Linear search: bisa sampai 100 langkah */
    int langkah_linear = 0;
    for (int i = 0; i < 100; i++) {
        langkah_linear++;
        if (arr[i] == target) break;
    }

    /* Binary search: maksimal log₂(100) ≈ 7 langkah */
    int langkah_binary = 0;
    int left = 0, right = 99;
    while (left <= right) {
        langkah_binary++;
        int mid = left + (right - left) / 2;
        if      (arr[mid] == target) break;
        else if (arr[mid] <  target) left  = mid + 1;
        else                         right = mid - 1;
    }

    printf("Linear search : %d langkah\n", langkah_linear);  /* 76 */
    printf("Binary search : %d langkah\n", langkah_binary);  /* ~7 */

    return 0;
}
```

---

## 6. AI untuk Analisis Big-O

### Meminta AI Menganalisis Big-O Kode

```
Berikan analisis Big-O untuk fungsi berikut:

void proses(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] + arr[j] == 100)
                printf("(%d, %d)\n", i, j);
        }
    }
}

Jelaskan: (1) berapa kali setiap baris dieksekusi, (2) suku dominannya, (3) Big-O akhirnya.
```

### Meminta AI Membandingkan Dua Implementasi

```
Bandingkan Big-O dari dua fungsi ini:

/* Versi A */
int cari_duplikat_a(int arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] == arr[j]) return 1;
    return 0;
}

/* Versi B — asumsikan array sudah terurut */
int cari_duplikat_b(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        if (arr[i] == arr[i+1]) return 1;
    return 0;
}

Mana yang lebih efisien dan kenapa?
```

### Yang Perlu Divalidasi dari Output AI

- [ ] Apakah AI menghitung jumlah iterasi loop dengan benar?
- [ ] Apakah suku dominan yang dipilih AI sudah benar?
- [ ] Coba input konkret (mis. n=4) dan hitung manual — apakah cocok dengan analisis AI?
- [ ] Waspada: AI kadang salah menghitung Big-O untuk loop dengan kondisi berhenti yang tidak linear (mis. `i *= 2`).

> Big-O bukan tentang kecepatan absolut — melainkan tentang **bagaimana skala kecepatan** seiring input tumbuh. Sebuah algoritma O(n²) bisa lebih cepat dari O(n log n) untuk n yang sangat kecil. Selalu kontekstualisasikan dengan ukuran data nyata.
