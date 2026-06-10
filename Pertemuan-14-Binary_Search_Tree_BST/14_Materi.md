# Pertemuan 14 — Binary Search Tree (BST)

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Sifat BST: Mengapa Pencarian Jadi Cepat?](#1-sifat-bst-mengapa-pencarian-jadi-cepat)
2. [Insert: Menambahkan Node ke BST](#2-insert-menambahkan-node-ke-bst)
3. [Search: Mencari Nilai di BST](#3-search-mencari-nilai-di-bst)
4. [Inorder Traversal = Data Terurut](#4-inorder-traversal--data-terurut)
5. [Delete: Menghapus Node (3 Kasus)](#5-delete-menghapus-node-3-kasus)
6. [AI untuk Debugging Delete](#6-ai-untuk-debugging-delete)

---

## 1. Sifat BST: Mengapa Pencarian Jadi Cepat?

**Binary Search Tree (BST)** adalah binary tree dengan satu aturan tambahan — **invarian BST**:

> Untuk setiap node N:
> - Semua nilai di **subtree kiri** < `N->data`
> - Semua nilai di **subtree kanan** > `N->data`

Contoh BST yang valid:

```
        50
       /  \
      30   70
     / \   / \
    20  40 60  80
```

Verifikasi:
- Node 50: semua di kiri (20, 30, 40) < 50 ✓, semua di kanan (60, 70, 80) > 50 ✓
- Node 30: semua di kiri (20) < 30 ✓, semua di kanan (40) > 30 ✓

### Kenapa BST Membuat Pencarian O(log n)?

Ketika mencari nilai 60 di tree di atas:
```
1. Bandingkan 60 dengan root (50) → 60 > 50 → pergi ke kanan
2. Bandingkan 60 dengan 70       → 60 < 70 → pergi ke kiri
3. Bandingkan 60 dengan 60       → ketemu!
```
Hanya **3 langkah** untuk tree dengan 7 node. Setiap langkah, kita membuang setengah tree yang tidak mungkin mengandung nilai yang dicari — persis seperti binary search!

**Perbandingan:**

| Operasi | Array (tidak terurut) | Linked List | BST (seimbang) |
|---|---|---|---|
| Search | O(n) | O(n) | **O(log n)** |
| Insert | O(1) akhir | O(1) awal | **O(log n)** |
| Delete | O(n) | O(n) | **O(log n)** |

> **Catatan penting:** O(log n) adalah **rata-rata** dan kasus terbaik. Jika BST miring (semua node ke satu sisi), worst case bisa O(n) — seperti linked list. Solusinya adalah BST yang "seimbang" (AVL Tree, Red-Black Tree) yang dipelajari di mata kuliah lanjutan.

---

## 2. Insert: Menambahkan Node ke BST

Aturan: temukan posisi daun yang tepat dengan mengikuti invarian BST.

```
Masukkan 45 ke BST:
        50
       /  \
      30   70
     / \
    20  40

Langkah:
  45 < 50 → pergi ke kiri (30)
  45 > 30 → pergi ke kanan (40)
  45 > 40 → pergi ke kanan (NULL) → sisipkan di sini!

Hasil:
        50
       /  \
      30   70
     / \
    20  40
          \
          45
```

### Implementasi Rekursif

```c
#include <stdio.h>
#include <stdlib.h>

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

/*
 * Insert nilai ke BST. Kembalikan pointer ke root (yang mungkin berubah
 * jika tree awalnya NULL).
 *
 * Pola: fungsi mengembalikan root sehingga kita bisa tulis:
 *   root = insert(root, 45);
 */
Node *insert(Node *root, int nilai) {
    /* Base case: posisi kosong ditemukan → buat node baru */
    if (root == NULL) return buat_node(nilai);

    if (nilai < root->data)
        root->kiri  = insert(root->kiri,  nilai);  /* masuk ke kiri */
    else if (nilai > root->data)
        root->kanan = insert(root->kanan, nilai);  /* masuk ke kanan */
    /* nilai == root->data: duplikat, tidak dimasukkan */

    return root;   /* kembalikan root (tidak berubah untuk node internal) */
}
```

**Mengapa mengembalikan `root`?**
Pada base case, `insert(NULL, nilai)` mengembalikan node baru. Pemanggil (parent) menangkap ini dengan `root->kiri = insert(root->kiri, nilai)` — itulah cara node baru tersambung ke tree.

---

## 3. Search: Mencari Nilai di BST

Logika sama dengan insert — ikuti invarian BST untuk memutuskan arah:

```c
/*
 * Cari nilai di BST. Kembalikan pointer ke node jika ditemukan,
 * NULL jika tidak ada.
 */
Node *search(Node *root, int target) {
    /* Base case 1: tree kosong atau node tidak ditemukan */
    if (root == NULL) return NULL;

    /* Base case 2: ketemu */
    if (root->data == target) return root;

    /* Recursive case: arahkan ke kiri atau kanan */
    if (target < root->data)
        return search(root->kiri,  target);
    else
        return search(root->kanan, target);
}
```

Penggunaan:
```c
Node *hasil = search(root, 40);
if (hasil != NULL)
    printf("Ditemukan: %d\n", hasil->data);
else
    printf("Tidak ditemukan.\n");
```

---

## 4. Inorder Traversal = Data Terurut

Ingat dari Pertemuan 13: inorder = Kiri → Akar → Kanan.

Untuk BST, karena kiri selalu < akar < kanan, inorder menghasilkan elemen **dalam urutan ascending**:

```
BST:        50          Inorder: 20 30 40 50 70
           /  \
          30   70
         / \
        20  40
```

```c
void inorder(Node *node) {
    if (node == NULL) return;
    inorder(node->kiri);
    printf("%d ", node->data);
    inorder(node->kanan);
}
```

> Ini setara dengan sorting! Masukkan n elemen ke BST lalu lakukan inorder → O(n log n), setara dengan Merge Sort.

---

## 5. Delete: Menghapus Node (3 Kasus)

Delete adalah operasi paling kompleks di BST karena harus menjaga invarian setelah penghapusan.

Ada **3 kasus** berdasarkan jumlah child node yang akan dihapus:

### Kasus 1 — Node adalah Leaf (tidak punya anak)

```
Hapus 20:
      30              30
     / \    →          \
    20  40              40
```
Cukup bebaskan node dan kembalikan `NULL` ke parent.

### Kasus 2 — Node punya tepat 1 anak

```
Hapus 30 (hanya punya child kanan):
      50              50
     /  \    →       /  \
    30   70          40   70
      \
       40
```
Ganti node yang dihapus dengan satu-satunya anaknya.

### Kasus 3 — Node punya 2 anak (paling kompleks)

Tidak bisa langsung dihapus. Strategi: ganti nilainya dengan **inorder successor** (nilai terkecil di subtree kanan), lalu hapus inorder successor dari subtree kanan.

**Inorder successor** = node paling kiri (terkecil) di subtree kanan.

```
Hapus 50 (punya 2 anak):
      50              60
     /  \    →       /  \
    30   70          30   70
        /
       60
```
Langkah:
1. Cari inorder successor: node terkecil di subtree kanan = 60
2. Salin data 60 ke node yang "dihapus" (node 50 → data menjadi 60)
3. Hapus node 60 dari subtree kanan (ini pasti kasus 1 atau 2)

### Implementasi

```c
/* Cari node dengan nilai terkecil (paling kiri) di tree */
Node *cari_minimum(Node *node) {
    while (node->kiri != NULL)
        node = node->kiri;
    return node;
}

/*
 * Hapus nilai dari BST. Kembalikan pointer ke root (yang mungkin berubah).
 * Panggil dengan: root = delete_node(root, nilai);
 */
Node *delete_node(Node *root, int nilai) {
    if (root == NULL) return NULL;   /* nilai tidak ada */

    if (nilai < root->data) {
        /* Nilai ada di subtree kiri */
        root->kiri = delete_node(root->kiri, nilai);

    } else if (nilai > root->data) {
        /* Nilai ada di subtree kanan */
        root->kanan = delete_node(root->kanan, nilai);

    } else {
        /* Ditemukan — salah satu dari 3 kasus */

        /* Kasus 1 & 2: 0 atau 1 anak */
        if (root->kiri == NULL) {
            Node *tmp = root->kanan;
            free(root);
            return tmp;   /* NULL jika leaf; child kanan jika ada 1 anak */
        }
        if (root->kanan == NULL) {
            Node *tmp = root->kiri;
            free(root);
            return tmp;
        }

        /* Kasus 3: 2 anak */
        Node *successor = cari_minimum(root->kanan);   /* inorder successor */
        root->data  = successor->data;                  /* salin nilai successor */
        root->kanan = delete_node(root->kanan, successor->data); /* hapus successor */
    }

    return root;
}
```

### Ringkasan 3 Kasus Delete

```
Node yang dihapus:         Aksi:
┌─────────────────┬────────────────────────────────────────────┐
│ Leaf (0 anak)   │ free → return NULL                         │
│ 1 anak          │ free → return pointer ke anak              │
│ 2 anak          │ copy nilai successor → delete successor     │
└─────────────────┴────────────────────────────────────────────┘
```

---

## 6. AI untuk Debugging Delete

Delete BST adalah bagian yang paling sering salah. AI bisa membantu menelusuri bug.

### Prompt Debugging Delete

```
Ini implementasi delete_node BST saya di C:
[tempelkan kode]

Setelah hapus node 50 dari tree ini:
  50 → kiri:30, kanan:70; 30 → kiri:20, kanan:40; 70 → kiri:60

Inorder seharusnya: 20 30 40 60 70
Tapi saya dapat: 20 30 40 50 70

Apa yang salah? Telusuri langkah kasus 3 (dua anak).
```

### Prompt Validasi Invarian BST

```
Setelah beberapa kali insert dan delete, bagaimana cara memverifikasi
bahwa sebuah tree masih merupakan BST yang valid?
Tuliskan fungsi C `int is_valid_bst(Node *node, int min, int max)`
yang memeriksa apakah setiap node memenuhi batasan min < data < max.
```

### Yang Perlu Divalidasi dari Output AI

- [ ] Apakah kode AI menggunakan `cari_minimum(root->kanan)` (bukan `cari_maximum(root->kiri)`) untuk inorder successor?
- [ ] Apakah AI meng-`free` node yang dihapus (bukan hanya melepas pointer)?
- [ ] Jalankan inorder sebelum dan sesudah delete — apakah hasilnya benar?
