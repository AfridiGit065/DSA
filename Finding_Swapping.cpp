#include <iostream>

using namespace std;
int InsertionSort(int arr[],int n){
    int count=0;
for (int i=1;i<n;i++){
    int t=arr[i];
    int j=i;
    while (j>=1 && arr[j-1] > t){
        arr[j] = arr[j-1];
        j--;
        count++;
    }

    arr[j]=t;
}
return count;

}
int main(){
int n;
cout<< "Enter n : ";
cin >> n;
int arr[n];
cout<< "Enter Array Elements : ";
for (int i=0;i<n;i++){
    cin>>arr[i];
}
cout<<InsertionSort(arr,n);
}
