/*
 * Pertemuan 4 — Task B: Dynamic Memory (malloc / calloc / free)
 * Topik   : Pointer & Dynamic Memory
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Compile: gcc 04_Task_B.c -o 04_Task_B
 *   - Jalankan: ./04_Task_B  (Linux/Mac)  atau  04_Task_B.exe  (Windows)
 */

#include <stdio.h>
#include <____>   // (0) tambahkan header untuk malloc, calloc, free

/* ============================================================
 * BAGIAN A — malloc: Array Dinamis Sesuai Input
 *
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

void bagian_A() {
    int n, i;
    int *arr;

    printf("=== Bagian A: malloc ===\n");
    printf("Jumlah elemen: ");
    scanf("%d", &n);

    // (A1) Alokasi memori untuk n elemen int menggunakan malloc
    arr = (int *) ____(____ * sizeof(int));

    // (A2) Cek apakah alokasi berhasil
    if (arr == ____) {
        printf("Alokasi memori gagal!\n");
        return;
    }

    // (A3) Isi array dengan nilai 1, 2, ..., n
    for (i = 0; i < n; i++) {
        arr[i] = ____;  // (A3) nilai elemen ke-i adalah i+1
    }

    // Tampilkan isi array
    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // (A4) Bebaskan memori
    ____(arr);
    arr = ____;   // (A5) set ke NULL setelah free

    printf("Memori berhasil dibebaskan.\n");
}


/* ============================================================
 * BAGIAN B — calloc: Array Diinisialisasi Nol
 *
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

void bagian_B() {
    int n, i;
    int *arr;

    printf("\n=== Bagian B: calloc ===\n");
    printf("Jumlah elemen: ");
    scanf("%d", &n);

    // (B1) Alokasi dengan calloc — semua elemen otomatis 0
    arr = (int *) ____(n, sizeof(int));

    if (arr == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }

    // Tampilkan isi awal (seharusnya semua 0)
    printf("Isi awal (calloc): ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // (B2) Isi array dengan nilai n, n-1, ..., 1
    for (i = 0; i < n; i++) {
        arr[i] = ____;  // (B2) nilai menurun dari n sampai 1
    }

    printf("Setelah diisi    : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // (B3) Bebaskan memori dan set ke NULL
    ____; // free
    ____;  // set NULL
}


/* ============================================================
 * BAGIAN C — Fungsi dengan Return Pointer
 *
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

// (C1) Lengkapi tipe kembalian dan parameter
____ buat_array_ganjil(int n) {
    int *arr;
    int i;

    // (C2) Alokasi memori untuk n elemen
    arr = (int *) malloc(____ * sizeof(int));

    if (arr == NULL) {
        return ____;  // (C3) kembalikan NULL jika alokasi gagal
    }

    // (C4) Isi dengan bilangan ganjil: 1, 3, 5, ...
    for (i = 0; i < n; i++) {
        arr[i] = ____;  // (C4) rumus bilangan ganjil ke-i (mulai i=0)
    }

    return arr;  // kembalikan pointer ke array yang baru dibuat
}

void bagian_C() {
    int n = 5;
    int i;
    int *hasil;

    printf("\n=== Bagian C: Fungsi Return Pointer ===\n");

    // (C5) Panggil buat_array_ganjil dan simpan hasilnya
    hasil = ____(____);;

    if (hasil == NULL) {
        printf("Gagal membuat array.\n");
        return;
    }

    printf("Bilangan ganjil pertama %d: ", n);
    for (i = 0; i < n; i++) {
        printf("%d ", hasil[i]);
    }
    printf("\n");

    // (C6) Bebaskan memori yang dialokasikan di dalam fungsi
    ____; // free hasil
    ____; // set NULL
}


/* ============================================================
 * main
 * ============================================================ */

int main() {
    bagian_A();
    bagian_B();
    bagian_C();
    return 0;
}
