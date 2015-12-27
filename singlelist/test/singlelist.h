//#include <iostream>
//using namespace std;
#ifndef HELLO_H
#define HELLO_H
struct _listnode{
    int key;
    _listnode *next;
};

class Node{
public:
    Node(int key);
    ~Node();
    bool empty(Node &head);
    void add(Node &head, int key);
    void del(Node &head, int key);
    _listnode * find(Node &head, int key);
    _listnode * addfind(Node &head, int key);
private:
    _listnode  node;
};
#endif
/*
template <class T>
Node ::Node(int key)
{
    this->node.next = NULL;
    this->node.key = key;
    cout <<"constructed"<<endl;
}

template <class T>
bool Node ::empty(Node &head)
{
    if(!(head.next))
        return false;
    else
        return true;
}

template <class T>
Node ::~Node()
{
   cout <<"destroyed"<<endl;
}
template <class T>
_listnode * Node ::find(Node &head, int key)
{
    _listnode  *phead = &(head.node);
    while(phead->next != NULL && phead->next->key != key)
    {
        phead = phead->next;
    }
    return phead;
}

template <class T>
_listnode * Node ::addfind(Node &head, int key)
{
    _listnode  *phead = &(head.node);
    while(phead != NULL && phead->key != key)
    {
        phead = phead->next;
    }
    return phead;
}

template <class T>
void Node ::add(Node &head, int key)
{
    _listnode * pnode;
    pnode = addfind(head, key);
    if(pnode)
        cout<<"same key!"<<endl;
    else
    {
        _listnode  *addnode = new _listnode ;
        addnode->key = key;
        addnode->next = head.node.next;
        head.node.next = addnode;
        cout<<"add "<<key<<" success!"<<endl;
    }
}

template <class T>
void Node ::del(Node &head, int key)
{
    _listnode * pnode;
    _listnode * tmp;
    int tmp_key;
    pnode = find(head, key);    
    if(pnode->next == NULL)
        cout<<"key "<<key<<" not exist!"<<endl;
    else
    {
        tmp = pnode->next;
        pnode->next = pnode->next->next;
        tmp_key = tmp->key;
        delete tmp;
        cout<<"delete "<<tmp_key<<" success!"<<endl;
    }
}
*/ 
