#include<iostream>
using namespace std;
void print (string arr[],int n){
    cout << "After sorted ";
for (int i=0;i<n;i++){
    cout<< arr[i]<< " ";
}
}
void sort(string arr[],int len[],int n){
for (int i=1;i<n;i++){
    int t=len[i];
    string e =arr[i];
    int j=i;
    while (j>=1 && len[j-1] > t){
        len[j]=len[j-1];
        arr[j] = arr[j-1];
        j--;
    }
    len[j]=t;
    arr[j]=e;
}
print(arr,n);

}
int main (){
cout<< "Enter number of elements ";
int n;
cin >> n;
string arr[n];
int length[n];
cout<< "Enter elements  : ";
for (int i=0;i<n;i++){
    cin>> arr[i];
}
for(int i=0;i<n;i++){
    length[i]=arr[i].length();
    //cout<< length [i]<<" ";
}
 sort (arr,length,n);
}
