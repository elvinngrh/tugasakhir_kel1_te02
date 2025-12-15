#include <stdio.h>
#include <string.h>
#define jumlah_film 5

void DaftarFilm() {
    printf("======= Film Yang Akan Tayang=======");
}

struct Film {
    char judul_film[30];
    char rating_usia[5];
    char genre[15];
    char harga[20];
    char tayang[20];
};


void Daftar_Film(struct Film film[]) { 

    char judul_film[jumlah_film][20] = {"A", "B", "C", "D", "E"};
    char rating_usia[jumlah_film][20] = {"13+", "21+", "2+", "2+", "13="};
    char genre[jumlah_film][20] = {"Horror", "Komedi dewasa", "Anak", "Anak", "Thriller"};
    char harga[jumlah_film][20] = {"90.000,00", "120.000,00", "30.000,00", "65.000,00", "100.000,00"};
    char tanggal[jumlah_film][20] = {
        "19:30/02/07/2025",
        "kecha",
        "kecha",
        "kecha", 
        "kecha"
    };

    for (int i = 0; i < jumlah_film; i++) {
        strcpy(film[i].judul_film, judul_film[i]);
        strcpy(film[i].rating_usia, rating_usia[i]);
        strcpy(film[i].genre, genre[i]);
        strcpy(film[i].harga, harga[i]);
        strcpy(film[i].tayang, tanggal[i]);
    }
}

void tabel_film() {
    struct Film daftar_film[jumlah_film];
    Daftar_Film(daftar_film);

    printf("=====================================================================================================================\n");
    printf("| %-2s | %-30s | %-12s | %-20s | %-14s | %-20s |\n", "NO", "Judul Film", "Rating Usia", "Genre", "Harga (Rp)", "Tayang Perdana");
    printf("=====================================================================================================================\n");
    for (int i = 0; i < jumlah_film; i++) {
        printf("| %-2d | %-30.30s | %-12.12s | %-20.20s | %-14s | %-20.20s |\n", 
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
    tabel_film();
    
    return 0;
}
