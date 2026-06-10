# Pertemuan 5 — Panduan Instruktur

**Topik:** Struct & Modular Programming
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code terinstall dan bisa compile C (`gcc` tersedia di terminal).
- [ ] Siapkan folder kerja kosong untuk demo live (pisah dari folder materi).
- [ ] Akun Claude AI / ChatGPT aktif untuk demo bagian 8 (AI kerangka modular).

### File yang Perlu Disiapkan
- [ ] `05_Materi.md` sudah dibagikan ke siswa sebelum atau di awal kelas.
- [ ] `05_Task_A.c` dan `05_Task_B.c` siap dibagikan setelah sesi latihan dimulai.
- [ ] Siapkan contoh proyek multi-file kecil (mahasiswa.h + mahasiswa.c + main.c) untuk demo langsung — jangan tunjukkan dulu sampai sesi Modular Programming.

### Kode Demo yang Perlu Disiapkan
Ketik atau siapkan beforehand di editor (jangan copy-paste saat kelas agar siswa bisa ikuti):

```c
/* demo_struct_awal.c — untuk sesi "Mendefinisikan Struct" */
#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    char nim[15];
    float ipk;
};

int main() {
    struct Mahasiswa mhs1;
    strcpy(mhs1.nama, "Andi");
    strcpy(mhs1.nim, "2024001");
    mhs1.ipk = 3.75;
    printf("%s | %s | %.2f\n", mhs1.nama, mhs1.nim, mhs1.ipk);
    return 0;
}
```

---

## B. Catatan Pedagogis

### Konsep Struct (Menit 15–40)

**Analogi yang bekerja dengan baik:**
- Struct = formulir data. Satu formulir punya banyak kolom (anggota). `typedef` = nama formulir itu sendiri.
- Sebelum masuk kode, tunjukkan "masalah" dulu: tampilkan kode 30 variabel terpisah (nama1, nim1, ipk1, nama2, ...) lalu tanya siswa: "ini nyaman dikelola?". Struct muncul sebagai solusi.

**Miskonsepsi umum:**
- Siswa sering lupa `strcpy` untuk string dan langsung pakai `=`. Tunjukkan error-nya dan jelaskan kenapa (array tidak bisa di-assign langsung).
- Inisialisasi `{"Andi", "001", 3.75}` — beberapa siswa bingung urutan. Tegaskan: urutan inisialisasi = urutan deklarasi anggota.

### typedef & Pointer ke Struct (Menit 40–60)

**Kapan pakai `.` vs `->` — ini HARUS jelas:**

| Situasi | Operator |
|---------|----------|
| Variabel struct biasa | `.` |
| Pointer ke struct | `->` |

Tulis di papan/slide dan tinggalkan selama sesi berlangsung. Hampir pasti ada siswa yang bingung di sini.

**Demo yang efektif:**
```c
Mahasiswa mhs;
Mahasiswa *ptr = &mhs;

/* tunjukkan KEDUANYA menghasilkan output sama */
printf("%s\n", mhs.nama);      /* via variabel langsung */
printf("%s\n", ptr->nama);     /* via pointer */
printf("%s\n", (*ptr).nama);   /* kenapa perlu tanda kurung? tunjukkan error tanpa kurung */
```

Tunjukkan bahwa `*ptr.nama` **error** karena `.` lebih prioritas dari `*`. Ini sering jadi "aha moment".

**By value vs by pointer — analogi surat:**
- By value = kirim fotokopi surat. Perubahan di fungsi tidak mempengaruhi aslinya.
- By pointer = kirim alamat lemari penyimpanan surat. Fungsi bisa langsung mengubah isi.

### Modular Programming (Menit 60–90)

**Urutan penjelasan yang terbukti efektif:**
1. Tunjukkan program satu file yang sudah panjang → "bayangkan kalau 500 baris".
2. Perkenalkan konsep "pemisahan tanggung jawab" — `.h` adalah kontrak, `.c` adalah pelaksana.
3. Ketik `mahasiswa.h` dulu (hanya deklarasi), compile — akan error karena belum ada implementasi.
4. Ketik `mahasiswa.c`, compile bersama-sama — berhasil.
5. Ketik `main.c`, compile tiga file — tunjukkan cara kompilasi multi-file.

**Include guard — kenapa perlu:**
Buat demo sederhana: buat `test.h` tanpa include guard, lalu di `main.c` tulis `#include "test.h"` dua kali. Tunjukkan error "redefinition". Tambahkan include guard, error hilang.

**Kesalahan kompilasi yang sering terjadi:**
- Lupa mengikutsertakan semua `.c` saat kompilasi: `gcc main.c -o program` (tanpa `mahasiswa.c`). Error: "undefined reference to tampilkan". Ini pelajaran penting.
- Salah `#include <mahasiswa.h>` (seharusnya `"mahasiswa.h"`). Tunjukkan perbedaannya.

### AI untuk Kerangka Modular (Menit 105–115)

