/*
 * Pertemuan 3 — Task B1: String — strlen & Hitung Manual
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Deskripsi:
 *   Hitung panjang string "Halo Dunia" dengan dua cara:
 *   (1) menggunakan fungsi strlen() dari <string.h>
 *   (2) menghitung manual karakter per karakter sampai null terminator '\0'
 *   Bandingkan hasilnya — keduanya harus sama.
 *
 * Expected Output:
 *   String           : "Halo Dunia"
 *   Panjang (strlen) : 10
 *   Panjang (manual) : 10
 *
 * Compile : gcc 03_Task_B1.c -o 03_Task_B1 -Wall
 * Jalankan: ./03_Task_B1  (Linux/Mac)  |  03_Task_B1.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>

int main() {
    char kata[] = "Halo Dunia";
    int panjang_manual = 0;
    int i;

    printf("=== Task B1: Panjang String ===\n");
    printf("String           : \"%s\"\n", kata);



    return 0;
}

/* TODO 1: Cetak panjang string kata menggunakan strlen().
 *   Hint: strlen(kata) mengembalikan jumlah karakter tanpa '\0'.
 *         Format output: "Panjang (strlen) : 10"
 */