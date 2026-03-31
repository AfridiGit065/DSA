#include <iostream>
using namespace std;

int binarySearchFirst(int arr[], int start, int end, int target) {
    int result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;
             end= mid-1;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}


int binarySearchLast(int arr[], int start, int end, int target) {
    int result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;
            start = mid + 1;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, target;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Enter the target element: ";
    cin >> target;

    int first = binarySearchFirst(arr, 0, n - 1, target);
    int last = binarySearchLast(arr, 0, n - 1, target);

    if (first == -1) {
        cout << "The target element is not found in the array." << endl;
    } else {
        cout << "First Occurrence: " << first << ", Last Occurrence: " << last << endl;
    }

    return main();
}

