# Pertemuan 7 — Doubly Linked List

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Dari Single ke Doubly: Apa Bedanya?](#1-dari-single-ke-doubly-apa-bedanya)
2. [Anatomi Node & Struktur Doubly LL](#2-anatomi-node--struktur-doubly-ll)
3. [Insert: Menyisipkan Node](#3-insert-menyisipkan-node)
4. [Traverse: Maju & Mundur](#4-traverse-maju--mundur)
5. [Delete: Menghapus Node](#5-delete-menghapus-node)
6. [Edge Cases & Cara Menanganinya](#6-edge-cases--cara-menanganinya)
7. [AI untuk Generate & Menguji Edge Cases](#7-ai-untuk-generate--menguji-edge-cases)

---

## 1. Dari Single ke Doubly: Apa Bedanya?

Pada Single Linked List, setiap node hanya tahu **siapa yang ada di depannya** (pointer `next`). Kalau kamu sudah berada di node ke-5 dan ingin ke node ke-4, kamu harus mulai lagi dari `head` — tidak bisa mundur.

**Doubly Linked List** menambahkan satu pointer lagi: **`prev`** (previous), yang menunjuk ke node sebelumnya. Sekarang setiap node tahu siapa tetangga kiri dan tetangga kanannya.

```
Single LL:  head ──► [10|next] ──► [20|next] ──► [30|NULL]

Doubly LL:  head                                       tail
              │                                          │
              ▼                                          ▼
         [NULL|10|──]──►[──|20|──]──►[──|30|NULL]
              ◄──────────────◄──────────────◄
```

### Perbandingan

| Aspek | Single LL | Doubly LL |
|---|---|---|
| Pointer per node | 1 (`next`) | 2 (`prev` + `next`) |
| Traversal | Hanya maju | Maju & mundur |
| Insert/delete | Butuh simpan node sebelumnya | Bisa akses langsung via `prev` |
| Memori | Lebih hemat | Sedikit lebih besar |
| Kompleksitas kode | Lebih sederhana | Lebih banyak pointer yang dijaga |

> **Kapan pilih Doubly LL?** Saat kamu butuh navigasi dua arah (mis. tombol Back/Forward di browser), atau delete yang perlu akses ke node sebelumnya secara efisien.

---

## 2. Anatomi Node & Struktur Doubly LL

### Definisi Node

```c
typedef struct Node {
    int data;
    struct Node *prev;   /* pointer ke node sebelumnya */
    struct Node *next;   /* pointer ke node berikutnya */
} Node;
```

### Peran `head` dan `tail`

- **`head`** — pointer ke node pertama. `head->prev == NULL`.
- **`tail`** — pointer ke node terakhir. `tail->next == NULL`.
- List kosong: `head == NULL` dan `tail == NULL`.

Menjaga `tail` opsional (bisa dicari dengan traverse), tapi memiliki `tail` membuat insert di belakang menjadi O(1) alih-alih O(n).

### Visualisasi List `[10 <-> 20 <-> 30]`

```
head                                tail
 │                                    │
 ▼                                    ▼
┌──────┬────┬──────┐   ┌──────┬────┬──────┐   ┌──────┬────┬──────┐
│ NULL │ 10 │  ────┼──►│  ◄───│ 20 │  ────┼──►│  ◄───│ 30 │ NULL │
└──────┴────┴──────┘   └──────┴────┴──────┘   └──────┴────┴──────┘
         ◄──────────────────────◄──────────────────────◄
```

### Fungsi Membuat Node

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *buat_node(int data) {
    Node *node_baru = (Node *) malloc(sizeof(Node));
    if (node_baru == NULL) {
        printf("Error: malloc gagal!\n");
        exit(1);
    }
    node_baru->data = data;
    node_baru->prev = NULL;
    node_baru->next = NULL;
    return node_baru;
}
```

---

## 3. Insert: Menyisipkan Node

Karena ada dua pointer per node, setiap insert harus memperbarui **empat sambungan** (bukan dua seperti di single LL). Urutan langkah sangat penting.

### Insert di Depan

```
Sebelum: head ──► [20 <-> 30] ◄── tail
Sesudah: head ──► [10 <-> 20 <-> 30] ◄── tail
```

```c
void insert_depan(Node **head, Node **tail, int data) {
    Node *node_baru = buat_node(data);

    if (*head == NULL) {
        /* list kosong — node baru sekaligus head dan tail */
        *head = node_baru;
        *tail = node_baru;
        return;
    }

    node_baru->next = *head;      /* langkah 1: hubungkan next node_baru ke head lama */
    (*head)->prev = node_baru;    /* langkah 2: hubungkan prev head lama ke node_baru */
    *head = node_baru;            /* langkah 3: pindahkan head ke node_baru */
}
```

### Insert di Belakang

```
Sebelum: head ──► [10 <-> 20] ◄── tail
Sesudah: head ──► [10 <-> 20 <-> 30] ◄── tail
```

```c
void insert_belakang(Node **head, Node **tail, int data) {
    Node *node_baru = buat_node(data);

    if (*tail == NULL) {
        /* list kosong */
        *head = node_baru;
        *tail = node_baru;
        return;
    }

    node_baru->prev = *tail;      /* langkah 1: hubungkan prev node_baru ke tail lama */
    (*tail)->next = node_baru;    /* langkah 2: hubungkan next tail lama ke node_baru */
    *tail = node_baru;            /* langkah 3: pindahkan tail ke node_baru */
}
```

### Insert di Tengah (Setelah Node Tertentu)

Sisipkan node baru **setelah** `node_sebelum`. Empat sambungan harus diperbarui:

```
Sebelum: ... [A] <-> [C] ...
Sisipkan B setelah A:
Sesudah: ... [A] <-> [B] <-> [C] ...
```

```c
void insert_setelah(Node **tail, Node *node_sebelum, int data) {
    if (node_sebelum == NULL) return;

    Node *node_baru  = buat_node(data);
    Node *node_sesud = node_sebelum->next;  /* simpan referensi ke C */

    node_baru->prev      = node_sebelum;    /* langkah 1: B.prev = A */
    node_baru->next      = node_sesud;      /* langkah 2: B.next = C */
    node_sebelum->next   = node_baru;       /* langkah 3: A.next = B */

    if (node_sesud != NULL) {
        node_sesud->prev = node_baru;       /* langkah 4: C.prev = B */
    } else {
        /* node_baru jadi tail baru karena sisipkan di akhir */
        *tail = node_baru;
    }
}
```

> **Checklist insert:** setelah setiap insert, pastikan:
> - `head->prev == NULL`
> - `tail->next == NULL`
> - Untuk setiap node: `node->next->prev == node` (jika `next` ada)
> - Untuk setiap node: `node->prev->next == node` (jika `prev` ada)

---

## 4. Traverse: Maju & Mundur

### Traverse Maju (head → tail)

```c
void tampilkan_maju(Node *head) {
    Node *saat_ini = head;
    printf("Maju : ");
    while (saat_ini != NULL) {
        printf("%d", saat_ini->data);
        if (saat_ini->next != NULL) printf(" <-> ");
        saat_ini = saat_ini->next;
    }
    printf("\n");
}
```

### Traverse Mundur (tail → head)

```c
void tampilkan_mundur(Node *tail) {
    Node *saat_ini = tail;
    printf("Mundur: ");
    while (saat_ini != NULL) {
        printf("%d", saat_ini->data);
        if (saat_ini->prev != NULL) printf(" <-> ");
        saat_ini = saat_ini->prev;   /* gunakan prev, bukan next */
    }
    printf("\n");
}
```

### Contoh Lengkap

```c
int main() {
    Node *head = NULL, *tail = NULL;

    insert_belakang(&head, &tail, 10);
    insert_belakang(&head, &tail, 20);
    insert_belakang(&head, &tail, 30);

    tampilkan_maju(head);    /* Maju : 10 <-> 20 <-> 30 */
    tampilkan_mundur(tail);  /* Mundur: 30 <-> 20 <-> 10 */

    return 0;
}
```

---

## 5. Delete: Menghapus Node

Menghapus node dari doubly LL membutuhkan pembaruan pointer `prev` **dan** `next` dari tetangga-tetangganya. Empat kasus yang perlu ditangani:

### Fungsi delete_node

```c
void delete_node(Node **head, Node **tail, int target) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    /* cari node target */
    Node *saat_ini = *head;
    while (saat_ini != NULL && saat_ini->data != target) {
        saat_ini = saat_ini->next;
    }

    if (saat_ini == NULL) {
        printf("Nilai %d tidak ditemukan.\n", target);
        return;
    }

    /* perbarui pointer tetangga kiri */
    if (saat_ini->prev != NULL) {
        saat_ini->prev->next = saat_ini->next;
    } else {
        /* tidak ada tetangga kiri → saat_ini adalah head */
        *head = saat_ini->next;
    }

    /* perbarui pointer tetangga kanan */
    if (saat_ini->next != NULL) {
        saat_ini->next->prev = saat_ini->prev;
    } else {
        /* tidak ada tetangga kanan → saat_ini adalah tail */
        *tail = saat_ini->prev;
    }

    free(saat_ini);
}
```

Visualisasi delete node `20` dari `[10 <-> 20 <-> 30]`:

```
Sebelum:
[10 | ──►20◄── | ──►]   [◄──10 | 20 | 30──►]   [◄──20 | 30 | NULL]

Langkah:
  node_10->next = node_30     (lewati 20 ke kanan)
  node_30->prev = node_10     (lewati 20 ke kiri)
  free(node_20)

Sesudah:
[NULL | 10 | ──►30]   [◄──10 | 30 | NULL]
```

### Fungsi Bebaskan Seluruh List

```c
void bebaskan_list(Node **head, Node **tail) {
    Node *saat_ini = *head;
    while (saat_ini != NULL) {
        Node *berikutnya = saat_ini->next;
        free(saat_ini);
        saat_ini = berikutnya;
    }
    *head = NULL;
    *tail = NULL;
}
```

---

## 6. Edge Cases & Cara Menanganinya

Doubly LL memiliki lebih banyak edge case dibanding single LL karena ada dua pointer yang harus dijaga konsisten di setiap operasi.

| Edge Case | Apa yang terjadi | Cara menangani |
|---|---|---|
| List kosong saat insert | `head` dan `tail` keduanya NULL | Node baru menjadi sekaligus `head` dan `tail` |
| Insert pada list satu node | `head == tail` | Setelah insert, cek ulang `head` dan `tail` |
| Delete satu-satunya node | List menjadi kosong | Set `head = NULL` dan `tail = NULL` |
| Delete head | `head` baru adalah `head->next` | `(*head)->prev = NULL` setelah geser |
| Delete tail | `tail` baru adalah `tail->prev` | `(*tail)->next = NULL` setelah geser |
| Insert setelah tail | Node baru menjadi tail baru | Update `*tail = node_baru` |

> Penyebab bug terbanyak pada doubly LL adalah **lupa memperbarui salah satu dari dua pointer** saat insert atau delete. Biasakan selalu mengecek kedua arah setelah setiap operasi.

---

## 7. AI untuk Generate & Menguji Edge Cases

### Meminta AI Generate Test Case

Ketika kamu sudah menulis fungsi `delete_node`, minta AI membantu mengidentifikasi edge cases yang mungkin terlewat:

```
Aku punya fungsi delete_node untuk doubly linked list:
[paste fungsi kamu]

Buatkan test cases untuk menguji semua edge case yang mungkin:
- list kosong
- list satu elemen
- hapus head
- hapus tail
- hapus node di tengah
- nilai tidak ditemukan

Sertakan kode C untuk setiap test case beserta output yang diharapkan.
```

### Meminta AI Audit Konsistensi Pointer

Setelah serangkaian operasi, minta AI mengecek apakah pointer-pointer masih konsisten:

```
Setelah insert_belakang(10), insert_belakang(20), insert_depan(5),
gambarkan kondisi head, tail, dan setiap node (nilai prev dan next-nya)
dalam doubly linked list. Verifikasi apakah semua pointer konsisten.
```

### Yang Perlu Divalidasi dari Output AI

- [ ] Apakah semua 6 edge case di tabel atas dicakup dalam test cases?
- [ ] Apakah kode yang dihasilkan AI **menggunakan `tail`** dengan benar (bukan hanya `head`)?
- [ ] Apakah `free` dipanggil di semua jalur delete?
- [ ] Compile dan jalankan kode test — apakah output sesuai yang diharapkan AI?

> Edge case pada doubly LL sering terlewat bahkan oleh programmer berpengalaman. Justru inilah kekuatan AI: ia bisa dengan cepat menghasilkan daftar kasus ekstrem yang mungkin tidak terpikirkan saat kamu sedang fokus menulis algoritma utama.
