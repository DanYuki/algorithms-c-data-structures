/*
 * Pertemuan 12 — Task B: Merge Sort & Quick Sort
 * Topik   : Sorting Algorithms
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 12_Task_B.c -o 12_Task_B
 *   - Jalankan: ./12_Task_B  (Linux/Mac)  atau  12_Task_B.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>


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

void salin_array(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

int sudah_terurut(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) return 0;
    return 1;
}


/* ============================================================
 * SOAL 1 — Fungsi Merge (bagian dari Merge Sort)
 *
 * Gabungkan dua sub-array yang sudah terurut:
 *   arr[kiri..tengah]  dan  arr[tengah+1..kanan]
 * menjadi satu segmen terurut di arr[kiri..kanan].
 *
 * Contoh:
 *   arr = [27, 38,  3, 43]   kiri=0, tengah=1, kanan=3
 *   Sebelum: L=[27,38], R=[3,43]
 *   Sesudah: arr = [3, 27, 38, 43]
 *
 * Langkah:
 *   1. Hitung ukuran L = tengah - kiri + 1, ukuran R = kanan - tengah.
 *   2. Alokasikan array sementara L[] dan R[] (gunakan malloc).
 *   3. Salin arr[kiri..tengah] ke L[], arr[tengah+1..kanan] ke R[].
 *   4. Gabungkan dengan loop:
 *        selama i < ukuranL DAN j < ukuranR:
 *          jika L[i] <= R[j] → arr[k++] = L[i++]
 *          jika tidak         → arr[k++] = R[j++]
 *   5. Salin sisa L[] atau R[] yang belum habis.
 *   6. free(L) dan free(R).
 *
 * Perhatian: k dimulai dari kiri (bukan 0), karena kita menulis
 *            kembali ke segmen arr[kiri..kanan].
 * ============================================================ */

