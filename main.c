#include <stdio.h>

void DaftarFilm() {
    printf("======= Film Yang Akan Tayang=======");
}

int main() {

    int jumlah_film = 5;
    int No_film = jumlah_film;
    char film[5][30] = {

    }; /*Ini misalkan filmnya*/

    char rating_usia[5][30] = {

    }; /*Rating usia*/

    char genre_film[5][30] = {

    }; /*genre film, boleh lebih dari satu*/

        int durasi_film[5][30] = {

    }; /*Durasi*/


    printf("===================================================\n");
    printf("| %-2s | %-8s | %-8s | %-6s | %-5s |\n", "NO", "Judul Film", "Rating Usia", "Genre", "Durasi");
    printf("===================================================\n");

    for (int i; i < jumlah_film; i++) {
        printf("| %-2d | %-8s | %-8s | %-6s | %-5s |\n", i, film[i], rating_usia[i], genre_film[i], durasi_film[i]);

    }

}
