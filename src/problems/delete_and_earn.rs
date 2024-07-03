use std::collections::HashMap;

/// 740. 删除并获得点数
/// https://leetcode.cn/problems/delete-and-earn

#[derive(Copy, Clone)]
struct Dp {
    num: i32,
    points: i32,
}

impl Dp {
    pub fn new(num: i32, points: i32) -> Self {
        Self {num, points}
    }
    pub fn calc(&self, n: i32, prev: i32) -> i32 {
        if n - 1 == self.num || n + 1 == self.num {
            return self.points;
        }
        return prev;
    }
}

struct Solution;

impl Solution {
    /// f(n) = max( nums[n]+dp(n-1, nums[n]), f(n-1) )
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();

        let mut vec = Vec::with_capacity(nums.len());
        for x in nums.into_iter() {
            if let Some((lst, sum)) = vec.last_mut() {
                if *lst == x {
                    *sum += x;
                } else {
                    vec.push((x, x));
                }
            } else {
                vec.push((x, x));
            }
        }

        let nums = vec;
        let len = nums.len();

        if len == 0 { return 0; }
        if len == 1 {
            return nums[0].1;
        }

        let (num, mut prev) = nums[0];
        let mut dp = Dp::new(num, 0);

        for i in 1..len  {
            let (x, val) = nums[i];

            // 先取出 nums[i] 再取 nums[0..i], 或先取 nums[0..i] 再取 x
            let take_x_later = if dp.num + 1 != x {prev + val} else {prev};
            let take_x_first = val + dp.calc(x, prev);
            let t = std::cmp::max(take_x_first, take_x_later);
            dp.num = x;
            dp.points = prev;

            prev = t;
        }
        return prev;
    }
}



#[test]
fn test() {
    let x = Solution::delete_and_earn(vec![3,4,2]);
    println!("{x}");
    assert_eq!(x, 6);

    let x = Solution::delete_and_earn(vec![2,2,3,3,3,4]);
    println!("{x}");
    assert_eq!(x, 9);
}
