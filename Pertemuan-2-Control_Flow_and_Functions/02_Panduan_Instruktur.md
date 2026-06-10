# Panduan Instruktur — Pertemuan 2

**Topik:** Control Flow & Functions
**Durasi:** 120 menit
**Dokumen ini TIDAK diberikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + GCC siap di mesin demo.
- [ ] Buat folder demo kosong `demo_p2/` untuk demo live.
- [ ] Tes kompilasi program sederhana dengan `if-else` dan loop sebelum kelas.

### Akun AI
- [ ] Login ke ChatGPT atau Claude — untuk demo bagian "AI untuk Boilerplate" (menit 105–115).
- [ ] Siapkan dua tab: satu editor kode, satu AI chat.

### Kode Demo yang Perlu Disiapkan
- [ ] Contoh `if-else if-else` (kelulusan dengan kategori) — Problem 1 dari plan.
- [ ] Contoh `switch-case` menu sederhana.
- [ ] Contoh `for`, `while`, `do-while` masing-masing satu.
- [ ] Contoh fungsi `hitung_luas` (dari Materi — untuk demo konsep fungsi & DRY).
- [ ] Contoh fungsi rekursi faktorial — versi loop DAN rekursi sekaligus.

> **Catatan konteks task:** Materi memakai contoh generik (kelulusan, persegi panjang) untuk
> menjelaskan konsep, sedangkan Task memakai **kasus dunia nyata** (potongan pajak gaji, tarif
> parkir, kalkulator BMI, progres tabungan) agar siswa melihat penerapan konkretnya. Perbedaan
> konteks ini disengaja — melatih siswa memindahkan konsep ke situasi baru (transfer of learning).

### File yang Disiapkan
- [ ] `02_Materi.md` — bagikan ke siswa di awal sesi.
- [ ] `02_Task_A1.c` (potongan pajak gaji) & `02_Task_A2.c` (tarif parkir) — bagikan saat segmen percabangan (sekitar menit 15–40).
- [ ] `02_Task_B.c` (kalkulator BMI & progres tabungan) — bagikan saat segmen latihan fungsi (sekitar menit 65–90).
- [ ] `02_Optional_Task.md` — bagikan di akhir sebagai PR.

---

## B. Catatan Pedagogis

### Urutan Penyampaian yang Direkomendasikan

1. **Recap P1 singkat** (maks 10 menit): tanya 2–3 siswa secara acak tentang format specifier, cara compile, dan satu konsep pseudocode. Jangan habiskan waktu terlalu lama di sini.

2. **Percabangan** — mulai dengan menunjukkan *masalah* yang tidak bisa diselesaikan tanpa percabangan, baru perkenalkan `if`. Jangan langsung jelaskan semua operator sekaligus; perkenalkan bertahap saat dibutuhkan.

3. **Perulangan** — jelaskan perbedaan ketiga loop dengan satu analogi konsisten:
   - `for` = "Kamu tahu mau memutar lagu berapa kali"
   - `while` = "Kamu putar lagu sampai bosan, tapi tidak tahu kapan bosannya"
   - `do-while` = "Kamu pasti dengar dulu satu lagu, baru putuskan mau lanjut atau tidak"

4. **Fungsi** — tekankan prinsip DRY dengan contoh konkret: tunjukkan kode *tanpa* fungsi yang berulang-ulang, lalu refactor ke versi dengan fungsi. Kontras ini lebih berkesan daripada langsung menjelaskan definisi.

5. **Rekursi** — jangan terburu-buru. Gambar "call stack" rekursi faktorial(4) secara manual di whiteboard atau di komentar kode. Banyak siswa baru memahami rekursi setelah melihat visualisasi stack.

### Miskonsepsi Umum & Cara Mengatasinya

