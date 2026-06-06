/*
 * Pertemuan 2 — Task A: Percabangan & Perulangan
 * Topik   : Control Flow & Functions
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ atau // TODO
 *   - Setelah semua bagian diisi, program harus bisa dikompilasi & berjalan
 *   - Compile: gcc 02_Task_A.c -o 02_Task_A
 *   - Jalankan: ./02_Task_A  (Linux/Mac)  atau  02_Task_A.exe  (Windows)
 *   - Kerjakan Bagian A, B, C secara berurutan
 */

#include <stdio.h>

/* ============================================================
 * BAGIAN A — Percabangan: if / else if / else
 *
 * Program menerima nilai ujian (0–100) dan menampilkan kategori:
 *   >= 85  → "Lulus dengan Pujian"
 *   >= 60  → "Lulus"
 *   < 60   → "Tidak Lulus"
 *
 * Contoh output:
 *   Masukkan nilai ujian: 78
 *   Hasil: Lulus
 * ============================================================ */

int bagian_A() {
    int nilai;

    printf("=== Bagian A: Percabangan ===\n");
    printf("Masukkan nilai ujian (0-100): ");
    scanf("%d", &nilai);

    /* (A1) Lengkapi kondisi if-else if-else sesuai ketentuan di atas */
    if (____) {
        printf("Hasil: Lulus dengan Pujian\n");
    } ____ (____) {
        printf("Hasil: Lulus\n");
    } ____ {
        printf("Hasil: Tidak Lulus\n");
    }

    return 0;
}


/* ============================================================
 * BAGIAN B — switch-case: Nama Hari
 *
 * Program menerima angka 1–7 dan menampilkan nama hari:
 *   1 → "Senin", 2 → "Selasa", ..., 7 → "Minggu"
 *   Selain 1–7 → "Angka tidak valid"
 *
 * Contoh output:
 *   Masukkan angka (1-7): 3
 *   Hari ke-3 adalah: Rabu
 * ============================================================ */

int bagian_B() {
    int angka_hari;

    printf("\n=== Bagian B: switch-case ===\n");
    printf("Masukkan angka hari (1-7): ");
    scanf("%d", &angka_hari);

    /* (B1) Lengkapi switch-case di bawah ini */
    switch (____) {
        case 1:
            printf("Hari ke-%d adalah: Senin\n", angka_hari);
            ____  /* (B2) Jangan lupa menghentikan fall-through! */
        case 2:
            printf("Hari ke-%d adalah: Selasa\n", angka_hari);
            ____
        case 3:
            printf("Hari ke-%d adalah: Rabu\n", angka_hari);
            ____
        case 4:
            printf("Hari ke-%d adalah: Kamis\n", angka_hari);
            ____
        case 5:
            printf("Hari ke-%d adalah: Jumat\n", angka_hari);
            ____
        case 6:
            printf("Hari ke-%d adalah: Sabtu\n", angka_hari);
            ____
        case 7:
            printf("Hari ke-%d adalah: Minggu\n", angka_hari);
            ____
        /* (B3) Tambahkan case untuk input yang tidak valid */
        ____:
            printf("Angka tidak valid. Masukkan angka 1-7.\n");
    }

    return 0;
}


/* ============================================================
 * BAGIAN C — Perulangan: for, while, do-while
 *
 * C1. Gunakan for: cetak bilangan 1 sampai N (N diinput pengguna).
 *     Contoh output (N=4): 1  2  3  4
 *
 * C2. Gunakan while: hitung jumlah digit angka yang diinput pengguna
 *     (berapa digit angka tersebut, mis. 1234 punya 4 digit).
 *     Contoh output: Angka 1234 memiliki 4 digit.
 *
 * C3. Gunakan do-while: minta pengguna menebak angka 7.
 *     Terus minta tebakan sampai jawabannya benar.
 *     Contoh output:
 *       Tebak angka (1-10): 3
 *       Salah, coba lagi!
 *       Tebak angka (1-10): 7
 *       Benar!
 * ============================================================ */

int bagian_C() {
    printf("\n=== Bagian C: Perulangan ===\n");

    /* --- C1: for --- */
    int batas;
    printf("\n[C1] Masukkan N: ");
    scanf("%d", &batas);

    printf("Bilangan 1 sampai %d: ", batas);
    /* (C1) Lengkapi header for-loop di bawah ini */
    for (____; ____; ____) {
        printf("%d  ", ____);
    }
    printf("\n");

    /* --- C2: while --- */
    int angka_digit;
    int jumlah_digit = 0;

    printf("\n[C2] Masukkan angka positif: ");
    scanf("%d", &angka_digit);

    int salinan = angka_digit;   /* simpan nilai asli untuk ditampilkan nanti */

    /* (C2) Lengkapi kondisi while dan isi tubuh loop */
    while (____) {
        ____           /* (C2a) Operasi untuk "memotong" satu digit */
        ____           /* (C2b) Tambahkan penghitung digit */
    }

    printf("Angka %d memiliki %d digit.\n", salinan, jumlah_digit);

    /* --- C3: do-while --- */
    int tebakan;
    int rahasia = 7;

    printf("\n[C3] Tebak angkanya (1-10)!\n");

    /* (C3) Lengkapi do-while di bawah ini */
    ____ {
        printf("Tebak angka (1-10): ");
        scanf("%d", &tebakan);

        if (tebakan != rahasia) {
            printf("Salah, coba lagi!\n");
        }
    } while (____);

    printf("Benar! Angkanya memang %d.\n", rahasia);

    return 0;
}


/* ============================================================
 * main — Panggil ketiga bagian secara berurutan
 * (Tidak perlu diubah)
 * ============================================================ */

int main() {
    bagian_A();
    bagian_B();
    bagian_C();
    return 0;
}
