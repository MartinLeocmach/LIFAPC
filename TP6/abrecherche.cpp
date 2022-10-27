#include <cstdio> 
#include "abrecherche.h"
#include "math.h"

abr::abr()
{
    val = 0;
    fils_d = nullptr;
    fils_g = nullptr;
}

abr::abr(Elem e)
{
    val = e;
    fils_d = nullptr;
    fils_g = nullptr;
}

abr::abr(abr *a)
{
    val = a->val;
    if(a->fils_g !=nullptr)
    {
        fils_g = new abr (a->fils_g);
    }
    else
    {
        fils_g = nullptr;
    }

    if(a->fils_d != nullptr)
    {
        fils_d = new abr (a->fils_d);
    }
    else
    {
        fils_d = nullptr;
    }
}

abr::~abr()
{
    delete fils_d;
    delete fils_g;
}


void abr::operator=(abr *a)
{
    val= a->val;
    delete fils_g;
    delete fils_d;
    if (a->fils_g !=nullptr)
    {
        fils_g = new abr (a->fils_g);
    }
    if (a->fils_d !=nullptr)
    {
        fils_d = new abr (a->fils_d);
    }
}

void abr::insertion(Elem e)
{
    if (e < val)
    {
        if (fils_g==nullptr)
        {
            fils_g = new abr(e);
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
            fils_d = new abr(e);
        }
        else
        {
            fils_d->insertion(e);
        }
    }
}

bool abr::recherche(Elem e)
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

void abr::affichePrefixRec()
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

void abr::affichePrefix()
{
    this->affichePrefixRec();
    printf ("\n");
}

void abr::affichePostfixRec()
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

void abr::affichePostfix()
{
    this->affichePostfixRec();
    printf("\n");
}

void abr::afficheInfixRec()
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

void abr::afficheInfix()
{
    this->afficheInfixRec();
    printf ("\n");
}

void abr::afficheEtatRec(int indentation)
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

void abr::afficheEtat()
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