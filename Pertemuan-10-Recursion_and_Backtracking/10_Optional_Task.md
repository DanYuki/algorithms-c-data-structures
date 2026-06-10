# Pertemuan 10 — Optional Task: Recursion & Backtracking

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` sendiri sebagai jawabanmu.

---

## Optional Task 1 — Palindrom & Balik String Rekursif (Level: Mudah)

### Latar Belakang

Rekursi sangat natural untuk operasi pada string karena string bisa dilihat sebagai: satu karakter pertama + sisa string (sub-masalah yang lebih kecil).

### Yang Harus Dibuat

Buat file **`optional1_rekursi_string.c`** yang mengimplementasikan dua fungsi berikut:

#### Bagian A — `balik_string`

```c
void balik_string(const char *input, char *output, int panjang);
```

Balik string `input` dan simpan hasilnya di `output` secara rekursif.

**Algoritma rekursif:**
- Base case: `panjang == 0` → selesai, tambahkan `'\0'` ke output.
- Recursive case: salin karakter terakhir `input[panjang-1]` ke posisi pertama output, lalu rekursi untuk sisa string `input[0..panjang-2]`.

Petunjuk implementasi alternatif (lebih sederhana):
```c
void balik_string(const char *input, char *output, int panjang) {
    if (panjang == 0) { *output = '\0'; return; }
    /* salin karakter terakhir ke posisi pertama output */
    *output = input[panjang - 1];
    /* rekursi: balik substring input[0..panjang-2] ke output+1 */
    balik_string(input, output + 1, panjang - 1);
}
```

#### Bagian B — `adalah_palindrom`

```c
int adalah_palindrom(const char *s, int kiri, int kanan);
```

Kembalikan 1 jika substring `s[kiri..kanan]` adalah palindrom, 0 jika bukan.

**Algoritma:**
- Base case 1: `kiri >= kanan` → palindrom (string panjang 0 atau 1 selalu palindrom).
- Base case 2: `s[kiri] != s[kanan]` → bukan palindrom.
- Recursive case: cek substring dalam `(kiri+1, kanan-1)`.

### Di `main()`, uji dengan:

| Input | `balik_string` | `adalah_palindrom` |
|---|---|---|
| `"Halo"` | `"olaH"` | 0 |
| `"racecar"` | `"racecar"` | 1 |
| `"abcba"` | `"abcba"` | 1 |
| `"12321"` | `"12321"` | 1 |
| `"hello"` | `"olleh"` | 0 |

### Contoh Output

```
"Halo"    → balik: "olaH"    | palindrom: tidak
"racecar" → balik: "racecar" | palindrom: ya
"abcba"   → balik: "abcba"   | palindrom: ya
"12321"   → balik: "12321"   | palindrom: ya
"hello"   → balik: "olleh"   | palindrom: tidak
```

---

## Optional Task 2 — N-Queens (Versi 4×4) dengan Backtracking (Level: Menantang)

### Latar Belakang

N-Queens adalah problem klasik backtracking: tempatkan N ratu di papan catur N×N sehingga tidak ada dua ratu yang saling menyerang (tidak boleh berada di baris, kolom, atau diagonal yang sama).

Untuk versi 4×4 (4-Queens), ada tepat **2 solusi**. Tugasmu adalah menemukan dan mencetak semua solusinya.

### Yang Harus Dibuat

Buat file **`optional2_n_queens.c`** yang melakukan hal berikut:

1. Representasikan papan sebagai array integer `int papan[4]` di mana `papan[baris]` menyimpan kolom tempat ratu di baris tersebut diletakkan. Nilai `-1` berarti belum diisi.

2. Implementasikan tiga fungsi:

   ```c
   /* Cek apakah menempatkan ratu di (baris, kolom) aman */
   int aman(int papan[], int baris, int kolom);

   /* Cetak solusi papan saat ini */
   void cetak_papan(int papan[]);

   /* Cari semua solusi mulai dari baris tertentu */
   void selesaikan(int papan[], int baris, int *jumlah_solusi);
   ```

3. Logika `aman(papan, baris, kolom)`:
   - Untuk setiap baris `r` sebelum `baris` (0 hingga baris-1):
     - Cek konflik kolom: `papan[r] == kolom`
     - Cek konflik diagonal: `abs(papan[r] - kolom) == abs(r - baris)`
   - Jika ada konflik → return 0 (tidak aman).
   - Jika tidak ada konflik → return 1 (aman).

4. Logika `selesaikan(papan, baris, jumlah_solusi)`:
   - Base case: `baris == 4` → semua ratu sudah ditempatkan → cetak papan dan tambah counter.
   - Recursive case: untuk kolom 0 sampai 3:
     - Jika `aman(papan, baris, kolom)`:
       - **Pilih:** `papan[baris] = kolom`
       - **Jelajahi:** `selesaikan(papan, baris + 1, jumlah_solusi)`
       - **Batalkan:** `papan[baris] = -1`

5. Format cetak papan: gunakan `Q` untuk ratu dan `.` untuk kosong.

### Contoh Output

```
=== 4-Queens: Mencari Semua Solusi ===

Solusi #1:
. Q . .
. . . Q
Q . . .
. . Q .

Solusi #2:
. . Q .
Q . . .
. . . Q
. Q . .

Total solusi: 2
```

### Petunjuk

- `#include <stdlib.h>` untuk `abs()`.
- Inisialisasi `papan[]` dengan `{-1, -1, -1, -1}` di awal.
- Panggil `selesaikan(papan, 0, &jumlah)` untuk memulai pencarian dari baris 0.
- Saat mencetak papan: loop baris 0–3, untuk setiap baris cetak kolom 0–3 — `Q` jika `papan[baris] == kolom`, `.` jika tidak.
- Untuk N=8, ada 92 solusi. Kamu bisa mencoba memperbesarnya dengan mengganti konstanta `N`.
