#include <cstdio>
#include "arbreAVL.h"

AVL::AVL()
{
    this->racine = nullptr;
}

AVL::AVL(Elem e)
{
    this->racine = new noeud(e);
}

AVL::AVL(AVL *a)
{
    this->racine = new noeud (a->racine);
}

AVL::~AVL()
{
    delete racine;
}


void AVL::operator=(AVL *a)
{
    this->racine=a->racine;
}

void AVL::insertion (Elem e)
{
    noeud* desequilibre;
    if(racine !=nullptr)
    {
        desequilibre = racine->insertion(e);
        if(desequilibre)
        {
            
        }
    }
    else
    {
        racine = new noeud(e);
    }
}

bool AVL::recherche (Elem e)
{
    return this->racine->recherche(e);
}

void AVL::affichePrefix()
{
    this->racine->affichePrefixRec();
    printf ("\n");
}

void AVL::affichePostfix()
{
    this->racine->affichePostfixRec();
    printf("\n");
}

void AVL::afficheInfix()
{
    this->racine->afficheInfixRec();
    printf ("\n");
}

void AVL::rotationGauche(noeud* &pN)
{
    noeud* buffer = pN->getFils_d();
    pN->changeFils_d(buffer->getFils_g());
    buffer->changeFils_g(pN);
    pN = buffer;
}

void AVL::rotationDroite(noeud* &pN)
{
    noeud* buffer = pN->getFils_g();
    pN->changeFils_g(buffer->getFils_d());
    buffer->changeFils_d(pN);
    pN = buffer;
}

void AVL::rotationDoubleGauche(noeud* &pN)
{
    noeud *buffer = pN->getFils_d();
    rotationDroite(buffer);
    pN->changeFils_d(buffer);
    rotationGauche(pN);

    /* Just in case une autre version
    noeud* buffer = pN->getFils_d()->getFils_g();
    pN->getFils_d()->changeFils_g(buffer->getFils_d());
    buffer->changeFils_d(pN->getFils_d());
    pN->changeFils_d(buffer);
    rotationGauche(pN);*/
}

void AVL::rotationDoubleDroite(noeud* &pN)
{
    noeud *buffer = pN->getFils_g();
    rotationGauche(buffer);
    pN->changeFils_g(buffer);
    rotationDroite(pN);
}