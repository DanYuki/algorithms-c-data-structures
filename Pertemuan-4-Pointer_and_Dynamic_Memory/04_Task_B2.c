/*
 * Pertemuan 4 — Task B2: calloc — Array Diinisialisasi Nol
 * Topik   : Pointer & Dynamic Memory
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 04_Task_B2.c -o 04_Task_B2
 *   - Jalankan: ./04_Task_B2  (Linux/Mac)  atau  04_Task_B2.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>

/* ============================================================
 * Program meminta jumlah elemen N,
 * mengalokasikan array int berukuran N dengan calloc
 * (semua elemen awalnya 0),
 * menampilkan isi awal, mengisi ulang dengan nilai N, N-1, ..., 1,
 * menampilkan kembali, lalu membebaskan memori.
 *
 * Contoh output (N=3):
 *   Jumlah elemen: 3
 *   Isi awal (calloc): 0 0 0
 *   Setelah diisi    : 3 2 1
 * ============================================================ */

int main() {
    int n, i;
    int *arr;

    printf("=== Task B2: calloc ===\n");
    printf("Jumlah elemen: ");
    scanf("%d", &n);

    // (1) Alokasi dengan calloc — semua elemen otomatis 0
    arr = (int *) ____(n, sizeof(int));

    if (arr == NULL) {
        printf("Alokasi memori gagal!\n");
        return 1;
    }

    printf("Isi awal (calloc): ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // (2) Isi array dengan nilai n, n-1, ..., 1
    for (i = 0; i < n; i++) {
        arr[i] = ____;  // (2) nilai menurun dari n sampai 1
    }

    printf("Setelah diisi    : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // (3) Bebaskan memori dan set ke NULL
    ____; // free
    ____;  // set NULL

    return 0;
}