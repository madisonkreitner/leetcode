package main

import (
	"fmt"
)

func main() {
	var nums = []int{1, 2, 3, 4, 5}
	ret := containsDuplicate(nums)
	fmt.Println(ret)

	nums = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 1}
	ret = containsDuplicate(nums)
	fmt.Println(ret)

	nums = []int{3, 3}
	ret = containsDuplicate(nums)
	fmt.Println(ret)

	nums = []int{}
	ret = containsDuplicate(nums)
	fmt.Println(ret)
}

func containsDuplicate(nums []int) bool {
	vals := make(map[int]int)
	for _, num := range nums {
		if _, ok := vals[num]; ok {
			return true
		}
		vals[num] = 1
	}
	return false
}
