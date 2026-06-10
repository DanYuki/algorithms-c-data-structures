# Pertemuan 11 — Panduan Instruktur

**Topik:** Searching Algorithms & Big-O Notation
**Durasi:** 120 menit
**File ini TIDAK dibagikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + `gcc` berjalan normal di komputer demo.
- [ ] Akun ChatGPT / Claude AI aktif untuk demo analisis Big-O (segmen 90–105).
- [ ] Siapkan array angka di papan (mis. 8 elemen terurut) untuk demo binary search manual.

### Kode Demo yang Perlu Disiapkan

```c
/* demo_search.c — perbandingan langkah minimal */
#include <stdio.h>

int main() {
    int arr[100];
    for (int i = 0; i < 100; i++) arr[i] = i * 2;  /* 0,2,4,...,198 */

    int target = 150, l = 0, b = 0;

    /* Linear */
    for (int i = 0; i < 100; i++) { l++; if (arr[i] == target) break; }

    /* Binary */
    int left = 0, right = 99;
    while (left <= right) {
        b++;
        int mid = left + (right - left) / 2;
        if      (arr[mid] == target) break;
        else if (arr[mid] <  target) left  = mid + 1;
        else                         right = mid - 1;
    }

    printf("Linear: %d langkah\n", l);   /* 76 */
    printf("Binary: %d langkah\n", b);   /* 7  */
    return 0;
}
```

---

## B. Catatan Pedagogis

### Linear Search (Menit 15–35)

**Mulai dengan pertanyaan, bukan definisi:**
"Bagaimana kamu mencari nama teman di daftar hadir yang tidak terurut?" — Jawabannya adalah linear search. Tidak ada cara lain selain memeriksa satu per satu.

**Tekankan keunggulan utama:** tidak butuh data terurut. Ini sering dilupakan siswa yang terlalu fokus pada "linear lambat" — padahal untuk data acak atau data kecil, linear search adalah satu-satunya pilihan yang valid.

### Binary Search (Menit 35–60)

**Demo manual di papan — WAJIB sebelum kode:**
Tulis 8 angka terurut di papan: `[3, 8, 11, 15, 27, 36, 42, 50]`. Cari angka 36.
- Tunjukkan: `mid = (0+7)/2 = 3`, `arr[3] = 15 < 36` → cari di kanan
- `mid = (4+7)/2 = 5`, `arr[5] = 36` → KETEMU!
- Hanya 2 langkah dari 8 elemen.

**Kesalahan paling umum: lupa prasyarat terurut.**
Demo ini: cari 15 di array `{15, 3, 42, 8, 27}` dengan binary search:
- `mid = 2`, `arr[2] = 42 > 15` → cari kiri `[15, 3]`
- `mid = 0`, `arr[0] = 15` → DITEMUKAN? Ya, kebetulan.
- Tapi cari 8: `mid = 2`, `arr[2] = 42 > 8` → kiri `[15, 3]`
- `mid = 0`, `arr[0] = 15 > 8` → kiri... TIDAK ADA → return -1. **BUG!**
- Ini membuktikan: binary search pada data tidak terurut = hasil tidak dapat dipercaya.

**Rumus `mid` yang aman:**
```c
mid = left + (right - left) / 2;   /* BENAR */
mid = (left + right) / 2;           /* BISA OVERFLOW jika indeks besar */
```

### Big-O (Menit 60–90)

**Jangan mulai dengan rumus — mulai dengan intuisi:**
"Kalau kamu punya daftar 10 nama, berapa lama mencarinya? 100 nama? 1000 nama? Kalau setiap 10× lipat butuh 10× lebih lama → linear. Kalau setiap 10× lipat hanya butuh +3 langkah → logaritmik."

**Tabel konkret yang harus ada di papan:**
```
n = 10:       Linear = 10,    Binary = ~4
n = 100:      Linear = 100,   Binary = ~7
n = 1.000:    Linear = 1.000, Binary = ~10
n = 1.000.000: Linear = 1.000.000, Binary = ~20
```

