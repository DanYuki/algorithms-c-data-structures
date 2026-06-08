/*
 * Pertemuan 3 — Task B1: String — strlen & Hitung Manual
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah empat)
 *   - Mulai dari (0): isi nama header yang dibutuhkan
 *   - File ini belum bisa di-compile sebelum semua ____ diisi
 *
 * Compile : gcc 03_Task_B1.c -o 03_Task_B1 -Wall
 * Jalankan: ./03_Task_B1  (Linux/Mac)  atau  03_Task_B1.exe  (Windows)
 *
 * Expected Output:
 *   String           : "Halo Dunia"
 *   Panjang (strlen) : 10
 *   Panjang (manual) : 10
 */

#include <stdio.h>
#include <____.h>   /* (0) header untuk fungsi strlen */

int main() {
    char kata[] = "Halo Dunia";
    int panjang_manual = 0;
    int i;

    printf("=== Task B1: Panjang String ===\n");
    printf("String           : \"%s\"\n", kata);

    /* (A1) Gunakan strlen untuk menghitung panjang string */
    printf("Panjang (strlen) : %d\n", ____(____));  /* nama fungsi, lalu argumennya */

    /* (A2) Hitung panjang secara manual dengan for loop.
     *      Loop terus selama karakter ke-i bukan null terminator '\0'.
     *      Setiap iterasi, tambahkan panjang_manual sebesar 1. */
    for (i = 0; ____ != '\0'; i++) {   /* (A2a) karakter ke-i dari kata */
        panjang_manual++;
    }
    printf("Panjang (manual) : %d\n", panjang_manual);

    return 0;
}