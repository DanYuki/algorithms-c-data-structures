# Pertemuan 9 — Panduan Instruktur

**Topik:** Queue (Array & Linked List)
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + `gcc` berjalan normal di komputer demo.
- [ ] Siapkan folder kerja kosong untuk demo live.
- [ ] Akun Claude AI aktif untuk demo circular queue validation (segmen 80–100).
- [ ] Siapkan properti fisik: antrean fisik bisa disimulasikan dengan 4–5 orang mahasiswa berbaris atau dengan kartu bernomor.

### Kode Demo yang Perlu Disiapkan

```c
/* demo_false_full.c — demonstrasi masalah antrian semu */
#include <stdio.h>
#define CAP 5
int data[CAP];
int front = 0, rear = -1, ukuran = 0;

void enqueue(int x) {
    if (rear == CAP - 1) { printf("PENUH! (padahal front=%d)\n", front); return; }
    data[++rear] = x;
    ukuran++;
}

int dequeue() {
    if (ukuran == 0) return -1;
    ukuran--;
    return data[front++];
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    dequeue(); dequeue();                    /* front geser ke kanan */
    enqueue(40); enqueue(50); enqueue(60);
    enqueue(70);  /* ini harusnya bisa tapi error! */
    return 0;
}
```

---

## B. Catatan Pedagogis

### Konsep Queue & FIFO (Menit 15–30)

**Mulai dengan simulasi fisik — bukan kode:**
Minta 3 mahasiswa berbaris di depan kelas. Mahasiswa ke-4 bergabung di belakang. Lalu panggil mahasiswa terdepan keluar. Ini adalah enqueue dan dequeue yang paling konkret.

**Tekankan perbedaan dari Stack:**
Stack: "yang terakhir masuk, pertama keluar" — seperti tumpukan buku. Queue: "yang pertama datang, pertama dilayani" — seperti antrian kasir. Keduanya membatasi akses, tapi dari ujung yang berbeda.

**Aplikasi nyata yang relevan:**
- CPU scheduling: proses-proses menunggu giliran di queue. Kalau queue tidak digunakan, proses yang terakhir masuk bisa terus "menyelip" ke depan.
- Buffer: paket jaringan, video streaming — semua pakai queue untuk menjaga urutan.

### Masalah False Full (Menit 35–50)

**Ini adalah momen "aha" utama pertemuan ini — jangan lewatkan!**

Demo `demo_false_full.c` di papan atau di layar:
1. Enqueue 3 elemen. Dequeue 2. Sekarang `front = 2`, `rear = 2`.
2. Enqueue 2 lagi: `rear = 4`. Sekarang penuh menurut `rear == CAP - 1`.
3. Tunjukkan: slot `[0]` dan `[1]` kosong tapi tidak bisa dipakai!

Tanya ke kelas: "Apa solusinya?" Tunggu jawaban. Biasanya ada yang menyarankan "geser semua elemen ke kiri". Bahas mengapa itu O(n) dan tidak efisien untuk queue yang sering diakses.

Lalu perkenalkan: "Solusi elegan: aritmetika modular."

### Aritmetika Modular & Circular Queue (Menit 50–75)

**Visualisasi melingkar di papan:**
Gambar 5 kotak dalam lingkaran (seperti jam). Tunjukkan rear bergerak searah jarum jam. Saat mencapai kotak terakhir (indeks 4), `(4+1) % 5 = 0` — kembali ke awal!

**Tunjukkan perhitungan modulo manual:**
```
rear = 4, KAPASITAS = 5
(rear + 1) % KAPASITAS = (4 + 1) % 5 = 5 % 5 = 0  ← kembali ke awal
```

**Variabel `ukuran` vs rumus posisi:**
Tekankan bahwa `ukuran` adalah cara paling bersih untuk membedakan penuh dan kosong. Pendekatan "satu slot kosong" (Optional Task 2) lebih tricky dan mudah salah. Untuk pemula, `ukuran` lebih aman.

### Queue Linked List (Menit 75–95)

**Hubungkan ke Pertemuan 6:**
"Kita sudah tahu insert di head dan insert di belakang. Queue adalah: insert di belakang (tail), delete di depan (head). Kita hanya butuh 2 pointer."

