#ifndef STACKLIST_STACKLIST_H
#define STACKLIST_STACKLIST_H

#include <initializer_list>
#include <string>
template<typename T>
class StackOnList;

template<typename T>
class QueueOnList;

template<typename T>
struct NodeStack {
    friend StackOnList<T>;
    friend QueueOnList<T>;
public:
    T value;
private:
    NodeStack<T> *prev;
    NodeStack<T> *next;

};

template<typename T>
class StackOnList {
private:
    NodeStack<T> *top;
public:
    StackOnList() {
        top = nullptr;

    }

    StackOnList(const std::initializer_list<T> &init_list) {
        top = nullptr;
        for (auto it = init_list.begin(); it != init_list.end(); it++) {
            push(*it);

        }
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    int Size() {
        if (isEmpty())
            return 0;

        int size = 1;
        NodeStack<T> *temp = top;
        while (temp->prev != nullptr) {
            size++;
            temp = temp->prev;
        }
        return size;
    }

    void push(const T &value) {
        NodeStack<T> *element = new NodeStack<T>;
        element->value = value;

        if (isEmpty()) {
            top = element;
            top->prev = nullptr;
        } else {
            element->prev = top;
            top = element;

        }
    }


    NodeStack<T> *Top() {
        return top;
    }


    T Pop() {
        if (!isEmpty()) {
            T temp = top->value;
            top = top->prev;
            return temp;

        }

    }
};

template<typename T>
class QueueOnList {
private:
    NodeStack<T> *back;
    NodeStack<T> *front;
public:
    QueueOnList() {
        back = nullptr;
        front = nullptr;
    }

    QueueOnList(const std::initializer_list<T> &init_list) {
        back = nullptr;
        front = nullptr;
        for (auto it = init_list.begin(); it != init_list.end(); it++) {
            push(*it);

        }
    }

    bool isEmpty() {
        return (back == nullptr && front == nullptr);
    }

    void push(const T &value) {
        NodeStack<T> *element = new NodeStack<T>;
        element->value = value;
        element->next = nullptr;
        element->prev = nullptr;
        if (isEmpty()) {
            back = element;
            front = element;
        } else {
            element->next = back;
            back->prev = element;
            back = element;
        }
    }

    NodeStack<T> *Top() {
        return front;
    }

    T Pop() {
        if (!isEmpty()) {
            T temp = front->value;
            if(front != back) {
                front->prev->next = nullptr;
                front = front->prev;
            }
            else {
                front=nullptr;
                back= nullptr;
            }
            return temp;
        }
    }
};

#endif //STACKLIST_STACKLIST_H
