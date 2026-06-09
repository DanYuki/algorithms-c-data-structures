/*
 * Pertemuan 2 -- Task B: Tulis Fungsimu Sendiri
 * Topik   : Functions & Rekursi Dasar
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - File ini berisi TIGA fungsi yang belum lengkap.
 *   - Baca komentar di atas setiap fungsi -- di sana tertulis apa yang harus
 *     fungsi tersebut lakukan, rumusnya, dan contoh nilainya.
 *   - Lengkapi BODY setiap fungsi, lalu panggil semua fungsi di dalam main().
 *
 * Compile : gcc 02_Task_B.c -o 02_Task_B -Wall
 * Jalankan: ./02_Task_B  (Linux/Mac)  atau  02_Task_B.exe  (Windows)
 *
 * Expected Output:
 *   === Persegi Panjang (panjang=5, lebar=3) ===
 *   Luas     : 15
 *   Keliling : 16
 *
 *   === Tabel Perkalian 4 ===
 *   4 x  1 =  4
 *   4 x  2 =  8
 *   4 x  3 = 12
 *   4 x  4 = 16
 *   4 x  5 = 20
 *   4 x  6 = 24
 *   4 x  7 = 28
 *   4 x  8 = 32
 *   4 x  9 = 36
 *   4 x 10 = 40
 */

#include <stdio.h>


/* ==============================================================
 * Fungsi 1: hitung_luas
 *
 * TUGAS: Kembalikan luas persegi panjang.
 *
 * Parameter : panjang (int), lebar (int)
 * Return    : luas (int)
 * Rumus     : panjang * lebar
 *
 * Contoh    : hitung_luas(5, 3) -> 15
 * ============================================================== */
int hitung_luas(int panjang, int lebar) {
    /* Tulis satu baris: return hasil perkalian panjang dan lebar */

}


/* ==============================================================
 * Fungsi 2: hitung_keliling
 *
 * TUGAS: Kembalikan keliling persegi panjang.
 *
 * Parameter : panjang (int), lebar (int)
 * Return    : keliling (int)
 * Rumus     : 2 * (panjang + lebar)
 *
 * Contoh    : hitung_keliling(5, 3) -> 16
 * ============================================================== */
int hitung_keliling(int panjang, int lebar) {
    /* Tulis satu baris: return hasil rumus keliling */

}


/* ==============================================================
 * Fungsi 3: cetak_tabel_perkalian
 *
 * TUGAS: Cetak tabel perkalian dari 1 sampai 10 untuk angka tertentu.
 *
 * Parameter : angka (int)
 * Return    : void (tidak mengembalikan nilai)
 *
 * Contoh output untuk angka = 4:
 *   4 x  1 =  4
 *   4 x  2 =  8
 *   ...
 *   4 x 10 = 40
 *
 * Petunjuk:
 *   - Gunakan for loop dengan variabel i dari 1 sampai 10
 *   - Di dalam loop, cetak: angka x i = angka*i
 *   - Gunakan format %2d agar angka satu digit rata kanan
 * ============================================================== */
void cetak_tabel_perkalian(int angka) {
    int i;
    /* Tulis for loop di sini */

}



/* ==============================================================
 * main -- Uji semua fungsi yang sudah kamu tulis
 *
 * TUGAS: Panggil setiap fungsi di bawah dan cetak hasilnya.
 *        Gunakan variabel panjang=5 dan lebar=3.
 *
 * Langkah:
 *   1. Cetak header "=== Persegi Panjang (panjang=5, lebar=3) ==="
 *      lalu panggil hitung_luas dan hitung_keliling, cetak hasilnya.
 *
 *   2. Cetak header "=== Tabel Perkalian 4 ==="
 *      lalu panggil cetak_tabel_perkalian dengan angka 4.
 *
 * ============================================================== */
int main() {
    int panjang = 5, lebar = 3;

    /* Bagian 1: Persegi Panjang */


    /* Bagian 2: Tabel Perkalian */


    return 0;
}
