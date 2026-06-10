# Pertemuan 7 — Panduan Instruktur

**Topik:** Doubly Linked List
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + `gcc` berjalan normal di komputer demo.
- [ ] Siapkan folder kerja kosong untuk demo live.
- [ ] Akun Claude AI aktif untuk demo edge cases (segmen 85–105).
- [ ] Siapkan papan tulis / whiteboard — gambar dua panah per node adalah WAJIB di pertemuan ini.

### Kode Demo yang Perlu Disiapkan

```c
/* demo_dll_awal.c — bangun doubly LL dari nol */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *prev; struct Node *next; } Node;

int main() {
    Node *n1 = malloc(sizeof(Node));
    Node *n2 = malloc(sizeof(Node));
    Node *n3 = malloc(sizeof(Node));

    n1->data = 10; n1->prev = NULL;  n1->next = n2;
    n2->data = 20; n2->prev = n1;   n2->next = n3;
    n3->data = 30; n3->prev = n2;   n3->next = NULL;

    Node *head = n1, *tail = n3;

    /* traverse maju */
    printf("Maju  : ");
    for (Node *p = head; p; p = p->next)
        printf("%d%s", p->data, p->next ? " <-> " : "\n");

    /* traverse mundur */
    printf("Mundur: ");
    for (Node *p = tail; p; p = p->prev)
        printf("%d%s", p->data, p->prev ? " <-> " : "\n");

    free(n1); free(n2); free(n3);
    return 0;
}
```

---

## B. Catatan Pedagogis

### Konsep Doubly LL (Menit 15–35)

**Jembatan dari Pertemuan 6:**
Mulai dengan bertanya: "Di single LL, kalau kamu sedang di node ke-5 dan ingin ke node ke-4, apa yang harus dilakukan?" → Mulai dari head lagi. "Doubly LL menyelesaikan ini dengan menambah satu pointer: `prev`."

**Gambar di papan — WAJIB dan pertahankan sepanjang kelas:**
```
head                             tail
 │                                 │
 ▼                                 ▼
[NULL|10|──]──►[◄──|20|──]──►[◄──|30|NULL]
       ◄──────────────◄──────────────◄
```
Gunakan dua warna berbeda untuk anak panah `next` (maju) dan `prev` (mundur) agar visualisasi jelas.

**Penekanan utama:**
- Setiap operasi insert/delete harus memperbarui **empat** sambungan (vs dua di single LL).
- `tail` sama pentingnya dengan `head` — jangan abaikan.

**Miskonsepsi umum:**
- Siswa sering memperbarui `next` tetapi lupa memperbarui `prev` (atau sebaliknya).
- Lupa bahwa saat insert pada list kosong, node baru menjadi **sekaligus** `head` dan `tail`.
- Saat delete satu-satunya node, **keduanya** `head` dan `tail` harus di-set NULL.

### Insert (Menit 35–60)

**Gambar insert depan langkah demi langkah:**
```
Kondisi awal:
head──►[20←→30]◄──tail

Langkah 1: node_baru->next = *head
[10|──►20]  [←20→30]◄──tail

Langkah 2: (*head)->prev = node_baru
[10|──►20]  [10←20→30]◄──tail

Langkah 3: *head = node_baru
head──►[10←→20←→30]◄──tail
```

**Gambar insert tengah — tekankan urutan 4 langkah:**
```
Sebelum: A ←→ C
Sisipkan B setelah A:

1. B.prev = A
2. B.next = C    ← lakukan 1&2 dulu (sambung B ke tetangga)
3. A.next = B    ← baru putus A dari C
4. C.prev = B
```

Demonstrasikan bug kalau langkah 3 dilakukan sebelum langkah 2: `A.next = B` dulu, lalu `B.next = A.next` — sekarang `B.next = B` sendiri (siklus)! Ini sangat meyakinkan.

### Delete & Traverse (Menit 60–85)

**Satu fungsi delete untuk semua kasus:**
Tunjukkan bahwa logika `if (saat_ini->prev != NULL)` otomatis menangani kasus head, dan `if (saat_ini->next != NULL)` otomatis menangani kasus tail — tidak perlu if-else terpisah per kasus.

**Pola yang elegan:**
```c
if (saat_ini->prev) saat_ini->prev->next = saat_ini->next; else *head = saat_ini->next;
if (saat_ini->next) saat_ini->next->prev = saat_ini->prev; else *tail = saat_ini->prev;
free(saat_ini);
```
Empat kondisi, empat baris — elegan dan lengkap. Tunjukkan ini setelah siswa memahami kasusnya satu per satu.

### Edge Cases dengan AI (Menit 85–105)

**Alur demo yang disarankan:**
1. Tulis `delete_node` yang sengaja cacat: lupa update `tail` saat menghapus tail.
2. Tunjukkan bug: list terlihat benar saat traverse maju, tapi `tail` masih menunjuk ke node yang sudah di-`free`.
3. Paste ke Claude AI dengan prompt: "Apakah ada bug pada fungsi ini? Tolong cek semua edge case delete."
4. Tunjukkan bagaimana AI mendeteksi bug `tail` yang tidak diperbarui.
5. Minta AI generate test cases — jalankan bersama.

