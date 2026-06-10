/*
 * Pertemuan 6 — Task C: Delete Node & Bebaskan List
 * Topik   : Linked List (Single)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 06_Task_C.c -o 06_Task_C
 *   - Jalankan: ./06_Task_C  (Linux/Mac)  atau  06_Task_C.exe  (Windows)
 *
 * Fungsi buat_node, tampilkan_list, insert_belakang sudah
 * disediakan lengkap. Fokus pada fungsi-fungsi delete di bawah.
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

void insert_belakang(Node **head, int data) {
    Node *node_baru = buat_node(data);
    if (*head == NULL) { *head = node_baru; return; }
    Node *saat_ini = *head;
    while (saat_ini->next != NULL) saat_ini = saat_ini->next;
    saat_ini->next = node_baru;
}


/* ============================================================
 * BAGIAN A — Delete Node Berdasarkan Nilai
 *
 * Lengkapi delete_node sehingga menghapus NODE PERTAMA
 * yang nilainya sama dengan target, lalu membebaskan memorinya.
 *
 * Tangani tiga kasus:
 *   1. List kosong
 *   2. Node yang dihapus adalah head
 *   3. Node yang dihapus ada di tengah atau akhir
 *
 * Sebelum: [10] -> [20] -> [30]
 * delete(20)
 * Sesudah: [10] -> [30]
 * ============================================================ */

void delete_node(Node **head, int target) {
    /* (A1) kasus 1: list kosong */
    if (*head == ____) {
        printf("List kosong, tidak ada yang dihapus.\n");
        return;
    }

    /* (A2) kasus 2: target ada di head */
    if ((*head)->data == target) {
        Node *akan_dihapus = *head;

        /* (A3) geser head ke node berikutnya */
        *head = ____->next;

        /* (A4) bebaskan node yang dihapus */
        ____(akan_dihapus);
        return;
    }

    /* (A5) kasus 3: cari node SEBELUM target */
    Node *saat_ini = *head;
    while (saat_ini->next != NULL && saat_ini->next->data != ____) {
        saat_ini = saat_ini->next;
    }

    /* (A6) cek apakah target ditemukan */
    if (saat_ini->____ == NULL) {
        printf("Nilai %d tidak ditemukan.\n", target);
        return;
    }

    /* (A7) simpan pointer ke node yang akan dihapus */
    Node *akan_dihapus = saat_ini->____;

    /* (A8) hubungkan saat_ini langsung ke node SETELAH yang dihapus */
    saat_ini->next = akan_dihapus->____;

    /* (A9) bebaskan memori node yang dihapus */
    ____(akan_dihapus);
}


/* ============================================================
 * BAGIAN B — Bebaskan Seluruh List
 *
 * Lengkapi bebaskan_list yang menelusuri seluruh list,
 * membebaskan setiap node satu per satu, lalu set head ke NULL.
 *
 * Penting: simpan pointer ke node BERIKUTNYA sebelum free —
 * setelah free, isi node tidak valid lagi.
 * ============================================================ */

void bebaskan_list(Node **head) {
    Node *saat_ini = *head;

    while (saat_ini != NULL) {
        /* (B1) simpan referensi ke node berikutnya SEBELUM free */
        Node *berikutnya = saat_ini->____;

        /* (B2) bebaskan node saat ini */
        ____(saat_ini);

        /* (B3) pindah ke node yang sudah disimpan */
        saat_ini = ____;
    }

    /* (B4) set head ke NULL setelah semua node dibebaskan */
    *head = ____;
}


/* ============================================================
 * BAGIAN C — Uji delete_node
 *
 * Lengkapi urutan pemanggilan delete_node di bawah sehingga
 * bisa mengamati setiap perubahan list.
 *
 * Output yang diharapkan:
 *   === Bagian C: Uji Delete ===
 *   Awal       : List: 10 -> 20 -> 30 -> 40 -> 50
 *   -hapus 30  : List: 10 -> 20 -> 40 -> 50
 *   -hapus 10  : List: 20 -> 40 -> 50
 *   -hapus 50  : List: 20 -> 40
 *   -hapus 99  : Nilai 99 tidak ditemukan.
 *                List: 20 -> 40
 * ============================================================ */

void bagian_C() {
    Node *head = NULL;

    /* bangun list: 10 -> 20 -> 30 -> 40 -> 50 */
    insert_belakang(&head, 10);
    insert_belakang(&head, 20);
    insert_belakang(&head, 30);
    insert_belakang(&head, 40);
    insert_belakang(&head, 50);

    printf("=== Bagian C: Uji Delete ===\n");
    printf("Awal       : "); tampilkan_list(head);

    /* (C1) hapus node dengan nilai 30 (di tengah) */
    delete_node(____, ____);
    printf("-hapus 30  : "); tampilkan_list(head);

    /* (C2) hapus node dengan nilai 10 (head) */
    ____(____,  10);
    printf("-hapus 10  : "); tampilkan_list(head);

    /* (C3) hapus node dengan nilai 50 (tail) */
    delete_node(&head, ____);
    printf("-hapus 50  : "); tampilkan_list(head);

    /* (C4) coba hapus nilai yang tidak ada */
    delete_node(&head, 99);
    printf("             "); tampilkan_list(head);

    bebaskan_list(&head);
}


/* ============================================================
 * BAGIAN D — Uji bebaskan_list & Kondisi Setelah Free
 *
 * Setelah bebaskan_list dipanggil, head harus bernilai NULL.
 * Lengkapi kode di bawah untuk memverifikasi ini.
 *
 * Output yang diharapkan:
 *   === Bagian D: Bebaskan List ===
 *   Sebelum dibebaskan: List: 1 -> 2 -> 3
 *   Setelah dibebaskan: List: (kosong)
 *   head setelah free : NULL
 * ============================================================ */

void bagian_D() {
    Node *head = NULL;

    insert_belakang(&head, 1);
    insert_belakang(&head, 2);
    insert_belakang(&head, 3);

    printf("\n=== Bagian D: Bebaskan List ===\n");
    printf("Sebelum dibebaskan: "); tampilkan_list(head);

    /* (D1) panggil bebaskan_list — kirim alamat head */
    ____(&head);

    printf("Setelah dibebaskan: "); tampilkan_list(head);

    /* (D2) cek apakah head sekarang NULL */
    if (head == ____) {
        printf("head setelah free : NULL\n");
    } else {
        printf("head setelah free : BUKAN NULL — ada yang salah!\n");
    }
}


/* ============================================================
 * main
 * ============================================================ */

int main() {
    bagian_C();
    bagian_D();
    return 0;
}
