/*

数据结构：
    1.链表 list
        ·单向链表
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

typedef LinkList* LListPoint;

//双向链表表
// struct DuLList
// {

// };







//操作链表的函数

    //创建单向链表头节点
LListPoint Build_LList(){
    const auto head = new LinkList();
    cin >> head->data;
    return head;
}
    //添加一个单向链表节点
LListPoint Add_LList(LListPoint PreNode){
    const auto newNode = new LinkList();
    cin >> newNode->data;
    newNode->next = nullptr; //C++最好空指针用 nullptr 
    PreNode->next = newNode;
    return newNode;
}
LListPoint Insert_LList(LListPoint Pre_Node,LListPoint This_Node){
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
void Remove_LList(LListPoint This_Node, LListPoint Pre_Node){
    if(This_Node->next != nullptr){
    Pre_Node->next = This_Node->next;
    delete This_Node;
    }else{
        Pre_Node->next = nullptr;
        delete This_Node;
    }
}
//查找内容，返回节点地址
LListPoint Search_LList(LListPoint search_Node,int Elem){
    LListPoint P = search_Node->next;
    while(P->next != nullptr && P -> data != Elem){
        P = P -> next;
    }
    if(P->data == Elem){
        return P;
    }else{
        P = nullptr;
        return P;
    }
   
}



    //打印
void PrintList(LListPoint head){
    if(head != nullptr){
            while (head != nullptr)
        {
            cout << head->data << endl;
            head = head->next; // 指向下一个节点位置
        }
    }else{
        printf("The list is NULL\n");
    }
    
}





int main()
{
    //创建链表

    //头节点
    LListPoint First_LL = Build_LList();
    //其他节点
    LListPoint second_LL = Add_LList(First_LL);
    // LinkList* third_LL =
    LListPoint third_LL = Add_LList(second_LL);

    LListPoint l = Search_LList(First_LL,4);

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