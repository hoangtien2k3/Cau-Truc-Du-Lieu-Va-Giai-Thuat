
/*
    Danh sách liên kết đơn (Single Linked List) là một cấu trúc dữ liệu động, nó là một danh sách 
    mà mỗi phần tử đều liên kết với phần tử đúng sau nó trong danh sách. Mỗi phần tử 
    (được gọi là một node hay nút) trong danh sách liên kết đơn là một cấu trúc có hai thành phần:

        + Thành phần dữ liệu: lưu thông tin về bản thân phần tử đó.
        + Thành phần liên kết: lưu địa chỉ phần tử đứng sau trong danh sách, nếu phần tử đó là phần tử cuối cùng thì thành phần này bằng NULL.



    ! Đặc điểm của danh sách liên kết đơn:
        * Do danh sách liên kết đơn là một cấu trúc dữ liệu động, được tạo nên nhờ việc cấp phát động nên nó có một số đặc điểm sau đây:

        + Được cấp phát bộ nhớ khi chạy chương trình.
        + Có thể thay đổi kích thước qua việc thêm, xóa phần tử.
        + Kích thước tối đa phụ thuộc vào bộ nhớ khả dụng của RAM.
        + Các phần tử được lưu trữ ngẫu nhiên (không liên tiếp) trong RAM.


        * Và do tính liên kết của phần tử đầu và phần tử đứng sau nó trong danh sách liên kết đơn, nó có các đặc điểm sau:

        + Chỉ cần nắm được phần tử đầu và cuối là có thể quản lý được danh sách.
        + Truy cập tới phần tử ngẫu nhiên phải duyệt từ đầu đến vị trí đó.
        + Chỉ có thể tìm kiếm tuyến tính một phần tử.


*/

/*
    !Tạo Node:
        Danh sách liên kết đơn được tạo thành từ nhiều node
        * Một node gồm hai thành phần: là 
            + thành phần dữ liệu.
            + thành phần liên kết.

        Ex: 
            struct Node
            {
                int data;
                Node* next;
            };

        * Để tạo một node mới, ta thực hiện cấp phát động cho node mới, khởi tạo giá trị ban đầu và trả về địa chỉ của node mới được cấp phát.

            Node* CreateNode(int init_data)
            {
                Node* node = new Node;
                node->data = init_data;
                node->next = NULL;      //  node vừa tạo chưa thêm vào danh sách nên chưa liên 
                                            kết với phần tử nào cả nên phần liên kết gán bằng NULL
                return node;
            }
*/

/*
    ! Tạo danh sách liên kết đơn:
        

*/


#include<bits/stdc++.h>
using namespace std;

// cau truc Node
struct Node {
    int data;
    Node *next;
};


// dinh nghia 
typedef struct Node* node;


// tao node cua danh sach
node makeNode(int x) {
    node temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}


// kiem tra rong
bool empty(node a) {
    return a == NULL;
}


// kich thuoc cua danh sach
int Size(node a) {
    int count = 0;
    while(a != NULL) {
        ++count;
        a = a->next; // gan dia chi cua node tiep theo cho node hien tai
    }
    return count;
}


// thêm một phần tử và đầu danh sách liên kết
void insertFirst(node &a, int x) {
    node temp = makeNode(x);
    if (a == NULL) {
        a = temp;
    } else {
        temp->next = a;
        a = temp;
    }
}


// them phan tu vao cuoi danh sach
void insertLast(node &a, int x) {
    node temp = makeNode(x);
    if (a == NULL) {
        a = temp;
    } else {
        node p = a;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = temp;
    }
}

// them phan tu vao giua danh sach
void insertMiddle(node &a, int x, int pos) {
    int n = Size(a);
    if (pos <= 0 || pos > pos + 1) {
        cout << "Vi tri chen khong hop le!\n";
    } else if (n == pos + 1) {
        insertLast(a, x); 
        return;
    }
    node p = a;
    for(int i = 1; i <pos - 1; i++) {
        p = p->next;
    }
    node temp = makeNode(x);
    temp->next = p->next;
    p->next = temp;
}


// xoa phan tu o dau
void deleteFirst(node &a) {
    if (a == NULL) return;
    a = a->next;
}


// xoa phan tu o cuoi
void deleteLast(node &a) {
    if (a == NULL) return;
    node truoc = NULL, sau = a;
    while(sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc = NULL) {
        a = NULL;
    } else {
        truoc->next = NULL;
    }
}


// xoa o giua
void deleteMiddle(node &a, int pos) {
    if (pos <= 0 || pos > Size(a)) return;
    node truoc = NULL, sau = a;
    for(int i=1; i<pos; i++) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc = NULL) {
        a = a->next;
    } else {
        truoc->next = sau->next;
    }
}


// in ra danh sach
void in(node a) {
    cout << "\n______________________________" << endl;
    while(a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n______________________________" << endl;
}


// ham main
int main() {
    Node *head = NULL;
    while(1) {
        cout << "____________Menu__________\n";
        cout << "1. chen phan tu o dau danh sach\n";
        cout << "2. chen phan tu o cuoi danh sach\n";
        cout << "3. chen phan tu o giua danh sach\n";
        cout << "4. xoa phan tu o dau\n";
        cout << "5. xoa phan tu o cuoi\n";
        cout << "6. xoa phan tu o giua\n";
        cout << "7. duyet danh sach lien ket\n";
        cout << "___________________________\n";
        cout << "Nhap lua chon!: ";
        int lc; cin >> lc;
        if (lc == 1) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            insertFirst(head, x);
        } else if (lc == 2) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            insertLast(head, x);
        } else if (lc == 3) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
            insertMiddle(head, x, pos);
        } else if (lc == 4) {
            deleteFirst(head);
        } else if (lc == 5) {
            deleteLast(head);
        } else if (lc == 6) {
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            deleteMiddle(head, pos); 
        } else if (lc == 7) {
            in(head);
        }
    }

    return 0;
}



















