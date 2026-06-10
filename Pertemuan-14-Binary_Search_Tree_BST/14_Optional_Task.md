# Pertemuan 14 — Optional Task: Binary Search Tree (BST)

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` sendiri sebagai jawabanmu.

---

## Optional Task 1 — Floor dan Ceiling di BST (Level: Mudah)

### Latar Belakang

Dalam BST, kita bisa memanfaatkan invarian untuk mencari nilai terdekat dari suatu angka secara efisien — tanpa perlu menelusuri semua node.

- **Floor(x)** = nilai terbesar di BST yang **≤ x** (pembulatan ke bawah)
- **Ceiling(x)** = nilai terkecil di BST yang **≥ x** (pembulatan ke atas)

```
BST: 10 20 30 40 50 60 70

floor(35)   = 30  (terbesar yang ≤ 35)
ceiling(35) = 40  (terkecil yang ≥ 35)
floor(40)   = 40  (exact match)
ceiling(40) = 40  (exact match)
floor(5)    = -1  (tidak ada yang ≤ 5)
ceiling(75) = -1  (tidak ada yang ≥ 75)
```

### Yang Harus Dibuat

Buat file **`optional1_floor_ceiling.c`** yang mengimplementasikan:

```c
/*
 * Kembalikan nilai terbesar di BST yang <= target.
 * Kembalikan -1 jika tidak ada.
 *
 * Strategi rekursif:
 *   - Jika node == NULL → return -1 (tidak ada kandidat)
 *   - Jika node->data == target → return node->data (exact match)
 *   - Jika target < node->data → floor pasti ada di kiri (kanan terlalu besar)
 *   - Jika target > node->data → node->data adalah kandidat floor,
 *     tapi mungkin ada yang lebih besar di kanan
 *     → cek kanan; jika ada hasil → pakai itu; jika tidak → pakai node->data
 */
int floor_bst(Node *node, int target);

/*
 * Kembalikan nilai terkecil di BST yang >= target.
 * Kembalikan -1 jika tidak ada.
 *
 * Strategi: cermin dari floor_bst (arah kiri/kanan terbalik).
 */
int ceiling_bst(Node *node, int target);
```

### Contoh Output

```
BST (inorder): 10 20 30 40 50 60 70

floor(35)   = 30
ceiling(35) = 40
floor(40)   = 40
ceiling(40) = 40
floor(5)    = -1
ceiling(75) = -1
floor(70)   = 70
ceiling(10) = 10
```

### Petunjuk

- Untuk `floor_bst`: jika `target > node->data`, simpan `node->data` sebagai kandidat, lalu cek kanan.
  ```c
  int hasil_kanan = floor_bst(node->kanan, target);
  return (hasil_kanan != -1) ? hasil_kanan : node->data;
  ```
- `ceiling_bst` adalah cermin: jika `target < node->data`, simpan `node->data` sebagai kandidat, lalu cek kiri.

---

## Optional Task 2 — Hitung Node dalam Range & Cetak Sorted Slice (Level: Menantang)

### Latar Belakang

Salah satu kekuatan BST adalah kemampuan menjawab pertanyaan *range query* secara efisien — misalnya: "Berapa banyak nilai antara 30 dan 60?" atau "Cetak semua nilai antara 25 dan 65 secara terurut."

Di array biasa ini butuh O(n). Di BST kita bisa memangkas cabang yang pasti di luar range.

### Yang Harus Dibuat

Buat file **`optional2_range_query.c`** yang mengimplementasikan dua fungsi:

#### Bagian 1 — Hitung Node dalam Range `[lo, hi]`

```c
/*
 * Kembalikan jumlah node dengan nilai dalam rentang [lo, hi] (inklusif).
 *
 * Strategi (manfaatkan invarian BST untuk pruning):
 *   - Base case: node == NULL → return 0
 *   - Jika node->data < lo  → hanya cek kanan (kiri pasti lebih kecil dari lo)
 *   - Jika node->data > hi  → hanya cek kiri  (kanan pasti lebih besar dari hi)
 *   - Jika lo <= node->data <= hi:
 *       hitung node ini (1) + rekursi kiri + rekursi kanan
 */
int hitung_range(Node *node, int lo, int hi);
```

#### Bagian 2 — Cetak Semua Nilai dalam Range `[lo, hi]` secara Terurut

```c
/*
 * Cetak semua nilai dalam rentang [lo, hi] dalam urutan ascending.
 * Gunakan pola inorder dengan pruning yang sama.
 *
 * Hint: modifikasi inorder standar:
 *   - Sebelum rekursi kiri: cek apakah node->data > lo (kalau tidak, kiri bisa dilewati)
 *   - Sebelum print: cek apakah lo <= node->data <= hi
 *   - Sebelum rekursi kanan: cek apakah node->data < hi (kalau tidak, kanan bisa dilewati)
 */
void cetak_range(Node *node, int lo, int hi);
```

### BST yang Digunakan

```c
/* Insert: 50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65, 75, 90 */
/*
 * BST yang terbentuk:
 *              50
 *            /    \
 *          30      70
 *         / \     /  \
 *        20  40  60   80
 *       / \   \   \    \
 *      10  25  45  65   90
 *                        \
 *                        75 (jika insert 75 setelah 90... cek strukturnya!)
 */
```

### Contoh Output

```
BST (inorder): 10 20 25 30 40 45 50 60 65 70 75 80 90

hitung_range([30, 65]) = 6    (30, 40, 45, 50, 60, 65)
hitung_range([1,  100])= 13   (semua)
hitung_range([55, 55]) = 0    (55 tidak ada di BST)
hitung_range([60, 60]) = 1    (hanya 60)

cetak_range([30, 65]): 30 40 45 50 60 65
cetak_range([1,  20]): 10 20
cetak_range([70, 90]): 70 75 80 90
```

### Pertanyaan Analisis (tulis sebagai komentar)

1. Apa kompleksitas `hitung_range` dan `cetak_range` dalam BST seimbang?
   (Hint: O(log n + k) di mana k = jumlah node dalam range)
2. Bandingkan dengan melakukan linear scan di linked list untuk range query yang sama.
   Mana yang lebih efisien, dan kapan BST mulai unggul?
