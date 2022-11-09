#ifndef _ELEMENT
#define _ELEMENT

class Elem
{
    private :
    int entier;

    public :
    Elem();
    Elem(int n);

    ~Elem();
    void operator= (int n);
    bool operator<(Elem e);
    int getValue ();
    void affichageElement();
};

#endif