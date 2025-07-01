#include <bits/stdc++.h>
using namespace std;


const int MOD = 998244353;
const int MAX_EXP = 1e5;

int dp[MAX_EXP+1]; 

int mod_pow(int base, int exp) {
    if (exp == 0) return 1;
    if (dp[exp] != 0) return dp[exp];

    int half = mod_pow(base, exp / 2);
    int result = (1LL * half * half) % MOD;
    if (exp % 2) result = (1LL * result * base) % MOD;

    dp[exp] = result;
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 0;
    cin >> test;
    
    for(int i=0;i<test;i++){

        int n=0;
        cin >>n;
        
        vector<int> p(n,0);
        vector<int> q(n,0);
        vector<int> index_p(n,0);   
        vector<int> index_q(n,0);
        
        int current_max_index = 0; 

        // max array for p
        for(int j = 0;j<n;j++){
            int temp =0;
            cin >>temp;
            
            p[j] = temp;
           
            if(temp>p[current_max_index]){
                current_max_index = j;
            }
            index_p[j] = current_max_index;
        }

        current_max_index = 0;
        // max array for q
        for(int j = 0;j<n;j++){
            int temp =0;
            cin >>temp;
            
            q[j] = temp;
           
            if(temp>q[current_max_index]){
                current_max_index = j;
            }

            index_q[j] = current_max_index;
        }
        //now calculating ri's
        vector<int> power(n);
        vector<int> r(n,0);
        for(int j = 0;j<n;j++){
           if(p[index_p[j]]>q[index_q[j]]){
              
             r[j] = (mod_pow(2,(p[index_p[j]])) + mod_pow(2,(q[j-index_p[j]])))%998244353; 
           }

           else if(p[index_p[j]]<q[index_q[j]]){

            r[j] = (mod_pow(2,(p[j-index_q[j]])) + mod_pow(2,(q[index_q[j]])))%998244353;
           }

           else {
            if(q[j-index_p[j]]>= p[j-index_q[j]]){

                r[j] = (mod_pow(2,(p[index_p[j]])) + mod_pow(2,(q[j-index_p[j]])))%998244353;
            }

            else{
                r[j] = (mod_pow(2,(p[j-index_q[j]])) + mod_pow(2,(q[index_q[j]])))%998244353;
            }
            
            
           }
         cout<<r[j]<<' ';
        }

        cout << '\n';
     
    }
}

