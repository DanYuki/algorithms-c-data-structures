# Pertemuan 12 — Panduan Instruktur

**Topik:** Sorting Algorithms
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + `gcc` berjalan normal di komputer demo.
- [ ] Akun Claude AI aktif untuk demo komparasi performa (segmen 100–112).
- [ ] Siapkan 5–6 kartu bernomor (atau tulis di papan) untuk demo sorting fisik.

### Kode Demo yang Perlu Disiapkan

```c
/* demo_bubble.c — bubble sort minimal untuk demo live */
#include <stdio.h>
#define N 5
int arr[N] = {64, 34, 25, 12, 22};

void cetak() { for(int i=0;i<N;i++) printf("%d ",arr[i]); printf("\n"); }

int main() {
    cetak();
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int t = arr[j]; arr[j] = arr[j+1]; arr[j+1] = t;
            }
        }
        printf("Pass %d: ", i+1); cetak();
    }
    return 0;
}
```

---

## B. Catatan Pedagogis

### Sorting O(n²) (Menit 15–45)

**Mulai dengan demo fisik — bukan kode:**
Siapkan 5 kartu bernomor (mis. 5, 3, 8, 1, 4). Minta satu mahasiswa maju untuk menyortir sambil instruktur memandu dengan aturan masing-masing algoritma.

**Bubble Sort:** "Bandingkan dua kartu bersebelahan. Kalau salah urut, tukar." Minta mahasiswa melakukan satu full pass di depan kelas. Tunjukkan bagaimana angka terbesar "menggelembung" ke akhir setiap pass.

**Selection Sort:** "Cari kartu terkecil dari semua yang tersisa, letakkan di posisi pertama. Ulangi." Lebih intuitif karena satu kartu langsung ke posisi finalnya.

**Insertion Sort:** "Ambil satu kartu, sisipkan ke posisi yang tepat di tangan kiri yang sudah terurut." Ini cara paling natural — persis seperti menyusun kartu remi.

**Tabel swap di papan:**
| Algoritma | Swap worst case | Swap best case |
|---|---|---|
| Bubble | O(n²) | 0 (dengan flag) |
| Selection | O(n) | O(n) |
| Insertion | O(n²) | 0 |

Tekankan: Selection Sort punya keunggulan unik — jumlah swap minimal (paling banyak n-1). Berguna jika operasi swap mahal (mis. memindahkan objek besar di disk).

### Merge Sort & Quick Sort (Menit 45–80)

**Gambar pohon divide-and-conquer di papan sebelum kode:**

Merge Sort:
```
[38, 27, 43, 3]
   /           \
[38, 27]    [43, 3]
 /    \      /    \
[38] [27]  [43]  [3]
 \    /      \    /
[27, 38]    [3, 43]
        \  /
   [3, 27, 38, 43]
```

Gambarlah dengan warna berbeda untuk fase "divide" (turun) dan "combine/merge" (naik).

**Fungsi `merge` adalah inti — luangkan waktu ekstra:**
Tunjukkan secara step-by-step:
- L = [27, 38], R = [3, 43]
- k=0: L[0]=27, R[0]=3 → 3 < 27 → ambil R[0], k++, j++
- k=1: L[0]=27, R[1]=43 → 27 < 43 → ambil L[0], k++, i++
- k=2: L[1]=38, R[1]=43 → 38 < 43 → ambil L[1], k++, i++
- Sisa R: ambil 43

**Quick Sort — tekankan pivot:**
Miskonsepsi: "quick sort selalu lebih cepat dari merge sort" — tidak selalu. Untuk data yang sudah terurut + pivot di ujung → O(n²). Solusi: random pivot.

Demo live kasus terburuk:
```c
int urut[] = {1, 2, 3, 4, 5};
quick_sort(urut, 0, 4);
/* pivot selalu 5 (terbesar) → partisi tidak seimbang → O(n²) */
```

### Demo AI: Komparasi Performa (Menit 100–112)

**Prompt yang menghasilkan diskusi bagus:**
```
Untuk array berisi 10.000 elemen acak:
1. Estimasikan jumlah perbandingan Bubble Sort vs Merge Sort.
2. Jika satu perbandingan butuh 1 nanosecond, berapa lama masing-masing?
3. Kapan Quick Sort bisa lebih lambat dari Merge Sort?
```

Setelah AI menjawab, compile `optional2_benchmark.c` (jika sudah selesai) dan bandingkan dengan prediksi AI.

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Recap Big-O dari Pertemuan 11: O(n), O(log n), O(n²).
- "Hari ini: bagaimana kita mengurutkan data? Ada beberapa strategi, dan kompleksitasnya berbeda drastis."

### 15–45 | Sorting O(n²)
- Demo fisik dengan kartu (5 menit per algoritma).
- Implementasi `bubble_sort` secara live, tunjukkan output tiap pass.
- Selection dan Insertion — lebih cepat: tunjukkan kode, fokus pada perbedaan strategi.

### 45–80 | Merge Sort & Quick Sort
- Gambar pohon di papan dulu, baru kode.
- `merge` function: trace step-by-step dengan dua sub-array kecil.
- `partisi` quick sort: trace dengan arr=[10,7,8,9,1,5], pivot=5.

