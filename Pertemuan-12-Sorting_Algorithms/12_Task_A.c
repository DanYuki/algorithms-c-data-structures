/*
 * Pertemuan 12 — Task A: Sorting O(n²)
 * Topik   : Sorting Algorithms
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 12_Task_A.c -o 12_Task_A
 *   - Jalankan: ./12_Task_A  (Linux/Mac)  atau  12_Task_A.exe  (Windows)
 */

#include <stdio.h>


/* ============================================================
 * Fungsi Bantu — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

void cetak_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

/* Salin isi array src ke dst */
void salin_array(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

/* Cek apakah array sudah terurut ascending */
int sudah_terurut(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) return 0;
    return 1;
}


/* ============================================================
 * SOAL 1 — Bubble Sort
 *
 * Urutkan arr[] secara ascending (kecil ke besar) menggunakan bubble sort.
 *
 * Contoh:
 *   Input : [64, 34, 25, 12, 22]
 *   Output: [12, 22, 25, 34, 64]
 *
 * Algoritma:
 *   - Loop luar i dari 0 sampai n-2.
 *   - Loop dalam j dari 0 sampai n-2-i.
 *   - Jika arr[j] > arr[j+1]: tukar keduanya.
 *
 * Optimasi (opsional tapi disarankan):
 *   - Gunakan flag `sudah_terurut`. Jika satu pass tidak ada swap → berhenti.
 *
 * Hint swap:
 *   int tmp    = arr[j];
 *   arr[j]     = arr[j + 1];
 *   arr[j + 1] = tmp;
 * ============================================================ */

