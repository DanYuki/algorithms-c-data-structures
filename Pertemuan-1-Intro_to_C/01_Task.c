/*
 * Pertemuan 1 — Task: Fill in the Blank
 * Topik   : Intro to C, Problem Solving & AI Engineering
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian yang bertanda \ /* ____ *\ / atau // TODO
 *   - Setelah semua bagian diisi, program harus bisa dikompilasi dan berjalan
 *   - Compile: gcc 01_Task.c -o 01_Task
 *   - Jalankan: ./01_Task  (Linux/Mac)  atau  01_Task.exe  (Windows)
 */

/* ============================================================
 * BAGIAN A — Hello World
 * Lengkapi program berikut agar mencetak:
 *   Halo, [nama kamu]!
 *   Ini program C pertamaku.
 * ============================================================ */

#include ____     /* (A1) Header yang memuat printf dan scanf */

int ____() {      /* (A2) Nama fungsi utama program C */

    printf("Halo, %s!\n", "Dzaka");       /* Ganti "Dzaka" dengan namamu */
    printf(____);                   /* (A3) Cetak: "Ini program C pertamaku.\n" */

    return ____;  /* (A4) Nilai kembalian yang menandakan program sukses */
}


/* ============================================================
 * BAGIAN B — Variabel & Format Specifier
 * Lengkapi deklarasi variabel dan format specifier yang tepat.
 *
 * Setelah diisi, output yang diharapkan:
 *   Nama   : Budi
 *   Usia   : 20
 *   Nilai  : 88.50
 *   Grade  : A
 * ============================================================ */

/*
 * CATATAN: Hapus komentar blok ini (slash-bintang di awal dan akhir)
 * untuk mengaktifkan Bagian B. Selesaikan Bagian A terlebih dahulu.
 *
#include <stdio.h>

int main() {

    // (B1) Deklarasi variabel — isi tipe data yang tepat
    ____  nama[]  = "Budi";   // teks / string
    ____  usia    = 20;       // bilangan bulat
    ____  nilai   = 88.5;     // bilangan desimal
    ____  grade   = 'A';      // satu karakter

    // (B2) Cetak setiap variabel — isi format specifier yang tepat
    printf("Nama   : %s\n",    nama);
    printf("Usia   : ____\n", usia);    // format untuk int
    printf("Nilai  : ____\n", nilai);   // format untuk float, 2 desimal
    printf("Grade  : ____\n", grade);   // format untuk char

    return 0;
}
*
*/


/* ============================================================
 * BAGIAN C — Terjemahkan Pseudocode ke Kode C
 *
 * Pseudocode:
 *   MULAI
 *     TAMPILKAN "Masukkan nilai kamu (0-100): "
 *     BACA nilai
 *
 *     JIKA nilai >= 60 MAKA
 *       TAMPILKAN "Selamat, kamu LULUS!"
 *     SELAIN ITU
 *       TAMPILKAN "Kamu BELUM LULUS. Semangat!"
 *     AKHIR JIKA
 *   SELESAI
 *
 * Output yang diharapkan (contoh input 75):
 *   Masukkan nilai kamu (0-100): 75
 *   Selamat, kamu LULUS!
 *
 * Output yang diharapkan (contoh input 45):
 *   Masukkan nilai kamu (0-100): 45
 *   Kamu BELUM LULUS. Semangat!
 * ============================================================ */

/*
 * CATATAN: Hapus komentar blok ini untuk mengaktifkan Bagian C.
 * Pastikan hanya satu fungsi main() yang aktif di satu waktu.
 *
#include <stdio.h>

int main() {

    ____ nilai;   /* (C1) Deklarasi variabel yang sesuai untuk nilai 0-100 */

    printf(____); /* (C2) Cetak: "Masukkan nilai kamu (0-100): " */
    scanf(____);  /* (C3) Baca input ke variabel nilai */

    /* (C4) Lengkapi kondisi if-else sesuai pseudocode */
    if (____) {
        printf("Selamat, kamu LULUS!\n");
    } ____ {
        printf("Kamu BELUM LULUS. Semangat!\n");
    }

    return 0;
}
*
*/
