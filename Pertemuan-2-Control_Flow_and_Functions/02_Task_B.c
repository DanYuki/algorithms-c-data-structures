/*
 * Pertemuan 2 -- Task B: Tulis Fungsimu Sendiri
 * Topik   : Functions & Rekursi Dasar
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - File ini berisi LIMA fungsi yang belum lengkap.
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
 *
 *   === Pangkat ===
 *   2^0 = 1
 *   2^3 = 8
 *   3^4 = 81
 *
 *   === Jumlah 1 sampai N ===
 *   Jumlah 1 s.d. 5  = 15
 *   Jumlah 1 s.d. 10 = 55
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
 * Fungsi 4: hitung_pangkat  (REKURSIF)
 *
 * TUGAS: Hitung basis^eksponen secara rekursif.
 *
 * Parameter : basis (int), eksponen (int)
 * Return    : hasil pangkat (int)
 *
 * Definisi rekursif:
 *   hitung_pangkat(basis, 0) = 1                              <- base case
 *   hitung_pangkat(basis, n) = basis * hitung_pangkat(basis, n-1)
 *
 * Contoh:
 *   hitung_pangkat(2, 0) -> 1
 *   hitung_pangkat(2, 3) -> 8   (2 * 2 * 2)
 *   hitung_pangkat(3, 4) -> 81  (3 * 3 * 3 * 3)
 *
 * Petunjuk:
 *   - Tulis if untuk base case (eksponen == 0), return 1
 *   - Tulis return untuk kasus rekursif: basis * panggil_fungsi_ini(basis, eksponen-1)
 * ============================================================== */
int hitung_pangkat(int basis, int eksponen) {
    /* Tulis base case di sini */

    /* Tulis return rekursif di sini */

}


/* ==============================================================
 * Fungsi 5: jumlah_1_sampai_n  (REKURSIF)
 *
 * TUGAS: Hitung 1 + 2 + ... + n secara rekursif.
 *
 * Parameter : n (int)
 * Return    : total jumlah (int)
 *
 * Definisi rekursif:
 *   jumlah_1_sampai_n(0) = 0                                  <- base case
 *   jumlah_1_sampai_n(n) = n + jumlah_1_sampai_n(n-1)
 *
 * Contoh:
 *   jumlah_1_sampai_n(5)  -> 15  (1+2+3+4+5)
 *   jumlah_1_sampai_n(10) -> 55  (1+2+...+10)
 *
 * Petunjuk:
 *   - Tulis if untuk base case (n == 0), return 0
 *   - Tulis return untuk kasus rekursif: n + panggil_fungsi_ini(n-1)
 * ============================================================== */
int jumlah_1_sampai_n(int n) {
    /* Tulis base case di sini */

    /* Tulis return rekursif di sini */

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
 *   3. Cetak header "=== Pangkat ==="
 *      lalu panggil hitung_pangkat untuk: 2^0, 2^3, 3^4.
 *      Format: printf("2^3 = %d\n", hitung_pangkat(2, 3));
 *
 *   4. Cetak header "=== Jumlah 1 sampai N ==="
 *      lalu panggil jumlah_1_sampai_n untuk n=5 dan n=10.
 *      Format: printf("Jumlah 1 s.d. 5  = %d\n", jumlah_1_sampai_n(5));
 * ============================================================== */
int main() {
    int panjang = 5, lebar = 3;

    /* Bagian 1: Persegi Panjang */


    /* Bagian 2: Tabel Perkalian */


    /* Bagian 3: Pangkat */


    /* Bagian 4: Jumlah 1 sampai N */


    return 0;
}
