/*
 * Pertemuan 4 — Task A: Pointer Dasar & Pass-by-Reference
 * Topik   : Pointer & Dynamic Memory
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 04_Task_A.c -o 04_Task_A
 *   - Jalankan: ./04_Task_A  (Linux/Mac)  atau  04_Task_A.exe  (Windows)
 */

#include <stdio.h>

/* ============================================================
 * BAGIAN A — Deklarasi & Dereference Pointer
 *
 * Lengkapi kode sehingga menghasilkan output:
 *   Nilai x          : 10
 *   Alamat x         : (alamat memori, nilai beda di tiap komputer)
 *   Isi ptr (alamat) : (sama dengan alamat x)
 *   Nilai via *ptr   : 10
 *   Nilai x setelah *ptr = 99 : 99
 * ============================================================ */

void bagian_A() {
    int x = 10;
    int ____ ptr;        // (A1) deklarasi ptr sebagai pointer ke int

    ptr = ____;          // (A2) arahkan ptr ke alamat variabel x

    printf("=== Bagian A: Deklarasi & Dereference ===\n");
    printf("Nilai x          : %d\n",  x);
    printf("Alamat x         : %p\n", ____);  // (A3) cetak alamat x
    printf("Isi ptr (alamat) : %p\n", ____);  // (A4) cetak nilai ptr (juga alamat x)
    printf("Nilai via *ptr   : %d\n", ____);  // (A5) dereference ptr untuk baca nilai

    // (A6) Ubah nilai x melalui pointer
    ____ = 99;  // (A6) tulis 99 ke alamat yang ditunjuk ptr

    printf("Nilai x setelah *ptr = 99 : %d\n", x);
}


/* ============================================================
 * BAGIAN B — Fungsi dengan Pointer: Increment
 *
 * Lengkapi fungsi tambah_satu yang menambah nilai variabel
 * sebesar 1 melalui pointer (pass-by-reference).
 *
 * Contoh output:
 *   Sebelum: 5
 *   Sesudah: 6
 * ============================================================ */

// (B1) Lengkapi parameter fungsi — harus menerima pointer ke int
void tambah_satu(____ pn) {
    ____ = ____ + 1;  // (B2) tambah 1 ke nilai yang ditunjuk pn
}

void bagian_B() {
    int nilai = 5;

    printf("\n=== Bagian B: Pass-by-Reference ===\n");
    printf("Sebelum: %d\n", nilai);

    tambah_satu(____);  // (B3) kirim alamat nilai, bukan nilai itu sendiri

    printf("Sesudah: %d\n", nilai);
}


/* ============================================================
 * BAGIAN C — Fungsi Swap
 *
 * Lengkapi fungsi swap yang menukar nilai dua variabel
 * menggunakan pointer.
 *
 * Contoh output:
 *   Sebelum swap: a = 5, b = 10
 *   Sesudah swap: a = 10, b = 5
 * ============================================================ */

// (C1) Lengkapi parameter fungsi swap
void swap(____ pa, ____ pb) {
    int temp;

    temp = ____;    // (C2) simpan nilai di alamat pa ke temp
    ____ = ____;    // (C3) salin nilai dari alamat pb ke alamat pa
    ____ = temp;    // (C4) salin temp ke alamat pb
}

void bagian_C() {
    int a = 5, b = 10;

    printf("\n=== Bagian C: Swap via Pointer ===\n");
    printf("Sebelum swap: a = %d, b = %d\n", a, b);

    swap(____, ____);  // (C5) kirim alamat a dan b

    printf("Sesudah swap: a = %d, b = %d\n", a, b);
}


/* ============================================================
 * BAGIAN D — Lacak Nilai Pointer
 *
 * Ikuti alur kode di bawah dan prediksi outputnya SEBELUM
 * menjalankan program. Tulis prediksimu di komentar, lalu
 * jalankan untuk memverifikasi.
 *
 * Tugas: isi ____ dengan ekspresi yang tepat agar output sesuai.
 * ============================================================ */

void bagian_D() {
    int p = 10, q = 20;
    int *ptr1 = &p;
    int *ptr2 = &q;

    printf("\n=== Bagian D: Lacak Nilai Pointer ===\n");

    printf("*ptr1        : %d\n", ____);   // (D1) nilai yang ditunjuk ptr1
    printf("*ptr2        : %d\n", ____);   // (D2) nilai yang ditunjuk ptr2

    *ptr1 = *ptr1 + *ptr2;  // (D3) apa nilai p sekarang? tulis prediksimu: ____

    printf("p setelah *ptr1 = *ptr1 + *ptr2 : %d\n", p);

    ptr1 = ptr2;            // (D4) ptr1 sekarang menunjuk ke q
    *ptr1 = 5;              // (D5) apa nilai q sekarang? tulis prediksimu: ____

    printf("q setelah ptr1 = ptr2 lalu *ptr1 = 5 : %d\n", ____); // (D6) cetak q
}


/* ============================================================
 * main
 * ============================================================ */

int main() {
    bagian_A();
    bagian_B();
    bagian_C();
    bagian_D();
    return 0;
}
