#ifndef LINKED_QUEUE
#define LINKED_QUEUE


#include "CLinkedList/CLinkedList.h"


template <typename E> class LinkedQueue{
public:
    LinkedQueue() : C(), numElem(0) {}
    int size() const{return numElem;}
    bool empty() const{return numElem==0;}
    const E &front() const noexcept(false);
    void enqueue(const E &e);
    void dequeue() noexcept(false);
    void print();

private:
    CLinkedList<E> C;
    int numElem;

};
  template <typename E> const E &LinkedQueue<E>:: front() const noexcept(false){
    if (empty()){
        throw QueueEmptyException("Front of empty queue");
    }
    return C.front();
  }

  template <typename E> void LinkedQueue<E> :: enqueue(const E &e){
    C.add(e);
    C.advance();
    numElem++;
  }

template <typename E> void LinkedQueue<E>::dequeue() noexcept(false){
    if(empty()){
        throw QueueEmptyException(" Queue is empty");
    }
    numElem--;
    C.remove();
}


template <typename E> void LinkedQueue<E>::print(){
    LinkedQueue<E> p;
    while(!empty()){
        std::cout << front() << " ";
        p.enqueue(front());
        dequeue();
    }
    while (!p.empty()){
        enqueue(p.front());
        p.dequeue();
        
    }
    std::cout << std::endl;

}

#endif
