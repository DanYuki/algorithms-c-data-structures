# Panduan Instruktur — Pertemuan 1

**Topik:** Intro to C, Problem Solving & AI Engineering
**Durasi:** 120 menit
**Dokumen ini TIDAK diberikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code terinstall di mesin demo, dengan extension **C/C++ (Microsoft)** aktif.
- [ ] GCC compiler terinstall dan bisa dipanggil dari terminal (`gcc --version` harus berhasil).
- [ ] Buat folder kerja kosong untuk demo live (mis. `demo_p1/`) — jangan pakai folder lain yang sudah berisi file.
- [ ] Tes kompilasi `hello.c` sebelum kelas dimulai.

### Akun AI
- [ ] Login ke ChatGPT atau Claude sebelum kelas — akan dipakai untuk demo prompt engineering.
- [ ] Siapkan dua tab: satu untuk kode, satu untuk AI chat.

### File yang Disiapkan
- [ ] `01_Materi.md` — bagikan ke siswa di awal sesi (atau upload ke platform kelas).
- [ ] `01_Task.c` — bagikan ke siswa saat segmen Task (menit ke-75 ke atas, atau sesuai alur).
- [ ] `01_Optional_Task.md` — bagikan di akhir sebagai PR.
- [ ] Siapkan **satu problem statement utama** yang akan dipakai dari awal sampai akhir segmen problem solving: **"Cek Bilangan Ganjil/Genap"**.

---

## B. Catatan Pedagogis

### Urutan Penyampaian yang Direkomendasikan

1. **Jangan mulai dengan teori** — mulai dengan pertanyaan: *"Kenapa kalian mau belajar programming?"* atau *"Pernah dengar istilah DSA?"*. Bangun relevansi dulu.

2. **Setup environment bersama-sama** — minta siswa install sambil kamu demo. Antisipasi: siswa Windows sering bingung dengan PATH MinGW. Siapkan solusi: pakai [mingw-get-setup.exe](https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/) atau arahkan ke MSYS2.

3. **Gunakan SATU problem statement sepanjang segmen problem solving** — jangan ganti soal di tengah jalan. Siswa harus melihat transformasi: problem → flowchart → pseudocode → kode C menggunakan soal yang sama (Ganjil/Genap).

4. **Gambar flowchart dulu secara manual** (di whiteboard atau menggunakan tools seperti draw.io) sebelum menulis pseudocode atau kode. Ini membantu siswa yang belum terbiasa berpikir algoritmik.

5. **Jangan terburu-buru ke sintaks** — miskonsepsi paling umum di pertemuan pertama adalah siswa menghafal sintaks tanpa mengerti alurnya. Tekankan: *"Pseudocode dulu, sintaks belakangan."*

### Miskonsepsi Umum & Cara Mengatasinya

| Miskonsepsi | Cara Mengatasinya |
|-------------|-------------------|
| Lupa titik koma (`;`) di akhir statement | Tunjukkan pesan error dari GCC, minta mereka baca pesan error sendiri. Biasakan baca error message dari awal. |
| Bingung kapan pakai `%d` vs `%f` | Gunakan analogi: format specifier seperti "label kotak" — `%d` untuk kotak integer, `%f` untuk kotak desimal. |
| Mengira `7 / 2` menghasilkan `3.5` | Demo langsung di terminal: `int` dibagi `int` membuang desimal. Tunjukkan perbaikannya dengan `7.0 / 2`. Hubungkan ke contoh konversi suhu (kalau pakai `9/5` hasil salah). |
| Mengira `%` adalah persen | Jelaskan `%` di C adalah **sisa bagi (modulo)**, bukan persentase. Contoh: `10 % 3 = 1`. |
| Bingung dengan `&` di `scanf` | Cukup bilang: *"scanf butuh 'alamat' bukan 'isinya' — ini akan kita pelajari lebih dalam di bab pointer."* Jangan jelaskan terlalu dalam di P1. |
| Menyamakan pseudocode dengan komentar kode | Tekankan: pseudocode ditulis **sebelum** kode, bukan sesudah. Tujuannya berbeda. |
| Mengira AI bisa menggantikan proses belajar | Ceritakan analogi: AI seperti kalkulator — sangat berguna, tapi kamu tetap harus mengerti matematika dasarnya. |

### Tips Demo Live

- **Sengaja buat error kecil** saat demo (mis. lupa titik koma), lalu debug bersama siswa. Ini mengajarkan bahwa error adalah hal normal, bukan kegagalan.
- **Tunjukkan proses kompilasi** dari terminal, bukan tombol "Run" di IDE — supaya siswa mengerti apa yang terjadi di balik layar.
- Saat demo prompt AI: **tunjukkan prompt buruk dulu**, lihat hasilnya, lalu perbaiki dengan prompt yang baik. Kontras ini lebih berkesan.

