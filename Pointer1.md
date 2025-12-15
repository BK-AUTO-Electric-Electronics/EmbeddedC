# [POINTER]()
---
---

## ***1. ĐỊNH NGHĨA, KHỞI TẠO:***
---

- **Con trỏ** là một biến **lưu trữ địa chỉ bộ nhớ** của một biến khác. Thay vì lưu giữ giá trị trực tiếp, nó **lưu giữ địa chỉ nơi giá trị được lưu trữ trong bộ nhớ**. Nó là xương sống của việc thao tác bộ nhớ cấp thấp trong ngôn ngữ C.
- Cú pháp khai báo: `kiểu_dữ_liệu *tên_con_trỏ;`
- Kiểu dữ liệu cho biết kiểu biến mà con trỏ có thể trỏ tới. Ví dụ, `int *ptr;` khai báo một con trỏ đến một số nguyên.
- Việc truy cập trực tiếp vào con trỏ chỉ cho ta địa chỉ được lưu trữ trong con trỏ. Để lấy giá trị tại địa chỉ được lưu trữ trong biến con trỏ, ta sử dụng **`toán tử '*' (hay toán tử giải tham chiếu)`** trong C.
  VD:
    ```c
    #include <stdio.h>

    int main() {
        //Biến thông thường
        int var = 10;
        
        //Biến con trỏ ptr lưu trữ địa chỉ của biến var
        int *ptr = &var;

        //Truy cập trực tiếp vào ptr sẽ cung cấp cho chúng 1 địa chỉ biến var
        printf("%d", ptr);
        return 0;
    }
    ```
  Output:
    ```c
    6422296 //Là địa chỉ lưu trữ biến var, mỗi máy sẽ có 1 địa chỉ khác nhau
    ```


- Con trỏ được khởi tạo bằng cách gán cho nó địa chỉ của một biến bằng **`toán tử địa chỉ (&)`**.
- Cú pháp: `pointer_name = &variable;`
- Việc **khởi tạo con trỏ** đảm bảo rằng nó trỏ đến một vị trí bộ nhớ hợp lệ trước khi sử dụng.
- Bạn cũng có thể khởi tạo một con trỏ thành `NULL` nếu nó chưa trỏ đến bất kỳ biến nào: `int *ptr = NULL;`
  
***Lưu ý : Trước đây, chúng ta đã sử dụng `%d` để in con trỏ, nhưng C cung cấp một định dạng riêng biệt `%p` để in con trỏ.*** 


## ***2. KÍCH THƯỚC CỦA CON TRỎ:***
---

- **Kích thước của con trỏ** trong C phụ thuộc vào **kiến ​​trúc (hệ bit)** của máy, chứ **không phải kiểu dữ liệu mà nó trỏ tới**.

  - Trên hệ thống **32-bit**, tất cả các con trỏ thường chiếm **4 byte**.
  - Trên hệ thống **64-bit**, tất cả các con trỏ thường chiếm **8 byte**.
- Kích thước vẫn không đổi bất kể kiểu dữ liệu ( `int*`, `char*`, `float*`, v.v.). Chúng ta có thể kiểm chứng điều này bằng cách sử dụng **toán tử `sizeof`** .
  
- VD:
    ```c
    #include<stdio.h>

    int main() {
        int *ptr1;
        char *ptr2;
    
        // Tìm kích thước bằng cách sử dụng hàm sizeof()
        printf("%zu\n", sizeof(ptr1));
        printf("%zu", sizeof(ptr2));
    
        return 0;
    }
    ```
### Lý do kích thước của các con trỏ giống nhau là vì chúng lưu trữ địa chỉ bộ nhớ, bất kể kiểu dữ liệu nào. Vì không gian cần thiết để lưu trữ địa chỉ của các vị trí bộ nhớ khác nhau là như nhau, nên bộ nhớ cần thiết cho một kiểu con trỏ sẽ bằng với bộ nhớ cần thiết cho các kiểu con trỏ khác.

## ***3. CÁC PHÉP TOÁN VỚI CON TRỎ:***
---
### ***a. Toán tử lấy địa chỉ `&`:*** Lấy địa chỉ của biến.
```c
int x = 10;
int *p = &x;   // p chứa địa chỉ của x

```

