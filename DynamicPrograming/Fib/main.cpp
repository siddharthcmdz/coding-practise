#include <iostream>
#include <conio.h>
#include <unordered_map>
using namespace std;

//fib(5) => 1 1 2 3 5 8 13 21

unordered_map<unsigned long, unsigned long> memo;
unsigned long fib(unsigned long n) {
    if(n <= 2) return 1;

    if(memo.find(n) != memo.end()) return memo[n];

    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}



int main(int argc, char** argv) 
{
    
    unsigned long res = fib(5);
    cout<<"res: "    <<res<<endl;

    res = fib(50);
    cout<<"res: "    <<res<<endl;


    getchar();
    return 0;
}