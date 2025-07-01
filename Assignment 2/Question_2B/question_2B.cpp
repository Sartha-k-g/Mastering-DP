#include <bits/stdc++.h>
using namespace std;

int rob(int i, vector<int>& nums, vector<int>& dp) {
    if (i >=nums.size()) {
        return 0;
    }

    if (dp[i] != -1) return dp[i];  

    int pick = nums[i] + rob(i + 2, nums, dp);
    int not_pick = rob(i + 1, nums, dp);
    return dp[i] = max(pick, not_pick);
}

int main(){
    
    vector<int> nums;
    //we take input nums
    int n = 0;
    n = nums.size();
    vector<int> dp1(n, -1);
    vector<int> last_removed(nums.begin(), nums.end() - 1);
    int max1 = rob(0, last_removed, dp1);

    vector<int> dp2(n, -1);
    vector<int> first_removed(nums.begin() + 1, nums.end());
    int max2 = rob(0, first_removed, dp2);

    cout<< max(max1,max2);

}