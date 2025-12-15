#include <stdio.h>
#include <string.h>
struct Film {
    int id;
    char judul[50];
    int durasi;
};

struct Jadwal {
    int id;
    int jam;
    int menit;
};

struct Booking {
    int id;
    int id_jadwal;
    char nama[50];
    int tiket;
};

void tampilFilm() {
    FILE *fp = fopen("film.txt", "r");
    struct Film f;

    printf("\nID | Judul | Durasi\n");
    printf("---------------------\n");
    while (fscanf(fp, "%d|%[^|]|%d\n",
                  &f.id, f.judul, &f.durasi) == 3) {
        printf("%d | %s | %d menit\n", f.id, f.judul, f.durasi);
    }
    fclose(fp);
}

void tampilJadwal(){
FILE *fj = fopen("jadwal.txt", "r");
    struct Jadwal j;

    printf("\nID Jadwal | Waktu \n");
    printf("--------------------\n");
    while (fscanf(fj, "%d|%d|%d\n", &j.id, &j.jam, &j.menit) == 3) {
        printf("%-9d | %02d:%02d\n", j.id, j.jam, j.menit);
    }
    fclose(fj);

}

void tambahBooking() {
    FILE *fp = fopen("booking.txt", "a");
    struct Booking b;

    printf("ID Booking   : ");
    scanf("%d", &b.id);

    printf("ID Jadwal    : ");
    scanf("%d", &b.id_jadwal);
    getchar();

    printf("Nama Pemesan : ");
    fgets(b.nama, sizeof(b.nama), stdin);
    b.nama[strcspn(b.nama, "\n")] = 0;

    printf("Jumlah Tiket : ");
    scanf("%d", &b.tiket);

    fprintf(fp, "%d|%d|%s|%d",
            b.id, b.id_jadwal, b.nama, b.tiket);

    fclose(fp);
    printf("Booking berhasil!\n");
}
void tampilBookingLengkap() {
    FILE *fb = fopen("booking.txt", "r");
    FILE *fj = fopen("jadwal.txt", "r");
    FILE *ff = fopen("film.txt", "r");

    if (fb == NULL || fj == NULL || ff == NULL) {
        printf("Salah satu file tidak ditemukan!\n");
        return;
    }

    struct Booking b;
    struct Jadwal j;
    struct Film f;

    printf("\nBooking Lengkap:\n");
    printf("Nama | Judul Film | Waktu | Tiket\n");
    printf("-------------------------------------\n");

    while (fscanf(fb, "%d|%d|%[^|]|%d\n",
                  &b.id, &b.id_jadwal, b.nama, &b.tiket) == 4) {

        rewind(fj);
        while (fscanf(fj, "%d|%d|%d\n", &j.id, &j.jam, &j.menit) == 3) {

            if (j.id == b.id_jadwal) {

                rewind(ff);
                while (fscanf(ff, "%d|%[^|]|%d\n", &f.id, f.judul, &f.durasi) == 3) {

                    if (f.id == j.id) {
                        printf("%s | %s | %02d:%02d | %d tiket\n",
                               b.nama, f.judul, j.jam, j.menit, b.tiket);
                    }

                }
            }
        }
    }

    fclose(fb);
    fclose(fj);
    fclose(ff);
}

int main() {
    int pilih;
    do {
        printf("\n1. Lihat Film");
        printf("\n2. Booking Tiket");
        printf("\n3. Lihat Booking Lengkap");
        printf("\n4. Lihat Jadwal");
        printf("\n0. Keluar\nPilih: ");
        scanf("%d", &pilih);

        if (pilih == 1) tampilFilm();
        else if (pilih == 2) tambahBooking();
        else if (pilih == 3) tampilBookingLengkap();
        else if (pilih == 4) tampilJadwal();
    } while (pilih != 0);
}
