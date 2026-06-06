/*
 * Pertemuan 3 — Task B: String & <string.h>
 * Topik   : Array & String
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Compile: gcc 03_Task_B.c -o 03_Task_B
 *   - Jalankan: ./03_Task_B  (Linux/Mac)  atau  03_Task_B.exe  (Windows)
 */

#include <stdio.h>
#include <____>   // (0) tambahkan header untuk fungsi strlen, strcpy, strcmp, strcat

/* ============================================================
 * BAGIAN A — strlen & Manual Hitung Panjang
 *
 * Lengkapi dua cara menghitung panjang string:
 *   1. Menggunakan strlen dari <string.h>
 *   2. Manual: loop sampai menemukan null terminator '\0'
 *
 * Contoh output:
 *   String  : "Halo Dunia"
 *   Panjang (strlen)  : 10
 *   Panjang (manual)  : 10
 * ============================================================ */

void bagian_A() {
    char kata[] = "Halo Dunia";
    int panjang_manual = 0;
    int i;

    printf("=== Bagian A: Panjang String ===\n");
    printf("String  : \"%s\"\n", kata);

    // (A1) Gunakan strlen untuk menghitung panjang
    printf("Panjang (strlen) : %d\n", ____(____)  );

    // (A2) Hitung panjang secara manual dengan loop
    // Loop terus selama karakter bukan null terminator
    for (i = 0; ____ != '\0'; i++) { // (A2a) kondisi: karakter ke-i bukan '\0'
        panjang_manual++;
    }
    printf("Panjang (manual) : %d\n", panjang_manual);
}


/* ============================================================
 * BAGIAN B — strcpy & strcmp
 *
 * B1. Salin string sumber ke tujuan menggunakan strcpy,
 *     lalu tampilkan keduanya.
 *
 * B2. Bandingkan dua kata menggunakan strcmp dan tampilkan
 *     apakah keduanya sama atau berbeda.
 *
 * Contoh output:
 *   Sumber : "Belajar C"
 *   Tujuan (setelah strcpy): "Belajar C"
 *
 *   Bandingkan "apel" dan "apel" : SAMA
 *   Bandingkan "apel" dan "mangga" : BERBEDA
 * ============================================================ */

void bagian_B() {
    char sumber[] = "Belajar C";
    char tujuan[20];       // pastikan cukup besar untuk menampung isi sumber

    char kata1[] = "apel";
    char kata2[] = "apel";
    char kata3[] = "mangga";

    printf("\n=== Bagian B: strcpy & strcmp ===\n");

    // (B1) Salin sumber ke tujuan menggunakan strcpy
    ____(tujuan, sumber);  // (B1) fungsi untuk menyalin string

    printf("Sumber : \"%s\"\n", sumber);
    printf("Tujuan (setelah strcpy): \"%s\"\n", tujuan);

    // (B2a) Bandingkan kata1 dan kata2
    printf("\nBandingkan \"%s\" dan \"%s\" : ", kata1, kata2);
    if (____(kata1, kata2) == ____) {  // (B2a) fungsi & nilai kembalian jika sama
        printf("SAMA\n");
    } else {
        printf("BERBEDA\n");
    }

    // (B2b) Bandingkan kata1 dan kata3
    printf("Bandingkan \"%s\" dan \"%s\" : ", kata1, kata3);
    if (____(kata1, kata3) == 0) {  // (B2b) fungsi perbandingan
        printf("SAMA\n");
    } else {
        printf("BERBEDA\n");
    }
}


/* ============================================================
 * BAGIAN C — strcat & Gabungkan String
 *
 * Buat kalimat sambutan dengan menggabungkan beberapa string
 * menggunakan strcat.
 *
 * Komponen: "Selamat datang, " + nama_pengguna + "!"
 *
 * Contoh output (input: Rina):
 *   Masukkan nama kamu: Rina
 *   Pesan: Selamat datang, Rina!
 * ============================================================ */

void bagian_C() {
    char nama[30];
    char pesan[60] = "Selamat datang, ";  // buffer cukup besar untuk hasil gabungan
    char penutup[] = "!";

    printf("\n=== Bagian C: strcat ===\n");
    printf("Masukkan nama kamu: ");
    scanf("%s", nama);

    // (C1) Gabungkan nama ke pesan menggunakan strcat
    ____(pesan, ____);      // (C1) tambahkan nama ke pesan

    // (C2) Gabungkan penutup ("!") ke pesan
    ____(pesan, ____);      // (C2) tambahkan penutup ke pesan

    printf("Pesan: %s\n", pesan);
}


/* ============================================================
 * BAGIAN D — Hitung Vokal dalam String
 *
 * Program menerima sebuah kata dari pengguna,
 * lalu menghitung berapa banyak huruf vokal (a, i, u, e, o)
 * yang ada di dalamnya (huruf besar dan kecil dihitung).
 *
 * Contoh output:
 *   Masukkan sebuah kata: Halo
 *   Jumlah vokal dalam "Halo" : 2
 * ============================================================ */

void bagian_D() {
    char kata[50];
    int i;
    int jumlah_vokal = 0;
    char c;

    printf("\n=== Bagian D: Hitung Vokal ===\n");
    printf("Masukkan sebuah kata: ");
    scanf("%s", kata);

    // (D1) Loop melalui setiap karakter sampai null terminator
    for (i = 0; ____ != '\0'; i++) {  // (D1) kondisi berhenti loop
        c = kata[i];

        // (D2) Cek apakah karakter adalah vokal (huruf besar atau kecil)
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
            ____ ) {  // (D2) tambahkan kondisi untuk huruf vokal KAPITAL (A,I,U,E,O)
            jumlah_vokal++;
        }
    }

    printf("Jumlah vokal dalam \"%s\" : %d\n", kata, jumlah_vokal);
}


/* ============================================================
 * main — Panggil semua bagian
 * ============================================================ */

int main() {
    bagian_A();
    bagian_B();
    bagian_C();
    bagian_D();
    return 0;
}
