# Pertemuan 6 — Linked List (Single)

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Mengapa Linked List?](#1-mengapa-linked-list)
2. [Anatomi Node & Head](#2-anatomi-node--head)
3. [Membuat Node & Menyambung Rantai](#3-membuat-node--menyambung-rantai)
4. [Traverse: Menelusuri List](#4-traverse-menelusuri-list)
5. [Insert: Menyisipkan Node](#5-insert-menyisipkan-node)
6. [Delete: Menghapus Node](#6-delete-menghapus-node)
7. [AI untuk Visualisasi & Debugging](#7-ai-untuk-visualisasi--debugging)

---

## 1. Mengapa Linked List?

Array sangat berguna, tapi punya keterbatasan:

| Masalah Array | Penjelasan |
|---|---|
| Ukuran tetap | Saat deklarasi, kamu harus tahu berapa elemen yang dibutuhkan |
| Insert/delete di tengah mahal | Harus menggeser semua elemen di belakangnya |
| Ukuran tidak bisa dikecilkan | Memori yang sudah dialokasi tidak bisa dikembalikan |

**Linked list** menyelesaikan masalah-masalah ini dengan cara yang berbeda: alih-alih menyimpan semua elemen dalam blok memori yang berurutan, setiap elemen berdiri sendiri di memori dan **saling terhubung lewat pointer**.

### Perbandingan Array vs Linked List

| Aspek | Array | Linked List |
|---|---|---|
| Ukuran | Tetap saat deklarasi | Dinamis — bisa bertambah/berkurang |
| Akses elemen | O(1) — langsung via indeks | O(n) — harus jalan dari head |
| Insert/delete di awal | O(n) — geser semua | O(1) — cukup ubah pointer |
| Insert/delete di tengah | O(n) — geser | O(n) — jalan ke posisi, tapi tidak geser |
| Memori | Efisien, blok berurutan | Ada overhead pointer per node |

> Tidak ada yang selalu lebih baik. Pilih array kalau akses random sering diperlukan; pilih linked list kalau insert/delete di awal/akhir lebih dominan.

---

## 2. Anatomi Node & Head

### Node

Setiap elemen dalam linked list disebut **node**. Satu node menyimpan dua hal:
1. **Data** — nilai yang ingin disimpan (angka, string, struct, dll.)
2. **Pointer `next`** — alamat node berikutnya dalam rantai

```c
struct Node {
    int data;           /* nilai yang disimpan */
    struct Node *next;  /* pointer ke node berikutnya */
};
```

> Perhatikan: `struct Node *next` mereferensikan tipe `struct Node` di dalam definisi `struct Node` sendiri. Ini disebut **self-referential struct** dan legal di C.

Visualisasi satu node:
```
┌──────────┬──────────┐
│  data    │   next   │
│  (int)   │ (pointer)│
└──────────┴──────────┘
```

### Rantai Node (Linked List)

Beberapa node yang disambungkan lewat pointer `next` membentuk linked list:

```
head
 │
 ▼
┌──────┬────┐    ┌──────┬────┐    ┌──────┬──────┐
│  10  │  ──┼───►│  20  │  ──┼───►│  30  │ NULL │
└──────┴────┘    └──────┴────┘    └──────┴──────┘
```

- `head` adalah pointer yang selalu menunjuk ke node **pertama** dalam list.
- Node terakhir memiliki `next = NULL` — penanda bahwa rantai telah berakhir.
- Kalau `head == NULL`, berarti list **kosong**.

### typedef untuk Node

Agar lebih ringkas, gunakan `typedef`. Karena struct Node mereferensikan dirinya sendiri, kita harus memberi nama pada struct-nya:

```c
typedef struct Node {
    int data;
    struct Node *next;  /* harus pakai "struct Node", bukan hanya "Node" */
} Node;
```

Setelah ini, kamu bisa menulis `Node *` daripada `struct Node *`.

---

## 3. Membuat Node & Menyambung Rantai

### Membuat Satu Node Baru

Node dialokasikan di heap (memori dinamis) menggunakan `malloc`:

```c
#include <stdio.h>
#include <stdlib.h>  /* untuk malloc dan free */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Membuat node baru dengan data tertentu */
Node *buat_node(int data) {
    Node *node_baru = (Node *) malloc(sizeof(Node));

    /* malloc bisa gagal (return NULL) jika memori habis */
    if (node_baru == NULL) {
        printf("Error: alokasi memori gagal!\n");
        exit(1);
    }

    node_baru->data = data;    /* isi data */
    node_baru->next = NULL;    /* belum disambungkan ke mana-mana */

    return node_baru;
}
```

> `sizeof(Node)` memberitahu `malloc` berapa byte yang dibutuhkan untuk satu node. Cast `(Node *)` mengubah pointer `void *` yang dikembalikan `malloc` menjadi `Node *`.

### Menyambung Beberapa Node Secara Manual

```c
int main() {
    Node *head = NULL;   /* list kosong */

    /* buat tiga node */
    Node *n1 = buat_node(10);
    Node *n2 = buat_node(20);
    Node *n3 = buat_node(30);

    /* sambungkan: 10 -> 20 -> 30 -> NULL */
    n1->next = n2;
    n2->next = n3;
    /* n3->next sudah NULL dari buat_node */

    head = n1;   /* head menunjuk ke node pertama */

    return 0;
}
```

Visualisasi setelah disambungkan:
```
head
 │
 ▼
[10|─────]──►[20|─────]──►[30|NULL]
```

---

## 4. Traverse: Menelusuri List

Untuk mengakses semua node, mulai dari `head` dan ikuti pointer `next` sampai bertemu `NULL`.

```c
void tampilkan_list(Node *head) {
    Node *saat_ini = head;   /* mulai dari head, jangan ubah head aslinya */

    printf("List: ");

    while (saat_ini != NULL) {
        printf("%d", saat_ini->data);

        if (saat_ini->next != NULL) {
            printf(" -> ");
        }

        saat_ini = saat_ini->next;   /* maju ke node berikutnya */
    }

    printf("\n");
}
```

> **Penting:** Gunakan variabel sementara (`saat_ini`) untuk traversal — **jangan** mengubah `head`. Kalau `head` bergeser, kamu kehilangan akses ke awal list selamanya.

### Contoh Penggunaan

```c
int main() {
    Node *head = NULL;

    Node *n1 = buat_node(10);
    Node *n2 = buat_node(20);
    Node *n3 = buat_node(30);
    n1->next = n2;
    n2->next = n3;
    head = n1;

    tampilkan_list(head);  /* Output: List: 10 -> 20 -> 30 */

    return 0;
}
```

---

## 5. Insert: Menyisipkan Node

### Insert di Depan (Head)

Tambahkan node baru sebelum head saat ini. Urutan langkah **sangat penting**:

```
Sebelum: head ──► [10] ──► [20] ──► NULL
Sesudah: head ──► [5] ──► [10] ──► [20] ──► NULL
```

```c
void insert_depan(Node **head, int data) {
    Node *node_baru = buat_node(data);

    node_baru->next = *head;   /* langkah 1: sambungkan node_baru ke head lama */
    *head = node_baru;         /* langkah 2: pindahkan head ke node_baru */
}
```

> `Node **head` — pointer ke pointer. Kita perlu mengubah nilai `head` di fungsi pemanggil, jadi harus dikirim via pointer (double pointer). Ini setara dengan "pass by reference" untuk pointer.

### Insert di Belakang (Tail)

Tambahkan node baru setelah node terakhir:

```
Sebelum: head ──► [10] ──► [20] ──► NULL
Sesudah: head ──► [10] ──► [20] ──► [30] ──► NULL
```

```c
void insert_belakang(Node **head, int data) {
    Node *node_baru = buat_node(data);

    /* kasus khusus: list kosong */
    if (*head == NULL) {
        *head = node_baru;
        return;
    }

    /* jalan sampai node terakhir */
    Node *saat_ini = *head;
    while (saat_ini->next != NULL) {
        saat_ini = saat_ini->next;
    }

    saat_ini->next = node_baru;   /* sambungkan node terakhir ke node baru */
}
```

### Insert di Posisi Tertentu

Sisipkan node baru di posisi ke-`posisi` (dimulai dari 0).

```
Sebelum: head ──► [10] ──► [30] ──► NULL
Insert 20 di posisi 1:
Sesudah: head ──► [10] ──► [20] ──► [30] ──► NULL
```

```c
void insert_posisi(Node **head, int data, int posisi) {
    /* posisi 0 = insert di depan */
    if (posisi == 0) {
        insert_depan(head, data);
        return;
    }

    Node *node_baru = buat_node(data);
    Node *saat_ini = *head;

    /* jalan ke node di posisi (posisi - 1) */
    for (int i = 0; i < posisi - 1; i++) {
        if (saat_ini == NULL) {
            printf("Posisi %d melebihi panjang list.\n", posisi);
            free(node_baru);   /* batalkan — kembalikan memori */
            return;
        }
        saat_ini = saat_ini->next;
    }

    /* sisipkan node_baru di antara saat_ini dan saat_ini->next */
    node_baru->next = saat_ini->next;   /* langkah 1: sambung ke node setelahnya */
    saat_ini->next = node_baru;         /* langkah 2: sambung node sebelumnya ke node_baru */
}
```

> ⚠️ **Urutan dua langkah terakhir tidak boleh terbalik.** Kalau `saat_ini->next = node_baru` dilakukan dulu, kamu kehilangan referensi ke node yang seharusnya jadi `node_baru->next`.

---

## 6. Delete: Menghapus Node

Menghapus node melibatkan tiga langkah:
1. Temukan node yang ingin dihapus.
2. Sambungkan node sebelumnya langsung ke node sesudahnya (lewati node yang dihapus).
3. `free` node yang dihapus agar memorinya kembali ke sistem.

### Delete Node Berdasarkan Nilai

```c
void delete_node(Node **head, int target) {
    /* list kosong */
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    /* kasus khusus: node yang dihapus adalah head */
    if ((*head)->data == target) {
        Node *akan_dihapus = *head;
        *head = (*head)->next;   /* pindahkan head ke node berikutnya */
        free(akan_dihapus);      /* bebaskan memori */
        return;
    }

    /* cari node sebelum target */
    Node *saat_ini = *head;
    while (saat_ini->next != NULL && saat_ini->next->data != target) {
        saat_ini = saat_ini->next;
    }

    /* target tidak ditemukan */
    if (saat_ini->next == NULL) {
        printf("Nilai %d tidak ditemukan.\n", target);
        return;
    }

    /* hapus node target */
    Node *akan_dihapus = saat_ini->next;
    saat_ini->next = akan_dihapus->next;   /* lewati node yang dihapus */
    free(akan_dihapus);                    /* bebaskan memori */
}
```

Visualisasi proses delete (hapus node `20`):
```
Sebelum:
saat_ini         akan_dihapus
   │                  │
   ▼                  ▼
[10|─]──►[20|─]──►[30|NULL]

Langkah: saat_ini->next = akan_dihapus->next
          free(akan_dihapus)

Sesudah:
[10|─────────────]──►[30|NULL]
```

### Fungsi Pembersihan: Free Semua Node

Ketika program selesai atau list tidak dibutuhkan lagi, bebaskan semua node untuk mencegah memory leak:

```c
void bebaskan_list(Node **head) {
    Node *saat_ini = *head;

    while (saat_ini != NULL) {
        Node *berikutnya = saat_ini->next;   /* simpan dulu referensi ke depan */
        free(saat_ini);                       /* baru free node ini */
        saat_ini = berikutnya;
    }

    *head = NULL;   /* set head ke NULL setelah semua node dibebaskan */
}
```

> Simpan `saat_ini->next` ke variabel sementara **sebelum** `free(saat_ini)`. Setelah `free`, memori node tersebut tidak valid lagi — mengakses `saat_ini->next` setelah `free` adalah **undefined behavior**.

---

## 7. AI untuk Visualisasi & Debugging

### Meminta AI Memvisualisasikan Rantai Node

Ketika mengerjakan linked list, sulit membayangkan kondisi pointer di setiap langkah. AI bisa membantu membuat visualisasi teks.

**Contoh prompt:**

```
Aku punya single linked list dengan head menunjuk ke [10 -> 20 -> 30 -> NULL].
Tunjukkan langkah demi langkah proses insert_depan(5):
- Gambarkan kondisi pointer sebelum, saat proses, dan sesudah.
- Gunakan diagram teks sederhana (ASCII).
```

### Meminta AI Debug Kode Pointer

Kalau ada bug pada kode linked list, AI bisa membantu menemukannya:

**Contoh prompt:**

```
Fungsi insert_belakang di bawah ini seharusnya menambahkan node di akhir list,
tapi ternyata selalu menimpa head. Apa yang salah?

void insert_belakang(Node **head, int data) {
    Node *node_baru = buat_node(data);
    Node *saat_ini = *head;
    while (saat_ini->next != NULL) {
        saat_ini = saat_ini->next;
    }
    saat_ini->next = node_baru;
}
```

### Apa yang Perlu Divalidasi dari Output AI

- [ ] Apakah visualisasi mencerminkan urutan langkah yang benar?
- [ ] Apakah analisis bug menjelaskan *kenapa* terjadi, bukan hanya menunjukkan *apa* yang salah?
- [ ] Apakah kode perbaikan yang disarankan AI bisa dikompilasi dan menghasilkan output yang benar?
- [ ] Apakah edge case (list kosong, hapus head, hapus satu-satunya node) sudah diperhatikan?

> Linked list punya banyak edge case yang halus. AI yang baik seharusnya menyebutkan edge case ini. Kalau tidak disebutkan, tanyakan secara eksplisit: "Bagaimana kalau list-nya kosong?"
