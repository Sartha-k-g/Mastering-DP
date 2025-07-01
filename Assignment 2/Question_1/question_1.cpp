#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n = 0;
    cin >> n;
    
    vector<int> cost(n+2,0);
 
    for(int i = 2; i<=n; i++){
        if (i%2!=0){
           cost[i] = 1 + min(cost[i - 1], cost[(i + 1) / 2] + 1);

        }

        else{
            cost[i] = 1 + cost[i/2];
        }
    }

    cout << cost[n];
}