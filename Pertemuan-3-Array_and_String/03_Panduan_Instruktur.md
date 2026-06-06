# Panduan Instruktur — Pertemuan 3

**Topik:** Array & String
**Durasi:** 120 menit
**Dokumen ini TIDAK diberikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + GCC siap di mesin demo.
- [ ] Buat folder demo kosong `demo_p3/` untuk demo live.
- [ ] Tes kompilasi program array dan string sebelum kelas.

### Akun AI
- [ ] Login ke ChatGPT atau Claude — untuk demo bagian "AI untuk Optimasi String" (menit 105–115).

### Kode Demo yang Perlu Disiapkan
- [ ] Contoh iterasi array 1D (cukup deklarasi + loop cetak).
- [ ] Contoh statistik array (jumlah, max, min) — Problem 1 dari plan.
- [ ] Contoh nested loop untuk matriks 3×3.
- [ ] Contoh program string: deklarasi, `printf`/`scanf`, dan `fgets`.
- [ ] Contoh penggunaan `strlen`, `strcpy`, `strcmp`, `strcat` masing-masing satu.

### File yang Disiapkan
- [ ] `03_Materi.md` — bagikan ke siswa di awal sesi.
- [ ] `03_Task_A.c` — bagikan saat segmen latihan array (sekitar menit 55–85).
- [ ] `03_Task_B.c` — bagikan saat segmen latihan string.
- [ ] `03_Optional_Task.md` — bagikan di akhir sebagai PR.

---

## B. Catatan Pedagogis

### Urutan Penyampaian yang Direkomendasikan

1. **Recap P2 singkat** (maks 10 menit): tanya singkat tentang loop dan fungsi dari P2.

2. **Array 1D** — mulai dengan motivasi: "Bagaimana simpan 30 nilai siswa tanpa 30 variabel?" Perkenalkan konsep array, lalu indexing. **Selalu gambar visualisasi kotak** di whiteboard saat menjelaskan array — ini sangat membantu.

3. **Indexing 0-based** — tekankan berulang kali. Ini adalah sumber bug terbesar di topik ini. Tunjukkan apa yang terjadi jika mengakses `array[5]` pada array berukuran 5 (compiler tidak selalu error, tapi outputnya tidak dapat diprediksi).

4. **Array 2D** — gunakan analogi spreadsheet/tabel. Tunjukkan bahwa `matriks[baris][kolom]` mirip dengan "baris ke sekian, kolom ke sekian" di Excel.

5. **String** — ini bagian terpenting dan paling banyak miskonsepsi. Tekankan:
   - String = array of char + `\0` di ujung.
   - Selalu siapkan 1 ruang ekstra untuk `\0`.
   - `scanf("%s")` tidak membaca spasi — gunakan `fgets` untuk kalimat.

6. **`<string.h>`** — demo setiap fungsi satu per satu dengan contoh kecil sebelum menggabungkannya.

### Miskonsepsi Umum & Cara Mengatasinya

| Miskonsepsi | Cara Mengatasinya |
|-------------|-------------------|
| Mengira indeks array mulai dari 1 | Gambar array sebagai kotak di whiteboard dengan label indeks mulai 0. |
| Akses array[ukuran] (off-by-one) | Demo: buat array[5], akses array[5], tunjukkan output tak terduga. Tekankan: indeks valid adalah 0–4. |
| Lupa `\0` saat deklarasi manual | Tunjukkan perbedaan antara `char s[] = "Halo"` (otomatis ada `\0`) vs `char s[4] = {'H','a','l','o'}` (tidak ada `\0` — berbahaya). |
| Menyalin string dengan `=` | Tunjukkan error kompilasi jika mencoba `tujuan = sumber`. Jelaskan kenapa: nama array adalah alamat, bukan nilai. |
| Membandingkan string dengan `==` | Demo: `"apel" == "apel"` membandingkan alamat memori, bukan isi. Tunjukkan `strcmp` sebagai solusi. |
| Ukuran buffer `strcat` terlalu kecil | Demo buffer overflow kecil-kecilan (hati-hati — di beberapa kompiler bisa crash). Tekankan aturan ukuran buffer. |

### Poin Kunci yang Sering Terlewat

- **`(float)` cast sebelum pembagian integer** — `total / 5` dan `(float)total / 5` menghasilkan hasil berbeda. Demo ini secara eksplisit.
- **`scanf("%s", nama)` tidak butuh `&`** — karena nama array sudah berupa alamat. Berbeda dengan `scanf("%d", &angka)`. Siswa sering bingung konsistensinya.
- **`fgets` menyimpan `\n`** — mengingatkan siswa bahwa ada newline di akhir string hasil `fgets` adalah penting agar tidak bingung dengan output yang terlihat ada baris kosong ekstra.

---

## C. Panduan Rundown

