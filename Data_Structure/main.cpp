/*

数据结构：
    1.链表 list
    
*/

#include <iostream>

using namespace std;



//通过指针和结构体来实现单向链表结构
//单向链表
struct Node
{
    //头部来储存数据：数据域
    int data;
    //指针来存放下一个节点的地址
    Node* next;
};
//双向脸部表








//操作链表的函数
//打印
void PrintList(Node* head){
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next; // 指向下一个节点位置
    }
}





int main()
{
    //创建链表

    //头节点
    Node* head = new Node();
    head->data = 1;

    //其他节点
    Node* second = new Node();
    second->data = 2;
    second->next = nullptr; //C++最好空指针用 nullptr 

    head->next = second;

    Node* third = new Node();
    third->data = 3;
    third->next = nullptr;

    second->next = third;   //third是Node*类型的

    //尾节点就是最后一个创建的节点，它的next指向 nullptr
    
    
    


	return 0;
}