# Pertemuan 14 — Panduan Instruktur

**Topik:** Binary Search Tree (BST)
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + `gcc` berjalan normal di komputer demo.
- [ ] Akun Claude AI aktif untuk demo debugging delete (segmen 95–110).
- [ ] Siapkan spidol 2 warna: satu untuk struktur tree, satu untuk menelusuri jalur insert/search/delete.

### Kode Demo yang Perlu Disiapkan

```c
/* demo_bst.c — BST minimal: insert + search + inorder + delete */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *kiri, *kanan; } Node;
Node *buat_node(int v) { Node *n=malloc(sizeof(Node)); n->data=v; n->kiri=n->kanan=NULL; return n; }
Node *insert(Node *r, int v) { if(!r) return buat_node(v); if(v<r->data) r->kiri=insert(r->kiri,v); else if(v>r->data) r->kanan=insert(r->kanan,v); return r; }
void inorder(Node *n) { if(!n) return; inorder(n->kiri); printf("%d ",n->data); inorder(n->kanan); }
Node *cari_min(Node *n) { while(n->kiri) n=n->kiri; return n; }
Node *del(Node *r, int v) {
    if(!r) return NULL;
    if(v<r->data) r->kiri=del(r->kiri,v);
    else if(v>r->data) r->kanan=del(r->kanan,v);
    else {
        if(!r->kiri){Node*t=r->kanan;free(r);return t;}
        if(!r->kanan){Node*t=r->kiri;free(r);return t;}
        Node *s=cari_min(r->kanan); r->data=s->data; r->kanan=del(r->kanan,s->data);
    }
    return r;
}
int main() {
    Node *root=NULL;
    int a[]={50,30,70,20,40,60,80};
    for(int i=0;i<7;i++) root=insert(root,a[i]);
    printf("Inorder: "); inorder(root); printf("\n");
    root=del(root,30);
    printf("Hapus 30: "); inorder(root); printf("\n");
    return 0;
}
```

---

## B. Catatan Pedagogis

### Sifat BST (Menit 15–35)

**Kaitkan langsung dengan Pertemuan 11 (Binary Search) dan Pertemuan 13 (Binary Tree):**
"Di P11 kita binary search pada array terurut — O(log n). BST menyimpan data dalam struktur yang memungkinkan kita melakukan binary search pada tree — tanpa perlu array."

**Gambar di papan dengan perbandingan eksplisit:**
```
Array terurut: [20, 30, 40, 50, 60, 70, 80]
               Cari 60 → periksa indeks 3(50) → 4(60) → ketemu (2 langkah)

BST setara:        50
                  /  \
                 30   70
                / \  / \
               20 40 60 80
               Cari 60 → 50 → 70 → 60 → ketemu (3 langkah, sama efisiennya)
```

**Tunjukkan kasus tree miring (degenerate BST):**
```
Insert berurutan: 10 → 20 → 30 → 40 → 50

10
  \
   20
     \
      30
        \
         40
           \
            50
```
"Ini BST yang valid, tapi persis seperti linked list. Search jadi O(n)! Inilah mengapa balanced BST (AVL, Red-Black) penting — tapi kita tidak implementasikan sekarang."

### Insert & Search (Menit 35–60)

**Tekankan pola "kembalikan root":**
Ini pola idiomatis BST rekursif di C yang sering membingungkan siswa. Jelaskan kenapa:
```c
root = insert(root, 45);
/* Kenapa tidak cukup: insert(root, 45); ? */
```
Karena jika `root == NULL` (tree kosong), `insert` mengembalikan node baru. Tanpa `root = ...`, variabel `root` di `main` tetap NULL.

### Delete (Menit 60–95)

**Ini segmen terpanjang dan paling sulit — luangkan ekstra waktu.**

**Strategi mengajar: mulai dari yang mudah ke yang sulit:**

1. Kasus 1 (leaf): "Cukup `free` dan kembalikan NULL. Sederhana."
2. Kasus 2 (1 anak): "Bypass node seperti di linked list — child menggantikan parent."
3. Kasus 3 (2 anak): "Tidak bisa langsung dihapus. Kenapa? Karena siapa yang menggantikannya?"

