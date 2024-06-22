#include <bits/stdc++.h>

using namespace std;

// #### Maximum Consecutive Ones ####

// Solution-1: Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
int findMaxConsecutiveOnes(vector<int> &arr, int n)
{
    int maxOnes = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;

            if (count > maxOnes)
            {
                maxOnes = count;
            }
        }
        else
        {
            count = 0;
        }
    }

    return maxOnes;
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
    cout << "Maximum Consecutive 1's is/are: " << findMaxConsecutiveOnes(arr, n) << endl;

    return 0;
}