# Pertemuan 6 — Panduan Instruktur

**Topik:** Linked List (Single)
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + `gcc` berjalan normal di komputer demo.
- [ ] Siapkan folder kerja kosong untuk demo live (terpisah dari folder materi).
- [ ] Akun Claude AI aktif untuk demo visualisasi & debugging (segmen 100–115).
- [ ] Siapkan kertas/whiteboard atau gambar sederhana rantai node untuk penjelasan awal.

### Kode Demo yang Perlu Disiapkan

Siapkan file berikut sebelum kelas (atau ketik live — lebih baik):

```c
/* demo_node_awal.c — bangun list secara manual */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    Node *n1 = (Node *) malloc(sizeof(Node));
    Node *n2 = (Node *) malloc(sizeof(Node));
    Node *n3 = (Node *) malloc(sizeof(Node));

    n1->data = 10;  n1->next = n2;
    n2->data = 20;  n2->next = n3;
    n3->data = 30;  n3->next = NULL;

    Node *head = n1;

    /* traverse */
    Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    free(n1); free(n2); free(n3);
    return 0;
}
```

---

## B. Catatan Pedagogis

### Konsep Linked List (Menit 15–35)

**Mulai dengan masalah nyata:**
Tunjukkan kode array yang membutuhkan `int arr[100]` padahal hanya terpakai 3 elemen. Tanyakan: "apa yang terjadi kalau data kamu tiba-tiba 101?" — array harus dideklarasi ulang. Linked list muncul sebagai solusi alami.

**Gambar di papan — wajib:**
Sebelum kode, gambar kotak-kotak node yang disambungkan dengan anak panah. Tampilkan juga `head` sebagai pointer yang mengambang di atas node pertama. Gambar ini harus tetap di papan selama sesi berlangsung.

```
head
 │
 ▼
┌────┬──┐    ┌────┬──┐    ┌────┬──────┐
│ 10 │──┼───►│ 20 │──┼───►│ 30 │ NULL │
└────┴──┘    └────┴──┘    └────┴──────┘
```

**Miskonsepsi paling umum:**
- "Linked list disimpan berurutan di memori seperti array." → **Salah.** Setiap node bisa ada di mana saja di heap — yang menyatukan mereka hanyalah pointer `next`.
- Lupa bahwa `head == NULL` berarti list kosong. Selalu tegaskan cek ini sebelum operasi apa pun.

### Membuat Node & Traverse (Menit 35–55)

**Demo langkah demi langkah:**
1. Ketik `buat_node` dari nol — jangan paste. Ini memberi waktu siswa menyerap tiap baris.
2. Setelah `malloc`, tunjukkan di papan: "malloc memberi kita kotak kosong di heap. Kita isi data-nya, lalu pasang next = NULL karena belum tahu ke mana disambungkan."
3. Demo `tampilkan_list` — tekankan variabel `saat_ini` yang terpisah dari `head`. Tunjukkan apa yang terjadi kalau `head` langsung dipakai untuk traverse (loop berjalan tapi `head` bergeser — kehilangan akses ke awal list).

**Double pointer — momen tersendiri:**
Double pointer (`Node **head`) adalah konsep yang sering membingungkan. Jelaskan analoginya:
- Pointer biasa = "aku pegang lembaran kertas yang bertuliskan alamat rumah".
- Double pointer = "aku pegang lembaran kertas yang bertuliskan *di mana lembaran kertas pertama disimpan*".
- Kita butuh double pointer agar fungsi bisa mengubah *ke mana head menunjuk*, bukan hanya isi node yang ditunjuk head.

Tunjukkan bukti: buat `insert_depan` dengan `Node *head` (bukan double pointer), jalankan — head di `main` tidak berubah. Ini adalah demonstrasi yang sangat meyakinkan.

### Insert (Menit 55–80)

**Gambar setiap operasi insert sebelum koding:**

Insert depan:
```
Langkah 1: node_baru->next = *head
node_baru ──► [10] ──► [20] ──► NULL
      ▲
   *head

Langkah 2: *head = node_baru
      ▲
   *head
node_baru ──► [10] ──► [20] ──► NULL
```

Insert tengah (urutan dua langkah):
```
BENAR:
  (1) node_baru->next = saat_ini->next   ← sambung dulu ke kanan
  (2) saat_ini->next = node_baru         ← baru putus dari kiri

SALAH (urutan terbalik):
  (1) saat_ini->next = node_baru         ← putus ke kanan dulu
  (2) node_baru->next = saat_ini->next   ← sekarang saat_ini->next = node_baru sendiri!
```

Demonstrasikan bug urutan terbalik ini — ini adalah salah satu "aha moment" paling berharga di topik linked list.

### Delete (Menit 80–100)

**Tiga kasus delete — gambar semua:**

1. **Hapus head:**
```
*head = (*head)->next;
free(akan_dihapus);
```

2. **Hapus di tengah:**
```
saat_ini->next = akan_dihapus->next;
free(akan_dihapus);
```

3. **Hapus di tail:** sama dengan kasus tengah — `akan_dihapus->next` adalah NULL, jadi `saat_ini->next = NULL`. Otomatis menjadi node terakhir.

**Dangling pointer — penting:**
Tunjukkan kode yang lupa `free` — jalankan dengan Valgrind atau tunjukkan konsepnya: memori yang sudah tidak dipakai tapi belum dikembalikan. Di embedded systems, ini bisa crash program.

Tunjukkan juga bahwa setelah `free(p)`, mengakses `p->data` adalah **undefined behavior** — kadang kode "bekerja" tapi itu keberuntungan, bukan kebenaran.

### AI untuk Visualisasi & Debugging (Menit 100–115)

**Alur demo yang disarankan:**

