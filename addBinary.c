// 67. 二进制求和
// https://leetcode-cn.com/problems/add-binary/

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define c2i(c) ((c)-'0')
#define i2c(i) ((i)+'0')

char * addBinary(char * a, char * b){
    int la = strlen(a);
    int lb = strlen(b);
    int l_short = la;
    int l_long = lb;
    char* p_short = a;
    char* p_long = b;

    if(la > lb){
        l_short = lb;
        l_long = la;
        p_short = b;
        p_long = a;
    }
    int carry = 0;
    for(int i=0; i < l_short; i++){
        int sum = c2i(p_short[l_short - 1 - i]) + c2i(p_long[l_long - 1 - i]) + carry;
        carry = sum / 2;
        p_long[l_long-1-i] = i2c(sum % 2);
    }

    if(!carry) return p_long;

    if(l_long > l_short){
        for(int i=l_long-l_short-1; i >= 0; i--){
            int sum = c2i(p_long[i]) + carry;
            carry = sum / 2;
            p_long[i] = i2c(sum % 2);
            if(!carry) return p_long;
        }
    }

    char* res = malloc(l_long + 2);
    res[0] = '1';
    memcpy(res+1, p_long, l_long + 1);

    return res;
}