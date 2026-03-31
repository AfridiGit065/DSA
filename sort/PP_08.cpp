#include<iostream>
using namespace std;
class elements {
 public:
int number;
int frequency=0;

};
void print(elements arr[],int n){
    for (int i=0;i<n;i++){
            cout << arr[i].frequency<< " ";
        //cout<< arr[i].number <<" ";
    }

}
void sort (elements arr[],int n){
    for (int i=1;i<n;i++){
        elements t=arr[i];

        int j=i;

        while (j>=1 && (arr[j-1].frequency < t.frequency ||
                        (arr[j-1].frequency == t.frequency && arr[j-1].number > t.number)) ){

                    arr[j]=arr[j-1];
                    j--;
                }
        arr[j]=t;
    }

print(arr,n);
}
int main (){
cout<< "Enter number of elements : ";
int n;
cin >> n;
elements arr[n];
cout << "Enter Array elements : ";
for (int i=0;i<n;i++){
    cin>>arr[i].number;
}
for (int i=0;i<n;i++){

    for (int j=0;j<n;j++){
        if (arr[i].number==arr[j].number ){
            arr[i].frequency++;

        }

    }

}
sort (arr,n);
}
