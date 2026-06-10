/*
 * Pertemuan 6 — Task B: Insert (Depan, Belakang, Posisi Tertentu)
 * Topik   : Linked List (Single)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 06_Task_B.c -o 06_Task_B
 *   - Jalankan: ./06_Task_B  (Linux/Mac)  atau  06_Task_B.exe  (Windows)
 *
 * Fungsi buat_node dan tampilkan_list sudah disediakan lengkap.
 * Fokus pada fungsi-fungsi insert di bawahnya.
 */

#include <stdio.h>
#include <stdlib.h>


/* ============================================================
 * Definisi Node & fungsi bantu — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *buat_node(int data) {
    Node *node_baru = (Node *) malloc(sizeof(Node));
    if (node_baru == NULL) { printf("Error: malloc gagal!\n"); exit(1); }
    node_baru->data = data;
    node_baru->next = NULL;
    return node_baru;
}

void tampilkan_list(Node *head) {
    Node *saat_ini = head;
    printf("List: ");
    if (saat_ini == NULL) { printf("(kosong)\n"); return; }
    while (saat_ini != NULL) {
        printf("%d", saat_ini->data);
        if (saat_ini->next != NULL) printf(" -> ");
        saat_ini = saat_ini->next;
    }
    printf("\n");
}


/* ============================================================
 * BAGIAN A — Insert di Depan (Head)
 *
 * Lengkapi insert_depan sehingga node baru menjadi head baru.
 *
 * Langkah:
 *   1. Buat node baru
 *   2. Sambungkan next node baru ke head saat ini
 *   3. Pindahkan head ke node baru
 *
 * Sebelum: head ──► [20] ──► [30] ──► NULL
 * Sesudah: head ──► [10] ──► [20] ──► [30] ──► NULL
 * ============================================================ */

/* (A1) Lengkapi tipe parameter — head harus double pointer agar bisa diubah */
void insert_depan(____ head, int data) {
    Node *node_baru = buat_node(data);

    /* (A2) sambungkan next node_baru ke head saat ini (*head) */
    node_baru->next = ____;

    /* (A3) pindahkan head ke node_baru */
    *head = ____;
}


/* ============================================================
 * BAGIAN B — Insert di Belakang (Tail)
 *
 * Lengkapi insert_belakang sehingga node baru ditambahkan
 * setelah node terakhir.
 *
 * Sebelum: head ──► [10] ──► [20] ──► NULL
 * Sesudah: head ──► [10] ──► [20] ──► [30] ──► NULL
 * ============================================================ */

void insert_belakang(Node **head, int data) {
    Node *node_baru = buat_node(data);

    /* (B1) kasus khusus: list kosong — node baru langsung jadi head */
    if (*head == ____) {
        *head = node_baru;
        return;
    }

    /* (B2) jalan ke node terakhir (yang next-nya NULL) */
    Node *saat_ini = *head;
    while (saat_ini->____ != NULL) {    // (B3) kondisi: selama bukan node terakhir
        saat_ini = saat_ini->next;
    }

    /* (B4) sambungkan next node terakhir ke node_baru */
    saat_ini->____ = node_baru;
}


/* ============================================================
 * BAGIAN C — Insert di Posisi Tertentu
 *
 * Lengkapi insert_posisi sehingga node baru disisipkan di
 * posisi ke-posisi (dimulai dari 0).
 *
 * Contoh: insert 99 di posisi 2 pada list [10 -> 20 -> 30]:
 *   Sesudah: [10 -> 20 -> 99 -> 30]
 *
 * Perhatikan URUTAN dua langkah penyambungan — jangan terbalik!
 * ============================================================ */

void insert_posisi(Node **head, int data, int posisi) {
    /* posisi 0 = insert di depan, pakai fungsi yang sudah ada */
    if (posisi == 0) {
        insert_depan(head, data);
        return;
    }

    Node *node_baru = buat_node(data);
    Node *saat_ini = *head;

    /* (C1) jalan ke node di posisi (posisi - 1) */
    for (int i = 0; i < ____; i++) {
        if (saat_ini == NULL) {
            printf("Posisi %d melebihi panjang list.\n", posisi);
            free(node_baru);
            return;
        }
        saat_ini = saat_ini->next;
    }

    /* (C2) sambungkan next node_baru ke node yang sekarang ada di posisi tersebut */
    node_baru->next = saat_ini->____;

    /* (C3) sambungkan next node sebelumnya (saat_ini) ke node_baru */
    saat_ini->____ = node_baru;
}


/* ============================================================
 * BAGIAN D — Uji Semua Fungsi Insert
 *
 * Lengkapi urutan pemanggilan fungsi di bawah sehingga
 * setiap perubahan list bisa diamati.
 *
 * Output yang diharapkan:
 *   === Bagian D: Uji Insert ===
 *   Awal       : List: (kosong)
 *   +belakang 10: List: 10
 *   +belakang 30: List: 10 -> 30
 *   +depan 5   : List: 5 -> 10 -> 30
 *   +posisi 1 (20): List: 5 -> 10 -> 20 -> 30
 *   +posisi 0 (1) : List: 1 -> 5 -> 10 -> 20 -> 30
 * ============================================================ */

void bagian_D() {
    Node *head = NULL;

    printf("=== Bagian D: Uji Insert ===\n");
    printf("Awal        : "); tampilkan_list(head);

    /* (D1) insert 10 di belakang */
    ____(____,  10);
    printf("+belakang 10: "); tampilkan_list(head);

    /* (D2) insert 30 di belakang */
    insert_belakang(&head, 30);
    printf("+belakang 30: "); tampilkan_list(head);

    /* (D3) insert 5 di depan */
    ____(____,  5);
    printf("+depan 5    : "); tampilkan_list(head);

    /* (D4) insert 20 di posisi 2 (antara 10 dan 30) */
    insert_posisi(&head, 20, ____);
    printf("+posisi 2 (20): "); tampilkan_list(head);

    /* (D5) insert 1 di posisi 0 (paling depan) */
    insert_posisi(&head, 1, 0);
    printf("+posisi 0 (1) : "); tampilkan_list(head);

    /* bersihkan memori — bebaskan semua node */
    Node *saat_ini = head;
    while (saat_ini != NULL) {
        Node *berikutnya = saat_ini->next;
        free(saat_ini);
        saat_ini = berikutnya;
    }
}


/* ============================================================
 * main
 * ============================================================ */

int main() {
    bagian_D();
    return 0;
}
