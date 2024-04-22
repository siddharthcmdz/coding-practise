#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


/*
https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/

Given a string s, return the maximum length of a 
substring
 such that it contains at most two occurrences of each character.
 

Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:

The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
Example 2:

Input: s = "aaaa"

Output: 2

Explanation:

The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 

Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.
*/

int bruteForce(string s)
{
    int n = s.size();
    int maxlen = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            string substr = s.substr(i, j-i+1);

            unordered_map<char, int> dups;
            bool equals2 = false; bool greater2 = false; int currlen = 0;
            for(int k = 0; k < substr.size(); k++)
            {
                char kchar = substr[k];
                dups[kchar]++;
                if(dups[kchar] == 2) {
                    equals2 = true;
                    currlen = substr.size();
                }
                if(dups[kchar] > 2) {
                    greater2 = true;
                    currlen = 0;
                }
            }
            if(equals2 && !greater2)
                maxlen = max(maxlen, currlen);
        }
    }

    return maxlen; 
}

int maximumLengthSubstring(string s)
{
    int n = s.size();
    int left = 0, right = 0;
    int maxlen = 0;
    unordered_map<char, int> dups;
    while(right < n)
    {
        char rchar = s[right];
        dups[rchar]++;
        cout<<"count of rchar: "<<dups[rchar]<<endl;
        while(dups[rchar] > 2)
        {
            char lchar = s[left];
            dups[lchar]--;
            left++;
        }
        maxlen = max(maxlen, right - left + 1);
        right++;
    }

    return maxlen;
}

int main()
{
    string input1 = "bcbbbcba";
    int expected1 = 4;
    int output1 = maximumLengthSubstring(input1);
    // int output1 = bruteForce(input1);
    cout<<"input1: "<<input1<<endl;
    cout<<"expected1: "<<expected1<<endl;
    cout<<"output1: "<<output1<<endl;

    return 0;
}