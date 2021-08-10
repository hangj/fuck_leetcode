// 9. 回文数
// https://leetcode-cn.com/problems/palindrome-number/


bool isPalindrome(int x){
    if(x==0)return true;
    if(x < 0 || x%10 == 0) return false;
    int y=0;
    for(int i = x;i; i/=10){
        if(y==i)return true;
        y = 10*y+i%10;
        if(y==i)return true;
        if(y>i)return false;
    }
    return x == y;
}