**Untuk kasus 3, gambar langkah demi langkah di papan:**
```
Hapus 50 dari:       50
                    /  \
                   30   70
                        /
                       60
Step 1: Cari inorder successor = min(subtree kanan 50) = 60
Step 2: Salin 60 ke posisi 50 → node "50" sekarang berisi 60
        60
       /  \
      30   70
           /
          60   ← ini yang akan dihapus selanjutnya

Step 3: delete(kanan, 60) → hapus node 60 dari subtree kanan
        60
       /  \
      30   70
```

**Miskonsepsi umum:**
- "Kenapa tidak pakai inorder predecessor (max di subtree kiri)?" → Boleh, sama-sama valid. Konvensi umum menggunakan successor.
- "Kenapa harus copy data, bukan re-link pointer?" → Re-link pointer bisa, tapi jauh lebih rumit karena harus update banyak pointer. Copy data lebih sederhana.

**Demo live "delete tanpa free":**
Tunjukkan bahwa jika `free(root)` dihilangkan, program tetap berjalan tapi ada memory leak. Gunakan Valgrind jika tersedia, atau cukup jelaskan konsepnya.

### Demo AI Debugging (Menit 95–110)

**Buat "bug yang disengaja" terlebih dahulu:**
Ubah `cari_minimum(root->kanan)` menjadi `cari_minimum(root->kiri)` di delete kasus 3, lalu tanya AI:

```
Ini implementasi delete BST saya. Setelah hapus node 50 dari tree:
  50(kiri:30, kanan:70), 30(kiri:20, kanan:40), 70(kiri:60)

Inorder seharusnya: 20 30 40 60 70
Saya dapat: 20 20 40 60 70

Kode delete kasus 3 saya:
  Node *suc = cari_minimum(root->kiri);  /* baris ini salah */
  root->data = suc->data;
  root->kanan = delete_node(root->kanan, suc->data);

Apa yang salah?
```

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Recap traversal inorder dari P13: "Inorder menghasilkan data terurut. Kenapa?"
- "Karena di tree yang kita buat, kiri < akar < kanan — ini sifat BST! Hari ini kita formalisasi dan implementasikan."

### 15–35 | Sifat BST
- Gambar BST + verifikasi invarian di papan.
- Bandingkan dengan binary search di array (P11).
- Tunjukkan kasus tree miring.

### 35–60 | Insert & Search
- Demo live insert bertahap: 50, 30, 70, 20, 40.
- Gambar tree setelah setiap insert.
- Implementasi rekursif — tekankan pola `root = insert(root, v)`.

### 60–95 | Delete (3 Kasus)
- Gambar 3 kasus di papan dengan contoh berbeda.
- Trace manual delete node 2 anak: tunjukkan inorder successor.
- Compile dan jalankan `demo_bst.c`, verifikasi inorder sebelum/sesudah delete.

### 95–110 | Demo AI
- Skenario bug delete yang disengaja.
- Minta AI mendiagnosis dan memperbaiki.
- Validasi perbaikan AI dengan menjalankan kode.

### 110–115 | Latihan Terbimbing
- Siswa kerjakan Task A Soal 1–3 (insert + search + inorder).

### 115–120 | Penutup & Tugas
- Rekap: invarian BST, insert/search O(log n), delete 3 kasus.
- Tugas: selesaikan Task A dan Task B.
- Preview: "Pertemuan 15: Graph — struktur data paling umum di dunia nyata. Peta, jejaring sosial, internet. BFS dan DFS."

---

## D. Kunci Jawaban Task

### Task A (`14_Task_A.c`)

**SOAL 1 — `insert`:**
```c
Node *insert(Node *root, int nilai) {
    if (root == NULL) return buat_node(nilai);
    if (nilai < root->data)      root->kiri  = insert(root->kiri,  nilai);
    else if (nilai > root->data) root->kanan = insert(root->kanan, nilai);
    return root;
}
```

