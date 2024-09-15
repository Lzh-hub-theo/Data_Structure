/*

数据结构：
    1.链表 list
        ·单向链表

 ! 这是个想法
 ? 如果我把这些函数内部进行对链表的识别，什么类型的链表就用这种类型的来实现，那就可以做到调用一个函数来解决各种链表的各种需求

*/

#include <iostream>

using namespace std;

void PrintLine(){
    cout << "***********" << '\n';
}

//通过指针和结构体来实现单向链表结构
//单向链表
struct LinkList
{
    //头部来储存数据：数据域
    int data;
    //指针来存放下一个节点的地址
    LinkList* next;
};

typedef LinkList* LList_Point;

//双向链表表
struct DuLList
{
    //前驱节点
    DuLList* pre;
    //数据域
    int data;
    //后驱节点
    DuLList* next;
};

typedef DuLList* DuLList_Point;






//操作链表的函数

    //创建单向链表头节点
LList_Point Build_LList(){
    const auto head = new LinkList();
    cin >> head->data;
    return head;
}
    //添加一个单向链表节点
LList_Point Add_LList(LList_Point PreNode){
    const auto newNode = new LinkList();
    cin >> newNode->data;
    newNode->next = nullptr; //C++最好空指针用 nullptr 
    PreNode->next = newNode;
    return newNode;
}
LList_Point Insert_LList(LList_Point Pre_Node,LList_Point This_Node){
    if (This_Node->next == nullptr) //说明是末尾节点
    {
        const auto newNode = new LinkList();
        cin >> newNode->data;
        newNode->next = nullptr; //C++最好空指针用 nullptr 
        This_Node->next = newNode;
        return newNode;
    }else{
        const auto newNode = new LinkList();
        cin >> newNode->data;
        Pre_Node->next = newNode;
        newNode->next = This_Node;
        return newNode;
    }
}
void Remove_LList(LList_Point This_Node, LList_Point Pre_Node){
    if(This_Node->next != nullptr){
        Pre_Node->next = This_Node->next;
        delete This_Node;
    }else{
        Pre_Node->next = nullptr;
        delete This_Node;
    }
}
//查找内容,返回节点地址,如果没找到就返回一个nullptr
LList_Point Search_LList(LList_Point const search_Node,int Elem){
    if(search_Node != nullptr){
        LList_Point P = search_Node->next;
        while(P->next != nullptr && P -> data != Elem){
        P = P -> next;
        }
        if(P->data == Elem){
            return P;
        }else{
            P = nullptr;
            return P;
        }
    }else{
        LList_Point P = nullptr;
        return P;
    }
}



    //打印
void PrintList(LList_Point head){
    if(head != nullptr){
            while (head != nullptr)
        {
            cout << head->data << endl;
            head = head->next; // 指向下一个节点位置
        }
    }else{
        printf("Error: The list is empty.\n");
    }
}





int main()
{
    //创建链表

    //头节点
    LList_Point First_LL = Build_LList();
    //其他节点
    LList_Point second_LL = Add_LList(First_LL);
    // LinkList* third_LL =
    LList_Point third_LL = Add_LList(second_LL);

    LList_Point l = Search_LList(First_LL,4);
    PrintLine();
    PrintList(l);
    PrintLine();

    

    //尾节点就是最后一个创建的节点，它的next指向 nullptr
    PrintList(First_LL);
    PrintLine();
    Remove_LList(third_LL,second_LL);
    PrintList(First_LL);
    PrintLine();
    Insert_LList(First_LL,second_LL);
    PrintLine();
    PrintList(First_LL);
    PrintLine();


	return 0;
}