#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
*/

int clamp(int min, int max, int val)
{
    if(val < min)
        return min;

    if(val > max)
        return max;

    return val;
}

int countGoodSubstrings(string s) {
    int k = 3; int n = s.size();
    unordered_set<char> charset;
    int counts = 0;
    for(int i = 0; i < n-k; i++)
    {
        int start = i;//clamp(0, n-1, i - k*0.5);
        int end = i+k-1;//clamp(i-k*0.5, n-1, i + k*0.5);

        for(int j = start; j <= end; j++)
        {
            charset.insert(s[j]);
            if(j == end)
            {
                if(charset.size() == k)
                {
                    //duplicates exists.
                    counts++;
                }
                charset.clear();
            }
        }
    }

    return counts;
}

int main(int argc, char** argv)
{
    string s1 = "xyzzaz";
    int output1 = 1;
    int result1 = countGoodSubstrings(s1);
    cout<<"input: "<<s1<<endl;
    cout<<"result1: "<<result1<<endl;
    cout<<"expected: "<<output1<<endl;


    // string s1 = "aababcabc";
    //int output = 4;

    return 0;
}