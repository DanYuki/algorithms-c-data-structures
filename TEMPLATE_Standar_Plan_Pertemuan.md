# Standar Plan Pertemuan — Template Course C DSA

Dokumen ini adalah **template & aturan baku** untuk merencanakan setiap pertemuan dalam course
"Algorithms, C & Data Structures with AI Applications". Gunakan struktur ini sebagai patokan
untuk Pertemuan 2 dan seterusnya. Pertemuan 1 (`Plan_Pertemuan_1.md`) adalah contoh penerapannya.

---

## ⚙️ Instruksi untuk AI (WAJIB DIIKUTI)

Saat membantu membuat plan atau materi untuk pertemuan mana pun, AI **harus**:

1. **Plan dulu sampai disetujui.** Selalu susun/revisi *plan* terlebih dahulu dan tunjukkan ke
   user. Jangan membuat materi apa pun sebelum user menyatakan plannya sudah **OK**. Iterasi
   plan sampai user setuju.

2. **Konfirmasi sebelum membuat materi.** Pembuatan komponen (Materi, Task, Optional Task,
   Panduan Instruktur) **selalu butuh konfirmasi user** terlebih dahulu. Jangan langsung
   generate file — tanyakan dulu, tunggu persetujuan, baru buat.

3. **Tanya/suggest jumlah DAN jenis Task & Optional Task.** Keduanya tidak baku — bergantung pada
   bobot, kompleksitas materi, dan tahap belajar. **Task wajib** (minimal 1, bisa lebih untuk
   materi berat); **Optional Task tidak wajib**. Sebelum membuat, AI **harus bertanya atau memberi
   saran** berapa jumlah masing-masing **dan jenis task yang sesuai** (lihat katalog jenis task &
   panduan di Bagian 4), lalu tunggu keputusan user.

   **Jenis task default adalah todo-task (gaya Kaggle).** AI memilih/menyarankan jenis berdasarkan
   bobot materi & tahap belajar, dari katalog: *todo-task*, *comment-guided*, atau *mini project*.
   **Todo-task dipakai sebagai default untuk mekanik inti** (lebih mudah dibaca daripada penanda
   `____`). **Beberapa task dalam satu pertemuan boleh berbeda jenis** (mis. Task A = todo-task untuk
   mekanik inti, Task B = mini project sebagai integrasi).

   **Ajukan daftar problem konkret dulu — biarkan user memilih sebelum generate.** Bersamaan dengan
   menanyakan jumlah & jenis, AI **harus menyajikan shortlist problem/task yang akan digenerate**
   untuk pertemuan itu (lebih banyak dari yang dibutuhkan agar user bisa memilih). Tiap item memuat:
   **judul singkat**, **1 kalimat deskripsi**, **jenis task**, dan **tingkat kesulitan**. User
   memilih / menyetujui / menukar problem mana yang dipakai. **AI tidak boleh membuat Task atau
   Materi sebelum daftar problem ini disetujui** — jangan "tancap gas" generate sebelum user pick.

4. **Satu file per komponen + simpan dalam folder pertemuan.** Materi (`.md`), Task (`.c`),
   Optional Task (`.md`), dan Panduan Instruktur (`.md`) masing-masing file terpisah, tanpa
   slide. Semua file satu pertemuan disimpan dalam **satu folder** dengan format:
   `Pertemuan-<NN>-<Slug_Judul_Materi>`. **Judul materi pada nama folder tidak boleh memuat
   simbol spesial** (`,` `&` `/` `:` dst.) — ubah jadi slug memakai underscore `_` sebagai
   pemisah kata. Contoh: judul "Intro to C, Problem Solving & AI Engineering" →
   `Pertemuan-1-Intro_to_C_Problem_Solving_AI_Engineering`.
   Jika Task lebih dari satu, beri akhiran huruf: `<NN>_Task_A.c`, `<NN>_Task_B.c`, dst.
   **Bila satu Task punya sub-soal, pecah jadi file terpisah per sub-soal** (`<NN>_Task_A1.c`,
   `<NN>_Task_A2.c`, dst.) — lihat detail di Bagian 4.B.