| Miskonsepsi | Cara Mengatasinya |
|-------------|-------------------|
| `=` vs `==` dalam kondisi `if` | Tunjukkan error atau perilaku aneh yang terjadi. Biasakan selalu baca error compiler. |
| Lupa `break` di `switch-case` | Demo "fall-through" secara langsung — tunjukkan output yang aneh tanpa `break`, lalu tambahkan `break` dan lihat perbedaannya. |
| `while` vs `do-while` tertukar | Tanya: "Kalau kondisi awal sudah salah dari awal, apakah `while` pernah jalan?" → Tidak. Bandingkan dengan `do-while`. |
| Infinite loop karena lupa update variabel | Sengaja demo infinite loop (Ctrl+C untuk stop), tunjukkan lokasi bug, lalu fix. |
| Rekursi tanpa base case → stack overflow | Demo crash dengan `faktorial_rekursi` tanpa base case. Ingatkan: *base case adalah "pintu keluar" rekursi.* |
| Mengira parameter dan variabel global sama | Tekankan: parameter hanya ada *di dalam* fungsi. Di luar fungsi, variabel itu tidak ada. |

### Poin Kunci yang Sering Terlewat

- **Urutan kondisi di `if-else if`** sangat penting — cek kondisi paling spesifik/ketat dulu.
- **Prototype fungsi** — jika fungsi didefinisikan setelah `main`, compiler akan komplain tanpa prototype. Tunjukkan keduanya.
- **Rekursi mengkonsumsi stack** — setiap pemanggilan fungsi rekursif menambah satu frame ke call stack. Ini yang menyebabkan stack overflow jika terlalu dalam.

---

## C. Panduan Rundown

| Waktu | Segmen | Yang Perlu Ditekankan |
|-------|--------|-----------------------|
| 0–15 | **Pembukaan / Recap P1** | Recap singkat: struktur C, tipe data, pseudocode. Jangan melewati kalau banyak yang belum paham. |
| 15–40 | **Percabangan** | Demo `if/else if/else` dengan Problem 1 (kelulusan). Perkenalkan `switch-case` dengan contoh menu. Tekankan urutan kondisi dan jangan lupa `break`. Bagikan `02_Task_A1.c` (pajak gaji) & `02_Task_A2.c` (tarif parkir). |
| 40–65 | **Perulangan** | Demo ketiga loop dengan contoh berbeda. Tunjukkan `break` dan `continue`. Sengaja buat infinite loop untuk demo. |
| 65–90 | **Fungsi** | Demo `hitung_luas` (versi tanpa fungsi → dengan fungsi). Jelaskan `void`. Tunjukkan prototype. Bagikan `02_Task_B.c` (kalkulator BMI & progres tabungan). |
| 90–105 | **Rekursi** | Gambar call stack faktorial(4) di whiteboard. Demo versi loop vs rekursi berdampingan. Arahkan ke Optional Task Soal 2. |
| 105–115 | **AI untuk Boilerplate** | Demo prompt buruk vs baik. Tunjukkan cara memvalidasi kode AI. |
| 115–120 | **Penutup & Tugas** | Rekap 5 poin utama. Bagikan `02_Optional_Task.md`. Preview P3: Array & String. |

---

## C2. Alasan Pemilihan Jenis & Konteks Task

| Task | Jenis | Konteks dunia nyata | Alasan |
|------|-------|---------------------|--------|
| A1 | comment-guided | Potongan pajak gaji bertingkat | Mekanik `if/else if/else` paling jelas lewat tarif pajak berjenjang; siswa mengisi blok logika di `main`, kerangka sudah bisa dikompilasi. |
| A2 | comment-guided | Tarif parkir per jenis kendaraan | `switch` cocok memetakan satu kode (jenis kendaraan) ke banyak nilai tetap; perhitungan total memperkuat aritmatika dari P1. |
| B | todo-task | Kalkulator BMI + progres tabungan | Tiga fungsi melatih tiga konsep berbeda (return value, `void` + percabangan, `void` + loop) dalam konteks yang dikenal siswa sehari-hari. |

> **Catatan konteks:** Optional Task Soal 2 (faktorial) & Soal 3 (FizzBuzz) sengaja **dipertahankan
> dalam bentuk klasik** — keduanya bernilai pedagogis tinggi (faktorial = contoh kanonik rekursi;
> FizzBuzz = soal interview legendaris). Soal 1 direframe jadi tabel proyeksi tabungan agar konteks
> nested-loop terasa nyata.

