/*************************************************************************************
Вычислите a^n. Решение оформите в виде рекурсивной функции power(a, n).
***************************************************************************************/

#include <iostream>
using namespace std;
double power(double a, int  n)
{
    if(n == 0) 
        return 1;
    return a*power(a, n-1);
}

int main() {
  double b;
    int m;
    cin >> b >> m;
    
    if (m < 0)
    {
        m = - m; 
        cout << 1 / power(b,m);
    }   
    else if (m == 0) 
        cout << 1;
    else
        cout << power(b,m);
     
  return 0;
}