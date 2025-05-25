#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* In f function, length of max subsequence at each index (by this we mean length of max subsequence which has final value
as value of echo at index) is calculated over recursive calls. If length has been calculated already, its stored
in lengths array so that we dont recalculate it. Final max length is calculated through checking max value in lengths array.*/

int f(int k,vector<int>& lengths, vector<int> echo){
    
    int max = 0;
    if(lengths[k]!=0){
        return lengths[k];
    }

    if(k==0){
        lengths[k] = 1;
        return lengths[k];
    }

    for(int i = k-1; i>=0; i--){

        if(echo[k]>echo[i]){
            if(max<f(i,lengths, echo)){
                max = f(i,lengths,echo);

            }
        }

        else f(i,lengths,echo);
        
    }

    lengths[k] = max+1;
    return lengths[k];
}

int main() {
    
    
    int n;
    cin >> n;
    vector<int> lengths(n, 0);
    vector<int> echo(n);
    int LIS = 0;

    for(int i = 0; i<n; i++){
      cin>> echo[i];
    }
    
    f(n-1, lengths, echo);

    for(int i = 0;i<n;i++){
        if(lengths[i]>LIS){
            LIS = lengths[i];
        }

    }
   
    cout<< LIS;

}