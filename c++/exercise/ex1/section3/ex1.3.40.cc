#include<iostream>
#include<ostream>
#include<cstdint>
#include<unordered_map>
//#include<string>
template<typename T>
struct Node{
    T item;
    Node *next;
};

template<class T>
class mylist;

template<class U>
std::ostream& operator<<(std::ostream& os, const mylist<U> &list);

template<class T>
class mylist{
public:
    typedef u_int32_t size_type;
    typedef T value_type;
    mylist():_head(nullptr){}
    size_type size(){return _size;}
    bool isEmpty(){return size()==0;}
    template<class U> friend std::ostream& operator<< (std::ostream& os, const mylist<U>& list);
    
    void insert(value_type item){
        auto search = node_map.find(item);
        if(search != node_map.end()){
            delete_node(search->second);
            node_map.erase(search);
        }
        Node<value_type>* oldFirst = _head;
        _head = new Node<value_type>();
        _head->item = item;
        _head->next = oldFirst;

        node_map.insert(std::pair<value_type, Node<value_type>*>(item, _head));
        _size++;
    }

    void delete_node(Node<value_type>* node){
        if(isEmpty()){
            return;
        }
        auto current = _head;
        if(node == current){
            delete _head;
            _head = current->next;
            --_size;
        }else{
            for(;current->next != nullptr; current = current->next){
                if(current->next == node){
                    current->next = current->next->next;
                    delete node;
                    --_size;
                    break;
                }
            }
        }
    }
private:

    Node<value_type>* _head;
    size_type _size;
    std::unordered_map<value_type, Node<value_type>*> node_map;
};


template<class U>
std::ostream& operator<<(std::ostream& os, const mylist<U> &list){
    
    //assert(!list.isEmpty());
    for(auto current = list._head; current != nullptr; current = current->next){
        os << current->item << std::endl;
    }
    return os;
}


int main(){
    mylist<std::string> l;
    l.insert(std::string("a"));
    l.insert(std::string("b"));
    l.insert(std::string("c"));
    l.insert(std::string("d"));
    l.insert(std::string("e"));
    l.insert(std::string("f"));
    l.insert(std::string("g"));
    l.insert(std::string("h"));
    l.insert(std::string("i"));
    l.insert(std::string("b"));
    std::cout << l << std::endl;
}


