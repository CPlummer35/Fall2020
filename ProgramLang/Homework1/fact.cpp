#include <iostream>
using namespace std;

int fact_recur(int n)
{
    if(n <= 1) 
        return 1;

    return n * fact_recur(n - 1);
}

void fact_imper(int n)
{
    int answer = 1;
    for(int i = 1; i <= n; i++) 
    {
        answer *= i;
    }
    cout << "imperative: " << answer << endl;  
}

int main()
{
    int n;
    cin >> n;
    cout << "recursion: " << fact_recur(n) << endl;
    fact_imper(n);
}

