# Pertemuan 13 — Panduan Instruktur

**Topik:** Trees: Binary Tree & Traversal
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + `gcc` berjalan normal di komputer demo.
- [ ] Akun Claude AI aktif untuk demo ASCII art tree (segmen 95–110).
- [ ] Siapkan spidol 2 warna untuk demo traversal di papan (satu warna untuk arah panah, satu warna untuk urutan kunjungan).

### Kode Demo yang Perlu Disiapkan

```c
/* demo_tree.c — tree kecil untuk demo live */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *kiri, *kanan; } Node;

Node *buat_node(int v) {
    Node *n = malloc(sizeof(Node));
    n->data = v; n->kiri = n->kanan = NULL;
    return n;
}

void preorder (Node *n) { if (!n) return; printf("%d ",n->data); preorder(n->kiri);  preorder(n->kanan); }
void inorder  (Node *n) { if (!n) return; inorder(n->kiri);  printf("%d ",n->data); inorder(n->kanan); }
void postorder(Node *n) { if (!n) return; postorder(n->kiri); postorder(n->kanan); printf("%d ",n->data); }

int main() {
    Node *root = buat_node(1);
    root->kiri = buat_node(2); root->kanan = buat_node(3);
    root->kiri->kiri = buat_node(4); root->kiri->kanan = buat_node(5);
    printf("Pre  : "); preorder(root);  printf("\n");
    printf("In   : "); inorder(root);   printf("\n");
    printf("Post : "); postorder(root); printf("\n");
    return 0;
}
```

---

## B. Catatan Pedagogis

### Dari Linier ke Hierarkis (Menit 15–40)

**Mulai dengan motivasi dunia nyata, bukan abstraksi:**
- "Struktur folder di komputermu adalah tree." Gambar di papan: `Documents/ → Kuliah/ → DSA/`.
- "Silsilah keluarga adalah tree." Gambar dengan nama nyata.
- "Ekspresi matematika `(2 + 3) * (4 - 1)` bisa direpresentasikan sebagai tree."

**Penekanan penting — bedakan heap dari stack:**
Ketika membuat node dengan `malloc`, siswa perlu paham bahwa tree hidup di **heap** (memori dinamis), bukan di stack. Pointer `root` sendiri ada di stack dan menunjuk ke heap.

```
Stack:    root → [alamat X]
Heap:     [X]: data=1, kiri=[Y], kanan=[Z]
          [Y]: data=2, kiri=[P], kanan=[Q]
          ...
```

**Jebakan typedef struct yang sering bikin bingung:**
```c
typedef struct Node {
    int data;
    struct Node *kiri;   /* HARUS struct Node — tidak bisa Node karena belum selesai didefinisikan */
} Node;
```
Demo live: tunjukkan error compiler jika kamu tulis `Node *kiri` di dalam struct sebelum typedef selesai.

### Traversal (Menit 65–95)

**WAJIB: gambar tree di papan dulu, baru kode:**

```
        1
       / \
      2   3
     / \
    4   5
```

**Cara menjelaskan traversal yang efektif — gunakan "tangan":**
Minta siswa membayangkan berjalan di tree dengan aturan: selalu coba belok kiri dulu. Tunjuk setiap node di papan dengan urutan kunjungan.

Untuk **Preorder**: "Kamu baca namamu dulu, baru ajak anak-anakmu."
Untuk **Inorder**: "Kamu tunggu anak kiri selesai, baru kamu muncul, baru anak kanan."
Untuk **Postorder**: "Kamu muncul paling akhir, setelah semua anakmu."

**Trace manual di papan — lakukan pelan-pelan:**

Preorder trace untuk tree di atas:
```
preorder(1): cetak 1 → preorder(2) → ...
  preorder(2): cetak 2 → preorder(4) → ...
    preorder(4): cetak 4 → preorder(NULL) → return
                           preorder(NULL) → return
  (kembali ke 2) → preorder(5) → ...
    preorder(5): cetak 5 → preorder(NULL) → return
                            preorder(NULL) → return
(kembali ke 1) → preorder(3) → ...
  preorder(3): cetak 3 → preorder(NULL) → return
                          preorder(NULL) → return
```
Hasil: **1 2 4 5 3** ✓

**Jembatan ke Pertemuan 14 — tekankan inorder:**
"Perhatikan hasil inorder: 4 2 5 1 3. Angkanya tidak terurut karena tree ini bukan BST. Tapi di Pertemuan berikutnya, kita akan buat Binary Search Tree — dan inorder BST SELALU menghasilkan data terurut ascending. Ini sifat paling penting BST!"

### Demo AI ASCII Art (Menit 95–110)

**Prompt rekomendasi:**
```
Aku punya binary tree di C dengan struktur:
- root = 1
- root->kiri = 2, root->kanan = 3
- 2->kiri = 4, 2->kanan = 5
- 3, 4, 5 adalah leaf

Gambar tree ini sebagai ASCII art yang rapi.
Lalu tuliskan hasil traversal preorder, inorder, dan postorder-nya.
```

**Yang perlu divalidasi setelah AI menjawab:**
Compile dan jalankan `demo_tree.c`. Output program harus cocok persis dengan jawaban AI. Jika tidak cocok → diskusi: di mana AI salah? Di mana kode salah?

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Recap sorting dari P12: "Kita sudah bisa mengurutkan data. Tapi bagaimana kalau datanya bukan flat, tapi hierarkis?"
- Contoh nyata: folder komputer, org chart perusahaan, file system.

