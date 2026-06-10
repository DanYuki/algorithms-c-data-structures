/*
 * Pertemuan 11 — Task A: Linear Search & Binary Search Iteratif
 * Topik   : Searching Algorithms & Big-O
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 11_Task_A.c -o 11_Task_A
 *   - Jalankan: ./11_Task_A  (Linux/Mac)  atau  11_Task_A.exe  (Windows)
 */

#include <stdio.h>


/* ============================================================
 * SOAL 1 — Linear Search
 *
 * Cari nilai target dalam array arr[] berukuran n.
 * Kembalikan indeks pertama di mana arr[i] == target.
 * Kembalikan -1 jika target tidak ada dalam array.
 *
 * Contoh:
 *   arr = {15, 3, 42, 8, 27}, n = 5, target = 8   → 3
 *   arr = {15, 3, 42, 8, 27}, n = 5, target = 99  → -1
 *   arr = {5, 5, 5},          n = 3, target = 5   → 0  (indeks pertama)
 *
 * Kompleksitas: O(n) — dalam kasus terburuk memeriksa semua elemen.
 *
 * Hint: loop dari i=0 sampai n-1, cek apakah arr[i] == target.
 * ============================================================ */

int linear_search(int arr[], int n, int target) {
    // TODO: implementasikan linear search
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 2 — Linear Search dengan Hitung Langkah
 *
 * Sama seperti Soal 1, tapi tambahkan parameter *langkah yang
 * mencatat berapa kali perbandingan (arr[i] == target) dilakukan.
 *
 * Contoh:
 *   arr = {15, 3, 42, 8, 27}, target = 8   → indeks 3, langkah = 4
 *   arr = {15, 3, 42, 8, 27}, target = 15  → indeks 0, langkah = 1
 *   arr = {15, 3, 42, 8, 27}, target = 99  → -1,       langkah = 5
 *
 * Hint:
 *   - Set *langkah = 0 di awal.
 *   - Setiap kali loop memeriksa elemen, tambah (*langkah)++.
 * ============================================================ */

int linear_search_langkah(int arr[], int n, int target, int *langkah) {
    // TODO: linear search + hitung jumlah perbandingan
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 3 — Binary Search Iteratif
 *
 * Cari nilai target dalam array TERURUT arr[] berukuran n.
 * Kembalikan indeks elemen yang sama dengan target.
 * Kembalikan -1 jika tidak ditemukan.
 *
 * Contoh (arr harus terurut!):
 *   arr = {3, 8, 11, 15, 27, 42}, n = 6, target = 27  → 4
 *   arr = {3, 8, 11, 15, 27, 42}, n = 6, target = 11  → 2
 *   arr = {3, 8, 11, 15, 27, 42}, n = 6, target = 99  → -1
 *
 * Kompleksitas: O(log n)
 *
 * Langkah:
 *   1. Set left = 0, right = n - 1.
 *   2. Selama left <= right:
 *      a. Hitung mid = left + (right - left) / 2
 *      b. Jika arr[mid] == target → return mid
 *      c. Jika arr[mid] < target  → left  = mid + 1  (cari di kanan)
 *      d. Jika arr[mid] > target  → right = mid - 1  (cari di kiri)
 *   3. Jika loop selesai tanpa menemukan → return -1
 * ============================================================ */

int binary_search(int arr[], int n, int target) {
    // TODO: implementasikan binary search iteratif
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 4 — Binary Search dengan Hitung Langkah
 *
 * Sama seperti Soal 3, tapi tambahkan parameter *langkah yang
 * mencatat berapa kali iterasi (perbandingan mid) dilakukan.
 *
 * Contoh:
 *   arr = {3, 8, 11, 15, 27, 42}, target = 27  → indeks 4, langkah = 2
 *   arr = {3, 8, 11, 15, 27, 42}, target = 3   → indeks 0, langkah = 3
 *   arr = {3, 8, 11, 15, 27, 42}, target = 99  → -1,       langkah = 3
 *
 * Hint: tambah (*langkah)++ di awal setiap iterasi while loop.
 * ============================================================ */

int binary_search_langkah(int arr[], int n, int target, int *langkah) {
    // TODO: binary search + hitung jumlah iterasi
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 5 — Bandingkan Efisiensi: Linear vs Binary Search
 *
 * Fungsi ini sudah LENGKAP — baca dan pahami, jangan ubah.
 * Fungsi memanggil Soal 2 dan Soal 4 untuk membandingkan
 * jumlah langkah kedua algoritma pada array yang sama.
 *
 * Setelah Soal 2 dan Soal 4 selesai, panggil bandingkan() di main()
 * dan pastikan outputnya masuk akal.
 * ============================================================ */

void bandingkan(int arr[], int n, int target) {
    int langkah_linear = 0, langkah_binary = 0;
    int idx_l = linear_search_langkah(arr, n, target, &langkah_linear);
    int idx_b = binary_search_langkah(arr, n, target, &langkah_binary);

    printf("Cari %3d | Linear: indeks %2d (%d langkah) | Binary: indeks %2d (%d langkah)\n",
           target, idx_l, langkah_linear, idx_b, langkah_binary);
}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

int main() {
    /* Array tidak terurut — untuk linear search */
    int acak[] = {15, 3, 42, 8, 27, 11, 36, 5};
    int n_acak  = 8;

    /* Array terurut — untuk binary search */
    int urut[]  = {3, 5, 8, 11, 15, 27, 36, 42};
    int n_urut  = 8;

    /* --- Soal 1: linear search dasar --- */
    printf("=== Soal 1: Linear Search ===\n");
    printf("Cari 8  di acak: indeks %d (harusnya 3)\n",  linear_search(acak, n_acak, 8));
    printf("Cari 15 di acak: indeks %d (harusnya 0)\n",  linear_search(acak, n_acak, 15));
    printf("Cari 99 di acak: indeks %d (harusnya -1)\n", linear_search(acak, n_acak, 99));

    /* --- Soal 2: linear search + langkah --- */
    printf("\n=== Soal 2: Linear Search + Hitung Langkah ===\n");
    int l = 0;
    linear_search_langkah(acak, n_acak, 8,  &l); printf("Cari  8 → %d langkah (harusnya 4)\n", l);
    linear_search_langkah(acak, n_acak, 15, &l); printf("Cari 15 → %d langkah (harusnya 1)\n", l);
    linear_search_langkah(acak, n_acak, 99, &l); printf("Cari 99 → %d langkah (harusnya 8)\n", l);

    /* --- Soal 3: binary search dasar --- */
    printf("\n=== Soal 3: Binary Search ===\n");
    printf("Cari 27 di urut: indeks %d (harusnya 5)\n",  binary_search(urut, n_urut, 27));
    printf("Cari  3 di urut: indeks %d (harusnya 0)\n",  binary_search(urut, n_urut, 3));
    printf("Cari 42 di urut: indeks %d (harusnya 7)\n",  binary_search(urut, n_urut, 42));
    printf("Cari 99 di urut: indeks %d (harusnya -1)\n", binary_search(urut, n_urut, 99));

    /* --- Soal 4: binary search + langkah --- */
    printf("\n=== Soal 4: Binary Search + Hitung Langkah ===\n");
    int b = 0;
    binary_search_langkah(urut, n_urut, 27, &b); printf("Cari 27 → %d langkah\n", b);
    binary_search_langkah(urut, n_urut,  3, &b); printf("Cari  3 → %d langkah\n", b);
    binary_search_langkah(urut, n_urut, 99, &b); printf("Cari 99 → %d langkah\n", b);

    /* --- Soal 5: perbandingan pada array besar --- */
    printf("\n=== Soal 5: Perbandingan Linear vs Binary (array 100 elemen) ===\n");
    int besar[100];
    for (int i = 0; i < 100; i++) besar[i] = i * 2;   /* 0, 2, 4, ..., 198 */

    bandingkan(besar, 100,   0);   /* di awal */
    bandingkan(besar, 100, 100);   /* di tengah */
    bandingkan(besar, 100, 198);   /* di akhir */
    bandingkan(besar, 100, 199);   /* tidak ada */

    return 0;
}
