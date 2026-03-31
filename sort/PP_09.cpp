#include <iostream>
using namespace std;
void print(int arr[],int n){
for (int i=0;i<n;i++){
    cout<<arr[i]<< " ";
}

}
void sort(int arr[],int n){
for (int i=1;i<n;i++){
    int t=arr[i];
    int j=i;
    while (j>=1 && arr[j-1]>t){
        arr[j]=arr[j-1];
        j-=1;
    }
    arr[j]=t;
  }
}
void concat(int arr[],int arr1[],int n1,int n2){
    int s=n1+n2;
    int c[s];
  for (int i=0;i<n1;i++){
    c[i]=arr[i];
}
int j=0;
for (int i=n1;i<s;i++){

    c[i]=arr1[j];
        j++;
}
sort(c,s);

print(c,s);
}
int main (){
int n1,n2;
cout<< "Enter number of element A & B";
cin>> n1 >> n2;
int A[n1],B[n2];
cout<<"Enter element of A: ";
for (int i=0;i<n1;i++){
    cin>>A[i];
}
cout<<"Enter element of B: ";
for (int i=0;i<n2;i++){
    cin>>B[i];
}

concat(A,B,n1,n2);

}
