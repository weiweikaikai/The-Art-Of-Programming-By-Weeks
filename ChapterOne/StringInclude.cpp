/*************************************************************************
	> File Name: StringInclude.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sun 12 Mar 2017 12:10:39 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
 
//字符串包含
//1.给定两个分别由字母组成的字符串A和字符串B，字符串B的长度比字符串A短。请问，如何最快地判断字符串B中所有字母是否都在字符串A里？
//比如，如果是下面两个字符串：
//String 1：ABCD
//String 2：BAD
//答案是true，即String2里的字母在String1里也都有，或者说String2是String1的真子集。
//如果是下面两个字符串：
//String 1：ABCD
//String 2：BCE
//答案是false，因为字符串String2里的E字母不在字符串String1里。
//同时，如果string1：ABCD，string 2：AA，同样返回true

bool StringContains(string &A,string &B){   //时间复杂度为O(m+n) 
    unsigned char strmap[26];
    for(int i=0;i<26;++i){
        strmap[i]=0; 
    }
    for(int j=0;j<(int)A.length();++j){
          strmap[A[j]]=1; 
    }
    for(int k=0;k<(int)B.length();++k){
        if(strmap[B[k]] == 0){
            return false; 
        }
    }
    return true;
}

bool string_contains(string &a,string &b){ //时间复杂度是O(m+n) 空间复杂度O(1) 比上面的空间复杂度好一些
    unsigned int hash=0;
    for(int i=0;i<(int)a.length();++i){
        hash |= (1<<(a[i]-'a'));    
    }
    for(int j=0;j<(int)b.length();++j){
        if( (hash &= (1<<(b[j]-'a'))) == 0){
            return false;
        }
    }
    return true;
}


void test1(){
    //这里的测试是用小写字母测试的，对于大写字母可能要在代码中做些小修改，但是不影响算法本身
    string a("abcddef");
    string b("aa");
    cout<<StringContains(a,b)<<endl;
    cout<<string_contains(a,b)<<endl;
}
//2.如果两个字符串的字符一样，但是顺序不一样，被认为是兄弟字符串，比如bad和adb即为兄弟字符串，现提供一个字符串，如何在字典中迅速找到它的兄弟字符串，请描述数据结构和查询过程。
 
typedef struct bucket{

    char* strp[256];
    size_t  use;

}node;

typedef struct hash{
    size_t hashsize;
    node* bucket;
}hashmap;

hashmap* CreateHash(size_t size){ //参数为hash表的大小

    hashmap*newhash = new hash;
    newhash->hashsize =size;
    newhash->bucket=new node[size];
    
    for(int i=0;i<(int)size;++i){
        newhash->bucket[i].use=0;
        for(int j=0;j<256;++j){
        newhash->bucket[i].strp[j]=NULL;
        }
    }
    return newhash;
}
int HashFuction(hashmap*hash,char *str){

    int newhash=0;
    while(*str != '\0'){ 
        newhash+=(int)(*str);
        str++;
    }
    return newhash%(hash->hashsize);
}
void InsertString(hashmap *hash,char*str){
    int newhash=HashFuction(hash,str);
    hash->bucket[newhash].strp[hash->bucket[newhash].use++]=str;
}
void PrintHash(hashmap *hash,size_t pos){ 
    for(int i=0;i<hash->bucket[pos].use;++i){
        cout<<hash->bucket[pos].strp[i]<<endl; 
    }
}
void FindBrotherString(hashmap*hash,char *str){
    int newhash=HashFuction(hash,str);
    PrintHash(hash,newhash);
}
void test2(){
    char str1[4]="cab";
    char str2[4]="bac";
    char dest[4]="abc";
    hashmap*hash =CreateHash(128);
    InsertString(hash,str1);
    InsertString(hash,str2);
    FindBrotherString(hash,dest);
}

int main(){
    
    //test1(); 
    test2();
    return 0;
} 
