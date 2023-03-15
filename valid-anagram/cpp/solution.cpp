#include <map>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // create a hashmap to store key and count
        std::map<char, int> smap;
        for (int i = 0; i < s.length(); i++)
        {
            // insert or update the char count
            smap[s[i]]++;
        }


        for (int i = 0; i < t.length(); i++)
        {
            // did not exist, not anagram
            if (smap.find(t[i]) == smap.end())
            {
                return false;
            }
            smap[t[i]]--;
        }

        
        for (auto it = smap.begin(); it != smap.end(); it++) {
            if (it->second != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string s = "anagram", t = "nagaram";
    cout << boolalpha << sol.isAnagram(s, t) << endl;

    s = "rat", t = "car";
    cout << boolalpha << sol.isAnagram(s, t) << endl;

    s = "aacc", t = "ccac";
    cout << boolalpha << sol.isAnagram(s, t) << endl;
}