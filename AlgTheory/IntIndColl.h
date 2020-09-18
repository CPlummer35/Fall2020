#ifndef INTINDCOLL_H_
#define INTINDCOLL_H_

class IntIndColl
{
    public: 
        IntIndColl(int sz = 100);
        ~IntIndColl();
        void store(int, int);
        int retrieve(int) const;
        IntIndColl(const IntIndColl&);
        int& operator[](int);
    private:
        int *collection;
        int size;
};

#endif