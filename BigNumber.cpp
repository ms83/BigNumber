#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <iterator>
#include "BigNumber.h"

BigNumber::BigNumber()
{
    digits.push_back(0);
}

BigNumber::BigNumber(const string& s)
{
    if (s.size() == 0) {
        digits.push_back(0);
        return;
    }

    for(auto &digit : s) {
        digits.push_back(digit-'0');
    }
}

BigNumber::BigNumber(const BigNumber &bigNumber)
{
    this->digits.assign(bigNumber.digits.begin(), bigNumber.digits.end());
}

BigNumber& BigNumber::operator=(const BigNumber& bigNumber)
{
    if (&bigNumber == this) {
        return *this;
    }
    this->digits.assign(bigNumber.digits.begin(), bigNumber.digits.end());
    return *this;
}

BigNumber BigNumber::operator+(const BigNumber& bigNumber)
{
    BigNumber n;
    n.digits.clear();

    int offset=0;
    int sum;
    const vector<int>& a = this->digits;
    const vector<int>& b = bigNumber.digits;
    int i = a.size()-1;
    int j = b.size()-1;

    while(i>=0 || j>=0) {
        sum = (i>=0 ? a[i] : 0) + (j>=0 ? b[j] : 0) + offset;
        n.digits.push_back(sum%10);
        offset = sum / 10;
        --i;
        --j;
    }

    if (offset) {
        n.digits.push_back(offset);
    }

    reverse(n.digits.begin(), n.digits.end());

    return n;
}

BigNumber BigNumber::operator*(const BigNumber& bigNumber)
{
    BigNumber n;
    // 01234
    n.digits.insert(n.digits.begin()+1, this->digits.begin(), this->digits.end());

    int offset=0;
    int mul=0;
    const vector<int>& a = this->digits;
    const vector<int>& b = bigNumber.digits;
    int i, j;

    BigNumber result;
    for(j=b.size()-1;j>=0;--j) {
        string row;
        for (unsigned int k=0; k<b.size()-1-j;++k) {
            row.append("0");
        }
        offset = 0;
        for(i=a.size()-1;i>=0;--i) {
            mul = b[j]*a[i] + offset;
            row.append(to_string(mul%10));
            offset = mul/10;
        }
        if (offset) {
            row.append(to_string(offset));
        }
        reverse(row.begin(), row.end());
        result = result + BigNumber(row);
    }

    return result;
}


string BigNumber::str()
{
    stringstream ss;
    copy(this->digits.begin(), this->digits.end(), ostream_iterator<int>(ss, ""));
    return ss.str();
}

ostream& operator<<(ostream& stream, const BigNumber& bigNumber) 
{
    for(auto &digit : bigNumber.digits) {
        stream << digit;
    }
    return stream;
}

