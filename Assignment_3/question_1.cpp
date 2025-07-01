/*Step 1: Handle base case, when n or m goes to left of string.- if(n<0||m<0) return 0; Correct.

Step 2: Handle 0th row/0th column case: else if((n==0||m==0) &&(s1[n]==s2[m])) return 1; 
Incorrect/Not required as we are only checking case where n==0||m==0 and characters match, we aren't checking characters not matching case. 
We don't need to make separate else if for this, recurrence will handle this case.

Step 3: if(dp[n][m]!=-1) return dp[n][m]; Correct. Return if already calculated.

Step 4: int a = 0,b=0,c=0; 
a = findlcs(s1,s2,n-1,m,dp); 
b = findlcs(s1,s2,n,m-1,dp); 
c = findlcs(s1,s2,n-1,m-1,dp);

There is slight issue in this step. Since we don't need to compute all a b and c for each step. I understand that even if we keep calling 
it wouldnt matter, since dp table filling time is o(m*n) in any case, but calling these uneccesarrily will cause constant time in each step 
to increase. So we remove this.

Step 5:if(s1[n]==s2[m]){ 
	a+=1;b+=1;c+=1; 
        } 
Incorrect case handling. When current characters match, we need to increment 1 to previous substring before adding the two characters. 
Basically, only c is to be incremented, a and b have no use in this case. They shouldnt be incremented.

Step 6: dp[n][m] = max(a,max(b,c));
This is a bug and less clean in general. First of all it should be max(c,max(a,b)). 
Then also to me this line is confusing. Instead of this we can write else case, for when characters dont match, 
and update dp in that case, instead of updating dp at the end."

Corrected Code: */
#include<bits/stdc++.h>
using namespace std;

int findlcs(string& s1, string& s2, int n, int m, vector<vector<int>>& dp) {
    if (n == 0 || m == 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];

    if (s1[n - 1] == s2[m - 1]) {
        dp[n][m] = 1 + findlcs(s1, s2, n - 1, m - 1, dp);
    } else {
        dp[n][m] = max(
            findlcs(s1, s2, n - 1, m, dp), //removing uneccesary a b and c changed time from 97 ms to 43 ms in leetcode submission, since constant overhead reduced.
            findlcs(s1, s2, n, m - 1, dp)
        );
    }
    return dp[n][m];
}


int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return findlcs(s1, s2, n, m, dp);
}