void bubble_sort(int arr[], int n) {
    // TODO: implementasikan bubble sort
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 2 — Bubble Sort dengan Hitung Swap
 *
 * Sama seperti Soal 1, tapi kembalikan jumlah pertukaran (swap)
 * yang terjadi selama proses sorting.
 *
 * Contoh:
 *   Input [64, 34, 25, 12, 22] → sorted, return 10  (10 swap)
 *   Input [1, 2, 3, 4, 5]      → sorted, return  0  (sudah terurut)
 *
 * Hint: buat variabel penghitung di awal, tambah setiap kali swap terjadi.
 * ============================================================ */

int bubble_sort_hitung_swap(int arr[], int n) {
    // TODO: bubble sort + kembalikan jumlah swap
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Selection Sort
 *
 * Urutkan arr[] secara ascending menggunakan selection sort.
 *
 * Contoh:
 *   Input : [64, 25, 12, 22, 11]
 *   Output: [11, 12, 22, 25, 64]
 *
 * Algoritma:
 *   - Loop luar i dari 0 sampai n-2.
 *   - Di dalam loop: cari indeks elemen terkecil di arr[i..n-1].
 *     Simpan indeksnya di idx_min, mulai dari i.
 *   - Setelah menemukan idx_min: tukar arr[i] dengan arr[idx_min].
 *
 * Catatan: selection sort selalu O(n²) — tidak ada optimasi early exit.
 * ============================================================ */

void selection_sort(int arr[], int n) {
    // TODO: implementasikan selection sort
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 4 — Insertion Sort
 *
 * Urutkan arr[] secara ascending menggunakan insertion sort.
 *
 * Contoh:
 *   Input : [5, 2, 4, 6, 1, 3]
 *   Output: [1, 2, 3, 4, 5, 6]
 *
 * Algoritma:
 *   - Loop luar i dari 1 sampai n-1.
 *   - Simpan arr[i] ke variabel kunci.
 *   - Loop dalam j = i-1, selama j >= 0 DAN arr[j] > kunci:
 *       geser arr[j] ke arr[j+1], lalu j--.
 *   - Setelah loop dalam: arr[j+1] = kunci.
 *
 * Keunggulan: jika data hampir terurut, loop dalam hampir tidak jalan → O(n).
 * ============================================================ */

void insertion_sort(int arr[], int n) {
    // TODO: implementasikan insertion sort
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 5 — Sorting Descending dengan Selection Sort
 *
 * Urutkan arr[] dari TERBESAR ke TERKECIL (descending)
 * menggunakan selection sort.
 *
 * Contoh:
 *   Input : [3, 1, 4, 1, 5, 9, 2, 6]
 *   Output: [9, 6, 5, 4, 3, 2, 1, 1]
 *
 * Hint: modifikasi Selection Sort dari Soal 3 —
 *   alih-alih mencari TERKECIL, cari TERBESAR di sisa array.
 * ============================================================ */

void selection_sort_desc(int arr[], int n) {
    // TODO: selection sort descending (terbesar ke terkecil)
    // Tulis kodemu di sini

}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

int main() {
    int asli[]  = {64, 34, 25, 12, 22};
    int n_asli  = 5;
    int kerja[10];

    /* --- Soal 1: Bubble Sort --- */
    printf("=== Soal 1: Bubble Sort ===\n");
    salin_array(asli, kerja, n_asli);
    printf("Sebelum: "); cetak_array(kerja, n_asli);
    bubble_sort(kerja, n_asli);
    printf("Sesudah: "); cetak_array(kerja, n_asli);
    printf("Terurut: %s\n\n", sudah_terurut(kerja, n_asli) ? "Ya ✓" : "TIDAK ✗");

    /* --- Soal 2: Bubble Sort + Hitung Swap --- */
    printf("=== Soal 2: Bubble Sort + Hitung Swap ===\n");
    int arr_swap1[] = {64, 34, 25, 12, 22};
    int arr_swap2[] = {1, 2, 3, 4, 5};
    int arr_swap3[] = {5, 4, 3, 2, 1};

    printf("Urutan terbalik [5,4,3,2,1] → %d swap\n",
           bubble_sort_hitung_swap(arr_swap3, 5));   /* 10 */
    printf("Sudah terurut   [1,2,3,4,5] → %d swap\n",
           bubble_sort_hitung_swap(arr_swap2, 5));   /* 0  */
    printf("Acak            [64,34,25,12,22] → %d swap\n\n",
           bubble_sort_hitung_swap(arr_swap1, 5));   /* 10 */

    /* --- Soal 3: Selection Sort --- */
    printf("=== Soal 3: Selection Sort ===\n");
    int arr3[] = {64, 25, 12, 22, 11};
    printf("Sebelum: "); cetak_array(arr3, 5);
    selection_sort(arr3, 5);
    printf("Sesudah: "); cetak_array(arr3, 5);
    printf("Terurut: %s\n\n", sudah_terurut(arr3, 5) ? "Ya ✓" : "TIDAK ✗");

    /* --- Soal 4: Insertion Sort --- */
    printf("=== Soal 4: Insertion Sort ===\n");
    int arr4[] = {5, 2, 4, 6, 1, 3};
    printf("Sebelum: "); cetak_array(arr4, 6);
    insertion_sort(arr4, 6);
    printf("Sesudah: "); cetak_array(arr4, 6);
    printf("Terurut: %s\n\n", sudah_terurut(arr4, 6) ? "Ya ✓" : "TIDAK ✗");

    /* --- Soal 5: Selection Sort Descending --- */
    printf("=== Soal 5: Selection Sort Descending ===\n");
    int arr5[] = {3, 1, 4, 1, 5, 9, 2, 6};
    printf("Sebelum: "); cetak_array(arr5, 8);
    selection_sort_desc(arr5, 8);
    printf("Sesudah: "); cetak_array(arr5, 8);   /* harusnya: [9,6,5,4,3,2,1,1] */

    /* Verifikasi descending */
    int terurut_desc = 1;
    for (int i = 0; i < 7; i++)
        if (arr5[i] < arr5[i+1]) { terurut_desc = 0; break; }
    printf("Terurut descending: %s\n", terurut_desc ? "Ya ✓" : "TIDAK ✗");

    return 0;
}
