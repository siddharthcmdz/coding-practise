#include <iostream>
#include <vector>
using namespace std;

/*
https://leetcode.com/problems/defuse-the-bomb/description/

You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

 

Example 1:

Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
Example 2:

Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0. 
Example 3:

Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
 
 */


vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    int negative = k < 0 ? -1 : 1;
    vector<int> result(n, 0);
    for(int i = 0; i < n; i++)
    {
        if(k > 0)
        {
            int startj = (i+1*negative) % n;
            int endj = (i + k*negative) % n;
            int sum = 0;

            for(int j = 0; j < k; j++)
            {
                int currj = (startj + j*negative) % n;
                sum += code[currj];
            }
            result[i] = sum;
        }
        else if(k < 0)
        {
            int startj = i - 1;
            int endj = i - k;
            startj = startj < 0 ? startj + n : startj;
            endj = endj < 0 ? endj + n : endj;
            int sum =0;
            for(int j =0; j < abs(k); j++ )
            {
                int currj = startj - j;
                if(currj < 0) currj += n;
                sum += code[currj];
            }
            result[i] = sum;
        }
        else {
            result[i] = 0;
        }
    }

    return result;
}

bool isEqual(const vector<int>& v1, const vector<int>& v2)
{
    int n = v1.size();
    for(int i = 0; i < n; i++)
    {
        if(v1[i] != v2[i])
            return false;
    }

    return true;
}

void print(const vector<int>& v)
{
    for(const int val : v)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(int argc, char** argv)
{
    // vector<int> code {5, 7, 1, 4};
    // cout<<"input1 : "<<endl;
    // print(code);

    // vector<int> expected {12,10,16,13};
    // int k = 3;

    // vector<int> result = decrypt(code, k);
    // if(isEqual(expected, result)) 
    // {
    //     cout<<"SUCCESS"<<endl;
    // } else {
    //     cout<<"FAILURE"<<endl;
    //     print(result);
    // }

    vector<int> code2 = {2, 4, 9, 3};
    int k2 = -2;
    cout<<"input2 : "<<endl;
    print(code2);

    vector<int> expected2 {12, 5, 6, 13};
    vector<int> result2 = decrypt(code2, k2);
    if(isEqual(expected2, result2)) 
    {
        cout<<"SUCCESS"<<endl;
    } else {
        cout<<"FAILURE"<<endl;
        print(result2);
    }

    return 0;
}
