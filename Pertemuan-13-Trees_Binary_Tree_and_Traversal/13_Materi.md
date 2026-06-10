# Pertemuan 13 — Trees: Binary Tree & Traversal

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Mengapa Tree? Dari Linier ke Hierarkis](#1-mengapa-tree-dari-linier-ke-hierarkis)
2. [Terminologi Tree](#2-terminologi-tree)
3. [Binary Tree: Definisi & Representasi Node](#3-binary-tree-definisi--representasi-node)
4. [Membangun Binary Tree dengan Pointer](#4-membangun-binary-tree-dengan-pointer)
5. [Traversal: Tiga Cara Menjelajah Tree](#5-traversal-tiga-cara-menjelajah-tree)
6. [AI untuk Visualisasi ASCII Art Tree](#6-ai-untuk-visualisasi-ascii-art-tree)

---

## 1. Mengapa Tree? Dari Linier ke Hierarkis

Struktur data yang sudah kita pelajari — array, linked list, stack, queue — bersifat **linier**: satu elemen hanya punya satu penerus.

```
Linked List:  A → B → C → D → NULL
              (setiap node punya 1 penerus)
```

Banyak data di dunia nyata bersifat **hierarkis** — satu entitas punya beberapa anak:

```
Struktur Folder:
  Documents/
  ├── Kuliah/
  │   ├── DSA/
  │   └── Algo/
  └── Pribadi/

Pohon Silsilah:
        Kakek
       /      \
    Ayah      Paman
    /   \
  Anak1  Anak2
```

Untuk memodelkan hubungan seperti ini, kita butuh **Tree (Pohon)** — struktur data non-linier di mana setiap node bisa punya lebih dari satu "penerus" (disebut *child*).

---

## 2. Terminologi Tree

```
              A          ← root (akar): tidak punya parent
            /   \
           B     C       ← internal nodes (punya child)
          / \     \
         D   E     F     ← leaf (daun): tidak punya child

```

| Istilah | Arti |
|---|---|
| **Root** | Node paling atas, tidak punya parent |
| **Parent** | Node di atas yang langsung terhubung |
| **Child** | Node di bawah yang langsung terhubung |
| **Sibling** | Node yang punya parent yang sama |
| **Leaf / Daun** | Node yang tidak punya child |
| **Internal Node** | Node yang punya minimal 1 child |
| **Edge** | Garis penghubung antara dua node |
| **Depth** | Jarak dari root ke node tersebut (root = depth 0) |
| **Height** | Jarak dari node tersebut ke leaf terdalam di bawahnya |
| **Height of Tree** | Height dari root (= kedalaman maksimum tree) |
| **Subtree** | Tree yang dibentuk oleh suatu node beserta semua descendant-nya |

Contoh pada tree di atas:
- Root: A (depth 0)
- B dan C: depth 1
- D, E, F: depth 2 (leaf)
- Height of tree: 2

---

## 3. Binary Tree: Definisi & Representasi Node

**Binary Tree** adalah tree di mana setiap node memiliki **paling banyak 2 child** — disebut *child kiri* dan *child kanan*.

### Representasi Node dalam C

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *kiri;   /* child kiri */
    struct Node *right;  /* child kanan */
} Node;
```

> **Kenapa `struct Node *kiri` bukan hanya `Node *kiri`?**
> Karena di dalam definisi `struct Node`, tipe `Node` belum selesai didefinisikan.
> Kita harus menulis nama struct lengkap: `struct Node *kiri`.
> Setelah `typedef` selesai, kita bisa menggunakan `Node *` di luar definisi struct.

### Membuat Node Baru

```c
Node *buat_node(int nilai) {
    Node *baru = (Node *)malloc(sizeof(Node));
    baru->data  = nilai;
    baru->kiri  = NULL;
    baru->kanan = NULL;
    return baru;
}
```

---

## 4. Membangun Binary Tree dengan Pointer

Kita akan membangun tree berikut secara manual:

```
        1
       / \
      2   3
     / \
    4   5
```

```c
int main() {
    /* Buat semua node */
    Node *root = buat_node(1);
    Node *n2   = buat_node(2);
    Node *n3   = buat_node(3);
    Node *n4   = buat_node(4);
    Node *n5   = buat_node(5);

    /* Sambungkan node */
    root->kiri  = n2;    /* 1's child kiri = 2 */
    root->kanan = n3;    /* 1's child kanan = 3 */
    n2->kiri    = n4;    /* 2's child kiri = 4 */
    n2->kanan   = n5;    /* 2's child kanan = 5 */
    /* n3, n4, n5 tidak punya child → kiri=kanan=NULL (default dari buat_node) */

    /* Tree siap digunakan */
    ...
}
```

Visualisasi pointer:

```
root → [data:1 | kiri:→ | kanan:→]
                  |            |
                  ↓            ↓
             [2|→|→]       [3|NULL|NULL]
               |   |
               ↓   ↓
          [4|N|N] [5|N|N]
```

### Membebaskan Memori

Setelah selesai menggunakan tree, bebaskan memori **dari bawah ke atas** (leaf terlebih dahulu):

```c
void bebaskan_tree(Node *root) {
    if (root == NULL) return;
    bebaskan_tree(root->kiri);    /* bebaskan subtree kiri dulu */
    bebaskan_tree(root->kanan);   /* bebaskan subtree kanan */
    free(root);                   /* baru bebaskan node ini */
}
```

---

## 5. Traversal: Tiga Cara Menjelajah Tree

**Traversal** = proses mengunjungi setiap node dalam tree tepat satu kali.

Ada tiga urutan traversal rekursif yang paling umum:

| Traversal | Urutan | Singkatan |
|---|---|---|
| **Preorder** | Akar → Kiri → Kanan | A K Ka |
| **Inorder** | Kiri → Akar → Kanan | K A Ka |
| **Postorder** | Kiri → Kanan → Akar | K Ka A |

> **Cara mudah menghafal:** posisi "Akar" menentukan nama — **Pre**order = Akar **pertama**, **In**order = Akar **di tengah**, **Post**order = Akar **terakhir**.

### Tree Contoh

```
        1
       / \
      2   3
     / \
    4   5
```

### Preorder (Akar → Kiri → Kanan)

```
kunjungi(1) → rekursi kiri(2) → kunjungi(2) → rekursi kiri(4) → kunjungi(4)
→ rekursi kiri(NULL)=berhenti → rekursi kanan(NULL)=berhenti
→ kembali ke (2) → rekursi kanan(5) → kunjungi(5) → ...
→ kembali ke (1) → rekursi kanan(3) → kunjungi(3)
```

**Hasil preorder: 1 2 4 5 3**

```c
void preorder(Node *node) {
    if (node == NULL) return;   /* base case */
    printf("%d ", node->data);  /* kunjungi Akar */
    preorder(node->kiri);       /* rekursi Kiri */
    preorder(node->kanan);      /* rekursi Kanan */
}
```

### Inorder (Kiri → Akar → Kanan)

```c
void inorder(Node *node) {
    if (node == NULL) return;   /* base case */
    inorder(node->kiri);        /* rekursi Kiri */
    printf("%d ", node->data);  /* kunjungi Akar */
    inorder(node->kanan);       /* rekursi Kanan */
}
```

**Hasil inorder: 4 2 5 1 3**

> **Fakta penting:** Untuk **Binary Search Tree (BST)**, inorder menghasilkan elemen **dalam urutan terurut ascending**. Ini akan sangat berguna di Pertemuan 14!

### Postorder (Kiri → Kanan → Akar)

```c
void postorder(Node *node) {
    if (node == NULL) return;   /* base case */
    postorder(node->kiri);      /* rekursi Kiri */
    postorder(node->kanan);     /* rekursi Kanan */
    printf("%d ", node->data);  /* kunjungi Akar terakhir */
}
```

**Hasil postorder: 4 5 2 3 1**

> **Kegunaan postorder:** root dikunjungi paling akhir, setelah semua anaknya. Ini persis urutan yang benar untuk **membebaskan memori** (fungsi `bebaskan_tree` di atas menggunakan pola postorder!).

### Ringkasan Traversal

```
Tree:
        1
       / \
      2   3
     / \
    4   5

Preorder  (A-K-Ka): 1  2  4  5  3
Inorder   (K-A-Ka): 4  2  5  1  3
Postorder (K-Ka-A): 4  5  2  3  1
```

### Kapan Menggunakan Masing-Masing?

| Traversal | Kegunaan Umum |
|---|---|
| Preorder | Menyalin/mencetak struktur tree; membuat prefix expression |
| Inorder | Menghasilkan data terurut dari BST |
| Postorder | Membebaskan memori; menghitung ukuran; membuat postfix expression |

---

## 6. AI untuk Visualisasi ASCII Art Tree

Saat debugging tree, sulit membayangkan strukturnya hanya dari kode. AI dapat membantu menggambarkan tree sebagai **ASCII art** berdasarkan deskripsi kita.

### Prompt Meminta ASCII Art

```
Aku punya binary tree dengan struktur berikut (dibuat manual di C):
- root = 1
- root->kiri = 2, root->kanan = 3
- 2->kiri = 4, 2->kanan = 5
- 3 adalah leaf
- 4 dan 5 adalah leaf

Gambarkan tree ini sebagai ASCII art. Lalu, tuliskan hasil traversal preorder, inorder, dan postorder-nya.
```

### Validasi Output AI

Setelah AI memberikan ASCII art dan traversal, verifikasi dengan menjalankan kode kamu:

```c
printf("Preorder : "); preorder(root); printf("\n");
printf("Inorder  : "); inorder(root);  printf("\n");
printf("Postorder: "); postorder(root); printf("\n");
```

Output program harus cocok dengan jawaban AI. Jika tidak cocok, cek apakah:
- [ ] Ada node yang sambungannya salah (`->kiri` vs `->kanan` tertukar)?
- [ ] Base case `if (node == NULL) return` sudah ada?
- [ ] Urutan print vs rekursi sudah sesuai (Preorder: print dulu, baru rekursi)?

### Prompt Debugging

```
Preorder tree saya menghasilkan: 1 3 2 4 5
Tapi seharusnya: 1 2 4 5 3
Ini kode fungsi preorder saya:
[tempelkan kode]
Apa yang salah?
```
