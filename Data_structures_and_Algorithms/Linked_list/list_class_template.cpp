#include<iostream>

//Doubly linked list
template<class T>
class list
{
  private:
    //Node của doubly linked list
    struct Node {
      T value;      // Dữ liệu của node (kiểu dữ liệu T)
      Node *next;   // Con trỏ trỏ đến Node trước
      Node *prev;   // Con trỏ trỏ đến Node tiếp theo
    
      // Khởi tạo giá trị ban đầu ghi tạo ra Node
      Node(T value) : value(value),prev(nullptr),next(nullptr) {} 
    };
    Node* head;  // Con trỏ đầu danh sách
    Node* tail;  // Con trỏ cuối danh sách
  
  public:
    //Constructor
    list() : head(nullptr),tail(nullptr) {}

    //Class Iterator duyệt qua danh sách liên kết
    class Iterator
    {
      private: 
        Node* current; // Con trỏ trỏ tới Node hiện tại
      public:
        // Constructor
        Iterator(Node* current) : current(current) {}

        // Toán tử ++ (tiến tới node tiếp theo)
        Iterator& operator++()
        {
          if (current) current = current->next;
          return *this;
        }

        // Toán tử --(lùi về node trước đó)
        Iterator& operator--()
        {
          if (current) current = current->prev;
          return *this;          
        }

        // Toán tử *(truy cập dữ liệu của node hiện tại)
        T& operator *()
        {
          return current->value;
        }

        // Toán tử !=(so sánh iterator)
        bool operator !=(const Iterator& other) const {
          return current != other.current;
        }

        // Trả về con trỏ node hiện tại
        Node* getNode() const {
          return current;
        }
    };

    // Truy cập phần tử đầu danh sách
    T& front() {
        if (!head) throw std::out_of_range("List is empty");
        return head->value;
    }

    // Truy cập phần tử cuối danh sách
    T& back() {
        if (!tail) throw std::out_of_range("List is empty");
        return tail->value;
    }

    // Xóa phần tử đầu danh sách
    void pop_front() {
        if (!head) throw std::out_of_range("List is empty");

        Node* temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr; // Hủy liên kết tới phần tử cũ
        } else {
            tail = nullptr; // Danh sách trống
        }

        delete temp;
    }

    // Xóa phần tử cuối danh sách
    void pop_back() {
        if (!tail) throw std::out_of_range("List is empty");

        Node* temp = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr; // Hủy liên kết tới phần tử cũ
        } else {
            head = nullptr; // Danh sách trống
        }

        delete temp;
    }

    // Thêm phần tử vào cuối danh sách
    void push_back(T value)
    {
      Node* newnode = new Node(value);
      if (!head)
      {
        head = tail = newnode;
        return;
      }
      tail->next = newnode;   // nối node mới vào cuối
      newnode->prev = tail;   // Liên kết node mới với tail hiện tại
      tail = newnode;         // Cập nhật tail
    }

    // Thêm phần tử vào đầu danh sách
    void push_front(T value)
    {
      Node* newnode = new Node(value);
      if (!head)
      {
        head = tail = newnode;
        return;
      }
      newnode->next = head;   // nối node mới vào đầu
      head->prev = newnode;   // Liên kết head hiện tại với node mới
      head = newnode;         // Cập nhật head
    }

    // Trả về số phần tử trong danh sách liên kết
    int size()
    {
      int cnt = 0;
      Iterator it = begin();
      while(it != end())
      {
        ++cnt;
        ++it;
      }
      return cnt;
    }

    // Chèn phần tử vào vị trí pos
    void Insert(T value, T pos)
    {
      Node* newnode = new Node(value);

      // Lấy kích thước của danh sách liên kết
      int n = size();

      // Trở thành push_back hoặc push_front nếu pos nằm tai boundary
      if (pos <= 1)
      {
        push_front(value);
        return;
      }
      else if(pos > n)
      {
        push_back(value);
        return;
      }

      // Xác định vị trí của pos và tạo 2 con trỏ tại pos và prepos 
      Iterator it = begin();
      while(--pos)
      {
        ++it;
      }
      Node* posNode = it.getNode();
      --it;
      Node* preNode = it.getNode();

      // Liên kết newnode trước posNode
      posNode->prev = newnode;
      newnode->next = posNode;
      // Liên kết newnode sau preNode
      preNode->next = newnode;
      newnode->prev = preNode;
    }

    // Trả về iterator trỏ đến sau phần tử cuối cùng
    Iterator end()
    {
      return Iterator(nullptr);
    }

    // Trả về iterator trỏ đến phần tử đầu tiên
    Iterator begin()
    {
      return Iterator(head);
    }

    // Hiển thị danh sách liên kết
    void display_forward()
    {
      for (Iterator it = begin();it != end();++it)
      {
        std::cout << *it << "->";
      }
      std::cout << "nullptr" << std::endl;
    }

    // Hiển thị danh sách liên kết đảo ngược
    void display_backward()
    {
      for (Iterator it = Iterator(tail);it != nullptr;--it)
      {
        std::cout << *it << "->";
      }
      std::cout << "nullptr" << std::endl;
    }

    //Destructor
    ~list()
    {
      Node* temp;
      while(head)
      {
        temp = head;
        head = head->next;
        delete temp;
      }
    }
};

int main()
{
  // Tạo danh sách liên kết kiểu int
  list<int> Linkedlist;

  //Thêm các thành viên
  Linkedlist.push_back(3);
  Linkedlist.push_back(4);
  Linkedlist.push_back(5);
  Linkedlist.push_back(6);

  //In ra so luong phan tu cua dslk
  std::cout << "Size: " << Linkedlist.size() << std::endl;

  //In ra man hinh 
  std::cout << "Display forward: ";
  Linkedlist.display_forward();
  std::cout << "Display backward: ";
  Linkedlist.display_backward();

  Linkedlist.Insert(10,1);
  std::cout << "After Inserting: ";
  Linkedlist.display_forward();

  std::cout << "The data of the first element: " << Linkedlist.front() << std::endl;
  std::cout << "The data of the last element: " << Linkedlist.back() << std::endl;

  Linkedlist.pop_front();
  std::cout << "After pop_front: ";
  Linkedlist.display_forward();

  Linkedlist.pop_back();
  std::cout << "After pop_back: ";
  Linkedlist.display_forward();
  return 0;
}