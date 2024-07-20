#include <iostream>
#include <unordered_map>

using namespace std;

struct MyComparator {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if(hash1 != hash2) {
            return hash1 ^ hash2;
        }

        return hash1;
    }
};

//in how many ways can one travel from 0, 0 to m-1, n-1
unordered_map<pair<int, int>, int, MyComparator> memo;
unsigned long gridTraveller(unsigned long m, unsigned long n)
{
    if(m == 1 && n == 1) return 1;

    if(m == 0 || n == 0) return 0;

    pair<unsigned long, unsigned long> pr = make_pair(m, n);
    if(memo.find(pr) != memo.end()) {
        return memo[pr];
    }
    
    memo[pr] = gridTraveller(m-1, n) + gridTraveller(m, n-1);
    return memo[pr];
}

int main(int argc, char** argv) 
{
    unsigned long m = 100, n = 10;
    unsigned long result = gridTraveller(m, n);

    cout<<"m: "<<m<<", n: "<<n<<", ways: "<<result<<endl;
    return 0;
}