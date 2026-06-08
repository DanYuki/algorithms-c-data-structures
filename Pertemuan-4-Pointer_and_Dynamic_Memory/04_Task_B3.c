/*
 * Pertemuan 4 — Task B3: Fungsi dengan Return Pointer
 * Topik   : Pointer & Dynamic Memory
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 04_Task_B3.c -o 04_Task_B3
 *   - Jalankan: ./04_Task_B3  (Linux/Mac)  atau  04_Task_B3.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>

/* ============================================================
 * Lengkapi fungsi buat_array_ganjil yang:
 *   - Menerima parameter n (jumlah elemen)
 *   - Mengalokasikan array int berukuran n
 *   - Mengisi array dengan bilangan ganjil: 1, 3, 5, ..., (2n-1)
 *   - Mengembalikan pointer ke array tersebut
 *
 * Pemanggil (main) bertanggung jawab membebaskan memori.
 *
 * Contoh output (n=5):
 *   Bilangan ganjil pertama 5: 1 3 5 7 9
 * ============================================================ */

// (1) Lengkapi tipe kembalian dan parameter
____ buat_array_ganjil(int n) {
    int *arr;
    int i;

    // (2) Alokasi memori untuk n elemen
    arr = (int *) malloc(____ * sizeof(int));

    if (arr == NULL) {
        return ____;  // (3) kembalikan NULL jika alokasi gagal
    }

    // (4) Isi dengan bilangan ganjil: 1, 3, 5, ...
    for (i = 0; i < n; i++) {
        arr[i] = ____;  // (4) rumus bilangan ganjil ke-i (mulai i=0)
    }

    return arr;
}

int main() {
    int n = 5;
    int i;
    int *hasil;

    printf("=== Task B3: Fungsi Return Pointer ===\n");

    // (5) Panggil buat_array_ganjil dan simpan hasilnya
    hasil = ____(____);;

    if (hasil == NULL) {
        printf("Gagal membuat array.\n");
        return 1;
    }

    printf("Bilangan ganjil pertama %d: ", n);
    for (i = 0; i < n; i++) {
        printf("%d ", hasil[i]);
    }
    printf("\n");

    // (6) Bebaskan memori yang dialokasikan di dalam fungsi
    ____; // free hasil
    ____; // set NULL

    return 0;
}
