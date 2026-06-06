# Panduan Instruktur — Pertemuan 4

**Topik:** Pointer & Dynamic Memory
**Durasi:** 120 menit
**Dokumen ini TIDAK diberikan ke siswa.**

---

## A. Persiapan Sebelum Kelas

### Environment
- [ ] VS Code + GCC siap di mesin demo.
- [ ] Buat folder demo kosong `demo_p4/`.
- [ ] Tes kompilasi program pointer dan malloc sebelum kelas.
- [ ] Opsional: install **Valgrind** (Linux/Mac) untuk demo deteksi memory leak secara live.

### Akun AI
- [ ] Login ke Claude AI — untuk demo bagian "AI untuk Pointer & Deteksi Leak" (menit 105–115).

### Kode Demo yang Perlu Disiapkan
- [ ] Deklarasi pointer + `&` + `*` + `printf` alamat.
- [ ] Fungsi `swap` dengan dan tanpa pointer (kontraskan keduanya).
- [ ] Program `malloc` → cek NULL → isi → tampilkan → `free` → set NULL.
- [ ] Contoh kode dengan memory leak yang sengaja dibuat — untuk demo deteksi.

### File yang Disiapkan
- [ ] `04_Materi.md` — bagikan ke siswa di awal sesi.
- [ ] `04_Task_A.c` — bagikan saat segmen pointer (menit 40–60).
- [ ] `04_Task_B.c` — bagikan saat segmen dynamic memory (menit 60–90).
- [ ] `04_Task_C.c` — bagikan saat segmen memory leak (menit 90–105).
- [ ] `04_Optional_Task.md` — bagikan di akhir sebagai PR.

---

## B. Catatan Pedagogis

### Analogi Utama: Alamat Rumah vs Isi Rumah

Gunakan analogi ini secara konsisten sepanjang pertemuan:
- **Variabel** = isi rumah (mis. nilai `42` di dalam kotak).
- **Alamat memori** = nomor rumah (mis. `0x7ffeabcd`).
- **Pointer** = selembar kertas yang mencatat nomor rumah.
- **`&x`** = "berapa nomor rumah x?"
- **`*ptr`** = "pergi ke rumah di alamat yang dicatat, lihat isinya."

Analogi ini membantu menjawab pertanyaan "kenapa kita perlu pointer jika bisa pakai variabel langsung?" — karena terkadang kamu perlu *memberi tahu seseorang di mana sesuatu disimpan*, bukan hanya memberikan salinannya.

### Urutan Penyampaian yang Direkomendasikan

1. **Recap P3** singkat: array & string, buffer. Tunjukkan koneksi: "array sudah menggunakan konsep alamat memori tanpa kita sadari."

2. **Pointer dasar** — mulai dengan `printf("%p", &x)` untuk menunjukkan alamat memori secara nyata. Ini membuat konsep abstrak menjadi konkret. Kemudian perkenalkan `*` untuk dereference.

3. **`*` saat deklarasi vs dereference** — ini HARUS dijelaskan eksplisit dan berulang. Tulis di whiteboard: `int *ptr` (deklarasi, `*` adalah penanda tipe) vs `*ptr = 5` (dereference, `*` adalah operator).

4. **Pass-by-reference** — demo dua versi fungsi swap: satu tanpa pointer (tidak bekerja), satu dengan pointer (bekerja). Kontras ini sangat efektif.

5. **Dynamic memory** — tunjukkan masalahnya dulu: "bagaimana jika kita tidak tahu ukuran array sebelum program jalan?" Baru perkenalkan `malloc`. Tekankan urutan: alokasi → cek NULL → gunakan → free → set NULL.

6. **Memory leak** — demo dengan kode sederhana yang punya leak. Jika Valgrind tersedia, tunjukkan output-nya. Kalau tidak, gunakan AI untuk mendeteksi.

### Miskonsepsi Umum & Cara Mengatasinya

