/*
 * Pertemuan 4 — Task C: Memory Leak & Dangling Pointer
 * Topik   : Pointer & Dynamic Memory
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Task ini berbeda dari Task A & B:
 *   - Beberapa bagian berisi KODE YANG SALAH yang harus kamu PERBAIKI.
 *   - Beberapa bagian perlu dilengkapi seperti biasa.
 *   - Tujuan: melatih kemampuan membaca, menganalisis, dan memperbaiki
 *     bug terkait memory leak dan dangling pointer.
 *
 * Compile: gcc 04_Task_C.c -o 04_Task_C
 */

#include <stdio.h>
#include <stdlib.h>

/* ============================================================
 * BAGIAN A — Temukan & Perbaiki Memory Leak
 *
 * Kode di bawah ini mengandung memory leak.
 * Tandai dengan komentar baris mana yang bermasalah,
 * lalu perbaiki kodenya.
 *
 * Petunjuk: jalankan kode ini dan pikirkan —
 *   apakah setiap malloc/calloc berpasangan dengan free?
 * ============================================================ */

void bagian_A() {
    int n = 5, i;

    printf("=== Bagian A: Perbaiki Memory Leak ===\n");

    int *arr1 = (int *) malloc(n * sizeof(int));
    if (arr1 == NULL) { return; }

    for (i = 0; i < n; i++) {
        arr1[i] = i + 1;
    }

    printf("arr1: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // BUG: arr1 di-overwrite tanpa dibebaskan dulu — memori pertama bocor!
    arr1 = (int *) malloc(n * sizeof(int));  // <-- perbaiki di sini
    if (arr1 == NULL) { return; }

    for (i = 0; i < n; i++) {
        arr1[i] = (i + 1) * 10;
    }

    printf("arr1 (baru): ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    free(arr1);
    arr1 = NULL;

    // (A1) Apakah ada memory leak lain di fungsi ini?
    // Tulis analisismu di sini sebagai komentar:
    // ____
}


/* ============================================================
 * BAGIAN B — Temukan & Perbaiki Dangling Pointer
 *
 * Kode di bawah berisi dangling pointer yang berbahaya.
 * Identifikasi masalahnya dan perbaiki.
 * ============================================================ */

void bagian_B() {
    int *ptr = (int *) malloc(sizeof(int));
    if (ptr == NULL) { return; }

    *ptr = 42;
    printf("\n=== Bagian B: Perbaiki Dangling Pointer ===\n");
    printf("Nilai sebelum free: %d\n", *ptr);

    free(ptr);
    // BUG: ptr masih digunakan setelah free — dangling pointer!

    // (B1) Perbaiki: apa yang harus dilakukan setelah free(ptr)
    //      agar baris di bawah ini aman?
    ____   // tulis perbaikannya di sini

    // Akses ptr setelah diperbaiki — seharusnya tidak menyebabkan undefined behavior
    if (ptr != NULL) {
        printf("ptr masih valid — seharusnya tidak sampai sini.\n");
    } else {
        printf("ptr sudah NULL — aman.\n");
    }
}


/* ============================================================
 * BAGIAN C — Disiplin free dalam Kondisi Bercabang
 *
 * Kode di bawah mengalokasikan memori di dalam kondisi if.
 * Lengkapi bagian yang kosong agar tidak ada memory leak
 * di semua jalur eksekusi (baik kondisi if maupun else).
 *
 * Contoh output (input 1):
 *   Pilih mode (1=kecil, 2=besar): 1
 *   Menggunakan array kecil (3 elemen): 0 0 0
 *   Memori dibebaskan.
 *
 * Contoh output (input 2):
 *   Pilih mode (1=kecil, 2=besar): 2
 *   Menggunakan array besar (10 elemen): 0 0 0 0 0 0 0 0 0 0
 *   Memori dibebaskan.
 * ============================================================ */

void bagian_C() {
    int pilihan, i;
    int *arr = NULL;
    int ukuran = 0;

    printf("\n=== Bagian C: free di Semua Jalur ===\n");
    printf("Pilih mode (1=kecil, 2=besar): ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        ukuran = 3;
        arr = (int *) calloc(ukuran, sizeof(int));
    } else {
        ukuran = 10;
        arr = (int *) calloc(ukuran, sizeof(int));
    }

    // (C1) Cek NULL — berlaku untuk kedua jalur
    if (____ == NULL) {
        printf("Alokasi gagal!\n");
        return;
    }

    if (pilihan == 1) {
        printf("Menggunakan array kecil (%d elemen): ", ukuran);
    } else {
        printf("Menggunakan array besar (%d elemen): ", ukuran);
    }

    for (i = 0; i < ukuran; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // (C2) Bebaskan memori — harus dilakukan di semua jalur!
    ____; // free arr
    ____; // set NULL
    printf("Memori dibebaskan.\n");
}


/* ============================================================
 * BAGIAN D — Analisis Kode (Tanpa Menulis Kode)
 *
 * Baca kode di bawah dan jawab pertanyaan-pertanyaannya
 * dengan menulis jawabanmu di komentar.
 *
 * TIDAK PERLU mengubah kode fungsinya — cukup isi jawaban
 * di komentar bertanda (D1), (D2), (D3).
 * ============================================================ */

int* fungsi_misterius(int n) {
    int *hasil = (int *) malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        hasil[i] = i * i;
    }
    return hasil;
}

void bagian_D() {
    printf("\n=== Bagian D: Analisis ===\n");

    int *data = fungsi_misterius(4);

    // (D1) Apa isi array data setelah pemanggilan di atas?
    //      (tanpa menjalankan program — trace manual)
    // Jawaban: ____

    // (D2) Siapa yang bertanggung jawab membebaskan memori array ini —
    //      fungsi_misterius atau bagian_D? Mengapa?
    // Jawaban: ____

    // (D3) Tulis satu baris kode untuk membebaskan memori dengan benar:
    ____; // free
    ____; // set NULL

    printf("Analisis selesai.\n");
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
