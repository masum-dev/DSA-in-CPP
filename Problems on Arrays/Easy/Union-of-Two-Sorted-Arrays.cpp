#include <bits/stdc++.h>

using namespace std;

// #### Union of Two Sorted Arrays ####

// Solution-1: Brute Force Approach (Using Set)
// Time Complexity: O((m+n)log(m+n))
// Space Complexity: O(m+n)
// {If Space of temp Array is considered}
// Space Complexity: O(1)
// {If Space of temp Array is Not considered}
vector<int> unionOfSortedArrays1(vector<int> &arr1, int n, vector<int> &arr2, int m)
{

    set<int> uniqueElements;

    for (int i = 0; i < n; i++)
    {
        uniqueElements.insert(arr1[i]);
    }

    for (int i = 0; i < m; i++)
    {
        uniqueElements.insert(arr2[i]);
    }

    vector<int> temp;

    for (auto it : uniqueElements)
    {
        temp.push_back(it);
    }

    return temp;
}

// Solution-2: Optimal Approach (Using 2 Pointers)
// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
// {If Space of temp Array is considered}
// Space Complexity: O(1)
// {If Space of temp Array is Not considered}
vector<int> unionOfSortedArrays2(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0;
    int j = 0;

    vector<int> temp;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (temp.size() == 0 || arr1[i] != temp.back()) // Avoid duplicates
            {
                temp.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (temp.size() == 0 || arr2[j] != temp.back()) // Avoid duplicates
            {
                temp.push_back(arr2[j]);
            }
            j++;
        }
    }

    // Handle remaining elements in 'arr1' (if any)
    while (i < n)
    {
        if (arr1[i] != temp.back())
        {
            temp.push_back(arr1[i]);
        }
        i++;
    }

    // Handle remaining elements in 'arr2' (if any)
    while (j < m)
    {
        if (arr2[j] != temp.back())
        {
            temp.push_back(arr2[j]);
        }
        j++;
    }

    return temp;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr1(n);

    // Input of the array-1
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    vector<int> arr2(m);

    // Input of the array-2
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<int> unionArray1 = unionOfSortedArrays1(arr1, n, arr2, m);
    vector<int> unionArray2 = unionOfSortedArrays2(arr1, n, arr2, m);

    // Output
    cout << "Union of arr1 and arr2 is (using Brute Force Approach) " << endl;
    for (auto it : unionArray1)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Union of arr1 and arr2 is (using Optimal Approach) " << endl;
    for (auto it : unionArray2)
    {
        cout << it << " ";
    }

    return 0;
}