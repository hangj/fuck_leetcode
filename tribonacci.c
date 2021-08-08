// 1137. 第 N 个泰波那契数
// https://leetcode-cn.com/problems/n-th-tribonacci-number/

int tribonacci(int n){
    if(n==0)return 0;
    if(n<3)return 1;
    
    int a=0,b=1,c=1;
    for(;n>2;n--){
        int t=c;
        c=a+b+c;
        a=b;b=t;
    }
    return c;
}