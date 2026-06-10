/*
 * Pertemuan 3 — Task B3: String — strcat & Bangun Pesan
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Deskripsi:
 *   Program meminta nama pengguna, lalu membangun kalimat sapaan
 *   dengan menggabungkan beberapa string menggunakan strcat.
 *   Hasil akhir: "Selamat datang, <nama>!"
 *
 * Contoh input: Rina
 * Expected Output:
 *   Masukkan nama kamu: Rina
 *   Pesan: Selamat datang, Rina!
 *
 * Compile : gcc 03_Task_B3.c -o 03_Task_B3 -Wall
 * Jalankan: ./03_Task_B3  (Linux/Mac)  |  03_Task_B3.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>

int main() {
    char nama[30];
    char pesan[60] = "Selamat datang, ";   /* buffer cukup besar untuk hasil gabungan */
    char penutup[] = "!";

    printf("Masukkan nama kamu: ");
    scanf("%s", nama);

    /* TODO 1: Gabungkan nama ke ujung pesan menggunakan strcat.
     *   Hint: strcat(tujuan, sumber) menambahkan sumber ke akhir tujuan.
     *         Pastikan buffer tujuan cukup besar untuk menampung hasil gabungan.
     */
    /* Tulis kodemu di sini */

    /* TODO 2: Gabungkan penutup ("!") ke ujung pesan.
     */
    /* Tulis kodemu di sini */

    printf("Pesan: %s\n", pesan);

    return 0;
}
