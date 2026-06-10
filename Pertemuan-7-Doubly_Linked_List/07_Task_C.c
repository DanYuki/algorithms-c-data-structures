/*
 * Pertemuan 7 — Task C: Delete Node & Edge Cases
 * Topik   : Doubly Linked List
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 07_Task_C.c -o 07_Task_C
 *   - Jalankan: ./07_Task_C  (Linux/Mac)  atau  07_Task_C.exe  (Windows)
 *
 * Fungsi bantu sudah disediakan lengkap termasuk insert.
 * Fokus pada delete_node dan pengujian edge cases.
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
    if (!n) { printf("Error: malloc gagal!\n"); exit(1); }
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

void insert_belakang(Node **head, Node **tail, int data) {
    Node *n = buat_node(data);
    if (!*tail) { *head = n; *tail = n; return; }
    n->prev = *tail; (*tail)->next = n; *tail = n;
}

void bebaskan_list(Node **head, Node **tail) {
    Node *p = *head;
    while (p) { Node *nx = p->next; free(p); p = nx; }
    *head = NULL; *tail = NULL;
}


/* ============================================================
 * BAGIAN A — delete_node: Menghapus Node Berdasarkan Nilai
 *
 * Fungsi ini menangani semua kasus:
 *   1. List kosong
 *   2. Nilai tidak ditemukan
 *   3. Node yang dihapus adalah head
 *   4. Node yang dihapus adalah tail
 *   5. Node yang dihapus ada di tengah
 *
 * Langkah umum setelah menemukan node target:
 *   - Perbarui next tetangga KIRI (jika ada)
 *   - Perbarui prev tetangga KANAN (jika ada)
 *   - Jika tidak ada tetangga kiri → update head
 *   - Jika tidak ada tetangga kanan → update tail
 *   - free(target)
 * ============================================================ */

void delete_node(Node **head, Node **tail, int target) {
    /* (A1) cek list kosong */
    if (*head == ____) {
        printf("List kosong.\n");
        return;
    }

    /* (A2) cari node target dengan traversal */
    Node *saat_ini = *head;
    while (saat_ini != NULL && saat_ini->data != ____) {
        saat_ini = saat_ini->next;
    }

    /* (A3) target tidak ditemukan */
    if (saat_ini == ____) {
        printf("Nilai %d tidak ditemukan.\n", target);
        return;
    }

    /* (A4) perbarui tetangga KIRI (prev dari saat_ini) */
    if (saat_ini->prev != NULL) {
        /* ada tetangga kiri — sambungkan next-nya melewati saat_ini */
        saat_ini->____->next = saat_ini->next;
    } else {
        /* saat_ini adalah HEAD — pindahkan head ke node berikutnya */
        *head = saat_ini->____;
    }

    /* (A5) perbarui tetangga KANAN (next dari saat_ini) */
    if (saat_ini->next != NULL) {
        /* ada tetangga kanan — sambungkan prev-nya melewati saat_ini */
        saat_ini->____->prev = saat_ini->prev;
    } else {
        /* saat_ini adalah TAIL — pindahkan tail ke node sebelumnya */
        *tail = saat_ini->____;
    }

    /* (A6) bebaskan memori node yang dihapus */
    ____(saat_ini);
}


/* ============================================================
 * BAGIAN B — Uji delete_node: Kasus Normal
 *
 * Lengkapi pemanggilan delete_node sehingga menghasilkan:
 *
 *   === Bagian B: Delete Normal ===
 *   Awal      : Maju  : 10 <-> 20 <-> 30 <-> 40 <-> 50
 *   -hapus 30 : Maju  : 10 <-> 20 <-> 40 <-> 50
 *   -hapus 10 : Maju  : 20 <-> 40 <-> 50
 *   -hapus 50 : Maju  : 20 <-> 40
 *   Mundur    : Mundur: 40 <-> 20
 * ============================================================ */

void bagian_B() {
    Node *head = NULL, *tail = NULL;

    insert_belakang(&head, &tail, 10);
    insert_belakang(&head, &tail, 20);
    insert_belakang(&head, &tail, 30);
    insert_belakang(&head, &tail, 40);
    insert_belakang(&head, &tail, 50);

    printf("=== Bagian B: Delete Normal ===\n");
    printf("Awal      : "); tampilkan_maju(head);

    /* (B1) hapus node di tengah (30) */
    delete_node(____, ____, ____);
    printf("-hapus 30 : "); tampilkan_maju(head);

    /* (B2) hapus head (10) */
    delete_node(&head, &tail, ____);
    printf("-hapus 10 : "); tampilkan_maju(head);

    /* (B3) hapus tail (50) */
    ____(____,  ____, 50);
    printf("-hapus 50 : "); tampilkan_maju(head);

    printf("Mundur    : "); tampilkan_mundur(tail);

    bebaskan_list(&head, &tail);
}


