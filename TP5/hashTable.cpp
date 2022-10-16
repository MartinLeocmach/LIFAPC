#include <iostream>
#include <cstdio>
#include "hashTable.h"


//Constructeur
hashTable::hashTable(int (*h)(key, int), int(*rh)(int, int, int))
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
    int compteur = 0;
    if (nbElem==taille)
    {
        printf("Table pleine \n");
    }
    else
    {
        int i = hash(p->getKey(), taille);
        while(this->tab[i]!=nullptr && !(p->isDeleted()) && compteur<taille)
        {   
            if(this->tab[i]->getKey()==p->getKey())
            {
                printf("Produit deja dans la table\n");
                return;
            }
            compteur++;
            i = rehash(i, compteur+1, taille);
        }
        tab[i]= p;
        nbElem++;
    }
}

bool hashTable::recherche (product *p)
{
    int i = hash(p->getKey(), taille);
    int compteur = 0;
    while (tab[i] !=nullptr && !(p->isDeleted()) && compteur<taille)
    {
        if (tab[i]->getKey() == p->getKey())
        {
            return true; 
        }
        compteur++;
        i = rehash(i, compteur+1, taille);
    }
    return false;
}

void hashTable::afficheTable()
{
    for (int i=0; i<taille; i++)
    {
        if ((tab[i] != nullptr) && (!tab[i]->isDeleted()))
        {
            printf("%u  -> %f\n", tab[i]->getKey(), tab[i]->getValue());
        }
    }
}

bool hashTable::suppression(product *p)
{
    int i = hash(p->getKey(), taille);
    int compteur = 0;
    while (tab[i] !=nullptr && !(tab[i]->isDeleted()) && compteur<taille)
    {
        if (tab[i]->getKey() == p->getKey())
        {
            tab[i]->doDelete();
            nbElem--;
            return true; 
        }
        compteur++;
        i = rehash(i, compteur+1, taille);
    }
    return false;
}

void hashTable::afficheElement(key key)
{
    int i = hash(key, taille);
    int nbEssai = 0;
    while(tab[i] !=nullptr && !(tab[i]->isDeleted()) && nbEssai<taille)
    {
        
        if (tab[i]->getKey() == key)
        {
            printf("in if \n");
            printf("%u -> %f : %d rehachages\n", tab[i]->getKey(), tab[i]->getValue(), nbEssai);
            return;
        }
        nbEssai++;
        i = rehash(i, nbEssai+1, taille);
    }
    printf ("l'élément avec la clé %u n'est pas dans la table\n", key);
}