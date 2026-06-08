/*
 * Pertemuan 2 — Task A1: if / else if / else
 * Topik   : Percabangan
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Baca komentar di dalam main() untuk tahu apa yang harus ditulis.
 *   - File ini sudah bisa di-compile dari awal — coba compile dulu sebelum mengisi.
 *
 * Compile : gcc 02_Task_A1.c -o 02_Task_A1 -Wall
 * Jalankan: ./02_Task_A1  (Linux/Mac)  atau  02_Task_A1.exe  (Windows)
 *
 * Expected Output (contoh input nilai = 78):
 *   Masukkan nilai ujian (0-100): 78
 *   Hasil: Lulus
 *
 * Expected Output (contoh input nilai = 91):
 *   Masukkan nilai ujian (0-100): 91
 *   Hasil: Lulus dengan Pujian
 */

#include <stdio.h>

int main() {
    int nilai;

    printf("=== Bagian A: Percabangan ===\n");
    printf("Masukkan nilai ujian (0-100): ");
    scanf("%d", &nilai);

    /*
     * TUGAS: Tulis struktur if / else if / else di bawah ini.
     *
     * Ketentuan:
     *   nilai >= 85  → cetak "Hasil: Lulus dengan Pujian"
     *   nilai >= 60  → cetak "Hasil: Lulus"
     *   selain itu   → cetak "Hasil: Tidak Lulus"
     *
     * Petunjuk:
     *   - Gunakan if (...) { } untuk kondisi pertama
     *   - Gunakan else if (...) { } untuk kondisi kedua
     *   - Gunakan else { } untuk kondisi terakhir
     *   - Cek kondisi paling ketat (>= 85) dulu, baru yang lebih longgar
     */


    return 0;
}