### 80–100 | Perbandingan & Panduan Memilih
- Tampilkan tabel perbandingan dari materi.
- Diskusi: "Kapan kamu memilih insertion sort?" → data kecil/hampir terurut.
- Demo quick sort worst case dengan array terurut.

### 100–112 | Demo AI
- Prompt komparasi performa.
- Jika ada waktu: jalankan benchmark sederhana live.

### 112–115 | Latihan Terbimbing
- Siswa kerjakan Task A Soal 1–2 minimal (bubble sort + hitung swap).

### 115–120 | Penutup & Tugas
- Rekap: tiga O(n²), dua O(n log n), trade-off masing-masing.
- Tugas: selesaikan Task A dan Task B.
- Preview: "Pertemuan 13: Tree (Pohon) — struktur data hierarkis. Binary Tree, BST (Binary Search Tree), traversal."

---

## D. Kunci Jawaban Task

### Task A (`12_Task_A.c`)

**SOAL 1 — `bubble_sort`:**
```c
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int sudah_terurut = 1;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp;
                sudah_terurut = 0;
            }
        }
        if (sudah_terurut) break;
    }
}
```

**SOAL 2 — `bubble_sort_hitung_swap`:**
```c
int bubble_sort_hitung_swap(int arr[], int n) {
    int swap = 0;
    for (int i = 0; i < n - 1; i++) {
        int sudah_terurut = 1;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp;
                swap++;
                sudah_terurut = 0;
            }
        }
        if (sudah_terurut) break;
    }
    return swap;
}
```

**SOAL 3 — `selection_sort`:**
```c
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[idx_min]) idx_min = j;
        if (idx_min != i) {
            int tmp = arr[i]; arr[i] = arr[idx_min]; arr[idx_min] = tmp;
        }
    }
}
```

**SOAL 4 — `insertion_sort`:**
```c
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int kunci = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > kunci) { arr[j+1] = arr[j]; j--; }
        arr[j+1] = kunci;
    }
}
```

**SOAL 5 — `selection_sort_desc`:**
```c
void selection_sort_desc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_maks = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[idx_maks]) idx_maks = j;
        if (idx_maks != i) {
            int tmp = arr[i]; arr[i] = arr[idx_maks]; arr[idx_maks] = tmp;
        }
    }
}
```

---

### Task B (`12_Task_B.c`)

**SOAL 1 — `merge`:**
```c
void merge(int arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1, n2 = kanan - tengah;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++) R[j] = arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}
```

**SOAL 2 — `merge_sort`:**
```c
void merge_sort(int arr[], int kiri, int kanan) {
    if (kiri >= kanan) return;
    int tengah = kiri + (kanan - kiri) / 2;
    merge_sort(arr, kiri, tengah);
    merge_sort(arr, tengah + 1, kanan);
    merge(arr, kiri, tengah, kanan);
}
```

**SOAL 3 — `partisi`:**
```c
int partisi(int arr[], int kiri, int kanan) {
    int pivot = arr[kanan], i = kiri - 1;
    for (int j = kiri; j < kanan; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i+1]; arr[i+1] = arr[kanan]; arr[kanan] = tmp;
    return i + 1;
}
```

**SOAL 4 — `quick_sort`:**
```c
void quick_sort(int arr[], int kiri, int kanan) {
    if (kiri >= kanan) return;
    int p = partisi(arr, kiri, kanan);
    quick_sort(arr, kiri, p - 1);
    quick_sort(arr, p + 1, kanan);
}
```

---

## E. Antisipasi Pertanyaan Umum

**"Kenapa merge sort butuh memori ekstra O(n)?"**
Saat menggabungkan (merge) dua sub-array, kita tidak bisa menggabungkan secara in-place tanpa overwrite data. Kita memerlukan array sementara L dan R untuk menyimpan salinan sebelum digabungkan kembali. Ada variasi in-place merge sort tapi jauh lebih kompleks dan jarang dipakai.

**"Quick sort worst case O(n²) — kenapa masih populer?"**
Karena dalam praktik, pivot acak/median-of-three membuat worst case sangat jarang terjadi. Juga, quick sort lebih cache-friendly (akses memori lokal) dibanding merge sort, sehingga konstanta-nya lebih kecil. `std::sort` di C++ menggunakan Introsort (quick sort + switch ke heap sort jika rekursi terlalu dalam).

**"Apa itu 'stable sort' dan kapan pentingnya?"**
Stable berarti elemen dengan nilai sama tetap dalam urutan relatif aslinya. Penting saat sorting berdasarkan beberapa kriteria secara bertahap — misalnya, sort berdasarkan nama dulu, lalu sort berdasarkan nilai: jika sort kedua stabil, mahasiswa dengan nilai sama tetap dalam urutan alphabetical dari sort pertama.

**"Kenapa bubble sort jarang dipakai?"**
Bubble sort tidak punya keunggulan signifikan dibanding insertion sort: keduanya O(n²) worst/average, tapi insertion sort lebih cache-friendly dan memiliki lebih sedikit swap dalam rata-rata kasus. Bubble sort hanya memiliki nilai edukatif karena ide "membandingkan elemen bersebelahan" mudah divisualisasikan.
