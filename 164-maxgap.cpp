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
  int maximumGap(std::vector<int>& nums) {
    if (nums.size() < 2)
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

int lower_bound(const std::vector<int>& vec, int target) {
//  int left = 0, right = vec.size();
//  while (left < right) {
//    int middle = (left + right)/2;
//    if (vec[middle] < target)
//      left = middle + 1;
//    else
//      right = middle;
//  }
//  return left;

  int left = 0, right = vec.size() - 1;
}

int upper_bound(const std::vector<int>& vec, int target) {
  
}

int main()
{
  Solution solution;
}
