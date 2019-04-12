//
// Created by ruben on 4/12/19.
//

#include "TwoLinkedList.h"
UTEC::Node::Node():value{0}, next{nullptr} {}

UTEC::Node::Node(int value):value{value}, next{nullptr} {}

UTEC::TwoLinkedList::TwoLinkedList():head1{nullptr},
                                    head2{nullptr},
                                    tail1{nullptr},
                                    tail2{nullptr},
                                    tail{nullptr}{}

UTEC::TwoLinkedList::~TwoLinkedList(){
    Node* temp = head1;
    while (temp->next != nullptr){
        delete temp;
        temp = temp->next;
    }
}
void UTEC::TwoLinkedList::push_back1(int value) {
    if (head1 != nullptr){
        Node* temp = new Node(value);
        if (head1->next== nullptr){
            head1 = temp;
            tail1 = temp;
        } else if (tail1->next == nullptr){
            tail1->next = temp;
            tail1 = temp;
        } else {
            tail->next =temp;
            tail = temp;
        } delete temp;
    }
}

void UTEC::TwoLinkedList::push_back2(int value) {
    if (head2 != nullptr){
        Node* temp = new Node(value);
        if (head2->next== nullptr){
            head2 = temp;
            tail2 = temp;
        } else if (tail2->next == nullptr){
            tail2->next = temp;
            tail2 = temp;
        } else {
            tail->next =temp;
            tail = temp;
        } delete temp;
    }
}
std::string UTEC::TwoLinkedList::merge(int value) {
    if ((head1 != nullptr) || (head2 != nullptr)){
        Node* temp = new Node(value);
        if ((tail1->next != nullptr ) && (tail2->next != nullptr)) {
            delete temp;
            return "Operacion duplicada";
        } else {
            tail1->next=temp;
            tail2->next=temp;
            delete temp;
            return "Operacion exitosa";
        }
    } else {
        return "NInguna lista ha sido inicializada";
    }
}
bool UTEC::TwoLinkedList::is_merged() {
    if ((tail1->next != nullptr ) && (tail2->next != nullptr)){
        return true;
    } else {
        return false;
    }
}
std::string UTEC::TwoLinkedList::getlist(int value) {
    if ((head1 != nullptr) && (head2 != nullptr)){
        Node* temp = nullptr;
        std::string cadena;
        if (value == 1){
            temp = head1;
            while (temp != tail1){
                cadena+=std::to_string(temp->value)+" ";
                temp = temp->next;
            } delete temp;
            return cadena;
        } else if (value == 2){
            temp = head2;
            while (temp != tail2->next){
                cadena+=std::to_string(temp->value)+" ";
                temp = temp->next;
            } delete temp;
            return cadena;
        } else if (value == 0){
            if (is_merged()){
                temp = tail1->next;
                cadena = getlist(1)+getlist(2)+std::to_string(temp->value)+" ";
                delete temp;
                return cadena;
            } else {
                return "";
            }
        }
    }
}

UTEC::Node* UTEC::TwoLinkedList::search(int value) {
    if ((head1 != nullptr) || (head2 != nullptr)){
        Node* temp = head1;
        if (temp != nullptr){
            while (temp != nullptr){
                if (temp->value == value){
                    return temp;
                } temp = temp->next;
            }
        } else {
            temp = head2;
            while (temp != nullptr){
                if (temp->value == value){
                    return temp;
                } temp = temp->next;
            }
            delete temp;
            return nullptr;
        }
    }
}

/*
void UTEC::TwoLinkedList::save(const std::string & file) {} {
    std::fstream documento()
}*/
