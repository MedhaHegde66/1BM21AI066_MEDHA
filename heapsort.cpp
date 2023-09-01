#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to heapify a subtree rooted with node i which is an index in arr[]
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one from the heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements (n): ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    clock_t start_time = clock(); // Record the start time

    heapSort(arr);

    clock_t end_time = clock(); // Record the end time

    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken for sorting: " << elapsed_time << " seconds" << endl;

    return 0;
}
