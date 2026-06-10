/*
 * Pertemuan 11 — Task B: Binary Search Rekursif & Analisis Big-O
 * Topik   : Searching Algorithms & Big-O
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Untuk soal analisis Big-O, tulis jawaban sebagai komentar
 *     (baris yang dimulai dengan //)
 *   - Jangan ubah signature fungsi
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 11_Task_B.c -o 11_Task_B
 *   - Jalankan: ./11_Task_B  (Linux/Mac)  atau  11_Task_B.exe  (Windows)
 */

#include <stdio.h>
#include <math.h>   /* untuk log2() di soal verifikasi */


/* ============================================================
 * SOAL 1 — Binary Search Rekursif
 *
 * Implementasikan binary search secara rekursif.
 * Parameter left dan right menentukan rentang pencarian.
 *
 * Contoh:
 *   arr = {1, 4, 7, 10, 15, 22, 30}, left=0, right=6, target=15 → 4
 *   arr = {1, 4, 7, 10, 15, 22, 30}, left=0, right=6, target=1  → 0
 *   arr = {1, 4, 7, 10, 15, 22, 30}, left=0, right=6, target=99 → -1
 *
 * Panggil dengan: binary_search_rekursif(arr, 0, n-1, target)
 *
 * Langkah:
 *   1. Base case: if (left > right) return -1  (rentang kosong)
 *   2. Hitung mid = left + (right - left) / 2
 *   3. Jika arr[mid] == target → return mid
 *   4. Jika arr[mid] < target  → rekursi ke kanan: (arr, mid+1, right, target)
 *   5. Jika arr[mid] > target  → rekursi ke kiri : (arr, left, mid-1, target)
 * ============================================================ */

int binary_search_rekursif(int arr[], int left, int right, int target) {
    // TODO: implementasikan binary search rekursif
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 2 — Binary Search Rekursif + Hitung Kedalaman Rekursi
 *
 * Sama seperti Soal 1, tapi tambahkan parameter *kedalaman yang
 * mencatat berapa kali fungsi memanggil dirinya sendiri
 * (termasuk pemanggilan pertama).
 *
 * Contoh:
 *   arr 7 elemen, target=15 (ada di tengah) → kedalaman = 1 atau 2
 *   arr 7 elemen, target=99 (tidak ada)     → kedalaman = 3
 *
 * Hint:
 *   - Tambah (*kedalaman)++ di awal fungsi (sebelum base case).
 *   - Pastikan pointer *kedalaman diinisialisasi ke 0 sebelum dipanggil.
 * ============================================================ */

int binary_search_rekursif_langkah(int arr[], int left, int right,
                                   int target, int *kedalaman) {
    // TODO: binary search rekursif + hitung kedalaman rekursi
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 3 — Verifikasi O(log n) Secara Empiris
 *
 * Fungsi ini sudah LENGKAP — baca, pahami, jangan ubah.
 * Setelah Soal 2 selesai, jalankan dan amati:
 *   - Apakah kedalaman rekursi sesuai dengan ⌈log₂(n)⌉?
 *   - Apakah pertumbuhan kedalaman sangat lambat dibanding n?
 *
 * Contoh output yang diharapkan:
 *   n =     8 | target tidak ada | kedalaman = 3 | ceil(log2(8))  = 3
 *   n =    16 | target tidak ada | kedalaman = 4 | ceil(log2(16)) = 4
 *   n =  1024 | target tidak ada | kedalaman = 10 | ceil(log2(1024)) = 10
 * ============================================================ */

void verifikasi_log_n() {
    printf("=== Soal 3: Verifikasi O(log n) ===\n");
    int ukuran[] = {8, 16, 32, 64, 128, 256, 512, 1024};
    int jml = 8;

    for (int i = 0; i < jml; i++) {
        int n = ukuran[i];
        int *arr = (int *) malloc_stub(n);   /* placeholder — lihat catatan di bawah */

        /* Isi arr dengan 0, 2, 4, ..., 2*(n-1) */
        /* Lalu cari nilai yang tidak ada (n*2+1) untuk worst case */
        /* Ini akan diisi saat Soal 2 sudah selesai */

        int kedalaman = 0;
        /* binary_search_rekursif_langkah(arr, 0, n-1, n*2+1, &kedalaman); */
        int log_teoritis = (int) ceil(log2(n));
        printf("n = %4d | kedalaman = %2d | ceil(log2(n)) = %d\n",
               n, kedalaman, log_teoritis);
        free(arr);
    }
}
/*
 * CATATAN: Soal 3 menggunakan malloc_stub() yang belum didefinisikan.
 * Ini sengaja dikomen agar file tetap bisa dikompilasi sejak awal.
 * Setelah mengimplementasikan Soal 2, uncomment baris yang perlu dan
 * ganti malloc_stub dengan alokasi yang benar:
 *   int *arr = (int *) malloc(n * sizeof(int));
 * Tambahkan #include <stdlib.h> di atas jika belum ada.
 */


/* ============================================================
 * SOAL 4 — Analisis Big-O (jawab sebagai komentar)
 *
 * Untuk setiap potongan kode berikut, tentukan:
 *   a. Big-O nya
 *   b. Alasan singkat (berapa kali loop berjalan?)
 *
 * Tulis jawabanmu sebagai komentar di bawah masing-masing potongan.
 * ============================================================ */

/* --- Potongan A --- */
void potongan_A(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) maks = arr[i];
    }
    printf("Maks: %d\n", maks);
}

