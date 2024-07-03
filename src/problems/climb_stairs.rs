/// 70. 爬楼梯
/// https://leetcode.cn/problems/climbing-stairs
/// 
struct Solution;

impl Solution {
    /// f(n) = f(n-1) + f(n-2)
    /// f(1) = 1
    /// f(2) = 2
    pub fn climb_stairs(n: i32) -> i32 {
        if n == 1 {
            return 1;
        }
        if n == 2 {
            return 2;
        }

        let mut a = 1;
        let mut b = 2;

        for i in 3..=n {
            let t = a + b;
            a = b;
            b = t;
        }

        return b;
    }
}
