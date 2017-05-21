#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
  std::string largestNumber(std::vector<int>& nums) {
    auto cmp = [](const std::string& left, const std::string& right) {
      std::string l = left + right;
      std::string r = right + left;
      return l > r;
    };
    
    std::vector<std::string> values;
    for (const int& i: nums)
      values.push_back(std::to_string(i));
    std::sort(values.begin(), values.end(), cmp);
    if (values.front() == "0")
      return "0";
    
    std::stringstream ss;
    for (const std::string& s: values)
      ss << s;
    return ss.str();
  }
};

template<class T>
std::ostream& operator << (std::ostream& output, const std::vector<T>& val) {
  output << "[";
  if (!val.empty()) {
    output << val.front();
    for (int i=1; i<val.size(); ++i) {
      output << "," << val[i];
    }
  }
  output << "]";
  return output;
}

int main()
{
  Solution solution;
  std::vector<int> a = {3, 30, 34, 5, 9};
  std::cout << solution.largestNumber(a) << std::endl;
}
