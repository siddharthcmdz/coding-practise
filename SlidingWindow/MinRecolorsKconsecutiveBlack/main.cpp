#include <iostream>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/

You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

 

Example 1:

Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
Example 2:

Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.
*/

int countWhites(string substr)
{
    int count = 0;
    for(int i = 0; i < substr.size(); i++) {
        if(substr[i] == 'W') count++;
    }

    return count;
}

int minimumRecolors(string blocks, int k) 
{
    int n = blocks.size();
    int minCount = INT_MAX;
    for(int i = 0; i < n - k + 1; i++)
    {
        string substr = blocks.substr(i, k);
        int m = substr.size();
        int numWhites = countWhites(substr);
        if(numWhites) {
            minCount = min(numWhites, minCount);
        }
        else {
            return 0;
        }
    }

    return minCount;
}

int main(int argc, char** argv)
{
    string input1 = "WBBWWBBWBW";
    int k1 = 7;
    int expected1 = 3;
    int result1 = minimumRecolors(input1, k1);
    cout<<"Input1: "<<input1<<endl;
    cout<<"k1: "<<k1<<endl;
    cout<<"expected1: "<<expected1<<endl;
    cout<<"result1: "<<result1<<endl;


    string input2 = "WBWBBBW";
    int k2 = 2;
    int expected2 = 0;
    int result2 = minimumRecolors(input2, k2);
    cout<<"Input1: "<<input2<<endl;
    cout<<"k1: "<<k2<<endl;
    cout<<"expected2: "<<expected2<<endl;
    cout<<"result2: "<<result2<<endl;

    return 0;
}