#include <iostream>
#include <cstdio>
#include "skipList.h"
#include <vector>
#include <time.h>

//Constructeur
//this est une liste vide
skipList::skipList()
{
    this->ad = new Cellule;
    this->ad->psuivant.push_back (nullptr);
}

//Destructeur Cellule
Cellule::~Cellule()
{
    if (psuivant[0] != nullptr)
    {
        delete psuivant[0];
    }
}

//Destructeur skipList
skipList::~skipList()
{
    delete ad;
}

bool skipList::pile_ou_face ()
{
    return rand()%2;
}
void skipList::insertion (Elem v)
{
    int niveau = ad->psuivant.size()-1;
    Cellule * c = ad;
    Cellule * nouvelle = new Cellule();
    std::vector<Cellule *> buffer(niveau+1);
    bool b = true;
    nouvelle->info = v;
    while (niveau >= 0)
    {
        while ((c->psuivant[niveau] != nullptr) && (c->psuivant[niveau]->info < v))
        {
            c = c->psuivant[niveau];
        }
        buffer[niveau] = c;
        niveau--;
    }
    niveau = 0;
    while (b)
    {
        if (niveau < ad->psuivant.size())
        {
            nouvelle->psuivant.push_back(buffer[niveau]->psuivant[niveau]);
            buffer[niveau]->psuivant[niveau] = nouvelle;
        }
        else
        {
            nouvelle->psuivant.push_back(nullptr);
            ad->psuivant.push_back(nouvelle);
        }
        b = pile_ou_face();
        niveau++;
    }
    printf ("fin insertion\n");
}

void skipList::affiche ()
{
    Cellule *c;
    printf("affichage liste :\n");
    if (ad->psuivant[0] != nullptr)
    {
        c = ad->psuivant[0];
    
        while (c->psuivant[0] != nullptr)
        {   
            std::cout << c->info << std::endl;
            c = c->psuivant[0];
        }
        std::cout << c->info << std::endl;
    }
}

void skipList::suppression (Elem v)
{
    int niveau = ad->psuivant.size() - 1;
    Cellule *c = ad;
    std::vector<Cellule *> buffer(niveau+1);
    while (niveau >= 0)
    {
        printf("boucle while\n");
        while ((c->psuivant[niveau] != nullptr) && (c->psuivant[niveau]->info < v))
        {
            c = c->psuivant[niveau];
        }
        buffer[niveau] = c;
        niveau --;
    }
    niveau = 0;
    if (c->psuivant[0]->info == v)
    {
        Cellule* dead = c->psuivant[0];
        printf ("élément à supprimer trouvé\n");
        while ((niveau < dead->psuivant.size()))
        {
            buffer[niveau]->psuivant[niveau] = dead->psuivant[niveau];
            dead->psuivant[niveau] = nullptr ;
            niveau++;
        }
        delete dead;
    }
}