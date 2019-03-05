#include <bits/stdc++.h>

template<class T>
class Node {
    public:
        T data;
        Node* next;
        Node* prev;

        Node(T value);
        ~Node();
};

template<class T>
Node<T>::Node(T value)
    :data(value)
    ,next(nullptr)
    ,prev(nullptr)
    { }

template<class T>
Node<T>::~Node() {
    // noting to do
}

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
        void insert(int index, T value);
        void replace(int index, T value);
        T getValue(int index);
        Node<T>* getNode(int index);
        void removeByIndex(int index);
        void removeByValue(T value); // default delete all value in linklist which equal parameter
        void removeByValue(T value, bool flag); // from head or from tail
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
    std::cout << "Index out of range(" << ~range << " ~ " << range << ")" << std::endl;
}

template<class T>
bool LinkList<T>::checkRange(int range, int offset) {
    // orignal version
    /**
     * this version has logic error
     */
    // if(offset > ~range && offset < range) {
    //     return true;
    // }
    // return false;
    if(offset >= ~range && offset <= range) 
        return true;
    return false;
}

template<class T>
LinkList<T>::LinkList()
    :head(nullptr) 
    ,tail(nullptr)
    ,length(0)
    ,formatlength(7) // dafault length 7 (minimal)
    { } 

template<class T>
LinkList<T>::~LinkList() {
    Node<T>* temp = nullptr;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    std::cout << "Delete LinkList" << std::endl;
}

template<class T>
void LinkList<T>::add(T value) {
    Node<T>* node = new Node<T>(value);

    if(isEmpty()) {
        head = node;
        tail = node;
    } 
    else {
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }

    length++;
}

template<class T>
void LinkList<T>::insert(int index,T value) {
    if(checkRange(length, index)) {

        if(isEmpty()) {
            add(value);
            return ;
        }

        Node<T>* temp = nullptr;
        Node<T>* node = new Node<T>(value);

        if(index < 0) {
            if(index == ~length) {
                node->next = head;
                head->prev = node;
                head = node;
                length++;
                return ;
            }

            temp = tail;
            index = ~index;
            while(index){
                temp = temp->prev;
                index--;
            }

            if(temp != tail) {
                node->next = temp->next;
                temp->next = node;
                node->next->prev = node;
                node->prev = temp;
            }
            else {
                add(value);
                return ;
            }
            
        } else {
            if(index == length) {
                tail->next = node;
                node->prev = tail;
                tail = node;
                length++;
                return ;
            }

            temp = head;
            while(index) {
                temp = temp->next;
                index--;
            }

            if(temp != head) {
                node->next = temp;
                temp->prev->next = node;
                node->prev = temp->prev;
                temp->prev = node;
            } 
            else {
                node->next = head;
                head->prev = node;
                head = node;
            }
        }

        length++;

    } else {
        printError(length);
    }

}

template<class T>
void LinkList<T>::replace(int index, T value) {
    if(checkRange(length-1,index)) {
        Node<T>* node = getNode(index);
        node->data = value;
    }
    else {
        printError(length);
    }
}

template<class T>
Node<T>* LinkList<T>::getNode(int index) {
    Node<T>* node = nullptr;
    if(checkRange(length-1,index)) {
        if(index < 0) {
            node = tail;
            index = ~index;
            while(index) {
                node = node->prev;
                index--;
            }
        } 
        else {
            node = head;
            while(index) {
                node = node->next;
                index--;
            }
        }
    }
    return node;
}


template<class T>
T LinkList<T>::getValue(int index) {
    Node<T>* node = getNode(index);
    if(node == nullptr) {
        std::string msg = "Index out of range("+std::to_string(~length+1) + " ~ " + std::to_string(length-1) + ")";
        throw msg;
    }
    return node->data;
}

template<class T>
void LinkList<T>::removeByIndex(int index) {
    if(checkRange(length-1,index)) {
        Node<T>* node = getNode(index);
        T temp = node->data;
        if(length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else if(node == head) {
            head = node->next;
            node->next->prev = node->prev;
        }
        else if(node == tail) {
            tail = node->prev;
            node->prev->next = node->next;
        }
        delete node;
        length--;
        std::cout << "Node postion:" << std::setw(5)
                  << index << "  value:" << std::setw(5)
                  << temp  << " deleted!" << std::endl;
    }
    else {
        printError(length-1);
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = -3;
    int y = 1;
    std::cout << "~x = " << ~x << std::endl;
    std::cout << "~y = " << ~y << std::endl;
    LinkList<int>* list = new LinkList<int>;
    list->insert(0,2);
    list->insert(-1,3);
    list->insert(1,5);
    list->insert(0,-100);
    list->insert(-2,132);
    list->display();
    try {
        std::cout << list->getValue(100) << std::endl;
    } catch(std::string& msg) {
        std::cerr << msg << '\n';
    }
    
    list->removeByIndex(-1);
    list->removeByIndex(0);
    list->removeByIndex(-1);
    list->removeByIndex(-1);
    list->removeByIndex(110);
    list->display();
    delete list;
    return 0;
}