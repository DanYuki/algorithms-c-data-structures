/*
 * Pertemuan 13 — Task B: Operasi pada Binary Tree
 * Topik   : Trees: Binary Tree & Traversal
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 13_Task_B.c -o 13_Task_B
 *   - Jalankan: ./13_Task_B  (Linux/Mac)  atau  13_Task_B.exe  (Windows)
 *
 * Catatan: file ini bergantung pada struct Node dan fungsi-fungsi dasar
 *          yang sama dengan Task A. Struct dan helper sudah disiapkan di bawah.
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

void inorder(Node *node) {
    if (node == NULL) return;
    inorder(node->kiri);
    printf("%d ", node->data);
    inorder(node->kanan);
}

void bebaskan_tree(Node *root) {
    if (root == NULL) return;
    bebaskan_tree(root->kiri);
    bebaskan_tree(root->kanan);
    free(root);
}


/* ============================================================
 * SOAL 1 — Hitung Jumlah Daun (Leaf)
 *
 * Node "daun" (leaf) adalah node yang tidak punya child —
 * yaitu kiri == NULL DAN kanan == NULL.
 *
 * Kembalikan jumlah leaf dalam tree.
 *
 * Contoh:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 *
 * Leaf: 4, 5, 3  → hitung_daun(root) = 3
 *
 * Hint:
 *   - Base case 1: node == NULL → return 0
 *   - Base case 2: node->kiri == NULL && node->kanan == NULL → return 1 (ini daun)
 *   - Recursive case: return hitung_daun(kiri) + hitung_daun(kanan)
 * ============================================================ */

