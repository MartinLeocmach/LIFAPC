#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "noeud.h"
#include "math.h"

noeud::noeud()
{
    val = 0;
    hauteur = 1;
    fils_d = nullptr;
    fils_g = nullptr;
}

noeud::noeud(Elem e)
{
    val = e;
    hauteur = 1;
    fils_d = nullptr;
    fils_g = nullptr;
}

noeud::noeud(noeud *a)
{
    val = a->val;
    hauteur = a->hauteur;
    if(a->fils_g !=nullptr)
    {
        fils_g = new noeud (a->fils_g);
    }
    else
    {
        fils_g = nullptr;
    }

    if(a->fils_d != nullptr)
    {
        fils_d = new noeud (a->fils_d);
    }
    else
    {
        fils_d = nullptr;
    }
}

noeud::~noeud()
{
    delete fils_d;
    delete fils_g;
}

Elem noeud::getValue()
{
    return val;
}

noeud * noeud::getFils_g()
{
    return fils_g;
}

noeud * noeud::getFils_d()
{
    return fils_d;
}

int noeud::getHauteur()
{
    if (this)
    {
        return hauteur;
    }
    return 0;
}

//Modificateurs des fils
void noeud::changeFils_g(noeud* n)
{
    fils_g = n;
}

void noeud::changeFils_d(noeud* n)
{
    fils_d = n;
}

void noeud::operator=(noeud *a)
{
    val= a->val;
    hauteur = a->hauteur;
    delete fils_g;
    delete fils_d;
    if (a->fils_g !=nullptr)
    {
        fils_g = new noeud (a->fils_g);
    }
    if (a->fils_d !=nullptr)
    {
        fils_d = new noeud (a->fils_d);
    }
}

bool noeud::checkDesequilibre()
{
    if (abs(fils_g->getHauteur() - fils_d->getHauteur())> 1)
    {
        return true;
    }
    return false;
}

void noeud::majHauteur()
{
    hauteur = std::max(fils_d->getHauteur(), fils_g->getHauteur())+1;
}


noeud** noeud::insertion(Elem e)
{
    noeud ** desequilibre;
    if(e.getValue()==val.getValue())
    {
        e.affichageElement();
        printf(" est déjà dans l'arbre\n");
        return nullptr;
    }
    if (e<val)
    {
        if (fils_g) //si fils_g n'est pas nullptr appel récursif dessus
        {
            desequilibre = fils_g->insertion(e);
            if (desequilibre)
            {
                return desequilibre;
            }
            else
            {
                if (fils_g->checkDesequilibre())
                {
                    return &fils_g;
                }
                else
                {
                    fils_g->majHauteur();
                    return nullptr;
                }
            }
        }
        else 
        {
            fils_g = new noeud(e);
            majHauteur();
            return nullptr;
        }
    }
    else 
    {
        if (fils_d) //si fils_d n'est pas nullptr appel récursif dessus
        {
            desequilibre = fils_d->insertion(e);
            if (desequilibre)
            {
                return desequilibre;
            }
            else
            {
                if (fils_d->checkDesequilibre())
                {
                    return &fils_d;
                }
                else
                {
                    fils_d->majHauteur();
                    return nullptr;
                }
            }
        }
        else 
        {
            fils_d = new noeud(e);
            majHauteur();
            return nullptr;
        }
    }
}

bool noeud::recherche(Elem e)
{
    if (e < val)
    {
        if (fils_g == nullptr)
        {
            return false;
        }
        else
        {
            return fils_g->recherche(e);
        }
    }
    else if (val < e)
    {
        if (fils_d == nullptr)
        {
            return false;
        }
        else
        {
            return fils_d->recherche(e);
        }
    }
    return true;
}

void noeud::affichePrefixRec()
{
    printf("%d ", this->val.getValue());
    if(fils_g)
    {
        fils_g->affichePrefixRec();
    }
    if(fils_d)
    {
        fils_d->affichePrefixRec();
    }
}



void noeud::affichePostfixRec()
{
    if(fils_g !=nullptr)
    {
        fils_g->affichePostfixRec();
    }
    if(fils_d !=nullptr)
    {
        fils_d->affichePostfixRec();
    }
    printf("%d ", this->val.getValue());
}


void noeud::afficheInfixRec()
{
    if(fils_g !=nullptr)
    {
        fils_g->afficheInfixRec();
    }
    printf("%d ", this->val.getValue());
    if(fils_d !=nullptr)
    {
        fils_d->afficheInfixRec();
    }
}

void noeud::afficheInfixHauteurRec()
{
    if(fils_g !=nullptr)
    {
        fils_g->afficheInfixHauteurRec();
    }
    printf("%d hauteur %d\n", this->val.getValue(), this->getHauteur());
    if(fils_d !=nullptr)
    {
        fils_d->afficheInfixHauteurRec();
    }
}

void noeud::affichePostfixHauteurRec()
{
    if(fils_g !=nullptr)
    {
        fils_g->affichePostfixHauteurRec();
    }
    if(fils_d !=nullptr)
    {
        fils_d->affichePostfixHauteurRec();
    }
    printf("%d hauteur %d\n", this->val.getValue(), this->getHauteur());
}


void noeud::afficheEtatRec(int indentation)
{
    int i, stocknumBit;
    int numBit = 64;
    if(fils_g !=nullptr)
    {
        fils_g->afficheEtatRec(indentation*2);
    }
    //printf("౹");
    while (pow(2, numBit-1) > indentation)
    {
        numBit= numBit/2;
    }
    stocknumBit= numBit;
    //printf("numBit = %d", stocknumBit);
    i=indentation;
        if (i%2 == 0)
        {
            for (numBit=stocknumBit; numBit>1; numBit=numBit/2)
            {
                if ((indentation/int(pow(2, numBit-1)))%2==1)
                {
                    printf ("|  ");
                }
                else
                {
                    printf("   ");
                }
            }
        }
        else
        {
            for (numBit=stocknumBit; numBit>1; numBit=numBit/2)
            {
                //printf("numBit = %d", numBit);
                if ((indentation/int(pow(2, numBit-1)))%2==0)
                {
                    printf ("|  ");
                }
                else
                {
                    printf("   ");
                }
            }
        }
    if (indentation%2 == 0)
    {
        printf("╭%d\n", this->val.getValue());
    }
    if (indentation%2 == 1)
    {
        printf("╰%d\n", this->val.getValue());
    }
    if(fils_d !=nullptr)
    {
        fils_d->afficheEtatRec((indentation*2)+1);
    }
}

void noeud::afficheEtat()
{
    if (fils_g != nullptr)
    {
        this->fils_g->afficheEtatRec(2);
    }
    printf("%d\n", this->val.getValue());
    if (fils_d != nullptr)
    {
        this->fils_d->afficheEtatRec(3);
    }
}