/*
 * Pertemuan 3 — Task A2: Array 1D — Pencarian Elemen
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Deskripsi:
 *   Array dengan 5 nilai sudah tersedia.
 *   Program meminta pengguna memasukkan sebuah nilai, lalu mencarinya di dalam array.
 *   Jika ditemukan, cetak indeksnya; jika tidak, cetak pesan "Tidak ditemukan."
 *
 * Expected Output (mencari 85):
 *   Array: {70, 85, 60, 92, 78}
 *   Cari nilai: 85
 *   Ditemukan di indeks 1.
 *
 * Expected Output (mencari 99):
 *   Array: {70, 85, 60, 92, 78}
 *   Cari nilai: 99
 *   Tidak ditemukan.
 *
 * Compile : gcc 03_Task_A2.c -o 03_Task_A2 -Wall
 * Jalankan: ./03_Task_A2  (Linux/Mac)  |  03_Task_A2.exe  (Windows)
 */

#include <stdio.h>

int main() {
    int nilai[5] = {70, 85, 60, 92, 78};
    int i;
    int cari;
    int ditemukan = 0;   /* flag: 0 = belum ditemukan, 1 = sudah */

    printf("Array: {70, 85, 60, 92, 78}\n");
    printf("Cari nilai: ");
    scanf("%d", &cari);

    

    return 0;
}


// Hints
/* TODO 1: Telusuri setiap elemen array nilai[] dari indeks 0 sampai 4.
 *   Jika nilai[i] sama dengan cari:
 *     - cetak "Ditemukan di indeks %d."
 *     - set ditemukan = 1
 *     - hentikan loop dengan break (tidak perlu lanjut mencari)
 */

/* TODO 2: Setelah loop, cek apakah nilai ditemukan atau tidak.
 *   Hint: gunakan variabel ditemukan sebagai kondisi if.
 */