int hitung_daun(Node *node) {
    // TODO: hitung jumlah leaf secara rekursif
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 2 — Hitung Tinggi Tree (Height)
 *
 * Height suatu node = panjang jalur terpanjang dari node tersebut
 * ke leaf di bawahnya.
 *
 * Konvensi:
 *   - height(NULL) = -1   (tree kosong)
 *   - height(leaf) = 0    (tidak ada anak)
 *
 * Contoh:
 *         1           ← height = 2
 *        / \
 *       2   3         ← height(2)=1, height(3)=0
 *      / \
 *     4   5           ← height(4)=0, height(5)=0
 *
 * hitung_tinggi(root) = 2
 *
 * Rumus rekursif:
 *   height(node) = 1 + max(height(node->kiri), height(node->kanan))
 *
 * Hint untuk max:
 *   int kiri_h  = hitung_tinggi(node->kiri);
 *   int kanan_h = hitung_tinggi(node->kanan);
 *   return 1 + (kiri_h > kanan_h ? kiri_h : kanan_h);
 * ============================================================ */

int hitung_tinggi(Node *node) {
    // TODO: hitung tinggi tree secara rekursif
    // Tulis kodemu di sini

    return -1;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Cari Nilai dalam Tree
 *
 * Cari apakah sebuah nilai ada di dalam tree (binary tree biasa,
 * bukan BST — jadi harus cek semua node).
 *
 * Kembalikan 1 jika ditemukan, 0 jika tidak.
 *
 * Contoh:
 *   cari_nilai(root, 5)  → 1  (ada)
 *   cari_nilai(root, 99) → 0  (tidak ada)
 *
 * Langkah:
 *   1. Base case: node == NULL → return 0
 *   2. Jika node->data == target → return 1 (ketemu!)
 *   3. Cari di subtree kiri → jika ditemukan, return 1
 *   4. Cari di subtree kanan → return hasilnya
 *
 * Hint: kamu bisa tulis langkah 3 dan 4 dalam satu baris:
 *   return cari_nilai(node->kiri, target) || cari_nilai(node->kanan, target);
 * ============================================================ */

int cari_nilai(Node *node, int target) {
    // TODO: cari target secara rekursif di seluruh tree
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 4 — Hitung Node di Level Tertentu
 *
 * Level diukur dari root (root = level 0).
 *
 * Kembalikan jumlah node yang berada tepat di level yang diminta.
 *
 * Contoh:
 *         1           ← level 0 → 1 node
 *        / \
 *       2   3         ← level 1 → 2 node
 *      / \
 *     4   5           ← level 2 → 2 node
 *
 *   node_di_level(root, 0) = 1
 *   node_di_level(root, 1) = 2
 *   node_di_level(root, 2) = 2
 *   node_di_level(root, 3) = 0  (level tidak ada)
 *
 * Ide rekursif:
 *   - Jika node == NULL → return 0
 *   - Jika level == 0   → return 1  (kita sudah di level yang diminta)
 *   - Jika tidak        → hitung di kiri dengan level-1, tambah dengan kanan dengan level-1
 *
 * Hint:
 *   return node_di_level(node->kiri, level - 1)
 *        + node_di_level(node->kanan, level - 1);
 * ============================================================ */

int node_di_level(Node *node, int level) {
    // TODO: hitung jumlah node di level tertentu
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * Pengujian — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

int main() {
    /*
     * Bangun tree:
     *         1
     *        / \
     *       2   3
     *      / \
     *     4   5
     */
    Node *root = buat_node(1);
    root->kiri         = buat_node(2);
    root->kanan        = buat_node(3);
    root->kiri->kiri   = buat_node(4);
    root->kiri->kanan  = buat_node(5);

    printf("Tree (inorder): "); inorder(root); printf("\n\n");

    /* --- Soal 1: Hitung Daun --- */
    printf("=== Soal 1: Hitung Daun ===\n");
    printf("Jumlah daun: %d (harusnya 3)\n\n", hitung_daun(root));

    /* --- Soal 2: Hitung Tinggi --- */
    printf("=== Soal 2: Hitung Tinggi ===\n");
    printf("Tinggi tree       : %d (harusnya 2)\n",   hitung_tinggi(root));
    printf("Tinggi node 2     : %d (harusnya 1)\n",   hitung_tinggi(root->kiri));
    printf("Tinggi node 3     : %d (harusnya 0)\n",   hitung_tinggi(root->kanan));
    printf("Tinggi tree kosong: %d (harusnya -1)\n\n", hitung_tinggi(NULL));

    /* --- Soal 3: Cari Nilai --- */
    printf("=== Soal 3: Cari Nilai ===\n");
    printf("Cari 5  : %d (harusnya 1)\n", cari_nilai(root, 5));
    printf("Cari 3  : %d (harusnya 1)\n", cari_nilai(root, 3));
    printf("Cari 99 : %d (harusnya 0)\n", cari_nilai(root, 99));
    printf("Cari di NULL: %d (harusnya 0)\n\n", cari_nilai(NULL, 1));

    /* --- Soal 4: Node di Level --- */
    printf("=== Soal 4: Node di Level ===\n");
    printf("Level 0: %d node (harusnya 1)\n", node_di_level(root, 0));
    printf("Level 1: %d node (harusnya 2)\n", node_di_level(root, 1));
    printf("Level 2: %d node (harusnya 2)\n", node_di_level(root, 2));
    printf("Level 3: %d node (harusnya 0)\n", node_di_level(root, 3));

    /* Uji tree tidak seimbang */
    printf("\n--- Tree tidak seimbang ---\n");
    Node *miring = buat_node(10);
    miring->kiri          = buat_node(20);
    miring->kiri->kiri    = buat_node(30);
    miring->kiri->kiri->kiri = buat_node(40);
    /*
     *  10
     *  /
     * 20
     * /
     * 30
     * /
     * 40
     */
    printf("Tinggi (harusnya 3): %d\n", hitung_tinggi(miring));
    printf("Daun   (harusnya 1): %d\n", hitung_daun(miring));

    bebaskan_tree(root);
    bebaskan_tree(miring);
    return 0;
}
