/// 746. 使用最小花费爬楼梯
/// https://leetcode.cn/problems/min-cost-climbing-stairs
/// 

use std::collections::HashMap;

struct Solution;
impl Solution {
    /// f(n) = min( cost[n-1]+f(n-1), cost[n-2]+f(n-2) )
    /// f(0) = 0
    /// f(1) = 0
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let len = cost.len();
        if len <= 1 { return 0; }

        let mut a = 0;
        let mut b = 0;

        for i in 2..=len {
            let t = std::cmp::min(cost[i-2]+a, cost[i-1]+b);
            a = b;
            b = t;
        }
        return b;
    }
}
