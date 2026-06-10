/*
 * Pertemuan 2 -- Task B: Tulis Fungsimu Sendiri
 * Topik   : Functions (kasus dunia nyata: kalkulator BMI & progres tabungan)
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - File ini berisi TIGA fungsi yang belum lengkap.
 *   - Baca komentar di atas setiap fungsi -- di sana tertulis apa yang harus
 *     fungsi tersebut lakukan, rumusnya, dan contoh nilainya.
 *   - Lengkapi BODY setiap fungsi, lalu panggil semua fungsi di dalam main().
 *
 * Compile : gcc 02_Task_B.c -o 02_Task_B -Wall
 * Jalankan: ./02_Task_B  (Linux/Mac)  atau  02_Task_B.exe  (Windows)
 *
 * Expected Output:
 *   === Kalkulator BMI ===
 *   Orang A (berat=60.0 kg, tinggi=1.70 m)
 *   BMI: 20.8
 *   Kategori: Normal
 *
 *   Orang B (berat=85.0 kg, tinggi=1.70 m)
 *   BMI: 29.4
 *   Kategori: Gemuk
 *
 *   === Progres Tabungan (setoran 500000/bulan) ===
 *   Bulan 1: 500000
 *   Bulan 2: 1000000
 *   Bulan 3: 1500000
 *   Bulan 4: 2000000
 */

#include <stdio.h>


/* ==============================================================
 * Fungsi 1: hitung_bmi
 *
 * TUGAS: Kembalikan nilai BMI (Body Mass Index) seseorang.
 *
 * Parameter : berat (float, dalam kg), tinggi (float, dalam meter)
 * Return    : bmi (float)
 * Rumus     : berat / (tinggi * tinggi)
 *
 * Contoh    : hitung_bmi(60.0, 1.70) -> 20.76...
 *
 * Petunjuk  : kedua parameter sudah float, jadi pembagiannya otomatis
 *             menghasilkan desimal (tidak terkena jebakan pembagian bulat).
 * ============================================================== */
float hitung_bmi(float berat, float tinggi) {
    /* TODO: return berat dibagi (tinggi * tinggi) */

}


/* ==============================================================
 * Fungsi 2: cetak_kategori_bmi
 *
 * TUGAS: Cetak kategori berat badan berdasarkan nilai BMI.
 *
 * Parameter : bmi (float)
 * Return    : void (tidak mengembalikan nilai, hanya mencetak)
 *
 * Ketentuan kategori:
 *   bmi < 18.5            -> "Kategori: Kurus"
 *   18.5 <= bmi < 25.0    -> "Kategori: Normal"
 *   25.0 <= bmi < 30.0    -> "Kategori: Gemuk"
 *   bmi >= 30.0           -> "Kategori: Obesitas"
 *
 * Contoh    : cetak_kategori_bmi(20.8) mencetak "Kategori: Normal"
 *
 * Petunjuk  : gunakan if / else if / else. Cek dari nilai terkecil ke
 *             terbesar, atau sebaliknya -- yang penting rentangnya tidak
 *             tumpang tindih.
 * ============================================================== */
void cetak_kategori_bmi(float bmi) {
    /* TODO: tulis if / else if / else untuk mencetak kategori */

}


/* ==============================================================
 * Fungsi 3: cetak_progres_tabungan
 *
 * TUGAS: Cetak saldo tabungan dari bulan ke bulan, dengan asumsi
 *        setoran yang sama setiap bulan (tanpa bunga).
 *
 * Parameter : setoran_bulanan (int), jumlah_bulan (int)
 * Return    : void
 *
 * Contoh output untuk setoran_bulanan=500000, jumlah_bulan=4:
 *   Bulan 1: 500000
 *   Bulan 2: 1000000
 *   Bulan 3: 1500000
 *   Bulan 4: 2000000
 *
 * Petunjuk:
 *   - Gunakan variabel saldo yang dimulai dari 0.
 *   - Pakai for loop dari bulan = 1 sampai jumlah_bulan.
 *   - Di setiap putaran: tambahkan setoran_bulanan ke saldo, lalu cetak.
 *     Contoh cetak: printf("Bulan %d: %d\n", bulan, saldo);
 * ============================================================== */
void cetak_progres_tabungan(int setoran_bulanan, int jumlah_bulan) {
    int saldo = 0;
    int bulan;
    /* TODO: tulis for loop di sini */

}



/* ==============================================================
 * main -- Uji semua fungsi yang sudah kamu tulis
 *
 * TUGAS: Panggil setiap fungsi di bawah dan cetak hasilnya sesuai
 *        Expected Output di bagian atas file.
 *
 * Langkah:
 *   1. Cetak header "=== Kalkulator BMI ==="
 *      - Orang A: berat 60.0, tinggi 1.70 -> hitung_bmi lalu cetak_kategori_bmi
 *      - Orang B: berat 85.0, tinggi 1.70 -> hitung_bmi lalu cetak_kategori_bmi
 *      Cetak nilai BMI dengan format %.1f, mis:
 *        printf("BMI: %.1f\n", hitung_bmi(60.0, 1.70));
 *
 *   2. Cetak header "=== Progres Tabungan (setoran 500000/bulan) ==="
 *      lalu panggil cetak_progres_tabungan(500000, 4).
 * ============================================================== */
int main() {

    /* Bagian 1: Kalkulator BMI */


    /* Bagian 2: Progres Tabungan */


    return 0;
}