**Jebakan: tail tidak di-reset saat queue kosong:**
Kasus yang sering bikin bug: setelah `dequeue` terakhir, `head = NULL` tapi `tail` masih menunjuk ke node yang sudah di-`free`. Saat `enqueue` berikutnya, `tail->next = node_baru` crash karena `tail` adalah dangling pointer.

Demo bug ini secara live, lalu tunjukkan fix: `if (q->head == NULL) q->tail = NULL`.

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Recap: "Stack = LIFO. Hari ini kita balik aturan: yang pertama masuk, pertama keluar."
- Simulasi fisik dengan mahasiswa berbaris.

### 15–35 | Konsep Queue & Operasi Inti
- FIFO, 5 operasi (enqueue/dequeue/front/isEmpty/isFull).
- Contoh aplikasi nyata.

### 35–55 | Queue Array & False Full
- Demo `demo_false_full.c`.
- Perkenalkan circular queue & modulo.
- Visualisasi melingkar di papan.

### 55–75 | Implementasi Circular Queue
- Ketik implementasi `enqueue` dan `dequeue` dengan modulo dari nol.
- Tunjukkan trace: enqueue 5x, dequeue 2x, enqueue 2x lagi — slot melingkar.

### 75–95 | Queue Linked List
- Hubungkan ke insert tail & delete head dari Pertemuan 6.
- Demo bug `tail` dangling dan solusinya.
- Bandingkan: array (batas tetap, cache-friendly) vs linked list (dinamis, overhead malloc).

### 95–108 | Demo AI
- Demo validasi rumus circular queue dengan AI (skenario trace).
- Siswa coba sendiri: minta AI jelaskan mengapa `(rear - front + CAP) % CAP` menghitung ukuran.

### 108–115 | Latihan Terbimbing
- Siswa kerjakan Task A Soal 1–3 minimal.
- Prioritas: pastikan semua bisa `enqueue` dan `dequeue` dengan modulo.

### 115–120 | Penutup & Tugas
- Rekap: FIFO, false full, solusi circular.
- Tugas: selesaikan Task A dan Task B.
- Preview: "Pertemuan berikutnya: kita akan lihat bagaimana Queue dipakai di algoritma Graph (BFS)."

---

## D. Kunci Jawaban Task

### Task A (`09_Task_A.c`)

**SOAL 1 — `init`:**
```c
void init(QueueArray *q) {
    q->front  = 0;
    q->rear   = KAPASITAS - 1;
    q->ukuran = 0;
}
```

**SOAL 2 — `isEmpty` & `isFull`:**
```c
int isEmpty(QueueArray *q) { return q->ukuran == 0; }
int isFull(QueueArray *q)  { return q->ukuran == KAPASITAS; }
```

**SOAL 3 — `enqueue`:**
```c
void enqueue(QueueArray *q, int x) {
    if (isFull(q)) { printf("Error: queue penuh!\n"); return; }
    q->rear = (q->rear + 1) % KAPASITAS;
    q->data[q->rear] = x;
    q->ukuran++;
}
```

**SOAL 4 — `dequeue`:**
```c
int dequeue(QueueArray *q) {
    if (isEmpty(q)) { printf("Error: queue kosong!\n"); return -1; }
    int nilai = q->data[q->front];
    q->front = (q->front + 1) % KAPASITAS;
    q->ukuran--;
    return nilai;
}
```

**SOAL 5 — `lihat_depan`:**
```c
int lihat_depan(QueueArray *q) {
    if (isEmpty(q)) { printf("Error: queue kosong!\n"); return -1; }
    return q->data[q->front];
}
```

**SOAL 6 — `tampilkan`:**
```c
void tampilkan(QueueArray *q) {
    printf("Queue (depan → belakang): ");
    if (isEmpty(q)) { printf("(kosong)\n"); return; }
    for (int i = 0; i < q->ukuran; i++) {
        printf("%d", q->data[(q->front + i) % KAPASITAS]);
        if (i < q->ukuran - 1) printf(" ");
    }
    printf("\n");
}
```

---

### Task B (`09_Task_B.c`)

**SOAL 1 — `init_ll`:**
```c
void init_ll(QueueLL *q) {
    q->head = NULL;
    q->tail = NULL;
}
```