1. Tunjukkan kode `insert_posisi` yang sengaja bug (urutan langkah terbalik).
2. Paste ke Claude AI dengan prompt: "Fungsi ini seharusnya insert di posisi tertentu tapi hasilnya salah. Apa masalahnya?"
3. Tunjukkan analisis AI — apakah AI menangkap bug urutan pointer?
4. Minta AI menggambar visualisasi kondisi pointer sebelum dan sesudah insert.
5. Kompilasi kode yang disarankan AI, verifikasi output.

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Recap Pertemuan 5: "Apa itu struct? Bagaimana cara mengakses anggota lewat pointer?"
- Jembatan: "Hari ini kita pakai struct + pointer untuk membangun struktur data pertama: linked list."

### 15–35 | Konsep Linked List
- Tunjukkan masalah array (ukuran tetap, insert mahal).
- Gambar node di papan — simpan gambar ini sepanjang kelas.
- Definisi `typedef struct Node` — tekankan self-referential struct.

### 35–55 | Membuat Node & Traverse
- Demo `buat_node` + penjelasan `malloc`, `sizeof`, cast.
- Demo traverse dengan variabel sementara.
- Cek pemahaman: minta siswa jelaskan mengapa tidak boleh mengubah `head` saat traverse.

### 55–80 | Insert
- Gambar setiap insert sebelum kode.
- Demo double pointer dengan perbandingan single pointer.
- Tekankan urutan dua langkah di insert tengah.

### 80–100 | Delete
- Gambar tiga kasus delete.
- Demo `bebaskan_list` — tekankan menyimpan `berikutnya` sebelum `free`.
- Tunjukkan konsep dangling pointer.

### 100–115 | AI untuk Visualisasi & Debugging
- Demo seperti panduan di atas.
- Siswa mencoba meminta AI memvisualisasikan operasi yang baru dipelajari.

### 115–120 | Penutup & Tugas
- Rekap 4 poin: node = data + pointer, head menandai awal, double pointer untuk ubah head, urutan pointer di insert/delete sangat penting.
- Tugas: selesaikan Task A, B, dan C.
- Preview: "Pertemuan 7 kita tambahkan pointer `prev` ke setiap node → Doubly Linked List."

---

## D. Kunci Jawaban Task

### Task A (`06_Task_A.c`)

| Label | Jawaban |
|-------|---------|
| A1 | `int` |
| A2 | `next` |
| B1 | `sizeof(Node)` |
| B2 | `data` |
| B3 | `next` |
| B4 | `node_baru` |
| C1 | `next` |
| C2 | `n2` |
| C3 | `n1` |
| D1 | `head` |
| D2 | `!= NULL` |
| D3 | `data` |
| D4 | `next` |
| E1 | `hitung++` |
| E2 | `hitung` |
| F1 | `5` |
| F2 | `10` |
| F2b | `n2` |
| F3b | `n4` |
| F3 | `tampilkan_list` |
| F4 | `panjang_list` |

### Task B (`06_Task_B.c`)

| Label | Jawaban |
|-------|---------|
| A1 | `Node **` |
| A2 | `*head` |
| A3 | `node_baru` |
| B1 | `NULL` |
| B2 | `next` |
| B3 | (kondisi loop sudah terisi `next`) |
| B4 | `next` |
| C1 | `posisi - 1` |
| C2 | `next` |
| C3 | `next` |
| D1 | `insert_belakang(&head, 10)` |
| D3 | `insert_depan(&head, 5)` |
| D4 | `2` |

### Task C (`06_Task_C.c`)

| Label | Jawaban |
|-------|---------|
| A1 | `NULL` |
| A2 | `(*head)->data == target` (sudah) |
| A3 | `akan_dihapus` |
| A4 | `free` |
| A5 | `target` |
| A6 | `next` |
| A7 | `next` |
| A8 | `next` |
| A9 | `free` |
| B1 | `next` |
| B2 | `free` |
| B3 | `berikutnya` |
| B4 | `NULL` |
| C1 | `delete_node(&head, 30)` |
| C2 | `delete_node` |
| C3 | `50` |
| D1 | `bebaskan_list` |
| D2 | `NULL` |

---

## E. Antisipasi Pertanyaan Umum

**"Kenapa harus `Node **head` dan bukan `Node *head`?"**
Karena kita ingin mengubah *ke mana `head` menunjuk* (nilai pointer-nya), bukan sekadar mengubah isi node yang ditunjuk `head`. Untuk mengubah nilai sebuah variabel dari dalam fungsi, kita kirim alamatnya — kalau yang ingin diubah adalah `Node *head`, kita kirim `Node **head`.

**"Kenapa `(*head)->next` bukannya `*head->next`?"**
Prioritas operator. `->` lebih tinggi dari `*`. Jadi `*head->next` dibaca sebagai `*(head->next)` — mencoba dereference `head->next` padahal `head` adalah `Node **`, bukan `Node *`. Tanda kurung `(*head)` memaksa dereference dilakukan dulu.

**"Apakah linked list lebih cepat dari array?"**
Tergantung operasinya. Akses elemen ke-`i`: array O(1), linked list O(n). Insert/delete di awal: array O(n) karena geser, linked list O(1). Tidak ada yang "lebih cepat" secara umum — konteks operasi yang menentukan.

**"Kenapa harus simpan `berikutnya` sebelum `free`?"**
Setelah `free(p)`, blok memori yang ditunjuk `p` dikembalikan ke sistem dan bisa ditimpa kapan saja. Mengakses `p->next` setelah `free` adalah undefined behavior — hasilnya tidak terprediksi. Menyimpan `berikutnya = p->next` sebelum `free` memastikan kita masih punya referensi yang valid.