**Cara membaca Big-O dari loop — tiga aturan cukup untuk pemula:**
1. Satu loop 0..n = O(n)
2. Loop yang membagi dua (i *= 2 atau left/right) = O(log n)
3. Loop bersarang (dua level) = O(n²)

**Miskonsepsi: "O(n²) selalu buruk"**
Tidak selalu. Untuk n = 5, O(n²) = 25 operasi — sangat cepat. Big-O relevan saat n besar. Selalu kontekstualisasikan: "untuk berapa banyak data ini akan dipakai?"

### Demo AI: Analisis Big-O (Menit 90–105)

**Alur demo yang terbukti efektif:**
1. Ketik potongan kode sederhana (loop bersarang) di chat AI.
2. Minta AI: "Tentukan Big-O fungsi ini dan jelaskan baris per baris."
3. Review bersama siswa — apakah penalaran AI benar?
4. Tunjukkan kasus di mana AI **bisa salah**: loop dengan kondisi berhenti tidak standard.

**Prompt untuk demo:**
```
Tentukan Big-O fungsi berikut dan jelaskan dengan menghitung berapa kali setiap baris dieksekusi:

void f(int n) {
    for (int i = 0; i < n; i++)       // baris A
        for (int j = i; j < n; j++)   // baris B
            printf("x");              // baris C
}
```
Jawaban benar: O(n²). Loop dalam mulai dari `i` (bukan 0), sehingga total iterasi = n + (n-1) + ... + 1 = n(n+1)/2 ≈ n²/2 → O(n²).

---

## C. Panduan Rundown

### 0–15 | Pembukaan
- Motivasi: "Kita sudah punya data di berbagai struktur. Sekarang: bagaimana cara mencarinya dengan efisien?"
- Perkenalkan pertanyaan benchmark: "Butuh berapa langkah untuk mencari di 1 juta data?"

### 15–35 | Linear Search
- Implementasi langsung — kode sangat pendek, fokus pada analisis kasus terbaik/terburuk.
- Tekankan: tidak butuh data terurut = keunggulan utama.

### 35–60 | Binary Search
- Demo manual di papan dulu, baru kode.
- Demo bug binary search pada data tidak terurut.
- Implementasi iteratif → rekursif.

### 60–90 | Big-O Notation
- Tabel konkret di papan.
- Tiga aturan membaca Big-O dari loop.
- Latihan: siswa menebak Big-O potongan kode sebelum instruktur menjelaskan.

### 90–105 | Demo AI
- Analisis Big-O loop bersarang dengan AI.
- Tunjukkan kasus AI bisa salah (loop i *= 2).

### 105–115 | Latihan Terbimbing
- Siswa kerjakan Task A Soal 1–3.
- Fokus: pastikan binary search menghasilkan -1 untuk elemen yang tidak ada.

### 115–120 | Penutup & Tugas
- Rekap: dua strategi search, prasyarat binary, Big-O sebagai alat analisis.
- Tugas: selesaikan Task A dan Task B.
- Preview: "Pertemuan 12: Sorting — Bubble Sort, Selection Sort, Insertion Sort. Kita akan lihat mengapa sorting itu O(n²) dan bagaimana Merge Sort mencapai O(n log n)."

---

## D. Kunci Jawaban Task

### Task A (`11_Task_A.c`)

**SOAL 1 — `linear_search`:**
```c
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;
    return -1;
}
```

**SOAL 2 — `linear_search_langkah`:**
```c
int linear_search_langkah(int arr[], int n, int target, int *langkah) {
    *langkah = 0;
    for (int i = 0; i < n; i++) {
        (*langkah)++;
        if (arr[i] == target) return i;
    }
    return -1;
}
```

**SOAL 3 — `binary_search`:**
```c
int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if      (arr[mid] == target) return mid;
        else if (arr[mid] <  target) left  = mid + 1;
        else                         right = mid - 1;
    }
    return -1;
}
```

