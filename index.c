#include <stdlib.h>
#include <stdio.h>
#include <string.h>
double convertLeftToRight();
double convertRightToLeft();

int main()
{
    printf("Tu veux convertir de la gauche vers la droite (GD) ou l'inverse (DG)");
    char sens[3];
    scanf("%s", &sens);

    if (strcmp(sens, "GD") == 0)
    {
        convertLeftToRight();
    }
    else if (strcmp(sens, "DG") == 0)
    {
        convertRightToLeft();
    }
    else
    {
        printf("T'as pas inserer la bonne lettre.");
    }

    return 0;
}

// droite à gauche
double convertLeftToRight()
{
    printf("Choisis le nombre a convertir : \n");
    double nbr;
    scanf("%lf", &nbr);

    printf("De quel unite veut tu convertir : \n");
    char convertIn[4];
    scanf("%s", convertIn);

    printf("A quel unite : \n");
    char convertOut[4];
    scanf("%s", convertOut);

    if (strcmp(convertIn, convertOut) == 0)
    {
        printf("%g", nbr);
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
    printf("%.2lf", nbr); // 2chiffres apres la virgule
    return nbr;
}

// gauche à droite
double convertRightToLeft()
{
    printf("Choisis le nombre a convertir : \n");
    double nbr;
    scanf("%lf", &nbr);

    printf("De quel unite veut tu convertir : \n");
    char convertIn[4];
    scanf("%s", convertIn);

    printf("A quel unite : \n");
    char convertOut[4];
    scanf("%s", convertOut);

    if (strcmp(convertIn, convertOut) == 0)
    {
        printf("%g", nbr);
        return nbr;
    }

    while (strcmp(convertIn, convertOut) != 0)
    {
        if (strcmp(convertIn, "mm") == 0)
        {
            strcpy(convertIn, "cm");
            nbr /= 10;
        }
        else if (strcmp(convertIn, "cm") == 0)
        {
            strcpy(convertIn, "dm");
            nbr /= 10;
        }
        else if (strcmp(convertIn, "dm") == 0)
        {
            strcpy(convertIn, "m");
            nbr /= 10;
        }
        else if (strcmp(convertIn, "m") == 0)
        {
            strcpy(convertIn, "dam");
            nbr /= 10;
        }
        else if (strcmp(convertIn, "dam") == 0)
        {
            strcpy(convertIn, "hm");
            nbr /= 10;
        }
        else if (strcmp(convertIn, "hm") == 0)
        {
            strcpy(convertIn, "km");
            nbr /= 10;
        }
        else
        {
            printf("Unite non conforme, impossible de convertir !");
            return -1;
        }
    }
    printf("%g", nbr); // %g permet d'enlever les zero inutiles
    return nbr;
}