#include <assert.h>
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

int main()
{
    test_operator_plus();
    test_operator_mul();
    return 0;
}