### ***b. Toán tử dereference `*`:*** Lấy giá trị tại địa chỉ mà con trỏ trỏ tới.
```c
int x = 10;
int *p = &x;

printf("%d", *p);   // in ra 10
*p = 20;            // thay đổi giá trị x thành 20

```

### ***c. Phép gán con trỏ:*** Gán địa chỉ cho con trỏ.
```c
int *p;
int x = 5;

p = &x;
```

### ***d. So sánh con trỏ:*** Bạn có thể so sánh hai con trỏ nếu chúng trỏ trong cùng một mảng.
```c
int a[5];
int *p = &a[1];
int *q = &a[3];

if (p < q) { ... }   // hợp lệ
```
Không được so sánh con trỏ trỏ tới hai vùng nhớ không liên quan.

### ***e. Phép cộng/trừ con trỏ:***

#### Cộng con trỏ với số nguyên
```c
int a[5];
int *p = a;   // p = &a[0]

p += 2;    // p trỏ tới a[2] nhảy 2 phần tử chứ không phải 2 byte
p ++; // trỏ sang phần tử tiếp theo
```
- Nếu `int` = 4 byte → p tăng 8 byte.


#### Trừ con trỏ với số nguyên
```c
p -= 1;   // lùi lại 1 phần tử
p --; //quay lại phần tử trước
```


#### Trừ hai con trỏ
- Chỉ hợp lệ khi cả hai con trỏ trỏ trong cùng một mảng.
```c
int a[10];
int *p = &a[7];
int *q = &a[2];

int diff = p - q;   // diff = 5
```

### ***f. Phép truy cập mảng qua con trỏ:***
```c
int a[5] = {1,2,3,4,5};
int *p = a;

printf("%d", p[2]);   // in ra 3
```
---

## ***4. CÁC LOẠI CON TRỎ ĐẶC BIỆT:***
---

### ***a. CON TRỎ TỚI HẰNG (POINTER TO CONSTANT):***
---

- Đây là con trỏ **có thể đổi địa chỉ**, nhưng **không được phép thay đổi giá trị** mà nó trỏ tới.
- VD:
    ```c
    int x = 10;
    int y = 20;

    const int * p = &x;   // p là con trỏ tới hằng
    p = &y;               // OK: đổi địa chỉ
    *p = 15;              // LỖI: không được sửa giá trị qua p
    ```
---
### ***b. HẰNG CON TRỎ (CONSTANT POINTER):***
---

- Đây là con trỏ **không thay đổi địa chỉ**, nhưng **thay đổi được giá trị** mà nó trỏ tới.Nó ***sẽ luôn trỏ đến cùng một địa chỉ bộ nhớ.***
- VD:
    ```c
    int x = 10;
    int y = 20;

    int* const p = &x;   // p là hằng con trỏ
    *p = 15;              // OK: thay đổi giá trị x
    p = &y;               // LỖI: không được đổi địa chỉ của p

    ```
---
### ***c. HẰNG CON TRỎ TỚI HẰNG (CONST POINTER TO CONST):***
---

- **Không đổi được địa chỉ, cũng không đổi được giá trị.**
- VD:
    ```c
    const int * const p = &x;
    ```
---

### ***d. CON TRỎ NULL (NULL POINTER):***
---
- Con trỏ NULL là những **con trỏ không trỏ đến bất kỳ vị trí bộ nhớ nào**. Nó được gán giá trị đặc biệt `NULL`.
- VD:
    ```c
    int *p = NULL; //p không trỏ tới biến nào
    //p không chứa địa chỉ hợp lệ
    // Không được phép dùng toán tử tham chiều (*p)(dereference) vì sẽ gây lỗi runtime (segmentation fault)
    ```

- Trong C, `NULL` thường được định nghĩa là: 
    ```c
    #define NULL ((void*)0)
    // NULL là hằng con trỏ có giá trị 0
    // Không phải số nguyên 0 mà là địa chỉ 0
    ```

***Con trỏ null giúp:***

- **Khởi tạo con trỏ an toàn** (tránh chứa rác)
- **Kiểm tra xem con trỏ đã được cấp phát hay chưa**
- **Phát hiện lỗi** khi hàm trả về con trỏ (ví dụ `malloc` thất bại)
- **Đánh dấu kết thúc danh sách liên kết, cây, mảng con trỏ…**
---