5. **Kode harus ramah pemula.** Semua contoh kode di Materi (dan kerangka di Task) ditulis agar
   mudah dipahami pemula — **tidak oversimplified** (jangan menghilangkan langkah penting,
   hindari "magic" yang membingungkan) dan **tidak overcomplicated** (hindari trik, sintaks
   ringkas yang membingungkan, atau abstraksi prematur). Pedoman:
   - Penamaan variabel/fungsi jelas dan deskriptif (hindari `a`, `b`, `x` bila tak perlu).
   - Satu konsep baru per contoh; bangun bertahap dari sederhana ke kompleks.
   - Beri komentar secukupnya untuk menjelaskan *kenapa*, bukan sekadar *apa*.
   - Gunakan gaya penulisan kode yang konsisten di seluruh pertemuan.
   - Utamakan keterbacaan dibanding kepintaran/keringkasan kode.

6. **Self-critique sebelum menyerahkan.** Setiap materi/komponen yang AI hasilkan **harus
   diperiksa sendiri terhadap template ini sebelum ditunjukkan ke user**. AI menandai
   (flag) setiap pelanggaran atau inkonsistensi terhadap aturan template — mis. jenis task tak
   sesuai bobot, edge case tak tercakup di Panduan Instruktur, penamaan/folder salah, kode tidak
   ramah pemula. Sampaikan hasil self-critique singkat bersama deliverable, bukan disembunyikan.

7. **Feedback loop ke template.** Setiap kali user merevisi sebuah plan/materi yang dihasilkan
   dan **puas dengan hasilnya**, AI harus menanyakan: **"apakah revisi ini perlu dimasukkan ke
   template?"** — agar perbaikan merambat balik ke standar. Jika user setuju, AI memperbarui
   `TEMPLATE_Standar_Plan_Pertemuan.md`.

---

## 1. Identitas Pertemuan

- **Pertemuan ke-:** _(nomor)_
- **Judul / Topik:** _(dari silabus)_
- **Durasi:** 2 jam (120 menit)
- **Tools:** _(mis. VS Code, ChatGPT / Claude AI)_

---

## 2. Tujuan Pertemuan (Outcome)

Daftar 3–5 hal konkret yang harus dikuasai siswa di akhir pertemuan. Ambil & turunkan dari
kolom *Outcome* pada silabus.

---

## 3. Alur Sesi (Rundown 120 menit)

Tabel pembagian waktu. Sesuaikan segmen dengan materi, tapi sertakan minimal:
pembukaan → materi inti → latihan/penerapan → penutup & tugas.

| Waktu | Segmen | Aktivitas |
|---|---|---|
| 0–15 | Pembukaan | **Fleksibel, sesuai keputusan tutor:** review/recap materi pertemuan sebelumnya, dan/atau motivasi singkat (opsional). Untuk pertemuan pertama, fokus ke pengenalan course. |
| ... | ... | ... |
| 115–120 | Penutup & Tugas | Rekap + preview pertemuan berikutnya |

---

## 4. Komponen Deliverable (WAJIB minimal 4 jenis file, dalam 1 folder pertemuan)

Semua file disimpan dalam folder `Pertemuan-<NN>-<Slug_Judul_Materi>` (judul tanpa simbol
spesial, kata dipisah `_`). Contoh: `Pertemuan-1-Intro_to_C_Problem_Solving_AI_Engineering`.

### A. Materi (`<NN>_Materi.md`) — untuk siswa
Bahan **bacaan siswa**: penjelasan konsep, contoh kode beranotasi, tabel/diagram pendukung,
dan demo penggunaan AI yang relevan dengan topik. File ini murni materi belajar siswa — tidak
memuat catatan untuk pengajar.

### B. Task (`<NN>_Task.c`) — **WAJIB**
File **C (`.c`)**, bukan Markdown, supaya bisa dikerjakan & dikompilasi langsung di editor.
**Wajib ada setiap pertemuan.** **Jenis task tidak baku** — AI menyarankan jenis yang sesuai
bobot materi & tahap belajar, lalu konfirmasi ke user.

