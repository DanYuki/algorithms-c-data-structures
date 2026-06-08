/*
 * Pertemuan 4 — Task A1: Deklarasi & Dereference Pointer
 * Topik   : Pointer & Dynamic Memory
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 04_Task_A1.c -o 04_Task_A1
 *   - Jalankan: ./04_Task_A1  (Linux/Mac)  atau  04_Task_A1.exe  (Windows)
 */

#include <stdio.h>

/* ============================================================
 * Lengkapi kode sehingga menghasilkan output:
 *   Nilai x          : 10
 *   Alamat x         : (alamat memori, nilai beda di tiap komputer)
 *   Isi ptr (alamat) : (sama dengan alamat x)
 *   Nilai via *ptr   : 10
 *   Nilai x setelah *ptr = 99 : 99
 * ============================================================ */

int main() {
    int x = 10;
    int __ptr;        // (1) deklarasi ptr sebagai pointer ke int

    ptr = ____;       // (2) arahkan ptr ke alamat variabel x

    printf("=== Task A1: Deklarasi & Dereference ===\n");
    printf("Nilai x          : %d\n",  x);
    printf("Alamat x         : %p\n", ____);  // (3) cetak alamat x
    printf("Isi ptr (alamat) : %p\n", ____);  // (4) cetak nilai ptr (juga alamat x)
    printf("Nilai via *ptr   : %d\n", ____);  // (5) dereference ptr untuk baca nilai

    // (6) Ubah nilai x melalui pointer
    ____ = 99;  // (6) tulis 99 ke alamat yang ditunjuk ptr

    printf("Nilai x setelah *ptr = 99 : %d\n", x);

    return 0;
}