/* Big-O Potongan A = ?  */
/* Alasan: */


/* --- Potongan B --- */
void potongan_B(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d,%d) ", i, j);
        }
    }
}

/* Big-O Potongan B = ?  */
/* Alasan: */


/* --- Potongan C --- */
void potongan_C(int n) {
    int i = 1;
    while (i < n) {
        printf("%d ", i);
        i = i * 2;
    }
}

/* Big-O Potongan C = ?  */
/* Alasan: */


/* --- Potongan D --- */
void potongan_D(int arr[], int n) {
    /* Langkah 1: cari maks — O(?) */
    int maks = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maks) maks = arr[i];

    /* Langkah 2: cetak semua pasangan — O(?) */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i] + arr[j]);
}

/* Big-O total Potongan D = ?     */
/* Alasan (sederhanakan dua suku): */


/* --- Potongan E --- */
int potongan_E(int n) {
    if (n <= 1) return n;
    return potongan_E(n - 1) + potongan_E(n - 1);
}

/* Big-O Potongan E = ?  */
/* Alasan (perhatikan: dua cabang rekursi, berkurang 1 tiap langkah): */


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah (Soal 1 & 2)
 * ============================================================ */

int main() {
    int arr[] = {1, 4, 7, 10, 15, 22, 30};
    int n = 7;

    /* --- Soal 1 --- */
    printf("=== Soal 1: Binary Search Rekursif ===\n");
    printf("Cari 15: indeks %d (harusnya 4)\n", binary_search_rekursif(arr, 0, n-1, 15));
    printf("Cari  1: indeks %d (harusnya 0)\n", binary_search_rekursif(arr, 0, n-1, 1));
    printf("Cari 30: indeks %d (harusnya 6)\n", binary_search_rekursif(arr, 0, n-1, 30));
    printf("Cari 99: indeks %d (harusnya -1)\n",binary_search_rekursif(arr, 0, n-1, 99));

    /* --- Soal 2 --- */
    printf("\n=== Soal 2: Binary Search Rekursif + Kedalaman ===\n");
    int k = 0;

    k = 0; binary_search_rekursif_langkah(arr, 0, n-1, 15, &k);
    printf("Cari 15: kedalaman = %d\n", k);

    k = 0; binary_search_rekursif_langkah(arr, 0, n-1,  1, &k);
    printf("Cari  1: kedalaman = %d\n", k);

    k = 0; binary_search_rekursif_langkah(arr, 0, n-1, 99, &k);
    printf("Cari 99: kedalaman = %d (worst case, harusnya ~3)\n", k);

    /* --- Soal 4: potongan kode dieksekusi agar tidak ada warning --- */
    printf("\n=== Soal 4: Potongan Kode (lihat komentar untuk jawaban Big-O) ===\n");
    int contoh[] = {5, 2, 8, 1};
    potongan_A(contoh, 4);
    potongan_B(3);
    potongan_C(16);
    potongan_D(contoh, 4);
    printf("potongan_E(4) = %d\n", potongan_E(4));  /* 8 = 2^(4-1) */

    return 0;
}
