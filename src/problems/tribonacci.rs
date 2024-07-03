/// 1137. 第 N 个泰波那契数
/// https://leetcode.cn/problems/n-th-tribonacci-number
/// 

struct Solution;
impl Solution {
    /// f(n) = f(n-1) + f(n-2) + f(n-3)
    /// f(0) = 0
    /// f(1) = 1
    /// f(2) = 1
    pub fn tribonacci(n: i32) -> i32 {
        if n < 2 { return n; }
        if n == 2 { return 1; }

        let mut a = 0;
        let mut b = 1;
        let mut c = 1;
        for _ in 3..=n {
            let t = a + b + c;
            a = b;
            b = c;
            c = t;
        }
        return c;
    }
}
