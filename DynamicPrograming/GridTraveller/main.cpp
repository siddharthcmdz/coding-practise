#include <iostream>

using namespace std;


//in how many ways can one travel from 0, 0 to m-1, n-1
int gridTraveller(int m, int n)
{
    if(m == 1 && n == 1) return 1;

    if(m == 0 || n == 0) return 0;

    return gridTraveller(m-1, n) + gridTraveller(m, n-1);
}

int main(int argc, char** argv) 
{
    int m = 2, n = 3;
    int result = gridTraveller(m, n);

    cout<<"m: "<<m<<", n: "<<n<<", ways: "<<result<<endl;
    return 0;
}