/* ============================================================
 * BAGIAN C — Edge Cases
 *
 * Lengkapi pengujian edge cases berikut:
 *
 * C1. List kosong → delete_node tidak crash, cetak pesan
 * C2. List satu node → setelah delete, head DAN tail harus NULL
 * C3. Nilai tidak ada → cetak pesan, list tidak berubah
 *
 * Output yang diharapkan:
 *   === Bagian C: Edge Cases ===
 *
 *   [C1] Delete dari list kosong:
 *   List kosong.
 *
 *   [C2] Delete satu-satunya node:
 *   Sebelum: Maju  : 99
 *   Sesudah: Maju  : (kosong)
 *   head == NULL: Ya ✓
 *   tail == NULL: Ya ✓
 *
 *   [C3] Delete nilai yang tidak ada:
 *   List: Maju  : 1 <-> 2 <-> 3
 *   Nilai 99 tidak ditemukan.
 *   List tetap: Maju  : 1 <-> 2 <-> 3
 * ============================================================ */

void bagian_C() {
    printf("\n=== Bagian C: Edge Cases ===\n");

    /* C1: delete dari list kosong */
    printf("\n[C1] Delete dari list kosong:\n");
    Node *head1 = NULL, *tail1 = NULL;
    /* (C1) panggil delete_node pada list kosong (head1, tail1) dengan nilai berapa saja */
    delete_node(____, ____, 10);

    /* C2: delete satu-satunya node */
    printf("\n[C2] Delete satu-satunya node:\n");
    Node *head2 = NULL, *tail2 = NULL;
    insert_belakang(&head2, &tail2, 99);
    printf("Sebelum: "); tampilkan_maju(head2);

    /* (C2) hapus node 99 dari list berisi satu elemen */
    delete_node(____, ____, ____);

    printf("Sesudah: "); tampilkan_maju(head2);
    printf("head == NULL: %s\n", head2 == NULL ? "Ya ✓" : "Tidak ✗");
    printf("tail == NULL: %s\n", tail2 == NULL ? "Ya ✓" : "Tidak ✗");

    /* C3: delete nilai yang tidak ada */
    printf("\n[C3] Delete nilai yang tidak ada:\n");
    Node *head3 = NULL, *tail3 = NULL;
    insert_belakang(&head3, &tail3, 1);
    insert_belakang(&head3, &tail3, 2);
    insert_belakang(&head3, &tail3, 3);
    printf("List: "); tampilkan_maju(head3);

    delete_node(&head3, &tail3, ____);   // (C3) coba hapus nilai 99

    printf("List tetap: "); tampilkan_maju(head3);
    bebaskan_list(&head3, &tail3);
}


/* ============================================================
 * BAGIAN D — Verifikasi Konsistensi Pointer Setelah Delete
 *
 * Setelah setiap delete, cek bahwa:
 *   - head->prev == NULL
 *   - tail->next == NULL
 *   - Setiap node->next->prev menunjuk balik ke node itu
 *
 * Fungsi cek_konsistensi sudah disediakan.
 * Lengkapi pemanggilan delete dan fungsi cek.
 * ============================================================ */

void cek_konsistensi(Node *head, Node *tail) {
    if (head == NULL) {
        printf("  [Kosong — tidak ada yang dicek]\n");
        return;
    }
    printf("  head->prev == NULL : %s\n", head->prev == NULL ? "✓" : "✗ BUG!");
    printf("  tail->next == NULL : %s\n", tail->next == NULL ? "✓" : "✗ BUG!");

    Node *p = head;
    int ok = 1;
    while (p->next != NULL) {
        if (p->next->prev != p) { ok = 0; break; }
        p = p->next;
    }
    printf("  Sambungan dua arah : %s\n", ok ? "✓" : "✗ BUG! prev tidak konsisten");
}

void bagian_D() {
    Node *head = NULL, *tail = NULL;

    insert_belakang(&head, &tail, 1);
    insert_belakang(&head, &tail, 2);
    insert_belakang(&head, &tail, 3);
    insert_belakang(&head, &tail, 4);

    printf("\n=== Bagian D: Verifikasi Konsistensi ===\n");
    printf("Awal: "); tampilkan_maju(head);
    cek_konsistensi(head, tail);

    /* (D1) hapus node di tengah (2), lalu cek konsistensi */
    delete_node(&head, &tail, ____);
    printf("Setelah hapus 2: "); tampilkan_maju(head);
    cek_konsistensi(____, ____);   // (D2) kirim head dan tail

    /* (D3) hapus head (1), lalu cek konsistensi */
    delete_node(&head, &tail, 1);
    printf("Setelah hapus 1: "); tampilkan_maju(head);
    cek_konsistensi(head, tail);

    bebaskan_list(&head, &tail);
}


/* ============================================================
 * main
 * ============================================================ */

int main() {
    bagian_B();
    bagian_C();
    bagian_D();
    return 0;
}
