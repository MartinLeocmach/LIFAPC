#include <cstdio>
#include "abrecherche.h"

abr::abr()
{
    this->racine = new noeud();
}

abr::abr(Elem e)
{
    this->racine = new noeud(e);
}

abr::abr(abr *a)
{
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
    this->racine->insertion(e);
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
    while (min != nullptr)
    {
        min = min->getFils_g();
    }
    this->minimum = min;
    racine->coudreRec(nullptr);
}

void abr::afficheCousu()
{
    noeud * curseur = minimum;
    bool remonte = false;
    while (minimum->getFils_g() != nullptr)
    {
    }

}