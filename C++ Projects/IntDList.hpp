
/*
.hpp file for function definitioons. Modify this file only when you add new functions in intDList.cpp
*/

#ifndef INTDLIST_H
#define INTDLIST_H
#include "IntDList_node.hpp"
#include <string>
using namespace std;
class IntDLList 
{
public:
    IntDLList(); 
    ~IntDLList();
    int isEmpty() const 
    {
        return ListHead->next == ListHead;
    }
    
    void insertInOrder (int);
    void addToTail(int);
    void addToHead(int );
    int  deleteFromHead(); // delete the head and return its info;
    int  deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    string addToString() const;

private:
    IntDLLNode* ListHead;
};

#endif /* INTDLIST_H */
