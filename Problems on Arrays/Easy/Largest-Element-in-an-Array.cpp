#include <bits/stdc++.h>

using namespace std;

// #### Largest Element in an Array ####
// Solution-1: Sorting (Sort the array in ascending order & get the last element)
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
int findLargestElement1(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    // Return the last element of the sorted array
    return arr[arr.size() - 1];
}

// Solution-2: Iterative approach (Using a max variable)
// Time Complexity: O(n)
// Space Complexity: O(1)
int findLargestElement2(vector<int> &arr, int n)
{
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
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
    cout << "Largest element in the array is: " << findLargestElement1(arr) << endl;
    cout << "Largest element in the array is: " << findLargestElement2(arr, n) << endl;

    return 0;
}