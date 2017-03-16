/*************************************************************************
	> File Name: PalindromeString.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Thu 16 Mar 2017 01:42:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//1.判断一个因为字符串是不是回文串 (如果你想判断一串汉字是不是，你也可以试试  欧 冷漠)

//解法1: 直接两个指针两头向中间走就行了
bool IsPalindromeString1(char *str){ //O(n)   O(1)
    if(str == NULL){
        return true;
    }
    char *left =str;
    char *right=left;
    while(*right != '\0'){
        right++; 
    }
    --right;
    while(left < right){
        if(*left++  != *right--){
            return false;
        }
    }
    return true;
}
bool IsPalindromeString2(char *str,int strlen){ //O(n)   O(1)
   if(str == NULL){
     return true;
   }
  char *left=str;
  char *right=str; 
  //将pos定位到字符串中间的位置
  int pos=((strlen>>1)-1) > 0 ? (strlen>>1)-1 : 0;
  left = str+pos;
  right = str+(strlen-1-pos);

  while(left >= str){
      if(*left-- != *right++){
        return false; 
      } 
  }
  return true;

}

//2.扩展 判断一个单链表中的数据是不是回文

//解决方式:采用快慢指针的方式    其中一个指针移到后半段的开头 将后半段进行逆置


//3.扩展 判断一个栈中数据是不是回文
//解决方式:对于栈的话，只需要将字符串全部压入栈，然后依次将各字符出栈，这样得到的就是原字符串的逆置串，分别和原字符串各个字符比较，就可以判断了

int main()
{
    char str[]="abcba";
    char str1[]="abddcba";
   cout<<IsPalindromeString1(str)<<endl;
   cout<<IsPalindromeString1(str1)<<endl;
   
   cout<<IsPalindromeString2(str,5)<<endl;
   cout<<IsPalindromeString2(str1,7)<<endl;
    return 0;
}

