#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
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
