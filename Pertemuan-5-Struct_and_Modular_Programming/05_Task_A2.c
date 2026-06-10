/*
 * Pertemuan 5 — Task A2: Membuat Variabel & Mengakses Anggota
 * Topik   : Struct & Modular Programming
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar di samping ____ memberikan petunjuk
 *   - Compile: gcc 05_Task_A2.c -o 05_Task_A2
 *   - Jalankan: ./05_Task_A2  (Linux/Mac)  atau  05_Task_A2.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char  nama[50];
    char  nim[15];
    float ipk;
} Mahasiswa;


/* ============================================================
 * BAGIAN B — Membuat Variabel & Mengakses Anggota
 *
 * Lengkapi kode sehingga menghasilkan output:
 *   Nama : Andi Pratama
 *   NIM  : 2024001
 *   IPK  : 3.75
 * ============================================================ */

int main() {
    Mahasiswa mhs1;     /* (B1) variabel mhs1 sudah dideklarasikan */

    /* mengisi anggota — string harus pakai strcpy */
    strcpy(mhs1.____, "Andi Pratama");  // (B2) nama anggota untuk nama
    strcpy(mhs1.nim,  "2024001");
    mhs1.____ = 3.75;                   // (B3) nama anggota untuk IPK

    printf("=== Bagian B: Akses Anggota Struct ===\n");
    printf("Nama : %s\n",   mhs1.____);  // (B4) cetak nama
    printf("NIM  : %s\n",   mhs1.nim);
    printf("IPK  : %.2f\n", mhs1.____);  // (B5) cetak IPK

    return 0;
}
