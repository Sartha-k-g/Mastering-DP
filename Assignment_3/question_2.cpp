#include<bits/stdc++.h>
using namespace std;

vector<string> LCS(string a,string b){
    int n =a.size();
    int m =b.size();
    vector<vector<set<string>>> dp(n+1,vector<set<string>>(m+1));
    for(int i=0;i<n+1;i++) dp[i][0].insert("");
    for(int i=0;i<m+1;i++) dp[0][i].insert("");

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1]==b[j-1]){
                for(auto &str:dp[i-1][j-1]){
                    dp[i][j].insert(str+a[i-1]);
                }
            }
            else{
                if(dp[i-1][j].begin()->size()>dp[i][j-1].begin()->size()) dp[i][j]=dp[i-1][j];
                else if(dp[i-1][j].begin()->size()<dp[i][j-1].begin()->size()) dp[i][j]=dp[i][j-1];
                else{
                    dp[i][j] = dp[i-1][j];
                    dp[i][j].insert(dp[i][j-1].begin(), dp[i][j-1].end());
                }
            }
        }
    }
    return vector<string>(dp[n][m].begin(), dp[n][m].end());
}

int main(){
    string a,b;
    cin>>a>>b;
    vector<string> ans = LCS(a,b);
    for(auto &str:ans) cout<<str<<" ";
}