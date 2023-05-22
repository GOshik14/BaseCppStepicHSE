/*************************************************************************************
Дано натуральное число n > 1. Проверьте, является ли оно простым.
 Программа должна вывести слово YES, если число простое и NO, если число составное.
Решение оформите в виде функции IsPrime(n), которая возвращает True для простых чисел
 и False для составных чисел. Количество операций в программе должно быть
 пропорционально корню из n.
***************************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int minDivisor(int n)
{
    bool flag = 0;
    double sqrt_n;
    int i;
    sqrt_n = sqrt(n);
    
    for(i = 2; i <= sqrt_n; i++)
    {
        if(!(n % i))
        {
            flag = 1; 
            break;
        }
    }
    
    if(flag)
        return i;
    else 
       return n;
}
int main() {
  int n;
    cin >> n;
    cout << (minDivisor(n) == n ? "YES" : "NO");
  return 0;
}