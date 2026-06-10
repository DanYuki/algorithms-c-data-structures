/*
 * Pertemuan 10 — Task A: Rekursi Dasar
 * Topik   : Recursion & Backtracking
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 10_Task_A.c -o 10_Task_A
 *   - Jalankan: ./10_Task_A  (Linux/Mac)  atau  10_Task_A.exe  (Windows)
 */

#include <stdio.h>


/* ============================================================
 * SOAL 1 — Penjumlahan Rekursif: sum(N) = 1 + 2 + ... + N
 *
 * Hitung jumlah semua bilangan bulat dari 1 sampai N secara rekursif.
 *
 * Contoh:
 *   sum(5) = 5 + 4 + 3 + 2 + 1 + 0 = 15
 *   sum(0) = 0
 *   sum(1) = 1
 *
 * Base case    : N == 0 → return 0
 * Recursive case: return N + sum(N - 1)
 * ============================================================ */

int sum(int n) {
    // TODO: implementasikan penjumlahan rekursif 1 sampai N
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 2 — Pangkat Rekursif: power(base, exp) = base^exp
 *
 * Hitung base pangkat exp secara rekursif.
 * Asumsikan exp >= 0 dan hasilnya tidak overflow int.
 *
 * Contoh:
 *   power(2, 0) = 1
 *   power(2, 3) = 8
 *   power(3, 4) = 81
 *   power(5, 1) = 5
 *
 * Base case    : exp == 0 → return 1  (x^0 = 1 untuk semua x)
 * Recursive case: return base * power(base, exp - 1)
 * ============================================================ */

long long power(long long base, int exp) {
    // TODO: implementasikan pangkat rekursif
    // Tulis kodemu di sini

    return 1;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Fibonacci Rekursif: fib(N)
 *
 * Kembalikan bilangan Fibonacci ke-N.
 * Deret Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 *
 * Contoh:
 *   fib(0) = 0
 *   fib(1) = 1
 *   fib(6) = 8
 *   fib(9) = 34
 *
 * Base case 1 : N == 0 → return 0
 * Base case 2 : N == 1 → return 1
 * Recursive case: return fib(N-1) + fib(N-2)
 *
 * Catatan: rekursi bercabang — dua pemanggilan rekursif per langkah.
 * ============================================================ */

int fib(int n) {
    // TODO: implementasikan Fibonacci rekursif
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 4 — Hitung Digit Rekursif: hitung_digit(N)
 *
 * Hitung berapa banyak digit bilangan bulat positif N.
 * Gunakan rekursi — jangan gunakan string, strlen, atau loop.
 *
 * Contoh:
 *   hitung_digit(5)    = 1
 *   hitung_digit(42)   = 2
 *   hitung_digit(100)  = 3
 *   hitung_digit(9999) = 4
 *
 * Hint:
 *   - Base case: N < 10 → return 1  (satu digit)
 *   - Recursive case: hapus digit terakhir dengan N / 10,
 *     lalu tambah 1.
 * ============================================================ */

int hitung_digit(int n) {
    // TODO: hitung jumlah digit secara rekursif
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 5 — Cari Nilai Maksimum Array secara Rekursif
 *
 * Temukan nilai terbesar dalam array arr[] yang berukuran n
 * menggunakan rekursi — jangan gunakan loop.
 *
 * Contoh:
 *   arr = {3, 7, 1, 9, 4}, n = 5  → 9
 *   arr = {5},              n = 1  → 5
 *   arr = {2, 2, 2},        n = 3  → 2
 *
 * Hint:
 *   - Base case: n == 1 → return arr[0]  (hanya satu elemen)
 *   - Recursive case:
 *       maks_sisa = maks_rekursif(arr, n - 1)
 *       if arr[n-1] > maks_sisa → return arr[n-1]
 *       else                    → return maks_sisa
 * ============================================================ */

int maks_rekursif(int arr[], int n) {
    // TODO: temukan nilai maksimum secara rekursif
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * Jalankan dan pastikan semua output sesuai komentar.
 * ============================================================ */

int main() {
    /* --- SOAL 1: sum --- */
    printf("=== Soal 1: Penjumlahan Rekursif ===\n");
    printf("sum(0)  = %d  (harusnya 0)\n",  sum(0));
    printf("sum(1)  = %d  (harusnya 1)\n",  sum(1));
    printf("sum(5)  = %d  (harusnya 15)\n", sum(5));
    printf("sum(10) = %d  (harusnya 55)\n", sum(10));

    /* --- SOAL 2: power --- */
    printf("\n=== Soal 2: Pangkat Rekursif ===\n");
    printf("power(2, 0) = %lld  (harusnya 1)\n",   power(2, 0));
    printf("power(2, 3) = %lld  (harusnya 8)\n",   power(2, 3));
    printf("power(3, 4) = %lld  (harusnya 81)\n",  power(3, 4));
    printf("power(5, 1) = %lld  (harusnya 5)\n",   power(5, 1));
    printf("power(2,10) = %lld  (harusnya 1024)\n",power(2,10));

    /* --- SOAL 3: fib --- */
    printf("\n=== Soal 3: Fibonacci Rekursif ===\n");
    printf("fib(0) = %d  (harusnya 0)\n",  fib(0));
    printf("fib(1) = %d  (harusnya 1)\n",  fib(1));
    printf("fib(6) = %d  (harusnya 8)\n",  fib(6));
    printf("fib(9) = %d  (harusnya 34)\n", fib(9));

    printf("\nDeret Fibonacci fib(0) s.d. fib(10):\n");
    for (int i = 0; i <= 10; i++) {
        printf("fib(%2d) = %d\n", i, fib(i));
    }

    /* --- SOAL 4: hitung_digit --- */
    printf("\n=== Soal 4: Hitung Digit ===\n");
    printf("hitung_digit(5)    = %d  (harusnya 1)\n", hitung_digit(5));
    printf("hitung_digit(42)   = %d  (harusnya 2)\n", hitung_digit(42));
    printf("hitung_digit(100)  = %d  (harusnya 3)\n", hitung_digit(100));
    printf("hitung_digit(9999) = %d  (harusnya 4)\n", hitung_digit(9999));

    /* --- SOAL 5: maks_rekursif --- */
    printf("\n=== Soal 5: Maksimum Array ===\n");
    int arr1[] = {3, 7, 1, 9, 4};
    int arr2[] = {5};
    int arr3[] = {2, 2, 2};
    int arr4[] = {1, 2, 3, 4, 5};

    printf("maks {3,7,1,9,4}  = %d  (harusnya 9)\n", maks_rekursif(arr1, 5));
    printf("maks {5}           = %d  (harusnya 5)\n", maks_rekursif(arr2, 1));
    printf("maks {2,2,2}       = %d  (harusnya 2)\n", maks_rekursif(arr3, 3));
    printf("maks {1,2,3,4,5}   = %d  (harusnya 5)\n", maks_rekursif(arr4, 5));

    return 0;
}
