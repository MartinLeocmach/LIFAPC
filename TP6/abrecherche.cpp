#include <cstdio> 
#include "abrecherche.h"

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

void abr::affichePrefix()
{
    printf("%d \n", this->val.getValue());
    if(fils_g !=nullptr)
    {
        printf("fils_g :\n");
        fils_g->affichePrefix();
    }
    if(fils_d !=nullptr)
    {
        printf("fils_d :\n");
        fils_d->affichePrefix();
    }
}

