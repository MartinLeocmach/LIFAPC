#include <cstdio>
#include "abrecherche.h"

abr::abr()
{
    this->racine = nullptr;
    minimum = nullptr;
}

abr::abr(Elem e)
{
    this->racine = new noeud(e);
    minimum = nullptr;
}

abr::abr(abr *a)
{
    minimum = a->minimum;
    this->racine = new noeud (a->racine);
}

abr::~abr()
{
    delete racine;
}


void abr::operator=(abr *a)
{
    this->racine=a->racine;
}

void abr::insertion (Elem e)
{
    if(racine !=nullptr)
    {
        this->racine->insertion(e);
    }
    else
    {
        racine = new noeud(e);
    }
}

bool abr::recherche (Elem e)
{
    return this->racine->recherche(e);
}

void abr::affichePrefix()
{
    this->racine->affichePrefixRec();
    printf ("\n");
}

void abr::affichePostfix()
{
    this->racine->affichePostfixRec();
    printf("\n");
}

void abr::afficheInfix()
{
    this->racine->afficheInfixRec();
    printf ("\n");
}

void abr::coudre()
{
    noeud *min = racine;
    if (racine == nullptr)
    {
        minimum = nullptr;
    }
    else
    {
        while (min->getFils_g() != nullptr)
        {
            min = min->getFils_g();
        }
        this->minimum = min;
        racine->coudreRec(nullptr);
    }
}

void abr::afficheCousu()
{
    noeud * curseur = minimum;
    bool remonte = false;
    while (curseur->getFils_d() != nullptr || (curseur->getFils_g() != nullptr && !remonte))
    {
        if (remonte || curseur->getFils_g()==nullptr)
        {
            curseur->getValue().affichageElement();
            if (curseur->isCoutured())
            {
                remonte = true;
            }
            else
            {
                remonte = false;
            }
            curseur = curseur->getFils_d();
        }
        else
        {
            curseur = curseur->getFils_g();
            remonte = false;
        }
    }
    curseur->getValue().affichageElement();
    printf("\n");
}

void abr::insertionCousu(Elem e)
{
    if (racine != nullptr)
    {
        racine->insertionCousu(e);
        if (e < minimum->getValue())
        {
            minimum = minimum->getFils_g();
        }
    }
    else
    {
        racine = new noeud(e);
        minimum = racine;
    }

}