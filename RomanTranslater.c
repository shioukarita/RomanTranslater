#include <stdio.h>
#include <string.h>

#define size 10

//ローマ数字の変換
int romanToInt(char roman) {
     if (roman == 'I') {
        return 1;
    } else if (roman == 'V') {
        return 5;
    } else if (roman == 'X') {
        return 10;
    } else if (roman == 'L') {
        return 50;
    } else if (roman == 'C') {
        return 100;
    } else if (roman == 'D') {
        return 500;
    } else if (roman == 'M') {
        return 1000;
    } else {
        return 0;
    }
}
//順序を逆にした表記法の検出
int value_cmp(char value, char prev_value){
 if(value == 'V' && prev_value == 'I'){
    return 4;
 }else if(value == 'X' && prev_value == 'I'){
    return 9;
 }else if(value == 'L' && prev_value == 'X'){
    return 40;
 }else if(value == 'C' && prev_value == 'X'){
    return 90;
 }else if(value == 'D' && prev_value == 'C'){
    return 400;
 }else if(value == 'M' && prev_value == 'C'){
    return 900;
 }else{
    return 0;
 }
}
//7種のローマ数字で表せられる文字の規制
int cal_check( int fre, int result ){
    int bre;
    if(fre >1){
        if(result == 5){
            return 0;
        }else if(result == 10){
            return 0;
        }else if(result == 50){
            return 0;
        }else if(result == 100){
            return 0;
        }else if(result == 500){
            return 0;
        }else if(result == 1000){
            return 0;
        }else{
            return 1;
        }

    }
 return 1;
}

//繰り返し文字の制御（カウント）
typedef struct _COUNT{
    char moji[10] ;
    int countmoji ;
}Count;

int main() {

    int sub_result;
    int prev_value = 0;
    int a =10000;
    int n,i;
    int m;
    int value,back_value;
    int bre;
    int pn;
    char input[20];
    char prev_input[1];
    int   result = 0;

     Count count[] ={
        {"I",0},
        {"V",0},
        {"X",0},
        {"L",0},
        {"C",0},
        {"D",0},
        {"M",0}

    };

    printf("こちらはローマ数字を数字に変換するプログラムです\n");
    printf("0を入力するとプログラムが終了します。\n\n");
    
    while (1) {
        printf("ローマ数字を入力してください\n");
        printf("入力:");
        scanf("%s", input,prev_input);
        
        for(int c=0; c<7;c++){
            count[c].countmoji =0;
        }
        
        if (input[0] == '0') {
            printf("プログラムを終了します。\n\n");
            break;
        }    

        for (i = 0; input[i] != '\0'; i++) {
            value = romanToInt(input[i]);
            //文字列の対象比較
            if(i >= 1){
                pn = i;
                prev_value = romanToInt(prev_input[pn]);

                if(prev_value >= value){
                    if(i==1){
                    result = sub_result;
                    }
                    result += value;
                }else{
                    sub_result = value_cmp(input[i],prev_input[pn]);
                    if(result<sub_result && i >=2){
                        bre = 1;
                        break;
                    }
                   
                    result += sub_result;

                    if(value_cmp(input[i], prev_input[pn]) == 0){
                        bre = 1;
                        break;
                    }else{
                        if(i >= 2){
                         back_value = romanToInt(prev_input[pn]);
                         result = result - back_value;
                        }
                    }
                }
            }else{
                 sub_result =  value;
            }
  
            if(value_cmp(i,result) != 0){
             bre =1;
            }
             //文字の制限
            if(cal_check(i, result) == 0){
                bre = 1;
                break;
            }
             //定義されていない文字の検出
            if (value == 0) {
                 bre = 1;
                break;
            }
            //文字のカウント
            for(m=0;m<7;m++){
                if(input[i] == *count[m].moji){
                    count[m].countmoji = count[m].countmoji + 1;
                }

                if(count[m].countmoji == 4){
                 printf("同じ文字が４つ使われています\n");
                 bre = 1;
                 break;
                }

                if(count[1].countmoji == 2){
                    bre = 1;
                }else if(count[3].countmoji == 2 ){
                    bre = 1;
                }else if(count[5].countmoji == 2 ){
                    bre =1;
                }else{
                    bre = 0;
                }
            }          

            if(bre == 1){
                break;
            }

            if (i==0) {
            printf("出力: %d\n\n", sub_result);
            result = 0;
            } 
             
        }
        //while文の抜け出し
        if(bre == 1){
            break;
        }
        //出力
        if (input[i] == '\0' && i != 1) {
            printf("出力: %d\n\n", result);
            result = 0;
            prev_value =0;
        }
        
    }
     if(bre == 1){
            printf("入力されたローマ数字が正しくありません\n");
            }
    
    return 0;


}