#include <bits/stdc++.h>

using namespace std;

// #### Left Rotate an Array by D Places ####
// Solution-1: Using a Temp Array
// Time Complexity: O(n)
// Space Complexity: O(k)
// since k array element needs to be stored in temp array
void leftRotate1(int arr[], int n, int k)
{

    // Adjust k to be within the valid range (0 to n-1)
    k = k % n;

    // Handle edge case: empty array
    if (n == 0)
    {
        return;
    }

    int temp[k];

    // Storing k elements in temp array from the left
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    // Shifting the rest of elements to the left
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }

    // Putting k elements back to main array
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
    }
}

// Solution-2: Using Reversal Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

// Function to Reverse Array
void reverseArray(int arr[], int start, int end)
{

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to Rotate k elements to the left
void leftRotate2(int arr[], int n, int k)
{

    // Adjust k to be within the valid range (0 to n-1)
    k = k % n;

    // Handle edge case: empty array
    if (n == 0)
    {
        return;
    }

    // Reverse first k elements
    reverseArray(arr, 0, k - 1);

    // Reverse last n-k elements
    reverseArray(arr, k, n - 1);

    // Reverse whole array
    reverseArray(arr, 0, n - 1);
}

int main()
{

    int n, k;
    cin >> n >> k;

    int arr[n];

    // Input the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    leftRotate1(arr, n, k);
    leftRotate2(arr, n, k);

    // Output
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}