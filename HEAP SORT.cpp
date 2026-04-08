#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, int &comparisons) {
    int largest = i;        
    int left = 2 * i + 1;   
    int right = 2 * i + 2;  

    if (left < n) {
        comparisons++;
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }

    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(int arr[], int n, int &comparisons) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0, comparisons);
    }
}

int main() {
    int n;
    int comparisons = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];  

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n, comparisons);

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nNumber of comparisons: " << comparisons << endl;

    delete[] arr; 
    return 0;
}