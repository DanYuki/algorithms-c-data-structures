# Pertemuan 4 — Optional Task

**Topik:** Pointer & Dynamic Memory
**Sifat:** Opsional — dikerjakan di luar kelas sebagai latihan tambahan

---

## Petunjuk Umum

- Buat file jawaban kamu sendiri (`04_OT1.c`, `04_OT2.c`, `04_OT3.c`).
- Sebelum menulis kode, buat pseudocode atau gambaran alur memorinya terlebih dahulu.
- Compile dan tes dengan berbagai input. Perhatikan apakah program crash atau tidak.
- Coba sendiri dulu minimal 15 menit sebelum minta bantuan AI.

---

## Soal 1 — Level Mudah: Array Dinamis dengan Statistik

**Problem Statement:**

Buat program C yang:
1. Meminta pengguna memasukkan jumlah data N (N ditentukan saat runtime).
2. Mengalokasikan array `double` berukuran N menggunakan `malloc`.
3. Meminta pengguna mengisi N nilai ke dalam array.
4. Menghitung dan menampilkan: **total**, **rata-rata**, **nilai terbesar**, dan **nilai terkecil**.
5. Membebaskan memori setelah selesai.

**Contoh output (N=4):**
```
Jumlah data: 4
Data[0]: 7.5
Data[1]: 3.2
Data[2]: 9.1
Data[3]: 5.0

Total    : 24.80
Rata-rata: 6.20
Terbesar : 9.10
Terkecil : 3.20
```

<details>
<summary>Panduan (klik jika butuh)</summary>

- Gunakan `malloc(n * sizeof(double))` untuk alokasi.
- Selalu cek `NULL` setelah `malloc`.
- Logika statistik sama seperti di Pertemuan 3 — bedanya sekarang ukuran array ditentukan saat runtime.
- Pastikan `free` dipanggil di **semua** jalur keluar fungsi (termasuk jika alokasi gagal setelah malloc berhasil).

**Pertanyaan pemandu:**
- Apa bedanya program ini dengan versi array statis di Pertemuan 3?
- Bagaimana jika pengguna memasukkan N = 0? Apakah `malloc(0)` aman?

</details>

---

## Soal 2 — Level Menantang: Resize Array Dinamis

**Problem Statement:**

Buat program C yang mensimulasikan array yang bisa "membesar" saat penuh:

1. Mulai dengan array berukuran 3 yang dialokasikan secara dinamis.
2. Program menerima angka dari pengguna satu per satu dalam loop.
3. Jika array sudah penuh dan pengguna ingin menambah lagi, program **membuat array baru berukuran dua kali lipat**, menyalin isi array lama ke yang baru, lalu membebaskan array lama.
4. Program berhenti saat pengguna memasukkan -1.
5. Setelah selesai, tampilkan semua elemen yang tersimpan dan bebaskan memori.

**Contoh output:**
```
Masukkan angka (-1 untuk berhenti): 10
Masukkan angka (-1 untuk berhenti): 20
Masukkan angka (-1 untuk berhenti): 30
[Array penuh (3/3), memperbesar ke ukuran 6]
Masukkan angka (-1 untuk berhenti): 40
Masukkan angka (-1 untuk berhenti): -1

Data tersimpan (4 elemen): 10 20 30 40
```

<details>
<summary>Panduan (klik jika butuh)</summary>

**Alur resize:**
```
arr_baru = malloc(ukuran_baru * sizeof(int))
cek NULL
salin isi arr_lama ke arr_baru (dengan loop atau memcpy)
free(arr_lama)
arr_lama = arr_baru   // sekarang arr menunjuk ke array yang lebih besar
```

**Variabel yang perlu dilacak:**
- `int *arr` — pointer ke array saat ini
- `int ukuran` — kapasitas saat ini
- `int jumlah` — berapa elemen yang sudah terisi

**Pertanyaan pemandu:**
- Apa yang terjadi jika `malloc` untuk array baru gagal? Apakah array lama masih aman?
- Apakah ada memory leak jika resize gagal di tengah jalan?
- Bisakah kamu memindahkan logika resize ke dalam fungsi terpisah `int* resize(int *arr, int ukuran_lama, int ukuran_baru)`?

</details>

---

## Soal 3 — Level Lanjutan: Stack Sederhana dengan Array Dinamis

**Problem Statement:**

Implementasikan struktur data **Stack** (tumpukan) menggunakan array dinamis. Stack mengikuti prinsip **LIFO** (Last In, First Out) — elemen yang terakhir dimasukkan adalah yang pertama dikeluarkan.

Buat program C yang mengimplementasikan operasi berikut:

| Fungsi | Deskripsi |
|--------|-----------|
| `inisialisasi_stack(int kapasitas)` | Alokasi array dinamis berukuran `kapasitas`, kembalikan pointer ke array. Simpan kapasitas dan jumlah elemen saat ini. |
| `push(...)` | Tambahkan elemen ke atas stack. Jika penuh, tampilkan pesan "Stack penuh." |
| `pop(...)` | Ambil dan hapus elemen teratas. Jika kosong, tampilkan "Stack kosong." |
| `peek(...)` | Lihat elemen teratas tanpa menghapus. |
| `tampilkan_stack(...)` | Tampilkan semua elemen dari atas ke bawah. |
| `hapus_stack(...)` | Bebaskan semua memori. |

Karena belum mempelajari `struct`, kamu bisa menggunakan **variabel global** atau **parameter terpisah** (pointer ke array, pointer ke variabel `top`, nilai `kapasitas`) untuk mewakili state stack.

**Contoh output:**
```
Push 10 → stack: [10]
Push 20 → stack: [20, 10]
Push 30 → stack: [30, 20, 10]
Peek: 30
Pop  → 30, stack: [20, 10]
Pop  → 20, stack: [10]
Push 40 → stack: [40, 10]
Tampilkan: 40 10
```

<details>
<summary>Panduan (klik jika butuh)</summary>

**Representasi stack dengan array:**
- Gunakan variabel `top` (indeks) yang dimulai dari -1 (stack kosong).
- `push`: `top++`, lalu `arr[top] = nilai`.
- `pop`: ambil `arr[top]`, lalu `top--`.
- `peek`: kembalikan `arr[top]` tanpa mengubah `top`.
- Stack penuh jika `top == kapasitas - 1`.
- Stack kosong jika `top == -1`.

**Mengapa ini penting?**
Stack adalah fondasi dari banyak algoritma penting: evaluasi ekspresi, undo/redo, DFS pada graf, dan call stack rekursi yang sudah kamu lihat di Pertemuan 2.

**Pertanyaan pemandu:**
- Bisakah kamu membuat stack yang otomatis resize (memperbesar diri) saat penuh, seperti di Soal 2?
- Bagaimana kamu akan mengetes bahwa implementasimu benar? Kasus apa yang perlu diuji?

</details>
