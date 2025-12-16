# [STORAGE CLASSES]()

Trong C, **storage classes** định nghĩa vòng đời, phạm vi và khả năng hiển thị của các biến. Chúng chỉ định nơi một biến được lưu trữ, thời gian giá trị của nó được giữ lại và cách thức truy cập, giúp chúng ta theo dõi sự tồn tại của một biến cụ thể trong suốt quá trình thực thi chương trình.

### Trong ngôn ngữ lập trình C, có **bốn lớp `storage classes`**:

## ***1. AUTO:***
- Đây là lớp lưu trữ mặc định cho tất cả các biến được khai báo bên trong một hàm hoặc một khối lệnh. Các biến kiểu `auto` chỉ có thể được truy cập trong phạm vi khối lệnh/hàm mà chúng được khai báo chứ không thể truy cập bên ngoài (phạm vi này xác định phạm vi hoạt động của chúng).
- Thuộc tính của biến `auto`:
  - Phạm vi: local (trong block `{ }`)
  - Giá trị mặc định: garbage value
  - Vị trí bộ nhớ: RAM
  - Thời hạn sử dụng:  Cho đến khi hết phạm vi hoạt động.
- VD:
```c
#include <stdio.h>

int main() {
  
    // Tham số `auto` ở đây là tùy chọn, vì đây là lớp lưu trữ mặc định
    auto int x = 10;  
    printf("%d", x); // output: 10
    return 0;
}
```
- **Giải thích:** Từ khóa `auto` được sử dụng để khai báo một biến cục bộ với chế độ lưu trữ tự động. Tuy nhiên, trong C, **các biến cục bộ mặc định đều là `auto`**, vì vậy việc chỉ định `auto` là tùy chọn.

- Từ khóa `auto` không **được sử dụng trước các hàm** vì **hàm không bị giới hạn trong phạm vi khối**.
---

## ***2. STATIC:***
- Lớp lưu trữ này được sử dụng để khai báo các biến tĩnh có thuộc tính giữ nguyên giá trị ngay cả khi chúng nằm ngoài phạm vi! Do đó, các biến tĩnh giữ nguyên giá trị của lần sử dụng cuối cùng trong phạm vi của chúng.
- Dùng để **giữ giá trị của biến giữa các lần gọi hàm** hoặc **giới hạn phạm vi của biến/hàm trong file**.
  - Phạm vi: local
  - Giá trị mặc định:  Không
  - Vị trí bộ nhớ: RAM
  - Thời hạn:  Cho đến khi kết thúc chương trình.

### ***a. Static biến cục bộ(static local variable):***
- Phạm vi: trong hàm
- Vòng đời: tồn tại suốt chương trình
- Khởi tạo: chỉ 1 lần

```c
void counter() {
    static int count = 0;
    count++;
    printf("%d\n", count); // gọi 3 lần sẽ in ra : 1 2 3
}
```

### ***b.Static biến toàn cục(static global variable):***
- Chỉ dùng được trong **file hiện tại**, không export ra file khác.
```c
static int globalVar = 5;
```

### ***c. Static hàm(Static function):***
- Hàm chỉ dùng trong file hiện tại.
```c
static void helper() { ... }
```

## ***3. REGISTER:***
- Storage classes này khai báo các biến `register(thanh ghi)` có chức năng tương tự như các biến tự động. Sự khác biệt duy nhất là trình biên dịch cố gắng lưu trữ các biến này trong **thanh ghi** của bộ vi xử lý nếu có **thanh ghi trống**, do đó tốc độ xử lý nhanh hơn nhiều so với bất kỳ biến nào khác.
- Thuộc tính của các đối tượng thuộc ***storage classes register***:
  - **Phạm vi:**  Địa phương
  - **Giá trị mặc định:**  Garbage value
  - **Vị trí bộ nhớ:**  Thanh ghi trong CPU hoặc RAM
  - **Thời hạn sử dụng:**  Cho đến khi hết phạm vi hoạt động.
- ***Lưu ý:* Trình biên dịch có thể bỏ qua đề xuất này dựa trên các thanh ghi có sẵn.**
- Gợi ý compiler lưu biến trong **thanh ghi CPU** để truy cập nhanh hơn.
  - Compiler có thể bỏ qua gợi ý này.
  - Không thể lấy địa chỉ của biến register.
```c
#include <stdio.h>

int main() {
  
    // Đề xuất lưu trữ trong thanh ghi
    register int i;  
    for (i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    return 0;
}
```
OUTPUT: 
```
0 1 2 3 4
```
***Giải thích:*** Từ khóa `register` gợi ý việc lưu trữ biến trong một thanh ghi để truy cập nhanh hơn, nhưng trình biên dịch có thể không phải lúc nào cũng tuân thủ yêu cầu này tùy thuộc vào số lượng thanh ghi CPU có sẵn.

## ***4. EXTERN:***
- Extern storage class dùng để **khai báo** một biến được định nghĩa ở file khác chứ không phải trong cùng một khối lệnh nơi nó được sử dụng. Về cơ bản, giá trị được gán cho nó trong một khối lệnh khác và giá trị này cũng có thể bị ghi đè/thay đổi trong một khối lệnh khác.

- Ngoài ra, một biến toàn cục thông thường cũng có thể được khai báo là biến ngoại tuyến bằng cách đặt từ khóa `extern` trước phần khai báo/định nghĩa của nó trong bất kỳ hàm/khối nào.

- Không cấp bộ nhớ, chỉ “nói” rằng biến tồn tại ở nơi khác.

