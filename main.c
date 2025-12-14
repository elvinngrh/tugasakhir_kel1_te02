#include <stdio.h>

void DaftarFilm() {
    printf("======= Film Yang Akan Tayang=======");
}

int main() {
    char film[5][20] = {
        "A",
        "B",
        "C",
        "D",
        "E"
    };

    char rating_usia[5][5] = {
        "13+",
        "21+",
        "2+",
        "2+",
        "13+"
    };

    char genre_film[5][20] = {
        "Horror",
        "Komedi Dewasa",
        "Anak",
        "Anak",
        "Thriller"
    };

    int durasi[5] = {
        90,
        30,
        120,
        60,
        120
    };
    char tayang[5][20] = {
        "19:30/02/07/2025", 
        "kecha",
        "kecha",
        "kecha",
        "kecha"};

    printf("====================================================================================================================\n");
    printf("| %-2s | %-30s | %-8s | %-20s | %-10s | %-20s |\n", "NO", "Judul Film", "Rating Usia", "Genre", "Durasi (menit)", "Tayang Perdana");
    printf("====================================================================================================================\n");
    for (int i; i < jumlah_film; i++) {
        printf("| %-2d | %-30s | %-11s | %-20s | %-14d | %-20s |\n", i+1, film[i], rating_usia[i], genre_film[i], durasi[i], tayang[i]);
    }
    printf("====================================================================================================================\n");

    return 0;
}
