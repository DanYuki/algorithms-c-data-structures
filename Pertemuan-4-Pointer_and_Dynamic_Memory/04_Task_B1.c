/*
 * Pertemuan 4 — Task B1: malloc — Array Dinamis Sesuai Input
 * Topik   : Pointer & Dynamic Memory
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 04_Task_B1.c -o 04_Task_B1
 *   - Jalankan: ./04_Task_B1  (Linux/Mac)  atau  04_Task_B1.exe  (Windows)
 */

#include <stdio.h>
#include <____>   // (0) tambahkan header untuk malloc dan free

/* ============================================================
 * Program meminta jumlah elemen N dari pengguna,
 * mengalokasikan array int berukuran N dengan malloc,
 * mengisi array dengan nilai 1, 2, ..., N,
 * menampilkannya, lalu membebaskan memori.
 *
 * Contoh output (N=4):
 *   Jumlah elemen: 4
 *   Array: 1 2 3 4
 *   Memori berhasil dibebaskan.
 * ============================================================ */

int main() {
    int n, i;
    int *arr;

    printf("=== Task B1: malloc ===\n");
    printf("Jumlah elemen: ");
    scanf("%d", &n);

    // (1) Alokasi memori untuk n elemen int menggunakan malloc
    arr = (int *) ____(____ * sizeof(int));

    // (2) Cek apakah alokasi berhasil
    if (arr == ____) {
        printf("Alokasi memori gagal!\n");
        return 1;
    }

    // (3) Isi array dengan nilai 1, 2, ..., n
    for (i = 0; i < n; i++) {
        arr[i] = ____;  // (3) nilai elemen ke-i adalah i+1
    }

    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // (4) Bebaskan memori
    ____(arr);
    arr = ____;   // (5) set ke NULL setelah free

    printf("Memori berhasil dibebaskan.\n");

    return 0;
}