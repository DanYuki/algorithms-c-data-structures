/*
 * Pertemuan 8 — Task A: Stack Berbasis Array
 * Topik   : Stack (Array & Linked List)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal (fungsi kosong tidak crash saat dipanggil)
 *   - Compile: gcc 08_Task_A.c -o 08_Task_A
 *   - Jalankan: ./08_Task_A  (Linux/Mac)  atau  08_Task_A.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>

#define KAPASITAS 8


/* ============================================================
 * Definisi Struct — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

typedef struct {
    int data[KAPASITAS];
    int top;
} StackArray;


/* ============================================================
 * SOAL 1 — Inisialisasi Stack
 *
 * Implementasikan init() agar stack siap dipakai.
 * Stack yang baru dibuat harus dianggap kosong.
 *
 * Hint: stack kosong ditandai dengan top bernilai -1.
 * ============================================================ */

void init(StackArray *s) {
    // TODO: set top ke nilai yang menandakan stack kosong
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 2 — Cek Stack Kosong & Penuh
 *
 * isEmpty: kembalikan 1 jika stack kosong, 0 jika tidak.
 * isFull : kembalikan 1 jika stack penuh, 0 jika tidak.
 *
 * Hint:
 *   - Kosong  → top == -1
 *   - Penuh   → top == KAPASITAS - 1
 * ============================================================ */

int isEmpty(StackArray *s) {
    // TODO: kembalikan 1 jika kosong, 0 jika tidak
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}

int isFull(StackArray *s) {
    // TODO: kembalikan 1 jika penuh, 0 jika tidak
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Push
 *
 * Masukkan nilai x ke atas stack.
 * Jika stack penuh, cetak "Error: stack penuh!" dan return.
 *
 * Langkah:
 *   1. Cek isFull — jika ya, cetak pesan dan return.
 *   2. Increment top.
 *   3. Simpan x di data[top].
 * ============================================================ */

void push(StackArray *s, int x) {
    // TODO: implementasikan push
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 4 — Pop
 *
 * Keluarkan dan kembalikan elemen teratas stack.
 * Jika stack kosong, cetak "Error: stack kosong!" dan kembalikan -1.
 *
 * Langkah:
 *   1. Cek isEmpty — jika ya, cetak pesan dan return -1.
 *   2. Simpan data[top] ke variabel sementara.
 *   3. Decrement top.
 *   4. Kembalikan nilai yang disimpan.
 * ============================================================ */

int pop(StackArray *s) {
    // TODO: implementasikan pop
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 5 — Peek
 *
 * Baca elemen teratas TANPA mengeluarkannya.
 * Jika stack kosong, cetak "Error: stack kosong!" dan kembalikan -1.
 *
 * Hint: sama dengan pop, tapi TANPA decrement top.
 * ============================================================ */

int peek(StackArray *s) {
    // TODO: implementasikan peek
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 6 — Tampilkan Isi Stack
 *
 * Cetak semua elemen dari TOP ke BOTTOM dalam format:
 *   Stack (top → bottom): 10 20 30
 *
 * Jika kosong, cetak:
 *   Stack (top → bottom): (kosong)
 *
 * Hint: loop dari indeks top ke 0 (menurun).
 * ============================================================ */

void tampilkan(StackArray *s) {
    // TODO: implementasikan tampilkan
    // Tulis kodemu di sini

}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * Jalankan dan pastikan semua output sesuai komentar.
 * ============================================================ */

int main() {
    StackArray s;
    init(&s);

    printf("=== Uji Init & isEmpty ===\n");
    printf("isEmpty setelah init: %d (harusnya 1)\n\n", isEmpty(&s));

    printf("=== Uji Push ===\n");
    push(&s, 30);
    push(&s, 20);
    push(&s, 10);
    tampilkan(&s);   /* Stack (top → bottom): 10 20 30 */

    printf("\n=== Uji Peek ===\n");
    printf("Peek: %d (harusnya 10)\n", peek(&s));
    tampilkan(&s);   /* stack tidak berubah: 10 20 30 */

    printf("\n=== Uji Pop ===\n");
    printf("Pop: %d (harusnya 10)\n", pop(&s));
    printf("Pop: %d (harusnya 20)\n", pop(&s));
    tampilkan(&s);   /* Stack (top → bottom): 30 */

    printf("\n=== Uji isFull ===\n");
    /* isi sampai penuh */
    push(&s, 1); push(&s, 2); push(&s, 3);
    push(&s, 4); push(&s, 5); push(&s, 6);
    push(&s, 7);   /* stack sekarang penuh (KAPASITAS = 8) */
    printf("isFull: %d (harusnya 1)\n", isFull(&s));
    push(&s, 99);  /* harus cetak: Error: stack penuh! */

    printf("\n=== Uji Pop pada Stack Kosong ===\n");
    /* kosongkan stack dulu */
    StackArray s2;
    init(&s2);
    pop(&s2);      /* harus cetak: Error: stack kosong! */
    peek(&s2);     /* harus cetak: Error: stack kosong! */

    printf("\n=== Uji Stack Kosong Setelah Pop Semua ===\n");
    StackArray s3;
    init(&s3);
    push(&s3, 5);
    pop(&s3);
    printf("isEmpty setelah pop semua: %d (harusnya 1)\n", isEmpty(&s3));
    tampilkan(&s3);   /* Stack (top → bottom): (kosong) */

    return 0;
}
