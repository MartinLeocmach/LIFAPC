#ifndef _PRODUCT
#define _PRODUCT


typedef double value;
typedef unsigned int key;
class product
{
    private :
    key k;
    value v;
    bool deleted;

    public :
    //Constructeur
    product(key key, value value);
    //Destructeur
    ~product();
    //Accesser
    key getKey();
    value getValue();
    bool isDeleted();
    //Modification
    //passe this->deleted à true
    void doDelete();
    //modifie this->v avec la valeur value
    void changeValue(value value); 

    
};

#endif