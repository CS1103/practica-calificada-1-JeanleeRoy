//
// Created by ruben on 4/12/19.
//

#ifndef PC1_TWOLINKEDLIST_H
#define PC1_TWOLINKEDLIST_H

#include <string>
#include <vector>

namespace UTEC {
    struct Node {
        int value;
        Node* next;
        Node();
        explicit Node(int);
    };
    class TwoLinkedList {
        Node* head1;
        Node* head2;
        Node* tail1;
        Node* tail2;
        Node* tail;
    public:
        TwoLinkedList();
        ~TwoLinkedList();
        void push_back1(int);
        void push_back2(int);
        std::string merge(int );
        bool is_merged();
        std::string getlist (int );
        Node* search (int );
        void save(const std::string &);
        void load(auto );
    };
}


#endif //PC1_TWOLINKEDLIST_H
