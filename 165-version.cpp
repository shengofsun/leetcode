#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cstring>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
    void splitVersion(string& source, std::vector<std::string>& result) {
        source.push_back('.');
        int lastToken = 0;
        for (int i=0; i<source.size(); ++i) {
            if (source[i] == '.') {
                result.push_back( source.substr(lastToken, i-lastToken) );
                lastToken = i+1;
            }
        }

        for (int i=0; i<result.size(); ++i) {
            int j;
            for (j=0; j<result[i].size() && result[i][j]=='0'; ++j);
            if (j == result[i].size())
                result[i] = "0";
            else
                result[i] = result[i].substr(j);
        }
        while (!result.empty() && result.back()=="0")
            result.pop_back();
    }

    int compareVersion(string version1, string version2) {
        std::vector<std::string> res1, res2;

        splitVersion(version1, res1);
        splitVersion(version2, res2);

        int len = std::min(res1.size(), res2.size());
        for (int i=0; i<len; ++i) {
            if (res1[i].size() != res2[i].size()) {
                return res1[i].size() < res2[i].size() ? -1 : 1;
            }
            int ans = strcmp(res1[i].c_str(), res2[i].c_str());
            if (ans != 0)
                return ans<0?-1:1;
        }
        if (res1.size() == res2.size())
            return 0;
        return res1.size() < res2.size() ? -1 : 1
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
    std::cout << solution.compareVersion("01", "1");
}
