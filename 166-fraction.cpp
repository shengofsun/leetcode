#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cmath>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool flag = true;
        if (numerator<0 && denominator>0) {
            flag = false;
        }
        if (numerator>0 && denominator<0) {
            flag = false;
        }
        long long n1 = numerator;
        long long d1 = denominator;
        unsigned long long n = abs(n1);
        unsigned long long d = abs(d1);

        std::stringstream ss;
        if (!flag)
            ss << '-';
        ss << n/d;
        n%=d;
        if (n==0)
            return ss.str();
        ss << ".";

        std::map<unsigned long long, int> remain;
        std::string numbers;

        while ( n!=0 && remain.find(n) == remain.end() ) {
            unsigned long long f = n*10;
            remain[n] = numbers.size();
            numbers.push_back(f/d + '0');
            n = f%d;
        }

        if (n==0) {
            ss << numbers;
            return ss.str();
        }
        else {
            int pos = remain[n];
            ss << numbers.substr(0, pos) << '(' << numbers.substr(pos) << ')';
            return ss.str();
        }
    }
};

template<class T>
void printVec(const vector<T>& vec) 
{
    for (int i=0; i<vec.size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }
}

int main()
{
    Solution solution;
    std::cout << solution.fractionToDecimal(-1, -2147483648) << std::endl;
}
