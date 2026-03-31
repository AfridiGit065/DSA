#include <iostream>
using namespace std;
void sort (int arr[],int n){
for (int i=0;i<n-1;i++){
    int max=i;
    for (int j=i+1;j<n;j++){
        if (arr[j]>arr[max]){
            max=j;
        }
    }
    int temp=arr[i];
    arr[i]=arr[max];
    arr[max]=temp;
}
}
 int binary_search(int arr[],int n,int key){


        int high=n-1,low = 0;

    while (low <= high){
            int mid=(high+low)/2;

        if (arr[mid]==key){

            return mid;
        }
        else if (arr[mid]<key){
            low=mid+1;
        }
        else high=mid-1;
    }

   return -1;
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
     sort(arr,n);
     /*for (int i=0;i<n;i++){
        cout << arr[i]<<" ";
     }*/
    int key;
    cout<< "Enter key : ";
    cin>> key;
    int result=binary_search(arr,n,key);
    if(result<0){
        cout<< "Not Found";
    }
    else cout<<"Found at "<<result<< " index"<<endl;
    }
