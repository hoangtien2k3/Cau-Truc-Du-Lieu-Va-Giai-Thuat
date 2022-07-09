
/*
    + Queue(hàng đợi) là một loại container, được thiết kế để hoạt động theo kiểu 
    FIFO (First- in first – out) (vào trước ra trước), tức là một kiểu danh sách 
    mà việc bổ sung được thực hiển ở cuối danh sách và loại bỏ ở đầu danh sách.


    Trong queue, có hai vị trí quan trọng là vị trí đầu danh sách (front), nơi phần tử được lấy ra, 
    và vị trí cuối danh sách (back), nơi phần tử cuối cùng được thêm vào.



    ! Các phương thức (ngôn ngữ C++):
        + size() :	Trả về số lượng phần tử của queue
        + empty() :	Trả về true(1) nếu queue rỗng, ngược lại là false (0)
        + front() :	Truy xuất phần tử ở đầu queue (phần tử đầu tiên được thêm vào)
        + back() :	Truy xuất phần tử ở cuối queue (phần tử cuối cùng được thêm vào)
        + push (const x) :	Thêm phần tử có giá trị x vào cuối queue. Kích thước queue tăng thêm 1.
        + pop () :	Loại bỏ phần tử ở đầu queue. Kích thước queue giảm đi 1.


*/