#include <iostream>
using namespace std;

template <class T>
class indColl
{
    public:
        indColl(int sz = 100);
        ~indColl();
        void Store(int, T);
        T& Retrieve(int) const;
        void Copy(const indColl&);
    private: 
        T *collection;
        int size;
};

int main()
{
    cout << "hey" << endl;
    indColl<int> array(10);

}