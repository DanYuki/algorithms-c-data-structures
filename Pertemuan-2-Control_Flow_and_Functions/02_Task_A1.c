/*
 * Pertemuan 2 — Task A1: if / else if / else
 * Topik   : Percabangan (kasus dunia nyata: potongan pajak gaji)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Baca komentar di dalam main() untuk tahu apa yang harus ditulis.
 *   - File ini sudah bisa di-compile dari awal — coba compile dulu sebelum mengisi.
 *
 * Compile : gcc 02_Task_A1.c -o 02_Task_A1 -Wall
 * Jalankan: ./02_Task_A1  (Linux/Mac)  atau  02_Task_A1.exe  (Windows)
 *
 * ----------------------------------------------------------------------
 * KONTEKS:
 *   Sebuah perusahaan memotong pajak dari gaji karyawan secara BERTINGKAT,
 *   tergantung besar gaji kotornya (gaji sebelum dipotong pajak):
 *
 *     Gaji kotor <= 4.000.000          -> tidak kena pajak  (0%)
 *     4.000.001 s.d. 10.000.000        -> pajak 5%
 *     di atas 10.000.000               -> pajak 15%
 *
 *   Gaji bersih = gaji kotor - potongan pajak.
 * ----------------------------------------------------------------------
 *
 * Expected Output (contoh input gaji = 3500000):
 *   Masukkan gaji kotor: 3500000
 *   Persen pajak  : 0%
 *   Potongan      : 0
 *   Gaji bersih   : 3500000
 *
 * Expected Output (contoh input gaji = 8000000):
 *   Masukkan gaji kotor: 8000000
 *   Persen pajak  : 5%
 *   Potongan      : 400000
 *   Gaji bersih   : 7600000
 *
 * Expected Output (contoh input gaji = 15000000):
 *   Masukkan gaji kotor: 15000000
 *   Persen pajak  : 15%
 *   Potongan      : 2250000
 *   Gaji bersih   : 12750000
 */

#include <stdio.h>

int main() {
    int gaji_kotor;
    int persen_pajak = 0;   /* akan kamu tentukan lewat percabangan di bawah */

    printf("=== Potongan Pajak Gaji ===\n");
    printf("Masukkan gaji kotor: ");
    scanf("%d", &gaji_kotor);

    /*
     * TUGAS 1: Tentukan persen_pajak menggunakan if / else if / else.
     *
     * Ketentuan:
     *   gaji_kotor <= 4000000          -> persen_pajak = 0
     *   gaji_kotor <= 10000000         -> persen_pajak = 5
     *   selain itu (lebih dari 10jt)   -> persen_pajak = 15
     *
     * Petunjuk:
     *   - Cek kondisi paling kecil (<= 4000000) dulu, baru naik ke yang lebih besar.
     *   - Untuk rentang tengah cukup tulis else if (gaji_kotor <= 10000000),
     *     karena nilai <= 4000000 sudah ditangani oleh if pertama.
     */


    /*
     * TUGAS 2: Hitung potongan dan gaji bersih.
     *
     *   potongan    = gaji_kotor * persen_pajak / 100
     *   gaji_bersih = gaji_kotor - potongan
     *
     * Petunjuk:
     *   - Tulis perkalian DULU baru pembagian (gaji_kotor * persen_pajak / 100),
     *     supaya hasil pembagian bilangan bulat tidak kehilangan ketelitian.
     *   - Deklarasikan variabel potongan dan gaji_bersih bertipe int.
     */


    /*
     * TUGAS 3: Cetak hasil dengan format berikut (ganti nilai 0 dengan variabelmu):
     *   printf("Persen pajak  : %d%%\n", persen_pajak);
     *   printf("Potongan      : %d\n", potongan);
     *   printf("Gaji bersih   : %d\n", gaji_bersih);
     *
     * Catatan: %% dipakai untuk mencetak satu tanda persen (%).
     */


    return 0;
}
