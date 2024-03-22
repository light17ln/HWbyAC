#include <bits/stdc++.h>
using namespace std;

// METHOD1
int findNthDivisible(int N, int a, int b, int c)
{
    int count = 0;
    int num = 1;   // 1 se start krenge

    // Loop Nth term tak chlega
    while (count < N)
    {
        if (num % a == 0 || num % b == 0 || num % c == 0)
        {
            count++;
        }
        num++;
    }
    return num - 1;
}

//METHOD2
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int divTermCount(int a, int b, int c, int num) {
    return ((num / a) + (num / b) + (num / c)
            - (num / lcm(a, b))
            - (num / lcm(b, c))
            - (num / lcm(a, c))
            + (num / lcm(a, lcm(b, c))));
}

int findNthTerm(int a, int b, int c, int n) {
    int low = 1, high = INT_MAX, mid;

    while (low < high) {
        mid = low + (high - low) / 2;

        if (divTermCount(a, b, c, mid) < n)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}