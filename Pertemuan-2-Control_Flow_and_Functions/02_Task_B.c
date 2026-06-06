/*
 * Pertemuan 2 — Task B: Fungsi & Rekursi
 * Topik   : Control Flow & Functions
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ atau // TODO
 *   - Setelah semua bagian diisi, program harus bisa dikompilasi & berjalan
 *   - Compile: gcc 02_Task_B.c -o 02_Task_B
 *   - Jalankan: ./02_Task_B  (Linux/Mac)  atau  02_Task_B.exe  (Windows)
 */

#include <stdio.h>

/* ============================================================
 * BAGIAN A — Definisi Fungsi: Luas & Keliling Persegi Panjang
 *
 * Lengkapi dua fungsi berikut:
 *   1. hitung_luas    — menerima panjang & lebar, mengembalikan luas (int)
 *   2. hitung_keliling — menerima panjang & lebar, mengembalikan keliling (int)
 *
 * Rumus: luas = panjang * lebar
 *        keliling = 2 * (panjang + lebar)
 *
 * Contoh output:
 *   Panjang: 5, Lebar: 3
 *   Luas     : 15
 *   Keliling : 16
 * ============================================================ */

/* (A1) Lengkapi tipe kembalian, nama fungsi, dan parameter */
____ ____(____) {
    return ____;   /* (A2) Isi rumus luas */
}

/* (A3) Lengkapi tipe kembalian, nama fungsi, dan parameter */
____ ____(____) {
    return ____;   /* (A4) Isi rumus keliling */
}


/* ============================================================
 * BAGIAN B — Fungsi void: Cetak Tabel Perkalian
 *
 * Lengkapi fungsi cetak_tabel_perkalian yang:
 *   - Menerima satu parameter: angka (int)
 *   - Tidak mengembalikan nilai (void)
 *   - Mencetak tabel perkalian angka dari 1 sampai 10
 *
 * Contoh output untuk angka = 3:
 *   3 x  1 =  3
 *   3 x  2 =  6
 *   ...
 *   3 x 10 = 30
 * ============================================================ */

/* (B1) Lengkapi tipe kembalian dan parameter */
____ cetak_tabel_perkalian(____) {
    int i;

    /* (B2) Lengkapi for-loop untuk mencetak tabel 1 sampai 10 */
    for (i = 1; ____; ____) {
        printf("%d x %2d = %2d\n", angka, i, ____);  /* (B3) isi hasil perkalian */
    }
}


/* ============================================================
 * BAGIAN C — Rekursi: Pangkat
 *
 * Lengkapi fungsi rekursif pangkat(basis, eksponen) yang menghitung
 * basis^eksponen (basis pangkat eksponen).
 *
 * Definisi rekursif:
 *   pangkat(basis, 0) = 1            ← base case
 *   pangkat(basis, n) = basis * pangkat(basis, n-1)   ← recursive case
 *
 * Contoh output:
 *   2^0 = 1
 *   2^1 = 2
 *   2^5 = 32
 *   3^4 = 81
 * ============================================================ */

int pangkat(int basis, int eksponen) {
    /* (C1) Lengkapi base case */
    if (____) {
        return ____;
    }

    /* (C2) Lengkapi recursive case */
    return ____;
}


/* ============================================================
 * main — Memanggil dan menguji semua fungsi di atas
 * ============================================================ */

int main() {
    /* --- Uji Bagian A --- */
    int panjang = 5, lebar = 3;
    printf("=== Bagian A: Luas & Keliling ===\n");
    printf("Panjang: %d, Lebar: %d\n", panjang, lebar);

    /* (D1) Panggil hitung_luas dengan panjang dan lebar */
    printf("Luas     : %d\n", ____);

    /* (D2) Panggil hitung_keliling dengan panjang dan lebar */
    printf("Keliling : %d\n", ____);

    /* --- Uji Bagian B --- */
    int angka_tabel;
    printf("\n=== Bagian B: Tabel Perkalian ===\n");
    printf("Masukkan angka: ");
    scanf("%d", &angka_tabel);

    /* (D3) Panggil cetak_tabel_perkalian */
    ____;

    /* --- Uji Bagian C --- */
    printf("\n=== Bagian C: Fungsi Pangkat ===\n");
    printf("2^0 = %d\n", pangkat(2, 0));
    printf("2^1 = %d\n", pangkat(2, 1));
    printf("2^5 = %d\n", pangkat(2, 5));

    /* (D4) Panggil pangkat(3, 4) dan cetak hasilnya dalam format "3^4 = ..." */
    ____

    return 0;
}