### 15–40 | Konsep Tree & Binary Tree
- Demo motivasi folder/silsilah.
- Terminologi di papan: root, child, leaf, depth, height.
- Definisi Binary Tree: maks 2 child.
- Tunjukkan `typedef struct Node` dan kenapa `struct Node *` di dalam struct.

### 40–65 | Membangun Tree
- Demo live `buat_node` dan cara menyambung node.
- Gambar diagram pointer di papan.
- Compile dan tampilkan bahwa tree bisa dibuat.

### 65–95 | Traversal
- Gambar tree di papan, trace 3 traversal manual.
- Preorder, inorder, postorder: implementasi dan output.
- Tekankan base case `NULL` dan hubungan dengan rekursi dari P10.
- Tekankan inorder → jembatan ke BST.

### 95–110 | Demo AI
- Prompt ASCII art tree.
- Bandingkan output AI dengan output program.

### 110–115 | Latihan Terbimbing
- Siswa kerjakan Task A Soal 1–3 minimal (struct + buat_node + preorder).

### 115–120 | Penutup & Tugas
- Rekap: struct Node, 3 traversal, base case NULL.
- Tugas: selesaikan Task A dan Task B.
- Preview: "Pertemuan 14: BST — Binary Search Tree. Kita tambahkan aturan: kiri selalu lebih kecil, kanan selalu lebih besar. Lalu insert, search, dan delete menjadi O(log n)!"

---

## D. Kunci Jawaban Task

### Task A (`13_Task_A.c`)

**SOAL 1 — struct Node:**
```c
typedef struct Node {
    int data;
    struct Node *kiri;
    struct Node *kanan;
} Node;
```

**SOAL 2 — `buat_node`:**
```c
Node *buat_node(int nilai) {
    Node *baru = (Node *)malloc(sizeof(Node));
    baru->data  = nilai;
    baru->kiri  = NULL;
    baru->kanan = NULL;
    return baru;
}
```

**SOAL 3 — `preorder`:**
```c
void preorder(Node *node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->kiri);
    preorder(node->kanan);
}
```

**SOAL 4 — `inorder`:**
```c
void inorder(Node *node) {
    if (node == NULL) return;
    inorder(node->kiri);
    printf("%d ", node->data);
    inorder(node->kanan);
}
```

**SOAL 5 — `postorder`:**
```c
void postorder(Node *node) {
    if (node == NULL) return;
    postorder(node->kiri);
    postorder(node->kanan);
    printf("%d ", node->data);
}
```

**SOAL 6 — `hitung_node`:**
```c
int hitung_node(Node *node) {
    if (node == NULL) return 0;
    return 1 + hitung_node(node->kiri) + hitung_node(node->kanan);
}
```

---

### Task B (`13_Task_B.c`)

**SOAL 1 — `hitung_daun`:**
```c
int hitung_daun(Node *node) {
    if (node == NULL) return 0;
    if (node->kiri == NULL && node->kanan == NULL) return 1;
    return hitung_daun(node->kiri) + hitung_daun(node->kanan);
}
```

**SOAL 2 — `hitung_tinggi`:**
```c
int hitung_tinggi(Node *node) {
    if (node == NULL) return -1;
    int kiri_h  = hitung_tinggi(node->kiri);
    int kanan_h = hitung_tinggi(node->kanan);
    return 1 + (kiri_h > kanan_h ? kiri_h : kanan_h);
}
```

**SOAL 3 — `cari_nilai`:**
```c
int cari_nilai(Node *node, int target) {
    if (node == NULL) return 0;
    if (node->data == target) return 1;
    return cari_nilai(node->kiri, target) || cari_nilai(node->kanan, target);
}
```

**SOAL 4 — `node_di_level`:**
```c
int node_di_level(Node *node, int level) {
    if (node == NULL) return 0;
    if (level == 0) return 1;
    return node_di_level(node->kiri, level - 1)
         + node_di_level(node->kanan, level - 1);
}
```

---

## E. Antisipasi Pertanyaan Umum

**"Kenapa kiri/kanan di dalam struct harus `struct Node *`, bukan `Node *`?"**
Karena saat compiler memproses baris `struct Node *kiri`, definisi `typedef ... Node` belum selesai. Nama `Node` belum dikenal. Nama `struct Node` sudah dikenal begitu kompiler melihat `struct Node {`. Setelah typedef selesai, di luar struct kamu bebas pakai `Node *`.

**"Apa bedanya binary tree dan linked list?"**
Linked list adalah kasus khusus binary tree di mana setiap node hanya punya satu child (misalnya hanya child kanan). Semua linked list adalah binary tree, tapi tidak sebaliknya. Secara konseptual, perbedaan utama adalah linked list selalu linier — ada satu jalur saja dari head ke tail — sedangkan binary tree bisa bercabang.

**"Kenapa height(NULL) = -1, bukan 0?"**
Agar height leaf = 0 (satu node tanpa anak). Jika kita definisikan height(NULL) = 0, maka height leaf = 1 + max(0, 0) = 1, bukan 0. Dengan height(NULL) = -1, height(leaf) = 1 + max(-1, -1) = 0. Ini konvensi yang paling umum dan menghasilkan height = jumlah edge dari node ke leaf terdalam.

**"Kenapa harus `free` dari leaf ke root, bukan root dulu?"**
Jika kamu `free(root)` lebih dulu, pointer ke child kiri dan kanan hilang — kamu tidak bisa lagi mengakses child untuk di-free. Memory leak! Fungsi `bebaskan_tree` menggunakan pola postorder justru karena itu: anak-anak dibebaskan dulu, baru parent-nya.
