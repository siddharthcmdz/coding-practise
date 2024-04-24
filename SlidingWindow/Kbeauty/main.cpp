#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/

The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:

It has a length of k.
It is a divisor of num.
Given integers num and k, return the k-beauty of num.

Note:

Leading zeros are allowed.
0 is not a divisor of any value.
A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: num = 240, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "24" from "240": 24 is a divisor of 240.
- "40" from "240": 40 is a divisor of 240.
Therefore, the k-beauty is 2.
Example 2:

Input: num = 430043, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "43" from "430043": 43 is a divisor of 430043.
- "30" from "430043": 30 is not a divisor of 430043.
- "00" from "430043": 0 is not a divisor of 430043.
- "04" from "430043": 4 is not a divisor of 430043.
- "43" from "430043": 43 is a divisor of 430043.
Therefore, the k-beauty is 2.
 */

string removeLeadingZeros(string str) {
    string res = "";
    int i = 0;
    while(str[i] == '0') {
        i++;
    }

    return str.substr(i);
}

int bruteForce(int num, int k) 
{
    string numstr = to_string(num);
    int n = numstr.size();
    unordered_set<int> uniques;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++) {
            string substr = numstr.substr(i, j-i+1);
            // substr = removeLeadingZeros(substr);
            cout<<"substr: "<<substr<<endl;
            int numsubstr = !substr.empty() ? atoi(substr.c_str()) : 0;
            // cout<<"numsubstr: "<<numsubstr<<endl;
            int substrsz = substr.size();
            bool isMuliple = numsubstr != 0 && num % numsubstr == 0;
            if(substrsz == k && isMuliple) {
                // uniques.insert(numsubstr);
                count++;
            }
        }
    }

    // return uniques.size();
    return count;
}

int slidingWindow(int num, int k) 
{
    string numstr = to_string(num);
    int n = numstr.size();
    int count = 0;
    for(int i = 0; i < n-k+1; i++) 
    {
        string substr = numstr.substr(i, k);
        // substr = removeLeadingZeros(substr);
        int substri = atoi(substr.c_str());

        if(substri != 0 && num % substri == 0)
            count++;
    }

    return count;
}



int main() {
    // int input1 = 240;
    int input1 = 430043;
    int k1 = 2;
    int expected1 = 2;
    // int result1 = bruteForce(input1, k1);
    int result1 = slidingWindow(input1, k1);
    cout<<"input1: "<<input1<<endl;
    cout<<"k1: "<<k1<<endl;
    cout<<"expected1: "<<expected1<<endl;
    cout<<"result1: "<<result1;

    return 0;
}