void merge(int arr[], int kiri, int tengah, int kanan) {
    // TODO: implementasikan fungsi merge
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 2 — Merge Sort (rekursif, menggunakan fungsi merge di atas)
 *
 * Urutkan arr[kiri..kanan] secara ascending menggunakan merge sort.
 *
 * Contoh:
 *   arr = [38, 27, 43, 3, 9, 82, 10]
 *   Setelah merge_sort(arr, 0, 6): [3, 9, 10, 27, 38, 43, 82]
 *
 * Panggil dengan: merge_sort(arr, 0, n-1)
 *
 * Langkah:
 *   1. Base case: if (kiri >= kanan) return   (sub-array panjang ≤1)
 *   2. Hitung tengah = kiri + (kanan - kiri) / 2
 *   3. Rekursi kiri:  merge_sort(arr, kiri, tengah)
 *   4. Rekursi kanan: merge_sort(arr, tengah+1, kanan)
 *   5. Gabungkan:     merge(arr, kiri, tengah, kanan)
 * ============================================================ */

void merge_sort(int arr[], int kiri, int kanan) {
    // TODO: implementasikan merge sort rekursif
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 3 — Fungsi Partisi (bagian dari Quick Sort)
 *
 * Susun ulang arr[kiri..kanan] sehingga:
 *   - Semua elemen < pivot ada di kiri pivot.
 *   - Semua elemen > pivot ada di kanan pivot.
 * Pivot adalah arr[kanan] (elemen terakhir).
 * Kembalikan indeks akhir pivot setelah partisi.
 *
 * Contoh:
 *   arr = [10, 7, 8, 9, 1, 5], kiri=0, kanan=5, pivot=5
 *   Sesudah: [1, 5, 8, 9, 10, 7]  → pivot 5 di indeks 1
 *   Return: 1
 *
 * Langkah (Lomuto partition):
 *   1. pivot = arr[kanan]
 *   2. i = kiri - 1  (indeks elemen terakhir yang ≤ pivot)
 *   3. Loop j dari kiri sampai kanan-1:
 *        jika arr[j] <= pivot:
 *          i++
 *          tukar arr[i] dengan arr[j]
 *   4. Tukar arr[i+1] dengan arr[kanan]  (letakkan pivot di posisi akhirnya)
 *   5. return i + 1
 * ============================================================ */

int partisi(int arr[], int kiri, int kanan) {
    // TODO: implementasikan fungsi partisi (Lomuto)
    // Tulis kodemu di sini

    return kiri;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 4 — Quick Sort (rekursif, menggunakan partisi di atas)
 *
 * Urutkan arr[kiri..kanan] secara ascending menggunakan quick sort.
 *
 * Contoh:
 *   arr = [10, 7, 8, 9, 1, 5]
 *   Setelah quick_sort(arr, 0, 5): [1, 5, 7, 8, 9, 10]
 *
 * Panggil dengan: quick_sort(arr, 0, n-1)
 *
 * Langkah:
 *   1. Base case: if (kiri >= kanan) return
 *   2. p = partisi(arr, kiri, kanan)
 *   3. Rekursi kiri:  quick_sort(arr, kiri, p - 1)
 *   4. Rekursi kanan: quick_sort(arr, p + 1, kanan)
 * ============================================================ */

void quick_sort(int arr[], int kiri, int kanan) {
    // TODO: implementasikan quick sort rekursif
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 5 — Verifikasi & Perbandingan
 *
 * Fungsi ini SUDAH LENGKAP — jalankan setelah Soal 1–4 selesai
 * untuk melihat kedua algoritma menghasilkan output yang sama.
 * ============================================================ */

void bandingkan_sorting() {
    int asli[] = {38, 27, 43, 3, 9, 82, 10, 55, 17, 60};
    int n = 10;
    int a[10], b[10];

    salin_array(asli, a, n);
    salin_array(asli, b, n);

    printf("Input awal: "); cetak_array(asli, n);

    merge_sort(a, 0, n - 1);
    printf("Merge Sort: "); cetak_array(a, n);
    printf("Terurut   : %s\n", sudah_terurut(a, n) ? "Ya ✓" : "TIDAK ✗");

    quick_sort(b, 0, n - 1);
    printf("Quick Sort: "); cetak_array(b, n);
    printf("Terurut   : %s\n", sudah_terurut(b, n) ? "Ya ✓" : "TIDAK ✗");

    /* Cek apakah hasilnya sama */
    int sama = 1;
    for (int i = 0; i < n; i++) if (a[i] != b[i]) { sama = 0; break; }
    printf("Hasil sama: %s\n", sama ? "Ya ✓" : "TIDAK ✗");
}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

int main() {
    /* --- Soal 1: uji fungsi merge secara langsung --- */
    printf("=== Soal 1: Fungsi Merge ===\n");
    int arr_merge[] = {27, 38, 3, 43};   /* L=[27,38] sudah urut, R=[3,43] sudah urut */
    printf("Sebelum merge: "); cetak_array(arr_merge, 4);
    merge(arr_merge, 0, 1, 3);           /* merge [27,38] dan [3,43] */
    printf("Sesudah merge: "); cetak_array(arr_merge, 4);   /* [3, 27, 38, 43] */
    printf("Terurut: %s\n\n", sudah_terurut(arr_merge, 4) ? "Ya ✓" : "TIDAK ✗");

    /* --- Soal 2: merge sort lengkap --- */
    printf("=== Soal 2: Merge Sort ===\n");
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    printf("Sebelum: "); cetak_array(arr2, 7);
    merge_sort(arr2, 0, 6);
    printf("Sesudah: "); cetak_array(arr2, 7);   /* [3, 9, 10, 27, 38, 43, 82] */
    printf("Terurut: %s\n\n", sudah_terurut(arr2, 7) ? "Ya ✓" : "TIDAK ✗");

    /* --- Soal 3: uji fungsi partisi secara langsung --- */
    printf("=== Soal 3: Fungsi Partisi ===\n");
    int arr3[] = {10, 7, 8, 9, 1, 5};   /* pivot = arr[5] = 5 */
    printf("Sebelum: "); cetak_array(arr3, 6);
    int p = partisi(arr3, 0, 5);
    printf("Sesudah: "); cetak_array(arr3, 6);
    printf("Indeks pivot: %d (nilai pivot: %d)\n\n", p, arr3[p]);
    /* Verifikasi: semua arr[0..p-1] <= arr[p] dan arr[p+1..5] >= arr[p] */

    /* --- Soal 4: quick sort lengkap --- */
    printf("=== Soal 4: Quick Sort ===\n");
    int arr4[] = {10, 7, 8, 9, 1, 5};
    printf("Sebelum: "); cetak_array(arr4, 6);
    quick_sort(arr4, 0, 5);
    printf("Sesudah: "); cetak_array(arr4, 6);   /* [1, 5, 7, 8, 9, 10] */
    printf("Terurut: %s\n\n", sudah_terurut(arr4, 6) ? "Ya ✓" : "TIDAK ✗");

    /* --- Soal 5: perbandingan merge vs quick --- */
    printf("=== Soal 5: Perbandingan Merge Sort vs Quick Sort ===\n");
    bandingkan_sorting();

    return 0;
}
