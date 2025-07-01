#include<bits/stdc++.h>
using namespace std;

//main trick of this problem was to recognize use of longest palindromic subsequence in minimising insertions.
//longest palindromic subsequence can be solved using longest common subsequence approach and using given string and reversed string.
int longestCommonSubsequence(string text1, string text2) {
        //previous 1-D dp code I used in solving an earlier question of LCS on leetcode. 
        string &shorter = (text1.size() <= text2.size()) ? text1 : text2;
        string &longer = (text1.size() > text2.size()) ? text1 : text2;

        int n = longer.size();
        int m = shorter.size();
        vector<int> dp(m, 0);

        for (int i = 0; i < n; i++) {
            int prev = 0;
            for (int j = 0; j < m; j++) {
                int temp = dp[j];
                if (longer[i] == shorter[j]) {
                    dp[j] = 1 + prev;
                } else if (j >= 1) {
                    dp[j] = max(dp[j - 1], dp[j]);
                }
                prev = temp;
            }
        }
        return dp[m - 1];
    }

    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int max = longestCommonSubsequence(s, t);
        return s.size() - max;
    }