#ifndef __DOUBLELINKEDLIST_HPP__
#define __DOUBLELINKEDLIST_HPP__

#include <iostream>
#include <memory>
#include <functional>

template <class T> class Node;
template <class T> class DoubleLinkedList;

template <class T>
class Node {
private:
    std::weak_ptr<Node<T>> llink;
    T data;
    std::shared_ptr<Node<T>> rlink;

public:
    Node<T>() : rlink(nullptr) {}
    //Node<T>(T inputData) : data(inputData) {}

    friend DoubleLinkedList<T>;
};

template <class T>
class DoubleLinkedList {
private:
    std::shared_ptr<Node<T>> head;

public:
    DoubleLinkedList() : head(nullptr) {}
    ~DoubleLinkedList() {}
    void createNode(const T& data);
    void pushFrontNode(const T& data);
    void pushBackNode(const T& data);
    void popFrontNode(void);
    void popBackNode(void);
    void insertNode(std::shared_ptr<Node<T>> pre, const T& data);
    void deleteNode(std::shared_ptr<Node<T>> del);
    std::shared_ptr<Node<T>> findNode(const T& data);
    void printNode(void);
    void clearList(void);
};
/*
template <class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    auto temp = head;
    while (nullptr != head) {
        temp = head->rlink;
        head.reset();
        head = temp;
    }
}
*/
template <class T>
void DoubleLinkedList<T>::createNode(const T& data) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>();
    newNode->data = data;
    head = newNode;
}

template <class T>
void DoubleLinkedList<T>::pushFrontNode(const T& data) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>();
    newNode->data = data;
    auto temp = head;
    
    if (nullptr != head) {
        temp->llink = newNode;
        newNode->rlink = temp;
        head = newNode;
    } else {
        head = newNode;
    }
}

template <class T>
void DoubleLinkedList<T>::pushBackNode(const T& data) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>();
    newNode->data = data;
    auto temp = head;

    if (nullptr != head) {
        while (nullptr != temp) {
            if (nullptr == temp->rlink) {
                temp->rlink = newNode;
                newNode->llink = temp;
                break;
            }
            temp = temp->rlink;
        }
    } else {
        head = newNode;
    }
}

template <class T>
void DoubleLinkedList<T>::popFrontNode(void) {
    auto temp = head;

    if (nullptr != head) {
        if (nullptr != head->rlink) {
            head->rlink->llink.lock() = nullptr;
            head = head->rlink;
            temp.reset();
        } else {
            temp.reset();
            head = nullptr;
        }
    }
}

template <class T>
void DoubleLinkedList<T>::popBackNode(void) {
    auto temp = head;

    if (nullptr != head) {
        while (nullptr != temp) {
            if (nullptr == temp->rlink) {
                break;
            }
            temp = temp->rlink;
        }

        if (nullptr != temp->llink.lock()) {
            temp->llink.lock()->rlink = nullptr;
            temp.reset();
        } else {
            temp.reset();
            head = nullptr;
        }
    }
}

template <class T>
void DoubleLinkedList<T>::insertNode(std::shared_ptr<Node<T>> pre, const T& data) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>();
    newNode->data = data;

    if (nullptr == head) {
        head = newNode;
    } else {
        if (nullptr != pre) {
            newNode->rlink = pre->rlink;
            pre->rlink = newNode;
            newNode->llink = pre;
        } else {
            newNode->rlink = head;
            head->llink = newNode;
            head = newNode;
        }

        if (nullptr != newNode->rlink) {
            newNode->rlink->llink = newNode;
        }
    }
}

template <class T>
void DoubleLinkedList<T>::deleteNode(std::shared_ptr<Node<T>> del) {
    if ((nullptr != head) && (nullptr != del)) {
        if (nullptr == del->llink.lock()) {
            head = del->rlink;
            if (nullptr != del->rlink) {
                del->rlink->llink.lock() = nullptr;
            }
        } else if (nullptr == del->rlink) {
            del->llink.lock()->rlink = nullptr;
        } else {
            del->llink.lock()->rlink = del->rlink;
            del->rlink->llink = del->llink;
        }
    }
}

template <class T>
std::shared_ptr<Node<T>> DoubleLinkedList<T>::findNode(const T& data) {
    auto temp = head;
    
    while (nullptr != temp) {
        if (temp->data == data) {
            break;
        } else {
            temp = temp->rlink;
        }
    }

    if (nullptr == temp) {
        temp = nullptr;
    }

    return temp;
}

template <class T>
void DoubleLinkedList<T>::printNode(void) {
    auto node = head;
    
    std::cout << "Node : ";
    
    while (nullptr != node) {
        std::cout << "[";
        std::cout << node->data;
        node = node->rlink;
        std::cout << "]";
        
        if (nullptr != node) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}

template <class T>
void DoubleLinkedList<T>::clearList(void) {
    auto temp = head;

    while (nullptr != head) {
        temp = head->rlink;
        head.reset();
        head = temp;
    }
}

#endif //__DOUBLELINKEDLIST_HPP__