---

## C. Panduan Rundown

| Waktu | Segmen | Yang Perlu Ditekankan |
|-------|--------|-----------------------|
| 0–15 | **Pembukaan** | Kenapa C? Peta 16 pertemuan. Konsep AI-Augmented Developer. Jaga energi tinggi — kesan pertama penting. |
| 15–40 | **Setup Environment** | Bantu siswa yang stuck satu per satu. Jangan lanjut sampai mayoritas berhasil kompilasi Hello World. |
| 40–60 | **Anatomi Program C** | Bedah setiap baris `hello.c`. Tekankan: `#include`, `main`, titik koma, `return 0`. |
| 60–72 | **Tipe Data & Kompilasi** | Demo `scanf` + `printf` dengan beberapa tipe data. Tunjukkan alur kompilasi di terminal. |
| 72–85 | **Operasi Aritmatika** | Demo `+ - * / %`. **Tekankan jebakan `int / int`** (`7/2` = 3) lalu perbaiki dengan `7.0/2`. Perkenalkan `%` (modulo) di sini — jadikan jembatan ke soal Ganjil/Genap. Tutup dengan contoh konversi suhu. |
| 85–105 | **Problem Solving** | **Ini segmen terpenting.** Gambar flowchart → tulis pseudocode → tulis kode C. Gunakan soal Ganjil/Genap (siswa sudah kenal `%` dari segmen sebelumnya). Minta siswa ikut menulis di kertas/editor mereka. |
| 105–115 | **Prompt Engineering** | Demo langsung di ChatGPT/Claude. Tampilkan perbedaan output dari prompt buruk vs baik. |
| 115–120 | **Penutup & Tugas** | Rekap singkat 3 poin utama. Bagikan `01_Task.c` dan `01_Optional_Task.md`. Preview P2. |

---

## D. Kunci Jawaban Task

### Bagian A — Hello World

```c
#include <stdio.h>     // (A1) <stdio.h>

int main() {           // (A2) main

    printf("Halo, %s!\n", "Dzaka");
    printf("Ini program C pertamaku.\n");  // (A3)

    return 0;          // (A4)
}
```

### Bagian B — Variabel & Format Specifier

```c
char   nama[]  = "Budi";   // (B1) char
int    usia    = 20;       // (B1) int
float  nilai   = 88.5;     // (B1) float
char   grade   = 'A';      // (B1) char

printf("Usia   : %d\n",   usia);    // (B2) %d
printf("Nilai  : %.2f\n", nilai);   // (B2) %.2f
printf("Grade  : %c\n",   grade);   // (B2) %c
```

### Bagian C — Terjemahkan Pseudocode

```c
int nilai;                                      // (C1) int

printf("Masukkan nilai kamu (0-100): ");        // (C2)
scanf("%d", &nilai);                            // (C3) "%d", &nilai

if (nilai >= 60) {                              // (C4) kondisi
    printf("Selamat, kamu LULUS!\n");
} else {                                        // (C4) else
    printf("Kamu BELUM LULUS. Semangat!\n");
}
```

---

## E. Antisipasi Pertanyaan Siswa

**Q: Kenapa harus pakai C, bukan Python yang lebih mudah?**
A: Python bagus untuk produktivitas, tapi C memaksa kamu memahami apa yang sebenarnya terjadi di memori komputer. Pemahaman ini sangat penting untuk DSA dan untuk menjawab soal technical interview tingkat lanjut.

**Q: Apakah kita akan selalu nulis kode dari nol, atau boleh pakai template?**
A: Di pertemuan awal kita mulai dari nol supaya kamu memahami setiap bagian. Nanti ketika sudah terbiasa, boleh pakai template atau snippet.

**Q: Kenapa `scanf` pakai `&` tapi `printf` tidak?**
A: `printf` hanya *membaca* nilai untuk ditampilkan. `scanf` harus *menulis* nilai ke variabel, jadi dia butuh tahu *di mana* variabel itu disimpan di memori — itulah yang diberikan oleh `&`. Topik ini akan lebih jelas di pertemuan Pointer.

**Q: AI kan bisa nulis kode, kenapa kita masih harus belajar?**
A: AI bisa menulis kode, tapi tidak bisa mengerti *masalahmu* atau *konteks proyekmu* lebih baik darimu. Tanpa pemahaman dasar, kamu tidak bisa mengevaluasi apakah kode yang dibuat AI sudah benar, efisien, atau sesuai kebutuhan.
