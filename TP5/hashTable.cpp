#include <iostream>
#include <cstdio>
#include "hashTable.h"


//Constructeur
hashTable::hashTable(int (*h)(key, int), int(*rh)(int, key, int))
{
    this->hash = h;
    this->rehash = rh;
    nbElem = 0;
    taille = 1000;
    for (int i=0; i<taille; i++)
    {
        this->tab[i] = nullptr;
    }
}

hashTable::~hashTable()
{
}

void hashTable::insertion (product *p)
{
    if (nbElem==taille)
    {
        printf("Table pleine \n");
    }
    else
    {
        int i = hash(p->k, taille);
        while(this->tab[i]!=nullptr && !(p->deleted))
        {   
            if(this->tab[i]->k==p->k)
            {
                printf("Produit deja dans la table\n");
                return;
            }
            i = rehash(i, p->k, taille);
        }
        tab[i]= p;
        nbElem++;
    }
}

bool hashTable::recherche (product *p)
{
    int i = hash(p->k, taille);
    while (tab[i] !=nullptr && !(p->deleted))
    {
        if (tab[i]->k == p->k)
        {
            return true; 
        }
        i = rehash(i, p->k, taille);
    }
    return false;
}