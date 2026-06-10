/*
 * Pertemuan 3 — Task A1: Array 1D — Input & Statistik
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Deskripsi:
 *   Program membaca 5 bilangan dari pengguna ke dalam sebuah array,
 *   lalu menampilkan total, rata-rata, nilai terbesar, dan nilai terkecil.
 *
 * Contoh input  : 70  85  60  92  78
 * Expected Output:
 *   Masukkan 5 nilai:
 *     nilai[0] = 70
 *     nilai[1] = 85
 *     nilai[2] = 60
 *     nilai[3] = 92
 *     nilai[4] = 78
 *
 *   Total    : 385
 *   Rata-rata: 77.0
 *   Terbesar : 92
 *   Terkecil : 60
 *
 * Compile : gcc 03_Task_A1.c -o 03_Task_A1 -Wall
 * Jalankan: ./03_Task_A1  (Linux/Mac)  |  03_Task_A1.exe  (Windows)
 */

#include <stdio.h>

int main() {
    int nilai[5];
    int i;
    int total    = 0;
    int terbesar;
    int terkecil;

    printf("Masukkan 5 nilai:\n");

    /* TODO 1: Baca 5 bilangan dari pengguna, simpan ke dalam array nilai[].
     *   Hint: gunakan for loop (i dari 0 sampai i < 5).
     *         Di tiap iterasi: printf prompt "  nilai[%d] = " lalu scanf ke &nilai[i].
     */
    /* Tulis kodemu di sini */

    /* TODO 2: Inisialisasi terbesar dan terkecil menggunakan elemen pertama array.
     *   Hint: pakai nilai[0] sebagai titik awal — bukan angka seperti 0 atau 999.
     */
    /* Tulis kodemu di sini */

    /* TODO 3: Dalam satu for loop, hitung total dan perbarui terbesar serta terkecil.
     *   Hint: untuk setiap nilai[i] —
     *         tambahkan ke total;
     *         jika nilai[i] lebih besar dari terbesar, perbarui terbesar;
     *         jika nilai[i] lebih kecil dari terkecil, perbarui terkecil.
     */
    /* Tulis kodemu di sini */

    printf("\nTotal    : %d\n", total);
    printf("Rata-rata: %.1f\n", (float)total / 5);
    printf("Terbesar : %d\n", terbesar);
    printf("Terkecil : %d\n", terkecil);

    return 0;
}
