# Pertemuan 12 — Sorting Algorithms

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Sorting O(n²): Bubble, Selection, Insertion](#1-sorting-on²-bubble-selection-insertion)
2. [Merge Sort: Divide and Conquer O(n log n)](#2-merge-sort-divide-and-conquer-on-log-n)
3. [Quick Sort: Pivot & Partisi O(n log n)](#3-quick-sort-pivot--partisi-on-log-n)
4. [Tabel Perbandingan Algoritma Sorting](#4-tabel-perbandingan-algoritma-sorting)
5. [Panduan Memilih Algoritma](#5-panduan-memilih-algoritma)
6. [AI untuk Komparasi Performa](#6-ai-untuk-komparasi-performa)

---

## 1. Sorting O(n²): Bubble, Selection, Insertion

### Bubble Sort

Ide: bandingkan dua elemen bersebelahan — jika salah urut, tukar. Ulangi sampai tidak ada pertukaran lagi.

```
Pass 1: [64, 34, 25, 12, 22]
  64>34 → tukar: [34, 64, 25, 12, 22]
  64>25 → tukar: [34, 25, 64, 12, 22]
  64>12 → tukar: [34, 25, 12, 64, 22]
  64>22 → tukar: [34, 25, 12, 22, 64]  ← 64 "gelembung" ke posisi akhir

Pass 2: [34, 25, 12, 22, 64]
  34>25 → tukar, 34>12 → tukar, 34>22 → tukar → [25, 12, 22, 34, 64]

...dan seterusnya
```

```c
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        /* Setelah pass ke-i, elemen terbesar ke-(i+1) sudah di posisinya */
        int sudah_terurut = 1;   /* optimasi: berhenti jika tidak ada swap */
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                /* tukar */
                int tmp  = arr[j];
                arr[j]   = arr[j + 1];
                arr[j+1] = tmp;
                sudah_terurut = 0;
            }
        }
        if (sudah_terurut) break;   /* array sudah terurut → berhenti lebih awal */
    }
}
```

**Kompleksitas:** O(n²) worst/average, O(n) best (sudah terurut dengan optimasi).

---

### Selection Sort

Ide: di setiap pass, **pilih** elemen terkecil dari sisa array dan pindahkan ke posisi yang benar.

```
[64, 25, 12, 22, 11]
Pass 1: cari min di [0..4] → 11 di indeks 4 → tukar dengan arr[0]
        [11, 25, 12, 22, 64]
Pass 2: cari min di [1..4] → 12 di indeks 2 → tukar dengan arr[1]
        [11, 12, 25, 22, 64]
Pass 3: cari min di [2..4] → 22 di indeks 3 → tukar dengan arr[2]
        [11, 12, 22, 25, 64]
Pass 4: cari min di [3..4] → 25 (sudah di tempat) — tidak perlu tukar
        [11, 12, 22, 25, 64]  ← selesai
```

```c
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        /* Cari indeks elemen terkecil di arr[i..n-1] */
        int idx_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[idx_min]) idx_min = j;
        }
        /* Tukar arr[i] dengan arr[idx_min] */
        if (idx_min != i) {
            int tmp       = arr[i];
            arr[i]        = arr[idx_min];
            arr[idx_min]  = tmp;
        }
    }
}
```

**Kompleksitas:** O(n²) di semua kasus — selalu mencari minimum di sisa array.
**Keunggulan:** jumlah swap minimal (paling banyak n-1 swap).

---

### Insertion Sort

Ide: seperti menyusun kartu remi — ambil satu kartu, sisipkan ke posisi yang tepat di bagian yang sudah terurut.

```
[5, 2, 4, 6, 1, 3]
i=1: ambil 2, sisipkan sebelum 5 → [2, 5, 4, 6, 1, 3]
i=2: ambil 4, sisipkan antara 2 dan 5 → [2, 4, 5, 6, 1, 3]
i=3: ambil 6, sudah di tempat → [2, 4, 5, 6, 1, 3]
i=4: ambil 1, sisipkan di depan → [1, 2, 4, 5, 6, 3]
i=5: ambil 3, sisipkan antara 2 dan 4 → [1, 2, 3, 4, 5, 6]
```

```c
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int kunci  = arr[i];
        int j      = i - 1;
        /* Geser elemen yang lebih besar dari kunci ke kanan */
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;   /* sisipkan kunci di posisi yang tepat */
    }
}
```

**Kompleksitas:** O(n²) worst, **O(n) best** (data hampir terurut).
**Keunggulan:** sangat efisien untuk data kecil atau hampir terurut. Digunakan secara internal oleh banyak implementasi stdlib sort.

---

## 2. Merge Sort: Divide and Conquer O(n log n)

### Ide

1. **Divide:** bagi array menjadi dua bagian sama besar.
2. **Conquer:** urutkan masing-masing bagian secara rekursif.
3. **Combine:** gabungkan dua bagian yang sudah terurut (merge).

```
         [38, 27, 43, 3, 9, 82, 10]
           /                      \
   [38, 27, 43, 3]           [9, 82, 10]
     /         \               /      \
 [38, 27]   [43, 3]       [9, 82]    [10]
   /    \    /    \        /    \
 [38]  [27] [43]  [3]    [9]  [82]
   \    /    \    /        \    /
  [27, 38]  [3, 43]       [9, 82]
       \        /               \
    [3, 27, 38, 43]          [9, 10, 82]
              \                  /
          [3, 9, 10, 27, 38, 43, 82]
```

### Implementasi

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Gabungkan arr[kiri..tengah] dan arr[tengah+1..kanan] */
void merge(int arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    /* Salin ke array sementara */
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++) R[j] = arr[tengah + 1 + j];

    /* Gabungkan L dan R kembali ke arr[kiri..kanan] */
    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else              arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int arr[], int kiri, int kanan) {
    if (kiri >= kanan) return;   /* base case: sub-array panjang 0 atau 1 */

    int tengah = kiri + (kanan - kiri) / 2;
    merge_sort(arr, kiri, tengah);       /* urutkan kiri */
    merge_sort(arr, tengah + 1, kanan);  /* urutkan kanan */
    merge(arr, kiri, tengah, kanan);     /* gabungkan */
}

/* Panggil dengan: merge_sort(arr, 0, n-1) */
```

**Kompleksitas:** O(n log n) di semua kasus (best, average, worst).
**Kelemahan:** membutuhkan memori tambahan O(n) untuk array sementara L dan R.
**Keunggulan:** stabil (urutan elemen sama tetap terjaga), performa konsisten.

---

## 3. Quick Sort: Pivot & Partisi O(n log n)

### Ide

1. Pilih satu elemen sebagai **pivot**.
2. **Partisi:** susun ulang array sehingga semua elemen < pivot ada di kiri, semua > pivot ada di kanan.
3. Rekursi pada bagian kiri dan kanan pivot.

```
Pivot = elemen terakhir

[10, 7, 8, 9, 1, 5]  pivot = 5
Partisi:
  i = -1  (indeks elemen kecil terakhir yang dimasukkan)
  j=0: arr[0]=10 ≥ 5 → lewati
  j=1: arr[1]=7  ≥ 5 → lewati
  j=2: arr[2]=8  ≥ 5 → lewati
  j=3: arr[3]=9  ≥ 5 → lewati
  j=4: arr[4]=1  < 5 → i=0, tukar arr[0]↔arr[4]: [1, 7, 8, 9, 10, 5]
  Selesai: tukar arr[i+1]=arr[1] dengan pivot arr[5]: [1, 5, 8, 9, 10, 7]
  Pivot 5 di indeks 1 — sudah di posisi akhirnya!

Rekursi kiri: [1]     → sudah terurut
Rekursi kanan:[8,9,10,7] → urutkan lagi
```

### Implementasi

```c
/* Partisi: pilih arr[kanan] sebagai pivot, susun ulang, kembalikan indeks pivot akhir */
int partisi(int arr[], int kiri, int kanan) {
    int pivot = arr[kanan];
    int i = kiri - 1;   /* indeks elemen terakhir yang ≤ pivot */

    for (int j = kiri; j < kanan; j++) {
        if (arr[j] <= pivot) {
            i++;
            /* tukar arr[i] dan arr[j] */
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    /* letakkan pivot di posisi akhirnya */
    int tmp = arr[i+1]; arr[i+1] = arr[kanan]; arr[kanan] = tmp;
    return i + 1;   /* indeks pivot */
}

void quick_sort(int arr[], int kiri, int kanan) {
    if (kiri >= kanan) return;   /* base case */

    int p = partisi(arr, kiri, kanan);
    quick_sort(arr, kiri, p - 1);    /* rekursi kiri */
    quick_sort(arr, p + 1, kanan);   /* rekursi kanan */
}

/* Panggil dengan: quick_sort(arr, 0, n-1) */
```

**Kompleksitas:**
- Average: O(n log n)
- Worst: O(n²) — terjadi jika pivot selalu terkecil/terbesar (array sudah terurut + pivot di ujung).
- **Solusi:** pilih pivot secara acak atau gunakan "median of three".

**Keunggulan:** in-place (tidak butuh memori tambahan signifikan), konstanta kecil — dalam praktik sering lebih cepat dari merge sort.

---

## 4. Tabel Perbandingan Algoritma Sorting

| Algoritma | Best | Average | Worst | Memori | Stabil? | In-place? |
|---|---|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Ya | Ya |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | Tidak | Ya |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Ya | Ya |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Ya | Tidak |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | Tidak | Ya |

**Stabil:** elemen dengan nilai sama tetap berada di urutan relatif aslinya setelah sorting.
**In-place:** sorting dilakukan di dalam array yang sama tanpa alokasi memori signifikan.

---

## 5. Panduan Memilih Algoritma

| Kondisi | Algoritma yang Disarankan | Alasan |
|---|---|---|
| n kecil (< 20) | Insertion Sort | Overhead rendah, mudah diimplementasikan |
| Data hampir terurut | Insertion Sort | O(n) pada kasus terbaik |
| Memori terbatas | Quick Sort atau Heap Sort | In-place |
| Butuh stabilitas | Merge Sort atau Insertion Sort | Elemen sama tetap urut relatif |
| Dataset besar, performa kritis | Merge Sort atau Quick Sort | O(n log n) |
| Data acak, rata-rata cepat | Quick Sort (dengan random pivot) | Konstanta kecil dalam praktik |
| Jaminan worst-case O(n log n) | Merge Sort atau Heap Sort | Quick Sort bisa O(n²) di worst case |

> Dalam praktik, `qsort()` dari stdlib C dan `std::sort()` di C++ menggunakan **Introsort** — kombinasi quick sort, heap sort, dan insertion sort — untuk memanfaatkan keunggulan masing-masing.

---

## 6. AI untuk Komparasi Performa

### Meminta AI Memprediksi Performa

```
Bandingkan Bubble Sort dan Merge Sort untuk mengurutkan array berisi 10.000 elemen acak.
Estimasikan:
  1. Berapa banyak perbandingan yang dilakukan masing-masing?
  2. Berapa rasio perbandingannya?
  3. Apakah ada kasus di mana Bubble Sort lebih baik?
```

### Meminta AI Menjelaskan Kasus Terburuk Quick Sort

```
Kapan Quick Sort mengalami O(n²)?
Berikan contoh array konkret (panjang 5) yang memicu worst case
jika kita selalu memilih elemen terakhir sebagai pivot.
Bagaimana cara menghindarinya?
```

### Yang Perlu Divalidasi dari Output AI

- [ ] Apakah estimasi jumlah operasi AI masuk akal secara matematis?
- [ ] Compile dan ukur waktu eksekusi dengan `clock()` dari `<time.h>` untuk n besar (mis. 10.000).
- [ ] Apakah Bubble Sort pada data hampir terurut benar-benar lebih cepat dari Quick Sort?

```c
#include <time.h>

clock_t mulai = clock();
bubble_sort(arr, n);
clock_t selesai = clock();
double waktu = (double)(selesai - mulai) / CLOCKS_PER_SEC;
printf("Waktu: %.4f detik\n", waktu);
```

> Performa aktual di mesin nyata dipengaruhi banyak faktor: cache, branch prediction, ukuran data. Benchmark empiris selalu lebih akurat dari prediksi teoritis saja.
