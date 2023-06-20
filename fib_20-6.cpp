#include<iostream>
#include<conio.h>
using namespace std;

class fibnac{

public:
    int fib(int n){
    if(n<=1){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
    }
    };
int main(){
int n,i,fibonacci;
cout<< "Enter the number:" ;
cin>>n;
fibnac f1;
for(i=0;i<=n;i++){
fibonacci= f1.fib(i);
cout<<"\t"<<fibonacci;
}
}
