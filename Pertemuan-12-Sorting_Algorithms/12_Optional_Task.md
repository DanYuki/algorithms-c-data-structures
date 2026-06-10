# Pertemuan 12 — Optional Task: Sorting Algorithms

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` sendiri sebagai jawabanmu.

---

## Optional Task 1 — Sort Array of Struct Berdasarkan Field (Level: Mudah)

### Latar Belakang

Sorting integer adalah latihan, tapi di dunia nyata kita sering mengurutkan data kompleks — daftar mahasiswa berdasarkan IPK, produk berdasarkan harga, atau nilai ujian dengan nama siswa.

### Yang Harus Dibuat

Buat file **`optional1_sort_struct.c`** yang melakukan hal berikut:

1. Definisikan struct `NilaiUjian`:
   ```c
   typedef struct {
       char  nama[50];
       int   nilai;
   } NilaiUjian;
   ```

2. Implementasikan dua fungsi sorting untuk struct ini:

   ```c
   /* Urutkan berdasarkan nilai, dari TERTINGGI ke TERENDAH (descending) */
   /* Gunakan algoritma apapun (bubble, selection, atau insertion) */
   void sort_by_nilai_desc(NilaiUjian data[], int n);

   /* Urutkan berdasarkan nama secara alphabetical (ascending A-Z) */
   /* Gunakan strcmp() dari <string.h> */
   void sort_by_nama_asc(NilaiUjian data[], int n);
   ```

3. Di `main()`, gunakan data berikut dan uji kedua sorting:

   ```c
   NilaiUjian kelas[] = {
       {"Eko Widodo",   72},
       {"Andi Pratama", 88},
       {"Citra Dewi",   95},
       {"Budi Santoso", 88},
       {"Dinda Rahayu", 79}
   };
   ```

4. Setelah sort by nilai, tampilkan peringkat (1, 2, 3, ...):

### Contoh Output

```
=== Peringkat Berdasarkan Nilai (Tertinggi → Terendah) ===
Peringkat 1: Citra Dewi      — 95
Peringkat 2: Andi Pratama    — 88
Peringkat 3: Budi Santoso    — 88
Peringkat 4: Dinda Rahayu   — 79
Peringkat 5: Eko Widodo      — 72

=== Daftar Alphabetical (A → Z) ===
1. Andi Pratama    — 88
2. Budi Santoso    — 88
3. Citra Dewi      — 95
4. Dinda Rahayu   — 79
5. Eko Widodo      — 72
```

### Petunjuk

- Untuk swap struct, gunakan variabel sementara bertipe `NilaiUjian`:
  ```c
  NilaiUjian tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
  ```
- Untuk sort by nama: gunakan `strcmp(data[i].nama, data[j].nama)`.
  `strcmp` mengembalikan negatif jika `a < b` secara alphabetical.
- Perhatikan: dua siswa dengan nilai sama (Andi dan Budi, keduanya 88) — urutan mereka relatif bergantung pada apakah algoritma yang kamu pilih **stabil** atau tidak.

---

## Optional Task 2 — Benchmark: Merge Sort vs Bubble Sort (Level: Menantang)

### Latar Belakang

Perbedaan O(n²) dan O(n log n) terlihat kecil di atas kertas, tapi sangat nyata untuk data besar. Di soal ini, kamu akan **mengukur waktu eksekusi** kedua algoritma dan membuktikan secara empiris bahwa merge sort jauh lebih cepat untuk n besar.

### Yang Harus Dibuat

Buat file **`optional2_benchmark.c`** yang melakukan hal berikut:

1. Implementasikan `bubble_sort` dan `merge_sort` (bisa salin dari Task A dan B).

2. Buat fungsi `isi_acak(arr, n, seed)` yang mengisi array dengan angka acak menggunakan `srand(seed)` dan `rand()`.

3. Buat fungsi `benchmark(n)` yang:
   - Mengisi array berukuran n dengan angka acak.
   - Mengukur waktu bubble sort dengan `clock()`.
   - Mengulang dengan array yang sama untuk merge sort.
   - Mencetak waktu keduanya.

   ```c
   #include <time.h>

   void benchmark(int n) {
       int *arr_bubble = malloc(n * sizeof(int));
       int *arr_merge  = malloc(n * sizeof(int));
       isi_acak(arr_bubble, n, 42);
       isi_acak(arr_merge,  n, 42);   /* seed sama → data identik */

       clock_t awal, akhir;

       awal = clock();
       bubble_sort(arr_bubble, n);
       akhir = clock();
       double waktu_bubble = (double)(akhir - awal) / CLOCKS_PER_SEC;

       awal = clock();
       merge_sort(arr_merge, 0, n - 1);
       akhir = clock();
       double waktu_merge = (double)(akhir - awal) / CLOCKS_PER_SEC;

       printf("n = %6d | Bubble: %.4f s | Merge: %.6f s | Rasio: %.1fx\n",
              n, waktu_bubble, waktu_merge,
              waktu_bubble > 0 ? waktu_bubble / waktu_merge : 0.0);

       free(arr_bubble);
       free(arr_merge);
   }
   ```

4. Di `main()`, jalankan benchmark untuk n = 1.000, 5.000, 10.000, 20.000, 50.000:

   ```c
   printf("%-8s | %-12s | %-12s | %s\n", "n", "Bubble Sort", "Merge Sort", "Rasio");
   printf("---------|--------------|--------------|-------\n");
   benchmark(1000);
   benchmark(5000);
   benchmark(10000);
   benchmark(20000);
   benchmark(50000);
   ```

### Contoh Output (waktu bervariasi tergantung mesin)

```
n        | Bubble Sort  | Merge Sort   | Rasio
---------|--------------|--------------|-------
n =   1000 | Bubble: 0.0030 s | Merge: 0.000050 s | Rasio: 60.0x
n =   5000 | Bubble: 0.0700 s | Merge: 0.000300 s | Rasio: 233.0x
n =  10000 | Bubble: 0.2800 s | Merge: 0.000650 s | Rasio: 430.0x
n =  20000 | Bubble: 1.1200 s | Merge: 0.001400 s | Rasio: 800.0x
n =  50000 | Bubble: 7.0000 s | Merge: 0.003800 s | Rasio: 1842.0x
```

### Pertanyaan Analisis (tulis sebagai komentar di file .c)

1. Bagaimana rasio waktu berubah saat n digandakan? Apakah konsisten dengan O(n²) vs O(n log n)?
2. Jika bubble sort butuh 7 detik untuk n=50.000, estimasikan berapa lama untuk n=100.000.
3. Pada n berapa bubble sort menjadi "tidak praktis" (misalnya lebih dari 10 detik)?

### Petunjuk

- Compile dengan: `gcc optional2_benchmark.c -o optional2`
- Untuk n besar, bubble sort bisa sangat lambat — sabar menunggu, atau kurangi nilai n jika terlalu lama.
- `CLOCKS_PER_SEC` biasanya 1000 di Windows dan 1.000.000 di Linux/Mac — `clock()` sudah menangani ini.
