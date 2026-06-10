/*
 * Pertemuan 5 — Task A1: Definisi Struct & typedef
 * Topik   : Struct & Modular Programming
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar di samping ____ memberikan petunjuk
 *   - Compile: gcc 05_Task_A1.c -o 05_Task_A1
 *   - Jalankan: ./05_Task_A1  (Linux/Mac)  atau  05_Task_A1.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>

/* ============================================================
 * BAGIAN A — Definisi Struct & typedef
 *
 * Lengkapi definisi struct Mahasiswa dengan typedef sehingga
 * tipe ini bisa dipakai tanpa kata "struct" di depannya.
 *
 * Anggota yang dibutuhkan:
 *   - nama  : string maksimal 50 karakter
 *   - nim   : string maksimal 15 karakter
 *   - ipk   : angka desimal
 * ============================================================ */

typedef ____ {          // (A1) kata kunci untuk mendefinisikan struct
    ____ nama[50];      // (A2) tipe data untuk string
    char nim[15];
    ____ ipk;           // (A3) tipe data untuk angka desimal (IPK)
} Mahasiswa;            // (A4) nama alias (typedef) — sudah benar, jangan ubah


/* ============================================================
 * Setelah struct terdefinisi dengan benar, program ini harus
 * bisa dikompilasi dan mencetak:
 *   Struct Mahasiswa berhasil dibuat!
 *   Nama : Test
 * ============================================================ */

int main() {
    Mahasiswa mhs;
    strcpy(mhs.nama, "Test");
    strcpy(mhs.nim, "0000000");
    mhs.ipk = 0.0;

    printf("Struct Mahasiswa berhasil dibuat!\n");
    printf("Nama : %s\n", mhs.nama);
    return 0;
}
