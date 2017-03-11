#include<iostream>
using namespace std;

//Q:给定一个字符串要求将字符串前边的若干个字符移动到字符串的尾部。
//如把字符串“abcdef”前面的2个字符'a'和'b'移动到字符串的尾部，使得原字符串变成字符串"cdefab"
//要求对长度为n的字符串操作时间复杂度为O(n) 空间复杂度为O(1)

//A:
//(1)暴力解决法 
//函数介绍:左边第一个字符移动到右边最后一个字符的位置
//参数介绍:(参数为字符串指针 和字符串长度)
void LeftShiftTORightOneChar(char *s,int n){

    if(s == NULL){
        return ; 
    }
    char tmp=s[0];
    for(int i=1;i<n;++i){
       s[i-1]=s[i];
    }
    s[n-1]=tmp;
    return;
}
//函数介绍:左边第一个字符移动到右边最后一个字符的位置
//参数介绍:(参数为字符串指针 和字符串长度,需要移动的字符数量)
void LeftShiftToRightString(char *s,int n,int m){

   if(s == NULL){
      return ;   
   }
    int times=m%n;//避免当m远远大于n时 无谓的循环   
   while(times--){
      LeftShiftTORightOneChar(s,n); 
   }
   return;
}

void test1(){
//此种方式  时间复杂度O(M*N) 空间复杂度O(1)
    
    char str[10]="abcdefghi"; 
    LeftShiftToRightString(str,9,3);
    cout<<"test1's result: "<<str<<endl;
    char str1[10]="abcdefghi"; 
    LeftShiftToRightString(str1,9,10);
    cout<<"test1's result: "<<str1<<endl;
}
//(2)三步反转法 
//函数介绍:逆转一定区间的字符串
//参数介绍:(参数为字符串指针 和字符串的区间 form 和to)
void ReverseString(char *s,int from,int to){
    
    while(from < to){//如果from==to情况出现那么这个区间是偶数 反之是奇数 此时from>to
        char tmp=s[from];
       s[from++]=s[to]; 
       s[to--]=tmp;
    }        
}
//函数介绍:左边第一个字符移动到右边最后一个字符的位置
//参数介绍:(参数为字符串指针 和字符串长度,要移动的字符数量)

void ThreeStepShiftString(char *s,int n,int m){

   if(s == NULL){
      return ;   
   }
   int times=m%n; //原因同上
   ReverseString(s,0,times-1);
   ReverseString(s,times,n-1);
   ReverseString(s,0,n-1);
   return;
}

void test2(){
//此种方式  时间复杂度O(M)+O(N-M)+O(N)其实就是O(N) 空间复杂度O(1)  
    char str[10]="abcdefghi"; 
    ThreeStepShiftString(str,9,3);
    cout<<"test2'result: "<<str<<endl;
}
//扩展(3)给出一个链表和一个数k，比如，链表为1→2→3→4→5→6，k=2，则翻转后2→1→6→5→4→3，若k=3，翻转后3→2→1→6→5→4，若k=4，翻转后4→3→2→1→6→5

int listsize=0; //只是为了下面算法方便构造链表用的 确实很挫的代码
typedef struct Node{
    int data;
    struct Node *next;
}ListNode;
//根据值来创建链表  无头的链表
bool  pushback(ListNode*&head,int value){
     
    ListNode*tmp = new ListNode;
    tmp->data=value;
    tmp->next=NULL;
    if(head == NULL){//空链表
      head  = tmp; 
      ++listsize;
    }
    else{
        ListNode*cur = head;
        while(cur->next){
            cur=cur->next;  
        }
        cur->next=tmp;
        ++listsize;
    } 
    return true ;
}
void PrintList(ListNode*head){
    if(head == NULL){
        cout<<"is null list\n";
    }
    else{
        ListNode*cur =head;
       while(cur){
           cout<<cur->data;
           if(cur->next != NULL){
               cout<<"->"; 
           } 
           cur=cur->next;
       }
       cout<<endl;
    }
    return ;
}
//翻转一定区间的链表的节点返回to那个节点的指针
ListNode *ReverseListHalfOfLeft(ListNode *&head,ListNode*&list,int from,int to){
    if(head == NULL){
        return NULL; 
    }
    ListNode*newhead=NULL;
    ListNode*end=NULL;
    ListNode*cur=head+from;
    ListNode*nowp=head+from;
    ListNode*nxt=NULL;
    for(int i=0;i<to-from;++i){
      cur=cur->next ; 
    }
    end=cur;
    ListNode*oldhead =end;
    while(nowp != end){
        nxt=nowp->next;
        nowp->next=newhead;
        newhead=nowp;
        nowp=nxt;
    }
    head=newhead; 
    for(int j=1;j<to-from;++j){
      newhead=newhead->next; 
    }
    list=newhead;
    return oldhead;
}
//翻转一定区间的链表的节点返回from那个节点的指针
void  ReverseListHalfOfRight(ListNode *head,ListNode*&right){
    if(head == NULL){
        return ; 
    }
    ListNode*newhead=NULL;
    ListNode*nowp=head;
    ListNode*nxt=NULL;
    while(nowp){
        nxt=nowp->next;
        nowp->next=newhead;
        newhead=nowp;
        nowp=nxt;
    }
    right=newhead;  
}

void ReverseList(ListNode *&head,int k){
    if(head==NULL){
        return; 
    }
    ListNode*left=NULL;
    ListNode*oldhead=ReverseListHalfOfLeft(head,left,0,k);
    //cout<<left->data<<endl;
    ListNode*right=NULL;
    ReverseListHalfOfRight(oldhead,right);
    //cout<<right->data<<endl;
    left->next=right;
}
void test3(){
    ListNode*head=NULL;
    for(int i=1;i<7;++i){
    pushback(head,i); 
    }
    PrintList(head);
    ReverseList(head,6);
    PrintList(head);
}

//扩展(4)编写程序，在原字符串中把字符串尾部的m个字符移动到字符串的头部，要求：长度为n的字符串操作时间复杂度为O(n)，空间复杂度为O(1)

void test4(){

//就是和把n-m个字符移动到最后面去一样呀
   char str[13]="ilovetencent";
   ThreeStepShiftString(str,12,12-7);
   cout<<str<<endl;
}

//扩展(5) 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变，句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理
void ReverseSentence(char *str){
    if(str == NULL){
       return ; 
    }
    char *cur=str;
    char *start=str;
    char *end=NULL;
    int flag=0;
    do{
        if(*cur == ' ' || *cur == '\0'){
           end=cur-1;
         while(start < end){
            char c=*start;
            *start++ = *end;
            *end-- = c;
         }
         flag=1;
        }
        if(flag){
         start = cur+1;
         flag=0;
        }

    }while(*cur++ != '\0');
    char *pend=cur-2;
    char *pstart=str;
    while(pstart < pend){
     char tmp = *pstart;
     *pstart++ = *pend;
     *pend-- = tmp;
    }
}
void test5(){
   char str[]="I am a student.";
   ReverseSentence(str);
   cout<<str<<endl;
}
int main(){

    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}
