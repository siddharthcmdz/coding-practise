#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum > 0) {
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                res.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) {
                    l++;
                }
            }
        }
    }
    return res;        
}


int main() {

    vector<int> ip = {-1,0,1,2,-1,-4};
    vector<vector<int>> op = threeSum(ip);

    for(int i = 0; i < op.size(); i++) {
        for(int j = 0; j < op[i].size(); j++) {
            cout<<op[i][j]<<" ";
        }
        cout<<endl;
    }
    
}