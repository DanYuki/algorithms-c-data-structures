/*
 * Pertemuan 4 — Task A3: Fungsi Swap via Pointer
 * Topik   : Pointer & Dynamic Memory
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 04_Task_A3.c -o 04_Task_A3
 *   - Jalankan: ./04_Task_A3  (Linux/Mac)  atau  04_Task_A3.exe  (Windows)
 */

#include <stdio.h>

/* ============================================================
 * Lengkapi fungsi swap yang menukar nilai dua variabel
 * menggunakan pointer.
 *
 * Contoh output:
 *   Sebelum swap: a = 5, b = 10
 *   Sesudah swap: a = 10, b = 5
 * ============================================================ */

// (1) Lengkapi parameter fungsi swap
void swap(____ pa, ____ pb) {
    int temp;

    temp = ____;    // (2) simpan nilai di alamat pa ke temp
    ____ = ____;    // (3) salin nilai dari alamat pb ke alamat pa
    ____ = temp;    // (4) salin temp ke alamat pb
}

int main() {
    int a = 5, b = 10;

    printf("=== Task A3: Swap via Pointer ===\n");
    printf("Sebelum swap: a = %d, b = %d\n", a, b);

    swap(____, ____);  // (5) kirim alamat a dan b

    printf("Sesudah swap: a = %d, b = %d\n", a, b);

    return 0;
}