#include <bits/stdc++.h>

using namespace std;

// #### Find the Missing Number in an Array (between 1 to N) ####

// Solution-1: Brute Force Approach (using Nested Loop & Linear Search)
// Time Complexity: O(n*n)
// Space Complexity: O(1)
int findMissingNumber1(vector<int> &arr, int n)
{
    // Outer loop that runs from 1 to N
    for (int i = 1; i <= n; i++)
    {
        // `flag` variable to check if an element exists
        bool flag = false;

        // Search the element using Linear Search
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = true;
                break;
            }
        }

        // Check if the element is missing
        if (!flag)
        {
            return i;
        }
    }

    // If loop completes without finding a missing number (shouldn't happen)
    // It is just to avoid warnings.
    return -1;
}

// Solution-2: Better Approach (using Hashing)
// Time Complexity: O(n) + O(n) ~ O(2n)
// Space Complexity: O(n)
int findMissingNumber2(vector<int> &arr, int n)
{
    // Hash table to store the presence of numbers
    vector<int> hash(n + 1, 0);

    // Mark the presence of elements in the hash table
    for (int i = 0; i < n - 1; i++)
    {
        hash[arr[i]] = 1;
    }

    // Find the missing number by iterating through the hash table
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }

    // If loop completes without finding a missing number (shouldn't happen)
    // It is just to avoid warnings.
    return -1;
}

// Solution-3: Optimal Approach 1 (Summation Approach)
// Time Complexity: O(n)
// Space Complexity: O(1)
int findMissingNumber3(vector<int> &arr, int n)
{
    // Sum of all numbers from 1 to N
    int sumOfNNums = (n * (n + 1)) / 2;

    int sumOfArr = 0;

    // Calculate the actual sum of elements in the array
    for (int i = 0; i < n - 1; i++)
    {
        sumOfArr += arr[i];
    }

    int missingNum = sumOfNNums - sumOfArr;

    return missingNum;
}

// Solution-4: Optimal Approach 2 (XOR Approach)
// Time Complexity: O(n)
// Space Complexity: O(1)
int findMissingNumber4(vector<int> &arr, int n)
{
    int xor1 = 0;
    int xor2 = 0;

    // XOR up to [1...N]
    // for (int i = 1; i <= n; i++)
    // {
    //     xor1 ^= i;
    // }

    // XOR of array elements
    // for (int i = 0; i < n - 1; i++)
    // {
    //     xor2 ^= arr[i];
    // }

    // Combining the above 2 loops
    for (int i = 0; i < n - 1; i++)
    {
        // XOR of array elements
        xor2 ^= arr[i];

        // XOR up to [1...N-1]
        xor1 ^= (i + 1);
    }

    // XOR up to [1...N]
    xor1 ^= n;

    // The missing number
    return xor1 ^ xor2;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n - 1);

    // Input of the array
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    // Output
    cout << "The missing number is (using Nested Loop & Linear Search): " << findMissingNumber1(arr, n) << endl;
    cout << "The missing number is (using Hashing): " << findMissingNumber2(arr, n) << endl;
    cout << "The missing number is (Summation Approach): " << findMissingNumber3(arr, n) << endl;
    cout << "The missing number is (XOR Approach): " << findMissingNumber4(arr, n) << endl;

    return 0;
}