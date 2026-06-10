/*
 * Pertemuan 8 — Task B: Stack Linked List & Cek Kurung Seimbang
 * Topik   : Stack (Array & Linked List)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 08_Task_B.c -o 08_Task_B
 *   - Jalankan: ./08_Task_B  (Linux/Mac)  atau  08_Task_B.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ============================================================
 * Definisi Struct — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

typedef struct Node {
    char data;          /* stack ini menyimpan karakter */
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} StackLL;


/* ============================================================
 * SOAL 1 — Inisialisasi Stack Linked List
 *
 * Implementasikan init_ll() agar stack siap dipakai.
 * Hint: stack kosong → top == NULL
 * ============================================================ */

void init_ll(StackLL *s) {
    // TODO: set top ke NULL
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 2 — isEmpty untuk Stack Linked List
 *
 * Kembalikan 1 jika stack kosong (top == NULL), 0 jika tidak.
 * ============================================================ */

int isEmpty_ll(StackLL *s) {
    // TODO: cek apakah top NULL
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Push untuk Stack Linked List
 *
 * Masukkan karakter c ke atas stack dengan membuat node baru.
 *
 * Langkah:
 *   1. Alokasikan node baru dengan malloc.
 *   2. Isi data node dengan c.
 *   3. Set next node baru ke top saat ini.
 *   4. Set top ke node baru.
 *
 * Jika malloc gagal, cetak "Error: malloc gagal!" dan return.
 * ============================================================ */

void push_ll(StackLL *s, char c) {
    // TODO: implementasikan push untuk linked list
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 4 — Pop untuk Stack Linked List
 *
 * Keluarkan dan kembalikan karakter teratas.
 * Jika kosong, cetak "Error: stack kosong!" dan kembalikan '\0'.
 *
 * Langkah:
 *   1. Cek isEmpty_ll.
 *   2. Simpan node top ke pointer sementara.
 *   3. Simpan data-nya.
 *   4. Geser top ke node berikutnya.
 *   5. Free node sementara.
 *   6. Kembalikan data.
 * ============================================================ */

char pop_ll(StackLL *s) {
    // TODO: implementasikan pop untuk linked list
    // Tulis kodemu di sini

    return '\0';   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 5 — Peek untuk Stack Linked List
 *
 * Baca karakter teratas TANPA mengeluarkannya.
 * Jika kosong, kembalikan '\0'.
 * ============================================================ */

char peek_ll(StackLL *s) {
    // TODO: implementasikan peek
    // Tulis kodemu di sini

    return '\0';   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 6 — Bebaskan Seluruh Stack
 *
 * Pop semua node yang masih ada di stack (ini sekaligus free).
 * Setelah fungsi selesai, top harus NULL.
 *
 * Hint: gunakan loop dengan pop_ll sampai isEmpty_ll.
 * ============================================================ */

void bebaskan_ll(StackLL *s) {
    // TODO: bebaskan semua node yang masih ada
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 7 — Cek Tanda Kurung Seimbang
 *
 * Periksa apakah pasangan kurung (), [], {} pada string ekspresi
 * seimbang. Gunakan StackLL yang sudah kamu implementasikan.
 *
 * Kembalikan 1 jika seimbang, 0 jika tidak.
 *
 * Algoritma:
 *   Untuk setiap karakter c dalam ekspresi:
 *     - Jika c adalah kurung buka: push ke stack.
 *     - Jika c adalah kurung tutup:
 *         a. Jika stack kosong → return 0 (tutup tanpa buka).
 *         b. Pop dari stack → dapat karakter buka.
 *         c. Jika buka tidak cocok dengan c → return 0.
 *   Setelah loop: return 1 jika stack kosong, 0 jika tidak.
 *
 * Pasangan yang valid:
 *   ')' cocok dengan '('
 *   ']' cocok dengan '['
 *   '}' cocok dengan '{'
 *
 * Hint: buat fungsi bantu kecil:
 *   char pasangan(char tutup) { ... }
 * yang mengembalikan kurung buka yang sesuai.
 * ============================================================ */

/* TODO: implementasikan fungsi pasangan (boleh di luar cek_seimbang) */
/* Tulis kodemu di sini */


int cek_seimbang(const char *ekspresi) {
    // TODO: implementasikan cek_seimbang menggunakan StackLL
    // Ingat: gunakan init_ll, push_ll, pop_ll, isEmpty_ll, bebaskan_ll
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

int main() {
    /* --- Bagian 1: Uji Stack Linked List --- */
    printf("=== Uji Stack Linked List ===\n");

    StackLL s;
    init_ll(&s);

    printf("isEmpty setelah init: %d (harusnya 1)\n", isEmpty_ll(&s));

    push_ll(&s, 'A');
    push_ll(&s, 'B');
    push_ll(&s, 'C');

    printf("Peek: %c (harusnya C)\n", peek_ll(&s));
    printf("Pop : %c (harusnya C)\n", pop_ll(&s));
    printf("Pop : %c (harusnya B)\n", pop_ll(&s));
    printf("isEmpty setelah 2 pop: %d (harusnya 0)\n", isEmpty_ll(&s));
    printf("Pop : %c (harusnya A)\n", pop_ll(&s));
    printf("isEmpty setelah semua pop: %d (harusnya 1)\n\n", isEmpty_ll(&s));

    pop_ll(&s);   /* harus cetak: Error: stack kosong! */

    bebaskan_ll(&s);

    /* --- Bagian 2: Uji Cek Kurung Seimbang --- */
    printf("\n=== Uji Cek Kurung Seimbang ===\n");

    const char *uji[] = {
        "(a + b) * (c - d)",     /* seimbang */
        "{[a + b] * (c)}",       /* seimbang */
        "((()))",                /* seimbang */
        "(a + [b * c)",          /* tidak — ) tidak cocok dengan [ */
        "(a + b",                /* tidak — ada yang tidak ditutup */
        "a + b)",                /* tidak — tutup tanpa buka */
        "{[()]}"                 /* seimbang */
    };
    int n = 7;

    for (int i = 0; i < n; i++) {
        printf("%-30s → %s\n", uji[i],
               cek_seimbang(uji[i]) ? "Seimbang ✓" : "Tidak seimbang ✗");
    }

    return 0;
}