**Katalog jenis task:**
- **Todo-task** *(default)* — gaya Kaggle. Kerangka kode menyediakan **signature fungsi yang sudah
  jadi** dengan body kosong yang ditandai `// TODO:` dan `// Tulis kodemu di sini`. Setiap task/fungsi
  dilengkapi: **deskripsi singkat** apa yang harus dicapai, **contoh input → output** konkret
  (mis. `hitung_luas(5, 3) -> 15`), dan **hint bertahap** bila perlu. File tetap bisa dikompilasi
  sejak awal. Lebih mudah dibaca daripada penanda `____`, dan fokus ke logika bukan menebak sintaks.
  Cocok sebagai **default untuk mekanik inti** di hampir semua materi.
- **Comment-guided** — varian todo-task yang lebih ringan: kerangka berisi komentar `// langkah 1:`,
  `// langkah 2:` yang memandu siswa menulis kode dari nol per langkah, tanpa signature per fungsi.
  Cocok untuk melatih alur berpikir berurutan pada satu blok kode (mis. isi `main()`).
- **Mini project** — spesifikasi kecil yang diimplementasikan siswa dari awal. Cocok untuk materi
  berat / akhir tahap sebagai integrasi.

> **Catatan format todo-task:** jangan gunakan penanda `____` di tengah ekspresi (sulit dibaca).
> Sebagai gantinya, sediakan signature/kerangka utuh dan tandai bagian yang dikosongkan dengan
> `// TODO:` plus baris kosong tempat siswa menulis. Hindari `/* ____ */` (merusak multi-line comment).

**Beberapa task dalam satu pertemuan boleh berbeda jenis** (mis. Task A = todo-task untuk
mekanik inti, Task B = mini project sebagai integrasi).

**Jumlah Task menyesuaikan bobot materi** — AI harus tanya/suggest dulu. Acuan (bukan aturan kaku):
- Materi ringan/konseptual → **1** task.
- Materi sedang → **1–2** task.
- Materi berat/banyak implementasi (mis. Linked List, Sorting, Tree) → **2–3** task.

Jika lebih dari satu, beri penamaan berakhiran huruf: `<NN>_Task_A.c`, `<NN>_Task_B.c`, dst.
(Bila hanya satu, cukup `<NN>_Task.c`.)

**Pecah file bila satu Task punya sub-soal.** Jika Task A (atau Task B, dst.) berisi beberapa
sub-soal/sub-bagian yang berdiri sendiri, **AI memecahnya menjadi file `.c` terpisah per sub-soal**,
jangan menumpuk semuanya dalam satu file. Penamaannya: huruf untuk grup task + angka untuk sub-soal —
`<NN>_Task_A1.c`, `<NN>_Task_A2.c`, `<NN>_Task_A3.c`, lalu `<NN>_Task_B1.c`, dst. Tujuannya tiap file
fokus ke satu latihan yang bisa dikompilasi & dikerjakan mandiri, sehingga lebih mudah dibaca dan
dinilai. (Bila sebuah grup task hanya satu soal, cukup `<NN>_Task_A.c` tanpa angka.)

### C. Optional Task (`<NN>_Optional_Task.md`) — **TIDAK WAJIB**
File **Markdown (`.md`)** berisi soal/latihan tambahan bertingkat (deskripsi problem statement,
bukan kode). Siswa membuat sendiri file `.c`-nya sebagai jawaban. Bersifat **opsional** —
sediakan bila relevan. **Jumlah menyesuaikan materi** — AI harus tanya/suggest dulu.

Panduan saran jumlah (acuan, bukan aturan kaku):
- Materi ringan/konseptual → **1–2** optional task.
- Materi sedang → **2–3** optional task.
- Materi berat/banyak implementasi → **2–3** optional task.

Tingkat kesulitan minimal mencakup:
- **Level Mudah** — variasi langsung dari contoh kelas.
- **Level Menantang** — moderat, butuh berpikir tapi tidak terlalu sulit.

_(Tambahkan level lain seperti "Lanjutan" hanya bila materi menuntut dan user setuju.)_

