# Pertemuan 9 — Optional Task: Queue

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` sendiri sebagai jawabanmu.

---

## Optional Task 1 — Simulasi Antrian Loket (Level: Mudah)

### Latar Belakang

Queue digunakan langsung di kehidupan nyata: antrian bank, antrian loket, antrian kasir. Kamu akan mensimulasikan antrian loket dengan nama pelanggan (string) sebagai data, bukan integer.

### Yang Harus Dibuat

Buat file **`optional1_antrian_loket.c`** yang melakukan hal berikut:

1. Implementasikan Queue Linked List yang menyimpan **nama pelanggan** (string `char[50]`):
   ```c
   typedef struct Node {
       char nama[50];
       struct Node *next;
   } Node;

   typedef struct {
       Node *head;
       Node *tail;
   } QueueLoket;
   ```

2. Implementasikan fungsi-fungsi ini:
   ```c
   void init(QueueLoket *q);
   int  isEmpty(QueueLoket *q);
   void enqueue(QueueLoket *q, const char *nama);
   char *dequeue(QueueLoket *q, char *buffer);  /* salin nama ke buffer, return buffer */
   void tampilkan(QueueLoket *q);
   void bebaskan(QueueLoket *q);
   ```

3. Di `main()`, simulasikan skenario berikut:

   ```
   Pelanggan datang: Andi, Budi, Citra
   Loket melayani   → Andi selesai dilayani
   Pelanggan datang: Dinda
   Loket melayani   → Budi selesai dilayani
   [tampilkan antrian tersisa]
   Loket melayani   → Citra selesai dilayani
   Loket melayani   → Dinda selesai dilayani
   [antrian kosong]
   ```

### Contoh Output

```
Antrian: Andi Budi Citra
Melayani: Andi
Antrian: Budi Citra Dinda
Melayani: Budi
Antrian: Citra Dinda
Melayani: Citra
Melayani: Dinda
Antrian: (kosong)
isEmpty: 1
```

### Petunjuk

- Untuk menyalin string gunakan `strcpy` dari `<string.h>`.
- Saat `enqueue`, salin `nama` ke dalam `node->nama` dengan `strcpy`.
- Saat `dequeue`, salin `node->nama` ke `buffer` sebelum `free(node)`, lalu kembalikan `buffer`.
- Pastikan tidak ada memory leak — panggil `bebaskan` di akhir.

---

## Optional Task 2 — Circular Queue: Deteksi Penuh & Kosong Tanpa Variabel `ukuran` (Level: Menantang)

### Latar Belakang

Di Task A, kita menggunakan variabel `ukuran` untuk membedakan kondisi penuh dan kosong. Ada pendekatan lain: **menyisakan satu slot kosong**. Slot ini tidak pernah diisi, tapi digunakan sebagai penanda.

Aturan:
- **Kosong** jika `front == rear`
- **Penuh** jika `(rear + 1) % KAPASITAS == front`

Karena satu slot tidak pernah diisi, kapasitas efektif = `KAPASITAS - 1`.

### Yang Harus Dibuat

Buat file **`optional2_circular_queue.c`** yang melakukan hal berikut:

1. Implementasikan Circular Queue **tanpa variabel `ukuran`**, menggunakan `KAPASITAS = 6` (kapasitas efektif = 5):
   ```c
   #define KAPASITAS 6

   typedef struct {
       int data[KAPASITAS];
       int front;
       int rear;
   } CircularQueue;
   ```

2. Implementasikan fungsi-fungsi berikut dengan logika penuh/kosong di atas:
   ```c
   void init(CircularQueue *q);          /* front = rear = 0 */
   int  isEmpty(CircularQueue *q);       /* front == rear */
   int  isFull(CircularQueue *q);        /* (rear + 1) % KAPASITAS == front */
   void enqueue(CircularQueue *q, int x);
   int  dequeue(CircularQueue *q);
   int  lihat_depan(CircularQueue *q);
   int  ukuran_antrian(CircularQueue *q); /* hitung tanpa variabel ukuran */
   void tampilkan(CircularQueue *q);
   ```

   Untuk `ukuran_antrian`, gunakan rumus:
   ```
   (rear - front + KAPASITAS) % KAPASITAS
   ```

3. Di `main()`, uji skenario berikut secara berurutan dan verifikasi output:

   | Operasi | Output yang Diharapkan |
   |---|---|
   | `init` | `isEmpty: 1, isFull: 0` |
   | `enqueue(10,20,30,40,50)` | queue penuh (5 elemen dari 5 slot efektif) |
   | `isFull` setelah 5x enqueue | `isFull: 1` |
   | `enqueue(99)` saat penuh | `Error: queue penuh!` |
   | `dequeue` 2x | `10, 20` |
   | `enqueue(60,70)` | berhasil (slot melingkar dipakai kembali) |
   | `tampilkan` | `30 40 50 60 70` |
   | `ukuran_antrian` | `5` |
   | `dequeue` sampai kosong | `30 40 50 60 70` |
   | `isEmpty` | `1` |

### Petunjuk

- `front = rear = 0` sebagai kondisi awal (kosong).
- Saat `enqueue`: `rear = (rear + 1) % KAPASITAS`, lalu isi `data[rear]`.
- Saat `dequeue`: `front = (front + 1) % KAPASITAS`, lalu ambil `data[front]`.
  - Perhatikan: kita `front` bergerak dulu sebelum baca, bukan setelahnya.
  - Ini karena slot `front` awal adalah dummy (kosong).
- Untuk `tampilkan`: mulai dari `(front + 1) % KAPASITAS` sampai `rear` (inklusif), pakai modulo.
- Bandingkan implementasi ini dengan Task A. Pendekatan mana yang lebih mudah dipahami?
