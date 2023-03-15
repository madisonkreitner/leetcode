#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    // Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    // An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    // loop through the list of strings

    // sort the current one, 
    
    // add it to hash map if not exists, key will be sorted, value will be array with original string

    // if exists, append to array of existing key

    // group into new vector return
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (int i = 0; i < strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            // does not exists
            if (anagrams.find(sorted) == anagrams.end()) {
                anagrams[sorted] = {strs[i]};
            } else {
                anagrams[sorted].push_back(strs[i]);
            }
        }
        vector<vector<string>> ret;
        for (auto it = anagrams.begin(); it != anagrams.end(); it++) {
            ret.push_back(it->second);
        }
        return ret;
    }
};

int main(void) {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution s;
    s.groupAnagrams(strs);

    return 0;
}