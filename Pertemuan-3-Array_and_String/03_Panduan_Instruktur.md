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
- [ ] `03_Task_A1.c` — array 1D statistik, bagikan saat segmen array (sekitar menit 55–70).
- [ ] `03_Task_A2.c` — pencarian array, bagikan setelah A1 selesai.
- [ ] `03_Task_A3.c` — array 2D matriks, bagikan setelah A2 selesai.
- [ ] `03_Task_B1.c` — strlen, bagikan saat segmen string.h (sekitar menit 85–90).
- [ ] `03_Task_B2.c` — strcpy & strcmp, bagikan setelah B1 selesai.
- [ ] `03_Task_B3.c` — strcat, bagikan setelah B2 selesai.
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
| 60–85 | **String di C** | Demo deklarasi, null terminator `\0`, `printf`/`scanf`/`fgets`. Tunjukkan bug tanpa `\0`. Bagikan `03_Task_A1/A2/A3.c` bertahap. |
| 85–105 | **`<string.h>`** | Demo satu per satu: `strlen`, `strcpy`, `strcmp`, `strcat`. Tekankan bahaya `=` dan `==` untuk string. Bagikan `03_Task_B1/B2/B3.c` bertahap. |
| 105–115 | **AI untuk Optimasi String** | Demo prompt → output AI → validasi manual bersama siswa. |
| 115–120 | **Penutup & Tugas** | Rekap 5 konsep utama. Bagikan `03_Optional_Task.md`. Preview P4: Pointer & Memory. |

---

## D. Kunci Jawaban Task A

### Task A1 — Statistik Array 1D

```c
for (i = 0; i < 5; i++) {           /* (A1) kondisi & naik */
    scanf("%d", &nilai[i]);          /* (A2) */
}

terbesar = nilai[0];                 /* (A3) */
terkecil = nilai[0];                 /* (A4) */

for (i = 0; i < 5; i++) {
    total = total + nilai[i];        /* (A6) */
    if (nilai[i] > terbesar) {       /* (A7) */
        terbesar = nilai[i];
    }
    if (nilai[i] < terkecil) {       /* (A8) */
        terkecil = nilai[i];
    }
}

printf("Rata-rata: %.1f\n", (float)total / 5);  /* (A9) */
```

### Task A2 — Pencarian Array

```c
for (i = 0; i < 5; i++) {           /* (B1) batas atas: 5 */
    if (nilai[i] == cari) {          /* (B2) */
        ...
    }
}
if (ditemukan == 0) { ... }          /* (B3) */
```

### Task A3 — Matriks 2x3

```c
for (baris = 0; baris < 2; baris++) {           /* (C1a) */
    for (kolom = 0; kolom < 3; kolom++) {        /* (C1b) */
        scanf("%d", &matriks[baris][kolom]);     /* (C2) */
    }
}

for (baris = 0; baris < 2; baris++) {
    for (kolom = 0; kolom < 3; kolom++) {
        printf("%3d", matriks[baris][kolom]);    /* (C4) */
        jumlah = jumlah + matriks[baris][kolom]; /* (C5) */
    }
    printf("\n");
}
```

### Panduan Pengecekan Bertahap Task A

Minta siswa selesaikan satu file per satu, lalu compile dan panggil instruktur sebelum lanjut ke file berikutnya.

**Task A1 — Statistik:**
Cek: apakah inisialisasi `terbesar` dan `terkecil` pakai `nilai[0]`, bukan `0`?
Kesalahan umum: inisialisasi dengan `0` — `terkecil = 0` selalu jadi terkecil kalau semua input positif; `terbesar = 0` bisa benar tapi hanya kebetulan.
Cek juga: apakah (A9) pakai `(float)total / 5`, bukan `total / 5`? Tunjukkan perbedaan outputnya kalau salah.

**Task A2 — Pencarian:**
Tanya siswa: *"Kenapa ada variabel `ditemukan`? Kenapa tidak langsung `printf` saja tanpa flag?"*
Kesalahan umum: lupa `break` setelah ditemukan (program tetap berjalan dan bisa cetak "Tidak ditemukan" padahal sudah ketemu).

**Task A3 — Matriks:**
Tanya siswa: *"Kenapa loop `baris` di luar dan `kolom` di dalam?"*
Kesalahan umum: menukar `baris` dan `kolom` di `scanf`/`printf` sehingga data terbaca atau tercetak terbalik.
Minta siswa run dan cocokkan output dengan Expected Output di header file baris per baris.

---

## E. Kunci Jawaban Task B

### Task B1 — strlen & Hitung Manual

```c
#include <string.h>                                    /* (0) */

printf("Panjang (strlen) : %d\n", strlen(kata));      /* (A1) */

for (i = 0; kata[i] != '\0'; i++) {                   /* (A2a) */
    panjang_manual++;
}
```

### Task B2 — strcpy & strcmp

