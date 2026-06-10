# Pertemuan 8 — Stack (Array & Linked List)

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Konsep Stack & Prinsip LIFO](#1-konsep-stack--prinsip-lifo)
2. [Operasi Inti Stack](#2-operasi-inti-stack)
3. [Stack Berbasis Array](#3-stack-berbasis-array)
4. [Stack Berbasis Linked List](#4-stack-berbasis-linked-list)
5. [Aplikasi: Cek Tanda Kurung Seimbang](#5-aplikasi-cek-tanda-kurung-seimbang)
6. [Pengantar Infix, Postfix & Konversi](#6-pengantar-infix-postfix--konversi)
7. [AI untuk Merumuskan Logika Konversi](#7-ai-untuk-merumuskan-logika-konversi)

---

## 1. Konsep Stack & Prinsip LIFO

**Stack** (tumpukan) adalah struktur data di mana elemen yang **terakhir dimasukkan** adalah yang **pertama dikeluarkan**. Prinsip ini disebut **LIFO** — *Last In, First Out*.

Analogi paling sederhana: tumpukan piring di dapur. Piring yang baru dicuci diletakkan di atas tumpukan. Saat hendak memakai piring, kamu mengambil dari atas — piring terakhir yang diletakkan adalah yang pertama diambil.

```
  Push 30     Push 20     Push 10
              ┌──────┐    ┌──────┐
              │  10  │    │  20  │ ← top
  ┌──────┐    ├──────┤    ├──────┤
  │  30  │    │  30  │    │  10  │
  └──────┘    └──────┘    ├──────┤
                          │  30  │
                          └──────┘
```

Stack digunakan di mana-mana dalam komputasi:
- **Call stack** — program menyimpan posisi "kembali ke mana" setiap kali memanggil fungsi.
- **Tombol Undo** di editor teks — setiap aksi disimpan di stack; Undo = pop.
- **Navigasi browser** — tombol Back mengambil halaman dari stack riwayat.
- **Pengecekan & evaluasi ekspresi** — compiler memakai stack untuk memproses ekspresi matematika.

---

## 2. Operasi Inti Stack

| Operasi | Deskripsi | Kondisi error |
|---------|-----------|---------------|
| `push(x)` | Masukkan elemen `x` ke atas stack | Stack penuh (`isFull`) |
| `pop()` | Keluarkan & kembalikan elemen teratas | Stack kosong (`isEmpty`) |
| `peek()` | Baca elemen teratas *tanpa* mengeluarkannya | Stack kosong |
| `isEmpty()` | Cek apakah stack kosong | — |
| `isFull()` | Cek apakah stack penuh (hanya untuk array) | — |

> Selalu cek `isEmpty` sebelum `pop` atau `peek`, dan `isFull` sebelum `push` (pada implementasi array). Operasi pada stack yang kosong atau penuh adalah **undefined behavior** yang sering menyebabkan crash atau hasil yang salah.

---

## 3. Stack Berbasis Array

Implementasi paling sederhana: gunakan array tetap dan variabel `top` yang menyimpan indeks elemen teratas.

- Saat stack **kosong**: `top = -1`
- Saat **push**: increment `top`, lalu isi `data[top] = x`
- Saat **pop**: baca `data[top]`, lalu decrement `top`

```
Kondisi awal: top = -1 (kosong)
Push 30: top = 0, data[0] = 30
Push 20: top = 1, data[1] = 20
Push 10: top = 2, data[2] = 10
Pop    : return data[2] = 10, top = 1
```

### Implementasi Lengkap

```c
#include <stdio.h>

#define KAPASITAS 5   /* ukuran maksimum stack */

typedef struct {
    int data[KAPASITAS];
    int top;
} StackArray;

/* Inisialisasi stack — set top ke -1 */
void init(StackArray *s) {
    s->top = -1;
}

/* Cek apakah stack kosong */
int isEmpty(StackArray *s) {
    return s->top == -1;
}

/* Cek apakah stack penuh */
int isFull(StackArray *s) {
    return s->top == KAPASITAS - 1;
}

/* Push: masukkan elemen ke stack */
void push(StackArray *s, int x) {
    if (isFull(s)) {
        printf("Error: stack penuh!\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

/* Pop: keluarkan & kembalikan elemen teratas */
int pop(StackArray *s) {
    if (isEmpty(s)) {
        printf("Error: stack kosong!\n");
        return -1;   /* nilai sentinel — tanda error */
    }
    int nilai = s->data[s->top];
    s->top--;
    return nilai;
}

/* Peek: baca elemen teratas tanpa mengeluarkan */
int peek(StackArray *s) {
    if (isEmpty(s)) {
        printf("Error: stack kosong!\n");
        return -1;
    }
    return s->data[s->top];
}
```

### Contoh Penggunaan

```c
int main() {
    StackArray s;
    init(&s);

    push(&s, 30);
    push(&s, 20);
    push(&s, 10);

    printf("Peek: %d\n", peek(&s));    /* 10 */
    printf("Pop : %d\n", pop(&s));     /* 10 */
    printf("Pop : %d\n", pop(&s));     /* 20 */
    printf("Peek: %d\n", peek(&s));    /* 30 */

    return 0;
}
```

Output:
```
Peek: 10
Pop : 10
Pop : 20
Peek: 30
```

### Kelebihan & Kekurangan Stack Array

| | Kelebihan | Kekurangan |
|---|---|---|
| Array | Sederhana, akses O(1) | Ukuran tetap — bisa overflow atau buang memori |

---

## 4. Stack Berbasis Linked List

Untuk menghindari batasan ukuran tetap, stack bisa diimplementasikan dengan linked list. Push dan pop selalu terjadi di **head** — operasi O(1) tanpa perlu tahu panjang list.

```
Push 30:  head ──► [30|NULL]
Push 20:  head ──► [20|──►30|NULL]
Push 10:  head ──► [10|──►20|──►30|NULL]
Pop:      return 10, head ──► [20|──►30|NULL]
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
    Node *top;   /* top menunjuk ke node teratas (head) */
} StackLL;

void init_ll(StackLL *s) {
    s->top = NULL;
}

int isEmpty_ll(StackLL *s) {
    return s->top == NULL;
}

void push_ll(StackLL *s, int x) {
    Node *node_baru = (Node *) malloc(sizeof(Node));
    if (node_baru == NULL) { printf("Error: malloc gagal!\n"); return; }
    node_baru->data = x;
    node_baru->next = s->top;   /* node baru menunjuk ke top lama */
    s->top = node_baru;         /* top sekarang adalah node baru */
}

int pop_ll(StackLL *s) {
    if (isEmpty_ll(s)) {
        printf("Error: stack kosong!\n");
        return -1;
    }
    Node *akan_dihapus = s->top;
    int nilai = akan_dihapus->data;
    s->top = akan_dihapus->next;   /* geser top ke node berikutnya */
    free(akan_dihapus);
    return nilai;
}

int peek_ll(StackLL *s) {
    if (isEmpty_ll(s)) { printf("Error: stack kosong!\n"); return -1; }
    return s->top->data;
}

void bebaskan_ll(StackLL *s) {
    while (!isEmpty_ll(s)) {
        pop_ll(s);   /* pop sekaligus free */
    }
}
```

### Perbandingan Array vs Linked List

| Aspek | Stack Array | Stack Linked List |
|---|---|---|
| Kapasitas | Tetap (`KAPASITAS`) | Dinamis — sebatas RAM |
| Overhead memori | Minimal | Satu pointer per node |
| `isFull` | Perlu dicek | Tidak ada (tidak bisa penuh) |
| Kompleksitas kode | Lebih sederhana | Sedikit lebih banyak |
| Alokasi memori | Stack / bss segment | Heap (malloc/free) |

> **Pilihan praktis:** untuk ukuran yang sudah diketahui dan terbatas → array. Untuk ukuran yang tidak diketahui atau bisa sangat besar → linked list.

---

## 5. Aplikasi: Cek Tanda Kurung Seimbang

Salah satu aplikasi stack yang paling klasik: memeriksa apakah tanda kurung pada sebuah ekspresi seimbang (setiap kurung buka punya pasangan kurung tutup yang tepat).

### Contoh

| Ekspresi | Seimbang? |
|---|---|
| `(a + b) * (c - d)` | ✓ Ya |
| `{[a + b] * (c)}` | ✓ Ya |
| `(a + [b * c)` | ✗ Tidak — kurung tutup `)` tidak cocok dengan `[` |
| `(a + b` | ✗ Tidak — ada kurung buka yang tidak ditutup |
| `a + b)` | ✗ Tidak — pop pada stack kosong |

### Algoritma

1. Telusuri ekspresi karakter per karakter.
2. Jika karakter adalah **kurung buka** (`(`, `[`, `{`) → **push** ke stack.
3. Jika karakter adalah **kurung tutup** (`)`, `]`, `}`) → **pop** dari stack dan cek apakah cocok.
   - Jika stack kosong saat pop → tidak seimbang.
   - Jika kurung tutup tidak cocok dengan yang di-pop → tidak seimbang.
4. Setelah semua karakter selesai: jika stack **kosong** → seimbang; jika ada sisa → tidak seimbang.

### Implementasi

```c
#include <stdio.h>
#include <string.h>

#define KAPASITAS 100

typedef struct {
    char data[KAPASITAS];
    int top;
} StackKarakter;

void init_k(StackKarakter *s)       { s->top = -1; }
int  isEmpty_k(StackKarakter *s)    { return s->top == -1; }
void push_k(StackKarakter *s, char c) {
    if (s->top < KAPASITAS - 1) s->data[++s->top] = c;
}
char pop_k(StackKarakter *s) {
    if (isEmpty_k(s)) return '\0';
    return s->data[s->top--];
}

/* Kembalikan pasangan kurung buka untuk kurung tutup */
char pasangan(char tutup) {
    if (tutup == ')') return '(';
    if (tutup == ']') return '[';
    if (tutup == '}') return '{';
    return '\0';
}

int cek_seimbang(const char *ekspresi) {
    StackKarakter s;
    init_k(&s);

    for (int i = 0; ekspresi[i] != '\0'; i++) {
        char c = ekspresi[i];

        if (c == '(' || c == '[' || c == '{') {
            push_k(&s, c);                 /* kurung buka → simpan */
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty_k(&s)) return 0;   /* tutup tanpa buka → tidak seimbang */
            char buka = pop_k(&s);
            if (buka != pasangan(c)) return 0;  /* pasangan tidak cocok */
        }
    }

    return isEmpty_k(&s);   /* seimbang jika stack kosong di akhir */
}

int main() {
    const char *uji[] = {
        "(a + b) * (c - d)",
        "{[a + b] * (c)}",
        "(a + [b * c)",
        "(a + b",
        "a + b)"
    };
    int n = 5;

    for (int i = 0; i < n; i++) {
        printf("%-25s → %s\n", uji[i],
               cek_seimbang(uji[i]) ? "Seimbang ✓" : "Tidak seimbang ✗");
    }
    return 0;
}
```

Output:
```
(a + b) * (c - d)         → Seimbang ✓
{[a + b] * (c)}           → Seimbang ✓
(a + [b * c)              → Tidak seimbang ✗
(a + b                    → Tidak seimbang ✗
a + b)                    → Tidak seimbang ✗
```

---

## 6. Pengantar Infix, Postfix & Konversi

### Notasi Ekspresi

| Notasi | Letak operator | Contoh |
|---|---|---|
| **Infix** | Di antara operand | `3 + 4 * 2` |
| **Prefix** | Sebelum operand | `+ 3 * 4 2` |
| **Postfix** | Setelah operand | `3 4 2 * +` |

Komputer lebih mudah mengevaluasi **postfix** karena tidak memerlukan aturan prioritas operator — cukup baca kiri ke kanan dan gunakan stack.

### Mengapa Postfix?

Ekspresi infix `3 + 4 * 2` ambigu tanpa aturan prioritas: apakah `(3 + 4) * 2 = 14` atau `3 + (4 * 2) = 11`? Komputer perlu memparsing ekspresi dua kali atau menggunakan tabel prioritas.

Postfix `3 4 2 * +` tidak ambigu — algoritmanya sederhana:
1. Baca `3` → push.
2. Baca `4` → push.
3. Baca `2` → push.
4. Baca `*` → pop `2` dan `4`, hitung `4 * 2 = 8`, push `8`.
5. Baca `+` → pop `8` dan `3`, hitung `3 + 8 = 11`, push `11`.
6. Hasil: `11`.

### Garis Besar Algoritma Infix → Postfix (Shunting-Yard)

Algoritma ini menggunakan **stack untuk operator** dan menghasilkan ekspresi postfix:

1. Untuk setiap token (angka/operator/kurung) dari kiri ke kanan:
   - **Angka/operand** → langsung tambahkan ke output.
   - **Kurung buka `(`** → push ke stack.
   - **Kurung tutup `)`** → pop dan output semua operator sampai bertemu `(`, lalu buang `(`.
   - **Operator** → pop dan output semua operator di stack yang prioritasnya ≥ operator saat ini, lalu push operator saat ini.
2. Di akhir: pop semua sisa operator dari stack ke output.

| Operator | Prioritas |
|---|---|
| `+`, `-` | 1 |
| `*`, `/` | 2 |
| `^` (pangkat) | 3 |

> Detail implementasi konversi infix→postfix adalah materi lanjutan. Bagian berikut menunjukkan bagaimana AI bisa membantu merumuskan logikanya.

---

## 7. AI untuk Merumuskan Logika Konversi

### Meminta AI Menjelaskan Algoritma Langkah demi Langkah

```
Jelaskan algoritma Shunting-Yard untuk konversi infix ke postfix
menggunakan stack. Gunakan ekspresi contoh: "3 + 4 * 2 - 1".

Tunjukkan:
1. Status stack operator pada setiap langkah
2. Output postfix yang terbentuk
3. Kode C sederhana untuk implementasinya
```

### Meminta AI Menguji Kasus Tertentu

```
Dengan algoritma Shunting-Yard, konversikan ekspresi infix berikut ke postfix:
- "a + b * c"
- "(a + b) * c"
- "a * b + c * d"

Tunjukkan kondisi stack dan output setelah memproses setiap token.
```

### Yang Perlu Divalidasi

- [ ] Apakah urutan operand dalam output postfix sudah benar?
- [ ] Apakah prioritas operator sudah ditangani dengan tepat (`*` sebelum `+`)?
- [ ] Apakah kurung buka `(` sudah dibuang dan tidak ikut masuk ke output?
- [ ] Compile dan jalankan kode yang dihasilkan — bandingkan hasil evaluasi postfix dengan hasil infix yang benar.

> Algoritma Shunting-Yard adalah contoh sempurna di mana AI berguna untuk membantu memahami *langkah-langkah algoritma* yang kompleks. Tapi tetap penting untuk menjalankan kode secara manual dengan beberapa contoh — terutama kasus dengan kurung bersarang.
