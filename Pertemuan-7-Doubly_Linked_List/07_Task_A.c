/*
 * Pertemuan 7 — Task A: Definisi Node, Membuat Node & Traverse Dua Arah
 * Topik   : Doubly Linked List
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 07_Task_A.c -o 07_Task_A
 *   - Jalankan: ./07_Task_A  (Linux/Mac)  atau  07_Task_A.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>


/* ============================================================
 * BAGIAN A — Definisi Node Doubly Linked List
 *
 * Lengkapi typedef struct Node untuk doubly linked list.
 * Setiap node harus memiliki:
 *   - data  : bilangan bulat
 *   - prev  : pointer ke node SEBELUMNYA
 *   - next  : pointer ke node BERIKUTNYA
 * ============================================================ */

typedef struct Node {
    int data;
    struct Node *____;   // (A1) pointer ke node sebelumnya
    struct Node *____;   // (A2) pointer ke node berikutnya
} Node;


/* ============================================================
 * BAGIAN B — Membuat Node Baru
 *
 * Lengkapi buat_node sehingga:
 *   1. Mengalokasikan memori untuk satu Node
 *   2. Mengisi data
 *   3. Mengisi KEDUA pointer (prev dan next) dengan NULL
 *   4. Mengembalikan pointer ke node baru
 * ============================================================ */

Node *buat_node(int data) {
    Node *node_baru = (Node *) malloc(____);   // (B1) ukuran alokasi

    if (node_baru == NULL) {
        printf("Error: malloc gagal!\n");
        exit(1);
    }

    node_baru->data = ____;    // (B2) isi data
    node_baru->prev = ____;    // (B3) belum ada tetangga kiri
    node_baru->____ = NULL;    // (B4) belum ada tetangga kanan

    return node_baru;
}


/* ============================================================
 * BAGIAN C — Traverse Maju (head → tail)
 *
 * Lengkapi tampilkan_maju sehingga mencetak semua data
 * dari head sampai NULL.
 *
 * Format: Maju : 10 <-> 20 <-> 30
 *         (tanpa " <-> " setelah elemen terakhir)
 * ============================================================ */

void tampilkan_maju(Node *head) {
    Node *saat_ini = ____;   // (C1) mulai dari head

    printf("Maju  : ");

    if (saat_ini == NULL) {
        printf("(kosong)\n");
        return;
    }

    while (saat_ini != NULL) {
        printf("%d", saat_ini->____);   // (C2) cetak data node saat ini

        if (saat_ini->____ != NULL) {   // (C3) cek apakah masih ada node berikutnya
            printf(" <-> ");
        }

        saat_ini = saat_ini->____;      // (C4) maju ke node berikutnya
    }
    printf("\n");
}


/* ============================================================
 * BAGIAN D — Traverse Mundur (tail → head)
 *
 * Lengkapi tampilkan_mundur sehingga mencetak semua data
 * dari tail sampai NULL menggunakan pointer prev.
 *
 * Format: Mundur: 30 <-> 20 <-> 10
 * ============================================================ */

void tampilkan_mundur(Node *tail) {
    Node *saat_ini = ____;   // (D1) mulai dari tail

    printf("Mundur: ");

    if (saat_ini == NULL) {
        printf("(kosong)\n");
        return;
    }

    while (saat_ini != NULL) {
        printf("%d", saat_ini->data);

        if (saat_ini->____ != NULL) {   // (D2) cek apakah masih ada node sebelumnya
            printf(" <-> ");
        }

        saat_ini = saat_ini->____;      // (D3) mundur ke node sebelumnya
    }
    printf("\n");
}


/* ============================================================
 * BAGIAN E — Menyambung Node Secara Manual & Uji Traverse
 *
 * Lengkapi kode di bagian_E untuk membentuk doubly LL:
 *   head ──► [10 <-> 20 <-> 30] ◄── tail
 *
 * Semua pointer prev dan next harus terhubung dengan benar.
 *
 * Output yang diharapkan:
 *   === Bagian E: Traverse Dua Arah ===
 *   Maju  : 10 <-> 20 <-> 30
 *   Mundur: 30 <-> 20 <-> 10
 * ============================================================ */

void bagian_E() {
    Node *n1 = buat_node(10);
    Node *n2 = buat_node(20);
    Node *n3 = buat_node(30);

    /* sambungkan n1 <-> n2 */
    n1->next = ____;      // (E1) n1 menunjuk ke n2
    n2->____ = n1;        // (E2) n2 menunjuk balik ke n1

    /* sambungkan n2 <-> n3 */
    n2->next = ____;      // (E3) n2 menunjuk ke n3
    n3->____ = n2;        // (E4) n3 menunjuk balik ke n2

    Node *head = ____;    // (E5) head adalah node pertama
    Node *tail = ____;    // (E6) tail adalah node terakhir

    printf("=== Bagian E: Traverse Dua Arah ===\n");
    tampilkan_maju(head);
    tampilkan_mundur(tail);

    /* verifikasi konsistensi pointer */
    printf("\nVerifikasi:\n");
    printf("head->prev (harus NULL) : %s\n", head->prev == NULL ? "NULL ✓" : "BUKAN NULL ✗");
    printf("tail->next (harus NULL) : %s\n", tail->next == NULL ? "NULL ✓" : "BUKAN NULL ✗");
    printf("n1->next->prev == n1   : %s\n", n1->next->prev == n1 ? "Benar ✓" : "Salah ✗");
    printf("n3->prev->next == n3   : %s\n", n3->prev->next == n3 ? "Benar ✓" : "Salah ✗");

    free(n1); free(n2); free(n3);
}


/* ============================================================
 * BAGIAN F — Hitung Panjang List (Maju & Mundur)
 *
 * Lengkapi dua fungsi:
 *   - panjang_dari_head: hitung node dengan traversal maju
 *   - panjang_dari_tail: hitung node dengan traversal mundur
 * Keduanya harus menghasilkan angka yang sama.
 *
 * Gunakan list yang sudah dibuat di bagian_E sebagai referensi.
 * ============================================================ */

int panjang_dari_head(Node *head) {
    int hitung = 0;
    Node *saat_ini = head;
    while (saat_ini != NULL) {
        ____;                          // (F1) tambah 1 ke hitung
        saat_ini = saat_ini->next;
    }
    return ____;                       // (F2) kembalikan hitung
}

int panjang_dari_tail(Node *tail) {
    int hitung = 0;
    Node *saat_ini = tail;
    while (saat_ini != NULL) {
        hitung++;
        saat_ini = saat_ini->____;     // (F3) mundur menggunakan prev
    }
    return hitung;
}

void bagian_F() {
    Node *n1 = buat_node(5);
    Node *n2 = buat_node(10);
    Node *n3 = buat_node(15);
    Node *n4 = buat_node(20);

    n1->next = n2;  n2->prev = n1;
    n2->next = n3;  n3->prev = n2;
    n3->next = n4;  n4->prev = n3;

    Node *head = n1;
    Node *tail = n4;

    printf("\n=== Bagian F: Panjang List ===\n");
    tampilkan_maju(head);

    int p_head = panjang_dari_head(____);   // (F4) kirim head
    int p_tail = panjang_dari_tail(____);   // (F5) kirim tail

    printf("Panjang dari head : %d\n", p_head);
    printf("Panjang dari tail : %d\n", p_tail);
    printf("Konsisten         : %s\n", p_head == p_tail ? "Ya ✓" : "Tidak ✗");

    free(n1); free(n2); free(n3); free(n4);
}


/* ============================================================
 * main
 * ============================================================ */

int main() {
    bagian_E();
    bagian_F();
    return 0;
}
