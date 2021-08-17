// 551. 学生出勤记录 I
// https://leetcode-cn.com/problems/student-attendance-record-i/


bool checkRecord(char * s){
    int cA = 0;
    int cL = 0;
    for(int i=0; s[i]; i++){
        if(s[i] == 'A'){
            cA ++;
            continue;
        }
        if(s[i] == 'L'){
            if(i == 0){
                cL = 1;
                continue;
            }
            if(s[i-1] != 'L'){
                cL = 1;
                continue;
            }else{
                cL ++;
                if(cL >= 3) return false;
                continue;
            }
        }
    }

    return cA < 2;
}
