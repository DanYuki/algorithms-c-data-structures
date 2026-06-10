/*
 * Pertemuan 7 — Task B: Insert (Depan, Belakang, Tengah)
 * Topik   : Doubly Linked List
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 07_Task_B.c -o 07_Task_B
 *   - Jalankan: ./07_Task_B  (Linux/Mac)  atau  07_Task_B.exe  (Windows)
 *
 * Node, buat_node, tampilkan_maju, tampilkan_mundur sudah
 * disediakan lengkap. Fokus pada fungsi-fungsi insert.
 */

#include <stdio.h>
#include <stdlib.h>


/* ============================================================
 * Definisi & fungsi bantu — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *buat_node(int data) {
    Node *n = (Node *) malloc(sizeof(Node));
    if (n == NULL) { printf("Error: malloc gagal!\n"); exit(1); }
    n->data = data; n->prev = NULL; n->next = NULL;
    return n;
}

void tampilkan_maju(Node *head) {
    Node *p = head;
    printf("Maju  : ");
    if (!p) { printf("(kosong)\n"); return; }
    while (p) { printf("%d", p->data); if (p->next) printf(" <-> "); p = p->next; }
    printf("\n");
}

void tampilkan_mundur(Node *tail) {
    Node *p = tail;
    printf("Mundur: ");
    if (!p) { printf("(kosong)\n"); return; }
    while (p) { printf("%d", p->data); if (p->prev) printf(" <-> "); p = p->prev; }
    printf("\n");
}

void bebaskan_list(Node **head, Node **tail) {
    Node *p = *head;
    while (p) { Node *next = p->next; free(p); p = next; }
    *head = NULL; *tail = NULL;
}


/* ============================================================
 * BAGIAN A — Insert di Depan
 *
 * Lengkapi insert_depan dengan 3 langkah utama:
 *   1. Sambungkan next node_baru ke head saat ini
 *   2. Perbarui prev head lama agar menunjuk ke node_baru
 *   3. Pindahkan head ke node_baru
 *
 * Jangan lupa tangani kasus list kosong (head == NULL)!
 *
 * Sebelum: head ──► [20 <-> 30] ◄── tail
 * Sesudah: head ──► [10 <-> 20 <-> 30] ◄── tail
 * ============================================================ */

void insert_depan(Node **head, Node **tail, int data) {
    Node *node_baru = buat_node(data);

    /* (A1) kasus list kosong — node baru jadi head sekaligus tail */
    if (*head == ____) {
        *head = node_baru;
        *tail = ____;
        return;
    }

    node_baru->____ = *head;     // (A2) next node_baru → head lama
    (*head)->____ = node_baru;   // (A3) prev head lama → node_baru
    *head = ____;                // (A4) pindahkan head ke node_baru
}


/* ============================================================
 * BAGIAN B — Insert di Belakang
 *
 * Langkah utama:
 *   1. Sambungkan prev node_baru ke tail saat ini
 *   2. Perbarui next tail lama agar menunjuk ke node_baru
 *   3. Pindahkan tail ke node_baru
 *
 * Sebelum: head ──► [10 <-> 20] ◄── tail
 * Sesudah: head ──► [10 <-> 20 <-> 30] ◄── tail
 * ============================================================ */

void insert_belakang(Node **head, Node **tail, int data) {
    Node *node_baru = buat_node(data);

    /* (B1) kasus list kosong */
    if (*tail == NULL) {
        *head = node_baru;
        *tail = node_baru;
        return;
    }

    node_baru->____ = *tail;     // (B2) prev node_baru → tail lama
    (*tail)->____ = node_baru;   // (B3) next tail lama → node_baru
    *tail = ____;                // (B4) pindahkan tail ke node_baru
}


/* ============================================================
 * BAGIAN C — Insert Setelah Node Tertentu
 *
 * Sisipkan node baru SETELAH node_sebelum.
 * Ada 4 sambungan yang harus diperbarui:
 *   Misal: A = node_sebelum, B = node_baru, C = node_setelah A
 *
 *   1. B.prev = A
 *   2. B.next = C
 *   3. A.next = B
 *   4. Jika C ada: C.prev = B
 *      Jika C tidak ada (A adalah tail): update *tail = B
 *
 * Sebelum: [10 <-> 30]
 * insert_setelah(node_10, 20)
 * Sesudah: [10 <-> 20 <-> 30]
 * ============================================================ */

void insert_setelah(Node **tail, Node *node_sebelum, int data) {
    if (node_sebelum == NULL) return;

    Node *node_baru  = buat_node(data);
    Node *node_sesud = node_sebelum->next;   /* simpan referensi ke C */

    node_baru->____ = node_sebelum;   // (C1) B.prev = A
    node_baru->____ = node_sesud;     // (C2) B.next = C
    node_sebelum->____ = node_baru;   // (C3) A.next = B

    if (node_sesud != NULL) {
        node_sesud->____ = node_baru; // (C4a) C.prev = B (jika C ada)
    } else {
        *tail = ____;                 // (C4b) B jadi tail baru (jika C tidak ada)
    }
}


/* ============================================================
 * BAGIAN D — Uji Semua Fungsi Insert
 *
 * Lengkapi pemanggilan fungsi sehingga menghasilkan output:
 *
 *   === Bagian D: Uji Insert ===
 *   Awal      : Maju  : (kosong)
 *   +blk 20   : Maju  : 20
 *   +blk 30   : Maju  : 20 <-> 30
 *   +depan 10 : Maju  : 10 <-> 20 <-> 30
 *   +stlh n1(15): Maju: 10 <-> 15 <-> 20 <-> 30
 *   Mundur    : Mundur: 30 <-> 20 <-> 15 <-> 10
 * ============================================================ */

void bagian_D() {
    Node *head = NULL, *tail = NULL;

    printf("=== Bagian D: Uji Insert ===\n");
    printf("Awal       : "); tampilkan_maju(head);

    /* (D1) insert 20 di belakang */
    insert_belakang(____, ____, 20);
    printf("+blk 20    : "); tampilkan_maju(head);

    /* (D2) insert 30 di belakang */
    ____(____,  ____, 30);
    printf("+blk 30    : "); tampilkan_maju(head);

    /* (D3) insert 10 di depan */
    insert_depan(____, ____, ____);
    printf("+depan 10  : "); tampilkan_maju(head);

    /* (D4) insert 15 setelah node pertama (head, yang berisi 10) */
    insert_setelah(____, ____, 15);   /* kirim &tail dan head (node setelah 10) */
    printf("+stlh 10(15): "); tampilkan_maju(head);

    printf("Mundur     : "); tampilkan_mundur(tail);

    bebaskan_list(&head, &tail);
}


/* ============================================================
 * main
 * ============================================================ */

int main() {
    bagian_D();
    return 0;
}
