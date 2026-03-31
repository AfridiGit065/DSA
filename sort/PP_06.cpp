#include <iostream>
using namespace std;
void print(int arr[],int n){
for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
}

}
void sortingArray(int arr[],int n){

for (int i=2;i<n;i+=2){// even index ascending order

    int t=arr[i];
   int j=i;
    while (j>=2 && arr[j-2]>t){
        arr[j]=arr[j-2];
        j=j-2;
    }
    arr[j]=t;
}
for (int i=3;i<n;i+=2){ // odd index decending order

    int t=arr[i];
    int j=i;
    while (j>=2 && arr[j-2]<t){
        arr[j]=arr[j-2];
        j=j-2;
    }
    arr[j]=t;
}

}

int main (){
int n;
cout<< "Enter numbers of element: ";
cin>> n;
int arr[n];
cout << "Enter your elements : ";
for (int i=0;i<n;i++){
    cin>> arr[i];
}
sortingArray(arr,n);
print(arr,n);
}
