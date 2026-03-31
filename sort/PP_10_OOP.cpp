#include <iostream>
using namespace std;

class Task {
public:
    int startTime;
    int finishTime;
    Task(){

    }

    Task(int s, int f) {
        startTime = s;
        finishTime = f;
    }

    int duration() {
        return finishTime - startTime;
    }
};

void sort(Task arr[], int n) {

    for (int i = 1; i < n; i++) {
        int s = arr[i].startTime;
        int f = arr[i].finishTime;
        int temp = arr[i].duration();
        int j = i;


        while (j >= 1 && arr[j-1].duration() > temp) {
            arr[j ].startTime = arr[j-1].startTime;
            arr[j ].finishTime = arr[j-1].finishTime;
            j--;
        }


        arr[j].startTime = s;
        arr[j].finishTime = f;
    }


    cout << "Sorted tasks by duration:\n";
    for (int i = 0; i < n; i++) {
        cout << "(" << arr[i].startTime << ", " << arr[i].finishTime << ") ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;


    Task arr[n];


    for (int i = 0; i < n; i++) {
        int s, f;
        cout << "Enter start and finish time for task " << i + 1 << ": ";
        cin >> s >> f;
        arr[i] = Task(s, f);
    }


    sort(arr, n);



    return 0;
}
