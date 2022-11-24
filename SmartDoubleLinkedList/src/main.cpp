#include "DoubleLinkedList.hpp"
#include <iostream>

int main(void) {
    std::cout << "Test 1. constructor ----------------------------------------------------" << std::endl;
    DoubleLinkedList<std::string> list;
    std::cout << "DoubleLinkedList<std::string> list" << std::endl;
    list.printNode();
    std::cout << std::endl;

    std::cout << "Test 2. create Node ----------------------------------------------------" << std::endl;
    std::cout << "list.createNode(수)" << std::endl;
    list.createNode("수");
    list.printNode();
    std::cout << std::endl;

    std::cout << "Test 3. print Node -----------------------------------------------------" << std::endl;
    std::cout << "list.printNode()" << std::endl;
    list.printNode();
    std::cout << std::endl;

    std::cout << "Test 4. find Node ------------------------------------------------------" << std::endl;
    std::shared_ptr<Node<std::string>> p;
    std::cout << "Node<std::string>* p" << std::endl;
    p = list.findNode("수");
    std::cout << "p = list.findNode(수)" << std::endl;
    std::cout << "p : " << p << std::endl;
    std::cout << std::endl;

    std::cout << "Test 5. push Front Node ------------------------------------------------" << std::endl;
    std::cout << "list.clearList()" << std::endl;
    list.clearList();
    list.printNode();
    std::cout << "list.pushFrontNode()" << std::endl;
    list.pushFrontNode("금");
    list.printNode();
    list.pushFrontNode("목");
    list.printNode();
    list.pushFrontNode("수");
    list.printNode();
    list.pushFrontNode("화");
    list.printNode();
    list.pushFrontNode("월");
    list.printNode();
    std::cout << std::endl;

    std::cout << "Test 6. push Back Node -------------------------------------------------" << std::endl;
    std::cout << "list.clearList()" << std::endl;
    list.clearList();
    list.printNode();
    std::cout << "list.pushBackNode()" << std::endl;
    list.pushBackNode("월");
    list.printNode();
    list.pushBackNode("화");
    list.printNode();
    list.pushBackNode("수");
    list.printNode();
    list.pushBackNode("목");
    list.printNode();
    list.pushBackNode("금");
    list.printNode();
    std::cout << std::endl;

    std::cout << "Test 7. pop Front Node -------------------------------------------------" << std::endl;
    std::cout << "list.clearList()" << std::endl;
    list.clearList();
    list.printNode();
    std::cout << "list.pushBackNode()" << std::endl;
    list.pushBackNode("월");
    list.pushBackNode("화");
    list.pushBackNode("수");
    list.pushBackNode("목");
    list.pushBackNode("금");
    list.printNode();
    std::cout << "list.popFrontNode() : " << std::endl;
    list.popFrontNode();
    list.printNode();
    list.popFrontNode();
    list.printNode();
    list.popFrontNode();
    list.printNode();
    list.popFrontNode();
    list.printNode();
    list.popFrontNode();
    list.printNode();
    std::cout << std::endl;

    std::cout << "Test 8. pop Back Node --------------------------------------------------" << std::endl;
    std::cout << "list.pushBackNode()" << std::endl;
    list.pushBackNode("월");
    list.pushBackNode("화");
    list.pushBackNode("수");
    list.pushBackNode("목");
    list.pushBackNode("금");
    list.printNode();
    std::cout << "list.popBackNode() : " << std::endl;
    list.popBackNode();
    list.printNode();
    list.popBackNode();
    list.printNode();
    list.popBackNode();
    list.printNode();
    list.popBackNode();
    list.printNode();
    list.popBackNode();
    list.printNode();
    std::cout << std::endl;

    std::cout << "Test 9. insert Node ----------------------------------------------------" << std::endl;
    std::cout << "list.pushBackNode()" << std::endl;
    list.pushBackNode("화");
    list.pushBackNode("목");
    list.pushBackNode("금");
    list.printNode();
    std::cout << "list.findNode(월)" << std::endl;
    p = list.findNode("월");
    std::cout << "list.insertNode(p, 월)" << std::endl;
    list.insertNode(p, "월");
    list.printNode();
    std::cout << "list.findNode(화)" << std::endl;
    p = list.findNode("화");
    std::cout << "list.insertNode(p, 수)" << std::endl;
    list.insertNode(p, "수");
    list.printNode();
    std::cout << std::endl;

    std::cout << "Test 10. delete Node ---------------------------------------------------" << std::endl;
    std::cout << "list.findNode(수)" << std::endl;
    p = list.findNode("수");
    std::cout << "list.deleteNode(p)" << std::endl;
    list.deleteNode(p);
    list.printNode();
    std::cout << "list.findNode(월)" << std::endl;
    p = list.findNode("월");
    std::cout << "list.deleteNode(p)" << std::endl;
    list.deleteNode(p);
    list.printNode();
    std::cout << "list.findNode(금)" << std::endl;
    p = list.findNode("금");
    std::cout << "list.deleteNode(p)" << std::endl;
    list.deleteNode(p);
    list.printNode();
    std::cout << "list.findNode(월)" << std::endl;
    p = list.findNode("월");
    std::cout << "list.deleteNode(p)" << std::endl;
    list.deleteNode(p);
    list.printNode();
    std::cout << std::endl;

    std::cout << "Test 11. clear List ----------------------------------------------------" << std::endl;
    std::cout << "list.clearList()" << std::endl;
    list.clearList();
    list.printNode();
    std::cout << "list.pushBackNode()" << std::endl;
    list.pushBackNode("월");
    list.pushBackNode("화");
    list.pushBackNode("수");
    list.pushBackNode("목");
    list.pushBackNode("금");
    list.printNode();
    std::cout << "list.clearList()" << std::endl;
    list.clearList();
    list.printNode();
    std::cout << std::endl;

    return 0;
}
