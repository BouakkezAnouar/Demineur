#ifndef BLANC_H
#define BLANC_H
#include<string>
#include "Case.h"


class Blanc: public Case
{
    public:
        Blanc(int c=8,std::string s="X");
        virtual ~Blanc();

    protected:

    private:
};

#endif // BLANC_H
