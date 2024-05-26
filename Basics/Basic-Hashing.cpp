#include <bits/stdc++.h>

using namespace std;

// ######### Counting frequencies of array elements #########
// Solution-1: Using two loops
// Time Complexity: O(n*n)
// Space Complexity: O(n)

void frequencyCount1(int arr[], int n)
{

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        // Skip this element if already processed
        if (visited[i] == true)
        {
            continue;
        }

        // Count frequency
        int counter = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = true;
                counter++;
            }
        }
        cout << arr[i] << " " << counter << endl;
    }
}

// Solution-2: Using Map
// Time Complexity: O(n)
// Space Complexity: O(n)

void frequencyCount2(int arr[], int n)
{

    unordered_map<int, int> mapp;

    for (int i = 0; i < n; i++)
    {
        mapp[arr[i]]++;
    }

    // Traverse through map and print frequencies
    for (auto x : mapp)
    {
        cout << x.first << " - " << x.second << endl;
    }
}

// ######### Find the highest/lowest frequency element #########
// Solution-1: Using Map
// Time Complexity: O(n)
// Space Complexity: O(n)

void hlFrequency(int arr[], int n)
{
    unordered_map<int, int> mapp;

    int maxFre = 0;
    int maxEle = 0;
    int minFre = n;
    int minEle = 0;

    for (int i = 0; i < n; i++)
    {
        mapp[arr[i]]++;
    }

    // Traverse through map to find the elements
    for (auto x : mapp)
    {
        int element = x.first;
        int count = x.second;

        if (count > maxFre)
        {
            maxFre = count;
            maxEle = element;
        }

        if (count < minFre)
        {
            minFre = count;
            minEle = element;
        }
    }

    cout << "The highest frequency element is: " << maxEle << " and it appears " << maxFre << " times." << endl;
    cout << "The lowest frequency element is: " << minEle << " and it appears " << minFre << " times." << endl;
}

int main()
{

    // ######### Number Hashing #########
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Using Array
    // Pre-compute
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    // Query
    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // Fetch:
        cout << hash[number] << endl;
    }

    // Using Map
    // Pre-compute
    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // Query
    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // Fetch:
        cout << hash[number] << endl;
    }

    // Input:
    //     5
    //     1 3 2 1 3
    //     4
    //     1
    //     2
    //     3
    //     12
    // Output:
    //     2
    //     1
    //     2
    //     0

    // ######### Character Hashing #########
    // Using Array
    // Case-1: Only Lowercase Letters
    string s;
    cin >> s;

    int hash[26] = {0};

    // Pre-compute
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'a']++;
    }

    // Query
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // Fetch:
        cout << hash[c - 'a'] << endl;
    }

    // Input:
    //      masum
    //      5
    //      m
    //      a
    //      s
    //      u
    //      z
    // Output:
    //      2
    //      1
    //      1
    //      1
    //      0

    // Case-2: Only Upper Letters
    string s;
    cin >> s;

    int hash[26] = {0};

    // Pre-compute
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'A']++;
    }

    // Query
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // Fetch:
        cout << hash[c - 'A'] << endl;
    }

    // Input:
    //      masum
    //      5
    //      M
    //      A
    //      S
    //      U
    //      Z
    // Output:
    //      2
    //      1
    //      1
    //      1
    //      0

    // Case-3: Both Upper & Lower Letters
    string s;
    cin >> s;

    int hash[256] = {0};

    // Pre-compute
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i]]++;
    }

    // Query
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // Fetch:
        cout << hash[c] << endl;
    }

    // Input:
    //      MASUMzz
    //      6
    //      M
    //      A
    //      S
    //      U
    //      m
    //      z
    // Output:
    //      2
    //      1
    //      1
    //      1
    //      0
    //      2

    // Using Map
    // Case-4: Both Upper & Lower Letters
    // Pre-compute
    map<char, int> hash;
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i]]++;
    }

    // Query
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // Fetch:
        cout << hash[c] << endl;
    }

    // Input:
    //      MASUMzz
    //      6
    //      M
    //      A
    //      S
    //      U
    //      m
    //      z
    // Output:
    //      2
    //      1
    //      1
    //      1
    //      0
    //      2

    // Counting frequencies of array elements
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    frequencyCount1(arr, n);
    frequencyCount2(arr, n);

    // Find the highest/lowest frequency element
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    hlFrequency(arr, n);

    return 0;
}