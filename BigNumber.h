#ifndef _BIGNUMBER_H_
#define _BIGNUMBER_H_

#include<vector>
#include<string>
#include<ostream>

using namespace std;

class BigNumber {
    public:
        BigNumber();
        BigNumber(const string&);
        BigNumber(const BigNumber &);
        BigNumber& operator=(const BigNumber&);
        BigNumber operator+(const BigNumber&);
        BigNumber operator*(const BigNumber&);
        friend ostream& operator<<(ostream& stream, const BigNumber&);
        string str();
        static void test_operator_plus();
        static void test_operator_mul();
    private:
        vector<int> digits;
};

#endif
