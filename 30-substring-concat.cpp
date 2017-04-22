#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<std::string, int> count;
        for (const string& word: words) {
            count[word]++;
        }

        vector<int> result;
        if (words.size() == 0 || words[0].size() == 0) {
            for (int i=0; i<s.size(); ++i)
                result.push_back(i);
            return result;
        }

        int word_length = words[0].size();
        int total_words_length = word_length * words.size();

        for (unsigned int i=0; i<s.size(); ++i) {
            if (i + total_words_length > s.size())
                break;
            unordered_map<std::string, int> used;
            for (const auto& kv: count) {
                used[kv.first] = kv.second;
            }
            int unused_words = words.size();
            int j = i;
            while (j + word_length <= s.size() && unused_words > 0) {
                std::string substr = s.substr(j, word_length);
                auto iter = used.find(substr);
                if (iter != used.end() && iter->second > 0) {
                    iter->second--;
                    unused_words--;
                    j+=word_length;
                }
                else
                    break;
            }
            if (unused_words == 0) {
                result.push_back(j - total_words_length);
            }
        }

        return result;
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
    std::vector<std::string> v = {"bar", "bar"};
    std::string s = "barbarthebarbarman";
    printVec(solution.findSubstring(s, v));
}
