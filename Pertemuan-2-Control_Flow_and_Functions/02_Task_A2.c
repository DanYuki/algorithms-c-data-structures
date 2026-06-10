/*
 * Pertemuan 2 — Task A2: switch-case
 * Topik   : Percabangan (kasus dunia nyata: tarif parkir)
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
 * ----------------------------------------------------------------------
 * KONTEKS:
 *   Sebuah tempat parkir mematok tarif PER JAM berdasarkan jenis kendaraan:
 *
 *     1 = Motor     -> Rp2.000 / jam
 *     2 = Mobil     -> Rp4.000 / jam
 *     3 = Bus/Truk  -> Rp8.000 / jam
 *
 *   Total biaya = tarif per jam * lama parkir (jam).
 * ----------------------------------------------------------------------
 *
 * Expected Output (contoh input jenis = 2, jam = 3):
 *   Masukkan jenis kendaraan (1=Motor, 2=Mobil, 3=Bus/Truk): 2
 *   Masukkan lama parkir (jam): 3
 *   Kendaraan : Mobil
 *   Tarif/jam : 4000
 *   Total     : 12000
 *
 * Expected Output (contoh input jenis = 9):
 *   Masukkan jenis kendaraan (1=Motor, 2=Mobil, 3=Bus/Truk): 9
 *   Masukkan lama parkir (jam): 3
 *   Jenis kendaraan tidak valid. Pilih 1, 2, atau 3.
 */

#include <stdio.h>

int main() {
    int jenis;
    int jam;
    int tarif_per_jam = 0;   /* akan kamu tentukan lewat switch di bawah */

    printf("=== Tarif Parkir ===\n");
    printf("Masukkan jenis kendaraan (1=Motor, 2=Mobil, 3=Bus/Truk): ");
    scanf("%d", &jenis);
    printf("Masukkan lama parkir (jam): ");
    scanf("%d", &jam);

    /*
     * TUGAS: Tulis switch (jenis) { ... } di bawah ini.
     *
     * Untuk setiap jenis valid, lakukan dua hal:
     *   - cetak nama kendaraannya, mis. printf("Kendaraan : Motor\n");
     *   - isi tarif_per_jam dengan tarif yang sesuai (2000 / 4000 / 8000).
     *
     * Ketentuan:
     *   case 1 -> "Kendaraan : Motor"     dan tarif_per_jam = 2000
     *   case 2 -> "Kendaraan : Mobil"     dan tarif_per_jam = 4000
     *   case 3 -> "Kendaraan : Bus/Truk"  dan tarif_per_jam = 8000
     *   default -> cetak "Jenis kendaraan tidak valid. Pilih 1, 2, atau 3."
     *
     * Petunjuk:
     *   - Setiap case diakhiri break; — tanpa break program "jatuh" ke case berikutnya.
     *   - Biarkan tarif_per_jam tetap 0 pada kasus tidak valid (default).
     */


    /*
     * Bagian di bawah ini SUDAH disediakan — jangan diubah.
     * Total hanya dicetak jika kendaraan valid (tarif_per_jam lebih dari 0).
     */
    if (tarif_per_jam > 0) {
        int total = tarif_per_jam * jam;
        printf("Tarif/jam : %d\n", tarif_per_jam);
        printf("Total     : %d\n", total);
    }

    return 0;
}
