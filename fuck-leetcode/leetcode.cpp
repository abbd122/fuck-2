#ifndef TEST_LEETCODE_CPP
#define TEST_LEETCODE_CPP

#include "utils.hpp"
// 王铮 19520591027
class Solution {
public:
    static string run(const string &s, const string &t) {
        if (s.size() < t.size()) {
            return {};
        }
        unordered_map<char, int> maps;
        unordered_map<char, int> mapt;
        for (auto &ch: t) {
            ++mapt[ch];
        }
        int count = (int) t.size();
        string ans{s};
        for (int slow = 0, fast = 0; fast < s.size(); ++fast) {
            ++maps[s[fast]];
            if (maps[s[fast]] <= mapt[s[fast]]) {
                --count;
            }
            while (maps[s[slow]] > mapt[s[slow]]) {
                --maps[s[slow++]];
            }
            if (!count && (fast - slow + 1) < ans.size()) {
                ans = s.substr(slow, fast - slow + 1);
            }
        }
        return ans;
    }
};
int main(int argc, char *argv[]) {
    auto res = Solution::run("ADOBECODEBANC", "ABC");
//    auto res = Solution::run("a", "a");
//    auto res = Solution::run("ABC", "ADOBECODEBDECANC");
    cout << res << endl;
}
#endif //TEST_LEETCODE_CPP