/*
 * Pertemuan 5 — Task A4: Array of Struct
 * Topik   : Struct & Modular Programming
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar di samping ____ memberikan petunjuk
 *   - Compile: gcc 05_Task_A4.c -o 05_Task_A4
 *   - Jalankan: ./05_Task_A4  (Linux/Mac)  atau  05_Task_A4.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char  nama[50];
    char  nim[15];
    float ipk;
} Mahasiswa;


/* ============================================================
 * BAGIAN D — Array of Struct
 *
 * Program menyimpan data 3 mahasiswa dalam array of struct,
 * lalu menampilkan semuanya dalam tabel.
 *
 * Lengkapi kode sehingga output-nya seperti ini:
 *   === Bagian D: Array of Struct ===
 *   No | Nama                 | NIM        | IPK
 *   -------------------------------------------------
 *    1 | Citra Dewi           | 2024003    | 3.90
 *    2 | Dani Firmansyah      | 2024004    | 3.60
 *    3 | Eka Saputra          | 2024005    | 3.20
 * ============================================================ */

int main() {
    /* (D1) deklarasi array of struct berisi 3 Mahasiswa
       sekaligus inisialisasi dengan data di bawah */
    ____ kelas[3] = {
        {"Citra Dewi",      "2024003", 3.90},
        {"Dani Firmansyah", "2024004", 3.60},
        {"Eka Saputra",     "2024005", 3.20}
    };

    printf("=== Bagian D: Array of Struct ===\n");
    printf("No | %-20s | %-10s | IPK\n", "Nama", "NIM");
    printf("-------------------------------------------------\n");

    /* (D2) lengkapi loop — iterasi dari 0 sampai < 3 */
    for (int i = ____; i < ____; i++) {
        printf("%2d | %-20s | %-10s | %.2f\n",
               i + 1,
               kelas[____].nama,   // (D3) akses nama anggota ke-i
               kelas[i].nim,
               kelas[____].ipk);   // (D4) akses ipk anggota ke-i
    }

    return 0;
}