```c
#include <string.h>                                    /* (0) */

strcpy(tujuan, sumber);                                /* (B1) */

if (strcmp(kata1, kata2) == 0) { ... }                 /* (B2a) nilai kembalian: 0 */
if (strcmp(kata1, kata3) == 0) { ... }                 /* (B2b) */
```

### Task B3 — strcat

```c
#include <string.h>                                    /* (0) */

strcat(pesan, nama);                                   /* (C1) */
strcat(pesan, penutup);                                /* (C2) */
```

### Panduan Pengecekan Bertahap Task B

Sama seperti Task A — minta siswa selesaikan satu file, compile, panggil instruktur, baru lanjut.

**Task B1 — strlen & manual:**
Tanya: *"Kenapa kondisi loop-nya `kata[i] != '\0'`, bukan `i < 10`?"*
Ini menguji apakah siswa paham null terminator sebagai penanda akhir string.
Kesalahan umum: kondisi loop menggunakan panjang hardcoded; `strlen` dipanggil dengan argumen salah (mis. `strlen("Halo Dunia")` — valid tapi tidak pakai variabel `kata`).

**Task B2 — strcpy & strcmp:**
Tanya: *"Kenapa tidak bisa pakai `tujuan = sumber`?"*
Kesalahan umum: menukar urutan argumen `strcpy(sumber, tujuan)` — string yang harusnya di-copy malah ditimpa.
Tanya juga: *"Apa artinya `strcmp` mengembalikan 0? Kenapa bukan 1?"*

**Task B3 — strcat:**
Cek: apakah ukuran buffer `pesan[60]` cukup untuk menampung `"Selamat datang, "` + nama + `"!"`?
Tanya: *"Apa yang terjadi kalau buffer terlalu kecil?"* — ini momen bagus untuk singgung buffer overflow secara ringan.

---

## F. Kunci Jawaban Optional Task

### Soal 1 — Penjumlahan Dua Matriks

```c
#include <stdio.h>

void cetak_matriks(int m[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int hasil[3][3];
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            hasil[i][j] = A[i][j] + B[i][j];

    printf("Matriks A:\n");  cetak_matriks(A);
    printf("\nMatriks B:\n"); cetak_matriks(B);
    printf("\nHasil A + B:\n"); cetak_matriks(hasil);

    return 0;
}
```

Poin penilaian: apakah siswa membuat fungsi `cetak_matriks` atau menulis loop cetak tiga kali? Fungsi adalah jawaban lebih baik — dorong ke sana kalau belum.

---

### Soal 2 — Cek Palindrom

```c
#include <stdio.h>
#include <string.h>

int main() {
    char kata[51];
    int kiri, kanan, palindrom = 1;

    printf("Masukkan kata: ");
    scanf("%s", kata);

    kiri  = 0;
    kanan = strlen(kata) - 1;

    while (kiri < kanan) {
        if (kata[kiri] != kata[kanan]) {
            palindrom = 0;
            break;
        }
        kiri++;
        kanan--;
    }

    if (palindrom)
        printf("\"%s\" adalah PALINDROM.\n", kata);
    else
        printf("\"%s\" bukan palindrom.\n", kata);

    return 0;
}
```

Poin diskusi: tanya siswa apa yang terjadi pada string panjang ganjil (mis. "katak" panjang 5) — karakter tengah tidak perlu dicek karena `kiri >= kanan` sebelum sampai ke sana.

---

### Soal 3 — Frekuensi Kemunculan Huruf

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char kalimat[101];
    int frekuensi[26] = {0};
    char huruf[26];
    int i, j, tf;
    char tc;

    for (i = 0; i < 26; i++) huruf[i] = 'a' + i;

    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    for (i = 0; kalimat[i] != '\0'; i++) {
        if (isalpha(kalimat[i]))
            frekuensi[tolower(kalimat[i]) - 'a']++;
    }

    /* selection sort descending berdasarkan frekuensi */
    for (i = 0; i < 25; i++) {
        for (j = i + 1; j < 26; j++) {
            if (frekuensi[j] > frekuensi[i]) {
                tf = frekuensi[i]; frekuensi[i] = frekuensi[j]; frekuensi[j] = tf;
                tc = huruf[i];     huruf[i]     = huruf[j];     huruf[j]     = tc;
            }
        }
    }

    printf("\nFrekuensi huruf:\n");
    for (i = 0; i < 26 && frekuensi[i] > 0; i++)
        printf("  %c : %d\n", huruf[i], frekuensi[i]);

    return 0;
}
```

Poin kunci yang perlu dijelaskan jika siswa bingung:
- `tolower(c) - 'a'` → mengubah karakter ke indeks 0–25 berdasarkan nilai ASCII.
- Array `huruf[]` perlu ikut diswap saat sorting, agar label huruf tidak terpisah dari frekuensinya.
- `fgets` menyimpan `\n` di akhir string — tidak masalah karena `isalpha('\n')` mengembalikan 0.

---

## G. Antisipasi Pertanyaan Siswa

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
