# Pertemuan 6 — Optional Task: Linked List (Single)

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` sendiri sebagai jawabanmu.

---

## Optional Task 1 — Daftar Belanja (Level: Mudah)

### Latar Belakang

Kamu ingin membuat program daftar belanja sederhana menggunakan linked list. Setiap item belanja disimpan sebagai node dalam list, dan kamu bisa menambah serta menghapus item.

### Yang Harus Dibuat

Buat file **`optional1_belanja.c`** yang melakukan hal berikut:

1. Definisikan `typedef struct` bernama `ItemBelanja` sebagai node dengan anggota:
   - `nama_item` — string maksimal 50 karakter
   - `next` — pointer ke `ItemBelanja` berikutnya

2. Buat fungsi-fungsi:
   - `ItemBelanja *buat_item(const char *nama)` — membuat node item baru.
   - `void tambah_item(ItemBelanja **head, const char *nama)` — insert di belakang.
   - `void hapus_item(ItemBelanja **head, const char *nama)` — hapus item pertama yang namanya cocok (gunakan `strcmp`).
   - `void tampilkan_daftar(ItemBelanja *head)` — tampilkan semua item bernomor urut.
   - `void bebaskan_daftar(ItemBelanja **head)` — bebaskan semua node.

3. Di `main()`:
   - Tambahkan 4 item: `"Susu"`, `"Roti"`, `"Telur"`, `"Mentega"`.
   - Tampilkan daftar.
   - Hapus `"Roti"`.
   - Tampilkan daftar lagi.
   - Hapus `"Susu"` (item pertama / head).
   - Tampilkan daftar lagi.

### Contoh Output

```
=== Daftar Belanja ===
1. Susu
2. Roti
3. Telur
4. Mentega

Menghapus "Roti"...
=== Daftar Belanja ===
1. Susu
2. Telur
3. Mentega

Menghapus "Susu"...
=== Daftar Belanja ===
1. Telur
2. Mentega
```

### Petunjuk

- Gunakan `#include <string.h>` untuk `strcpy` dan `strcmp`.
- Untuk `hapus_item`, tangani tiga kasus: list kosong, hapus head, hapus tengah/tail.
- Pastikan memanggil `bebaskan_daftar` di akhir `main()`.

---

## Optional Task 2 — Cari Nilai Minimum & Maksimum (Level: Menantang)

### Latar Belakang

Linked list berisi data angka yang dimasukkan pengguna. Program harus bisa mencari nilai minimum dan maksimum, serta menghapus semua kemunculan nilai tertentu dari list.

### Yang Harus Dibuat

Buat file **`optional2_minmax.c`** yang melakukan hal berikut:

1. Definisikan node integer standar:
   ```c
   typedef struct Node { int data; struct Node *next; } Node;
   ```

2. Buat fungsi-fungsi (selain `buat_node`, `tampilkan_list`, `insert_belakang` yang kamu tulis sendiri):
   - `int cari_minimum(Node *head)` — kembalikan nilai terkecil dalam list. Asumsikan list tidak kosong.
   - `int cari_maksimum(Node *head)` — kembalikan nilai terbesar dalam list.
   - `int hitung_kemunculan(Node *head, int target)` — kembalikan berapa kali `target` muncul dalam list.
   - `void hapus_semua(Node **head, int target)` — hapus **semua** node yang nilainya sama dengan `target` (bukan hanya node pertama).

3. Di `main()`:
   - Buat list: `[5, 3, 8, 3, 1, 9, 3, 6]`.
   - Tampilkan list, cetak nilai minimum dan maksimum.
   - Cetak berapa kali nilai `3` muncul.
   - Hapus semua kemunculan `3`, tampilkan list hasil.

### Contoh Output

```
List awal  : List: 5 -> 3 -> 8 -> 3 -> 1 -> 9 -> 3 -> 6
Minimum    : 1
Maksimum   : 9
Kemunculan 3: 3 kali

Hapus semua nilai 3...
List akhir : List: 5 -> 8 -> 1 -> 9 -> 6
```

### Petunjuk

- `cari_minimum`: inisialisasi `min = head->data`, lalu traverse dan update jika ketemu yang lebih kecil.
- `hapus_semua`: lebih sulit dari `delete_node` biasa karena target bisa muncul berulang dan bisa berturut-turut. Perlu loop yang terus memeriksa `(*head)->data` dan `saat_ini->next->data` selama masih ada yang cocok.
- Tangani kasus khusus di `hapus_semua`: bagaimana kalau beberapa head berturut-turut bernilai `target`?

---

## Optional Task 3 — Membalik Linked List In-Place (Level: Lanjutan)

### Latar Belakang

Membalik urutan linked list adalah operasi klasik yang melatih kemampuan memanipulasi pointer secara mandiri. Tantangannya: lakukan **tanpa membuat list atau node baru** — ubah arah pointer `next` dari setiap node yang sudah ada.

### Yang Harus Dibuat

Buat file **`optional3_reverse.c`** yang melakukan hal berikut:

1. Gunakan definisi node integer standar dan buat fungsi `buat_node`, `tampilkan_list`, `insert_belakang` sendiri.

2. Buat fungsi:
   ```c
   void reverse_list(Node **head);
   ```
   Fungsi ini membalik urutan list **in-place** — tanpa `malloc` tambahan, tanpa membuat list baru. Hanya boleh menggunakan variabel pointer sementara.

3. Di `main()`:
   - Buat list `[1 -> 2 -> 3 -> 4 -> 5]`, tampilkan.
   - Panggil `reverse_list`, tampilkan hasilnya.
   - Uji lagi dengan list satu elemen `[42]` — setelah reverse, hasilnya harus tetap `[42]`.
   - Uji dengan list kosong — program tidak boleh crash.

### Contoh Output

```
=== Uji Reverse ===
Sebelum reverse: List: 1 -> 2 -> 3 -> 4 -> 5
Sesudah reverse: List: 5 -> 4 -> 3 -> 2 -> 1

=== Uji Edge Case: Satu Elemen ===
Sebelum reverse: List: 42
Sesudah reverse: List: 42

=== Uji Edge Case: List Kosong ===
Sebelum reverse: List: (kosong)
Sesudah reverse: List: (kosong)
```

### Petunjuk Algoritma

Gunakan **tiga pointer** yang bergerak maju bersama:

```
prev    curr    berikutnya
NULL    [1]──►[2]──►[3]──►...
```

Pada setiap iterasi:
1. Simpan `berikutnya = curr->next` (jangan sampai kehilangan sisa list).
2. Balik arah: `curr->next = prev`.
3. Geser semua maju: `prev = curr`, `curr = berikutnya`.

Setelah loop, `curr == NULL` dan `prev` menunjuk ke node terakhir (yang sekarang jadi head baru).

Gambarkan proses ini di kertas sebelum mulai koding — ini jauh lebih membantu daripada langsung menulis kode.
