#include <cstdio> 
#include "noeud.h"
#include "math.h"

noeud::noeud()
{
    val = 0;
    coutured = false;
    fils_d = nullptr;
    fils_g = nullptr;
}

noeud::noeud(Elem e)
{
    val = e;
    coutured = false;
    fils_d = nullptr;
    fils_g = nullptr;
}

noeud::noeud(noeud *a)
{
    val = a->val;
    coutured = false;
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

void noeud::operator=(noeud *a)
{
    val= a->val;
    coutured = a->coutured;
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

void noeud::insertion(Elem e)
{
    if (e < val)
    {
        if (fils_g==nullptr)
        {
            fils_g = new noeud(e);
        }
        else
        {
            fils_g->insertion(e);
        }
    }
    else if (val < e)
    {
        if (fils_d==nullptr)
        {
            fils_d = new noeud(e);
        }
        else
        {
            fils_d->insertion(e);
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
    if(fils_g !=nullptr)
    {
        fils_g->affichePrefixRec();
    }
    if(fils_d !=nullptr)
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
    if(fils_d !=nullptr && !coutured)
    {
        fils_d->afficheInfixRec();
    }
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

void noeud::coudreRec(noeud* dernierGauche)
{
    if (this->fils_g != nullptr)
    {
        fils_g->coudreRec(this);
    }
    if (fils_d !=nullptr)
    {
        fils_d->coudreRec(dernierGauche);
    }
    else
    {
        fils_d = dernierGauche;
        coutured = true;
    }
}
