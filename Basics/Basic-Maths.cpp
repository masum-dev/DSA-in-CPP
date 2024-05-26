#include <bits/stdc++.h>

using namespace std;

/*
    # Count Digits
    # Reverse a Number
    # Check Palindrome
    # Armstrong Numbers
    # Print all Divisors
    # Check for Prime
    # GCD Or HCF
*/

// #### Count Digits ####
// Solution-1
// Time Complexity: O (n), where n is the length of the given number
// Space Complexity: O(1)
int countDigits1(int n)
{
    int x = n;
    int counter = 0;

    while (x != 0)
    {
        x /= 10;
        counter++;
    }

    return counter;
}

// Solution-2
// Convert to String and Find the length of the string
// Time Complexity: O (1)
// Space Complexity: O(1)
int countDigits2(int n)
{
    string s = to_string(n);

    return s.length();
}

// Solution-3
// Use logarithm base 10 to count the number of digits
// Time Complexity: O (1)
// Space Complexity: O(1)
int countDigits3(int n)
{
    int x = n;
    return floor(log10(x) + 1);
}

// #### Reverse a Number ####
// Time Complexity: O(n), where n is the length of the given number
// Space Complexity: O(1)
int reverseNumber(int n)
{
    int x = n;
    int reversedNum = 0;
    while (x != 0)
    {
        int lastDigit = x % 10;
        reversedNum = (reversedNum * 10) + lastDigit;
        x /= 10;
    }
    return reversedNum;
}

// #### Check Palindrome ####
// Time Complexity: O(n), where n is the length of the given number
// Space Complexity: O(1)
bool isPalindrome(int n)
{
    int x = n;
    int reversedNum = 0;
    while (x != 0)
    {
        int lastDigit = x % 10;
        reversedNum = (reversedNum * 10) + lastDigit;
        x /= 10;
    }

    if (n == reversedNum)
        return true;

    else
        return false;
}

// #### Armstrong Numbers ####
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isArmstrong(int n)
{
    int copyOfn = n;
    // Counting digits in n
    int temp = n;
    int counter = 0;
    while (temp != 0)
    {
        temp /= 10;
        counter++;
    }
    // Building the sum of powered number
    int sumOfPower = 0;
    while (copyOfn != 0)
    {
        int lastDigit = copyOfn % 10;
        sumOfPower += pow(lastDigit, counter);
        copyOfn /= 10;
    }
    // Comparing
    if (sumOfPower == n)
        return true;

    else
        return false;
}

// #### Print all Divisors ####
// Solution-1
// Time Complexity: O(n)
// Space Complexity: O(1)
void printDivisorsBruteForce(int n)
{
    cout << "All divisors of " << n << " are: ";
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

// Solution-2
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)
void printDivisorsOptimal(int n)
{
    cout << "All divisors of " << n << " are: ";
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
                cout << n / i << " ";
        }
    }
}

// #### Check for Prime ####
// Solution-1
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isPrimeBruteForce(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Solution-2
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)
bool isPrimeOptimal(int n)
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// #### GCD Or HCF ####
// Solution-1
// Time Complexity: O(n)
// Space Complexity: O(1)
int gcdBruteForce(int n1, int n2)
{
    int gcd = 1;
    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

// Solution-2 : Using Euclidean’s theorem (using loop)
// Time Complexity: O(log min(a, b))
// Space Complexity: O(1)
int gcdOptimal1(int n1, int n2)
{
    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 %= n2;
        else
            n2 %= n1;
    }
    if (n1 == 0)
        return n2;
    else
        return n1;
}

// Solution-3 : Using Euclidean’s theorem (using recursion)
// Time Complexity: O(log min(a, b))
// Space Complexity: O(1)
int gcdOptimal2(int n1, int n2)
{
    // Base case
    if (n2 == 0)
    {
        return n1;
    }
    // Recursive case
    return gcdOptimal2(n2, n1 % n2);
}

int main()
{
    int n;
    cin >> n;

    int n1, n2;
    cin >> n1 >> n2;
    // Count Digits
    cout << "The number of digits in " << n << " is " << countDigits1(n) << endl;
    cout << "The number of digits in " << n << " is " << countDigits2(n) << endl;
    cout << "The number of digits in " << n << " is " << countDigits3(n) << endl;

    // Reverse a Number
    cout << "The reverse of " << n << " is " << reverseNumber(n) << endl;

    // Check Palindrome
    if (isPalindrome(n))
    {
        cout << n << " is a Palindrome number" << endl;
    }
    else
    {
        cout << n << " is Not a Palindrome number" << endl;
    }

    // Armstrong Numbers
    if (isArmstrong(n))
    {
        cout << n << " is an Armstrong number" << endl;
    }
    else
    {
        cout << n << " is Not an Armstrong number" << endl;
    }

    // Print all Divisors
    printDivisorsBruteForce(n);
    cout << endl;
    printDivisorsOptimal(n);
    cout << endl;

    // Check for Prime
    if (n != 1 && isPrimeBruteForce(n))
    {
        cout << n << " is a Prime number" << endl;
    }
    else
    {
        cout << n << " is Not a Prime number" << endl;
    }

    if (n != 1 && isPrimeOptimal(n))
    {
        cout << n << " is a Prime number" << endl;
    }
    else
    {
        cout << n << " is Not a Prime number" << endl;
    }

    // GCD Or HCF
    cout << "GCD or HCF of " << n1 << " and " << n2 << " is: " << gcdBruteForce(n1, n2) << endl;
    cout << "GCD or HCF of " << n1 << " and " << n2 << " is: " << gcdOptimal1(n1, n2) << endl;
    cout << "GCD or HCF of " << n1 << " and " << n2 << " is: " << gcdOptimal2(n1, n2) << endl;

    return 0;
}
