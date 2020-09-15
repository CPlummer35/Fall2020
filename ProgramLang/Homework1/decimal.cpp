#include <iostream>
using namespace std;

int decimal(int n)
{
    int answer;
    while(n > 0)
    {
        n /= 10;
        answer++;
    }

    return answer;
}

int decimalRecur(int n)
{
    if(n == 0) return 0;
    return 1 + decimalRecur(n/10);
}

int main()
{
    int n;
    cin >> n;
    cout << decimal(n) << endl;
    cout << decimalRecur(n) << endl;
}