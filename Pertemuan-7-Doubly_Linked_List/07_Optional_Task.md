# Pertemuan 7 — Optional Task: Doubly Linked List

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` sendiri sebagai jawabanmu.

---

## Optional Task 1 — Daftar Nilai Terurut (Level: Mudah)

### Latar Belakang

Daripada insert di depan atau belakang, kali ini kamu harus menyisipkan node di posisi yang tepat agar list selalu **terurut dari kecil ke besar** secara otomatis.

### Yang Harus Dibuat

Buat file **`optional1_terurut.c`** yang melakukan hal berikut:

1. Gunakan node doubly LL standar (`data`, `prev`, `next`).

2. Buat fungsi:
   - `void insert_terurut(Node **head, Node **tail, int data)` — sisipkan node baru di posisi yang tepat agar list tetap terurut ascending. Tidak boleh mengurutkan ulang setelah insert — harus langsung disisipkan di tempat yang benar.
   - `void tampilkan_maju(Node *head)` dan `void tampilkan_mundur(Node *tail)` — seperti biasa.
   - `void bebaskan_list(Node **head, Node **tail)`.

3. Di `main()`:
   - Insert angka-angka berikut satu per satu (tidak berurutan): `30, 10, 50, 20, 40`.
   - Setelah tiap insert, tampilkan list maju.
   - Di akhir, tampilkan list mundur — harus terurut dari besar ke kecil.

### Contoh Output

```
Insert 30: Maju  : 30
Insert 10: Maju  : 10 <-> 30
Insert 50: Maju  : 10 <-> 30 <-> 50
Insert 20: Maju  : 10 <-> 20 <-> 30 <-> 50
Insert 40: Maju  : 10 <-> 20 <-> 30 <-> 40 <-> 50
Mundur   : Mundur: 50 <-> 40 <-> 30 <-> 20 <-> 10
```

### Petunjuk

- `insert_terurut` mirip dengan `insert_setelah`, tapi kamu perlu traverse dulu untuk menemukan posisi yang tepat (node pertama yang nilainya > data baru).
- Tangani tiga kasus: insert di depan (data < head), insert di belakang (data > semua), insert di tengah.
- Setelah insert, verifikasi `head->prev == NULL` dan `tail->next == NULL`.

---

## Optional Task 2 — Hapus Semua Duplikat (Level: Menantang)

### Latar Belakang

Diberikan doubly linked list yang mungkin mengandung nilai duplikat. Tugasmu adalah menghapus semua node duplikat sehingga setiap nilai hanya muncul sekali — tanpa mengubah urutan kemunculan pertama setiap nilai.

### Yang Harus Dibuat

Buat file **`optional2_hapus_duplikat.c`** yang melakukan hal berikut:

1. Gunakan node doubly LL standar.

2. Buat fungsi:
   - `void hapus_duplikat(Node **head, Node **tail)` — telusuri list dari head, dan untuk setiap nilai, hapus semua kemunculannya yang berikutnya.
   - Sertakan juga `insert_belakang`, `tampilkan_maju`, `tampilkan_mundur`, `bebaskan_list`.

3. Di `main()`:
   - Bangun list: `[1, 3, 2, 3, 1, 4, 2, 5]`.
   - Tampilkan list sebelum dan sesudah `hapus_duplikat`.
   - Verifikasi bahwa traverse mundur menghasilkan kebalikan dari traverse maju (konsistensi pointer dua arah).

### Contoh Output

```
Sebelum: Maju  : 1 <-> 3 <-> 2 <-> 3 <-> 1 <-> 4 <-> 2 <-> 5
Sesudah: Maju  : 1 <-> 3 <-> 2 <-> 4 <-> 5
Mundur : Mundur: 5 <-> 4 <-> 2 <-> 3 <-> 1
```

### Petunjuk

- Algoritma nested loop: untuk setiap node `curr`, scan semua node setelahnya (`runner`) — kalau `runner->data == curr->data`, hapus `runner`.
- Saat menghapus `runner`, update pointer tetangganya (`prev` dan `next`), lalu `free`. Pastikan pointer `tail` ikut diperbarui jika yang dihapus adalah tail.
- Ingat: setelah menghapus `runner`, `runner` harus bergeser ke `runner->next` yang baru (yang sudah tersambung melewati node yang dihapus).

---

## Optional Task 3 — Simulasi Playlist Lagu (Level: Lanjutan)

### Latar Belakang

Doubly linked list cocok untuk merepresentasikan playlist musik karena bisa navigasi maju (lagu berikutnya) dan mundur (lagu sebelumnya). Kamu akan mensimulasikan pemutar musik sederhana.

### Yang Harus Dibuat

Buat file **`optional3_playlist.c`** yang melakukan hal berikut:

1. Definisikan node `Lagu` dengan anggota:
   - `judul` — string 100 karakter
   - `artis` — string 50 karakter
   - `durasi_detik` — int
   - `prev`, `next` — pointer ke `Lagu`

2. Buat fungsi-fungsi:
   - `Lagu *buat_lagu(const char *judul, const char *artis, int durasi)`.
   - `void tambah_lagu(Lagu **head, Lagu **tail, const char *judul, const char *artis, int durasi)` — insert di belakang.
   - `void hapus_lagu(Lagu **head, Lagu **tail, const char *judul)` — hapus berdasarkan judul (gunakan `strcmp`).
   - `void tampilkan_playlist(Lagu *head)` — tampilkan nomor urut, judul, artis, dan durasi (format mm:ss).
   - `void putar_maju(Lagu *saat_ini)` — cetak "▶ Memutar: [judul] — [artis]", lalu tampilkan lagu berikutnya (atau "Playlist selesai" jika tidak ada).
   - `void putar_mundur(Lagu *saat_ini)` — cetak lagu sebelumnya (atau "Sudah di lagu pertama" jika tidak ada).

3. Di `main()`:
   - Tambahkan 4 lagu ke playlist.
   - Tampilkan playlist lengkap.
   - Simulasikan: mulai dari lagu pertama → putar maju 2x → putar mundur 1x.
   - Hapus salah satu lagu, tampilkan playlist lagi.

### Contoh Output

```
=== Playlist ===
1. Bohemian Rhapsody    - Queen           [5:55]
2. Hotel California     - Eagles          [6:30]
3. Stairway to Heaven   - Led Zeppelin    [8:02]
4. Imagine              - John Lennon     [3:07]

▶ Memutar: Bohemian Rhapsody — Queen
  Berikutnya: Hotel California — Eagles

▶ Memutar: Hotel California — Eagles
  Berikutnya: Stairway to Heaven — Led Zeppelin

▶ Memutar: Stairway to Heaven — Led Zeppelin
  Sebelumnya: Hotel California — Eagles

Menghapus "Hotel California"...

=== Playlist ===
1. Bohemian Rhapsody    - Queen           [5:55]
2. Stairway to Heaven   - Led Zeppelin    [8:02]
3. Imagine              - John Lennon     [3:07]
```

### Petunjuk

- Untuk format durasi `mm:ss`: `printf("%d:%02d", durasi / 60, durasi % 60)`.
- `hapus_lagu` menggunakan `strcmp(saat_ini->judul, judul) == 0` untuk mencocokkan judul.
- `putar_maju` dan `putar_mundur` tidak perlu mengubah data list — cukup baca `next` dan `prev` dari node yang diterima.
- Pastikan `bebaskan_list` dipanggil di akhir `main`.
