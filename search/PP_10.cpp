
#include<iostream>
using namespace std;
int binary_search(int arr[],int n){


        int high=n-1,low = 0;

    while (low <= high){
            int mid=(high+low)/2;

        if (arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){

            return mid;
        }
        else if (arr[mid-1]<arr[mid]){
            low=mid+1;
        }
        else high=mid-1;
    }


}
int main (){
    cout<< "Enter number of elements :";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter elements ";

    for (int i=0;i<n; i++){
        cin >> arr[i];
    }


    int result=binary_search(arr,n);

     cout<<result<<endl;
    }
