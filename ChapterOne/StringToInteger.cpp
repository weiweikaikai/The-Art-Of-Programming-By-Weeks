/*************************************************************************
	> File Name: StringToInteger.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sun 12 Mar 2017 10:26:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//1.将字符串转换为整数   
//注意以下几点:
//1.对空指针的判断
//2.对正负号的判断
//3.对非数字字符的判断
//4.对超过整形表示范围的的判断逻辑处理
int StrToInt(const char*str){
    const int MAXINT  =(int)(((unsigned int)~0)>>1);
    const int MININT =-((unsigned int)MAXINT-1);
    //cout<<MAXINT<<endl;
    //cout<<MININT<<endl;
    if(str == NULL){
        return 0;
    }
    //处理空格
    while(isspace(*str)){
        str++; 
    }
    int flag=1;
    if(*str == '-' || *str == '+'){
        if(*str == '-'){
            flag=-1;
        }
        str++;
    }

    int ret=0;
    while(*str != '\0'){
        if(*str <'0' || *str >'9'){
        }
        else{
            int c=*str-'0';
            //处理溢出 
            if(flag >0 && ((ret > MAXINT/10)||((ret == MAXINT/10)&&(c > MAXINT%10)))){
                    ret =MAXINT;
                    break;
                    }
            if(flag <0 && ((ret >(unsigned)MININT/10)||((ret == (unsigned)MININT/10)&&(c > (unsigned)MAXINT%10)))){
                    ret =MININT;
                     break;
                    }
           ret=ret*10+c;
           }
           str++;
    }
    return ret < 0 ? ret : ret*flag;
}

void test1(){

 const char *str1="123456";
 const char *str2="+123456";
 const char *str3="-123456";
 const char *str4="12fjha3456";
 const char *str5="     12fjha3456";
 const char *str6="1111111111111111111111111111111111111111111111111111111";
 const char *str7="-111111111111111111111111111111111111111111111111111111";
 cout<<StrToInt(str1)<<endl;
 cout<<StrToInt(str2)<<endl;
 cout<<StrToInt(str3)<<endl;
 cout<<StrToInt(str4)<<endl;
 cout<<StrToInt(str5)<<endl;
 cout<<StrToInt(str6)<<endl;
 cout<<StrToInt(str7)<<endl;
}
//2.扩展 string 转换为double 类型
//
int main()
{
    test1();
    return 0;
}

