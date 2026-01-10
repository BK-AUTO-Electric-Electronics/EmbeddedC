
---

# Automotive Module Manager – Project Design

## 1. Mô tả project

Hệ thống **Automotive Module Manager** mô phỏng quản lý các module trên ô tô như động cơ, ABS, đèn, điều hòa, cảm biến… Mỗi module có trạng thái **ON/OFF**, cảnh báo hoặc lỗi. Chương trình hỗ trợ:

* Thêm/xóa module động thời gian chạy
* Quản lý trạng thái bằng **bitmask**
* Gán hành động cho module thông qua **function pointer**
* Xử lý lỗi module an toàn bằng **setjmp/longjmp**
* Tối ưu bộ nhớ trạng thái bằng **struct và union**

Mục tiêu: Giúp người dùng quan sát, bật/tắt và kiểm soát trạng thái từng module, mô phỏng cơ chế quản lý ECU trên ô tô thực tế.

---

## 2. Phân tích thiết kế

### 2.1. Struct Module

```c
typedef struct Module {
    int id;
    char name[30];
    status_t status;

    void (*on)(struct Module *);
    void (*off)(struct Module *);
    void (*check)(struct Module *);
} Module;
```

* `id`, `name`: định danh module
* `status`: lưu trạng thái ON, ERROR, WARNING (bitmask)
* Function pointers: gán các hàm bật/tắt/kiểm tra module

### 2.2. Quản lý danh sách module

* Dùng **mảng động** `Module* module_list`
* `module_qty` lưu số lượng module
* Các hàm: `add_module()`, `remove_module()`, `list_modules()`

### 2.3. Bitmask

```c
typedef enum {
    STATUS_ON      = (1U << 0),
    STATUS_ERROR   = (1U << 1),
    STATUS_WARNING = (1U << 2)
} status_flag_t;
```

* ON/OFF, ERROR, WARNING lưu trong 1 byte
* Các hàm helper trong `bitmask_utils.c`:

  * `status_set(status_t *s, status_flag_t f)`
  * `status_clear(status_t *s, status_flag_t f)`
  * `status_check(status_t s, status_flag_t f)`

### 2.4. Function pointer

* Mỗi module gán các hành động:

```c
m->on = turn_on_module;
m->off = turn_off_module;
m->check = check_module;
```

* Giúp gọi hàm **động**, không cần switch-case cho từng module

### 2.5. Xử lý lỗi (setjmp/longjmp)

* Khi module gặp lỗi:

```c
if (status_check(m->status, STATUS_ERROR)) {
    throw_error();  // dùng longjmp
}
```

* Chương trình nhảy về **trạng thái an toàn** mà không dừng toàn bộ hệ thống

---

## 3. Flowchart chương trình (văn bản)

```
          +-------------------------+
          |   Bắt đầu chương trình  |
          +-------------------------+
                    |
                    v
        +-----------------------+
        | Thêm module mới?      | <--+
        +-----------------------+    |
          | Có / Không               |
          v                          |
+----------------------+             |
| Nhập ID, tên module  |             |
+----------------------+             |
          |                          |
          v                          |
+-----------------------+            |
| Gán function pointer  |            |
+-----------------------+            |
          |                          |
          v                          |
+-----------------------+            |
| Bật/Tắt module        |            |
|  - on()               |            |
|  - off()              |            |
+-----------------------+            |
          |                          |
          v                          |
+-----------------------+            |
| Kiểm tra trạng thái   |            |
|  - check()            |            |
+-----------------------+            |
          |                          |
          v                          |
+----------------------+
| Module lỗi?          |
|  - STATUS_ERROR      |
|  - STATUS_WARNING    |
+----------------------+
          |
          v
+----------------------+
| setjmp/longjmp xử lý lỗi |
+----------------------+
          |
          v
     +----------+
     | Kết thúc |
     +----------+
```

---

## 4. Cách sử dụng

1. Biên dịch chương trình với Makefile.
2. Chạy file thực thi (`app.exe` trên Windows).
3. Thêm module, nhập ID và tên.
4. Gán hành động (`on`, `off`, `check`) bằng function pointer.
5. Thực hiện bật/tắt module và kiểm tra trạng thái.
6. Lỗi module sẽ được xử lý bằng setjmp/longjmp, trạng thái an toàn được giữ.

---