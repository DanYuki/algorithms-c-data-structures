# Pertemuan 8 — Panduan Instruktur

**Topik:** Stack (Array & Linked List)
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + `gcc` berjalan normal di komputer demo.
- [ ] Siapkan folder kerja kosong untuk demo live.
- [ ] Akun Claude AI aktif untuk demo konversi infix→postfix (segmen 80–105).
- [ ] Siapkan properti fisik (opsional tapi sangat efektif): tumpukan kertas/buku untuk visualisasi LIFO.

### Kode Demo yang Perlu Disiapkan

```c
/* demo_stack_array.c — stack array minimal */
#include <stdio.h>
#define CAP 5
int data[CAP], top = -1;
void push(int x) { if (top < CAP-1) data[++top] = x; }
int  pop()       { return top >= 0 ? data[top--] : -1; }
int  peek()      { return top >= 0 ? data[top]   : -1; }
int main() {
    push(30); push(20); push(10);
    printf("Peek: %d\n", peek());   /* 10 */
    printf("Pop : %d\n", pop());    /* 10 */
    printf("Pop : %d\n", pop());    /* 20 */
    printf("Peek: %d\n", peek());   /* 30 */
    return 0;
}
```

---

## B. Catatan Pedagogis

### Konsep Stack & LIFO (Menit 15–35)

**Mulai dengan properti fisik — bukan kode:**
Ambil 3–4 buku/lembar kertas, tumpuk satu per satu sambil sebut "push 30, push 20, push 10". Lalu ambil dari atas sambil sebut "pop → 10, pop → 20". Ini lebih membekas dibanding langsung kode.

**Analogi yang bekerja:**
- Tumpukan piring — paling intuitif.
- Call stack — lebih teknikal: "setiap kali kamu panggil fungsi, komputer `push` alamat 'kembaliknya'. Saat fungsi selesai, `pop` → balik ke caller."
- Undo/Redo di text editor.

**Bedakan stack dari array biasa:**
Array: kamu bisa akses elemen mana saja dengan indeks. Stack: kamu hanya bisa mengakses **satu elemen** — yang paling atas. Ini bukan kelemahan — ini adalah **kontrak** yang memungkinkan jaminan LIFO.

### Stack Berbasis Array (Menit 35–60)

**Visualisasi `top` di papan:**
```
index:  [0]  [1]  [2]  [3]  [4]
data :   30   20   10   -    -
                    ↑
                   top=2
```
Setiap push: `top++` lalu isi. Setiap pop: baca lalu `top--`. Elemen "lama" masih ada di array tapi tidak bisa diakses karena `top` sudah mundur.

**Miskonsepsi: "pop menghapus data dari memori"**
Tidak — `pop` hanya menurunkan `top`. Data lama masih ada di array tapi dianggap tidak ada oleh stack. Ini penting saat debugging — jangan kaget kalau melihat data "sisa" di memori.

**Kenapa `top = -1` dan bukan 0?**
Karena indeks 0 adalah posisi elemen pertama yang valid. Kalau `top = 0` untuk kosong, kita tidak bisa membedakan "kosong" dengan "ada satu elemen di indeks 0". `top = -1` adalah sentinel yang jelas: tidak ada elemen.

### Stack Berbasis Linked List (Menit 60–80)

**Push = insert di head, Pop = delete head:**
Hubungkan langsung ke materi Pertemuan 6. Siswa yang sudah paham insert/delete head di linked list akan langsung mengerti ini.

**Mengapa push/pop di head, bukan di tail?**
Karena push/pop di head = O(1). Push/pop di tail = O(n) (harus jalan ke ujung untuk pop). Stack harus O(1) untuk semua operasi intinya.

**Perbandingan yang perlu ditekankan:**
- Array: kode lebih sederhana, tapi bisa `stack overflow` atau buang memori.
- Linked list: fleksibel, tapi ada overhead `malloc`/`free` setiap push/pop.
- Di sistem embedded (RAM terbatas), stack array lebih aman karena ukurannya dapat diprediksi.

### Aplikasi: Cek Kurung & Infix→Postfix (Menit 80–105)

