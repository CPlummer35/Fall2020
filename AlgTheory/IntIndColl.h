#ifndef INTINDCOLL_H_
#define INTINDCOLL_H_

class IntIndColl
{
    public:
        IntIndColl(int sz = 100);
        ~IntIndColl();
        void store(int, int);
        int Retrieve(int) const;
        void Copy(const IntIndColl&);
    private:
        int *collection;
        int size;
};
#endif