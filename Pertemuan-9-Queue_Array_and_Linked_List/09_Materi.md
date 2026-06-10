# Pertemuan 9 — Queue (Array & Linked List)

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Konsep Queue & Prinsip FIFO](#1-konsep-queue--prinsip-fifo)
2. [Operasi Inti Queue](#2-operasi-inti-queue)
3. [Queue Berbasis Array](#3-queue-berbasis-array)
4. [Queue Berbasis Linked List](#4-queue-berbasis-linked-list)
5. [Circular Queue: Solusi Pemborosan Memori](#5-circular-queue-solusi-pemborosan-memori)
6. [AI untuk Validasi Logika Modular](#6-ai-untuk-validasi-logika-modular)

---

## 1. Konsep Queue & Prinsip FIFO

**Queue** (antrian) adalah struktur data di mana elemen yang **pertama dimasukkan** adalah yang **pertama dikeluarkan**. Prinsip ini disebut **FIFO** — *First In, First Out*.

Analogi paling alami: antrian di loket. Orang yang pertama datang dilayani pertama. Orang baru mengantri di belakang, bukan di depan.

```
Enqueue →  [ 30 | 20 | 10 ]  → Dequeue
             (baru)   (lama)
              rear    front
```

**Queue vs Stack:**

| | Stack | Queue |
|---|---|---|
| Prinsip | LIFO — terakhir masuk, pertama keluar | FIFO — pertama masuk, pertama keluar |
| Akses | Satu ujung (top) | Dua ujung (front & rear) |
| Analogi | Tumpukan piring | Antrian loket |

Queue digunakan di mana-mana:
- **CPU scheduling** — proses-proses menunggu giliran dieksekusi.
- **Print queue** — dokumen dicetak sesuai urutan dikirim.
- **BFS (Breadth-First Search)** — algoritma penelusuran graf menggunakan queue.
- **Buffer jaringan** — paket data menunggu dikirim secara berurutan.

---

## 2. Operasi Inti Queue

| Operasi | Deskripsi | Kondisi error |
|---|---|---|
| `enqueue(x)` | Masukkan elemen `x` di bagian belakang (rear) | Queue penuh |
| `dequeue()` | Keluarkan & kembalikan elemen terdepan (front) | Queue kosong |
| `front()` | Baca elemen terdepan *tanpa* mengeluarkannya | Queue kosong |
| `isEmpty()` | Cek apakah queue kosong | — |
| `isFull()` | Cek apakah queue penuh (untuk array) | — |

> Selalu cek `isEmpty` sebelum `dequeue` atau `front`, dan `isFull` sebelum `enqueue`.

---

## 3. Queue Berbasis Array

### Pendekatan Dasar: `front` & `rear`

Gunakan dua indeks:
- **`front`** — indeks elemen terdepan (yang akan di-dequeue berikutnya).
- **`rear`** — indeks elemen terbelakang (tempat enqueue terakhir).

```
Kondisi awal: front = 0, rear = -1 (kosong)
Enqueue 10: rear = 0, data[0] = 10
Enqueue 20: rear = 1, data[1] = 20
Enqueue 30: rear = 2, data[2] = 30

Kondisi: front=0, rear=2
[ 10 | 20 | 30 |  - |  - ]
   ↑               
 front                rear=2

Dequeue → return 10, front = 1
[ 10 | 20 | 30 |  - |  - ]
        ↑
      front=1       rear=2
```

### Masalah: Antrian Semu (False Full)

Setelah beberapa kali dequeue, `front` bergerak ke kanan. Slot di kiri `front` terlihat kosong, tapi kode `isFull` (`rear == KAPASITAS - 1`) tetap menganggap queue penuh — padahal masih ada ruang di kiri!

```
Setelah 2x dequeue + 3x enqueue lagi:
[  - |  - | 30 | 40 | 50 ]
              ↑           ↑
           front=2      rear=4

Enqueue 60 → ERROR: "queue penuh!" padahal slot [0] dan [1] kosong!
```

Solusi naif: geser semua elemen ke kiri setiap dequeue (O(n), tidak efisien). **Solusi yang benar: Circular Queue.**

### Implementasi Queue Array (Dasar)

```c
#include <stdio.h>

#define KAPASITAS 5

typedef struct {
    int data[KAPASITAS];
    int front;
    int rear;
    int ukuran;   /* jumlah elemen saat ini */
} QueueArray;

void init(QueueArray *q) {
    q->front = 0;
    q->rear  = -1;
    q->ukuran = 0;
}

int isEmpty(QueueArray *q) { return q->ukuran == 0; }
int isFull(QueueArray *q)  { return q->ukuran == KAPASITAS; }

void enqueue(QueueArray *q, int x) {
    if (isFull(q)) { printf("Error: queue penuh!\n"); return; }
    q->rear = (q->rear + 1) % KAPASITAS;   /* modulo untuk circular */
    q->data[q->rear] = x;
    q->ukuran++;
}

int dequeue(QueueArray *q) {
    if (isEmpty(q)) { printf("Error: queue kosong!\n"); return -1; }
    int nilai = q->data[q->front];
    q->front = (q->front + 1) % KAPASITAS;  /* modulo untuk circular */
    q->ukuran--;
    return nilai;
}

int front(QueueArray *q) {
    if (isEmpty(q)) { printf("Error: queue kosong!\n"); return -1; }
    return q->data[q->front];
}
```

> Perhatikan: implementasi di atas sudah menggunakan `% KAPASITAS` — ini adalah **circular queue** (dibahas di Bagian 5). Variabel `ukuran` digunakan untuk membedakan kondisi penuh vs kosong.

---

## 4. Queue Berbasis Linked List

Untuk menghindari batasan kapasitas tetap, gunakan linked list. Strategi:
- **Enqueue** → insert di **tail** (belakang).
- **Dequeue** → delete di **head** (depan).

Keduanya O(1) karena kita menjaga pointer `head` (front) dan `tail` (rear).

```
Enqueue 10: head ──► [10|NULL] ◄── tail
Enqueue 20: head ──► [10|──►20|NULL] ◄── tail
Enqueue 30: head ──► [10|──►20|──►30|NULL] ◄── tail

Dequeue → return 10:
          head ──► [20|──►30|NULL] ◄── tail
```

### Implementasi

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;   /* front — dequeue dari sini */
    Node *tail;   /* rear  — enqueue ke sini   */
} QueueLL;

void init_ll(QueueLL *q) {
    q->head = NULL;
    q->tail = NULL;
}

int isEmpty_ll(QueueLL *q) { return q->head == NULL; }

void enqueue_ll(QueueLL *q, int x) {
    Node *node_baru = (Node *) malloc(sizeof(Node));
    if (!node_baru) { printf("Error: malloc gagal!\n"); return; }
    node_baru->data = x;
    node_baru->next = NULL;

    if (q->tail == NULL) {
        /* queue kosong — node baru sekaligus head dan tail */
        q->head = node_baru;
        q->tail = node_baru;
    } else {
        q->tail->next = node_baru;   /* sambungkan ke akhir */
        q->tail = node_baru;         /* pindahkan tail */
    }
}

int dequeue_ll(QueueLL *q) {
    if (isEmpty_ll(q)) { printf("Error: queue kosong!\n"); return -1; }

    Node *akan_dihapus = q->head;
    int nilai = akan_dihapus->data;

    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;  /* queue jadi kosong */

    free(akan_dihapus);
    return nilai;
}

int front_ll(QueueLL *q) {
    if (isEmpty_ll(q)) { printf("Error: queue kosong!\n"); return -1; }
    return q->head->data;
}

void bebaskan_ll(QueueLL *q) {
    while (!isEmpty_ll(q)) dequeue_ll(q);
}
```

### Contoh Penggunaan

```c
int main() {
    QueueLL q;
    init_ll(&q);

    enqueue_ll(&q, 10);
    enqueue_ll(&q, 20);
    enqueue_ll(&q, 30);

    printf("Front : %d\n", front_ll(&q));    /* 10 */
    printf("Dequeue: %d\n", dequeue_ll(&q)); /* 10 */
    printf("Dequeue: %d\n", dequeue_ll(&q)); /* 20 */
    printf("Front : %d\n", front_ll(&q));    /* 30 */

    bebaskan_ll(&q);
    return 0;
}
```

Output:
```
Front : 10
Dequeue: 10
Dequeue: 20
Front : 30
```

---

## 5. Circular Queue: Solusi Pemborosan Memori

### Ide Dasar

Daripada membiarkan slot di kiri `front` terbuang sia-sia, gunakan **indeks melingkar**: setelah mencapai akhir array, indeks kembali ke awal (`0`).

```
Visualisasi melingkar (KAPASITAS = 5):

     [0]
   /     \
 [4]     [1]
   \     /
     [2]
       \
       [3]

front dan rear bergerak searah jarum jam.
Saat rear mencapai [4] dan enqueue lagi → rear kembali ke [0].
```

### Aritmetika Modular

Rumus kunci:
```
rear  baru = (rear  + 1) % KAPASITAS
front baru = (front + 1) % KAPASITAS
```

Contoh dengan `KAPASITAS = 5`:

| `rear` sekarang | `(rear + 1) % 5` |
|---|---|
| 0 | 1 |
| 1 | 2 |
| 3 | 4 |
| 4 | **0** ← melingkar kembali! |

### Membedakan Penuh vs Kosong

Masalah: jika hanya pakai `front` dan `rear`, kondisi penuh (`front == rear + 1`) bisa tertukar dengan kondisi lain. Solusi paling bersih: tambahkan variabel `ukuran`.

```
isEmpty : ukuran == 0
isFull  : ukuran == KAPASITAS
```

### Contoh Circular Queue dalam Aksi

```c
#include <stdio.h>

#define CAP 4

typedef struct {
    int data[CAP];
    int front, rear, ukuran;
} CircularQueue;

void init_cq(CircularQueue *q)    { q->front = 0; q->rear = CAP - 1; q->ukuran = 0; }
int  isEmpty_cq(CircularQueue *q) { return q->ukuran == 0; }
int  isFull_cq(CircularQueue *q)  { return q->ukuran == CAP; }

void enqueue_cq(CircularQueue *q, int x) {
    if (isFull_cq(q))  { printf("Penuh!\n"); return; }
    q->rear = (q->rear + 1) % CAP;
    q->data[q->rear] = x;
    q->ukuran++;
}

int dequeue_cq(CircularQueue *q) {
    if (isEmpty_cq(q)) { printf("Kosong!\n"); return -1; }
    int val = q->data[q->front];
    q->front = (q->front + 1) % CAP;
    q->ukuran--;
    return val;
}

int main() {
    CircularQueue q;
    init_cq(&q);

    enqueue_cq(&q, 10);   /* [10, -, -, -]  front=0 rear=0 */
    enqueue_cq(&q, 20);   /* [10,20, -, -]  front=0 rear=1 */
    enqueue_cq(&q, 30);   /* [10,20,30, -]  front=0 rear=2 */
    enqueue_cq(&q, 40);   /* [10,20,30,40]  front=0 rear=3 — PENUH */

    printf("Dequeue: %d\n", dequeue_cq(&q));  /* 10, front=1 */
    printf("Dequeue: %d\n", dequeue_cq(&q));  /* 20, front=2 */

    enqueue_cq(&q, 50);   /* slot [0] dipakai lagi! rear=(3+1)%4=0 */
    enqueue_cq(&q, 60);   /* slot [1] dipakai lagi! rear=1 */
    /* sekarang: [50,60,30,40] front=2 rear=1 */

    printf("Dequeue: %d\n", dequeue_cq(&q));  /* 30 */
    printf("Dequeue: %d\n", dequeue_cq(&q));  /* 40 */
    printf("Dequeue: %d\n", dequeue_cq(&q));  /* 50 */
    printf("Dequeue: %d\n", dequeue_cq(&q));  /* 60 */

    return 0;
}
```

Output:
```
Dequeue: 10
Dequeue: 20
Dequeue: 30
Dequeue: 40
Dequeue: 50
Dequeue: 60
```

Slot `[0]` dan `[1]` berhasil digunakan kembali — tidak ada pemborosan!

---

## 6. AI untuk Validasi Logika Modular

### Meminta AI Memvalidasi Rumus Circular Queue

Rumus `(index + 1) % size` terlihat sederhana tapi mudah salah di edge case. Minta AI memverifikasi:

```
Aku punya circular queue dengan KAPASITAS = 5.
Validasi apakah rumus ini benar untuk semua kasus:
  rear_baru  = (rear  + 1) % KAPASITAS
  front_baru = (front + 1) % KAPASITAS

Tunjukkan trace untuk skenario:
  1. Enqueue 5x sampai penuh, lalu dequeue 3x, lalu enqueue 3x lagi.
  2. Apakah front atau rear pernah keluar dari rentang [0, KAPASITAS-1]?
```

### Meminta AI Menjelaskan Kondisi Penuh vs Kosong

```
Pada circular queue berkapasitas 4, apa perbedaan antara:
  a. Menggunakan variabel "ukuran" untuk cek penuh/kosong
  b. Menggunakan rumus (front == (rear + 1) % CAP) untuk cek penuh

Berikan kasus di mana pendekatan (b) bisa membingungkan atau salah.
```

### Yang Perlu Divalidasi dari Output AI

- [ ] Apakah indeks `front` dan `rear` selalu dalam rentang `[0, KAPASITAS - 1]`?
- [ ] Apakah kondisi penuh dan kosong dapat dibedakan dengan jelas?
- [ ] Apakah setelah serangkaian enqueue dan dequeue, urutan FIFO tetap terjaga?
- [ ] Compile dan jalankan kode yang disarankan — verifikasi dengan trace manual.

> Aritmetika modular mudah terlihat benar tapi tersembunyi satu kondisi edge yang salah. Selalu uji dengan skenario: (1) enqueue sampai penuh, (2) dequeue sampai kosong, (3) gabungan enqueue & dequeue bergantian.
