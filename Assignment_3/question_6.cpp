#include<bits/stdc++.h>
using namespace std;

//First I was using 1-d DP array, then I realised I dont need to use o(n) space, since we only need fixed lookback values at any moment.
//If we have stock, that means we either bought it before, or we are buying it now. If we are buying it now, we need to ensure that
//we dont own any stock at i-2, due to cooldown condition. If we have owned stock at i-2, we cannot buy at i. Since to Buy we need to sell first.
int maxProfit(vector<int>& prices) {
        int have=0;
        int not_have=0;
        int have_last=-prices[0];
        int not_have_last=0;
        int not_have_last_2=0;

        for(int i=1;i<prices.size();i++){
            have=max(have_last,not_have_last_2-prices[i]);
            not_have=max(not_have_last,have_last+prices[i]);

            not_have_last_2=not_have_last;
            not_have_last=not_have;
            have_last=have;
        }
        return not_have;
    }