/*
 * Pertemuan 2 — Task A3: Perulangan (for, while, do-while)
 * Topik   : Perulangan
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Ada tiga sub-tugas: C1, C2, C3. Kerjakan berurutan.
 *   - Baca komentar di tiap bagian untuk tahu apa yang harus ditulis.
 *   - File ini sudah bisa di-compile dari awal — coba compile dulu sebelum mengisi.
 *
 * Compile : gcc 02_Task_A3.c -o 02_Task_A3 -Wall
 * Jalankan: ./02_Task_A3  (Linux/Mac)  atau  02_Task_A3.exe  (Windows)
 *
 * Expected Output (contoh):
 *
 *   [C1] Masukkan N: 4
 *   Bilangan 1 sampai 4: 1  2  3  4
 *
 *   [C2] Masukkan angka positif: 1234
 *   Angka 1234 memiliki 4 digit.
 *
 *   [C3] Tebak angkanya (1-10)!
 *   Tebak angka (1-10): 3
 *   Salah, coba lagi!
 *   Tebak angka (1-10): 7
 *   Benar! Angkanya memang 7.
 */

#include <stdio.h>

int main() {
    printf("=== Bagian C: Perulangan ===\n");


    /* --------------------------------------------------------
     * C1 — for loop
     *
     * TUGAS: Minta pengguna input N, lalu cetak bilangan 1 sampai N.
     *
     * Contoh output (N=4): Bilangan 1 sampai 4: 1  2  3  4
     *
     * Petunjuk:
     *   - Buat variabel int batas untuk menyimpan input N
     *   - Gunakan for (i = 1; i <= batas; i++) { ... }
     *   - Di dalam loop, cetak i dengan format: printf("%d  ", i);
     *   - Setelah loop selesai, cetak newline: printf("\n");
     * -------------------------------------------------------- */
    printf("\n");

    int batas;
    printf("[C1] Masukkan N: ");
    scanf("%d", &batas);

    printf("Bilangan 1 sampai %d: ", batas);
    /* Tulis for loop di sini */


    printf("\n");


    /* --------------------------------------------------------
     * C2 — while loop
     *
     * TUGAS: Minta pengguna input angka positif, lalu hitung
     *        berapa banyak digit yang dimiliki angka itu.
     *
     * Contoh output: Angka 1234 memiliki 4 digit.
     *
     * Petunjuk:
     *   - Buat variabel int angka dan int jumlah_digit = 0
     *   - Simpan salinan angka asli sebelum diubah:
     *       int salinan = angka;
     *   - Gunakan while (angka > 0) { ... }
     *   - Di dalam loop: bagi angka dengan 10 (buang satu digit),
     *     lalu tambahkan jumlah_digit sebesar 1
     *   - Setelah loop, cetak hasilnya menggunakan salinan
     * -------------------------------------------------------- */
    printf("\n");

    int angka, jumlah_digit = 0;
    printf("[C2] Masukkan angka positif: ");
    scanf("%d", &angka);

    int salinan = angka;

    /* Tulis while loop di sini */


    printf("Angka %d memiliki %d digit.\n", salinan, jumlah_digit);


    /* --------------------------------------------------------
     * C3 — do-while loop
     *
     * TUGAS: Minta pengguna menebak angka 7. Terus minta tebakan
     *        sampai jawabannya benar.
     *
     * Contoh output:
     *   Tebak angka (1-10): 3
     *   Salah, coba lagi!
     *   Tebak angka (1-10): 7
     *   Benar! Angkanya memang 7.
     *
     * Petunjuk:
     *   - Buat variabel int tebakan dan int rahasia = 7
     *   - Gunakan do { ... } while (tebakan != rahasia);
     *   - Di dalam do: minta input, lalu cek apakah salah
     *   - Perbedaan do-while vs while: do-while PASTI jalan minimal sekali,
     *     baru cek kondisinya. Cocok untuk menu dan tebak-tebakan.
     * -------------------------------------------------------- */
    printf("\n");

    int tebakan;
    int rahasia = 7;
    printf("[C3] Tebak angkanya (1-10)!\n");

    /* Tulis do-while loop di sini */


    printf("Benar! Angkanya memang %d.\n", rahasia);


    return 0;
}
