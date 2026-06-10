# Pertemuan 10 — Panduan Instruktur

**Topik:** Recursion & Backtracking
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + `gcc` berjalan normal di komputer demo.
- [ ] Akun Claude AI aktif untuk demo visualisasi call stack (segmen 95–110).
- [ ] Siapkan folder kerja kosong untuk demo live.

### Kode Demo yang Perlu Disiapkan

```c
/* demo_rekursi.c — faktorial & sum, siap diketik live */
#include <stdio.h>

int faktorial(int n) {
    if (n == 0) return 1;
    return n * faktorial(n - 1);
}

int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}

int main() {
    printf("faktorial(5) = %d\n", faktorial(5));  /* 120 */
    printf("sum(10)      = %d\n", sum(10));        /* 55  */
    return 0;
}
```

```c
/* demo_maze.c — maze solver minimal untuk demo live */
#include <stdio.h>
#define N 4
int maze[N][N] = {
    {0,0,1,0},
    {1,0,0,1},
    {1,1,0,0},
    {1,1,1,0}
};
void cetak(){ for(int r=0;r<N;r++){ for(int k=0;k<N;k++) printf("%c ",maze[r][k]==0?'.':maze[r][k]==1?'#':'*'); printf("\n"); } printf("\n"); }
int selesaikan(int r, int k){
    if(r<0||r>=N||k<0||k>=N||maze[r][k]!=0) return 0;
    if(r==N-1&&k==N-1){ maze[r][k]=2; return 1; }
    maze[r][k]=2;
    if(selesaikan(r+1,k)||selesaikan(r,k+1)||selesaikan(r-1,k)||selesaikan(r,k-1)) return 1;
    maze[r][k]=0;
    return 0;
}
int main(){ cetak(); selesaikan(0,0); cetak(); return 0; }
```

---

## B. Catatan Pedagogis

### Rekursi: Mulai dari Base Case (Menit 15–40)

**Aturan #1 yang harus selalu ditekankan: tulis base case DULU.**
Sebelum menulis recursive case, tanyakan: "Apa kondisi terkecil yang bisa langsung dijawab?" Jika base case belum jelas, rekursi akan salah.

**Visualisasi stack di papan — wajib dilakukan:**
Saat menjelaskan `faktorial(3)`, gambar kotak-kotak di papan secara vertikal:
```
┌──────────────┐
│ faktorial(0) │  ← return 1
├──────────────┤
│ faktorial(1) │  ← return 1×1
├──────────────┤
│ faktorial(2) │  ← return 2×1
├──────────────┤
│ faktorial(3) │  ← return 3×2
├──────────────┤
│    main()    │
└──────────────┘
```
Gambar kotak naik satu per satu saat rekursi turun, lalu hapus dari atas sambil menuliskan nilai balik. Ini lebih membekas dari sekadar trace teks.

**Miskonsepsi yang sering terjadi: "rekursi lebih lambat, kenapa dipakai?"**
Rekursi lebih lambat dari iterasi jika kita tidak hati-hati (overhead call stack). Tapi rekursi membuat *beberapa* masalah jauh lebih mudah ditulis dan dipahami — terutama masalah yang bersifat rekursif secara alami (pohon, maze, backtracking). Setelah konsep dipahami, optimasi (iterasi, memoization) bisa dilakukan.

### Backtracking: Demonstrasi Visual (Menit 65–95)

**Ini adalah bagian tersulit. Jangan rush.**

**Cara terbaik: demo maze di papan dulu, baru kode.**
1. Gambar maze 4×4 di papan (bisa pakai grid spidol).
2. Tandai start dan end.
3. Telusuri langkah demi langkah *dengan spidol dua warna*:
   - Warna A: sel yang sedang dicoba (pilih).
   - Warna B: garis backtrack (hapus dengan tanda X atau warna berbeda).
4. Tunjukkan saat backtrack terjadi: "kita sudah coba semua arah dari sini, ternyata buntu, kita batalkan pilihan ini dan mundur ke persimpangan sebelumnya."

**Tekankan baris backtrack di kode:**
```c
maze[r][k] = 0;   /* ← INI adalah backtrack */
return 0;
```
Minta siswa membayangkan: "Apa yang terjadi kalau baris ini dihapus?" Jawaban: sel yang buntu tidak bisa dikunjungi dari jalur lain → bisa melewatkan solusi yang valid.

**Perbedaan rekursi biasa vs backtracking:**
- Rekursi biasa: setelah memanggil diri sendiri, hasilnya langsung dikembalikan.
- Backtracking: setelah rekursi gagal, kita **undo** perubahan state — ini yang membuat backtracking berbeda.

### Demo AI: Call Stack (Menit 95–110)

**Prompt yang terbukti menghasilkan output berguna:**
```
Tunjukkan call stack untuk fib(4) secara lengkap sebagai pohon rekursi.
Tandai setiap node dengan nilai yang dikembalikan.
```

Setelah AI menghasilkan pohon, tanyakan ke kelas:
- "Berapa kali fib(2) dihitung?" → jawabannya 3 kali.
- "Ini efisien tidak?" → tidak! Inilah kenapa kita butuh memoization atau iterasi untuk Fibonacci besar.

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Recap rekursi dasar dari Pertemuan 2 (jika sudah ada): faktorial, prinsip dasar.
- Atau: perkenalkan rekursi dari nol dengan analogi "fungsi yang memanggil dirinya sendiri, seperti cermin di dalam cermin — tapi harus ada batas agar tidak tak terbatas."