---

## D. Kunci Jawaban Task A

### Task A1 — if / else if / else (potongan pajak gaji)

```c
/* TUGAS 1: tentukan persen_pajak */
if (gaji_kotor <= 4000000) {
    persen_pajak = 0;
} else if (gaji_kotor <= 10000000) {
    persen_pajak = 5;
} else {
    persen_pajak = 15;
}

/* TUGAS 2: hitung potongan & gaji bersih */
int potongan    = gaji_kotor * persen_pajak / 100;
int gaji_bersih = gaji_kotor - potongan;

/* TUGAS 3: cetak hasil */
printf("Persen pajak  : %d%%\n", persen_pajak);
printf("Potongan      : %d\n", potongan);
printf("Gaji bersih   : %d\n", gaji_bersih);
```

> **Catatan:** tulis `gaji_kotor * persen_pajak / 100` (perkalian dulu, baru bagi) — bukan
> `gaji_kotor / 100 * persen_pajak` — agar pembagian bilangan bulat tidak membuang ketelitian.
> Untuk angka gaji yang sangat besar, `int` bisa overflow; di tahap ini cukup gunakan nilai wajar.

### Task A2 — switch-case (tarif parkir)

```c
switch (jenis) {
    case 1:
        printf("Kendaraan : Motor\n");
        tarif_per_jam = 2000;
        break;
    case 2:
        printf("Kendaraan : Mobil\n");
        tarif_per_jam = 4000;
        break;
    case 3:
        printf("Kendaraan : Bus/Truk\n");
        tarif_per_jam = 8000;
        break;
    default:
        printf("Jenis kendaraan tidak valid. Pilih 1, 2, atau 3.\n");
}
```

> Bagian perhitungan total (`tarif_per_jam * jam`) sudah disediakan di kerangka dan hanya berjalan
> saat `tarif_per_jam > 0`, sehingga input tidak valid tidak ikut mencetak total.

---

## E. Kunci Jawaban Task B

### Fungsi 1 — hitung_bmi

```c
float hitung_bmi(float berat, float tinggi) {
    return berat / (tinggi * tinggi);
}
```

### Fungsi 2 — cetak_kategori_bmi

```c
void cetak_kategori_bmi(float bmi) {
    if (bmi < 18.5) {
        printf("Kategori: Kurus\n");
    } else if (bmi < 25.0) {
        printf("Kategori: Normal\n");
    } else if (bmi < 30.0) {
        printf("Kategori: Gemuk\n");
    } else {
        printf("Kategori: Obesitas\n");
    }
}
```

### Fungsi 3 — cetak_progres_tabungan

```c
void cetak_progres_tabungan(int setoran_bulanan, int jumlah_bulan) {
    int saldo = 0;
    int bulan;
    for (bulan = 1; bulan <= jumlah_bulan; bulan++) {
        saldo = saldo + setoran_bulanan;
        printf("Bulan %d: %d\n", bulan, saldo);
    }
}
```

### main — Pemanggilan Fungsi

```c
int main() {
    printf("=== Kalkulator BMI ===\n");

    printf("Orang A (berat=60.0 kg, tinggi=1.70 m)\n");
    printf("BMI: %.1f\n", hitung_bmi(60.0, 1.70));
    cetak_kategori_bmi(hitung_bmi(60.0, 1.70));

    printf("\nOrang B (berat=85.0 kg, tinggi=1.70 m)\n");
    printf("BMI: %.1f\n", hitung_bmi(85.0, 1.70));
    cetak_kategori_bmi(hitung_bmi(85.0, 1.70));

    printf("\n=== Progres Tabungan (setoran 500000/bulan) ===\n");
    cetak_progres_tabungan(500000, 4);

    return 0;
}
```

> **Tentang nilai BMI:** `60 / (1.70 × 1.70) = 20.76` → dibulatkan `%.1f` jadi `20.8` (Normal);
> `85 / (1.70 × 1.70) = 29.41` → `29.4` (Gemuk). Kedua parameter bertipe `float`, jadi tidak ada
> jebakan pembagian bilangan bulat di sini.

