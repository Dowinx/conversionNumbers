#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int convertLeftToRight();

int main()
{
    convertLeftToRight();
    return 0;
}

// SANS VIRGULE
int convertLeftToRight()
{
    printf("Choisis le nombre a convertir : \n");
    int nbr;
    scanf("%d", &nbr);

    printf("De quel unite veut tu convertir : \n");
    char convertIn[4];
    scanf("%s", convertIn);

    printf("A quel unite : \n");
    char convertOut[4];
    scanf("%s", convertOut);

    if (strcmp(convertIn, convertOut) == 0)
    {
        printf("%d", nbr);
        return nbr;
    }

    while (strcmp(convertIn, convertOut) != 0)
    {
        if (strcmp(convertIn, "km") == 0)
        {
            strcpy(convertIn, "hm");
            nbr *= 10;
        }
        else if (strcmp(convertIn, "hm") == 0)
        {
            strcpy(convertIn, "dam");
            nbr *= 10;
        }
        else if (strcmp(convertIn, "dam") == 0)
        {
            strcpy(convertIn, "m");
            nbr *= 10;
        }
        else if (strcmp(convertIn, "m") == 0)
        {
            strcpy(convertIn, "dm");
            nbr *= 10;
        }
        else if (strcmp(convertIn, "dm") == 0)
        {
            strcpy(convertIn, "cm");
            nbr *= 10;
        }
        else if (strcmp(convertIn, "cm") == 0)
        {
            strcpy(convertIn, "mm");
            nbr *= 10;
        }
        else
        {
            printf("Unite non conforme, impossible de convertir !");
            return -1;
        }
    }
    printf("%d", nbr);
    return nbr;
}