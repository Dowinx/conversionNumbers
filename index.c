#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct indiceConvert indiceConvert;

struct indiceConvert
{
    int indiceConvertIn;
    int indiceConvertOut;
    char uniteConvertIn[4];
    char uniteConvertOut[4];
};

indiceConvert rechercheIndice()
{
    char *unite[] = {"km", "hm", "dam", "m", "dm", "cm", "mm"};

    char uniteConvertIn[4];
    printf("unite 1 \n");
    scanf("%s", uniteConvertIn);

    char uniteConvertOut[4];
    printf("unite 2 \n");
    scanf("%s", uniteConvertOut);

    int i;
    indiceConvert result = {0, 0, "", ""};

    for (i = 0; i < 7; i++)
    {
        if (strcmp(unite[i], uniteConvertIn) == 0)
        {
            result.indiceConvertIn = i;
            strcpy(result.uniteConvertIn, unite[i]);
            // printf("indice en entree : %d \n", i);
        }
        if (strcmp(unite[i], uniteConvertOut) == 0)
        {
            result.indiceConvertOut = i;
            strcpy(result.uniteConvertOut, unite[i]);
            // printf("indice en sortie : %d \n", i);
        }
    }
    return result;
}

double convertLeftToRight(indiceConvert result);
double convertRightToLeft(indiceConvert result);

int main()
{

    indiceConvert result = rechercheIndice();

    if (result.indiceConvertIn > result.indiceConvertOut)
    {
        convertRightToLeft(result);
    }
    else if ((result.indiceConvertIn < result.indiceConvertOut))
    {
        convertLeftToRight(result);
    }
    else
    {
        printf("Tu converties deux unites pareils, change ! ");
    }

    // printf("Tu veux convertir de la gauche vers la droite (GD) ou l'inverse (DG)");
    // char sens[3];
    // scanf("%s", &sens);

    // if (strcmp(sens, "GD") == 0)
    // {
    //     convertLeftToRight();
    // }
    // else if (strcmp(sens, "DG") == 0)
    // {
    //     convertRightToLeft();
    // }
    // else
    // {
    //     printf("T'as pas inserer la bonne lettre.");
    // }

    return 0;
}

// gauche à droite
double convertLeftToRight(indiceConvert result)
{
    printf("Choisis le nombre a convertir : \n");
    double nbr;
    scanf("%lf", &nbr);

    char convertIn[4];
    strcpy(convertIn, result.uniteConvertIn);

    char convertOut[4];
    strcpy(convertOut, result.uniteConvertOut);

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
    printf("%.4lf", nbr); // 4chiffres apres la virgule
    return nbr;
}

// droite à gauche
double convertRightToLeft(indiceConvert result)
{
    printf("Choisis le nombre a convertir : \n");
    double nbr;
    scanf("%lf", &nbr);

    char convertIn[4];
    strcpy(convertIn, result.uniteConvertIn);

    char convertOut[4];
    strcpy(convertOut, result.uniteConvertOut);

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
    printf("%lf", nbr);
    return nbr;
}