Thuộc tính của các đối tượng thuộc **storage classes extern**
- Phạm vi: global
- Giá trị mặc định: 0
- Vị trí bộ nhớ: RAM
- Thời hạn: Cho đến khi chương trình kết thúc.

VD:

**printVar.c**
```c
int globalVar;
```

Một tập tin khác khai báo biến này là **extern static**, cho biết nó đã được khai báo trong một tập tin khác. Sau đó, tập tin này in ra biến đó.

**main.c**
```c
#include <stdio.h>

// Global variable
int globalVar = 100;  

void printGlobalVar();

int main() {
  
    // Prints: Global variable is: 100
    printGlobalVar(); 
    return 0;
}
```

Để chạy chương trình này, chúng ta phải biên dịch cả hai tập tin cùng nhau để **main.c** có thể nhận được định nghĩa của biến `globalVar` . Chúng ta sử dụng lệnh sau cho GCC:
```
gcc main.c printVar.c -o main
```

### **Bảng tóm tắt:**
| Storage Class | Scope | Lifetime | Storage | Default Value | Note |
|---------------|--------|-----------|----------|----------------|------|
| `auto` | within block | end of block | stack | garbage | mặc định |
| `register` | within block | end of block | CPU register | garbage | không lấy địa chỉ |
| `static` (local) | within block | entire program | data segment | 0 | giữ giá trị |
| `static` (global) | file | entire program | data segment | 0 | chỉ dùng trong file |
| `extern` | global | entire program | nơi định nghĩa | 0 | chỉ khai báo |


## ***5. VOLATILE:***
- `volatile` **không phải storage class**, mà là **type qualifier** (bộ định tính kiểu), giống như `const`.
- `volatile` báo cho compiler rằng giá trị của biến có thể thay đổi bất ngờ, không phải do code trong chương trình thay đổi mà nội dung của nó có thể thay đổi bất cứ lúc nào từ một thiết bị ngoại vi nào đó.

- Chúng ta có thể sử dụng  **từ khóa `volatile`** cho nhiều mục đích khác nhau, chẳng hạn như khai báo các biến toàn cục, trình xử lý tín hiệu, các biến giữa các luồng dùng chung, v.v. Khi một biến được khai báo là volatile, nó báo cho trình biên dịch biết:
  - Trình biên dịch không được giả định rằng giá trị của biến không thay đổi giữa các lần truy cập, vì vậy nó phải đọc giá trị từ bộ nhớ mỗi khi biến được sử dụng.
  - Trình biên dịch không được sắp xếp lại các lệnh theo cách làm thay đổi thứ tự truy cập của biến volatile.

Cú pháp sử dụng từ khóa `volatile` trong C
```c
volatile dataType varName;
```

### ***a. Khi nào cần dùng `volatile`?***
Ba trường hợp kinh điển:

#### **a1. Biến bị thay đổi bởi interrupt (ISR):**
```c
volatile int flag;

void ISR() {
    flag = 1; // thay đổi ngoài luồng chính
}
```

#### **a2. Biến dùng trong đa luồng:**
```c
volatile int stop = 0;

while (!stop) {
    // thread khác có thể thay đổi stop
}
```

#### **a3. Truy cập thanh ghi phần cứng:**
```c
#define STATUS (*(volatile unsigned int*)0x40001000)
```

### ***b. `volatile` kết hợp với các storage classes:***

#### **b1. `volatile` + `auto`:** Biến cục bộ bình thường nhưng không được tối ưu hóa.
```c
void func() {
    volatile int x = 0;
}
```
*Ý nghĩa:* Compiler phải đọc `x` từ RAM mỗi lần dùng.

#### **b2. `volatile` + `static`:** 
```c
static volatile int flag = 0;
```

*Ý nghĩa:*
- `static` → biến tồn tại suốt chương trình, lưu ở data segment
- `volatile` → không được tối ưu hóa, phải đọc lại mỗi lần

*Ứng dụng:* Biến được ISR thay đổi, nhưng main loop đọc.
```c
static volatile int ready = 0;

void ISR() {
    ready = 1;
}

int main() {
    while (!ready) { } // phải volatile để không bị tối ưu thành vòng lặp vô hạn
}
```

#### **b3. `volatile` + `extern`:** Dùng khi biến được định nghĩa ở file khác và có thể thay đổi bất ngờ.
File A:

```c
volatile int sensorValue = 0;
```
File B:

```c
extern volatile int sensorValue;
```
*Ý nghĩa:* Biến toàn cục có thể bị ISR hoặc phần cứng thay đổi.

#### **b4. `volatile` + `register`:** Không hợp lệ

*Lý do:*
- `register` yêu cầu compiler không lưu biến trong RAM
- `volatile` yêu cầu compiler phải đọc biến từ RAM mỗi lần
Hai yêu cầu mâu thuẫn → compiler báo lỗi.


### Tóm tắt kết hợp `volatile` với **storage classes:**

|Storage class|Kết hợp với volatile|Ý nghĩa|
|-------------|--------------------|-------|
|`auto`|✅ Hợp lệ|Biến cục bộ không tối ưu hóa|
|`static`|✅ Rất quan trọng|Biến toàn chương trình nhưng phải đọc lại mỗi lần|
|`extern`|✅ Hợp lệ|Biến toàn cục ở file khác, có thể thay đổi bất ngờ|
|`register`|❌ Không hợp lệ|Mâu thuẫn: register ≠ RAM|