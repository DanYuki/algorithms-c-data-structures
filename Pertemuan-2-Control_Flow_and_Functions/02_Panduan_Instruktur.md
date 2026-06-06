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
- [ ] Contoh fungsi `hitung_luas` (Bagian A Task B).
- [ ] Contoh fungsi rekursi faktorial — versi loop DAN rekursi sekaligus.

### File yang Disiapkan
- [ ] `02_Materi.md` — bagikan ke siswa di awal sesi.
- [ ] `02_Task_A.c` — bagikan saat segmen latihan percabangan/loop (sekitar menit 65–90).
- [ ] `02_Task_B.c` — bagikan saat segmen latihan fungsi/rekursi.
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
| 15–40 | **Percabangan** | Demo `if/else if/else` dengan Problem 1 (kelulusan). Perkenalkan `switch-case` dengan contoh menu. Tekankan urutan kondisi dan jangan lupa `break`. |
| 40–65 | **Perulangan** | Demo ketiga loop dengan contoh berbeda. Tunjukkan `break` dan `continue`. Sengaja buat infinite loop untuk demo. |
| 65–90 | **Fungsi** | Demo `hitung_luas` (versi tanpa fungsi → dengan fungsi). Jelaskan `void`. Tunjukkan prototype. Bagikan `02_Task_A.c`. |
| 90–105 | **Rekursi** | Gambar call stack faktorial(4) di whiteboard. Demo versi loop vs rekursi berdampingan. Bagikan `02_Task_B.c`. |
| 105–115 | **AI untuk Boilerplate** | Demo prompt buruk vs baik. Tunjukkan cara memvalidasi kode AI. |
| 115–120 | **Penutup & Tugas** | Rekap 5 poin utama. Bagikan `02_Optional_Task.md`. Preview P3: Array & String. |

---

## D. Kunci Jawaban Task A

### Bagian A — if / else if / else

```c
if (nilai >= 85) {
    printf("Hasil: Lulus dengan Pujian\n");
} else if (nilai >= 60) {
    printf("Hasil: Lulus\n");
} else {
    printf("Hasil: Tidak Lulus\n");
}
```

### Bagian B — switch-case

```c
switch (angka_hari) {
    case 1: printf("Hari ke-%d adalah: Senin\n",   angka_hari); break;
    case 2: printf("Hari ke-%d adalah: Selasa\n",  angka_hari); break;
    case 3: printf("Hari ke-%d adalah: Rabu\n",    angka_hari); break;
    case 4: printf("Hari ke-%d adalah: Kamis\n",   angka_hari); break;
    case 5: printf("Hari ke-%d adalah: Jumat\n",   angka_hari); break;
    case 6: printf("Hari ke-%d adalah: Sabtu\n",   angka_hari); break;
    case 7: printf("Hari ke-%d adalah: Minggu\n",  angka_hari); break;
    default: printf("Angka tidak valid. Masukkan angka 1-7.\n");
}
```

### Bagian C — Perulangan

**C1 (for):**
```c
for (i = 1; i <= batas; i++) {
    printf("%d  ", i);
}
```

**C2 (while — hitung digit):**
```c
while (angka_digit > 0) {
    angka_digit = angka_digit / 10;  /* C2a: buang digit terakhir */
    jumlah_digit++;                  /* C2b: hitung digit */
}
```

**C3 (do-while):**
```c
do {
    printf("Tebak angka (1-10): ");
    scanf("%d", &tebakan);
    if (tebakan != rahasia) {
        printf("Salah, coba lagi!\n");
    }
} while (tebakan != rahasia);
```

---

## E. Kunci Jawaban Task B

### Bagian A — Luas & Keliling

```c
int hitung_luas(int panjang, int lebar) {
    return panjang * lebar;
}

int hitung_keliling(int panjang, int lebar) {
    return 2 * (panjang + lebar);
}
```

### Bagian B — Tabel Perkalian (void)

```c
void cetak_tabel_perkalian(int angka) {
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%d x %2d = %2d\n", angka, i, angka * i);
    }
}
```

### Bagian C — Rekursi Pangkat

```c
int pangkat(int basis, int eksponen) {
    if (eksponen == 0) {   /* C1: base case */
        return 1;
    }
    return basis * pangkat(basis, eksponen - 1);  /* C2: recursive case */
}
```

### Bagian D — Pemanggilan di main

```c
printf("Luas     : %d\n", hitung_luas(panjang, lebar));      /* D1 */
printf("Keliling : %d\n", hitung_keliling(panjang, lebar));  /* D2 */
cetak_tabel_perkalian(angka_tabel);                          /* D3 */
printf("3^4 = %d\n", pangkat(3, 4));                        /* D4 */
```

---

## F. Antisipasi Pertanyaan Siswa

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