**Pertanyaan diskusi:**
- "Mengapa traverse mundur bisa mendeteksi bug yang traverse maju tidak bisa?"
- "Apa yang terjadi kalau kita `free` node tapi masih ada pointer lain yang menunjuk ke sana?"

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Recap pertemuan 6: tanya "apa kelemahan single LL saat kita mau mundur?".
- Preview: "Hari ini kita tambahkan `prev` — navigasi jadi dua arah."

### 15–35 | Konsep Doubly LL
- Gambar node di papan (dua warna anak panah).
- Demo `demo_dll_awal.c` dari nol.
- Tegaskan peran `tail` — ini sering dilupakan.

### 35–60 | Insert
- Gambar tiap insert sebelum kode.
- Demo insert depan, belakang, tengah.
- Tunjukkan bug urutan langkah terbalik.

### 60–85 | Delete & Traverse
- Gambar tiga kasus delete (head/tengah/tail).
- Tunjukkan pola elegan empat baris.
- Demo traverse mundur — manfaat nyata `prev`.

### 85–105 | Edge Cases dengan AI
- Demo bug `tail` + analisis AI seperti panduan di atas.
- Siswa mencoba generate test cases mereka sendiri dengan AI.

### 105–115 | Latihan Terbimbing
- Siswa buka Task C, kerjakan Bagian C (edge cases).
- Bahas: edge case mana yang paling sering dilupakan?

### 115–120 | Penutup & Tugas
- Rekap: 4 sambungan per insert/delete, `tail` sama penting dengan `head`, edge case wajib diuji.
- Tugas: selesaikan Task A, B, C.
- Preview: "Pertemuan 8 kita pakai konsep ini untuk Stack."

---

## D. Kunci Jawaban Task

### Task A (`07_Task_A.c`)

| Label | Jawaban |
|-------|---------|
| A1 | `prev` |
| A2 | `next` |
| B1 | `sizeof(Node)` |
| B2 | `data` |
| B3 | `NULL` |
| B4 | `next` |
| C1 | `head` |
| C2 | `data` |
| C3 | `next` |
| C4 | `next` |
| D1 | `tail` |
| D2 | `prev` |
| D3 | `prev` |
| E1 | `n2` |
| E2 | `prev` |
| E3 | `n3` |
| E4 | `prev` |
| E5 | `n1` |
| E6 | `n3` |
| F1 | `hitung++` |
| F2 | `hitung` |
| F3 | `prev` |
| F4 | `head` |
| F5 | `tail` |

### Task B (`07_Task_B.c`)

| Label | Jawaban |
|-------|---------|
| A1 | `NULL` |
| A1b | `node_baru` |
| A2 | `next` |
| A3 | `prev` |
| A4 | `node_baru` |
| B2 | `prev` |
| B3 | `next` |
| B4 | `node_baru` |
| C1 | `prev` |
| C2 | `next` |
| C3 | `next` |
| C4a | `prev` |
| C4b | `node_baru` |
| D1 | `&head`, `&tail` |
| D2 | `insert_belakang`, `&head`, `&tail` |
| D3 | `&head`, `&tail`, `10` |
| D4 | `&tail`, `head` |

### Task C (`07_Task_C.c`)

| Label | Jawaban |
|-------|---------|
| A1 | `NULL` |
| A2 | `target` |
| A3 | `NULL` |
| A4 | `prev` |
| A4b | `next` |
| A5 | `next` |
| A5b | `prev` |
| A6 | `free` |
| B1 | `&head`, `&tail`, `30` |
| B2 | `10` |
| B3 | `delete_node`, `&head`, `&tail` |
| C1 | `&head1`, `&tail1` |
| C2 | `&head2`, `&tail2`, `99` |
| C3 | `99` |
| D1 | `2` |
| D2 | `head`, `tail` |

---

## E. Antisipasi Pertanyaan Umum

**"Kenapa perlu `tail`? Kan bisa dicari dari `head`?"**
Bisa — tapi O(n). Dengan `tail`, insert di belakang menjadi O(1). Di struktur data yang lebih kompleks (seperti deque), akses O(1) ke kedua ujung sangat penting.

**"Kapan pakai doubly LL dibanding single LL?"**
Saat butuh: (1) traversal mundur, (2) delete yang perlu akses ke node sebelumnya tanpa menyimpan pointer tambahan, (3) implementasi deque (double-ended queue). Biayanya: memori ekstra satu pointer per node, dan kode lebih banyak karena dua sambungan yang harus dijaga.

**"Apakah mungkin linked list melingkar (circular)?"**
Ya — Circular Linked List di mana `tail->next = head` (dan di doubly: `head->prev = tail`). Berguna untuk implementasi round-robin scheduler atau buffer melingkar. Ini bisa disebutkan sebagai preview topik lanjutan.

**"Bagaimana kalau lupa update salah satu dari empat sambungan?"**
Program mungkin tidak crash segera, tapi traversal mundur akan menghasilkan data yang salah atau infinite loop. Inilah mengapa fungsi `cek_konsistensi` di Task C penting — selalu verifikasi setelah setiap operasi saat masih belajar.
