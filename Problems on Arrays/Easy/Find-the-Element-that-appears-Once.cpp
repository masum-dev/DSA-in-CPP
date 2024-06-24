#include <bits/stdc++.h>

using namespace std;

// #### Find the Element that appears Once ####

// Solution-1: Brute Force Approach (using Nested Loop)
// Time Complexity: O(n*n)
// Space Complexity: O(1)
int getSingleElement1(vector<int> &arr, int n)
{

    // Loop for selecting elements
    for (int i = 0; i < n; i++)
    {
        // Selected element
        int num = arr[i];

        int counter = 0;

        // Find the occurrence using Linear Search
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
            {
                counter++;
            }
        }

        // If the occurrence is 1 return that element
        if (counter == 1)
        {
            return num;
        }
    }

    // In case no element appears once
    return -1;
}

// Solution-2: Better Approach 1 (using Hashing)
// Time Complexity: O(3n)
// Space Complexity: O(maxElement+1)
// where maxElement is the maximum element of the array.
int getSingleElement2(vector<int> &arr, int n)
{

    // Find the maximum element
    int maxElement = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    // Hash Array of size maxElement + 1
    // And Hash the array
    vector<int> hash(maxElement + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // Find the single element and return that
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            return arr[i];
        }
    }

    // In case no element appears once
    return -1;
}

// Solution-3: Better Approach 2 (using Map for Hashing)
// Time Complexity: O(nlogM) + O(M)
// where M = size of the map i.e. M = (n/2)+1. n = size of the array.
// Space Complexity: O(M)
// where M = size of the map i.e. M = (n/2)+1. n = size of the array.
int getSingleElement3(vector<int> &arr, int n)
{

    // Declare the Map
    // And Hash the array
    map<int, int> track;

    for (int i = 0; i < n; i++)
    {
        track[arr[i]]++;
    }

    // Find the single element and return that
    for (auto it : track)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }

    // In case no element appears once
    return -1;
}

// Solution-4: Optimal Approach (using XOR)
// Time Complexity: O(n)
// Space Complexity: O(1)
int getSingleElement4(vector<int> &arr, int n)
{
    int appearsOnce = 0;

    // XOR all the elements
    for (int i = 0; i < n; i++)
    {
        appearsOnce ^= arr[i];
    }

    return appearsOnce;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    // Input of the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Output
    cout << "Element that appears Once (Brute Force Approach) : " << getSingleElement1(arr, n) << endl;
    cout << "Element that appears Once (Better Approach 1) : " << getSingleElement2(arr, n) << endl;
    cout << "Element that appears Once (Better Approach 2) : " << getSingleElement3(arr, n) << endl;
    cout << "Element that appears Once (Optimal Approach) : " << getSingleElement4(arr, n) << endl;

    return 0;
}