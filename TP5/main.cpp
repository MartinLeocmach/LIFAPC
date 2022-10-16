#include <iostream>
#include <cstdio>
#include "hashTable.h"
#include "product.h"


int hashModulo(key k, int taille)
{
    return k%taille;
}

int rehashLineaire(int indice, int numEssai, int taille)
{
    return (indice+1)%taille;
}

int rehashQuad(int indice, int numEssai, int taille)
{
    unsigned int ui = indice+((numEssai-1)*(numEssai-1));
    return (indice+(ui))%taille;
}

int main ()
{
    hashTable hTable(hashModulo, rehashQuad);
    product *p;
    key cle = 51546;
    double value = 45.454;
    for (int i=0; i<999; i++)
    {
        p = new product(cle, value);
        hTable.insertion(p);
        cle= cle+80;
        value++;
    }
    printf("insertions ok\n");
    p= new product (51550, 45.65);
    if (hTable.recherche(p))
    {
        printf("%d est dans la table\n", p->getKey());
    }
    else
    {
        printf("%d n'est pas dans la table\n", p->getKey());
    }
    //hTable.afficheTable();
    p = new product(51546, 45.454);
    hTable.insertion(p);
    hTable.afficheElement(51546);
    return 0;
}