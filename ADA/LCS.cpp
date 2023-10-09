#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int** dp = new int*[m + 1];
    for (int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // If the last characters match, add 1 to the result
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // Otherwise, take the maximum of the two possibilities
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int result = dp[m][n];

    for (int i = 0; i <= m; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

    int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    int length = lcs(s1, s2);

    cout << lcs(s1, s2) << endl;    
    cout << "NAME: NANDINI SAIN" << endl;
    cout << "ENROLLMENT NO. : A2305221060" << endl;


    return 0;
}

