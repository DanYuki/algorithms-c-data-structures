/*
 * Pertemuan 5 — Task A3: Inisialisasi Langsung
 * Topik   : Struct & Modular Programming
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar di samping ____ memberikan petunjuk
 *   - Compile: gcc 05_Task_A3.c -o 05_Task_A3
 *   - Jalankan: ./05_Task_A3  (Linux/Mac)  atau  05_Task_A3.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char  nama[50];
    char  nim[15];
    float ipk;
} Mahasiswa;


/* ============================================================
 * BAGIAN C — Inisialisasi Langsung & Akses Anggota
 *
 * Lengkapi inisialisasi struct sehingga menghasilkan output:
 *   Nama : Budi Santoso
 *   NIM  : 2024002
 *   IPK  : 3.50
 *
 * Gunakan cara inisialisasi langsung (bukan strcpy).
 * ============================================================ */

int main() {
    /* (C1) isi nilai di antara kurung kurawal sesuai urutan anggota:
       nama, nim, ipk */
    Mahasiswa mhs2 = {____, ____, ____};

    printf("=== Bagian C: Inisialisasi Langsung ===\n");
    printf("Nama : %s\n",   mhs2.nama);
    printf("NIM  : %s\n",   mhs2.nim);
    printf("IPK  : %.2f\n", mhs2.ipk);

    return 0;
}
