#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    char persons[5][8] = { "Vacilev\0",
                           "Vlogura\0",
                           "Nivilev\0",
                           "Prinuba\0",
                           "Fremeta\0" };
    char prazdnik[3][13] = { "DnemUchitela\0",
                           "DnemRabocego\0",
                           "NovimGodom\0" };
    char pozd1[3][9] = { "Schastya\0",
                           "Zdorowya\0",
                           "Udachi\0" };
    char pozd2[3][9] = { "Deneshek\0",
                           "Poznaniy\0",
                           "Lubvi\0" };
    char pozd3[3][9] = { "GoodMood\0",
                           "Energicn\0",
                           "Dobroty\0" };
    for (int j = 0; j < 5; j++) {

        int i = rand() % 3;
        int i1 = rand() % 3;
        int i2 = rand() % 3;
        int i3 = rand() % 3;

        printf("%s pozdravlyau tebya c %s. I shelau %s, %s i %s\n", persons[j] , prazdnik[i] , pozd1[i1] , pozd2[i2] , pozd3[i3] );
    }
    getch();

    return 0;
}