#include <iostream>

template <class T>
class Linked_List{
    private:
        struct Node{
            T value;
            //std::unique_ptr<Node> next; // use for ~Linked_List() = default;
            Node *next;
            Node *prev;
            
            Node(T value) : value(value), prev(nullptr), next(nullptr){}
        };
        Node *head; 
        Node* tail;
    
    public:
        Linked_List() : head(nullptr), tail(nullptr){}

        class Iterator{
            private: 
                Node* current;
            public:
                Iterator(Node* current) : current(current){}
                //++ Operator (go to next node)
                Iterator& operator++(){
                    if(current) current = current->next;
                    return *this;
                }
                //-- Operator (back to previous node)
                Iterator& operator--(){
                    if(current) current = current->prev;
                    return *this;
                }
                //Access value of current node
                T& operator*(){
                    return current->value;
                }
                //!= Operator compare iterator (const is not allow change anything about data member of current object) 
                bool operator !=(const Iterator& other) const{
                    return current != other.current;
                }

                Node* getNode() const{
                    return current;
                }
        };
        //return iterator pointing fist element
        Iterator begin(){
            return Iterator(head);
        }
        //return iterator pointing nullptr (last list)
        Iterator end(){
            return Iterator(nullptr);
        }
        //Access first element of list
        T& front(){
            if(!head) throw std::out_of_range("List is empty");
            return head->value;
        }
        //Access last element of list
        T& back(){
            if(!tail) throw std::out_of_range("List is empty");
            return tail->value;
        }
        //Delete first element
        void pop_front(){
            if(!head) throw std::out_of_range("List is empty");
            Node* delete_head = head;
            head = head->next;
            if(head){//if head->next have a node
                head->prev = nullptr;
            }else{//just have one node, head->next = nullptr
                tail = nullptr;
            }

            delete delete_head;
        }
        //Delete last element
        void pop_back(){
            if(!tail) throw std::out_of_range("List is empty");
            Node* delete_tail = tail;
            tail = tail->prev;
            if(tail){//if tail->prev have a node
                tail->next = nullptr; //prev tail -> nullptr
            }else{
                head = nullptr;
            }

            delete delete_tail;
        }
        //Add element at last list
        void push_back(const T& value){
            Node* new_node = new Node(value);
            if(!head){//list is empty
                head = tail = new_node;
                return;
            }
            tail->next = new_node;//tail for new node
            new_node->prev = tail;//Append new_node to tail node
            tail = new_node;//now tail is new node
        }
        //Add element at first list
        void push_front(const T& value){
            Node* new_node = new Node(value);
            if(!head){
                head = tail = new_node;
                return;
            }
            head->prev = new_node;//head for new node
            new_node->next = head;//Append new_node to head node
            head = new_node;//now head is new node
        }
        //Size
        size_t size(){
            int count = 0;
            Iterator it = begin();
            while(it != end()){
                ++count;
                ++it;
            }
            return count;
        }
        //Add element by optional position
        void insert(const T& value, T position){
            Node* new_node = new Node(value);

            int current_size = size();

            if(position <= 1){
                push_front(value);
                return;
            }else if(position > current_size){
                push_back(value);
                return;
            }

            Iterator it = begin();
            while(--position){
                ++it;
            }
            Node* position_Node = it.getNode();
            --it;
            Node* previous_Node = it.getNode();
            //Push position node back
            position_Node->prev = new_node;
            new_node->next = position_Node;
            //Connect previous node to new node
            previous_Node->next = new_node;
            new_node->prev = previous_Node;
        }
        //Print linked list forward
        void printAll_forward(){
            for(Iterator it = begin(); it != end(); ++it){
                std::cout << *it << "->";
            }
            std::cout << "nullptr" << std:: endl;
        }
        //Print linked list forward
        void printAll_backward(){
            for(Iterator it = Iterator(tail); it != nullptr; --it){
                std::cout << *it << std::endl;
            }
            std::cout << "nullptr" << std::endl;
        }
    ~Linked_List(){
        
        while(head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
        
};

int main()
{
  // Tạo danh sách liên kết kiểu int
  Linked_List<int> Linkedlist;

  //Thêm các thành viên
  Linkedlist.push_back(3);
  Linkedlist.push_back(4);
  Linkedlist.push_back(5);
  Linkedlist.push_back(6);

  //In ra so luong phan tu cua dslk
  std::cout << "Size: " << Linkedlist.size() << std::endl;

  //In ra man hinh 
  std::cout << "Display forward: ";
  Linkedlist.printAll_forward();
  std::cout << "Display backward: ";
  Linkedlist.printAll_backward();

  Linkedlist.insert(10,1);
  std::cout << "After Inserting: ";
  Linkedlist.printAll_forward();

  std::cout << "The data of the first element: " << Linkedlist.front() << std::endl;
  std::cout << "The data of the last element: " << Linkedlist.back() << std::endl;

  Linkedlist.pop_front();
  std::cout << "After pop_front: ";
  Linkedlist.printAll_forward();

  Linkedlist.pop_back();
  std::cout << "After pop_back: ";
  Linkedlist.printAll_forward();
  return 0;
}