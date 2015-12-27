#include "singlelist.h"
#include <iostream>
using namespace std;
Node::Node(int key)
{
    this->node.next = NULL;
    this->node.key = key;
   cout <<"constructed"<<endl;
}

bool Node::empty(Node &head)
{
    if(!(head.node.next))
        return false;
    else
        return true;
}

Node::~Node()
{
  cout <<"destroyed"<<endl;
}
_listnode * Node::find(Node &head, int key)
{
    _listnode  *phead = &(head.node);
    while(phead->next != NULL && phead->next->key != key)
    {
        phead = phead->next;
    }
    return phead;
}

_listnode * Node::addfind(Node &head, int key)
{
    _listnode  *phead = &(head.node);
    while(phead != NULL && phead->key != key)
    {
        phead = phead->next;
    }
    return phead;
}

void Node::add(Node &head, int key)
{
    _listnode * pnode;
    pnode = addfind(head, key);
    if(pnode)
    {   
       cout<<"same key!"<<endl;
    }
    else
    {
        _listnode  *addnode = new _listnode ;
        addnode->key = key;
        addnode->next = head.node.next;
        head.node.next = addnode;
       cout<<"add "<<key<<" success!"<<endl;
    }
}

void Node::del(Node &head, int key)
{
    _listnode * pnode;
    _listnode * tmp;
    int tmp_key;
    pnode = find(head, key);    
    if(pnode->next == NULL)
    {
       cout<<"key "<<key<<" not exist!"<<endl;
    }
    else
    {
        tmp = pnode->next;
        pnode->next = pnode->next->next;
        tmp_key = tmp->key;
        delete tmp;
       cout<<"delete "<<tmp_key<<" success!"<<endl;
    }
}
/*
void Node::Node(int key)
{
    this->next = NULL;
    this->key = key;
    cout <<"constructed"<<endl;
}

bool Node::empty(Node &head)
{
    if(!(head.next))
        return false;
    else
        return true;
}

Node* Node::find(Node &head, int key)
{
    while(head.next != NULL && head.next->key != key)
        head = head.next;

    return head;
}

void Node::add(Node &head, int key)
{
    if(find(head, key))
        cout<<"same key!"<<endl;
    else
    {
        Node *node = new Node(key);
        node->next = head.next;
        head.next = node;
        cout<<"add "<<key<<" success!"<<endl;
    }
}

void Node::del(Node &head, int key)
{
    Node* node;
    Node* tmp;
    int tmp_key;
    node = find(head, key);    
    if(!node)
        cout<<"key "<<key<<" not exist!"<<endl;
    else
    {
        tmp = node->next;
        node->next = node->next->next;
        tmp_key = tmp->key;
        delete tmp;
        cout<<"delete "<<tmp_key<<" success!"<<endl;
    }
}
*/ 