### 15–40 | Rekursi Lanjutan & Call Stack
- Ketik `demo_rekursi.c` dari nol (faktorial dan sum).
- Gambar call stack `faktorial(3)` di papan.
- Tunjukkan bug lupa base case → stack overflow.
- Perkenalkan rekursi bercabang (Fibonacci) — gambar pohon rekursi fib(4).

### 40–65 | Divide and Conquer
- Pola: "masalah besar → sub-masalah kecil → gabungkan".
- Contoh: `sum_array` rekursif, `power` rekursif.
- Tunjukkan `power_cepat`: bagi dua exp → O(log n) vs O(n).

### 65–95 | Backtracking
- Demo maze di papan dulu (2 warna spidol), baru kode.
- Ketik `demo_maze.c` dari nol — tekankan langkah backtrack.
- Tunjukkan: apa yang terjadi jika baris backtrack dihapus?

### 95–110 | AI Visualisasi Call Stack
- Demo pohon rekursi fib(4) dengan AI.
- Tunjukkan: betapa banyak komputasi yang duplikat → motivasi untuk memoization (preview Pertemuan 11).
- Siswa mencoba sendiri: minta AI trace maze solver.

### 110–115 | Latihan Terbimbing
- Siswa kerjakan Task A Soal 1–2 minimal.
- Fokus: pastikan base case ditulis benar terlebih dahulu.

### 115–120 | Penutup & Tugas
- Rekap: base case, call stack, divide & conquer, backtracking (pilih/undo).
- Tugas: selesaikan Task A dan Task B.
- Preview: "Pertemuan 11: Searching & Sorting — Binary Search, Bubble Sort, Selection Sort, dan kenalan pertama dengan Big-O Notation."

---

## D. Kunci Jawaban Task

### Task A (`10_Task_A.c`)

**SOAL 1 — `sum`:**
```c
int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}
```

**SOAL 2 — `power`:**
```c
long long power(long long base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}
```

**SOAL 3 — `fib`:**
```c
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
```

**SOAL 4 — `hitung_digit`:**
```c
int hitung_digit(int n) {
    if (n < 10) return 1;
    return 1 + hitung_digit(n / 10);
}
```

**SOAL 5 — `maks_rekursif`:**
```c
int maks_rekursif(int arr[], int n) {
    if (n == 1) return arr[0];
    int maks_sisa = maks_rekursif(arr, n - 1);
    return arr[n - 1] > maks_sisa ? arr[n - 1] : maks_sisa;
}
```

---

### Task B (`10_Task_B.c`)

**SOAL 1 — `valid`:**
```c
int valid(int m[][KOLOM], int r, int k) {
    return r >= 0 && r < BARIS &&
           k >= 0 && k < KOLOM &&
           m[r][k] == 0;
}
```

**SOAL 2 — `selesaikan`:**
```c
int selesaikan(int m[][KOLOM], int r, int k) {
    if (!valid(m, r, k)) return 0;

    if (r == BARIS - 1 && k == KOLOM - 1) {
        m[r][k] = 2;
        return 1;
    }

    m[r][k] = 2;

    if (selesaikan(m, r + 1, k)) return 1;
    if (selesaikan(m, r, k + 1)) return 1;
    if (selesaikan(m, r - 1, k)) return 1;
    if (selesaikan(m, r, k - 1)) return 1;

    m[r][k] = 0;   /* backtrack */
    return 0;
}
```

**SOAL 3 — `hitung_langkah`:**
```c
int hitung_langkah(int m[][KOLOM]) {
    int hitung = 0;
    for (int r = 0; r < BARIS; r++)
        for (int k = 0; k < KOLOM; k++)
            if (m[r][k] == 2) hitung++;
    return hitung;
}
```

Output yang diharapkan untuk Uji 1:
```
Solusi ditemukan — jalur: (0,0)→(0,1)→(1,1)→(1,2)→(2,2)→(2,3)→(3,3)→(4,3)→(4,4)
Jumlah langkah: 9
```

---

## E. Antisipasi Pertanyaan Umum

**"Kapan harus pakai rekursi, kapan iterasi?"**
Pakai rekursi ketika: (1) masalahnya secara alami rekursif (pohon, maze, backtracking), (2) kode rekursif jauh lebih pendek dan mudah dipahami. Pakai iterasi ketika: (1) rekursi terlalu dalam (risiko stack overflow), (2) performa kritis (iterasi lebih cache-friendly). Sebagai aturan praktis: jika rekursinya bisa ditulis dengan satu atau dua baris, pakai rekursi. Jika butuh lima baris, pikirkan dua kali.

**"Kenapa Fibonacci rekursif sangat lambat?"**
Karena kita menghitung sub-masalah yang sama berulang kali. `fib(30)` dipanggil ratusan juta kali secara total. Solusi: **memoization** (simpan hasil yang sudah dihitung) atau **iterasi** (lebih efisien). Pertemuan 11 akan membahas konsep efisiensi algoritma lebih dalam.

**"Apa bedanya rekursi dan backtracking?"**
Rekursi adalah teknik pemrograman (fungsi memanggil diri sendiri). Backtracking adalah strategi pencarian yang *menggunakan* rekursi: ia mencoba semua kemungkinan dan *membatalkan* (undo) pilihan yang terbukti gagal. Semua backtracking menggunakan rekursi, tapi tidak semua rekursi adalah backtracking.

**"Mengapa urutan coba arah di maze penting?"**
Urutan arah (bawah, kanan, atas, kiri) menentukan jalur mana yang ditemukan pertama — bukan apakah solusi ditemukan. Jika kita ingin jalur terpendek, backtracking saja tidak cukup — kita butuh BFS (Queue, Pertemuan 9) atau Dijkstra's algorithm.
