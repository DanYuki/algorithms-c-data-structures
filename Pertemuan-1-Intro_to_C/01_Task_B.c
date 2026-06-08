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
 * BAGIAN B — Variabel & Format Specifier
 * Lengkapi deklarasi variabel dan format specifier yang tepat.
 *
 * Setelah diisi, output yang diharapkan:
 *   Nama   : Budi
 *   Usia   : 20
 *   Nilai  : 88.50
 *   Grade  : A
 * ============================================================ */

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
