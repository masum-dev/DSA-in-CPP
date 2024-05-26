#include <bits/stdc++.h>

using namespace std;

// #### Insertion Sort ####
// Time Complexity: O(n*n) for the worst and average cases and O(n) for the best case. Here, n = size of the array.
// Space Complexity: O(1)

void insertionSort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    // Input the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Insertion Sort
    insertionSort(arr, n);

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}