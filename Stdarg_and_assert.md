# [STDARG.H]()
--- 
- Header file có tên stdarg.h trong Thư viện C định nghĩa một kiểu biến `va_list` và 3 **macro** mà có thể được sử dụng để lấy các tham số trong một hàm khi số tham số là chưa được biết (ví dụ như số tham số là có thể biến đổi).  


## Biến được định nghĩa trong ***stdarg.h***

 `va_list`: Đây là một kiểu phù hợp để lưu trữ thông tin cần thiết bởi ba macro là `va_start()`, `va_arg()` và `va_end()`.


## Các macro được định nghĩa trong ***stdarg.h***

|MACRO|MÔ TẢ|THAM SỐ|
|---|-----|-------|
|`void va_start(va_list ap, last_arg)`|Macro này khởi tạo biến ap để được sử dụng với hai macro là `va_arg` và `va_end`. |- `last_arg` là tham số cố định được biết cuối cùng, đang được truyền tới hàm, ví dụ: tham số ở trước ellipsis <br>- `ap` − Đây là đối tượng của va_list và nó giữ thông tin cần thiết để thu được các tham số bổ sung với va_arg|
|`type va_arg(va_list ap, type)`|Macro này thu nhận tham số tiếp theo trong danh sách tham số của hàm với kiểu type|- `ap` − Đây là đối tượng của kiểu `va_list` với thông tin về các tham số bổ sung và trạng thái thu nhận. Đối tượng này nên được khởi tạo bởi một lời gọi ban đầu tới `va_start` trước khi lời gọi đầu tiên tới `va_arg`. <br> - **type** − Đây là tên kiểu. Tên kiểu này được sử dụng như là kiểu của biểu thức, mà macro này mở rộng tới.|
|`void va_end(va_list ap)`|**Macro** này cho phép một hàm có số tham số biến đổi mà sử dụng **macro** là `va_start` để trả về. Nếu `va_end` không được gọi trước khi trả về từ hàm đó, thì kết quả là không được định nghĩa|- `ap` − Đây là đối tượng `va_list` được khởi tạo trước đó bởi `va_start` trong cùng hàm.|
|`va_copy(va_list ap1, va_list ap2)`|Cho phép sao chép `ap1` sang `ap2`||

### VD về chương trình C sử dụng `stdarg.h`
```c
#include <stdio.h>
#include <stdarg.h> //Để sử dụng các macro trong stdarg.h

int Tong(int n, ...) {
    int sum = 0;

    va_list arr; // Khởi tạo arr để lưu trữ các phần tử ở dấu ...
    va_start(arr, n); // Bắt đầu định nghĩa arr

    for (int i = 0;i < n;i++) {
        sum += va_arg(arr, int); // va_arg là các phần tử trong arr, kiểu dữ liệu là int
    }

    va_end(arr); // Kết thúc định nghĩa arr

    return sum;
}

int main() {
    printf("%d\n", Tong(3, 1, 2, 3)); //In ra màn hình tổng 3 số 1+2+3 = 6
    printf("%d", Tong(4, 5, 6, 7, 8)); //In ra màn hình tổng 4 số 5+6+7+8 = 26
}
```

Kết quả sẽ là:
```c
6
26
```

### `Stdarg.h` cho phép nhập một số lượng tham số bất kì mà không biết trước có bao nhiêu tham số.
### 
---
---
---

# [ASSERT]()

## ***1. ASSERT()***

- `ASSERT` là các câu lệnh được sử dụng để kiểm tra các giả định do lập trình viên đưa ra, chẳng hạn như xác thực logic hoặc bất biến trong mã. Ví dụ, chúng ta có thể sử dụng `assert` để kiểm tra xem chỉ mục của một mảng có nằm trong giới hạn hợp lệ trong quá trình phát triển hay không. Sau đây là cú pháp của `assert`:
    `void assert(int expression);`

- **expression**: Đây có thể là một biến hoặc bất cứ biểu thức C nào. Nếu **expression** ước lượng là **TRUE**, thì `assert()` không làm điều gì. Nếu **expression** ước lượng là **false**, thì `assert()` hiển thị một thông báo lỗi trên ***stderr*** và ngừng thực thi chương trình.
- **Macro** này không trả về bất cứ giá trị nào.

***Ví dụ:*** Chương trình C sau minh họa cách sử dụng của assert() macro trong Thư viện C:

```c
#include <assert.h> // include để dùng được macro assert
#include <stdio.h>
int main()
{
   int a;
   char str[50];
	 
   printf("Nhap mot gia tri nguyen: \n");
   scanf("%d", &a);
   assert(a >= 10);
   printf("Gia tri nguyen vua nhap la %d\n", a);
    
   printf("Nhap mot chuoi: ");
   scanf("%s", &str);
   assert(str != NULL);
   printf("Chuoi vua nhap la: %s\n", str);
	
   return(0);
}
```

#### 1. Trường hợp nhập một số nguyên có giá trị < 10, sẽ có thông báo lỗi sau:

```
Nhap mot gia tri nguyen: 
8
Assertion failed: a >= 10, file 123.c, line 10
```

#### 2. Nếu nhập một số nguyên và chuỗi thỏa mãn điều kiện, sẽ cho kết quả:

```
Nhap mot gia tri nguyen: 
10
Gia tri nguyen vua nhap la 10
Nhap mot chuoi: 12345
Chuoi vua nhap la: 12345
```


 ## ***2. ASSERT với NDEBUG:***

 - Trong C/C++, chúng ta có thể loại bỏ hoàn toàn các `assert()` tại thời điểm biên dịch bằng cách sử dụng bộ tiền xử lý `NDEBUG`.

 ```c
 // Chương trình bên dưới chạy tốt vì NDEBUG được định nghĩa
#include <stdio.h>
#define NDEBUG
#include <assert.h>

int main()
{
    int x = 7;
    assert (x==5); //assert sẽ lỗi nhưng vì đã định nghĩa NDEBUG nên chương trình vẫn chạy bình thường
    return 0;
}
```