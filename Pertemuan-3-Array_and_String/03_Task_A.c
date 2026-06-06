/*
 * Pertemuan 3 — Task A: Array 1D & Array 2D
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 03_Task_A.c -o 03_Task_A
 *   - Jalankan: ./03_Task_A  (Linux/Mac)  atau  03_Task_A.exe  (Windows)
 */

#include <stdio.h>

/* ============================================================
 * BAGIAN A — Array 1D: Input & Statistik
 *
 * Program membaca 5 nilai dari pengguna ke dalam array,
 * lalu menampilkan: total, rata-rata, nilai terbesar, terkecil.
 *
 * Contoh output:
 *   Masukkan 5 nilai:
 *     nilai[0] = 70
 *     nilai[1] = 85
 *     nilai[2] = 60
 *     nilai[3] = 92
 *     nilai[4] = 78
 *
 *   Total    : 385
 *   Rata-rata: 77.0
 *   Terbesar : 92
 *   Terkecil : 60
 * ============================================================ */

void bagian_A() {
    int nilai[5];
    int i;
    int total    = 0;
    int terbesar;
    int terkecil;

    printf("=== Bagian A: Statistik Array 1D ===\n");
    printf("Masukkan 5 nilai:\n");

    // (A1) Loop untuk membaca input ke setiap elemen array
    for (i = 0; ____ ; ____) {
        printf("  nilai[%d] = ", i);
        scanf("%d", ____); // (A2) alamat elemen ke-i
    }

    // Inisialisasi terbesar & terkecil dari elemen pertama
    terbesar = ____;  // (A3) elemen pertama array
    terkecil = ____;  // (A4) elemen pertama array

    // (A5) Loop untuk menghitung total, terbesar, dan terkecil
    for (i = 0; i < 5; i++) {
        total = total + ____;  // (A6) tambahkan elemen ke-i ke total

        if (____ > terbesar) { // (A7) cek apakah elemen ke-i lebih besar dari terbesar
            terbesar = nilai[i];
        }
        if (____ < terkecil) { // (A8) cek apakah elemen ke-i lebih kecil dari terkecil
            terkecil = nilai[i];
        }
    }

    printf("\nTotal    : %d\n", total);
    printf("Rata-rata: %.1f\n", (float)total / ____); // (A9) bagi dengan jumlah elemen
    printf("Terbesar : %d\n", terbesar);
    printf("Terkecil : %d\n", terkecil);
}


/* ============================================================
 * BAGIAN B — Array 1D: Cari Elemen
 *
 * Lanjutan dari Bagian A — gunakan array nilai[] yang sama.
 * Program meminta pengguna memasukkan angka yang dicari,
 * lalu tampilkan apakah angka tersebut ada di array dan di indeks berapa.
 *
 * Contoh output (mencari 85):
 *   Cari nilai: 85
 *   Ditemukan di indeks 1.
 *
 * Contoh output (mencari 99):
 *   Cari nilai: 99
 *   Tidak ditemukan.
 * ============================================================ */

void bagian_B() {
    int nilai[5] = {70, 85, 60, 92, 78};  // data tetap untuk latihan
    int i;
    int cari;
    int ditemukan = 0;  // flag: 0 = belum ditemukan

    printf("\n=== Bagian B: Pencarian di Array ===\n");
    printf("Cari nilai: ");
    scanf("%d", &cari);

    // (B1) Loop untuk mencari nilai di array
    for (i = 0; i < ____; i++) { // (B1) batas atas loop
        if (nilai[i] == ____) {  // (B2) bandingkan elemen ke-i dengan nilai yang dicari
            printf("Ditemukan di indeks %d.\n", i);
            ditemukan = 1;
            break;  // berhenti setelah ditemukan
        }
    }

    // (B3) Tampilkan pesan jika tidak ditemukan
    if (____ == 0) { // (B3) cek flag ditemukan
        printf("Tidak ditemukan.\n");
    }
}


/* ============================================================
 * BAGIAN C — Array 2D: Input & Tampilkan Matriks
 *
 * Program membaca matriks 2x3 dari pengguna, lalu menampilkannya
 * dalam format tabel rapi, dan menghitung jumlah seluruh elemen.
 *
 * Contoh output:
 *   Isi matriks 2x3 (baris demi baris):
 *     [0][0] = 1
 *     [0][1] = 2
 *     [0][2] = 3
 *     [1][0] = 4
 *     [1][1] = 5
 *     [1][2] = 6
 *
 *   Isi matriks:
 *    1  2  3
 *    4  5  6
 *
 *   Jumlah semua elemen: 21
 * ============================================================ */

void bagian_C() {
    int matriks[2][3];
    int baris, kolom;
    int jumlah = 0;

    printf("\n=== Bagian C: Matriks 2x3 ===\n");
    printf("Isi matriks 2x3 (baris demi baris):\n");

    // (C1) Nested loop untuk membaca input ke matriks
    for (baris = 0; baris < ____; baris++) {       // (C1a) jumlah baris
        for (kolom = 0; kolom < ____; kolom++) {   // (C1b) jumlah kolom
            printf("  [%d][%d] = ", baris, kolom);
            scanf("%d", &matriks[____][____]);       // (C2) akses elemen [baris][kolom]
        }
    }

    printf("\nIsi matriks:\n");

    // (C3) Nested loop untuk menampilkan matriks dan menghitung jumlah
    for (baris = 0; baris < 2; baris++) {
        for (kolom = 0; kolom < 3; kolom++) {
            printf("%3d", ____);       // (C4) cetak elemen [baris][kolom]
            jumlah = jumlah + ____;    // (C5) tambahkan ke jumlah
        }
        printf("\n");
    }

    printf("\nJumlah semua elemen: %d\n", jumlah);
}


/* ============================================================
 * main — Panggil ketiga bagian secara berurutan
 * ============================================================ */

int main() {
    bagian_A();
    bagian_B();
    bagian_C();
    return 0;
}
