#include <bits/stdc++.h>

using namespace std;

// #### Bubble Sort ####
// Time Complexity: O(n*n) for the worst, average and best cases. Here, n = size of the array.
// Space Complexity: O(1)

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// #### Bubble Sort ####
// Time Complexity: O(n*n) for the worst and average cases and O(n) for the best case. Here, n = size of the array.
// Space Complexity: O(1)

void bubbleSortOptimized(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool didSwap = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }

        if (didSwap == false)
        {
            break;
        }
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

    // Bubble Sort
    bubbleSort(arr, n);
    bubbleSortOptimized(arr, n);

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}