| Waktu | Segmen | Yang Perlu Ditekankan |
|-------|--------|-----------------------|
| 0–15 | **Pembukaan / Recap P2** | Recap singkat loop dan fungsi. Motivasi array: "bagaimana simpan 100 nilai?" |
| 15–40 | **Array 1D** | Visualisasi kotak, indexing 0-based, iterasi loop. Demo statistik (jumlah/max/min). |
| 40–60 | **Array 2D** | Analogi tabel, nested loop, akses `[baris][kolom]`. Demo cetak matriks 3×3. |
| 60–85 | **String di C** | Demo deklarasi, null terminator `\0`, `printf`/`scanf`/`fgets`. Tunjukkan bug tanpa `\0`. Bagikan `03_Task_A.c`. |
| 85–105 | **`<string.h>`** | Demo satu per satu: `strlen`, `strcpy`, `strcmp`, `strcat`. Tekankan bahaya `=` dan `==` untuk string. Bagikan `03_Task_B.c`. |
| 105–115 | **AI untuk Optimasi String** | Demo prompt → output AI → validasi manual bersama siswa. |
| 115–120 | **Penutup & Tugas** | Rekap 5 konsep utama. Bagikan `03_Optional_Task.md`. Preview P4: Pointer & Memory. |

---

## D. Kunci Jawaban Task A

### Bagian A — Statistik Array 1D

```c
// (A1) kondisi dan update loop input
for (i = 0; i < 5; i++) {
    scanf("%d", &nilai[i]);  // (A2)
}

terbesar = nilai[0];  // (A3)
terkecil = nilai[0];  // (A4)

for (i = 0; i < 5; i++) {
    total = total + nilai[i];    // (A6)
    if (nilai[i] > terbesar) {   // (A7)
        terbesar = nilai[i];
    }
    if (nilai[i] < terkecil) {   // (A8)
        terkecil = nilai[i];
    }
}

printf("Rata-rata: %.1f\n", (float)total / 5);  // (A9)
```

### Bagian B — Pencarian

```c
for (i = 0; i < 5; i++) {        // (B1) batas atas: 5
    if (nilai[i] == cari) {       // (B2)
        ...
    }
}
if (ditemukan == 0) { ... }       // (B3)
```

### Bagian C — Matriks 2x3

```c
// (C1a) batas baris: 2, (C1b) batas kolom: 3
for (baris = 0; baris < 2; baris++) {
    for (kolom = 0; kolom < 3; kolom++) {
        scanf("%d", &matriks[baris][kolom]);  // (C2)
    }
}

for (baris = 0; baris < 2; baris++) {
    for (kolom = 0; kolom < 3; kolom++) {
        printf("%3d", matriks[baris][kolom]);  // (C4)
        jumlah = jumlah + matriks[baris][kolom];  // (C5)
    }
    printf("\n");
}
```

---

## E. Kunci Jawaban Task B

### Bagian 0 — Header

```c
#include <string.h>
```

### Bagian A — strlen & manual

```c
printf("Panjang (strlen) : %d\n", strlen(kata));  // (A1)

for (i = 0; kata[i] != '\0'; i++) {               // (A2a)
    panjang_manual++;
}
```

### Bagian B — strcpy & strcmp

```c
strcpy(tujuan, sumber);  // (B1)

if (strcmp(kata1, kata2) == 0) { ... }  // (B2a)
if (strcmp(kata1, kata3) == 0) { ... }  // (B2b)
```

### Bagian C — strcat

```c
strcat(pesan, nama);     // (C1)
strcat(pesan, penutup);  // (C2)
```

### Bagian D — Hitung Vokal

```c
for (i = 0; kata[i] != '\0'; i++) {  // (D1)
    c = kata[i];
    if (c=='a'||c=='i'||c=='u'||c=='e'||c=='o' ||
        c=='A'||c=='I'||c=='U'||c=='E'||c=='O') {  // (D2)
        jumlah_vokal++;
    }
}
```

---

## F. Antisipasi Pertanyaan Siswa

**Q: Kenapa indeks array mulai dari 0, bukan 1?**
A: Di C, nama array adalah alamat elemen pertama di memori. `array[i]` secara internal berarti "pergi ke alamat awal, lalu maju `i` langkah". Jadi elemen pertama ada di 0 langkah dari awal, bukan 1.

**Q: Apa yang terjadi kalau kita akses array di luar batasnya?**
A: Di C tidak ada pengecekan otomatis — program akan membaca/menulis ke memori yang tidak seharusnya. Hasilnya tidak terduga: bisa crash, bisa data korup, bisa berjalan seolah normal tapi dengan nilai salah.

**Q: Kenapa `scanf("%s", nama)` tidak pakai `&`?**
A: Nama array (seperti `nama`) sudah mewakili alamat elemen pertamanya. Jadi `nama` dan `&nama[0]` adalah hal yang sama. Untuk tipe data biasa seperti `int`, kita pakai `&angka` karena `angka` hanya mewakili nilai, bukan alamat.

**Q: Kapan pakai `scanf` dan kapan `fgets` untuk string?**
A: `scanf("%s")` untuk satu kata (berhenti di spasi). `fgets` untuk satu baris penuh termasuk spasi. Untuk program yang memproses nama lengkap atau kalimat, `fgets` lebih aman.

**Q: Kenapa `strcmp` mengembalikan 0 untuk "sama"? Bukankah lebih intuitif kalau 1?**
A: Nilai kembalian `strcmp` menunjukkan *perbedaan* antara dua string secara leksikografis: 0 = tidak ada perbedaan (sama), negatif = s1 < s2, positif = s1 > s2. Ini juga berguna untuk sorting string.