| Miskonsepsi | Cara Mengatasinya |
|-------------|-------------------|
| `*` di deklarasi = `*` di dereference | Tulis keduanya di whiteboard dan jelaskan konteksnya berbeda. Minta siswa mengulangi perbedaannya. |
| Lupa `&` saat panggil fungsi dengan parameter pointer | Demo: panggil `swap(x, y)` → error kompilasi. Lalu `swap(&x, &y)` → berhasil. |
| Mengira pointer dan variabel yang ditunjuknya adalah hal yang sama | Tunjukkan bahwa `ptr` dan `x` punya alamat berbeda: `printf("%p %p", &ptr, &x)`. |
| Lupa cek `NULL` setelah `malloc` | Tanya: "apa yang terjadi jika server kehabisan RAM dan `malloc` gagal, lalu kamu langsung pakai pointer-nya?" |
| Mengira `free` menghapus nilai dalam pointer | Demo: setelah `free(ptr)`, `printf("%p", ptr)` masih menunjukkan alamat lama. `free` membebaskan memori, bukan mengubah pointer. Ini kenapa perlu `ptr = NULL`. |
| Memory leak di fungsi bercabang (if/else) | Tunjukkan bahwa `return` di tengah fungsi bisa melewati `free` di akhir. Tanamkan kebiasaan: "apakah semua jalur keluar fungsi sudah memanggil `free`?" |

---

## C. Panduan Rundown

| Waktu | Segmen | Yang Perlu Ditekankan |
|-------|--------|-----------------------|
| 0–15 | **Pembukaan / Recap P3** | Recall: buffer di string, ukuran array harus fixed. Tunjukkan batasannya → motivasi pointer & dynamic memory. |
| 15–40 | **Konsep Pointer** | Demo `&` dan `%p`. Deklarasi pointer, hubungkan ke variabel. Tekankan perbedaan `*` deklarasi vs dereference. |
| 40–60 | **Pointer & Fungsi/Array** | Demo pass-by-value yang gagal vs pass-by-reference yang berhasil. Fungsi swap. Hubungan pointer & array. Bagikan `04_Task_A.c`. |
| 60–90 | **Dynamic Memory** | Demo `malloc` → NULL check → gunakan → `free` → set NULL. Lalu `calloc`. Demo fungsi yang return pointer. Bagikan `04_Task_B.c`. |
| 90–105 | **Memory Leak & Dangling Pointer** | Demo kode dengan leak, tunjukkan dengan Valgrind atau AI. Demo dangling pointer. Tanamkan kebiasaan `ptr = NULL` setelah `free`. Bagikan `04_Task_C.c`. |
| 105–115 | **AI untuk Pointer & Leak** | Demo prompt lacak alur pointer + deteksi leak. Validasi bersama siswa. |
| 115–120 | **Penutup & Tugas** | Rekap: `&`, `*`, `malloc`, `free`, NULL check, `ptr=NULL`. Bagikan Optional Task. Preview P5: Struct. |

---

## D. Kunci Jawaban Task A

### Bagian A
```c
int *ptr;          // (A1)
ptr = &x;          // (A2)
printf("... %p\n", &x);   // (A3)
printf("... %p\n",  ptr); // (A4)
printf("... %d\n", *ptr); // (A5)
*ptr = 99;                // (A6)
```

### Bagian B
```c
void tambah_satu(int *pn) {   // (B1)
    *pn = *pn + 1;            // (B2)
}
tambah_satu(&nilai);          // (B3)
```

### Bagian C
```c
void swap(int *pa, int *pb) { // (C1)
    temp = *pa;    // (C2)
    *pa  = *pb;    // (C3)
    *pb  = temp;   // (C4)
}
swap(&a, &b);     // (C5)
```

### Bagian D
```c
printf("*ptr1 : %d\n", *ptr1);  // (D1) → 10
printf("*ptr2 : %d\n", *ptr2);  // (D2) → 20
// (D3) p = 10 + 20 = 30
// (D5) q = 5
printf("... : %d\n", q);        // (D6)
```

---

## E. Kunci Jawaban Task B

### Header
```c
#include <stdlib.h>
```

