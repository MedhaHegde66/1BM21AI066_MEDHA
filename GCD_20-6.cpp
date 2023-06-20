#include <iostream>
using namespace std;
  class gg{
  public:
int gcd(int a, int b)
{

    if (a == 0)
       return b;
    if (b == 0)
       return a;


    if (a == b)
        return a;


    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
};


int main()
{
    int a = 40, b = 60;
    gg g1;
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<g1.gcd(a, b);
    return 0;
}
