/*
 * Pertemuan 14 — Task A: BST Insert, Search, dan Inorder
 * Topik   : Binary Search Tree (BST)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 14_Task_A.c -o 14_Task_A
 *   - Jalankan: ./14_Task_A  (Linux/Mac)  atau  14_Task_A.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>


/* ============================================================
 * Definisi Struct & Fungsi buat_node — SUDAH LENGKAP
 * ============================================================ */

typedef struct Node {
    int data;
    struct Node *kiri;
    struct Node *kanan;
} Node;

Node *buat_node(int nilai) {
    Node *baru = (Node *)malloc(sizeof(Node));
    baru->data  = nilai;
    baru->kiri  = NULL;
    baru->kanan = NULL;
    return baru;
}

void bebaskan_bst(Node *root) {
    if (root == NULL) return;
    bebaskan_bst(root->kiri);
    bebaskan_bst(root->kanan);
    free(root);
}


/* ============================================================
 * SOAL 1 — Insert: Tambahkan Nilai ke BST
 *
 * Masukkan nilai ke posisi yang tepat agar invarian BST tetap terjaga:
 *   - Semua nilai di kiri  < root->data
 *   - Semua nilai di kanan > root->data
 *
 * Fungsi mengembalikan root (pola umum BST agar tree bisa diubah):
 *   root = insert(root, 30);
 *
 * Contoh (insert 30, 50, 20, 40, 70 ke tree kosong):
 *   Hasil BST:    50
 *                /  \
 *               30   70
 *              / \
 *             20  40
 *   Inorder: 20 30 40 50 70
 *
 * Langkah:
 *   1. Base case: root == NULL → return buat_node(nilai)
 *   2. Jika nilai < root->data → root->kiri  = insert(root->kiri,  nilai)
 *   3. Jika nilai > root->data → root->kanan = insert(root->kanan, nilai)
 *   4. (nilai == root->data: duplikat, abaikan)
 *   5. return root
 * ============================================================ */

Node *insert(Node *root, int nilai) {
    // TODO: implementasikan insert BST rekursif
    // Tulis kodemu di sini

    return root;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 2 — Search: Cari Nilai di BST
 *
 * Cari apakah nilai ada di BST. Manfaatkan invarian BST untuk
 * memotong setengah pencarian di setiap langkah.
 *
 * Kembalikan pointer ke node jika ditemukan, NULL jika tidak.
 *
 * Contoh (pada BST dengan nilai 20 30 40 50 70):
 *   search(root, 40)  → pointer ke node dengan data=40
 *   search(root, 99)  → NULL
 *
 * Langkah:
 *   1. Base case: root == NULL → return NULL (tidak ada)
 *   2. Base case: root->data == target → return root (ketemu!)
 *   3. Jika target < root->data → cari di kiri
 *   4. Jika target > root->data → cari di kanan
 * ============================================================ */

Node *search(Node *root, int target) {
    // TODO: implementasikan search BST rekursif
    // Tulis kodemu di sini

    return NULL;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Inorder Traversal (cetak data terurut)
 *
 * Cetak semua nilai BST dalam urutan ascending (Kiri → Akar → Kanan).
 *
 * Untuk BST apapun yang valid, inorder SELALU menghasilkan urutan terurut.
 *
 * Contoh (BST: 50 30 70 20 40):
 *   inorder(root) → mencetak: 20 30 40 50 70
 *
 * Ini persis sama dengan inorder dari Pertemuan 13!
 * (Base case: node == NULL → return)
 * ============================================================ */

void inorder(Node *node) {
    // TODO: implementasikan inorder traversal
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 4 — Cari Nilai Minimum di BST
 *
 * Dalam BST, nilai terkecil selalu ada di node paling KIRI.
 * Terus ke kiri sampai tidak ada anak kiri lagi.
 *
 * Contoh (BST: 50 30 70 20 40):
 *   cari_min(root) → 20
 *
 * Langkah:
 *   - Selama node->kiri != NULL: node = node->kiri
 *   - return node->data
 *
 * Hint: gunakan loop while, bukan rekursi.
 *
 * Catatan: asumsikan tree tidak kosong (root != NULL).
 * ============================================================ */

int cari_min(Node *root) {
    // TODO: cari nilai minimum di BST
    // Tulis kodemu di sini

    return -1;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 5 — Cari Nilai Maksimum di BST
 *
 * Dalam BST, nilai terbesar selalu ada di node paling KANAN.
 *
 * Contoh (BST: 50 30 70 20 40):
 *   cari_maks(root) → 70
 *
 * Langkah: mirip cari_min, tapi terus ke KANAN.
 * ============================================================ */

int cari_maks(Node *root) {
    // TODO: cari nilai maksimum di BST
    // Tulis kodemu di sini

    return -1;   /* ganti baris ini */
}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

int main() {
    Node *root = NULL;

    /* Bangun BST dengan insert berurutan */
    int data[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;
    for (int i = 0; i < n; i++)
        root = insert(root, data[i]);

    /*
     * BST yang terbentuk:
     *         50
     *        /  \
     *       30   70
     *      / \  / \
     *     20 40 60 80
     */

    /* --- Soal 3: Inorder --- */
    printf("=== Soal 3: Inorder (harus terurut) ===\n");
    printf("Inorder  : "); inorder(root); printf("\n");
    printf("Harusnya : 20 30 40 50 60 70 80\n\n");

    /* --- Soal 2: Search --- */
    printf("=== Soal 2: Search ===\n");
    int cari[] = {40, 60, 99, 20};
    for (int i = 0; i < 4; i++) {
        Node *hasil = search(root, cari[i]);
        printf("Cari %2d: %s\n", cari[i], hasil ? "Ditemukan ✓" : "Tidak ada ✗");
    }
    printf("Harusnya: Ditemukan, Ditemukan, Tidak ada, Ditemukan\n\n");

    /* --- Soal 4 & 5: Min & Maks --- */
    printf("=== Soal 4 & 5: Min & Maks ===\n");
    printf("Minimum : %d (harusnya 20)\n", cari_min(root));
    printf("Maksimum: %d (harusnya 80)\n\n", cari_maks(root));

    /* Uji insert duplikat — BST tidak berubah */
    printf("=== Uji Duplikat ===\n");
    root = insert(root, 50);   /* duplikat, tidak dimasukkan */
    printf("Setelah insert 50 (duplikat): "); inorder(root); printf("\n");
    printf("Harusnya tetap: 20 30 40 50 60 70 80\n");

    bebaskan_bst(root);
    return 0;
}
