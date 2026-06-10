/*
 * Pertemuan 3 — Task B2: String — strcpy & strcmp
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Deskripsi:
 *   Latihan dua operasi penting dari <string.h>:
 *   (1) strcpy  — salin isi satu string ke string lain
 *   (2) strcmp  — bandingkan dua string (hasilnya 0 jika sama)
 *
 * Expected Output:
 *   Sumber                  : "Belajar C"
 *   Tujuan (setelah strcpy) : "Belajar C"
 *
 *   Bandingkan "apel" dan "apel"   : SAMA
 *   Bandingkan "apel" dan "mangga" : BERBEDA
 *
 * Compile : gcc 03_Task_B2.c -o 03_Task_B2 -Wall
 * Jalankan: ./03_Task_B2  (Linux/Mac)  |  03_Task_B2.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>

int main() {
    char sumber[] = "Belajar C";
    char tujuan[20];      /* cukup besar untuk menampung isi sumber + '\0' */

    char kata1[] = "apel";
    char kata2[] = "apel";
    char kata3[] = "mangga";

    printf("=== Task B2: strcpy & strcmp ===\n");

    /* TODO 1: Salin isi sumber ke tujuan menggunakan strcpy, lalu cetak keduanya.
     *   Ingat: di C, assignment biasa (tujuan = sumber) tidak bisa digunakan untuk string.
     *   Format output:
     *     Sumber                  : "Belajar C"
     *     Tujuan (setelah strcpy) : "Belajar C"
     */
    /* Tulis kodemu di sini */

    /* TODO 2: Bandingkan pasangan string berikut menggunakan strcmp, lalu cetak hasilnya.
     *   (a) kata1 vs kata2  → harus tampil: Bandingkan "apel" dan "apel"   : SAMA
     *   (b) kata1 vs kata3  → harus tampil: Bandingkan "apel" dan "mangga" : BERBEDA
     *   Hint: strcmp(s1, s2) mengembalikan 0 jika kedua string identik.
     *         Jangan bandingkan string dengan ==; itu membandingkan alamat, bukan isi.
     */
    /* Tulis kodemu di sini */

    return 0;
}
