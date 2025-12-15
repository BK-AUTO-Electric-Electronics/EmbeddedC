# [MACRO]()

---

**Macro** hiểu đơn giản là tên do người viết chương trình đặt.

### Các loại **macro**:

## **_1. OBJECT - LIKE MACRO:_** Macro hằng số

- Định nghĩa 1 hằng số, giá trị cố định

- Khi đó quản lí code sẽ dễ hơn, khi cần sửa chỉ cần sửa trên dòng `#define`

```c
#define PI 3.141
```

## **_2. FUNCTION - LIKE MACRO:_** Macro dạng hàm

- Định nghĩa đoạn tạo mã giống như hàm nhưng không tạo overhead gọi hàm.

```c
#define SQUARE(x) ((x)*(x))
```

2 dạng trên đều dùng bộ tiền xử lí: `#define`

## **_3. CONDITIONAL COMPLILATION MACRO:_**

- Dùng để biên dịch có điều kiện, giúp code chạy trên nhiều vi điều khiển khác nhau.

- Bao gồm:

| DIRECTIVE (CHỈ THỊ) | CHỨC NĂNG                                         |
| ------------------- | ------------------------------------------------- |
| `#ifdef`            | Trả về giá trị TRUE nếu macro đã được định nghĩa  |
| `#endif`            | Kết thúc điều kiện xử lí                          |
| `#if`               | Kiểm tra điều kiện nếu biên dịch là đúng          |
| `#else`,`#elif`     | Sẽ được gọi khi điều kiện trong macro `#if` FALSE |

### VD:

```c
#if (MCU == STM32F1) //Conditional complilation với macro đc định nghĩa STM32F1
#elif (MCU == STM32F7) //Conditional complilation với macro đc định nghĩa STM32F7
#else //Conditional complilation với macro còn lại
#endif
```

## **_4. INCLUDE GUARD MACRO_**

- Ngăn việc `include` nhiều lần 1 file header.

- Là cơ chế để nếu đã `include` 1 header file rồi thì những lần `include` sau sẽ không ảnh hưởng gì. Hay sử dụng 2 direct là `#ifndef`,`#define` và `#endif`.

```c
#ifndef _MY_HEADER_H_ //Nếu macro _MY_HEADER_H_ chưa được định nghĩa
#define _MY_HEADER_H_ //Thì macro _MY_HEADER_H_ được định nghĩa
#endif //Kết thúc macro điều kiện
```

## **_5. Macro nhiều dòng:_**

- Để xuống dòng trong macro thì bạn sẽ dùng ký tự `\`. Như trong ví dụ sau đây chúng ta sẽ sửa lại đoạn code trên 1 chút để nó thành 1 macro có nhiều dòng nhằm cho thấy tác dụng của kí tự `\`

```c
#define PRINT_SUM(a, b)        \
    printf("a = %d\n", a);     \
    printf("b = %d\n", b);     \
    printf("Sum = %d\n", a+b);
\\ '\' là toán tử tiếp tục, để xuống dòng dùng toán tử '\' để nối các dòng lại với nhau nếu các dòng code quá dài.
```

Sử dụng:

```c
PRINT_SUM(3, 5);
```

Kết quả:

```c
a = 3
b = 5
a + b = 8
```

## **_6. VARIADIC MACRO:_**

- Có thể truyền lượng tham số không xác định như khi sử dụng `stdarg`.

- Cú pháp: `#define MACRO_NAME(...)`

- Dấu ‘…’ cho phép truyền nhiều tham số

- `__VA_ARGS__` : dùng để là mã định danh thay thế để chèn các đối số bổ sung. `__VA_ARGS__` được thay thế bằng tất cả các đối số khớp với dấu ‘…’ bao gồm cả dấu phẩy. Khi không truyền thêm đối số sau dấu phẩy thì dùng cú pháp `##__VA_ARGS__` để loại bỏ dấu phẩy thừa và nối chuỗi.

- VD:

  ```c
  #include <stdio.h>
  #include <stdarg.h> //Để sử dụng các macro trong stdarg.h

  #define Sum(...) Tong(__VA_ARGS__)

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

## **_7. X-MACROS:_**

**_X-Macros_** là một phương pháp sử dụng `#define` để tạo danh sách macro có thể mở rộng và tái sử dụng trong nhiều ngữ cảnh khác nhau. Ưu điểm của **_X-Macros_**:

- Dễ bảo trì:** Chỉ cần sửa đổi **một danh sách duy nhất**, tất cả các phần còn lại sẽ tự động cập nhật.
- **Hạn chế lỗi:** Tránh việc quên cập nhật các switch-case hoặc bảng ánh xạ.
- **Tái sử dụng dễ dàng:** Có thể dùng cùng một danh sách cho nhiều mục đích khác nhau (enum, chuỗi, mảng, v.v.)

**_Định nghĩa các phần tử của danh sách:_**

```c
#define VARIABLES \
    X(value1, 1)  \
    .
    .
    .  \
    X(valueN, N)
```

**_Mở rộng danh sách để tạo ra các đoạn khai báo hoặc câu lệnh:_**

```c
#define X(name) int name;
    VARIABLES
#undef X
```

**_Ví dụ kinh điển: Enum + String table_**

```c
// Định nghĩa danh sách lỗi bằng macro
// file: colors.x
#define COLOR_LIST \
    X(RED)         \
    X(GREEN)       \
    X(BLUE)

// Tạo enum từ danh sách
typedef enum {
#define X(name) name,
    COLOR_LIST
#undef X
} Color;

// 3. Tạo bảng string tương ứng
const char* ColorName[] = {
#define X(name) #name, // #name : giá trị X[name] là name
    COLOR_LIST
#undef X
};

// 4. Sử dụng
int main()
{
    printf("%s\n", ColorName[GREEN]); // OUTPUT: GREEN
}
```

**_VD khác: Enum + giá trị + mô tả_**

```c
#define ERROR_LIST \
    X(ERR_OK, 0, No error) \
    X(ERR_FAIL, -1, Failed) \
    X(ERR_BUSY, -2, Busy)

// Tạo enum
#define ERROR_LIST \
    X(ERR_OK, 0, No error) \
    X(ERR_FAIL, -1, Failed) \
    X(ERR_BUSY, -2, Busy)

// Tạo enum
typedef enum {
#define X(name, value, desc) name = value, // // gán các hằng số 'name' bằng giá trị 'value'
    ERROR_LIST
#undef X
} ErrorCode;

// Tạo bảng mô tả
const char* ErrorDesc[] = {
#define X(name, code, desc) #desc,
    ERROR_LIST
#undef X
};

int main() {
    int a = ERR_FAIL; // a = -1
    printf("%s\n", ErrorDesc[ERR_OK]); //OUTPUT: No error
    printf("%d", a); // OUTPUT: -1
}
```

