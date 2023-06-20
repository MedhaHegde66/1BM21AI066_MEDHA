#include<iostream>
using namespace std;

class ls{
    public:
void linear_search(int arr[20],int key,int n){
int i;
for(i=0;i<n;i++)
{
    if(arr[i]==key){break;}

}
if(i<n){
    cout<< "element found by linear search at position %d"<<i+1;
}
else{
    cout<< "Element not found";
}
}
};

    int main(){
    int a[20],key,n,i;
    cout<<"How many elements?";
    cin>>n;
    cout<<"enter the elements of the array";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter the key to be searched:";
    cin>>key;
    ls l1;
    l1.linear_search(a,key,n);


    }

