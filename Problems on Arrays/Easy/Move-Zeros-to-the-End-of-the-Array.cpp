#include <bits/stdc++.h>

using namespace std;

// #### Move Zeros to the end of the Array ####
// Solution-1: Brute Force Approach (Using a Temp Array)

// Time Complexity: O(n) + O(x) + O(n-x) ~ O(2n)
// n = total no. of elements
// x = no. of non-zero elements
// n-x = total no. of zeros

// Space Complexity: O(n)
// In the worst case, all elements can be non-zero.
void moveAllZerosToEnd1(vector<int> &arr, int n)
{
    vector<int> temp;

    // Push non-zero elements to the temp vector.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    // Number of non-zero elements
    int nz = temp.size();

    // Copy all non-zeros to main vector
    for (int i = 0; i < nz; i++)
    {
        arr[i] = temp[i];
    }

    // Fill the remaining elements of the main vector with zeros
    for (int i = nz; i < n; i++)
    {
        arr[i] = 0;
    }
}

// Solution-2: Optimal Approach (Using 2 Pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)
void moveAllZerosToEnd2(vector<int> &arr, int n)
{

    int j = -1;
    // Find the first zero (if any)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    // If no-zeros, return
    if (j == -1)
    {
        return;
    }

    // If non-zero found, swap it with the element at index 'j'.
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
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

    moveAllZerosToEnd1(arr, n);
    moveAllZerosToEnd2(arr, n);

    // Output
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}