**SOAL 2 — `isEmpty_ll`:**
```c
int isEmpty_ll(QueueLL *q) { return q->head == NULL; }
```

**SOAL 3 — `enqueue_ll`:**
```c
void enqueue_ll(QueueLL *q, int x) {
    Node *n = (Node *) malloc(sizeof(Node));
    if (!n) { printf("Error: malloc gagal!\n"); return; }
    n->data = x;
    n->next = NULL;
    if (q->tail == NULL) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
}
```

**SOAL 4 — `dequeue_ll`:**
```c
int dequeue_ll(QueueLL *q) {
    if (isEmpty_ll(q)) { printf("Error: queue kosong!\n"); return -1; }
    Node *tmp = q->head;
    int nilai = tmp->data;
    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;   /* penting: reset tail */
    free(tmp);
    return nilai;
}
```

**SOAL 5 — `lihat_depan_ll`:**
```c
int lihat_depan_ll(QueueLL *q) {
    if (isEmpty_ll(q)) { printf("Error: queue kosong!\n"); return -1; }
    return q->head->data;
}
```

**SOAL 6 — `bebaskan_ll`:**
```c
void bebaskan_ll(QueueLL *q) {
    while (!isEmpty_ll(q)) dequeue_ll(q);
}
```

**SOAL 7 — `tampilkan_ll`:**
```c
void tampilkan_ll(QueueLL *q) {
    printf("Queue (depan → belakang): ");
    if (isEmpty_ll(q)) { printf("(kosong)\n"); return; }
    Node *curr = q->head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) printf(" ");
        curr = curr->next;
    }
    printf("\n");
}
```

---

## E. Antisipasi Pertanyaan Umum

**"Kenapa rear diinisialisasi ke `KAPASITAS - 1`, bukan -1 atau 0?"**
Karena saat `enqueue` pertama, kita melakukan `rear = (rear + 1) % KAPASITAS` sebelum mengisi. Kalau `rear = KAPASITAS - 1`, maka `(KAPASITAS - 1 + 1) % KAPASITAS = KAPASITAS % KAPASITAS = 0` — elemen pertama masuk di slot `[0]`, tepat. Kalau `rear = -1`, modulo `-1 + 1 = 0` juga benar, tapi ekspresi `(-1 + 1) % CAP` ada di C di mana `-1 % 5` bisa implementation-defined. `KAPASITAS - 1` lebih aman.

**"Kenapa pakai variabel `ukuran` bukan rumus `(rear - front + CAP) % CAP`?"**
Kedua cara benar. Tapi `ukuran` lebih mudah dibaca dan tidak punya edge case kondisi penuh vs kosong yang ambigu. Rumus modular adalah alternatif valid tapi membutuhkan desain `front`/`rear` yang konsisten (lihat Optional Task 2 untuk pendekatan ini).

**"Apa bedanya Queue Array dan Queue LL dari sisi performa?"**
Operasi enqueue dan dequeue keduanya O(1). Perbedaan: Queue Array lebih cache-friendly (data berurutan di memori), Queue LL punya overhead `malloc`/`free` per elemen. Untuk queue dengan ukuran yang diketahui dan sering diakses, array lebih cepat. Untuk queue yang ukurannya berubah drastis, LL lebih fleksibel.

**"Kenapa di dequeue_ll kita harus reset `tail = NULL` saat head jadi NULL?"**
Karena `tail` masih menunjuk ke node yang baru saja di-`free`. Ini disebut dangling pointer. Jika kita enqueue lagi, kode `q->tail->next = node_baru` akan mencoba mengakses memori yang sudah dibebaskan — undefined behavior, sering crash. Reset `tail = NULL` saat queue kosong memastikan enqueue berikutnya masuk ke cabang `tail == NULL` yang benar.

**"Apakah Queue bisa dipakai untuk graf?"**
Ya! BFS (Breadth-First Search) menggunakan queue secara langsung. Setiap node yang akan dijelajahi di-enqueue. Setelah selesai diproses, node di-dequeue dan semua tetangganya di-enqueue. Ini yang membuat BFS menjelajah graph "lapis per lapis". Topik ini akan dibahas di pertemuan tentang graph.
