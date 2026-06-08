/*
 * Pertemuan 1 — Task: Fill in the Blank
 * Topik   : Intro to C, Problem Solving & AI Engineering
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian yang bertanda \ /* ____ *\ / atau // TODO
 *   - Setelah semua bagian diisi, program harus bisa dikompilasi dan berjalan
 *   - Compile: gcc 01_Task.c -o 01_Task
 *   - Jalankan: ./01_Task  (Linux/Mac)  atau  01_Task.exe  (Windows)
 */
/* ============================================================
 * BAGIAN C — Terjemahkan Pseudocode ke Kode C
 *
 * Pseudocode:
 *   MULAI
 *     TAMPILKAN "Masukkan nilai kamu (0-100): "
 *     BACA nilai
 *
 *     JIKA nilai >= 60 MAKA
 *       TAMPILKAN "Selamat, kamu LULUS!"
 *     SELAIN ITU
 *       TAMPILKAN "Kamu BELUM LULUS. Semangat!"
 *     AKHIR JIKA
 *   SELESAI
 *
 * Output yang diharapkan (contoh input 75):
 *   Masukkan nilai kamu (0-100): 75
 *   Selamat, kamu LULUS!
 *
 * Output yang diharapkan (contoh input 45):
 *   Masukkan nilai kamu (0-100): 45
 *   Kamu BELUM LULUS. Semangat!
 * ============================================================ */

#include <stdio.h>

int main() {

    ____ nilai;   /* (C1) Deklarasi variabel yang sesuai untuk nilai 0-100 */

    printf(____); /* (C2) Cetak: "Masukkan nilai kamu (0-100): " */
    scanf(____);  /* (C3) Baca input ke variabel nilai */

    /* (C4) Lengkapi kondisi if-else sesuai pseudocode */
    if (____) {
        printf("Selamat, kamu LULUS!\n");
    } ____ {
        printf("Kamu BELUM LULUS. Semangat!\n");
    }

    return 0;
}