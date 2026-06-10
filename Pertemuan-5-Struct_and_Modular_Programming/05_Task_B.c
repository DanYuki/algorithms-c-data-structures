/*
 * Pertemuan 5 — Task B: Pointer ke Struct & Modular Programming
 * Topik   : Struct & Modular Programming
 * Nama    : ___________________________
 * Tanggal : ___________________________
 *
 * Petunjuk:
 *   - Isi semua bagian bertanda ____ (garis bawah)
 *   - Komentar // di samping ____ memberikan petunjuk
 *   - Task ini mensimulasikan kode modular dalam SATU file.
 *     Komentar penanda "=== [mahasiswa.h] ===" dan "=== [mahasiswa.c] ==="
 *     menunjukkan bagian mana yang seharusnya ada di file mana.
 *   - Compile: gcc 05_Task_B.c -o 05_Task_B
 *   - Jalankan: ./05_Task_B  (Linux/Mac)  atau  05_Task_B.exe  (Windows)
 */

#include <stdio.h>
#include <string.h>


/* ============================================================
 * === [mahasiswa.h] — bagian ini biasanya di file terpisah ===
 *
 * BAGIAN A — Include Guard & typedef Struct
 *
 * Lengkapi include guard dan definisi struct agar header
 * aman di-include lebih dari sekali.
 * ============================================================ */

/* (A1) Tulis baris pertama include guard — cek apakah MAHASISWA_H sudah didefinisikan */
#ifndef ____

/* (A2) Jika belum, definisikan sekarang */
#define ____

typedef struct {
    char nama[50];
    char nim[15];
    float ipk;
} Mahasiswa;

/* Prototipe fungsi — sudah benar, jangan ubah */
void tampilkan(Mahasiswa mhs);
void update_ipk(Mahasiswa *mhs, float ipk_baru);
int  cari_ipk_tertinggi(Mahasiswa kelas[], int jumlah);

/* (A3) Tutup blok #ifndef */
____


/* ============================================================
 * === [mahasiswa.c] — bagian ini biasanya di file terpisah ===
 *
 * BAGIAN B — Implementasi Fungsi
 *
 * Lengkapi tiga fungsi: tampilkan, update_ipk, dan
 * cari_ipk_tertinggi.
 * ============================================================ */

/* Fungsi tampilkan — menerima struct by value, hanya membaca */
void tampilkan(Mahasiswa mhs) {
    printf("%-20s | %-10s | %.2f\n",
           mhs.____,    // (B1) akses anggota nama
           mhs.nim,
           mhs.____);   // (B2) akses anggota ipk
}

/* Fungsi update_ipk — menerima pointer ke struct agar bisa mengubah data asli */
/* (B3) Lengkapi parameter: nama pointer dan tipe float untuk ipk_baru */
void update_ipk(____ *mhs, ____ ipk_baru) {
    mhs->____ = ipk_baru;   // (B4) update ipk via operator ->
}

/*
 * Fungsi cari_ipk_tertinggi
 * Menerima: array of struct Mahasiswa dan jumlah elemennya
 * Mengembalikan: indeks mahasiswa dengan IPK tertinggi
 */
int cari_ipk_tertinggi(Mahasiswa kelas[], int jumlah) {
    int indeks_tertinggi = 0;   /* asumsikan elemen pertama tertinggi dulu */

    for (int i = 1; i < jumlah; i++) {
        /* (B5) bandingkan ipk kelas[i] dengan ipk kelas[indeks_tertinggi] */
        if (kelas[i].____ > kelas[____].ipk) {
            indeks_tertinggi = i;
        }
    }

    return indeks_tertinggi;
}


/* ============================================================
 * === [main.c] — program utama ===
 *
 * BAGIAN C — Pointer ke Struct (operator ->)
 *
 * Lengkapi kode sehingga menghasilkan output:
 *   === Bagian C: Pointer ke Struct ===
 *   Sebelum update via pointer:
 *   Andi Pratama         | 2024001    | 3.75
 *   Sesudah update via pointer:
 *   Andi Pratama         | 2024001    | 3.85
 * ============================================================ */

void bagian_C() {
    Mahasiswa mhs1 = {"Andi Pratama", "2024001", 3.75};
    Mahasiswa *ptr;

    /* (C1) arahkan ptr ke alamat mhs1 */
    ptr = ____;

    printf("=== Bagian C: Pointer ke Struct ===\n");
    printf("Sebelum update via pointer:\n");

    /* (C2) panggil tampilkan dengan men-dereference ptr
       Ingat: ptr adalah pointer, tampilkan() butuh nilai Mahasiswa (bukan pointer) */
    tampilkan(____);

    /* (C3) update IPK mhs1 menjadi 3.85 menggunakan operator -> */
    ptr->____ = 3.85;

    printf("Sesudah update via pointer:\n");
    tampilkan(____);    // (C4) tampilkan mhs1 yang sudah diupdate (sama dengan C2)
}


/* ============================================================
 * BAGIAN D — Fungsi update_ipk & cari_ipk_tertinggi
 *
 * Lengkapi pemanggilan fungsi sehingga:
 * 1. IPK Budi diperbarui menjadi 3.70 via fungsi update_ipk
 * 2. Indeks mahasiswa dengan IPK tertinggi ditemukan dan ditampilkan
 *
 * Contoh output:
 *   === Bagian D: update_ipk & cari_ipk_tertinggi ===
 *   Data awal:
 *   Andi Pratama         | 2024001    | 3.75
 *   Budi Santoso         | 2024002    | 3.50
 *   Citra Dewi           | 2024003    | 3.90
 *
 *   Setelah update IPK Budi menjadi 3.70:
 *   Andi Pratama         | 2024001    | 3.75
 *   Budi Santoso         | 2024002    | 3.70
 *   Citra Dewi           | 2024003    | 3.90
 *
 *   IPK tertinggi: Citra Dewi (3.90)
 * ============================================================ */

void bagian_D() {
    Mahasiswa kelas[3] = {
        {"Andi Pratama", "2024001", 3.75},
        {"Budi Santoso", "2024002", 3.50},
        {"Citra Dewi",   "2024003", 3.90}
    };
    int jumlah = 3;

    printf("\n=== Bagian D: update_ipk & cari_ipk_tertinggi ===\n");
    printf("Data awal:\n");
    for (int i = 0; i < jumlah; i++) {
        tampilkan(kelas[i]);
    }

    /* (D1) panggil update_ipk untuk kelas[1] (Budi), IPK baru 3.70
       Ingat: update_ipk butuh POINTER ke Mahasiswa, bukan nilai-nya */
    update_ipk(____, ____);

    printf("\nSetelah update IPK Budi menjadi 3.70:\n");
    for (int i = 0; i < jumlah; i++) {
        tampilkan(kelas[i]);
    }

    /* (D2) panggil cari_ipk_tertinggi — kirim array dan jumlah elemen */
    int idx = cari_ipk_tertinggi(____, ____);

    printf("\nIPK tertinggi: %s (%.2f)\n",
           kelas[____].nama,    // (D3) akses nama mahasiswa di indeks idx
           kelas[idx].ipk);
}


/* ============================================================
 * main
 * ============================================================ */

int main() {
    bagian_C();
    bagian_D();
    return 0;
}
