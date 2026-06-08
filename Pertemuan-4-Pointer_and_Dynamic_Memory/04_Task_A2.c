/*
 * Pertemuan 4 — Task A2: Fungsi dengan Pointer (Pass-by-Reference)
 * Topik   : Pointer & Dynamic Memory
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 04_Task_A2.c -o 04_Task_A2
 *   - Jalankan: ./04_Task_A2  (Linux/Mac)  atau  04_Task_A2.exe  (Windows)
 */

#include <stdio.h>

/* ============================================================
 * Lengkapi fungsi tambah_satu yang menambah nilai variabel
 * sebesar 1 melalui pointer (pass-by-reference).
 *
 * Contoh output:
 *   Sebelum: 5
 *   Sesudah: 6
 * ============================================================ */

// (1) Lengkapi parameter fungsi — harus menerima pointer ke int
void tambah_satu(____ pn) {
    ____ = ____ + 1;  // (2) tambah 1 ke nilai yang ditunjuk pn
}

int main() {
    int nilai = 5;

    printf("=== Task A2: Pass-by-Reference ===\n");
    printf("Sebelum: %d\n", nilai);

    tambah_satu(____);  // (3) kirim alamat nilai, bukan nilai itu sendiri

    printf("Sesudah: %d\n", nilai);

    return 0;
}