### D. Panduan Instruktur (`<NN>_Panduan_Instruktur.md`)
File terpisah berisi **instruksi penyampaian untuk pengajar** — tidak diberikan ke siswa. Memuat:
- **Persiapan sebelum kelas** (environment, akun AI, contoh kode/dataset yang perlu disiapkan).
- **Catatan pedagogis** (urutan penyampaian, analogi, miskonsepsi umum, tips menjelaskan).
- **Edge case** yang perlu diwaspadai/ditekankan untuk topik ini.
- **Alasan pemilihan jenis task** — untuk tiap task, catat singkat *kenapa* jenis itu dipilih
  (mis. "Task B mini project karena materi sudah cukup untuk integrasi mandiri"),
  demi transparansi pedagogis.
- **Panduan rundown** (apa yang ditekankan di tiap segmen, kunci jawaban Task bila perlu).

---

## 5. Problem Statement (bila relevan)

Sediakan 1–3 problem statement yang sesuai topik, untuk dipakai sebagai contoh utama di Materi
dan/atau soal di Task & Optional Task. Untuk tiap problem, tandai: **(a)** apakah direkomendasikan
sebagai contoh utama, **(b)** tingkat kesulitan, dan **(c) tag jenis task yang disarankan**
(todo-task / comment-guided / mini project).

Contoh format:
> **Problem X — Judul** *(level mudah · jenis: todo-task)*

> Catatan: persiapan pengajar dan catatan pedagogis **tidak** ditaruh di sini maupun di
> `Materi.md`. Keduanya masuk ke file **Panduan Instruktur** (Komponen D).

---

## 6. Checklist Review

Dijalankan user (dengan bantuan self-critique AI) di dua titik persetujuan.

**Sebelum menyetujui PLAN:**
- [ ] Timing rundown terasa realistis untuk 120 menit (tak ada segmen yang kepadatan/terlalu longgar).
- [ ] Jenis task yang disarankan cocok dengan bobot materi & tahap belajar.
- [ ] Jumlah Task (wajib) & Optional Task (opsional) sesuai acuan bobot materi.
- [ ] Problem statement punya tag tingkat kesulitan **dan** jenis task.

**Sebelum mulai GENERATE materi (setelah plan OK):**
- [ ] AI sudah menyajikan shortlist problem konkret (judul + 1 kalimat + jenis + tingkat kesulitan).
- [ ] User sudah memilih/menyetujui problem mana yang dipakai — tidak ada generate sebelum ini.

**Sebelum menyetujui MATERI final:**
- [ ] Kurva kesulitan dari Task → Optional Task terasa pas (naik bertahap, tidak melompat).
- [ ] Edge case sudah tercakup di Panduan Instruktur.
- [ ] Panduan Instruktur memuat alasan pemilihan jenis tiap task.
- [ ] Kode ramah pemula (tidak oversimplified / overcomplicated); todo-task memakai signature utuh + `// TODO:` (bukan penanda `____`).
- [ ] Penamaan file & folder sesuai standar (slug tanpa simbol spesial, `_A`/`_B` bila >1 task).
- [ ] Hasil **self-critique AI** sudah dilampirkan & tidak ada pelanggaran template tersisa.

---

## ✅ Alur Kerja Standar (Ringkasan)

1. AI menyusun **plan** berdasarkan template ini → tunjukkan ke user.
2. Iterasi plan sampai user bilang **OK** (pakai **Checklist Review — sebelum menyetujui plan**).
3. AI **konfirmasi** akan membuat materi, **tanya jumlah + jenis Task (wajib) & Optional Task (opsional)**,
   dan **menyajikan shortlist problem konkret** (judul + 1 kalimat + jenis + tingkat kesulitan) untuk
   dipilih user. Tunggu user pick/setuju daftar problem **sebelum** generate apa pun.
4. Setelah user setuju (jumlah, jenis, **dan daftar problem**), AI membuat file dalam folder `Pertemuan-<NN>-<Slug_Judul_Materi>`:
   Materi (`.md`), Task (`.c` — satu atau lebih, beri akhiran `_A`/`_B` bila >1),
   Optional Task (`.md`), dan Panduan Instruktur (`.md`).
5. AI menjalankan **self-critique terhadap template**, lampirkan ringkasannya saat menyerahkan
   deliverable (user pakai **Checklist Review — sebelum menyetujui materi final**).
6. Jika user merevisi & puas, AI bertanya: **"apakah revisi ini perlu dimasukkan ke template?"**
   dan memperbarui template bila disetujui.
