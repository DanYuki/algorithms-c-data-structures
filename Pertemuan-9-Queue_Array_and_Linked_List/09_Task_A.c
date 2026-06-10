/*
 * Pertemuan 9 — Task A: Queue Berbasis Array (Circular Queue)
 * Topik   : Queue (Array & Linked List)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 09_Task_A.c -o 09_Task_A
 *   - Jalankan: ./09_Task_A  (Linux/Mac)  atau  09_Task_A.exe  (Windows)
 */

#include <stdio.h>

#define KAPASITAS 5


/* ============================================================
 * Definisi Struct — SUDAH LENGKAP, jangan ubah
 *
 * Queue Array ini menggunakan:
 *   - front  : indeks elemen terdepan
 *   - rear   : indeks elemen terbelakang
 *   - ukuran : jumlah elemen saat ini (untuk membedakan penuh vs kosong)
 * ============================================================ */

typedef struct {
    int data[KAPASITAS];
    int front;
    int rear;
    int ukuran;
} QueueArray;


/* ============================================================
 * SOAL 1 — Inisialisasi Queue
 *
 * Implementasikan init() agar queue siap dipakai (kosong).
 *
 * Hint:
 *   - front  = 0
 *   - rear   = KAPASITAS - 1   (posisi sebelum slot pertama, siap maju)
 *   - ukuran = 0
 * ============================================================ */

void init(QueueArray *q) {
    // TODO: inisialisasi front, rear, dan ukuran
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 2 — Cek Queue Kosong & Penuh
 *
 * isEmpty: kembalikan 1 jika queue kosong, 0 jika tidak.
 * isFull : kembalikan 1 jika queue penuh, 0 jika tidak.
 *
 * Hint: gunakan variabel ukuran, bukan posisi front/rear.
 *   - Kosong → ukuran == 0
 *   - Penuh  → ukuran == KAPASITAS
 * ============================================================ */

int isEmpty(QueueArray *q) {
    // TODO: kembalikan 1 jika kosong
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}

int isFull(QueueArray *q) {
    // TODO: kembalikan 1 jika penuh
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Enqueue
 *
 * Masukkan nilai x ke bagian belakang queue.
 * Jika penuh, cetak "Error: queue penuh!" dan return.
 *
 * Langkah:
 *   1. Cek isFull — jika ya, cetak pesan dan return.
 *   2. Geser rear ke depan secara MELINGKAR:
 *        rear = (rear + 1) % KAPASITAS
 *   3. Simpan x di data[rear].
 *   4. Tambah ukuran.
 *
 * Kunci: gunakan modulo agar rear tidak keluar dari batas array.
 * ============================================================ */

void enqueue(QueueArray *q, int x) {
    // TODO: implementasikan enqueue dengan aritmetika modular
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 4 — Dequeue
 *
 * Keluarkan dan kembalikan elemen terdepan queue.
 * Jika kosong, cetak "Error: queue kosong!" dan kembalikan -1.
 *
 * Langkah:
 *   1. Cek isEmpty — jika ya, cetak pesan dan return -1.
 *   2. Simpan data[front] ke variabel sementara.
 *   3. Geser front ke depan secara MELINGKAR:
 *        front = (front + 1) % KAPASITAS
 *   4. Kurangi ukuran.
 *   5. Kembalikan nilai yang disimpan.
 * ============================================================ */

int dequeue(QueueArray *q) {
    // TODO: implementasikan dequeue dengan aritmetika modular
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 5 — Lihat Depan (front peek)
 *
 * Kembalikan elemen terdepan TANPA mengeluarkannya.
 * Jika kosong, cetak "Error: queue kosong!" dan kembalikan -1.
 *
 * Hint: sama seperti dequeue, tapi TANPA menggeser front
 *       dan TANPA mengubah ukuran.
 * ============================================================ */

int lihat_depan(QueueArray *q) {
    // TODO: kembalikan elemen terdepan tanpa mengubah queue
    // Tulis kodemu di sini

    return -1;   /* ganti/pertahankan sesuai implementasimu */
}


/* ============================================================
 * SOAL 6 — Tampilkan Isi Queue
 *
 * Cetak semua elemen dari depan (front) ke belakang (rear):
 *   Queue (depan → belakang): 10 20 30
 *
 * Jika kosong:
 *   Queue (depan → belakang): (kosong)
 *
 * Hint:
 *   - Gunakan loop sebanyak ukuran kali.
 *   - Indeks setiap elemen: (front + i) % KAPASITAS
 *
 * Jangan ubah front atau rear — ini hanya tampilan.
 * ============================================================ */

void tampilkan(QueueArray *q) {
    // TODO: cetak semua elemen dari depan ke belakang
    // Tulis kodemu di sini

}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * Jalankan dan pastikan semua output sesuai komentar.
 * ============================================================ */

int main() {
    QueueArray q;
    init(&q);

    printf("=== Uji Init & isEmpty ===\n");
    printf("isEmpty setelah init : %d (harusnya 1)\n\n", isEmpty(&q));

    printf("=== Uji Enqueue ===\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    tampilkan(&q);   /* Queue (depan → belakang): 10 20 30 */

    printf("\n=== Uji Lihat Depan ===\n");
    printf("Depan: %d (harusnya 10)\n", lihat_depan(&q));
    tampilkan(&q);   /* queue tidak berubah: 10 20 30 */

    printf("\n=== Uji Dequeue ===\n");
    printf("Dequeue: %d (harusnya 10)\n", dequeue(&q));
    printf("Dequeue: %d (harusnya 20)\n", dequeue(&q));
    tampilkan(&q);   /* Queue (depan → belakang): 30 */
    printf("Depan: %d (harusnya 30)\n", lihat_depan(&q));

    printf("\n=== Uji Circular: Enqueue setelah beberapa Dequeue ===\n");
    /*
     * Situasi saat ini: front sudah bergeser ke kanan.
     * Slot lama di kiri front harus bisa dipakai kembali.
     */
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);   /* slot yang sudah di-dequeue dipakai lagi */
    tampilkan(&q);     /* Queue (depan → belakang): 30 40 50 60 70 */

    printf("\n=== Uji isFull & Enqueue saat Penuh ===\n");
    printf("isFull: %d (harusnya 1)\n", isFull(&q));
    enqueue(&q, 99);   /* harus cetak: Error: queue penuh! */

    printf("\n=== Uji Dequeue sampai Kosong ===\n");
    printf("Dequeue: %d\n", dequeue(&q));   /* 30 */
    printf("Dequeue: %d\n", dequeue(&q));   /* 40 */
    printf("Dequeue: %d\n", dequeue(&q));   /* 50 */
    printf("Dequeue: %d\n", dequeue(&q));   /* 60 */
    printf("Dequeue: %d\n", dequeue(&q));   /* 70 */
    printf("isEmpty: %d (harusnya 1)\n", isEmpty(&q));
    tampilkan(&q);                           /* Queue (depan → belakang): (kosong) */
    dequeue(&q);                             /* harus cetak: Error: queue kosong! */

    return 0;
}
