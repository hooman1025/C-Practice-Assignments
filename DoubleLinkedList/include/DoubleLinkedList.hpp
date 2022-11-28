#ifndef __DOUBLELINKEDLIST_HPP__
#define __DOUBLELINKEDLIST_HPP__

#include <iostream>

template <class T> class Node;
template <class T> class DoubleLinkedList;

template <class T>
class Node {
private:
    Node* llink = nullptr;
    T data;
    Node* rlink = nullptr;

    friend DoubleLinkedList<T>;
};

template <class T>
class DoubleLinkedList {
private:
    Node<T>* head;

public:
    DoubleLinkedList() : head(nullptr) {}
    ~DoubleLinkedList();
    void createNode(const T& data);
    void pushFrontNode(const T& data);
    void pushBackNode(const T& data);
    void popFrontNode(void);
    void popBackNode(void);
    void insertNode(Node<T>* pre, const T& data);
    void deleteNode(Node<T>* del);
    Node<T>* findNode(const T& data);
    void printNode(void);
    void clearList(void);
};

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    Node<T>* temp = head;
    while (nullptr != head) {
        temp = head->rlink;
        delete head;
        head = temp;
    }
}

template <class T>
void DoubleLinkedList<T>::createNode(const T& data) {
    Node<T>* newNode = new Node<T>();
    head = newNode;
    newNode->data = data;
}

template <class T>
void DoubleLinkedList<T>::pushFrontNode(const T& data) {
    Node<T>* newNode = new Node<T>();
    Node<T>* temp = head;

    if (nullptr != head) {
        temp->llink = newNode;
        newNode->rlink = temp;
        head = newNode;
        newNode->data = data;
    } else {
        head = newNode;
        newNode->data = data;
    }
}

template <class T>
void DoubleLinkedList<T>::pushBackNode(const T& data) {
    Node<T>* newNode = new Node<T>();
    Node<T>* temp = head;

    if (nullptr != head) {
        while (nullptr != temp) {
            if (nullptr == temp->rlink) {
                temp->rlink = newNode;
                newNode->llink = temp;
                newNode->data = data;
                break;
            }
            temp = temp->rlink;
        }
    } else {
        head = newNode;
        newNode->data = data;
    }
}

template <class T>
void DoubleLinkedList<T>::popFrontNode(void) {
    Node<T>* temp = head;

    if (nullptr != head) {
        if (nullptr != head->rlink) {
            head->rlink->llink = nullptr;
            head = head->rlink;
            delete temp;
        } else {
            delete temp;
            head = nullptr;
        }
    }
}

template <class T>
void DoubleLinkedList<T>::popBackNode(void) {
    Node<T>* temp = head;

    if (nullptr != head) {
        while (nullptr != temp) {
            if (nullptr == temp->rlink) {
                break;
            }
            temp = temp->rlink;
        }

        if (nullptr != temp->llink) {
            temp->llink->rlink = nullptr;
            delete temp;
        } else {
            delete temp;
            head = nullptr;
        }
    }
}

template <class T>
void DoubleLinkedList<T>::insertNode(Node<T>* pre, const T& data) {
    Node<T>* newNode = new Node<T>();
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
void DoubleLinkedList<T>::deleteNode(Node<T>* del) {
    if ((nullptr != head) && (nullptr != del)) {
        if (nullptr == del->llink) {
            head = del->rlink;
            if (nullptr != del->rlink) {
                del->rlink->llink = nullptr;
            }
            delete del;
        } else if (nullptr == del->rlink) {
            del->llink->rlink = nullptr;
            delete del;
        } else {
            del->llink->rlink = del->rlink;
            del->rlink->llink = del->llink;
            delete del;
        }
    }
}

template <class T>
Node<T>* DoubleLinkedList<T>::findNode(const T& data) {
    Node<T>* temp = head;
    
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
    Node<T>* node;
    node = head;

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
    Node<T>* temp = head;

    while (nullptr != head) {
        temp = head->rlink;
        delete head;
        head = temp;
    }
}

#endif //__DOUBLELINKEDLIST_HPP__