**SOAL 4 — `binary_search_langkah`:**
```c
int binary_search_langkah(int arr[], int n, int target, int *langkah) {
    *langkah = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        (*langkah)++;
        int mid = left + (right - left) / 2;
        if      (arr[mid] == target) return mid;
        else if (arr[mid] <  target) left  = mid + 1;
        else                         right = mid - 1;
    }
    return -1;
}
```

Output yang diharapkan untuk Soal 5 (array 100 elemen, 0,2,4,...,198):
```
Cari   0 | Linear:  1 langkah | Binary: ~7 langkah
Cari 100 | Linear: 51 langkah | Binary: ~3 langkah
Cari 198 | Linear:100 langkah | Binary: ~7 langkah
Cari 199 | Linear:100 langkah | Binary: ~7 langkah
```

---

### Task B (`11_Task_B.c`)

**SOAL 1 — `binary_search_rekursif`:**
```c
int binary_search_rekursif(int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if      (arr[mid] == target) return mid;
    else if (arr[mid] <  target) return binary_search_rekursif(arr, mid+1, right, target);
    else                         return binary_search_rekursif(arr, left, mid-1, target);
}
```

**SOAL 2 — `binary_search_rekursif_langkah`:**
```c
int binary_search_rekursif_langkah(int arr[], int left, int right,
                                   int target, int *kedalaman) {
    (*kedalaman)++;
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if      (arr[mid] == target) return mid;
    else if (arr[mid] <  target) return binary_search_rekursif_langkah(arr, mid+1, right, target, kedalaman);
    else                         return binary_search_rekursif_langkah(arr, left, mid-1, target, kedalaman);
}
```

**SOAL 4 — Jawaban Analisis Big-O:**

| Potongan | Big-O | Alasan |
|---|---|---|
| A | O(n) | Satu loop 0..n |
| B | O(n²) | Dua loop bersarang, masing-masing 0..n |
| C | O(log n) | i digandakan tiap iterasi → berhenti setelah log₂(n) langkah |
| D | O(n²) | O(n) + O(n²) = O(n²) — suku terbesar menang |
| E | O(2ⁿ) | Dua cabang rekursi, kedalaman n → 2⁰+2¹+...+2ⁿ = 2ⁿ⁺¹−1 |

---

## E. Antisipasi Pertanyaan Umum

**"Kapan harus sorting data dulu sebelum pakai binary search?"**
Jika kamu hanya perlu mencari satu kali, sorting + binary search = O(n log n) + O(log n) = O(n log n). Ini lebih lambat dari linear search O(n) untuk satu pencarian. Tapi jika kamu perlu mencari berkali-kali (k kali), sorting + k × binary search = O(n log n) + k×O(log n). Untuk k besar, ini jauh lebih efisien dari k × O(n).

**"Apakah binary search bisa dipakai untuk string?"**
Ya, dengan modifikasi: ganti perbandingan integer dengan `strcmp`. `strcmp(arr[mid], target)` mengembalikan negatif, 0, atau positif — gunakan tanda ini seperti < 0, == 0, > 0.

**"Kenapa O(n²) disebut kuadratik? Kuadrat dari apa?"**
Kuadrat dari n. Jika n = 10, O(n²) ≈ 100. Jika n = 100, O(n²) ≈ 10.000. Setiap kali n naik 10×, waktu naik 100× (10²). Ini berasal dari dua loop bersarang: loop luar n kali × loop dalam n kali = n² total operasi.

**"Apakah ada yang lebih cepat dari O(log n) untuk pencarian?"**
Ya: O(1) — akses langsung dengan hash table (pencarian berdasarkan kunci yang di-hash ke indeks). Kita akan melihat ini di topik hash map. Untuk pencarian berbasis perbandingan nilai, secara teoritis tidak bisa lebih baik dari O(log n).
