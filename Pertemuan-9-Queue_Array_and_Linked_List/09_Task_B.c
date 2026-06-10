/*
 * Pertemuan 9 — Task B: Queue Berbasis Linked List
 * Topik   : Queue (Array & Linked List)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 09_Task_B.c -o 09_Task_B
 *   - Jalankan: ./09_Task_B  (Linux/Mac)  atau  09_Task_B.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>


/* ============================================================
 * Definisi Struct — SUDAH LENGKAP, jangan ubah
 *
 * Queue Linked List menggunakan dua pointer:
 *   - head : menunjuk elemen terdepan (DEQUEUE dari sini)
 *   - tail  : menunjuk elemen terbelakang (ENQUEUE ke sini)
 *
 * Kedua operasi berjalan O(1) karena kita selalu punya tail.
 * ============================================================ */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;   /* front — elemen yang paling duluan masuk */
    Node *tail;   /* rear  — elemen yang paling belakangan masuk */
} QueueLL;


/* ============================================================
 * SOAL 1 — Inisialisasi Queue Linked List
 *
 * Implementasikan init_ll() agar queue siap dipakai (kosong).
 * Hint: queue kosong → head == NULL dan tail == NULL
 * ============================================================ */

void init_ll(QueueLL *q) {
    // TODO: set head dan tail ke NULL
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 2 — Cek Queue Kosong
 *
 * Kembalikan 1 jika queue kosong, 0 jika tidak.
 * Hint: kosong berarti head == NULL
 * ============================================================ */

int isEmpty_ll(QueueLL *q) {
    // TODO: cek apakah head NULL
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Enqueue (masukkan di bagian belakang / tail)
 *
 * Masukkan nilai x ke belakang queue.
 * Jika malloc gagal, cetak "Error: malloc gagal!" dan return.
 *
 * Langkah:
 *   1. Alokasikan node baru dengan malloc.
 *   2. Isi data dan set next ke NULL.
 *   3. Jika queue kosong (tail == NULL):
 *        - head dan tail sama-sama tunjuk ke node baru.
 *      Jika tidak:
 *        - tail->next = node baru  (sambungkan ke akhir)
 *        - tail = node baru        (pindahkan tail)
 *   4. (Tidak ada langkah 4 — itu saja!)
 *
 * Perhatian: JANGAN ubah head saat enqueue ke queue yang tidak kosong.
 * ============================================================ */

void enqueue_ll(QueueLL *q, int x) {
    // TODO: implementasikan enqueue di tail
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 4 — Dequeue (keluarkan dari bagian depan / head)
 *
 * Keluarkan dan kembalikan elemen terdepan.
 * Jika kosong, cetak "Error: queue kosong!" dan kembalikan -1.
 *
 * Langkah:
 *   1. Cek isEmpty_ll.
 *   2. Simpan pointer head ke variabel sementara (akan_dihapus).
 *   3. Simpan data-nya ke variabel nilai.
 *   4. Geser head ke node berikutnya: head = head->next
 *   5. Jika head sekarang NULL → tail juga harus NULL (queue jadi kosong).
 *   6. Free akan_dihapus.
 *   7. Kembalikan nilai.
 *
 * Perhatian: jangan lupa reset tail ke NULL saat queue jadi kosong!
 * ============================================================ */

int dequeue_ll(QueueLL *q) {
    // TODO: implementasikan dequeue dari head
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 5 — Lihat Depan (front peek)
 *
 * Kembalikan elemen terdepan TANPA mengeluarkannya.
 * Jika kosong, cetak "Error: queue kosong!" dan kembalikan -1.
 * ============================================================ */

int lihat_depan_ll(QueueLL *q) {
    // TODO: kembalikan data di head tanpa mengubah queue
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 6 — Bebaskan Seluruh Queue
 *
 * Hapus semua node yang masih ada di queue.
 * Setelah selesai, head dan tail harus NULL.
 *
 * Hint: gunakan loop dengan dequeue_ll sampai isEmpty_ll.
 * ============================================================ */

void bebaskan_ll(QueueLL *q) {
    // TODO: bebaskan semua node
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 7 — Tampilkan Isi Queue
 *
 * Cetak semua elemen dari head (depan) ke tail (belakang):
 *   Queue (depan → belakang): 10 20 30
 *
 * Jika kosong:
 *   Queue (depan → belakang): (kosong)
 *
 * Hint:
 *   - Gunakan pointer sementara (curr) mulai dari head.
 *   - Loop curr = curr->next sampai NULL.
 *   - JANGAN pindahkan head itu sendiri!
 * ============================================================ */

void tampilkan_ll(QueueLL *q) {
    // TODO: cetak semua elemen menggunakan pointer sementara
    // Tulis kodemu di sini

}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * Jalankan dan pastikan semua output sesuai komentar.
 * ============================================================ */

int main() {
    QueueLL q;
    init_ll(&q);

    printf("=== Uji Init & isEmpty ===\n");
    printf("isEmpty setelah init: %d (harusnya 1)\n\n", isEmpty_ll(&q));

    printf("=== Uji Enqueue ===\n");
    enqueue_ll(&q, 10);
    enqueue_ll(&q, 20);
    enqueue_ll(&q, 30);
    tampilkan_ll(&q);   /* Queue (depan → belakang): 10 20 30 */

    printf("\n=== Uji Lihat Depan ===\n");
    printf("Depan: %d (harusnya 10)\n", lihat_depan_ll(&q));
    tampilkan_ll(&q);   /* tidak berubah: 10 20 30 */

    printf("\n=== Uji Dequeue ===\n");
    printf("Dequeue: %d (harusnya 10)\n", dequeue_ll(&q));
    printf("Dequeue: %d (harusnya 20)\n", dequeue_ll(&q));
    tampilkan_ll(&q);   /* Queue (depan → belakang): 30 */
    printf("Depan: %d (harusnya 30)\n", lihat_depan_ll(&q));

    printf("\n=== Uji Enqueue Lanjutan (tidak ada batas kapasitas) ===\n");
    enqueue_ll(&q, 40);
    enqueue_ll(&q, 50);
    enqueue_ll(&q, 60);
    enqueue_ll(&q, 70);
    enqueue_ll(&q, 80);   /* linked list tidak punya batas tetap */
    tampilkan_ll(&q);     /* Queue (depan → belakang): 30 40 50 60 70 80 */

    printf("\n=== Uji Dequeue sampai Kosong ===\n");
    printf("Dequeue: %d\n", dequeue_ll(&q));   /* 30 */
    printf("Dequeue: %d\n", dequeue_ll(&q));   /* 40 */
    printf("Dequeue: %d\n", dequeue_ll(&q));   /* 50 */
    printf("Dequeue: %d\n", dequeue_ll(&q));   /* 60 */
    printf("Dequeue: %d\n", dequeue_ll(&q));   /* 70 */
    printf("Dequeue: %d\n", dequeue_ll(&q));   /* 80 */
    printf("isEmpty: %d (harusnya 1)\n", isEmpty_ll(&q));
    tampilkan_ll(&q);                          /* Queue (depan → belakang): (kosong) */

    printf("\n=== Uji Dequeue pada Queue Kosong ===\n");
    dequeue_ll(&q);      /* harus cetak: Error: queue kosong! */
    lihat_depan_ll(&q);  /* harus cetak: Error: queue kosong! */

    printf("\n=== Uji Enqueue Setelah Kosong (head & tail harus reset) ===\n");
    enqueue_ll(&q, 99);
    tampilkan_ll(&q);    /* Queue (depan → belakang): 99 */
    printf("Depan: %d (harusnya 99)\n", lihat_depan_ll(&q));

    bebaskan_ll(&q);
    printf("isEmpty setelah bebaskan: %d (harusnya 1)\n", isEmpty_ll(&q));

    return 0;
}
