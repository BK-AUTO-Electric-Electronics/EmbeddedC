### ***e. CON TRỎ ĐẾN HÀM (FUNCTION POINTER):***
---
- Con trỏ hàm  là một loại con trỏ lưu trữ địa chỉ của một hàm, cho phép truyền hàm làm đối số và gọi hàm một cách động. 
- VD:
    ```c
    #include <stdio.h>

    int add(int a, int b) {
        return a + b;
    }

    int main() {
  
        // Khai báo 1 con trỏ hàm khớp với hàm add()
        int (*fptr)(int, int);

        // gán giá trị cho add()
        fptr = & add;

        // Gọi hàm qua con trỏ
        printf("%d", fptr(10, 5));
        return 0;
    }
    ```
- OUTPUT:
    ```c
    15
    ```

- Khai báo con trỏ hàm: `return_type (*pointer_name)(parameter_types);`

- Khởi tạo: 
    - Con trỏ hàm sau đó được khởi tạo bằng cách gán địa chỉ của hàm đó:
    `pointer_name = &function_name`
    - Chúng ta cũng có thể bỏ qua địa chỉ của toán tử vì chính tên hàm hoạt động như một con trỏ hàm hằng:
    `pointer_name = function_name;`

### Function pointer như tham số (callback):
- VD:
    ```c
    #include <stdio.h>

    // Tạo 1 hàm cộng đơn giản
    int add(int a, int b) {
    return a + b;
    }

    // Tạo 1 hàm trừ đơn giản
    int subtract(int a, int b) {
    return a - b;
    }

    void calc(int a, int b, int (*op)(int, int)) {
    printf("%d\n", op(a, b));
    }

    int main() {
        calc(10, 5, add); // cộng a và b
  	    calc(10, 5, subtract); // Lấy a trừ b
        return 0;
    }
    ```
- OUTPUT:
    ```
    15
    5
    ```

### Mảng function pointer
- VD:
    ```c
    #include <stdio.h>

    int add(int a, int b) {
        return a + b;
    }
    int sub(int a, int b) {
        return a - b;
    }
    int mul(int a, int b) {
        return a * b;
    }
    int divd(int a, int b) {
        if(b!=0)
            return a / b;
        else
            return -1;
    }

    int main() {
    
        int (*farr[])(int, int) = {add, sub, mul, divd};
        int x = 10, y = 5;

        printf("Sum: %d\n", farr[0](x, y)); //add
        printf("Difference: %d\n", farr[1](x, y));//sub
        printf("Product: %d\n", farr[2](x, y));//mul
        printf("Divide: %d", farr[3](x, y));//divd

        return 0;
    }   

    ```
- OUTPUT:
    ```c
    Sum: 15
    Difference: 5
    Product: 50
    Divide: 2
    ```

### Typedef cho function pointer
- VD: 
    ```c
    typedef int (*Func)(int, int);

    int add(int a, int b) {
        return a + b;
    }

    int main() {
        Func f = add;
        printf("%d\n", f(2, 3));// kết quả là 5
    }
    ```

---

### ***f. CON TRỎ VOID (VOID POINTER):***
---
- là con trỏ không có kiểu (typeless pointer). Nó có thể **trỏ tới bất kỳ kiểu dữ liệu nào**, nhưng **không thể dereference trực tiếp** vì nó không biết kích thước kiểu dữ liệu.
- **VD:** Chương trình sau không biên dịch được.
```c
#include <stdio.h>

int main()
{
    int a = 10;
    void* ptr = &a;
    printf("%d", *ptr);

    return 0;
}
```
- OUTPUT:
```
Compiler Error: 'void*' is not a pointer-to-object type
```

- **VD:** Dùng void pointer để viết hàm swap tổng quát
```c
#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    char temp;
    char *p = a;
    char *q = b;

    for (size_t i = 0; i < size; i++) {
        temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}


int main()
{
    int x = 10, y = 20;
    swap(&x, &y, sizeof(int));
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
```
- OUTPUT:
```
x = 20, y = 10
```
---


### ***g. POINTER TO POINTER:***
---
#### **(+) Con trỏ đến con trỏ (Con trỏ kép) (Double pointer)**
- Trong ngôn ngữ C, **con trỏ kép** là **loại con trỏ lưu trữ địa chỉ của một con trỏ khác**. Con trỏ thứ nhất được dùng để lưu trữ địa chỉ của biến, và con trỏ thứ hai được dùng để lưu trữ địa chỉ của con trỏ thứ nhất. Vì vậy, chúng còn được gọi là **con trỏ đến con trỏ**.
- VD: 
```c
#include <stdio.h>

int main()
{

    int var = 10;

    int *ptr1 = &var; // con trỏ đến số nguyên

    int **ptr2 = &ptr1; // con trỏ đến con trỏ(con trỏ kép)

    printf("var: %d\n", var);
    printf("*ptr1: %d\n", *ptr1);
    printf("**ptr2: %d", **ptr2);

    return 0;
}
```
- OUTPUT:
```
var: 10
*ptr1: 10
**ptr2: 10
```
- ***Giải thích:*** Trong đoạn mã này, `ptr1` là một con trỏ lưu trữ địa chỉ của biến số nguyên `var` . `ptr2` là một con trỏ kép lưu trữ địa chỉ của con trỏ `*ptr1` . `**ptr2` truy cập vào chính `ptr2` để lấy giá trị của `ptr1` (chính là địa chỉ của `var` ) và sau đó truy cập vào địa chỉ đó để lấy giá trị của chính `var`.
  
