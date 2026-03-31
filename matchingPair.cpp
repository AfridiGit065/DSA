#include<iostream>
using namespace std;
bool LinearSearch(int arr[],int n,int x){
    for(int i=0;i<n;i++){
    if(arr[i]==x){
            return true;

    }
    }
    return false;
}
void SearchPair(int arr[],int n,int x,int y ){

    if(LinearSearch(arr,n,x) && LinearSearch(arr, n, y)){
           cout<<"PAIR MATCHED ";

    }
     else if(LinearSearch(arr,n,x) || LinearSearch(arr, n, y)){
            if(LinearSearch(arr,n,x)){
                cout<<"ONLY ME"<<"("<<x<<")";
            }
         else cout<<"ONLY ME"<<"("<<y<<")";
    }
    else cout<<"BETTER LUCK NEXT TIME";
}

int main(){
int N,X,Y;
cout<<"Enter Array Size : ";
cin>>N;
int arr[N];
cout<<"Enter elements of array : ";
for(int i=0;i<N;i++){
    cin>>arr[i];
}
cout<<"Enter X & Y : ";
cin>> X >> Y;
SearchPair(arr,N,X,Y);
}
