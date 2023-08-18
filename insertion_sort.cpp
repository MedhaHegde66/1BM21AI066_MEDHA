#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class InsertionSort {
public:
    void sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }
};

int main() {
    InsertionSort insertionSort;

    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    auto start = chrono::high_resolution_clock::now();  // Start the timer

    insertionSort.sort(arr);

    auto end = chrono::high_resolution_clock::now();    // End the timer

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);  // Calculate the duration

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