**Demo cek kurung — trace manual dulu:**
Sebelum kode, telusuri `"(a + [b * c)"` langkah demi langkah di papan:
```
( → push: stack = ['(']
a → skip
+ → skip
[ → push: stack = ['(', '[']
b → skip
* → skip
c → skip
) → pop → '[' ≠ ')' → TIDAK SEIMBANG
```
Ini membuat algoritma terasa nyata sebelum siswa melihat kode.

**Infix→Postfix — jangan rush:**
Algoritma Shunting-Yard adalah topik yang berat. Tujuan di sesi ini bukan agar siswa bisa mengimplementasikannya secara mandiri, tapi agar mereka:
1. Paham **mengapa** stack diperlukan (menyimpan operator yang menunggu).
2. Bisa membaca dan memvalidasi kode yang dihasilkan AI.

**Alur demo AI (menit 80–105):**
1. Tuliskan ekspresi `3 + 4 * 2` di papan. Tanya: "Bagaimana komputer tahu `*` harus dihitung dulu?"
2. Perkenalkan postfix sebagai solusi: `3 4 2 * +`.
3. Minta AI menjelaskan Shunting-Yard dengan contoh token per token.
4. Minta AI generate kode C.
5. **Review bersama siswa:** apakah tabel prioritas benar? Apakah kurung ditangani?
6. Compile dan uji.

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Recap: "Di doubly LL, kita bisa navigasi dua arah. Sekarang kita batasi akses: hanya satu ujung. Hasilnya lebih sederhana tapi sangat powerful."

### 15–35 | Konsep Stack
- Demo fisik dengan buku/kertas.
- Perkenalkan 5 operasi + LIFO.
- Contoh aplikasi (call stack, undo, browser back).

### 35–60 | Stack Array
- Visualisasi `top` di papan.
- Ketik `demo_stack_array.c` dari nol.
- Tunjukkan bug umum: push tanpa cek `isFull`, pop tanpa cek `isEmpty`.

### 60–80 | Stack Linked List
- Hubungkan ke materi Pertemuan 6 (insert/delete head).
- Demo — tekankan push = insert head, pop = delete head.
- Bandingkan keduanya.

### 80–105 | Aplikasi
- Trace manual cek kurung di papan, lalu tunjukkan kode.
- Demo infix→postfix dengan AI seperti panduan di atas.
- Siswa mencoba minta AI menjelaskan kasus ekspresi mereka sendiri.

### 105–115 | Latihan Terbimbing
- Siswa kerjakan Task A (Soal 1–3 minimal) atau Task B.
- Fokus: pastikan semua bisa push dan pop dengan benar.

### 115–120 | Penutup & Tugas
- Rekap: LIFO, dua implementasi, cek kurung sebagai aplikasi nyata.
- Tugas: selesaikan Task A dan Task B.
- Preview: "Pertemuan 9: Queue — mirip Stack tapi FIFO. Ada satu lagi ujung yang bisa diakses."

---

## D. Kunci Jawaban Task

### Task A (`08_Task_A.c`)

**SOAL 1 — `init`:**
```c
void init(StackArray *s) {
    s->top = -1;
}
```

**SOAL 2 — `isEmpty` & `isFull`:**
```c
int isEmpty(StackArray *s) { return s->top == -1; }
int isFull(StackArray *s)  { return s->top == KAPASITAS - 1; }
```

**SOAL 3 — `push`:**
```c
void push(StackArray *s, int x) {
    if (isFull(s)) { printf("Error: stack penuh!\n"); return; }
    s->top++;
    s->data[s->top] = x;
}
```

**SOAL 4 — `pop`:**
```c
int pop(StackArray *s) {
    if (isEmpty(s)) { printf("Error: stack kosong!\n"); return -1; }
    int nilai = s->data[s->top];
    s->top--;
    return nilai;
}
```

**SOAL 5 — `peek`:**
```c
int peek(StackArray *s) {
    if (isEmpty(s)) { printf("Error: stack kosong!\n"); return -1; }
    return s->data[s->top];
}
```

