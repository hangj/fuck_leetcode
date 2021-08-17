// 12. 整数转罗马数字
// https://leetcode-cn.com/problems/integer-to-roman/


static char ret[20] = {0};

char * intToRoman(int num){
    // char* ret = malloc(sizeof(char) * 16); // 不知为啥会报错。。
    memset(ret, 0, sizeof(ret));
    char* p = ret;

    int thousand = num / 1000;
    for(int i=0;i< thousand; i++) *p++='M';

    num %= 1000;
    int hundred = num / 100;
    if(hundred == 9){
        *p++ = 'C';
        *p++ = 'M';
    }else if(hundred == 4){
        *p++ = 'C';
        *p++ = 'D';
    }else if(hundred >= 5){
        *p++ = 'D';
        hundred -= 5;
        for(int i=0;i< hundred; i++) *p++='C';
    }else{
        for(int i=0;i< hundred; i++) *p++='C';
    }


    num %= 100;
    int ten = num / 10;
    if(ten == 9){
        *p++ = 'X';
        *p++ = 'C';
    }else if(ten == 4){
        *p++ = 'X';
        *p++ = 'L';
    }else if(ten >= 5){
        *p++ = 'L';
        ten -= 5;
        for(int i=0;i< ten; i++) *p++='X';
    }else{
        for(int i=0;i< ten; i++) *p++='X';
    }
    num %= 10;

    if(num == 9){
        *p++ = 'I';
        *p++ = 'X';
    }else if(num == 4){
        *p++ = 'I';
        *p++ = 'V';
    }else if(num >= 5){
        *p++ = 'V';
        num -= 5;
        for(int i=0;i< num; i++) *p++='I';
    }else{
        for(int i=0;i< num; i++) *p++='I';
    }

    return ret;
}
