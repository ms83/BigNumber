#include <assert.h>
#include <iostream>
#include <cmath>
#include "BigNumber.h"

void test_operator_plus()
{
    for(int i=1; i<1000; ++i) {
        for(int j=1; j<1000; ++j) {
            BigNumber a(to_string(i));
            BigNumber b(to_string(j));
            assert(to_string(i+j) == ((a+b).str()));
        }
    }
}

void test_operator_mul()
{
    for(int i=1; i<100; ++i) {
        for(int j=1; j<100; ++j) {
            BigNumber a(to_string(i));
            BigNumber b(to_string(j));
            assert(to_string(i*j) == ((a*b).str()));
        }
    }
}

vector<int> multiply(vector<int>& a, vector<int>& b)
{
    vector<int> result(a.size() + b.size(), 0);
    for( int i = a.size() - 1; i >= 0; i-- )
    {
        for( int j = b.size() - 1; j >= 0; j-- )
        {
            result[ i + j + 1 ] += ( b[ j ]) * ( a[ i ]); //single array to store intermediate values
        }
    }
    for( int i = a.size() + b.size(); i >= 0; i-- ){
        if( result[ i ] >= 10 ){
            result[ i - 1 ] +=result[ i ] / 10;
            result[ i ] %= 10;
        }
    }
    return result;
}

int main()
{
    string s(to_string(2));
    vector<int> a{1,2,3};
    vector<int> b{3,4,5};
    vector<int> p = multiply(a,b);

    for (auto &x: p) {
        cout << x << " " ;
    }
    cout << endl;
    return 0;
    test_operator_plus();
    test_operator_mul();
    return 0;
}
