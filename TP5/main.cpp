#include <iostream>
#include "hashTable.h"


int hashModulo(key k, int taille)
{
    return k%taille;
}

int rehashLineaire(int indice, key k, int taille)
{
    return indice+1%taille;
}

int main ()
{
    hashTable hTable(hashModulo, rehashLineaire);
    product *p = new product();
    p->deleted = false;
    int cle = 51546;
    double value = 45.454;
    hTable.insertion(p);
    for (int i=0; i<1002; i++)
    {
        hTable.insertion(p);
        p->k++;
        p->v++;
    }
    p->k = 51400;
    if (hTable.recherche(p))
    {
        printf("%d est dans la table\n", p->k);
    }
    return 0;
}