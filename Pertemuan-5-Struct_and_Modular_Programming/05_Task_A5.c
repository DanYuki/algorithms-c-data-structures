/*
 * Pertemuan 5 — Task A5: Fungsi yang Menerima Struct (by value)
 * Topik   : Struct & Modular Programming
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar di samping ____ memberikan petunjuk
 *   - Compile: gcc 05_Task_A5.c -o 05_Task_A5
 *   - Jalankan: ./05_Task_A5  (Linux/Mac)  atau  05_Task_A5.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char  nama[50];
    char  nim[15];
    float ipk;
} Mahasiswa;


/* ============================================================
 * BAGIAN E — Fungsi yang Menerima Struct (by value)
 *
 * Lengkapi fungsi cetak_header dan cetak_baris sehingga
 * bisa mencetak data satu mahasiswa.
 *
 * cetak_header tidak punya parameter.
 * cetak_baris menerima satu Mahasiswa by value.
 * ============================================================ */

void cetak_header() {
    printf("=== Bagian E: Fungsi dengan Struct ===\n");
    printf("%-20s | %-10s | IPK\n", "Nama", "NIM");
    printf("--------------------------------------\n");
}

/* (E1) lengkapi parameter — terima satu Mahasiswa by value */
void cetak_baris(____ mhs) {
    printf("%-20s | %-10s | %.2f\n",
           mhs.____,    // (E2) akses nama
           mhs.nim,
           mhs.____);   // (E3) akses ipk
}

int main() {
    Mahasiswa mhs1 = {"Andi Pratama", "2024001", 3.75};
    Mahasiswa mhs2 = {"Budi Santoso", "2024002", 3.50};

    cetak_header();
    cetak_baris(____);  // (E4) kirim mhs1 ke fungsi
    cetak_baris(____);  // (E5) kirim mhs2 ke fungsi

    return 0;
}
