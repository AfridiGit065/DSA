#include<iostream>
using namespace std;
void sort (int arr[],int n){
    for (int i=0;i<n-1;i++){
        int min=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
int first(int arr[],int n,int key){
int high=n-1,low=0;
int first=-1;int last=-1;
while (low<=high){
    int mid =(high+low)/2;
    if (arr[mid]==key){
        first=mid; high=mid-1;
    }
    else if (arr[mid]<key){
        low=mid +1;
    }
    else high=mid-1;
}

return first;
}
int last(int arr[],int n,int key){
int high=n-1,low=0;
int last=-1;

while (low <= high){
    int mid =(high+low)/2;
    if (arr[mid]==key){
        last=mid; low=mid+1;
    }
    else if (arr[mid]<key){
        low = mid +1;
    }
    else high = mid-1;
}
return last;
}
int main (){
cout<<"Enter number of elements : ";
int n;
cin>>n;
int arr[n];
cout<<"Enter elements : " ;
for (int i=0;i<n;i++){
    cin>> arr[i];
}
sort (arr,n);
int key;
cout<< "Enter key: ";
cin>> key;
int f=first(arr,n,key);
int l=last(arr,n,key);
int count=l-f+1;
cout<< count;
}
