// 7. 整数反转
// https://leetcode-cn.com/problems/reverse-integer/

int reverse(int x){
    int sign = x < 0 ? -1 : 1;

    unsigned int ret = 0;
    while(x){
        int mod = x % 10;
        if(mod < 0) mod = -mod;
        if((0x7fffffff - mod)/10 < ret ) return 0;
        ret = ret * 10 + mod;
        x = x / 10;
        
    }

    return sign*(int)ret;
}