#### **Kích thước của con trỏ kép:**
- Kích thước của con trỏ kép cũng giống như kích thước của bất kỳ con trỏ nào khác vì nó cũng lưu trữ địa chỉ.
- VD:
```c
#include <stdio.h>

int main()
{

    // định nghĩa con trỏ đơn và con trỏ kép
    int a = 5;
    int *ptr = &a;
    int **d_ptr = &ptr;

    // Kích thước của con trỏ kép
    printf("%d bytes\n", sizeof(d_ptr));
    
    
    // Kích thước của con trỏ đơn
    printf("%d bytes", sizeof(ptr));

    return 0;
}
```
- OUTPUT
```
4 byte
4 byte
```
- ***Lưu ý: Kết quả đầu ra của đoạn mã trên cũng phụ thuộc vào loại máy đang được sử dụng.***


#### **Tạo mảng 2D động:**
- Con trỏ kép rất hữu ích trong việc tạo mảng 2D có kích thước động, trong đó mỗi hàng có thể có số phần tử khác nhau.
```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m = 2, n = 3;

    // Tạo 1 con trỏ kép
    int **arr;

    // Cấp phát bộ nhớ cho các hàng
    arr = (int **)malloc(m * sizeof(int *));

    // Cấp phát bộ nhớ cho mỗi hàng
    for (int i = 0; i < m; i++)
        arr[i] = (int *)malloc(n * sizeof(int));

    // Khởi tạo 1 số giá trị
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = i * n + j + 1;
        }
    }

    // In mảng
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Giải phóng bộ nhớ đã cấp phát
    for (int i = 0; i < m; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
```
- OUTPUT:
```
1 2 3
4 5 6
```
- **Giải thích :** Mảng 2 chiều là một mảng mà mỗi phần tử về cơ bản là một mảng 1 chiều. Điều này có thể được thực hiện bằng cách sử dụng con trỏ kép. Con trỏ kép trỏ đến phần tử đầu tiên của mảng 2 chiều, và mỗi con trỏ mà nó tham chiếu trỏ đến một mảng 1 chiều được cấp phát động bằng hàm malloc().


#### Truyền mảng chuỗi vào hàm
```c
#include <stdio.h>

// Hàm nhận 1 mảng chuỗi làm đối số
void print(char **arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%s\n", *(arr + i));
}

int main()
{
    char *arr[10] = {"Geek", "Geeks", "Geekfor"};
    print(arr, 3);
    return 0;
}
```

- OUTPUT:
```
geek
geeks
geekfor
```
- **Giải thích :** Mảng chuỗi thường được lưu trữ dưới dạng mảng con trỏ đến chuỗi. Mảng này có thể được truyền vào hàm bằng cách sử dụng con trỏ kép.
  
#### Ứng dụng con trỏ kép trong C:
- Chúng được sử dụng trong việc cấp phát bộ nhớ động cho các mảng đa chiều.
- Chúng có thể được sử dụng để lưu trữ dữ liệu đa cấp như đoạn văn, câu và ngữ nghĩa từ trong tài liệu văn bản.
- Chúng được sử dụng trong cấu trúc dữ liệu để thao tác trực tiếp với địa chỉ của các nút mà không cần sao chép.
- Chúng có thể được sử dụng làm đối số hàm để thao tác với địa chỉ được lưu trữ trong con trỏ cục bộ.


#### Multi-level Pointer
- Cú pháp: 
```c
// Khai báo con trỏ cấp 1
datatype *pointer; 

// Khai báo con trỏ cấp 2
datatype **pointer; 

// Khai báo con trỏ cấp 3
datatype ***pointer; 
.
.
```
- VD:
```c
#include <stdio.h>
// Chương trình C cho chuỗi con trỏ

int main()
{
    int var = 10;

    // Con trỏ cấp 1
    // Khai báo con trỏ đến biến var
    int* ptr1;

    // Con trỏ cấp 2
    // Khai báo con trỏ đến con trỏ '*ptr1'
    int** ptr2;

    // Con trỏ cấp 3
    // Khai báo con trỏ đến con trỏ '*ptr2'
    int*** ptr3;

    // Lưu trữ địa chỉ của biến var đến biến con trỏ ptr1
    ptr1 = &var;

    // Lưu trữ địa chỉ của con trỏ cấp 1 ptr1 đến con trỏ cấp 2 ptr2
    ptr2 = &ptr1;

    // Lưu trữ địa chỉ của con trỏ cấp 2 ptr2 đến con trỏ cấp 3 ptr3
    ptr3 = &ptr2;

    // Hiển thị các giá trị
    printf("Giá trị của biến var = %d\n",var);
    printf("Giá trị của biến var sử dụng con trỏ ptr1 = %d\n",*ptr1);
    printf("Giá trị của biến var sử dụng con trỏ ptr2 = %d\n",**ptr2);
    printf("Giá trị của biến var sử dụng con trỏ ptr3 = %d\n",***ptr3);

    return 0;
}
```
- OUTPUT:
```
Giá trị của biến var = 10
Giá trị của biến var sử dụng con trỏ ptr1 = 10
Giá trị của biến var sử dụng con trỏ ptr2 = 10
Giá trị của biến var sử dụng con trỏ ptr3 = 10
```
---