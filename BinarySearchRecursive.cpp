#include<iostream>
using namespace std;

int binary_search(int A[],int start,int end,int key){
    if(start==end){
        if(A[start]==key){
            return start;
        }
        else return -1;
    }
    else{
        int mid=(start+end)/2;
        if(A[mid]==key){
            return mid;
        }
        else if(key<A[mid]){
            return binary_search(A,start,mid-1,key);
        }
        else{
            return binary_search(A,mid+1,end, key);
        }
    }
}

int main(){
    int n,i,key, result;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout<<"Which number you want to find? ";
    cin>>key;
    result=binary_search(arr,0,n-1,key);
    if(result!=-1)
        cout << "Found at position " << result+1 << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
