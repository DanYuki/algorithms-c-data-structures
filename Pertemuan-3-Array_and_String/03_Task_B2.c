/*
 * Pertemuan 3 — Task B2: String — strcpy & strcmp
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah empat)
 *   - Mulai dari (0): isi nama header yang dibutuhkan
 *   - File ini belum bisa di-compile sebelum semua ____ diisi
 *
 * Compile : gcc 03_Task_B2.c -o 03_Task_B2 -Wall
 * Jalankan: ./03_Task_B2  (Linux/Mac)  atau  03_Task_B2.exe  (Windows)
 *
 * Expected Output:
 *   Sumber                  : "Belajar C"
 *   Tujuan (setelah strcpy) : "Belajar C"
 *
 *   Bandingkan "apel" dan "apel"   : SAMA
 *   Bandingkan "apel" dan "mangga" : BERBEDA
 */

#include <stdio.h>
#include <____.h>   /* (0) header untuk fungsi strcpy dan strcmp */

int main() {
    char sumber[] = "Belajar C";
    char tujuan[20];      /* pastikan cukup besar untuk menampung isi sumber */

    char kata1[] = "apel";
    char kata2[] = "apel";
    char kata3[] = "mangga";

    printf("=== Task B2: strcpy & strcmp ===\n");

    /* (B1) Salin sumber ke tujuan menggunakan strcpy */
    ____(tujuan, sumber);                 /* (B1) nama fungsi untuk menyalin string */

    printf("Sumber                  : \"%s\"\n", sumber);
    printf("Tujuan (setelah strcpy) : \"%s\"\n", tujuan);

    /* (B2a) Bandingkan kata1 dan kata2 menggunakan strcmp.
     *       strcmp mengembalikan 0 jika kedua string SAMA. */
    printf("\nBandingkan \"%s\" dan \"%s\"   : ", kata1, kata2);
    if (____(kata1, kata2) == ____) {     /* (B2a) nama fungsi | nilai kembalian jika sama */
        printf("SAMA\n");
    } else {
        printf("BERBEDA\n");
    }

    /* (B2b) Bandingkan kata1 dan kata3 */
    printf("Bandingkan \"%s\" dan \"%s\" : ", kata1, kata3);
    if (____(kata1, kata3) == 0) {        /* (B2b) nama fungsi perbandingan */
        printf("SAMA\n");
    } else {
        printf("BERBEDA\n");
    }

    return 0;
}