#include <bits/stdc++.h>

using namespace std;

// Partition function for Quick Sort
int partition(vector<int> &arr, int low, int high)
{
    // Select the pivot element (first element in the array)
    int pivot = arr[low];

    // Initialize indices for partitioning
    int i = low;
    int j = high;

    // Partitioning loop
    while (i < j)
    {
        // Move 'i' to the right until an element greater than pivot is found
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        // Move 'j' to the left until an element smaller than or equal to pivot is found
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        // Swap elements if 'i' is still less than 'j'
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // Move pivot to its correct position
    swap(arr[low], arr[j]);

    // Return the index of the pivot element
    return j;
}

// #### Quick Sort ####
// Time Complexity:
// Best & Average case: O(nlogn)
// Worst case: O(n*n)

// Space Complexity:
// Best & Average case: O(logn)
// Worst case: O(n)

void quickSort(vector<int> &arr, int low, int high)
{
    // Check if there are elements to be sorted
    if (low < high)
    {
        // Partition the array and get the partition index
        int partitionIndex = partition(arr, low, high);

        // Recursively sort the left partition
        quickSort(arr, low, partitionIndex - 1);

        // Recursively sort the right partition
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    // Input the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Quick Sort
    quickSort(arr, 0, n - 1);

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}