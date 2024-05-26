#include <bits/stdc++.h>

using namespace std;

// #### Remove Duplicates from Sorted Array ####
// Solution-1: Brute Force Approach
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int removeDuplicates1(vector<int> &arr, int n)
{
    set<int> uniqueElements;

    for (int i = 0; i < n; i++)
    {
        uniqueElements.insert(arr[i]);
    }

    int k = uniqueElements.size();

    // Copy unique elements from the set back into the input array
    int i = 0;
    for (auto x : uniqueElements)
    {
        arr[i] = x;
        i++;
    }

    // Return the number of unique elements
    return k;
}

// Solution-2: Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
int removeDuplicates2(vector<int> &arr, int n)
{

    int i = 0; // Pointer to track the position of the next unique element
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    // Return the number of unique elements
    return i + 1;
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

    // Output: Brute Force Approach
    int k1 = removeDuplicates1(arr, n);

    cout << "The array after removing duplicate elements is: ";
    for (int i = 0; i < k1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output: Optimal Approach
    int k2 = removeDuplicates2(arr, n);

    cout << "The array after removing duplicate elements is: ";
    for (int i = 0; i < k2; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}