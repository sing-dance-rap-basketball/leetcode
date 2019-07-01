/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */
func twoSum(nums []int, target int) []int {
	mp := make(map[int]int)
	for index, value := range nums {
		if i, ok := mp[target - value]; ok {
			return []int{i, index}
		} else {
			mp[value] = index
		}
	}
	return []int{}
}

