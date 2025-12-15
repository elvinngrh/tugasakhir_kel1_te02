#include <stdio.h>

void DaftarFilm() {
    printf("======= Film Yang Akan Tayang=======");
}

struct Film {
    char judul_film[30];
    char rating_usia[5];
    char genre[15];
    int durasi;
    char tayang[20];
};

int main() {
    struct Film daftar_film[jumlah_film] = {
        /*{judul, rating usia, genre, durasi,  jadwal tayang},*/
        {"A", "13+", "Horror", 90,  "19:30/02/07/2025"},
        {"B", "21+", "Komedi Dewasa", 30, "kecha"},
        {"C", "2+",  "Anak", 120, "kecha"},
        {"D", "2+",  "Anak", 60,  "kecha"},
        {"E", "13+", "Thriller", 120, "kecha"}
    };

    printf("=====================================================================================================================\n");
    printf("| %-2s | %-30s | %-12s | %-20s | %-14s | %-20s |\n", "NO", "Judul Film", "Rating Usia", "Genre", "Durasi (menit)", "Tayang Perdana");
    printf("=====================================================================================================================\n");
    for (int i = 0; i < jumlah_film; i++) {
        printf("| %-2d | %-30.30s | %-12.12s | %-20.20s | %-14d | %-20.20s |\n", 
            i+1, 
            daftar_film[i].judul_film, 
            daftar_film[i].rating_usia, 
            daftar_film[i].genre, 
            daftar_film[i].durasi, 
            daftar_film[i].tayang);
    }
    printf("=====================================================================================================================\n");

    return 0;
}
