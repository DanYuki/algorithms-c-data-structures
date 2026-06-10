# Pertemuan 10 — Recursion & Backtracking

**Course:** Algorithms, C & Data Structures with AI Applications
**Durasi:** 120 menit

---

## Daftar Isi

1. [Anatomi Rekursi: Base Case & Recursive Case](#1-anatomi-rekursi-base-case--recursive-case)
2. [Call Stack: Apa yang Terjadi di Balik Layar](#2-call-stack-apa-yang-terjadi-di-balik-layar)
3. [Divide and Conquer: Pecah Masalah Menjadi Lebih Kecil](#3-divide-and-conquer-pecah-masalah-menjadi-lebih-kecil)
4. [Backtracking: Coba → Mundur → Coba Lagi](#4-backtracking-coba--mundur--coba-lagi)
5. [Studi Kasus: Maze Solver](#5-studi-kasus-maze-solver)
6. [AI untuk Visualisasi Call Stack](#6-ai-untuk-visualisasi-call-stack)

---

## 1. Anatomi Rekursi: Base Case & Recursive Case

**Rekursi** adalah teknik di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan versi yang lebih kecil dari masalah yang sama.

Setiap fungsi rekursif harus punya dua bagian:

| Bagian | Peran | Tanpa ini... |
|---|---|---|
| **Base case** | Kondisi berhenti — tidak rekursi lagi | Fungsi tidak pernah berhenti → **stack overflow** |
| **Recursive case** | Memanggil diri sendiri dengan input yang *lebih kecil* | Masalah tidak menyusut → tak terbatas |

### Contoh: Faktorial

```
n! = n × (n-1) × (n-2) × ... × 1
0! = 1  (base case)
```

```c
#include <stdio.h>

long long faktorial(int n) {
    /* Base case */
    if (n == 0) return 1;

    /* Recursive case: n! = n × (n-1)! */
    return n * faktorial(n - 1);
}

int main() {
    printf("5! = %lld\n", faktorial(5));   /* 120 */
    printf("0! = %lld\n", faktorial(0));   /* 1  */
    return 0;
}
```

### Contoh: Penjumlahan 1 sampai N

```c
int sum(int n) {
    if (n == 0) return 0;            /* base case */
    return n + sum(n - 1);           /* recursive case */
}
```

Trace `sum(4)`:
```
sum(4)
  = 4 + sum(3)
        = 3 + sum(2)
              = 2 + sum(1)
                    = 1 + sum(0)
                              = 0
                    = 1 + 0 = 1
              = 2 + 1 = 3
        = 3 + 3 = 6
  = 4 + 6 = 10
```

### Rekursi Bercabang: Fibonacci

Fibonacci memiliki **dua** pemanggilan rekursif — ini disebut **rekursi bercabang**.

```
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)  untuk n ≥ 2
```

```c
int fib(int n) {
    if (n == 0) return 0;   /* base case 1 */
    if (n == 1) return 1;   /* base case 2 */
    return fib(n - 1) + fib(n - 2);   /* dua cabang rekursi */
}
```

> **Perhatian:** Fibonacci rekursif murni sangat tidak efisien — `fib(5)` menghitung `fib(3)` sebanyak 2 kali, `fib(2)` sebanyak 3 kali, dan seterusnya. Untuk nilai besar, gunakan iterasi atau memoization. Di sini kita pakai untuk belajar konsep rekursi bercabang.

---

## 2. Call Stack: Apa yang Terjadi di Balik Layar

Setiap kali fungsi dipanggil, komputer menyimpan "konteks eksekusi" (variabel lokal, alamat kembali) di sebuah struktur bernama **call stack**. Saat fungsi selesai, konteksnya di-pop dari stack.

### Trace Call Stack untuk `faktorial(3)`

```
Panggilan pertama:   faktorial(3) dimasukkan ke stack
  Panggilan kedua:   faktorial(2) dimasukkan ke stack
    Panggilan ketiga: faktorial(1) dimasukkan ke stack
      Panggilan ke-4: faktorial(0) dimasukkan ke stack
                      faktorial(0) selesai → return 1 → pop
      faktorial(1) mendapat 1 → return 1×1=1 → pop
    faktorial(2) mendapat 1 → return 2×1=2 → pop
  faktorial(3) mendapat 2 → return 3×2=6 → pop
Hasil akhir: 6
```

Visualisasi stack pada saat semua pemanggilan sudah masuk (sebelum ada yang kembali):

```
┌─────────────────┐  ← TOP
│ faktorial(0)    │
├─────────────────┤
│ faktorial(1)    │
├─────────────────┤
│ faktorial(2)    │
├─────────────────┤
│ faktorial(3)    │
├─────────────────┤
│     main()      │
└─────────────────┘  ← BOTTOM
```

### Kenapa Stack Overflow Terjadi?

Setiap panggilan rekursif menggunakan memori stack. Jika rekursi terlalu dalam (base case tidak tercapai, atau input terlalu besar), stack habis → **stack overflow**.

```c
/* BAHAYA: base case salah → rekursi tak terbatas */
int faktorial_rusak(int n) {
    if (n == 1) return 1;   /* BUG: n=0 tidak ditangani → rekursi terus */
    return n * faktorial_rusak(n - 1);
}
/* faktorial_rusak(0) → faktorial_rusak(-1) → faktorial_rusak(-2) → ... → CRASH */
```

---

## 3. Divide and Conquer: Pecah Masalah Menjadi Lebih Kecil

**Divide and Conquer** adalah strategi algoritmik di mana kita:
1. **Divide** — pecah masalah menjadi sub-masalah yang lebih kecil.
2. **Conquer** — selesaikan sub-masalah (biasanya secara rekursif).
3. **Combine** — gabungkan hasil sub-masalah menjadi solusi akhir.

Rekursi adalah alat utama untuk mengimplementasikan strategi ini.

### Contoh: Jumlah Elemen Array secara Rekursif

```c
int jumlah_array(int arr[], int n) {
    if (n == 0) return 0;                        /* base case: array kosong */
    return arr[n - 1] + jumlah_array(arr, n - 1); /* elemen terakhir + sisa */
}

int main() {
    int data[] = {3, 1, 4, 1, 5};
    printf("Jumlah: %d\n", jumlah_array(data, 5));  /* 14 */
    return 0;
}
```

### Contoh: Power (Pangkat)

Menghitung `base^exp` secara rekursif:

```c
long long power(long long base, int exp) {
    if (exp == 0) return 1;                    /* base case: x^0 = 1 */
    return base * power(base, exp - 1);        /* x^n = x × x^(n-1) */
}
```

Versi lebih efisien menggunakan **fast power** (bagi dua):

```c
long long power_cepat(long long base, int exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long half = power_cepat(base, exp / 2);
        return half * half;         /* x^n = (x^(n/2))^2 */
    }
    return base * power_cepat(base, exp - 1);
}
```

> `power_cepat` menghitung `2^10` dalam 4 langkah, bukan 10. Ini adalah O(log n) vs O(n).

---

## 4. Backtracking: Coba → Mundur → Coba Lagi

**Backtracking** adalah teknik pencarian di mana kita:
1. **Pilih** — ambil satu pilihan dari opsi yang tersedia.
2. **Jelajahi** — lanjutkan rekursi dengan pilihan tersebut.
3. **Batalkan** — jika jalan buntu, *undo* pilihan dan coba opsi lain.

```
Kerangka umum backtracking:

void selesaikan(state) {
    if (state adalah solusi) {
        catat/cetak solusi;
        return;
    }
    for setiap pilihan yang tersedia {
        pilih(pilihan);              /* tandai: pilihan diambil */
        selesaikan(state baru);      /* rekursi */
        batalkan(pilihan);           /* undo: kembali ke state sebelumnya */
    }
}
```

### Analogi: Labirin

Bayangkan kamu di dalam labirin. Kamu mencoba satu arah. Kalau buntu, kamu **mundur** ke persimpangan terakhir dan coba arah lain. Kamu terus mencoba sampai menemukan jalan keluar atau semua opsi habis.

```
Labirin 4×4:
S = Start, E = End, # = Dinding, . = Kosong

S . . #
# # . #
. . . .
# # # E

Langkah backtracking:
→ Coba kanan: (0,1) ✓
→ Coba kanan: (0,2) ✓
→ Kanan? (0,3) = Dinding ✗
→ Coba bawah: (1,2) ✓
→ Coba bawah: (2,2) ✓
→ Coba kanan: (2,3) ✓
→ Coba bawah: (3,3) = E → SELESAI!
```

---

## 5. Studi Kasus: Maze Solver

### Representasi Maze

Maze direpresentasikan sebagai array 2D integer:
- `0` = jalur yang bisa dilewati
- `1` = dinding (tidak bisa dilewati)
- `2` = jalur yang sudah dikunjungi (marking)

```c
#define BARIS 5
#define KOLOM 5

int maze[BARIS][KOLOM] = {
    {0, 0, 1, 1, 1},
    {1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1},
    {1, 1, 1, 0, 0}
};
/* Start: (0,0), End: (4,4) */
```

### Fungsi Utama: `selesaikan_maze`

```c
#include <stdio.h>

#define BARIS 5
#define KOLOM 5

int maze[BARIS][KOLOM] = {
    {0, 0, 1, 1, 1},
    {1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1},
    {1, 1, 1, 0, 0}
};

void cetak_maze() {
    for (int r = 0; r < BARIS; r++) {
        for (int k = 0; k < KOLOM; k++) {
            if      (maze[r][k] == 0) printf(". ");
            else if (maze[r][k] == 1) printf("# ");
            else if (maze[r][k] == 2) printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

int selesaikan(int r, int k) {
    /* Batas array atau dinding */
    if (r < 0 || r >= BARIS || k < 0 || k >= KOLOM) return 0;
    if (maze[r][k] != 0) return 0;

    /* Base case: tujuan tercapai */
    if (r == BARIS - 1 && k == KOLOM - 1) {
        maze[r][k] = 2;   /* tandai tujuan */
        return 1;
    }

    /* Tandai sel ini sebagai bagian dari jalur */
    maze[r][k] = 2;

    /* Coba keempat arah: bawah, kanan, atas, kiri */
    if (selesaikan(r + 1, k)) return 1;   /* bawah  */
    if (selesaikan(r, k + 1)) return 1;   /* kanan  */
    if (selesaikan(r - 1, k)) return 1;   /* atas   */
    if (selesaikan(r, k - 1)) return 1;   /* kiri   */

    /* BACKTRACK: semua arah buntu → batalkan penandaan */
    maze[r][k] = 0;
    return 0;
}

int main() {
    printf("Maze awal:\n");
    cetak_maze();

    if (selesaikan(0, 0)) {
        printf("Solusi ditemukan (jalur ditandai *):\n");
        cetak_maze();
    } else {
        printf("Tidak ada solusi.\n");
    }
    return 0;
}
```

Output:
```
Maze awal:
. . # # #
# . . # #
# # . . #
# # # . #
# # # . .

Solusi ditemukan (jalur ditandai *):
* * # # #
# * * # #
# # * * #
# # # * #
# # # * *
```

### Poin Kunci Backtracking di Kode Ini

- **Pilih:** `maze[r][k] = 2` — tandai sel sebagai bagian jalur.
- **Jelajahi:** `selesaikan(r+1, k)`, `selesaikan(r, k+1)`, dst.
- **Batalkan (backtrack):** `maze[r][k] = 0` — hapus penandaan jika semua arah buntu.
- Tanpa baris `maze[r][k] = 0` di akhir, sel yang sudah dicoba tidak bisa dikunjungi lagi dari jalur lain → solusi bisa tidak ditemukan.

---

## 6. AI untuk Visualisasi Call Stack

### Meminta AI Menggambarkan Call Stack

Rekursi bisa membingungkan karena eksekusinya tidak linear. AI sangat berguna untuk menggambarkan call stack langkah demi langkah.

```
Tunjukkan call stack untuk pemanggilan faktorial(4) secara lengkap.
Format: setiap baris adalah satu frame stack, dengan indentasi untuk kedalaman.
Tunjukkan kapan setiap frame masuk ke stack dan kapan di-pop, termasuk nilai yang dikembalikan.
```

### Meminta AI Melacak Backtracking

```
Diberikan maze 4×4 berikut:
  0 0 1 0
  1 0 0 1
  1 1 0 0
  1 1 1 0

Telusuri langkah demi langkah fungsi selesaikan(0,0).
Tunjukkan setiap sel yang ditandai (pilih) dan dibatalkan (backtrack).
```

### Yang Perlu Divalidasi dari Output AI

- [ ] Apakah call stack yang digambarkan AI sesuai dengan urutan push dan pop yang benar?
- [ ] Apakah langkah backtrack (pembatalan penandaan sel) digambarkan dengan benar?
- [ ] Compile dan jalankan kodenya — apakah output sesuai dengan trace AI?
- [ ] Coba ubah posisi start/end atau tambah dinding — apakah solusi AI tetap benar?

> Rekursi dan backtracking adalah topik di mana visualisasi sangat membantu. Minta AI menggambar pohon rekursi atau animasi langkah-langkah backtracking — lalu verifikasi dengan menjalankan kode aslinya.
