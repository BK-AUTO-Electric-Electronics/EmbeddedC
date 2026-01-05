# Phân tích thiết kế
## 1. Tổng quan thiết kế hệ thống

- Hệ thống được thiết kế nhằm mô phỏng việc quản lý trạng thái các module trong ô tô, tương tự các ECU (Electronic Control Unit) trong hệ thống xe hơi hiện đại.

- Mỗi module đại diện cho một chức năng:

    Động cơ (Engine ECU)

    Phanh ABS

    Cảm biến nhiệt độ

    ...

- Hệ thống cho phép:

1. Thêm / xóa module động

2. Quản lý trạng thái module (ON / OFF / ERROR / WARNING)

3. Điều khiển module bằng con trỏ hàm

4. Xử lý lỗi không làm sập chương trình bằng setjmp / longjmp

5. Thiết kế tập trung vào:

6. Tối ưu bộ nhớ

7. Tính mở rộng

8. Mô phỏng kiến trúc Embedded / Automotive


## 2. Thiết kế dữ liệu Module (Struct & Union)
### 2.1 Struct Module
```c
typedef struct {
    uint8_t id;
    char name[12];
    uint8_t status;

    ModuleAction on;
    ModuleAction off;
    ModuleAction fault;
    ModuleAction check;
} Module;
```
- Phân tích thiết kế:
```
|Thành phần	    |      Lý do sử dụng                     
|uint8_t id	    |      ID module nhỏ → tiết kiệm bộ nhớ    
|char name[12]	|      Tên module cố định, tránh cấp phát động
|uint8_t status	|      Lưu trạng thái bằng bitmask
|ModuleAction	|      Con trỏ hàm → đa hình hành vi
```
### 2.2 union
```c
typedef union {
    uint8_t all;
    struct {
        uint8_t on      : 1;
        uint8_t error   : 1;
        uint8_t warning : 1;
    } bits;
} ModuleStatus;
```
Lý do dùng union:

Cho phép truy cập nhanh từng bit

Đồng thời vẫn có thể thao tác toàn bộ byte

Phù hợp với hệ thống nhúng, CAN frame, register

## 3. Thiết kế quản lý trạng thái bằng Bitmask
### 3.1 Định nghĩa bitmask
```c
#define STATUS_ON      (1 << 0)
#define STATUS_ERROR   (1 << 1)
#define STATUS_WARNING (1 << 2)
```
Phân tích:

1 byte (uint8_t) có thể chứa tối đa 8 trạng thái

Dễ mở rộng trong tương lai

Thao tác bit nhanh, hiệu quả

### 3.2 Các thao tác bitmask
```c
status |= STATUS_ON;        // bật
status &= ~STATUS_ON;       // tắt
status & STATUS_ERROR;      // kiểm tra lỗi
```

## 4. Thiết kế quản lý danh sách module (Dynamic Memory)
### 4.1 Mảng động module
```c
Module *module_list;
size_t module_count;

Lý do:

Số lượng module không cố định

Có thể thêm / xóa module trong runtime

Phù hợp hệ thống mô phỏng ECU
```
### 4.2 Cấp phát động
```c
module_list = realloc(module_list,
                      (module_count + 1) * sizeof(Module));
```
Ưu điểm:

Không lãng phí bộ nhớ

Dễ mở rộng hệ thống

## 5. Thiết kế điều khiển module bằng Function Pointer
### 5.1 Định nghĩa con trỏ hàm
```c
typedef void (*ModuleAction)(Module *);
```
Lý do thiết kế:

Mỗi module có hành vi riêng

Không dùng if / switch cứng

Mô phỏng đa hình trong C

### 5.2 Gán hành vi cho module
```c
module->on    = engine_on;
module->off   = engine_off;
module->fault = engine_fault;
module->check = engine_check;


➡ Module chỉ gọi:

module->on(module);
```

➡ Không quan tâm chi tiết xử lý bên trong

## 6. Thiết kế xử lý lỗi bằng setjmp / longjmp
### 6.1 Vấn đề cần giải quyết

Trong hệ thống ô tô:

Một module lỗi không được làm sập toàn hệ thống

Cần quay về trạng thái an toàn

### 6.2 Giải pháp
```c
jmp_buf env;

if (setjmp(env) == 0) {
    module->check(module);
} else {
    handle_error();
}

Khi xảy ra lỗi:
longjmp(env, 1);
```

➡ Hệ thống nhảy về điểm an toàn, tiếp tục chạy

## 7. Thiết kế phân tách module theo file
```
File	                   |    Chức năng
main.c	                   |    Điều khiển luồng chính
module_manager.c	       |    Thêm / xóa / quản lý module
bitmask_utils.c            |    Xử lý trạng thái
function_handler.c	       |    Hành vi module
error_handler.c	           |    Xử lý lỗi
```
➡ Tuân thủ Single Responsibility Principle

## 8. Flow tổng quát hệ thống
```
Start
  ↓
Init system
  ↓
Add modules
  ↓
Check module status
  ↓
Error?
  ├─ No → Continue
  └─ Yes → longjmp → Safe state
  ↓
End
```