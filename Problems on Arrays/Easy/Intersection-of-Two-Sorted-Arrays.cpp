#include <bits/stdc++.h>

using namespace std;

// #### Intersection of Two Sorted Arrays ####

// Solution-1: Brute Force Approach (Using Set)
// Time Complexity: O(m*n)
// Space Complexity: O(m)
vector<int> intersectionOfSortedArrays1(vector<int> &arr1, int n, vector<int> &arr2, int m)
{

    vector<int> temp;

    // To track visited
    vector<int> visited(m, 0);

    int i = 0;
    int j = 0;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < m; j++)
        {

            // If element matches and has not been matched with any element before
            if (arr1[i] == arr2[j] && visited[j] == 0)
            {
                temp.push_back(arr2[j]);
                visited[j] = 1;
                break;
            }

            // As the array is sorted, element will not be beyond this
            else if (arr2[j] > arr1[i])
            {
                break;
            }
        }
    }

    return temp;
}

// Solution-2: Optimal Approach (Using 2 Pointers)
// Time Complexity: O(m+n)
// Space Complexity: O(min(n, m))
vector<int> intersectionOfSortedArrays2(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0;
    int j = 0;

    vector<int> temp;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
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

    vector<int> intersectArray1 = intersectionOfSortedArrays1(arr1, n, arr2, m);
    vector<int> intersectArray2 = intersectionOfSortedArrays2(arr1, n, arr2, m);

    // Output
    cout << "Intersection of arr1 and arr2 is (using Brute Force Approach) " << endl;
    for (auto it : intersectArray1)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Intersection of arr1 and arr2 is (using Optimal Approach) " << endl;
    for (auto it : intersectArray2)
    {
        cout << it << " ";
    }

    return 0;
}