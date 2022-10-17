#include <iostream>
#include <cstdio>
#include "product.h"

//Constructeur
product::product(key key, value value)
{
    k =key;
    v = value;
    is_deleted = false;
}

//Destructeur
product::~product(void)
{
    //is_deleted = true;
}

//Access key
key product::getKey()
{
    return k;
}

//Acces value
value product::getValue()
{
    return v;
}

//Le produit a été delete
//return true si le produit a été retiré false sinon
bool product::isDeleted()
{
    return is_deleted;
}

//Modification
//delete le produit de la table
void product::doDelete()
{
    is_deleted =true;
}

void product::changeValue(value value)
{
    v = value;
}