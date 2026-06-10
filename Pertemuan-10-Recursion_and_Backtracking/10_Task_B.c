/*
 * Pertemuan 10 — Task B: Backtracking — Maze Solver
 * Topik   : Recursion & Backtracking
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah struct, konstanta, atau fungsi yang SUDAH LENGKAP
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 10_Task_B.c -o 10_Task_B
 *   - Jalankan: ./10_Task_B  (Linux/Mac)  atau  10_Task_B.exe  (Windows)
 *
 * ---------------------------------------------------------------
 * Representasi Maze (array 2D integer):
 *   0 = jalur kosong (bisa dilewati)
 *   1 = dinding      (tidak bisa dilewati)
 *   2 = jalur solusi (ditandai saat ditemukan)
 *
 * Tujuan: temukan jalur dari sel (0,0) ke sel (BARIS-1, KOLOM-1)
 *         menggunakan rekursi + backtracking.
 * ---------------------------------------------------------------
 */

#include <stdio.h>

#define BARIS 5
#define KOLOM 5

/*
 * Maze yang digunakan untuk pengujian.
 * S = (0,0), E = (4,4)
 * Jalur valid: (0,0)→(0,1)→(1,1)→(1,2)→(2,2)→(2,3)→(3,3)→(4,3)→(4,4)
 */
int maze[BARIS][KOLOM] = {
    {0, 0, 1, 1, 1},
    {1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1},
    {1, 1, 1, 0, 0}
};

/* Maze cadangan untuk uji "tidak ada solusi" (dipakai di Soal 3) */
int maze_buntu[BARIS][KOLOM] = {
    {0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0}
};


/* ============================================================
 * Fungsi Bantu — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

void cetak_maze(int m[][KOLOM]) {
    for (int r = 0; r < BARIS; r++) {
        for (int k = 0; k < KOLOM; k++) {
            if      (m[r][k] == 0) printf(". ");
            else if (m[r][k] == 1) printf("# ");
            else if (m[r][k] == 2) printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

/* Salin isi maze sumber ke maze tujuan */
void salin_maze(int sumber[][KOLOM], int tujuan[][KOLOM]) {
    for (int r = 0; r < BARIS; r++)
        for (int k = 0; k < KOLOM; k++)
            tujuan[r][k] = sumber[r][k];
}


/* ============================================================
 * SOAL 1 — Cek Apakah Sel Valid
 *
 * Kembalikan 1 jika sel (r, k) boleh dikunjungi, 0 jika tidak.
 * Sebuah sel boleh dikunjungi jika:
 *   a. Koordinatnya di dalam batas maze (0 ≤ r < BARIS, 0 ≤ k < KOLOM).
 *   b. Nilainya adalah 0 (jalur kosong, bukan dinding atau sudah ditandai).
 *
 * Hint: gunakan operator && (AND) untuk menggabungkan semua kondisi.
 * ============================================================ */

int valid(int m[][KOLOM], int r, int k) {
    // TODO: kembalikan 1 jika (r,k) bisa dikunjungi, 0 jika tidak
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 2 — Selesaikan Maze dengan Backtracking
 *
 * Cari jalur dari sel (r, k) ke tujuan (BARIS-1, KOLOM-1).
 * Kembalikan 1 jika jalur ditemukan, 0 jika tidak ada jalur.
 *
 * Algoritma:
 *   1. Cek apakah (r, k) valid menggunakan fungsi valid().
 *      Jika tidak → return 0.
 *   2. Base case: jika (r, k) adalah tujuan (BARIS-1, KOLOM-1):
 *      - Tandai m[r][k] = 2 (bagian dari solusi).
 *      - return 1.
 *   3. Tandai m[r][k] = 2 (sel ini dipilih sebagai bagian jalur).
 *   4. Coba keempat arah secara rekursif:
 *      - Bawah  : selesaikan(m, r+1, k)
 *      - Kanan  : selesaikan(m, r, k+1)
 *      - Atas   : selesaikan(m, r-1, k)
 *      - Kiri   : selesaikan(m, r, k-1)
 *      Jika salah satu mengembalikan 1 → return 1 (solusi ditemukan!).
 *   5. Backtrack: semua arah buntu → batalkan penandaan m[r][k] = 0,
 *      lalu return 0.
 *
 * PENTING: langkah 5 (backtrack) adalah inti backtracking.
 * Tanpanya, sel yang sudah dicoba tidak bisa dikunjungi dari jalur lain.
 * ============================================================ */

int selesaikan(int m[][KOLOM], int r, int k) {
    // TODO: implementasikan maze solver dengan backtracking
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Hitung Jumlah Langkah Solusi
 *
 * Setelah maze diselesaikan (sel solusi ditandai dengan 2),
 * hitung berapa banyak sel yang menjadi bagian jalur solusi
 * (termasuk sel start dan end).
 *
 * Hint: loop semua sel, hitung yang bernilai 2.
 * ============================================================ */

int hitung_langkah(int m[][KOLOM]) {
    // TODO: hitung jumlah sel yang bernilai 2
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

int main() {
    int kerja[BARIS][KOLOM];

    /* --- Uji 1: maze normal --- */
    printf("=== Maze Awal ===\n");
    cetak_maze(maze);

    salin_maze(maze, kerja);
    if (selesaikan(kerja, 0, 0)) {
        printf("=== Solusi Ditemukan (jalur ditandai *) ===\n");
        cetak_maze(kerja);
        printf("Jumlah langkah (sel di jalur): %d\n\n", hitung_langkah(kerja));
    } else {
        printf("Tidak ada solusi.\n\n");
    }

    /* --- Uji 2: maze tanpa solusi --- */
    printf("=== Maze Buntu (tidak ada jalur) ===\n");
    cetak_maze(maze_buntu);

    salin_maze(maze_buntu, kerja);
    if (selesaikan(kerja, 0, 0)) {
        printf("Solusi ditemukan.\n\n");  /* tidak harusnya masuk sini */
    } else {
        printf("Tidak ada solusi. ✓ (diharapkan)\n\n");
    }

    /* --- Uji 3: uji fungsi valid --- */
    printf("=== Uji Fungsi valid() ===\n");
    /* reset maze kerja ke kondisi awal */
    salin_maze(maze, kerja);

    printf("valid(kerja, 0, 0) = %d  (harusnya 1 — jalur kosong)\n",  valid(kerja, 0, 0));
    printf("valid(kerja, 0, 2) = %d  (harusnya 0 — dinding)\n",       valid(kerja, 0, 2));
    printf("valid(kerja,-1, 0) = %d  (harusnya 0 — luar batas)\n",    valid(kerja,-1, 0));
    printf("valid(kerja, 5, 0) = %d  (harusnya 0 — luar batas)\n",    valid(kerja, 5, 0));
    printf("valid(kerja, 4, 4) = %d  (harusnya 1 — tujuan, kosong)\n",valid(kerja, 4, 4));

    /* sel yang sudah ditandai (2) tidak valid lagi */
    kerja[1][1] = 2;
    printf("valid(kerja, 1, 1) = %d  (harusnya 0 — sudah ditandai)\n", valid(kerja, 1, 1));

    return 0;
}
