#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char jadwal_tayang[20];
    int jumlah_tiket;
    int total_pembayaran;
};

void Daftar_Film(struct Film film[]) {
    char judul_film[JUMLAH_FILM][20] = {"Interstellar", "The Avengers", "Jumbo", "Boboiboy The Movie", "Insidious"};
    char rating_usia[JUMLAH_FILM][20] = {"13+", "13+", "SU", "7+", "17+"};
    char genre[JUMLAH_FILM][20] = {"Sci-Fi", "Superhero", "Keluarga", "Fantasi", "Horror"};
    char harga[JUMLAH_FILM][20] = {"50000", "60000", "40000", "45000", "50000"};
    char tanggal[JUMLAH_FILM][20] = {"4/01/2026", "20/01/2026", "1/02/2026", "17/02/2026", "9/03/2026"};

    for (int i = 0; i < JUMLAH_FILM; i++) {
        strcpy(film[i].judul_film, judul_film[i]);
        strcpy(film[i].rating_usia, rating_usia[i]);
        strcpy(film[i].genre, genre[i]);
        strcpy(film[i].harga, harga[i]);
        strcpy(film[i].tayang, tanggal[i]);
    }
}

int total_harga(int pilihan, int jumlah_tiket) {
    struct Film film[JUMLAH_FILM];
    Daftar_Film(film);
    return atoi(film[pilihan - 1].harga) * jumlah_tiket;
}

int add_booking(int pilihan) {
    struct Film film[JUMLAH_FILM];
    Daftar_Film(film);

    struct Booking b1;
    char buffer[50];

    FILE *fp = fopen("booking.txt", "a+");
    if (!fp) {
        printf("Gagal membuka file!\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    if (size == 0) {
        fprintf(fp, "==================================================================================================================================\n");
        fprintf(fp, "| %-2s | %-30s | %-25s | %-20s | %-14s | %-20s |\n",
                "ID", "Nama", "Judul Film", "Jadwal", "Jumlah Tiket", "Total Biaya");
        fprintf(fp, "==================================================================================================================================\n");
    }

    getchar();

    printf("Nama Pemesan : ");
    fgets(b1.pemesan, sizeof(b1.pemesan), stdin);
    b1.pemesan[strcspn(b1.pemesan, "\n")] = 0;

    printf("Jumlah Tiket : ");
    fgets(buffer, sizeof(buffer), stdin);
    b1.jumlah_tiket = atoi(buffer);

    if (b1.jumlah_tiket <= 0) {
        printf("Jumlah tiket tidak valid!\n");
        fclose(fp);
        return 1;
    }
    strcpy(b1.judul, film[pilihan - 1].judul_film);
    strcpy(b1.jadwal_tayang, film[pilihan - 1].tayang);
    b1.id = pilihan;
    b1.total_pembayaran = total_harga(pilihan, b1.jumlah_tiket);
    fprintf(fp, "| %-2d | %-30s | %-25s | %-20s | %-14d | Rp%-17d |\n",
            b1.id,
            b1.pemesan,
            b1.judul,
            b1.jadwal_tayang,
            b1.jumlah_tiket,
            b1.total_pembayaran);

    fprintf(fp, "==================================================================================================================================\n");
    fclose(fp);
    printf("Booking berhasil disimpan!\n");
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
    scanf(" %c", &ver);
    
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
    struct Film film[JUMLAH_FILM];
    Daftar_Film(film);

    printf("\n====================================================================================================\n");
    printf("| %-2s | %-30s | %-10s | %-15s | %-10s | %-15s |\n",
           "No", "Judul", "Rating", "Genre", "Harga", "Tayang");
    printf("====================================================================================================\n");

    for (int i = 0; i < JUMLAH_FILM; i++) {
        printf("| %-2d | %-30s | %-10s | %-15s | Rp%-7s | %-15s |\n",
               i + 1,
               film[i].judul_film,
               film[i].rating_usia,
               film[i].genre,
               film[i].harga,
               film[i].tayang);
    }
    printf("====================================================================================================\n");
}

int main() {
    int pilih, film;

    do {
        printf("\n=== MENU ===");
        printf("\n1. Lihat Film");
        printf("\n2. Booking Tiket");
        printf("\n0. Keluar");
        printf("\nPilih: ");
        scanf("%d", &pilih);

        if (pilih == 1) tabel_film();
        else if (pilih == 2) pilih_film(&film);
        else if (pilih == 0) printf("Terima kasih!\n");
        else printf("Pilihan tidak valid!\n");

    } while (pilih != 0);

    return 0;
}
