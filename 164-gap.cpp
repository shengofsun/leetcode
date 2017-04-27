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


template<class T>
void printVec(const vector<T>& vec) 
{
    for (int i=0; i<vec.size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }
}

class Solution
{
public:
    void bucketSort(std::vector<int>& current, std::vector<int>& next, int shift) {
        std::vector<int> count(300, 0);

        for (unsigned int i=0; i<current.size(); ++i) {
            int n = ((current[i] >> shift) & 0xff);
            count[n+1]++;
        }
        for (unsigned int i=1; i<256; ++i) {
            count[i] += count[i-1];
        }
        for (unsigned int i=0; i<current.size(); ++i) {
            int n = ((current[i] >> shift) & 0xff);
            next[ count[n]++ ] = current[i];
        }
    }

    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        std::vector<int> back(nums.size());

        std::vector<int>* current = &nums;
        std::vector<int>* next = &back;

        for (int i=0; i<4; ++i) {
            bucketSort(*current, *next, i*8);
            std::swap(current, next);
        }

        int maxGap = 0;
        for (int i=0; i<current->size() - 1; ++i) {
            int g = (*current)[i+1] - (*current)[i];
            if (g > maxGap)
                maxGap = g;
        }

        return maxGap;
    }
};

int main()
{
    Solution solution;
    std::vector<int> a{1000000, 1, 15, 324, 34, 55, 22, 11, 99};
    std::cout << solution.maximumGap( a ) << std::endl;
    
}
