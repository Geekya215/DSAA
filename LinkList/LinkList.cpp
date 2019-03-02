#include <bits/stdc++.h>

template<class T>
class Node {
    public:
        T data;
        Node* next;
        Node* prev;
};

template<class T>
class LinkList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;
        int formatlength;

    public:
        LinkList();
        ~LinkList();
        void setFormat(int length);
        void add(T value);
        void insert(int index,T value);
        void replace(int index,T value);
        T getValue(int index);
        Node<T>* getNode(int index);
        void removeByIndex(int index);
        void removeByValue(T value);
        void display();
        bool isEmpty();
        bool checkRange(int range, int offset);
        void printError(int range);
};

template<class T>
void LinkList<T>::setFormat(int length) {
    if(length >= 7 && length <= 13) {
        formatlength = length;
    } else {
        std::cout << "Oops! reset failed, length must between 7 ~ 13" << std::endl;
    }
}

template<class T>
void LinkList<T>::display() {

    if(isEmpty()) {
        std::cout << "LinkList is empty!" << std::endl;
        return ;
    }

    Node<T>* temp = head;
    int posindex = 0;
    int negindex = ~length+1;
    std::cout << std::setw(formatlength) << "(+)pos" 
              << std::setw(formatlength) << "(-)neg" 
              << std::setw(formatlength) << "value" << std::endl;
    while(temp != nullptr) { 
        std::cout << std::setw(formatlength) << '[' + std::to_string(posindex++) + ']'
                  << std::setw(formatlength) << '[' + std::to_string(negindex++) + ']' 
                  << std::setw(formatlength) << temp->data << std::endl;
        temp = temp->next;
    }
}

template<class T>
bool LinkList<T>::isEmpty() {
    return !length;
}

template<class T>
void LinkList<T>::printError(int range) {
    std::cout << "Index out of range(" << ~range << '~' << range << '0' << std::endl;
}

template<class T>
bool LinkList<T>::checkRange(int range, int offset) {
    if(offset > ~range && offset < range) {
        return true;
    }
    return false;
}

template<class T>
LinkList<T>::LinkList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
    formatlength = 7; // dafault length 7 (minimal)
}

template<class T>
LinkList<T>::~LinkList() {
    Node<T>* temp = nullptr;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    length = NULL;
    formatlength = NULL;
    std::cout << "Delete LinkList" << std::endl;
}

template<class T>
void LinkList<T>::add(T value) {
    Node<T>* node = new Node<T>;
    node->data = value;
    node->next = nullptr;
    node->prev = nullptr;

    if(isEmpty()) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }

    length++;
}

template<class T>
void LinkList<T>::insert(int index,T value) {
    if(checkRange(length+1, index)) {
        Node<T>* temp = nullptr;
        Node<T>* node = new Node<T>;
        node->data = value;
        node->next = nullptr;
        node->prev = nullptr;

        if(isEmpty()) {
            add(value);
            delete node;
            return ;
        }

        if(index < 0) {
            temp = tail;
            index = ~index;
            while(index){
                temp = temp->prev;
                index--;
            }
            
        } else {
            temp = head;
            while(index) {
                temp = temp->next;
                index--;
            }
        }

        if(temp == head) {
            node->next = head;
            head->prev = node;
            head = node;
        } else {
            temp->prev->next = node;
            node->prev = temp->prev;
            node->next = temp;
            temp->prev = node;
        }

    } else {
        printError(length);
    }

    length++;
}

template<class T>
Node<T>* LinkList<T>::getNode(int index) {
    Node<T>* node = nullptr;
    if(checkRange(length)) {
        
    }
    return node;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 0;
    std::cout << ~x << std::endl;
    LinkList<int>* list = new LinkList<int>();
    list->insert(-1,13);
    list->add(17);
    list->add(24);
    list->add(21314);
    list->add(282);
    list->display();
    list->insert(-1,213);
    list->display();
    list->~LinkList();
    return 0;
}