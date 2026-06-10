/*
 * Pertemuan 14 — Task B: BST Delete dan Validasi
 * Topik   : Binary Search Tree (BST)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 14_Task_B.c -o 14_Task_B
 *   - Jalankan: ./14_Task_B  (Linux/Mac)  atau  14_Task_B.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>


/* ============================================================
 * Definisi Struct & Fungsi Dasar — SUDAH LENGKAP, jangan ubah
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

Node *insert(Node *root, int nilai) {
    if (root == NULL) return buat_node(nilai);
    if (nilai < root->data) root->kiri  = insert(root->kiri,  nilai);
    else if (nilai > root->data) root->kanan = insert(root->kanan, nilai);
    return root;
}

void inorder(Node *node) {
    if (node == NULL) return;
    inorder(node->kiri);
    printf("%d ", node->data);
    inorder(node->kanan);
}

void bebaskan_bst(Node *root) {
    if (root == NULL) return;
    bebaskan_bst(root->kiri);
    bebaskan_bst(root->kanan);
    free(root);
}


/* ============================================================
 * SOAL 1 — Cari Inorder Successor (node terkecil di subtree)
 *
 * "Inorder successor" dari suatu node adalah nilai terkecil
 * yang LEBIH BESAR dari nilai node tersebut.
 * Dalam BST, ini adalah node paling KIRI di subtree KANAN.
 *
 * Fungsi ini digunakan oleh delete_node (Soal 2) untuk kasus
 * node dengan dua anak.
 *
 * Contoh:
 *         50
 *        /  \
 *       30   70
 *           /
 *          60
 *
 *   cari_minimum(root->kanan) = node dengan data 60
 *   (paling kiri di subtree kanan node 50)
 *
 * Langkah:
 *   - Selama node->kiri != NULL: node = node->kiri
 *   - return node   (bukan node->data — kembalikan pointer!)
 *
 * Hint: gunakan loop while. Berbeda dengan cari_min di Task A,
 *       fungsi ini mengembalikan POINTER ke node, bukan integer.
 * ============================================================ */

