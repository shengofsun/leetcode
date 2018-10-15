#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <limits>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
    int findPeakElement(vector<int>& nums) {
        std::vector<int> cp;
        cp.push_back(std::numeric_limits<int>::min());
        cp.insert(cp.end(), nums.begin(), nums.end());
        cp.push_back(std::numeric_limits<int>::min());
        for (int i=1; i<cp.size()-1; ++i) {
            if (cp[i] >= cp[i-1] && cp[i]>=cp[i+1])
                return i-1;
        }
        return 0;
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
}

10 20   50 60
