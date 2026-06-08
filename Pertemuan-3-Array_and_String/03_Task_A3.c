/*
 * Pertemuan 3 — Task A3: Array 2D — Input & Tampilkan Matriks
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah empat)
 *   - Komentar di samping setiap ____ memberikan petunjuk
 *   - File ini belum bisa di-compile sebelum semua ____ diisi
 *
 * Compile : gcc 03_Task_A3.c -o 03_Task_A3 -Wall
 * Jalankan: ./03_Task_A3  (Linux/Mac)  atau  03_Task_A3.exe  (Windows)
 *
 * Expected Output (contoh input 1-6 berurutan):
 *   Isi matriks 2x3 (baris demi baris):
 *     [0][0] = 1
 *     [0][1] = 2
 *     [0][2] = 3
 *     [1][0] = 4
 *     [1][1] = 5
 *     [1][2] = 6
 *
 *   Isi matriks:
 *    1  2  3
 *    4  5  6
 *
 *   Jumlah semua elemen: 21
 */

#include <stdio.h>

int main() {
    int matriks[2][3];
    int baris, kolom;
    int jumlah = 0;

    printf("=== Bagian C: Matriks 2x3 ===\n");
    printf("Isi matriks 2x3 (baris demi baris):\n");

    /* (C1) Nested loop untuk membaca input ke matriks */
    for (baris = 0; baris < ____; baris++) {        /* (C1a) jumlah baris matriks */
        for (kolom = 0; kolom < ____; kolom++) {    /* (C1b) jumlah kolom matriks */
            printf("  [%d][%d] = ", baris, kolom);
            scanf("%d", &matriks[____][____]);       /* (C2) akses elemen [baris][kolom] */
        }
    }

    printf("\nIsi matriks:\n");

    /* (C3) Nested loop untuk menampilkan matriks dan menghitung jumlah */
    for (baris = 0; baris < 2; baris++) {
        for (kolom = 0; kolom < 3; kolom++) {
            printf("%3d", ____);         /* (C4) cetak elemen [baris][kolom] */
            jumlah = jumlah + ____;      /* (C5) tambahkan elemen ke jumlah total */
        }
        printf("\n");
    }

    printf("\nJumlah semua elemen: %d\n", jumlah);

    return 0;
}