**SOAL 2 — `search`:**
```c
Node *search(Node *root, int target) {
    if (root == NULL) return NULL;
    if (root->data == target) return root;
    if (target < root->data) return search(root->kiri,  target);
    else                     return search(root->kanan, target);
}
```

**SOAL 3 — `inorder`:**
```c
void inorder(Node *node) {
    if (node == NULL) return;
    inorder(node->kiri);
    printf("%d ", node->data);
    inorder(node->kanan);
}
```

**SOAL 4 — `cari_min`:**
```c
int cari_min(Node *root) {
    while (root->kiri != NULL) root = root->kiri;
    return root->data;
}
```

**SOAL 5 — `cari_maks`:**
```c
int cari_maks(Node *root) {
    while (root->kanan != NULL) root = root->kanan;
    return root->data;
}
```

---

### Task B (`14_Task_B.c`)

**SOAL 1 — `cari_minimum` (pointer, bukan int):**
```c
Node *cari_minimum(Node *node) {
    while (node->kiri != NULL) node = node->kiri;
    return node;
}
```

**SOAL 2 — `delete_node`:**
```c
Node *delete_node(Node *root, int nilai) {
    if (root == NULL) return NULL;

    if (nilai < root->data)
        root->kiri  = delete_node(root->kiri,  nilai);
    else if (nilai > root->data)
        root->kanan = delete_node(root->kanan, nilai);
    else {
        /* Kasus 1 & 2: 0 atau 1 anak */
        if (root->kiri == NULL) { Node *t = root->kanan; free(root); return t; }
        if (root->kanan == NULL) { Node *t = root->kiri;  free(root); return t; }
        /* Kasus 3: 2 anak */
        Node *suc  = cari_minimum(root->kanan);
        root->data = suc->data;
        root->kanan = delete_node(root->kanan, suc->data);
    }
    return root;
}
```

**SOAL 3 — `hitung_node`:**
```c
int hitung_node(Node *root) {
    if (root == NULL) return 0;
    return 1 + hitung_node(root->kiri) + hitung_node(root->kanan);
}
```

**SOAL 4 — `is_valid_bst`:**
```c
int is_valid_bst(Node *node, int min, int maks) {
    if (node == NULL) return 1;
    if (node->data <= min || node->data >= maks) return 0;
    return is_valid_bst(node->kiri,  min,        node->data)
        && is_valid_bst(node->kanan, node->data, maks);
}
```

---

## E. Antisipasi Pertanyaan Umum

**"Kenapa BST tidak boleh duplikat?"**
Standarnya BST tidak menyimpan duplikat karena posisi duplikat ambigu (kiri atau kanan?). Jika ingin menyimpan duplikat, perlu pilih konvensi konsisten, misalnya duplikat selalu ke kanan (`>=` daripada `>`). Banyak implementasi mengabaikan duplikat atau menambahkan counter per node.

**"Kenapa inorder successor = minimum di subtree kanan?"**
Inorder successor dari node N adalah node berikutnya dalam inorder traversal — yaitu nilai terkecil yang lebih besar dari N. Di BST, semua nilai yang lebih besar dari N ada di subtree kanan. Yang terkecil di antara mereka adalah node paling kiri di subtree kanan.

**"Apakah `is_valid_bst` bisa diganti dengan cek inorder terurut?"**
Ya — jika inorder menghasilkan urutan ascending, tree adalah BST. Tapi pendekatan `min/max` lebih efisien (O(n) sekali jalan, tanpa alokasi array sementara) dan lebih mudah diimplementasikan rekursif.

**"Kenapa BST bisa O(n) di worst case?"**
Jika kita insert data yang sudah terurut (1, 2, 3, 4, 5...), setiap node hanya punya child kanan — tree menjadi "linked list miring". Semua operasi jadi O(n). Self-balancing BST (AVL Tree, Red-Black Tree) mendeteksi dan memperbaiki ketidakseimbangan ini secara otomatis, menjamin O(log n) di semua kasus.
