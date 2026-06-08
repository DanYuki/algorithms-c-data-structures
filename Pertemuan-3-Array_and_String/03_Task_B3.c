/*
 * Pertemuan 3 — Task B3: String — strcat & Gabungkan String
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah empat)
 *   - Mulai dari (0): isi nama header yang dibutuhkan
 *   - File ini belum bisa di-compile sebelum semua ____ diisi
 *
 * Compile : gcc 03_Task_B3.c -o 03_Task_B3 -Wall
 * Jalankan: ./03_Task_B3  (Linux/Mac)  atau  03_Task_B3.exe  (Windows)
 *
 * Expected Output (contoh input: Rina):
 *   Masukkan nama kamu: Rina
 *   Pesan: Selamat datang, Rina!
 */

#include <stdio.h>
#include <____.h>   /* (0) header untuk fungsi strcat */

int main() {
    char nama[30];
    char pesan[60] = "Selamat datang, ";  /* buffer cukup besar untuk hasil gabungan */
    char penutup[] = "!";

    printf("=== Task B3: strcat ===\n");
    printf("Masukkan nama kamu: ");
    scanf("%s", nama);

    /* (C1) Gabungkan nama ke pesan menggunakan strcat.
     *      strcat(tujuan, sumber) menambahkan sumber ke ujung tujuan. */
    ____(pesan, ____);   /* (C1) nama fungsi | string yang ditambahkan */

    /* (C2) Gabungkan penutup ("!") ke pesan */
    ____(pesan, ____);   /* (C2) nama fungsi | string penutup */

    printf("Pesan: %s\n", pesan);

    return 0;
}