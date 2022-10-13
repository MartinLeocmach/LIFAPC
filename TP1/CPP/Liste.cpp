#include <iostream>
#include <cstdio>
#include "liste.h"

Liste::Liste()
{
    std::cout << ("Liste::Liste()") << std::endl;
    this->taille = 0;
    this->ad = nullptr;
}

Liste::Liste(const Liste & l)
{
    this->taille = 0;
    this->ad = nullptr;
    Cellule * C = l.ad;
    while (C != nullptr)
    {
        ajoutEnQueue(C->info);
        C = celluleSuivante(C);
    }
}

Cellule::~Cellule()
{
    delete this->psuivant;
}

bool Liste::testVide() const
{
    return (this->taille == 0);
}

Elem Liste::premierElement() const
{
    return this->ad->info;
}

Cellule * Liste::premiereCellule() const
{
    return this->ad;
}

Cellule * Liste::celluleSuivante(const Cellule *pc) const
{
    if (this->testVide())
    {
        return nullptr;
    }
    return pc->psuivant;
}

Elem Liste::elementCellule(const Cellule * pc) const
{
    return pc->info;
}

void Liste::affichage() const
{
    Cellule *C = new Cellule;
    C = this->ad;
    while (C !=nullptr)
    {
        std::cout << C->info << " " << std::endl;
        C = C->psuivant;
    }
}

void Liste::ajoutEnTete(const Elem & e)
{
    Cellule *C = new Cellule;
    C->info = e;
    C->psuivant = this->ad;
    this->ad = C;
    this->taille++;
    std::cout << "ajout en tete. taille =" << this->taille << std::endl;
}

void Liste::suppressionEnTete()
{
    Cellule *C = new Cellule;
    C = this->celluleSuivante(this->ad);
    this->ad->psuivant = nullptr;
    this->ad->~Cellule();
    this->ad = C;
    this->taille--;
}

void Liste::vide()
{
    std::cout << "vidage liste" <<std::endl;
    delete this->ad;
    this->ad = nullptr;
    this->taille = 0;
    std::cout << "liste vidée" <<std::endl;
}

void Liste::ajoutEnQueue(const Elem & e)
{
    Cellule *C;
    Cellule *Q = new Cellule;
    Q->info = e;
    Q->psuivant = nullptr;
    int i;
    if (testVide())
    {
        this->ad = Q;
        this->taille++;
    }
    else
    {
        C = this->ad;
        for (i=0; i<this->taille-1; i++)
        {
            C = this->celluleSuivante(C);
        }
        C->psuivant = Q;
        this->taille++;
    }
}

Cellule * Liste::rechercheElement(const Elem & e) const
{
    Cellule *C = this->ad;
    while (C != nullptr || C->info == e)
    {
        C = this->celluleSuivante(C);
    }
    std::cout << "element trouve" << std::endl;
    return C;

}

Liste & Liste::operator = (const Liste & l)
{
    this->ad = new Cellule;
    this->ad->info = l.ad->info;
    this->ad->psuivant = this->ad->psuivant;
    return *this;
}

Liste::~Liste()
{
    delete this->ad;
}