### Bagian A
```c
arr = (int *) malloc(n * sizeof(int));  // (A1)
if (arr == NULL) { ... }                // (A2)
arr[i] = i + 1;                         // (A3)
free(arr);                              // (A4)
arr = NULL;                             // (A5)
```

### Bagian B
```c
arr = (int *) calloc(n, sizeof(int));   // (B1)
arr[i] = n - i;                         // (B2) → n, n-1, ..., 1
free(arr); arr = NULL;                  // (B3)
```

### Bagian C
```c
int* buat_array_ganjil(int n) {         // (C1) tipe: int*
    arr = (int *) malloc(n * sizeof(int));  // (C2)
    return NULL;                         // (C3) jika gagal
    arr[i] = 2 * i + 1;                 // (C4) rumus ganjil ke-i
}
hasil = buat_array_ganjil(n);           // (C5)
free(hasil); hasil = NULL;              // (C6)
```

---

## F. Kunci Jawaban Task C

### Bagian A — Perbaikan Memory Leak
```c
// Sebelum menimpa arr1, bebaskan dulu:
free(arr1);
arr1 = NULL;
arr1 = (int *) malloc(n * sizeof(int));
```
Analisis (A1): tidak ada leak lain — `free(arr1)` di akhir sudah menangani alokasi kedua.

### Bagian B — Perbaikan Dangling Pointer
```c
free(ptr);
ptr = NULL;   // (B1) — setelah ini, if (ptr != NULL) akan false → aman
```

### Bagian C
```c
if (arr == NULL) { ... }   // (C1)
free(arr); arr = NULL;     // (C2)
```

### Bagian D
```c
// (D1) isi array: 0, 1, 4, 9  (yaitu i*i untuk i=0,1,2,3)
// (D2) bagian_D — karena fungsi_misterius mengembalikan pointer,
//      pemanggil yang menerima pointer itu bertanggung jawab membebaskannya
free(data);    // (D3a)
data = NULL;   // (D3b)
```

---

## G. Antisipasi Pertanyaan Siswa

**Q: Kapan harus pakai pointer, kapan tidak?**
A: Gunakan pointer ketika: (1) kamu perlu fungsi mengubah variabel di luar fungsi itu (pass-by-reference), (2) kamu perlu alokasi memori dinamis, atau (3) kamu bekerja dengan struktur data seperti linked list, tree, dan graph. Untuk operasi sederhana yang tidak perlu mengubah variabel luar, cukup pass-by-value.

**Q: Kenapa `arr` di fungsi tidak perlu `&` saat dikirim ke fungsi yang menerima pointer?**
A: Nama array sudah merupakan alamat elemen pertamanya (`int *`). Jadi `arr` dan `&arr[0]` adalah hal yang sama. Mengirim `arr` ke fungsi yang menerima `int *` sudah cukup.

**Q: Apa bedanya stack memory dan heap memory?**
A: Variabel biasa (lokal) disimpan di **stack** — otomatis dibersihkan saat fungsi selesai, ukurannya fixed. `malloc`/`calloc` mengalokasikan di **heap** — bertahan sampai kamu `free`, ukurannya fleksibel. Memory leak terjadi di heap.

**Q: Apakah `malloc(0)` valid?**
A: Di C standar, `malloc(0)` boleh mengembalikan pointer non-NULL (tapi tidak boleh dideref) atau NULL. Hasilnya implementation-defined. Hindari `malloc(0)` dalam kode produksi.

**Q: Kenapa harus set `ptr = NULL` setelah `free`? Bukankah `free` sudah cukup?**
A: `free` hanya memberitahu sistem bahwa blok memori itu boleh dipakai lagi — pointer-nya sendiri tidak diubah, masih menyimpan alamat lama. Tanpa `ptr = NULL`, kamu mungkin tidak sengaja mengakses alamat itu lagi (dangling pointer). Dengan `ptr = NULL`, percobaan akses akan crash dengan pesan yang jelas, jauh lebih mudah di-debug.
