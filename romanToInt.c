// 13. 罗马数字转整数
// https://leetcode-cn.com/problems/roman-to-integer/



int romanToInt(char * s){
    int map['Z'] = {0};
    map['I']=1; map['V']=5;
    map['X']=10; map['L']=50;
    map['C']=100; map['D']=500;
    map['M']=1000;

    int num = 0;
    while(*s){
        if(*(s+1) && map[*(s+1)] > map[*s]){
            num += map[*(s+1)] - map[*s];
            s += 2;
            continue;
        }
        num += map[*s++];
    }
    return num;
}
