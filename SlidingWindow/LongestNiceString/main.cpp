#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/longest-nice-substring/description/
A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

 

Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
Example 2:

Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
Example 3:

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.
 

Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.
*/

bool find(string str, char c)
{
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == c + 32 || str[i] == c - 32 )
            return true;
    }

    return false;
}

bool isNice(string str)
{
    for(int i = 0; i < str.size(); i++) {
        if(!find(str, str[i])) {
            return false;
        }
    }

    return true;
}

bool containsNiceSubstr(string str)
{
    bool hasOneNiceSubstr = false, hasOneNotNiceSubstr = false;
    int n = str.size();
    for(int i = 0; i < n; i++)
    {
        if(find(str, str[i])) {
            hasOneNiceSubstr = true;
        }
        else {
            hasOneNotNiceSubstr = true;
        }
    }

    return hasOneNiceSubstr && hasOneNotNiceSubstr;
}

string bruteForce(string s) 
{
    //brute force
    int n = s.size();
    string ans = "";
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            string substr = s.substr(i, j-i+1);
            if(isNice(substr))
                if(ans.size() < substr.size()) ans = substr;
        }
    }

    return ans;
}


string longestNiceSubstring(string s) {
    int left = 0, right = 0, n = s.size();
    string result = "";
    while(right < n)
    {
        string substr = s.substr(left, right - left + 1);
        while(containsNiceSubstr(substr))
        {
            left++;
            substr = s.substr(left, right - left + 1);
        }

        if(isNice(substr) && result.size() < substr.size()) {
            result = substr;
        }

        right++;
    }

    return result;
}

int main() {
    string input1 = "YazaAay";
    string expected1 = "aAa";
    // string result1 = bruteForce(input1);
    string result1 = longestNiceSubstring(input1);
    cout<<"input1: "<<input1<<endl;
    cout<<"expected1: "<<expected1<<endl;
    cout<<"result1: "<<result1<<endl;

    return 0;
}