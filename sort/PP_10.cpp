#include <iostream>

using namespace std;


void Sort(int start[], int finish[], int n) {

    for (int i = 1; i < n; i++) {
        int s = start[i];
        int f = finish[i];
        int Duration = f-s;
        int j = i ;


        while (j >= 1 && (finish[j-1] - start[j-1]) > Duration) {
            start[j] = start[j-1];
            finish[j] = finish[j-1];
            j = j - 1;
        }


        start[j] =s;
        finish[j] = f;
    }


    cout << "Sorted tasks by duration: ";
    for (int i = 0; i < n; i++) {
        cout << "(" << start[i] << ", " << finish[i] << ") ";
    }
    cout << endl;
}

int main() {
    int n;
    cout<<"enter numbers of tasks: ";
    cin>>n;

    int start[n] ;
    cout<< "Enter start elements: ";
    for (int i=0;i<n;i++){
        cin>>start[i];
    }
    int finish[n];
    cout<< "Enter finish elements: ";
   for (int i=0;i<n;i++){
        cin>>finish[i];
    }

    Sort(start, finish, n);

    return 0;
}
