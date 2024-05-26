#include <bits/stdc++.h>

using namespace std;

/*
    # Print something N times
    # Print name N times using recursion
    # Print 1 to N using recursion
    # Print N to 1 using recursion
    # Sum of first N numbers
    # Factorial of N numbers
    # Reverse an array
    # Check if a string is palindrome or not
    # Fibonacci Number
*/

// #### Print something N times using recursion (using global variable) ####
// Time Complexity: O(n)
// Space Complexity: O(n)
int counter = 0;
void printNTimes()
{
    // Base case
    if (counter == 5)
        return;

    cout << counter << endl;
    counter++;

    printNTimes();
}

// #### Print name N times using recursion (using passed parameter) ####
// Time Complexity: O(n)
// Space Complexity: O(n)
void printNameNTimes(int i, int n)
{
    // Base case
    if (i > n)
        return;

    cout << "Masum" << endl;

    printNameNTimes(i + 1, n);
}

// #### Print 1 to N using recursion ####
// Time Complexity: O(n)
// Space Complexity: O(n)
void print1ToN(int i, int n)
{
    // Base case
    if (i > n)
        return;

    cout << i << endl;

    print1ToN(i + 1, n);
}

// #### Print N to 1 using recursion ####
// Time Complexity: O(n)
// Space Complexity: O(n)
void printNTo1(int n, int i)
{
    // Base case
    if (n < i)
        return;

    cout << n << endl;

    printNTo1(n - 1, i);
}

// #### Sum of first N numbers ####
// Solution-1: Parameterized Way
// Time Complexity: O(n)
// Space Complexity: O(n)
void sumOfN1(int n, int sum)
{
    // Base case
    if (n < 1)
    {
        cout << "Sum is: " << sum << endl;
        return;
    }

    sumOfN1(n - 1, sum + n);
}

// Solution-2: Functional Way
// Time Complexity: O(n)
// Space Complexity: O(n)
int sumOfN2(int n)
{
    // Base case
    if (n == 0)
        return 0;

    return n + sumOfN2(n - 1);
}

// #### Factorial of N numbers ####
// Time Complexity: O(n)
// Space Complexity: O(n)
int factorialOfN(int n)
{
    // Base case
    if (n == 0)
    {
        return 1;
    }

    return n * factorialOfN(n - 1);
}

// #### Reverse an array ####
// Solution-1: Using an extra array
// Time Complexity: O(n)
// Space Complexity: O(n)
void printArray(int arr[], int n)
{
    cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray1(int arr[], int n)
{
    int revArr[n];

    for (int i = 0; i < n; i++)
    {
        revArr[i] = arr[n - 1 - i];
    }

    // Printing the array
    printArray(revArr, n);
}

// Solution-2: Space-optimized iterative method
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverseArray2(int arr[], int n)
{

    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }

    // Printing the array
    printArray(arr, n);
}

// Solution-3: Recursive method
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverseArray3(int arr[], int start, int end)
{
    // Base case
    if (start >= end)
    {
        return;
    }

    swap(arr[start], arr[end]);
    reverseArray3(arr, arr[start + 1], arr[end - 1]);
}

// Solution-4: Using library function (New Approach)
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverseArray4(int arr[], int n)
{

    // Reversing elements from index 0 to n-1
    reverse(arr, arr + n);

    // Printing the array
    printArray(arr, n);
}

// #### Check if a string is palindrome or not ####
// Solution-1: Space-optimized iterative method
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isPalindromeString1(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start < end)
    {
        if (tolower(s[start]) != tolower(s[end]))
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}

// Solution-2: Recursive method
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isPalindromeString2(string s, int start, int end)
{
    // Base case
    if (start >= end)
        return true;

    // Recursive case
    if (tolower(s[start]) != tolower(s[end]))
    {
        return false;
    }
    return isPalindromeString2(s, start + 1, end - 1);
}

// #### Fibonacci Number ####
// Time Complexity: O(2^n)
// Space Complexity: O(n)
int fibonacci(int n)
{
    // Base case
    if (n <= 1)
        return n;

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // Print something N times
    printNTimes();

    // Print name N times using recursion
    int n;
    cin >> n;
    printNameNTimes(1, n);

    // Print 1 to N using recursion
    print1ToN(1, 10);

    // Print N to 1 using recursion
    printNTo1(10, 1);

    // Sum of first N numbers
    sumOfN1(10, 0);
    int n;
    cin >> n;
    cout << "Sum of N: " << sumOfN2(n) << endl;

    // Factorial of N numbers
    int n;
    cin >> n;
    cout << "Factorial of N: " << factorialOfN(n) << endl;

    // Reverse an array
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reverseArray1(arr, n);
    reverseArray2(arr, n);
    reverseArray3(arr, 0, n - 1);
    printArray(arr, n);
    reverseArray4(arr, n);

    // Check if a string is palindrome or not
    string s;
    cin >> s;

    if (isPalindromeString1(s))
    {
        cout << s << " is Palindrome string." << endl;
    }
    else
    {
        cout << s << " is NOT Palindrome string." << endl;
    }

    if (isPalindromeString2(s, 0, s.length() - 1))
    {
        cout << s << " is Palindrome string." << endl;
    }
    else
    {
        cout << s << " is NOT Palindrome string." << endl;
    }

    // Fibonacci Number
    int n;
    cin >> n;
    cout << "Fibonacci series till " << n << " : ";
    for (int i = 0; i <= n; i++)
    {
        cout << fibonacci(i) << " ";
    }

    return 0;
}