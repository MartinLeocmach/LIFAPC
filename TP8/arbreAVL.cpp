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

noeud* AVL::getRacine()
{
    return racine;
}

void AVL::operator=(AVL *a)
{
    this->racine=a->racine;
}

void AVL::insertion (Elem e)
{
    if(racine)
    {
        noeud** desequilibre = racine->insertion(e); 
        if (desequilibre ==nullptr && racine->checkDesequilibre())
        {
            desequilibre = &racine;
        }
        else
        {
            racine->majHauteur();
        }
        if (desequilibre)
        {
            if((*desequilibre)->getFils_g()->getHauteur() > (*desequilibre)->getFils_d()->getHauteur())
            {
                if ((*desequilibre)->getFils_g()->getFils_g()->getHauteur() > (*desequilibre)->getFils_g()->getFils_d()->getHauteur())
                {
                    rotationDroite(desequilibre);
                }
                else
                {
                    rotationDoubleDroite(desequilibre);
                }
            }
            else
            {
                if((*desequilibre)->getFils_d()->getFils_d()->getHauteur() > (*desequilibre)->getFils_d()->getFils_g()->getHauteur())
                {
                    rotationGauche(desequilibre);
                }
                else
                {
                    rotationDoubleGauche(desequilibre);
                }
            }
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

void AVL::affichePostfixHauteur()
{
    printf("-----------------------\n");
    this->racine->affichePostfixHauteurRec();
    printf("-----------------------\n");
}

void AVL::afficheInfixHauteur()
{
    printf("-----------------------\n");
    this->racine->afficheInfixHauteurRec();
    printf("-----------------------\n");
}

void AVL::rotationGauche(noeud** &pN)
{
    noeud* buffer = (*pN)->getFils_d();
    (*pN)->changeFils_d(buffer->getFils_g());
    buffer->changeFils_g(*pN);
    *pN = buffer;
    (*pN)->getFils_d()->majHauteur();
    (*pN)->getFils_g()->majHauteur();
    (*pN)->majHauteur();
}

void AVL::rotationDroite(noeud** &pN)
{
    noeud* buffer = (*pN)->getFils_g();
    (*pN)->changeFils_g(buffer->getFils_d());
    buffer->changeFils_d(*pN);
    *pN = buffer;
    (*pN)->getFils_d()->majHauteur();
    (*pN)->getFils_g()->majHauteur();
    (*pN)->majHauteur();
}

void AVL::rotationDoubleGauche(noeud** &pN)
{
    noeud* bufferD = (*pN)->getFils_d();
    noeud* bufferDG = (*pN)->getFils_d()->getFils_g();
    bufferD->changeFils_g(bufferDG->getFils_d());
    bufferDG->changeFils_d(bufferD);
    (*pN)->changeFils_d(bufferDG->getFils_g());
    bufferDG->changeFils_g(*pN);
    *pN = bufferDG;
    (*pN)->getFils_g()->majHauteur();
    (*pN)->getFils_d()->majHauteur();
    (*pN)->majHauteur();
}

void AVL::rotationDoubleDroite(noeud** &pN)
{
    noeud* bufferG = (*pN)->getFils_g();
    noeud* bufferGD = (*pN)->getFils_g()->getFils_d();
    bufferG->changeFils_d(bufferGD->getFils_g());
    bufferGD->changeFils_g(bufferG);
    (*pN)->changeFils_g(bufferGD->getFils_d());
    bufferGD->changeFils_d(*pN);
    *pN = bufferGD;
    (*pN)->getFils_g()->majHauteur();
    (*pN)->getFils_d()->majHauteur();
    (*pN)->majHauteur();
}