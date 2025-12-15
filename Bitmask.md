# [BITMASK]()
---

## ***1. ĐỊNH NGHĨA:***


- **Bitmasking** là một kỹ thuật liên quan đến việc thao tác **bit**. Về cơ bản, nó giống như việc đặt một mặt nạ lên một số **bit** nhất định và ẩn đi những **bit** không hữu ích khác, nhằm giúp chương trình hiệu quả hơn nhiều và tối ưu hóa bộ nhớ.

- **Bitmasking** là một chuỗi bit cũng có thể được gọi là tập bit hoặc trường bit và được sử dụng để thực hiện các phép toán bit trên dữ liệu đã cho.

 Về cơ bản, có 6 toán tử bitwise trong C có thể được sử dụng để thao tác bit như sau:
- `&` (Toán tử **AND bitwise**): trả về giá trị 1 nếu cả 2 bit đều là 1
- `|` (Toán tử **OR bitwise**): trả về giá trị 1 nếu ít nhất 1 trong 2 bit là 1
- `^` (Toán tử **XOR bitwise**): trả về giá trị 1 nếu 2 bit khác nhau
- `~` (Toán tử **Bitwise NOT**)
- `<<` (Toán tử dịch chuyển trái)
- `>>` (Toán tử dịch chuyển phải) <br>
    VD: 
    ```c
    int b = 9; // 00001001
    b << 1; // 00010010 nên b = 18
    b >> 1; // 00000100 nên b = 4
    ````


## ***2. KỸ THUẬT BITMASKING:***


### **a. Bật bit thứ i(Set up bit):**
- Trong kỹ thuật này, chúng ta đặt một bit cụ thể thành 1 mà không ảnh hưởng đến bất kỳ bit nào khác.
- Cú pháp: `number | (1 << bit_position_to_set)`
- VD: 
    ```c
    int S = 34; // 100010
    int j = 3;
    S |= (1 << j); // 101010 -> 42
    ```


### **b. Tắt bit thứ i(Clear a bit):**
- Trong phép toán này, chúng ta đặt một bit cụ thể thành 0 (thay vì 1 trong trường hợp trước) mà không ảnh hưởng đến bất kỳ bit nào khác.
- Cú pháp: `number & ~ (1 << bit_position_to_clear)`
- VD: 
    ```c
    int S = 42; // 00101010
    int j = 1;
    S &= ~(1 << j); // 00101000 -> 
    ```

### **c. Đảo (toggle) bit thứ i:**
- Trong phép toán này, chúng ta lật một bit cụ thể, nếu bit là 0 thì biến nó thành 1, ngược lại thì biến nó thành 0.
- Cú pháp: `number ^ (1 << bit_position_to_flipping) `
- VD: 
    ```c
    int S = 40; // 101000
    int j = 2;
    S ^= (1 << j); // 101100 -> 44
    ```


### **d. Kiểm tra (Checking) bit thứ i:**
- Trong phép toán này, chúng ta kiểm tra xem một bit cụ thể có phải là 1 hay không bằng cách sử dụng toán tử AND bitwise (&) cùng với toán tử dịch chuyển trái (<<).
- Kết quả trả về 1 là đang mở, và ngược lại là đang đóng
- Cú pháp: `bool isOn = (S & (1 << j)) != 0;`
- VD: 
    ```c
    int S = 42; // 00101010
    int j = 3;
    if (S & (1 << j)) printf("Bit %d dang bat\n",j);
    else printf("Bit %d dang tat\n",j);
    ```
    OUTPUT: 
    ```c
    Bit 3 dang bat
    ```


### **e. Lấy bit bật nhỏ nhất (Least Significant Bit On):**
- Cú pháp: `S & -S`
- VD:
    ```c
    int S = 40; // 00101000
    int T = S & -S; // 000001000 -> 8
    ```


### **f. Bật tất cả các bit từ 0 đến n-1**
- Cú pháp: `S = (1 << n) - 1;`
- VD:
    ```c
    int n = 3; // 00000011
    int S = (1 << n) - 1; // 00000111 -> 7
    ```
