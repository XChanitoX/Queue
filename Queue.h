#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
using namespace std;

template<typename T>
struct Node{
    T value;
    Node *next;
    Node *prev;

    explicit Node(T value_){
        this->value = value_;
        this->next = nullptr;
        this->prev = nullptr;
    }
    void killSelf(){
        this->value = 0;
        this->next = nullptr;
        this->prev = nullptr;
        delete this;
    }
};

template<typename T>
class Queue{
private:
    Node<T> *head;
    Node<T> *tail;
public:
    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    void insertElement(T value){
        auto node = new Node<T>(value);
        if (!this->head) {
            this->head = node;
            this->tail = node;
        } else{
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
        }
    }

    T popElement(){
        T value;
        if (!this->head) {
            cout << "El queue está vacío" << endl;
            value = 0;
        } else{
            value = this->tail->value;
            this->tail = this->tail->prev;
            this->tail->next->killSelf();
            this->tail->next = nullptr;
        }
        return value;
    }

    void printQueue(){
        auto temp = this->head;
        while(temp->next){
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << temp->value<< endl;
    }
};

#endif //QUEUE_QUEUE_H