# Pertemuan 8 — Optional Task: Stack

**Course:** Algorithms, C & Data Structures with AI Applications

Kerjakan soal-soal berikut sebagai latihan tambahan. Buat file `.c` sendiri sebagai jawabanmu.

---

## Optional Task 1 — Membalik String dengan Stack (Level: Mudah)

### Latar Belakang

Prinsip LIFO membuat stack sangat cocok untuk membalik urutan sesuatu. Jika kamu push semua karakter sebuah string ke stack, lalu pop satu per satu, kamu akan mendapatkan string yang terbalik.

### Yang Harus Dibuat

Buat file **`optional1_balik_string.c`** yang melakukan hal berikut:

1. Implementasikan stack karakter berbasis array (atau linked list — pilih salah satu):
   - `init`, `isEmpty`, `isFull` (jika array), `push`, `pop`

2. Buat fungsi:
   ```c
   void balik_string(const char *input, char *output);
   ```
   Fungsi ini membalik string `input` dan menyimpan hasilnya di `output`, menggunakan stack sebagai mekanisme pembalik. Jangan gunakan fungsi bawaan seperti `strrev`.

3. Di `main()`, uji dengan setidaknya 4 string berikut:
   - `"Halo Dunia"` → `"ainuD olaH"`
   - `"racecar"` → `"racecar"` (palindrom — sama)
   - `"12345"` → `"54321"`
   - `""` (string kosong) → `""` (tidak crash)

### Contoh Output

```
Input : "Halo Dunia"    → Output: "ainuD olaH"
Input : "racecar"       → Output: "racecar"
Input : "12345"         → Output: "54321"
Input : ""              → Output: ""
```

### Petunjuk

- Tentukan `KAPASITAS` cukup besar (mis. 200) agar bisa menampung string panjang.
- Push setiap karakter dari indeks 0 sampai akhir string.
- Pop satu per satu dan simpan ke `output`, lalu tambahkan `'\0'` di akhir.
- Tambahkan `#include <string.h>` untuk `strlen`.

---

## Optional Task 2 — Evaluasi Ekspresi Postfix (Level: Menantang)

### Latar Belakang

Postfix (Reverse Polish Notation) adalah notasi ekspresi di mana operator ditulis setelah operand-operandnya. Keunggulannya: tidak perlu tanda kurung dan aturan prioritas — komputer bisa mengevaluasinya langsung dengan satu pass kiri ke kanan menggunakan stack.

Contoh: `3 4 2 * +` setara dengan `3 + (4 * 2) = 11`.

### Yang Harus Dibuat

Buat file **`optional2_postfix.c`** yang melakukan hal berikut:

1. Implementasikan stack integer (`int`) berbasis array atau linked list.

2. Buat fungsi:
   ```c
   int evaluasi_postfix(const char *ekspresi);
   ```
   Fungsi ini menerima string ekspresi postfix di mana token (angka dan operator) dipisahkan spasi, lalu mengembalikan hasil evaluasinya.

   Algoritma:
   - Baca token satu per satu (pisahkan dengan `strtok` atau parse manual).
   - Jika token adalah **angka**: konversi ke int dengan `atoi` dan push.
   - Jika token adalah **operator** (`+`, `-`, `*`, `/`):
     - Pop dua operand dari stack: `b = pop()`, `a = pop()`.
     - Hitung `a op b` dan push hasilnya.
   - Di akhir: pop satu kali — itu adalah hasilnya.

3. Di `main()`, uji dengan ekspresi-ekspresi berikut:

| Ekspresi Postfix | Setara Infix | Hasil |
|---|---|---|
| `"3 4 +"` | `3 + 4` | `7` |
| `"3 4 2 * +"` | `3 + 4 * 2` | `11` |
| `"5 1 2 + 4 * + 3 -"` | `5 + (1+2)*4 - 3` | `14` |
| `"10 2 /"` | `10 / 2` | `5` |

### Contoh Output

```
"3 4 +"            = 7
"3 4 2 * +"        = 11
"5 1 2 + 4 * + 3 -" = 14
"10 2 /"           = 5
```

### Petunjuk

- Gunakan `strtok(ekspresi_copy, " ")` untuk memotong ekspresi per token. **Perhatian:** `strtok` memodifikasi string aslinya — salin dulu dengan `strcpy` ke buffer sementara.
- Cek apakah token adalah operator dengan `strlen(token) == 1 && (token[0] == '+' || ...)`.
- Jika bukan operator, anggap angka dan gunakan `atoi(token)`.
- Ingat urutan pop: `b = pop()` dulu, baru `a = pop()`. Untuk operasi asosiatif (`+`, `*`) tidak masalah, tapi untuk `-` dan `/` urutannya penting: hasilnya adalah `a op b`.
- Tambahkan `#include <string.h>` dan `#include <stdlib.h>`.
