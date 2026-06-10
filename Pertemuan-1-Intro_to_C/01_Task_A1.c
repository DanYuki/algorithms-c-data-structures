/*
 * Pertemuan 1 — Task A1: Hello World
 * Topik   : Intro to C, Problem Solving & AI Engineering
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian yang bertanda ____  atau // TODO
 *   - Setelah semua bagian diisi, program harus bisa dikompilasi dan berjalan
 *   - Compile: gcc 01_Task_A1.c -o 01_Task_A1
 *   - Jalankan: ./01_Task_A1  (Linux/Mac)  atau  01_Task_A1.exe  (Windows)
 */

/* ============================================================
 * BAGIAN A — Hello World
 * Lengkapi program berikut agar mencetak:
 *   Halo, [nama kamu]!
 *   Ini program C pertamaku.
 * ============================================================ */

#include ____     /* (A1) Header yang memuat printf dan scanf */

int ____() {      /* (A2) Nama fungsi utama program C */

    printf("Halo, %s!\n", "Haltev");       /* Ganti "Haltev" dengan namamu */
    printf(____);                   /* (A3) Cetak: "Ini program C pertamaku.\n" */

    return 0;  /* (A4) Nilai kembalian yang menandakan program sukses */
}