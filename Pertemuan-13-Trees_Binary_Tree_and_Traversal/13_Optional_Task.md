# Pertemuan 13 — Optional Task: Binary Tree & Traversal

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` sendiri sebagai jawabanmu.

---

## Optional Task 1 — Cetak Tree Level per Level (Level: Mudah)

### Latar Belakang

Traversal preorder/inorder/postorder mengunjungi node mengikuti arah *kedalaman* (depth-first). Cara lain yang sangat berguna adalah **level-order traversal** — kunjungi semua node di level 0 dahulu, lalu semua di level 1, dst. Ini menghasilkan tampilan tree seperti membaca dari atas ke bawah, kiri ke kanan.

```
        1
       / \
      2   3
     / \
    4   5

Level-order: 1  2  3  4  5
```

Kamu sudah punya fungsi `node_di_level(root, level)` dari Task B. Gunakan itu!

### Yang Harus Dibuat

Buat file **`optional1_level_order.c`** yang:

1. Mendefinisikan struct `Node` dan fungsi `buat_node`, `bebaskan_tree`, `hitung_tinggi`.

2. Implementasikan fungsi:
   ```c
   /* Cetak semua node level per level, mulai dari level 0 */
   void level_order(Node *root);
   ```
   Strategi: gunakan `hitung_tinggi` untuk tahu berapa level ada, lalu loop dari level 0
   sampai tinggi tree, cetak semua node di setiap level.

   ```c
   /* Cetak semua node di satu level tertentu */
   void cetak_level(Node *node, int level);

   void level_order(Node *root) {
       int tinggi = hitung_tinggi(root);
       for (int i = 0; i <= tinggi; i++) {
           printf("Level %d: ", i);
           cetak_level(root, i);
           printf("\n");
       }
   }
   ```

3. Di `main()`, bangun tree ini dan panggil `level_order`:
   ```c
   /*
    *         1
    *        / \
    *       2   3
    *      / \   \
    *     4   5   6
    */
   ```

### Contoh Output

```
=== Level-Order Traversal ===
Level 0: 1
Level 1: 2 3
Level 2: 4 5 6

=== Perbandingan Traversal ===
Preorder    : 1 2 4 5 3 6
Inorder     : 4 2 5 1 3 6
Postorder   : 4 5 2 6 3 1
Level-order : 1 2 3 4 5 6
```

### Pertanyaan Refleksi (tulis sebagai komentar)

1. Traversal mana yang paling mudah dipahami manusia untuk melihat struktur tree?
2. Apa kelemahan pendekatan "loop level + cetak_level"? (Hint: bayangkan jika tree sangat dalam dan tidak seimbang.)

---

## Optional Task 2 — Mirror Tree (Level: Menantang)

### Latar Belakang

**Mirror** dari sebuah binary tree adalah tree di mana subtree kiri dan kanan setiap node ditukar. Misalnya:

```
Tree asli:         Mirror-nya:
      1                 1
     / \               / \
    2   3             3   2
   / \                   / \
  4   5                 5   4
```

Ini berguna untuk memahami manipulasi struktur tree secara rekursif — dan juga soal klasik dalam wawancara teknis.

### Yang Harus Dibuat

Buat file **`optional2_mirror_tree.c`** yang:

1. Implementasikan fungsi `mirror`:
   ```c
   /*
    * Tukar semua subtree kiri dan kanan di seluruh tree (in-place).
    * Ubah tree itu sendiri — tidak membuat tree baru.
    *
    * Langkah:
    *   1. Base case: node == NULL → return
    *   2. Tukar node->kiri dengan node->kanan
    *   3. Rekursi ke node->kiri (yang sekarang adalah kanan asli)
    *   4. Rekursi ke node->kanan (yang sekarang adalah kiri asli)
    */
   void mirror(Node *node);
   ```

2. Implementasikan fungsi `is_mirror` yang mengecek apakah dua tree adalah cermin satu sama lain:
   ```c
   /*
    * Kembalikan 1 jika tree a dan tree b adalah cermin satu sama lain.
    * Kembalikan 0 jika tidak.
    *
    * Dua tree adalah cermin jika:
    *   - Keduanya NULL           → mirror (return 1)
    *   - Salah satu NULL         → bukan mirror (return 0)
    *   - a->data == b->data DAN
    *     a->kiri  ↔ b->kanan adalah mirror DAN
    *     a->kanan ↔ b->kiri  adalah mirror
    */
   int is_mirror(Node *a, Node *b);
   ```

3. Di `main()`, bangun tree asli, buat salinannya, lakukan mirror pada salah satu, lalu verifikasi:

   ```c
   /*
    * Tree yang digunakan:
    *         1
    *        / \
    *       2   3
    *      / \   \
    *     4   5   6
    */
   Node *original = /* bangun tree */;
   Node *salinan  = /* bangun tree yang sama */;

   printf("Inorder original: "); inorder(original); printf("\n");
   mirror(salinan);
   printf("Inorder setelah mirror: "); inorder(salinan); printf("\n");

   printf("is_mirror(original, salinan): %d (harusnya 1)\n",
          is_mirror(original, salinan));

   /* Mirror lagi → kembali ke semula */
   mirror(salinan);
   printf("is_mirror setelah mirror 2x: %d (harusnya 0)\n",
          is_mirror(original, salinan));
   /* Kenapa 0? Karena is_mirror mengecek CERMIN, bukan kesamaan.
      Setelah di-mirror 2x, salinan kembali identik dengan original —
      dan tree yang identik bukan cermin (kecuali tree simetris). */
   ```

### Contoh Output

```
Inorder original         : 4 2 5 1 3 6
Inorder setelah mirror   : 6 3 1 5 2 4
is_mirror(original, salinan): 1
is_mirror setelah mirror 2x : 0

=== Verifikasi Visual ===
Original (inorder) : 4 2 5 1 3 6
Mirror   (inorder) : 6 3 1 5 2 4
```

### Pertanyaan Analisis (tulis sebagai komentar)

1. Apa kompleksitas Big-O dari fungsi `mirror`? Jelaskan.
2. Apakah `mirror(mirror(tree))` selalu menghasilkan tree yang identik dengan tree asal?
3. Kapan `is_mirror(tree, tree)` bernilai 1? (Hint: tree seperti apa yang merupakan cermin dari dirinya sendiri?)
