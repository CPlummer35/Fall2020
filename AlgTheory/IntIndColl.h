#ifndef INTINDCOLL_H_
#define INTINDCOLL_H_

class IntIndColl
{
    public: 
        IntIndColl(int sz = 100);
        ~IntIndColl();
        void store(int, int);
        int retrieve(int) const;
    private:
        int *collection;
        int size;
};

#endif