#include <iostream>
using namespace std;

void Insertion_sort(int arr[],int n){
    for ( int i=1;i<n;i++){
      int t=arr[i];
      int j=i;
      while (j>=1 && arr[j-1]>t)  {
        arr[j]=arr[j-1];
        j--;
      }
      arr[j]=t;
    }
}
int smallestMissingElement(int arr[],int n){
    Insertion_sort(arr,n);
int high=1,current=1;
for (int i=1;i<n;i++){
    if (arr[i-1]==arr[i]-1){
        current++;
    }
    else {
        if(current >high){
            high=current;
        }
        current=1;
    }
}
if(current >high){
            high=current;
        }

        return high;
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
cout<<smallestMissingElement(arr,n);

}

