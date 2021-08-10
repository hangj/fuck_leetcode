// 8. 字符串转换整数 (atoi)
// https://leetcode-cn.com/problems/string-to-integer-atoi/

int myAtoi(char * s){
    for(; *s==' '||*s=='\t'||*s=='\n'||*s=='\r'; s++);
    int sign = 1;
    if(*s == '-'){
        sign = -1;
        s++;
    }else if(*s=='+') s++;

    int ret = 0;
    int min = 0x80000000; // −2^31;
    int max = 0x7fffffff; // 2^31 - 1;
    for(; *s >='0' && *s <= '9';s++){
        int d = *s - '0';
        if(ret > 214748364 || (ret == 214748364 && *s > '7')){
            ret = max;
            break;
        }

        if(ret < -214748364 || (ret == -214748364 && *s > '8')){
            ret = min;
            break;
        }
        ret = ret*10 + (sign>0? d: -d);
    }

    return ret;
}