---

## F. Panduan Pengecekan Bertahap Task B

Task B dirancang agar dikerjakan **fungsi per fungsi**. Minta siswa memanggil instruktur setiap kali satu fungsi selesai — jangan tunggu semua selesai baru dicek.

### Fungsi 1 — hitung_bmi
Tanya siswa: *"Apa yang dikembalikan fungsi ini, dan tipenya apa?"* Pastikan ada `return`, bukan `printf`, dan tipe kembaliannya `float`.
Kesalahan umum: lupa `return`; menulis `berat / tinggi * tinggi` tanpa kurung (salah urutan operasi — jadi `(berat/tinggi)*tinggi`); atau mendeklarasikan parameter sebagai `int` sehingga BMI kehilangan desimal.

### Fungsi 2 — cetak_kategori_bmi
Tanya siswa: *"Kenapa cukup tulis `else if (bmi < 25.0)` tanpa menyebut batas bawah 18.5 lagi?"*
Kesalahan umum: rentang tumpang tindih atau ada celah; menukar urutan sehingga semua nilai jatuh ke kategori pertama. Tekankan: cek berurutan dari kecil ke besar, kondisi sebelumnya sudah "memotong" rentang di bawahnya.
Verifikasi cepat: `cetak_kategori_bmi(20.8)` → Normal; `cetak_kategori_bmi(29.4)` → Gemuk.

### Fungsi 3 — cetak_progres_tabungan
Minta siswa compile dan jalankan, lalu bandingkan output dengan Expected Output di header file.
Kesalahan umum: lupa menginisialisasi `saldo = 0`; menambahkan setoran *setelah* mencetak (sehingga Bulan 1 = 0); loop mulai dari 0 atau berhenti di `bulan < jumlah_bulan` sehingga jumlah baris salah.

### main — Pemanggilan Fungsi
Setelah semua fungsi selesai, minta siswa tulis sendiri semua pemanggilan di `main`, compile, dan cocokkan output dengan Expected Output di header file secara baris per baris.
Kesalahan umum: argumen tertukar (`hitung_bmi(1.70, 60.0)`), lupa `\n` atau baris kosong pemisah, format `%d` untuk BMI alih-alih `%.1f`.

---

## G. Antisipasi Pertanyaan Siswa

**Q: Kapan harus pakai `for`, kapan `while`, kapan `do-while`?**
A: `for` kalau tahu pasti berapa kali iterasi. `while` kalau tidak tahu kapan berhentinya. `do-while` kalau harus jalan minimal sekali dulu baru cek kondisinya — paling sering dipakai untuk menu interaktif.

**Q: Kenapa fungsi harus didefinisikan sebelum `main`?**
A: Compiler membaca file dari atas ke bawah. Kalau fungsi belum "dikenal" saat `main` dipanggil, compiler akan komplain. Solusinya: taruh fungsi sebelum `main`, atau gunakan *prototype* di atas `main`.

**Q: Apa bedanya parameter dan variabel biasa?**
A: Parameter hidup hanya di dalam fungsi itu. Setiap kali fungsi dipanggil, parameter mendapat nilai baru (dari argumen yang dikirim). Di luar fungsi, parameter tidak bisa diakses.

**Q: Rekursi terasa lebih sulit dari loop — apakah wajib dipakai?**
A: Tidak selalu — banyak masalah bisa diselesaikan dengan loop saja. Tapi rekursi akan sangat berguna saat belajar Tree dan Graph nanti, karena struktur data itu secara alami "rekursif" (setiap node punya child yang juga node). Sekarang cukup pahami konsep dasarnya.

**Q: Kenapa AI kadang menghasilkan kode yang salah?**
A: AI menghasilkan kode berdasarkan pola, bukan pemahaman logika seperti manusia. Ia bisa salah kalau promptnya ambigu atau masalahnya di luar data pelatihannya. Makanya validasi selalu diperlukan.
