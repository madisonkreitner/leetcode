#include <vector>
#include <map>
#include <iostream>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        // create a hashmap to store key and count
        std::map<int, int> vals;
        // loop through list
        for (int i = 0; i < nums.size(); i++)
        {
            // if key exists in the map already
            if (vals.count(nums[i]) == 1)
            {
                return true;
            }

            // add the key to the map
            vals.insert(std::pair<int, int>{nums[i], 1});
        }
        return false;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{3, 4, 2, 8, 15, 267};
    bool ret = s.containsDuplicate(nums);
    std::cout << "nums contains dup: " << ret << std::endl;   

    std::vector<int> dups{3, 4, 2, 8, 3, 15, 267};
    ret = s.containsDuplicate(dups);
    std::cout << "dups contains dup: " << ret << std::endl;
    
    std::vector<int> c3{3, 3};
    ret = s.containsDuplicate(c3);
    std::cout << "c3 contains dup: " << ret << std::endl;   
    
    std::vector<int> c4{3};
    ret = s.containsDuplicate(c4);
    std::cout << "c4 contains dup: " << ret << std::endl;   
    
    std::vector<int> c5{};
    ret = s.containsDuplicate(c5);
    std::cout << "c5 contains dup: " << ret << std::endl;   
}