**Alur demo yang disarankan:**
1. Perlihatkan prompt yang ada di Materi (soal buku perpustakaan).
2. Paste ke Claude AI, tunjukkan output yang dihasilkan.
3. **Review bersama siswa** — minta mereka mengidentifikasi: apakah include guard ada? Apakah prototipe cocok dengan definisi?
4. Coba compile kode hasil AI — kalau ada error, jadikan momen pembelajaran: "ini kenapa kita harus baca kode AI, bukan langsung percaya".
5. Tekankan: AI adalah alat bantu, bukan pengganti pemahaman.

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Recap Pertemuan 4: tanya siswa "apa bedanya pass-by-value dan pass-by-reference?" dan "kapan kita pakai pointer?".
- Jembatan ke hari ini: "tadi kita pakai pointer untuk satu variabel. Bagaimana kalau kita punya banyak data yang saling berkaitan?"

### 15–40 | Konsep Struct
- Mulai dengan masalah (lihat analogi formulir di atas).
- Demo live: ketik `demo_struct_awal.c` dari nol, compile, jalankan.
- Tunjukkan inisialisasi langsung vs via `strcpy`.
- Cek pemahaman: minta satu siswa menjelaskan apa itu anggota struct sebelum lanjut.

### 40–60 | typedef & Pointer ke Struct
- Refactor `demo_struct_awal.c` dengan typedef — tunjukkan perbedaan sebelum dan sesudah.
- Demo `.` vs `->` seperti di catatan pedagogis.
- Demo `by value` vs `by pointer` dengan fungsi `update_ipk`.

### 60–90 | Modular Programming
- Demo multi-file langkah demi langkah (jangan tunjukkan file jadi — ketik bersama).
- Demonstrasi include guard dengan sengaja menghilangkannya dulu.
- Tunjukkan cara kompilasi: `gcc mahasiswa.c main.c -o program`.

### 90–105 | Studi Kasus Modular
- Siswa buka `05_Task_B.c` — fokus pada bagian `[mahasiswa.h]` dan `[mahasiswa.c]`.
- Beri 10 menit mengerjakan bagian A dan B task ini.
- Bahas bersama: mana yang paling banyak salah diisi?

### 105–115 | AI untuk Kerangka Modular
- Demo seperti panduan di atas.
- Siswa boleh mencoba sendiri di laptop masing-masing.

### 115–120 | Penutup & Tugas
- Rekap 3 poin utama: (1) struct mengorganisasi data, (2) `->` untuk pointer ke struct, (3) header + implementasi untuk kode modular.
- Tugas: selesaikan `05_Task_A.c` dan `05_Task_B.c`.
- Preview Pertemuan 6: "Pertemuan depan kita pakai struct untuk membangun struktur data pertama kita: Linked List."

---

## D. Kunci Jawaban Task

### Task A (`05_Task_A.c`)

| Label | Jawaban |
|-------|---------|
| A1 | `struct` |
| A2 | `char` |
| A3 | `float` |
| A4 | Sudah benar (`Mahasiswa`) |
| B2 | `nama` |
| B3 | `ipk` |
| B4 | `nama` |
| B5 | `ipk` |
| C1 | `"Budi Santoso", "2024002", 3.50` |
| D1 | `Mahasiswa` |
| D2 | `0`, `3` |
| D3 | `i` (untuk `kelas[i].nama`) |
| D4 | `i` (untuk `kelas[i].ipk`) |
| E1 | `Mahasiswa` |
| E2 | `nama` |
| E3 | `ipk` |
| E4 | `mhs1` |
| E5 | `mhs2` |

### Task B (`05_Task_B.c`)

| Label | Jawaban |
|-------|---------|
| A1 | `MAHASISWA_H` |
| A2 | `MAHASISWA_H` |
| A3 | `#endif` |
| B1 | `nama` |
| B2 | `ipk` |
| B3 | `Mahasiswa`, `float` |
| B4 | `ipk` |
| B5 | `ipk`, `indeks_tertinggi` |
| C1 | `&mhs1` |
| C2 | `*ptr` |
| C3 | `ipk` |
| C4 | `*ptr` atau `mhs1` (keduanya benar) |
| D1 | `&kelas[1]`, `3.70` |
| D2 | `kelas`, `jumlah` |
| D3 | `idx` |

---

## E. Antisipasi Pertanyaan Umum

**"Kenapa struct pakai titik koma (`;`) di akhir kurung kurawal?"**
Karena definisi struct adalah *deklarasi tipe*, bukan blok kode. Tanda `;` mengakhiri pernyataan deklarasi. Sama seperti `int x;` — `x` ada di akhir nama, `;` mengakhiri pernyataan.

**"Kenapa `->` disebut 'arrow operator'?"**
Karena secara visual `->` terlihat seperti anak panah yang menunjuk ke anggota struct dari pointer. Mnemonik: "pointer *menunjuk ke* anggota".

**"Kapan file `.h` butuh `#include` sendiri?"**
Jika header menggunakan tipe dari header lain (misalnya `FILE*` dari `<stdio.h>`), maka `.h` tersebut harus meng-include header yang dibutuhkan. Prinsip: header harus bisa di-include sendirian tanpa error.

**"Kalau ada 10 file `.c`, harus compile semua setiap kali?"**
Di proyek nyata, digunakan `Makefile` atau build system (CMake, dll.) yang hanya recompile file yang berubah. Ini akan dibahas di luar scope kelas, tapi boleh disebutkan sebagai preview.