Node *cari_minimum(Node *node) {
    // TODO: temukan dan kembalikan pointer ke node terkecil
    // Tulis kodemu di sini

    return node;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 2 — Delete Node dari BST (3 Kasus)
 *
 * Hapus node dengan nilai tertentu dari BST.
 * Fungsi mengembalikan root (yang mungkin berubah).
 * Panggil dengan: root = delete_node(root, nilai);
 *
 * Tiga kasus yang harus ditangani:
 *
 * KASUS 1 — Node adalah leaf (kiri == NULL && kanan == NULL):
 *   free(root) → return NULL
 *
 * KASUS 2 — Node punya tepat 1 anak:
 *   Jika kiri == NULL: Node *tmp = root->kanan; free(root); return tmp;
 *   Jika kanan == NULL: Node *tmp = root->kiri; free(root); return tmp;
 *
 * KASUS 3 — Node punya 2 anak:
 *   a. Cari inorder successor: Node *suc = cari_minimum(root->kanan)
 *   b. Salin data successor: root->data = suc->data
 *   c. Hapus successor dari subtree kanan:
 *      root->kanan = delete_node(root->kanan, suc->data)
 *
 * Catatan: Kasus 1 tertangani oleh Kasus 2 (kiri==NULL, kanan==NULL):
 *   "kiri == NULL" → tmp = root->kanan (= NULL) → free → return NULL ✓
 *   Jadi kamu bisa menggabungkan Kasus 1 dan 2 dalam 2 kondisi saja!
 *
 * Contoh (hapus 30 dari BST 50-30-70-20-40):
 *   30 punya 2 anak (20 dan 40)
 *   Inorder successor 30 = 40 (min di subtree kanan 30)
 *   → Salin 40 ke posisi 30 → Hapus 40 dari subtree kanan
 *   Hasil: 20 40 50 70  (inorder)
 * ============================================================ */

Node *delete_node(Node *root, int nilai) {
    // TODO: implementasikan delete BST (3 kasus)
    // Tulis kodemu di sini

    return root;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Hitung Jumlah Node di BST
 *
 * Kembalikan total jumlah node dalam BST.
 *
 * Contoh (BST: 50 30 70 20 40):
 *   hitung_node(root) → 5
 *
 * Hint: sama persis dengan hitung_node dari Task A Pertemuan 13!
 *   return 1 + hitung_node(kiri) + hitung_node(kanan)
 * ============================================================ */

int hitung_node(Node *root) {
    // TODO: hitung total node secara rekursif
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 4 — Validasi BST
 *
 * Periksa apakah tree adalah BST yang valid — yaitu, apakah
 * invarian (kiri < akar < kanan) terpenuhi untuk SETIAP node.
 *
 * Strategi: pass batas min dan max ke setiap node.
 * Setiap node harus berada dalam rentang (min, maks).
 *
 * Kembalikan 1 jika valid, 0 jika tidak.
 *
 * Langkah:
 *   1. Base case: node == NULL → return 1 (tree kosong selalu valid)
 *   2. Jika node->data <= min ATAU node->data >= maks → return 0 (pelanggaran!)
 *   3. Rekursi kiri:  is_valid_bst(node->kiri,  min,        node->data)
 *   4. Rekursi kanan: is_valid_bst(node->kanan, node->data, maks)
 *   5. return hasil kiri && hasil kanan
 *
 * Panggil dengan: is_valid_bst(root, INT_MIN, INT_MAX)
 * (Gunakan -2147483648 dan 2147483647 jika INT_MIN/INT_MAX belum dikenal)
 *
 * Hint: #include <limits.h> untuk mendapatkan INT_MIN dan INT_MAX.
 * ============================================================ */

#include <limits.h>

int is_valid_bst(Node *node, int min, int maks) {
    // TODO: validasi apakah tree adalah BST yang benar
    // Tulis kodemu di sini

    return 1;   /* ganti baris ini */
}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

/* Helper: bangun BST dari array */
Node *bangun_bst(int arr[], int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, arr[i]);
    return root;
}

int main() {
    /* BST utama: 50 30 70 20 40 60 80 */
    int data[] = {50, 30, 70, 20, 40, 60, 80};
    Node *root = bangun_bst(data, 7);

    printf("BST awal (inorder): "); inorder(root); printf("\n");
    printf("Jumlah node: %d (harusnya 7)\n\n", hitung_node(root));

    /* --- Soal 4: Validasi --- */
    printf("=== Soal 4: Validasi BST ===\n");
    printf("BST valid: %d (harusnya 1)\n", is_valid_bst(root, INT_MIN, INT_MAX));

    /* Buat tree palsu yang melanggar invarian */
    Node *palsu = buat_node(10);
    palsu->kiri  = buat_node(5);
    palsu->kanan = buat_node(3);   /* 3 < 10 tapi ada di kanan! */
    printf("Tree palsu valid: %d (harusnya 0)\n\n", is_valid_bst(palsu, INT_MIN, INT_MAX));
    bebaskan_bst(palsu);

    /* --- Soal 1 & 2: Delete --- */
    printf("=== Soal 2: Delete Node ===\n");

    /* Hapus leaf: 20 */
    printf("Hapus 20 (leaf):\n");
    root = delete_node(root, 20);
    printf("  Inorder  : "); inorder(root); printf("\n");
    printf("  Harusnya : 30 40 50 60 70 80\n");
    printf("  BST valid: %d\n\n", is_valid_bst(root, INT_MIN, INT_MAX));

    /* Hapus node 1 anak: 30 (sekarang hanya punya kanan=40 setelah 20 dihapus) */
    printf("Hapus 30 (1 anak):\n");
    root = delete_node(root, 30);
    printf("  Inorder  : "); inorder(root); printf("\n");
    printf("  Harusnya : 40 50 60 70 80\n");
    printf("  BST valid: %d\n\n", is_valid_bst(root, INT_MIN, INT_MAX));

    /* Hapus node 2 anak: 70 (punya 60 dan 80) */
    printf("Hapus 70 (2 anak):\n");
    root = delete_node(root, 70);
    printf("  Inorder  : "); inorder(root); printf("\n");
    printf("  Harusnya : 40 50 60 80\n");
    printf("  BST valid: %d\n\n", is_valid_bst(root, INT_MIN, INT_MAX));

    /* Hapus root: 50 (2 anak) */
    printf("Hapus root 50 (2 anak):\n");
    root = delete_node(root, 50);
    printf("  Inorder  : "); inorder(root); printf("\n");
    printf("  Harusnya : 40 60 80\n");
    printf("  BST valid: %d\n\n", is_valid_bst(root, INT_MIN, INT_MAX));

    /* Hapus nilai yang tidak ada */
    printf("Hapus 99 (tidak ada):\n");
    root = delete_node(root, 99);
    printf("  Inorder  : "); inorder(root); printf("\n");
    printf("  Harusnya : 40 60 80 (tidak berubah)\n");

    bebaskan_bst(root);
    return 0;
}
