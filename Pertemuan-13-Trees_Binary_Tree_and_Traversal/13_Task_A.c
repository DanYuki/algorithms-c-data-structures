/*
 * Pertemuan 13 — Task A: Binary Tree & Traversal
 * Topik   : Trees: Binary Tree & Traversal
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Implementasikan fungsi-fungsi yang bertanda TODO
 *   - Jangan ubah signature fungsi (nama, parameter, return type)
 *   - File ini sudah bisa dikompilasi sejak awal
 *   - Compile: gcc 13_Task_A.c -o 13_Task_A
 *   - Jalankan: ./13_Task_A  (Linux/Mac)  atau  13_Task_A.exe  (Windows)
 */

#include <stdio.h>
#include <stdlib.h>


/* ============================================================
 * SOAL 1 — Definisi Struct Node
 *
 * Definisikan struct untuk satu node dalam binary tree.
 * Setiap node menyimpan:
 *   - data  : sebuah integer
 *   - kiri  : pointer ke child kiri (NULL jika tidak ada)
 *   - kanan : pointer ke child kanan (NULL jika tidak ada)
 *
 * Gunakan typedef sehingga kamu bisa menulis 'Node *' (bukan 'struct Node *')
 * di luar definisi struct.
 *
 * Petunjuk typedef:
 *   typedef struct NamaStruct {
 *       ...
 *       struct NamaStruct *kiri;   // di dalam definisi, harus tulis nama struct penuh
 *   } NamaAlias;
 * ============================================================ */

/* TODO: definisikan struct Node di sini */
/* Tulis kodemu di sini */


/* ============================================================
 * SOAL 2 — Fungsi Membuat Node Baru
 *
 * Buat fungsi yang mengalokasikan node baru di heap,
 * mengisinya dengan nilai yang diberikan, dan mengembalikan pointer-nya.
 *
 * Contoh:
 *   Node *n = buat_node(42);
 *   printf("%d\n", n->data);  // 42
 *   printf("%p\n", n->kiri);  // (nil) / 0x0
 *
 * Langkah:
 *   1. malloc satu Node
 *   2. Set data = nilai
 *   3. Set kiri = NULL, kanan = NULL
 *   4. return pointer ke node baru
 * ============================================================ */

Node *buat_node(int nilai) {
    // TODO: alokasikan dan inisialisasi node baru
    // Tulis kodemu di sini

    return NULL;   /* ganti baris ini */
}


/* ============================================================
 * SOAL 3 — Traversal Preorder (Akar → Kiri → Kanan)
 *
 * Cetak semua nilai dalam tree dengan urutan:
 *   1. Kunjungi node saat ini (cetak data)
 *   2. Rekursi ke subtree kiri
 *   3. Rekursi ke subtree kanan
 *
 * Untuk tree:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 *
 * Output preorder: 1 2 4 5 3
 *
 * Hint: base case = jika node NULL, langsung return (tidak ada yang dicetak).
 * ============================================================ */

void preorder(Node *node) {
    // TODO: implementasikan traversal preorder
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 4 — Traversal Inorder (Kiri → Akar → Kanan)
 *
 * Cetak semua nilai dalam urutan:
 *   1. Rekursi ke subtree kiri
 *   2. Kunjungi node saat ini (cetak data)
 *   3. Rekursi ke subtree kanan
 *
 * Untuk tree yang sama di atas:
 * Output inorder: 4 2 5 1 3
 *
 * Catatan: untuk Binary Search Tree (BST), inorder menghasilkan
 *          data dalam urutan terurut ascending — kita akan manfaatkan
 *          ini di Pertemuan 14!
 * ============================================================ */

void inorder(Node *node) {
    // TODO: implementasikan traversal inorder
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 5 — Traversal Postorder (Kiri → Kanan → Akar)
 *
 * Cetak semua nilai dalam urutan:
 *   1. Rekursi ke subtree kiri
 *   2. Rekursi ke subtree kanan
 *   3. Kunjungi node saat ini (cetak data)
 *
 * Untuk tree yang sama di atas:
 * Output postorder: 4 5 2 3 1
 *
 * Catatan: perhatikan bahwa root (1) dicetak paling terakhir.
 *          Pola ini sama dengan urutan membebaskan memori!
 * ============================================================ */

void postorder(Node *node) {
    // TODO: implementasikan traversal postorder
    // Tulis kodemu di sini

}


/* ============================================================
 * SOAL 6 — Hitung Jumlah Node
 *
 * Kembalikan jumlah total node dalam tree (termasuk root).
 *
 * Contoh:
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 * hitung_node(root) → 5
 *
 * Tree kosong (NULL) → 0
 *
 * Hint: jumlah node = 1 (node ini) + jumlah node di kiri + jumlah node di kanan.
 *       Ini pola rekursi klasik — mirip sum_array rekursif dari Pertemuan 10!
 * ============================================================ */

int hitung_node(Node *node) {
    // TODO: hitung total node secara rekursif
    // Tulis kodemu di sini

    return 0;   /* ganti baris ini */
}


/* ============================================================
 * Fungsi Bantu — SUDAH LENGKAP, jangan ubah
 * ============================================================ */

/* Bebaskan semua node dalam tree */
void bebaskan_tree(Node *root) {
    if (root == NULL) return;
    bebaskan_tree(root->kiri);
    bebaskan_tree(root->kanan);
    free(root);
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
    if (root == NULL) {
        printf("buat_node belum diimplementasikan.\n");
        return 1;
    }
    root->kiri         = buat_node(2);
    root->kanan        = buat_node(3);
    root->kiri->kiri   = buat_node(4);
    root->kiri->kanan  = buat_node(5);

    /* --- Soal 3: Preorder --- */
    printf("=== Soal 3: Preorder (A-K-Ka) ===\n");
    printf("Hasil  : "); preorder(root);  printf("\n");
    printf("Harusnya: 1 2 4 5 3\n\n");

    /* --- Soal 4: Inorder --- */
    printf("=== Soal 4: Inorder (K-A-Ka) ===\n");
    printf("Hasil  : "); inorder(root);   printf("\n");
    printf("Harusnya: 4 2 5 1 3\n\n");

    /* --- Soal 5: Postorder --- */
    printf("=== Soal 5: Postorder (K-Ka-A) ===\n");
    printf("Hasil  : "); postorder(root); printf("\n");
    printf("Harusnya: 4 5 2 3 1\n\n");

    /* --- Soal 6: Hitung Node --- */
    printf("=== Soal 6: Hitung Node ===\n");
    printf("Jumlah node: %d (harusnya 5)\n\n", hitung_node(root));

    /* Uji tree kosong */
    printf("Tree kosong (NULL): %d node (harusnya 0)\n", hitung_node(NULL));

    /* Bersihkan memori */
    bebaskan_tree(root);
    return 0;
}
