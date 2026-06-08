/*
 * Pertemuan 3 — Task A1: Array 1D — Input & Statistik
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah empat)
 *   - Komentar di samping setiap ____ memberikan petunjuk
 *   - File ini belum bisa di-compile sebelum semua ____ diisi
 *
 * Compile : gcc 03_Task_A1.c -o 03_Task_A1 -Wall
 * Jalankan: ./03_Task_A1  (Linux/Mac)  atau  03_Task_A1.exe  (Windows)
 *
 * Expected Output (contoh):
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
 */

#include <stdio.h>

int main() {
    int nilai[5];
    int i;
    int total    = 0;
    int terbesar;
    int terkecil;

    printf("=== Bagian A: Statistik Array 1D ===\n");
    printf("Masukkan 5 nilai:\n");

    /* (A1) Loop untuk membaca input ke setiap elemen array */
    for (i = 0; ____ ; ____) {            /* batas: i < 5 | naik: i++ */
        printf("  nilai[%d] = ", i);
        scanf("%d", ____);                 /* (A2) alamat elemen ke-i: &nilai[i] */
    }

    terbesar = ____;   /* (A3) inisialisasi dari elemen pertama: nilai[0] */
    terkecil = ____;   /* (A4) inisialisasi dari elemen pertama: nilai[0] */

    /* (A5) Loop untuk menghitung total, terbesar, dan terkecil */
    for (i = 0; i < 5; i++) {
        total = total + ____;              /* (A6) tambahkan elemen ke-i: nilai[i] */

        if (____ > terbesar) {             /* (A7) bandingkan elemen ke-i dengan terbesar */
            terbesar = nilai[i];
        }
        if (____ < terkecil) {             /* (A8) bandingkan elemen ke-i dengan terkecil */
            terkecil = nilai[i];
        }
    }

    printf("\nTotal    : %d\n", total);
    printf("Rata-rata: %.1f\n", (float)total / ____); /* (A9) bagi dengan jumlah elemen: 5 */
    printf("Terbesar : %d\n", terbesar);
    printf("Terkecil : %d\n", terkecil);

    return 0;
}