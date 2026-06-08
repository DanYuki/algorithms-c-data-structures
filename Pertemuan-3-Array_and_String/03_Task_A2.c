/*
 * Pertemuan 3 — Task A2: Array 1D — Pencarian Elemen
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah empat)
 *   - Komentar di samping setiap ____ memberikan petunjuk
 *   - File ini belum bisa di-compile sebelum semua ____ diisi
 *
 * Compile : gcc 03_Task_A2.c -o 03_Task_A2 -Wall
 * Jalankan: ./03_Task_A2  (Linux/Mac)  atau  03_Task_A2.exe  (Windows)
 *
 * Expected Output (mencari 85):
 *   Cari nilai: 85
 *   Ditemukan di indeks 1.
 *
 * Expected Output (mencari 99):
 *   Cari nilai: 99
 *   Tidak ditemukan.
 */

#include <stdio.h>

int main() {
    int nilai[5] = {70, 85, 60, 92, 78};  /* data tetap untuk latihan */
    int i;
    int cari;
    int ditemukan = 0;   /* flag: 0 = belum ditemukan */

    printf("=== Bagian B: Pencarian di Array ===\n");
    printf("Cari nilai: ");
    scanf("%d", &cari);

    /* (B1) Loop untuk mencari nilai di array */
    for (i = 0; i < ____; i++) {          /* (B1) batas atas: jumlah elemen array */
        if (nilai[i] == ____) {            /* (B2) bandingkan elemen ke-i dengan nilai yang dicari */
            printf("Ditemukan di indeks %d.\n", i);
            ditemukan = 1;
            break;   /* berhenti setelah ditemukan */
        }
    }

    /* (B3) Tampilkan pesan jika tidak ditemukan */
    if (____ == 0) {                       /* (B3) cek flag ditemukan */
        printf("Tidak ditemukan.\n");
    }

    return 0;
}