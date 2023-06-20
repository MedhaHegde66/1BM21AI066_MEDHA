#include<iostream>
#include<conio.h>
using namespace std;

class fac{

public:
    int fact(int n){
    if(n<=1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
    }
    };
int main(){
int n,factorial;
cout<< "Enter the number:" ;
cin>>n;
fac f2;
factorial=f2.fact(n);
cout<<"\t the factorial of \t"<<n<<"\t is \t"<<factorial;
}

