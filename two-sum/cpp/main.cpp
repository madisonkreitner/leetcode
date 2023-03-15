#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// cannot assume sorted array

// brute force is n^2, try each combination of numbers until you find the solution

// fast solution (nlogn)
// 1. sort ascending
// 2. use l and r pointers to find values,
// 3. search original array for values, to get correct indices

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int l = 0, r = sorted.size() - 1, val1, val2;
        while (l < r) {
            int sum = sorted[l] + sorted[r];
            if (sum > target) {
                r--;
            } else if (sum < target) {
                l++;
            } else {
                val1 = sorted[l];
                val2 = sorted[r];
                break;
            }
        }

        // find the original indices
        int ind1, ind2;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val1) {
                ind1 = i;
            } else if (nums[i] == val2) {
                ind2 = i;
            }
        }
        return {ind1, ind2};
    }
};


int main(void) {
    Solution s;

    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ret = s.twoSum(nums, target);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;

    nums = {3,2,4};
    target = 6;
    ret = s.twoSum(nums, target);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;

    nums = {3,3};
    target = 6;
    ret = s.twoSum(nums, target);    
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;

    return 0;
}