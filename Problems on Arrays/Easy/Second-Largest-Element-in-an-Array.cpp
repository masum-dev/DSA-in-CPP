#include <bits/stdc++.h>

using namespace std;

// #### Second Largest Element in an Array ####
// Solution-1: Sorting
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
int secondLargestElement1(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int large = arr[arr.size() - 1];
    int secondLarge = arr[arr.size() - 1];

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] != large)
        {
            secondLarge = arr[i];
            break;
        }
    }
    return secondLarge;
}

// Solution-2: Better Approach
// Time Complexity: O(n), We do two linear traversals in our array
// Space Complexity: O(1)
int secondLargestElement2(vector<int> &arr, int n)
{

    // Find the largest element in the array
    int large = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }

    // Find the second largest element excluding the largest one
    int secondLarge = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secondLarge && arr[i] != large)
        {
            secondLarge = arr[i];
        }
    }
    return secondLarge;
}

// Solution-3: Optimal Approach
// Time Complexity: O(n), Single-pass solution
// Space Complexity: O(1)
int secondLargestElement3(vector<int> &arr, int n)
{

    int large = arr[0];
    int secondLarge = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            secondLarge = large;
            large = arr[i];
        }
        else if (arr[i] > secondLarge && arr[i] != large)
        {
            secondLarge = arr[i];
        }
    }
    return secondLarge;
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

    // Output
    cout << "Second largest element in the array is: " << secondLargestElement1(arr) << endl;
    cout << "Second largest element in the array is: " << secondLargestElement2(arr, n) << endl;
    cout << "Second largest element in the array is: " << secondLargestElement3(arr, n) << endl;
    return 0;
}