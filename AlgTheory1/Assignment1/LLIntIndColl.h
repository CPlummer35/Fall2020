#ifndef LLINTINDCOLL_H_
#define LLINTINDCOLL_H_

class LLIntIndColl
{
    public: 
        LLIntIndColl(long long int sz = 100);
        ~LLIntIndColl();
        void store(long long int, long long int);
        long long int retrieve(long long int) const;
        LLIntIndColl(LLIntIndColl&);
        long long int& operator[](long long int);
    private:
        long long int *collection;
        long long int size;
};

#endif