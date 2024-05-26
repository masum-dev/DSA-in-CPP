#include <bits/stdc++.h>

using namespace std;

// #### Check if Array is Sorted ####
// Solution-1: Brute Force Approach
// Time Complexity: O(n*n)
// Space Complexity: O(1)
bool isArraySorted1(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                return false;
        }
    }
    return true;
}

// Solution-2: Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isArraySorted2(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
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

    bool bruteforce = isArraySorted1(arr, n);
    bool optimal = isArraySorted2(arr, n);

    // Output
    if (bruteforce)
    {
        cout << "The array is sorted." << endl;
    }
    else
    {
        cout << "The array is not sorted." << endl;
    }
    //
    if (optimal)
    {
        cout << "The array is sorted." << endl;
    }
    else
    {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}