**SOAL 6 — `tampilkan`:**
```c
void tampilkan(StackArray *s) {
    printf("Stack (top → bottom): ");
    if (isEmpty(s)) { printf("(kosong)\n"); return; }
    for (int i = s->top; i >= 0; i--) {
        printf("%d", s->data[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}
```

### Task B (`08_Task_B.c`)

**SOAL 1–2:**
```c
void init_ll(StackLL *s)    { s->top = NULL; }
int  isEmpty_ll(StackLL *s) { return s->top == NULL; }
```

**SOAL 3 — `push_ll`:**
```c
void push_ll(StackLL *s, char c) {
    Node *n = (Node *) malloc(sizeof(Node));
    if (!n) { printf("Error: malloc gagal!\n"); return; }
    n->data = c;
    n->next = s->top;
    s->top = n;
}
```

**SOAL 4 — `pop_ll`:**
```c
char pop_ll(StackLL *s) {
    if (isEmpty_ll(s)) { printf("Error: stack kosong!\n"); return '\0'; }
    Node *tmp = s->top;
    char val = tmp->data;
    s->top = tmp->next;
    free(tmp);
    return val;
}
```

**SOAL 5 — `peek_ll`:**
```c
char peek_ll(StackLL *s) {
    if (isEmpty_ll(s)) return '\0';
    return s->top->data;
}
```

**SOAL 6 — `bebaskan_ll`:**
```c
void bebaskan_ll(StackLL *s) {
    while (!isEmpty_ll(s)) pop_ll(s);
}
```

**SOAL 7 — `cek_seimbang`:**
```c
char pasangan(char tutup) {
    if (tutup == ')') return '(';
    if (tutup == ']') return '[';
    if (tutup == '}') return '{';
    return '\0';
}

int cek_seimbang(const char *ekspresi) {
    StackLL s;
    init_ll(&s);
    for (int i = 0; ekspresi[i] != '\0'; i++) {
        char c = ekspresi[i];
        if (c=='(' || c=='[' || c=='{') {
            push_ll(&s, c);
        } else if (c==')' || c==']' || c=='}') {
            if (isEmpty_ll(&s)) { bebaskan_ll(&s); return 0; }
            char buka = pop_ll(&s);
            if (buka != pasangan(c)) { bebaskan_ll(&s); return 0; }
        }
    }
    int hasil = isEmpty_ll(&s);
    bebaskan_ll(&s);
    return hasil;
}
```

---

## E. Antisipasi Pertanyaan Umum

**"Kenapa `top` dimulai dari -1 dan bukan 0?"**
Indeks -1 berarti "tidak ada elemen" — tidak ada indeks array yang valid bernilai -1. Kalau `top = 0` berarti kosong, kita tidak bisa membedakan stack kosong dengan stack berisi satu elemen di indeks 0. Nilai -1 adalah *sentinel* yang jelas.

**"Apa bedanya stack array dan stack linked list dalam hal performa?"**
Keduanya O(1) untuk push dan pop. Tapi stack array lebih *cache-friendly* (data berurutan di memori) dan tidak punya overhead `malloc`/`free`. Stack linked list lebih fleksibel tapi setiap push/pop memanggil `malloc`/`free` yang relatif lambat. Untuk jumlah push/pop yang sangat banyak (jutaan), perbedaan ini bisa terasa.

**"Apakah stack bisa overflow?"**
Ya, untuk implementasi array (jika push melebihi `KAPASITAS`). Untuk linked list, stack hanya bisa "overflow" jika RAM komputer habis — sangat jarang terjadi untuk program biasa. Istilah "stack overflow" yang terkenal (situs Q&A programmer) mengacu pada call stack yang habis karena rekursi tak terbatas, bukan struktur data stack yang kita pelajari.

**"Kenapa postfix lebih mudah dievaluasi oleh komputer?"**
Infix membutuhkan dua tahap: (1) parse ekspresi untuk menemukan urutan operasi berdasarkan prioritas, (2) evaluasi. Postfix cukup satu tahap: baca kiri ke kanan, operand push, operator pop dua dan push hasilnya. Tidak ada aturan prioritas yang perlu ditangani saat evaluasi.
