/*
 * Pertemuan 6 — Task A: Definisi Node, Membuat Node & Traverse
 * Topik   : Linked List (Single)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 06_Task_A.c -o 06_Task_A
 *   - Jalankan: ./06_Task_A  (Linux/Mac)  atau  06_Task_A.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>


/* ============================================================
 * BAGIAN A — Definisi Struct Node
 *
 * Lengkapi definisi typedef struct Node.
 * Setiap node menyimpan:
 *   - data  : satu bilangan bulat
 *   - next  : pointer ke node berikutnya (bertipe Node *)
 * ============================================================ */

typedef struct Node {
    ____ data;              // (A1) tipe data untuk bilangan bulat
    struct Node *____;      // (A2) nama pointer ke node berikutnya
} Node;


/* ============================================================
 * BAGIAN B — Membuat Node Baru
 *
 * Lengkapi fungsi buat_node sehingga:
 *   1. Mengalokasikan memori untuk satu Node baru
 *   2. Mengisi anggota data dengan parameter yang diterima
 *   3. Mengisi anggota next dengan NULL (belum disambungkan)
 *   4. Mengembalikan pointer ke node yang baru dibuat
 * ============================================================ */

Node *buat_node(int data) {
    /* (B1) alokasikan memori sebesar satu Node */
    Node *node_baru = (Node *) malloc(____);

    if (node_baru == NULL) {
        printf("Error: alokasi memori gagal!\n");
        exit(1);
    }

    node_baru->____ = data;    // (B2) isi anggota data
    node_baru->____ = NULL;    // (B3) next belum menunjuk ke mana-mana

    return ____;               // (B4) kembalikan pointer ke node baru
}


/* ============================================================
 * BAGIAN C — Menyambung Node Secara Manual
 *
 * Lengkapi kode di bagian_C agar membentuk rantai:
 *   10 -> 20 -> 30 -> NULL
 * lalu set head ke node pertama.
 *
 * Output yang diharapkan:
 *   head->data       : 10
 *   head->next->data : 20
 * ============================================================ */

void bagian_C() {
    Node *head = NULL;

    Node *n1 = buat_node(10);
    Node *n2 = buat_node(20);
    Node *n3 = buat_node(30);

    /* (C1) sambungkan n1 ke n2 */
    n1->____ = n2;

    /* (C2) sambungkan n2 ke n3 */
    ____->next = n3;

    /* n3->next sudah NULL dari buat_node */

    /* (C3) set head ke node pertama */
    head = ____;

    printf("=== Bagian C: Menyambung Node ===\n");
    printf("head->data       : %d\n", head->data);
    printf("head->next->data : %d\n", head->next->data);   /* node ke-2 */

    /* bersihkan memori — sudah disediakan, jangan ubah */
    free(n1); free(n2); free(n3);
}


/* ============================================================
 * BAGIAN D — Traverse: Menampilkan Seluruh List
 *
 * Lengkapi fungsi tampilkan_list yang menelusuri list
 * dari head sampai NULL dan mencetak setiap data.
 *
 * Format output: List: 10 -> 20 -> 30
 * (tanpa " -> " di akhir elemen terakhir)
 * ============================================================ */

void tampilkan_list(Node *head) {
    /* (D1) buat pointer sementara — jangan pakai head langsung */
    Node *saat_ini = ____;

    printf("List: ");

    /* (D2) loop selama saat_ini belum NULL */
    while (saat_ini ____ NULL) {
        printf("%d", saat_ini->____);   // (D3) cetak data node saat ini

        /* cetak " -> " hanya jika masih ada node berikutnya */
        if (saat_ini->next != NULL) {
            printf(" -> ");
        }

        /* (D4) maju ke node berikutnya */
        saat_ini = saat_ini->____;
    }

    printf("\n");
}


/* ============================================================
 * BAGIAN E — Menghitung Panjang List
 *
 * Lengkapi fungsi panjang_list yang mengembalikan jumlah
 * node dalam list.
 *
 * Contoh: list [10 -> 20 -> 30] → panjang = 3
 *         list kosong (head = NULL) → panjang = 0
 * ============================================================ */

int panjang_list(Node *head) {
    int hitung = 0;
    Node *saat_ini = head;

    while (saat_ini != NULL) {
        /* (E1) tambahkan 1 ke hitung setiap kali melewati satu node */
        ____;

        saat_ini = saat_ini->next;
    }

    return ____;   // (E2) kembalikan hasil hitungan
}


/* ============================================================
 * BAGIAN F — Menggunakan Semua Fungsi Bersama
 *
 * Lengkapi bagian_F sehingga:
 *   1. Membuat 4 node dengan data: 5, 10, 15, 20
 *   2. Menyambung keempatnya (5 -> 10 -> 15 -> 20 -> NULL)
 *   3. Menampilkan list menggunakan tampilkan_list
 *   4. Mencetak panjang list menggunakan panjang_list
 *
 * Output yang diharapkan:
 *   === Bagian F: Menggunakan Semua Fungsi ===
 *   List: 5 -> 10 -> 15 -> 20
 *   Panjang list: 4
 * ============================================================ */

void bagian_F() {
    /* (F1) buat 4 node */
    Node *n1 = buat_node(____);    // data = 5
    Node *n2 = buat_node(____);    // data = 10
    Node *n3 = buat_node(15);
    Node *n4 = buat_node(20);

    /* (F2) sambungkan keempat node secara berurutan */
    n1->next = ____;    // n1 -> n2
    n2->next = n3;
    n3->next = ____;    // n3 -> n4
    /* n4->next sudah NULL */

    Node *head = n1;

    printf("=== Bagian F: Menggunakan Semua Fungsi ===\n");

    /* (F3) panggil tampilkan_list */
    ____(head);

    /* (F4) panggil panjang_list dan cetak hasilnya */
    printf("Panjang list: %d\n", ____(head));

    /* bersihkan memori */
    free(n1); free(n2); free(n3); free(n4);
}


/* ============================================================
 * main
 * ============================================================ */

int main() {
    bagian_C();
    bagian_F();
    return 0;
}
