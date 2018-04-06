#ifndef NUMERO_H
#define NUMERO_H
#include "Case.h"

class Numero : public Case
{
    public:
        Numero(int n=0);
        virtual ~Numero();

    protected:

    private:
        int num ;
};

#endif // NUMERO_H
