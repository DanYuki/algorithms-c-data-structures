/*
 * Pertemuan 2 — Task A2: switch-case
 * Topik   : Percabangan
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Baca komentar di dalam main() untuk tahu apa yang harus ditulis.
 *   - File ini sudah bisa di-compile dari awal — coba compile dulu sebelum mengisi.
 *
 * Compile : gcc 02_Task_A2.c -o 02_Task_A2 -Wall
 * Jalankan: ./02_Task_A2  (Linux/Mac)  atau  02_Task_A2.exe  (Windows)
 *
 * Expected Output (contoh input = 3):
 *   Masukkan angka hari (1-7): 3
 *   Hari ke-3 adalah: Rabu
 *
 * Expected Output (contoh input = 9):
 *   Masukkan angka hari (1-7): 9
 *   Angka tidak valid. Masukkan angka 1-7.
 */

#include <stdio.h>

int main() {
    int angka_hari;

    printf("=== Bagian B: switch-case ===\n");
    printf("Masukkan angka hari (1-7): ");
    scanf("%d", &angka_hari);

    /*
     * TUGAS: Tulis switch-case di bawah ini.
     *
     * Ketentuan:
     *   1 → "Hari ke-1 adalah: Senin"
     *   2 → "Hari ke-2 adalah: Selasa"
     *   3 → "Hari ke-3 adalah: Rabu"
     *   4 → "Hari ke-4 adalah: Kamis"
     *   5 → "Hari ke-5 adalah: Jumat"
     *   6 → "Hari ke-6 adalah: Sabtu"
     *   7 → "Hari ke-7 adalah: Minggu"
     *   selain 1-7 → "Angka tidak valid. Masukkan angka 1-7."
     *
     * Petunjuk:
     *   - Gunakan switch (angka_hari) { ... }
     *   - Setiap case diakhiri dengan break; — tanpa break, program akan
     *     terus jatuh ke case berikutnya (disebut "fall-through")
     *   - Gunakan default: untuk menangani input yang tidak valid
     *   - Format printf: printf("Hari ke-%d adalah: Senin\n", angka_hari);
     */


    return 0;
}
