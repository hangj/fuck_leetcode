/// 198. 打家劫舍
/// https://leetcode.cn/problems/house-robber

struct Solution;

impl Solution {
    /// f(n) = max( nums[n]+f(n-2), f(n-1) )
    /// f(0) = 0
    /// f(1) = nums[0]
    /// f(2) = max(nums[1], f(1))

    pub fn rob(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len == 0 { return 0; }
        if len == 1 { return nums[0]; }
        if len == 2 { return std::cmp::max(nums[1], nums[0]); }

        let mut a = nums[0];
        let mut b = std::cmp::max(nums[1], nums[0]);

        for i in 2..len {
            let t = std::cmp::max( nums[i]+a, b );
            a = b;
            b = t;
        }
        return b;
    }
}
