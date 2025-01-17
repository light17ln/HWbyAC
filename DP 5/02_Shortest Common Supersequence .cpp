#include <bits/stdc++.h>
using namespace std;
//lc1092

class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.length();
        int m = b.length();
        int t[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    t[i][j] = t[i - 1][j - 1] + 1;
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        int i = n;
        int j = m;
        string s = "";

        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                s.push_back(a[i - 1]);
                i--;
                j--;
            } 
            else {
                if (t[i][j - 1] > t[i - 1][j]) {
                    s.push_back(b[j - 1]);
                    j--;
                } 
                else {
                    s.push_back(a[i - 1]);
                    i--;
                }
            }
        }

        while (i > 0) {
            s.push_back(a[i - 1]);
            i--;
        }
        while (j > 0) {
            s.push_back(b[j - 1]);
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};