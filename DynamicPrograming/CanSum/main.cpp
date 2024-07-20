#include <iostream>
#include <conio.h>
#include <unordered_map>
#include <vector>

using namespace std;


bool canSum(int target, const vector<int>& nums) {
    if(target == 0) return true;

    if(target < 0 ) return false;

    for(int num : nums) {
        if(canSum(target-num, nums)) {
            return true;
        }
    }

    return false;
}

int main(int argc, char** argv) {
    bool res = canSum(7, {5, 3, 4, 7});

    string resstr = res ? "true" : "false";
    cout <<"result: "<<resstr<<endl;

    return 0;
}