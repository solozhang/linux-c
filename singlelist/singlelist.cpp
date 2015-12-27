#include "singlelist.h"
#include <iostream>
//using namespace std;
template <class T>
Node<T>::Node(T key)
{
    this->node.next = NULL;
    this->node.key = key;
//    cout <<"constructed"<<endl;
}

template <class T>
bool Node<T>::empty(Node &head)
{
    if(!(head.next))
        return false;
    else
        return true;
}

template <class T>
Node<T>::~Node()
{
//   cout <<"destroyed"<<endl;
}
template <class T>
_listnode<T>* Node<T>::find(Node &head, T key)
{
    _listnode<T> *phead = &(head.node);
    while(phead->next != NULL && phead->next->key != key)
    {
        phead = phead->next;
    }
    return phead;
}

template <class T>
_listnode<T>* Node<T>::addfind(Node &head, T key)
{
    _listnode<T> *phead = &(head.node);
    while(phead != NULL && phead->key != key)
    {
        phead = phead->next;
    }
    return phead;
}

template <class T>
void Node<T>::add(Node &head, T key)
{
    _listnode<T>* pnode;
    pnode = addfind(head, key);
    if(pnode)
    {   
//        cout<<"same key!"<<endl;
    }
    else
    {
        _listnode<T> *addnode = new _listnode<T>;
        addnode->key = key;
        addnode->next = head.node.next;
        head.node.next = addnode;
//        cout<<"add "<<key<<" success!"<<endl;
    }
}

template <class T>
void Node<T>::del(Node &head, T key)
{
    _listnode<T>* pnode;
    _listnode<T>* tmp;
    T tmp_key;
    pnode = find(head, key);    
    if(pnode->next == NULL)
    {
//        cout<<"key "<<key<<" not exist!"<<endl;
    }
    else
    {
        tmp = pnode->next;
        pnode->next = pnode->next->next;
        tmp_key = tmp->key;
        delete tmp;
//        cout<<"delete "<<tmp_key<<" success!"<<endl;
    }
}
/*
void Node::Node(T key)
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

Node* Node::find(Node &head, T key)
{
    while(head.next != NULL && head.next->key != key)
        head = head.next;

    return head;
}

void Node::add(Node &head, T key)
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

void Node::del(Node &head, T key)
{
    Node* node;
    Node* tmp;
    T tmp_key;
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
