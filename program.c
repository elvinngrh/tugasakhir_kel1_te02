#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define JUMLAH_FILM 5

int add_booking(int pilihan);
void pilih_film(int *pilihfilm);

struct Film {
    char judul_film[30];
    char rating_usia[5];
    char genre[15];
    char harga[20];
    char tayang[20];
};

struct Booking {
    int id;
    char pemesan[30];
    char judul[30];
    char jadwal_tayang[15];
    int jumlah_tiket;
    int total_pembayaran;
};

void Daftar_Film(struct Film film[]) { 

    char judul_film[JUMLAH_FILM][20] = {"Interstellar", "Avengers", "C", "D", "E"};
    char rating_usia[JUMLAH_FILM][20] = {"13+", "21+", "2+", "2+", "13"};
    char genre[JUMLAH_FILM][20] = {"Horror", "Komedi dewasa", "Anak", "Anak", "Thriller"};
    char harga[JUMLAH_FILM][20] = {"90000", "120000", "30.000", "65000", "100000"};
    char tanggal[JUMLAH_FILM][20] = {
        "19//07/2025",
        "kecha",
        "kecha",
        "kecha", 
        "kecha"
    };

    for (int i = 0; i < JUMLAH_FILM; i++) {
        strcpy(film[i].judul_film, judul_film[i]);
        strcpy(film[i].rating_usia, rating_usia[i]);
        strcpy(film[i].genre, genre[i]);
        strcpy(film[i].harga, harga[i]);
        strcpy(film[i].tayang, tanggal[i]);
    }
}

int total_harga(int pilihan, int jumlah_tiket) {
    struct Film daftar_film[JUMLAH_FILM];
    Daftar_Film(daftar_film);
    int harga_tiket = 0;
    int jumlah = jumlah_tiket;

    if (pilihan >= 1 && pilihan <= JUMLAH_FILM) {
        char *harga_str = daftar_film[pilihan - 1].harga;
        harga_tiket = atoi(harga_str);
    }

    return jumlah*harga_tiket;
}

int add_booking(int pilihan) {
    struct Film daftar_film[JUMLAH_FILM];
    Daftar_Film(daftar_film);
    struct Booking b1;
    char buffer[100];
    
    FILE *fp = fopen("booking.txt", "a");
    if (fp == NULL) {
        printf("Gagal membuka file!\n");
        return 1;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("Nama Pemesan         : ");
    fgets(b1.pemesan, sizeof(b1.pemesan), stdin);
    b1.pemesan[strcspn(b1.pemesan, "\n")] = '\0';

    printf("Jumlah Tiket         :");
    fgets(buffer, sizeof(buffer), stdin);
    b1.jumlah_tiket = strtol(buffer, NULL, 10);

    strcpy(b1.judul, daftar_film[pilihan-1].judul_film);
    strcpy(b1.jadwal_tayang, daftar_film[pilihan-1].tayang);
    b1.id = pilihan;
    b1.total_pembayaran = total_harga(pilihan, b1.jumlah_tiket);

    if (b1.jumlah_tiket <= 0) {
        printf("Jumlah tiket tidak valid!\n");
        fclose(fp);
        return 1;
    }

    fprintf(fp, "==================================================================================================================================\n");
    fprintf(fp, "| %-2s | %-30s | %-25s | %-20s | %-14s | %-20s |\n",
            "ID", "Nama", "Judul FILM", "Jadwal Tayang", "Jumlah Tiket", "Total Pembayaran");
    fprintf(fp, "==================================================================================================================================\n");

    fprintf(fp, "| %-2d | %-30s | %-25s | %-20s | %-14d | %-20d |\n",
        b1.id,
        b1.pemesan,
        b1.judul,
        b1.jadwal_tayang,
        b1.jumlah_tiket,
        b1.total_pembayaran);

    fprintf(fp, "==================================================================================================================================\n");

    fclose(fp);
    printf("\nbooking berhasil ditambahkan!\n");
    return 0;
}

void pilih_film(int *pilihfilm) {
    char ver;
    do {
    printf("\nSilahkan pilih film berdasarkan nomor urut (1 - %d):", JUMLAH_FILM);
    scanf("%d", pilihfilm);

    if (*pilihfilm < 1 || *pilihfilm > JUMLAH_FILM) {
        printf("Error! Pilihan tidak tersedia, silakan pilih kembali.\n");
    }

    } while (*pilihfilm < 1 || *pilihfilm > JUMLAH_FILM);

    printf("Apakah anda sudah yakin dengan pilihan anda? Y/N:");
    scanf("%s", &ver);
    
    do {
        if (ver != 'Y' && ver != 'N') {
            printf("Input tidak valid. Silakan masukkan 'Y' untuk Ya atau 'N' untuk Tidak: ");
            scanf(" %c", &ver);
    }
    } while (ver != 'Y' && ver != 'N');

    if (ver == 'Y') {
        printf("Anda telah memilih film nomor %d.\n", *pilihfilm);
        add_booking(*pilihfilm);
    } 
    else if (ver == 'N') {
        printf("Silakan pilih film kembali.\n");
        pilih_film(pilihfilm);
    }
}

void tabel_film() {
    struct Film daftar_film[JUMLAH_FILM];
    Daftar_Film(daftar_film);

    printf("=====================================================================================================================\n");
    printf("| %-2s | %-30.30s | %-12.12s | %-20.20s | %-14.14s | %-20.20s |\n", "NO", "Judul Film", "Rating Usia", "Genre", "Harga (Rp)", "Tayang Perdana");
    printf("=====================================================================================================================\n");
    for (int i = 0; i < JUMLAH_FILM; i++) {
        printf("| %-2d | %-30s | %-12s | %-20s | %-14s | %-20s |\n", 
            i+1,
            daftar_film[i].judul_film, 
            daftar_film[i].rating_usia, 
            daftar_film[i].genre,
            daftar_film[i].harga, 
            daftar_film[i].tayang);
    }
    printf("=====================================================================================================================\n");
}

int main() {
    struct Film daftar_film[JUMLAH_FILM];
    Daftar_Film(daftar_film);
    int pilihan_film;
    int pilih;
    
    do {
        printf("\n1. Lihat Film dan Jadwal");
        printf("\n2. Booking Tiket");
        printf("\n3. Lihat Lengkap");

        printf("\n0. Keluar\nPilih: ");
        scanf("%d", &pilih);

        if (pilih == 1) tabel_film();
        else if (pilih == 2) pilih_film(&pilihan_film);
        else if (pilih == 3) printf("\nFitur belum tersedia\n");
        else if (pilih == 0) printf("\nTerima kasih telah menggunakan layanan kami!\n");
        else printf("\nPilihan tidak valid, silakan coba lagi.\n");
    } while (pilih != 0);

    return 0;
}
