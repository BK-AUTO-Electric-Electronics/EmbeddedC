# project_design.md

## 1. Mô tả project
Project mô phỏng hệ thống quản lý các module trong ô tô (ví dụ: động cơ, phanh, đèn, điều hòa, cảm biến).  
Mỗi module có trạng thái: ON (BẬT), LỖI, CẢNH_BÁO.  
Chương trình chạy theo các chức năng: bật/tắt, check cảnh báo, thêm/xóa module, xử lý lỗi và quay về trạng thái an toàn.

## 2. Phân tích thiết kế

### 2.1. Cấu trúc dữ liệu
- `Module` (struct): gồm `id`, `status`, `ops`
  - `id`: định danh module
  - `status`: trạng thái module 
  - `ops`: các hàm điều khiển gồm on/off/check

- Danh sách module: `module_list` là mảng động trên heap, quản lý bằng:
  - `module_count`: số phần tử đang dùng
  - `module_capacity`: dung lượng cấp phát 

### 2.2. Quản lý danh sách bằng cấp phát động
- Thêm module: dùng `realloc` tăng dung lượng khi cần
- Xóa module: 
  - `module_list[i] = module_list[module_count - 1]`
  - `module_count--`


## 3. bitmask, function pointer, setjmp/longjmp

### 3.1. Bitmask + Union (status)
- Dùng 3 bit trong `status.raw`:
  - `STATUS_ON`
  - `STATUS_LOI`
  - `STATUS_CANHBAO`

- Dùng `union ModuleStatus`:
  - `raw`: thao tác bit nhanh bằng `|`, `&`, `~`
  - `bit.on/bit.loi/bit.canhbao`


### 3.2. Function pointer 
Mỗi module có `ops` gồm 3 con trỏ hàm:
- `ops.on`  -> bật module
- `ops.off` -> tắt module
- `ops.check` -> kiểm tra (OFF mà check thì set CẢNH_BÁO)

Khi điều khiển:
- `m->ops.on(m);`
- `m->ops.off(m);`
- `m->ops.check(m);`

### 3.3. setjmp/longjmp (xử lý lỗi)
- `setjmp(safe_point)` đặt điểm an toàn trong `main`.
- Khi module bị LỖI nghiêm trọng, gọi:
  - `longjmp(safe_point, 1);`
- Chương trình quay lại điểm an toàn và gọi `safe_reset()`:
  - reset trạng thái toàn bộ module về mặc định (OFF, không LỖI, không CẢNH_BÁO).

 ## 4. Flowchart chương trình

Flowchart chương trình được mô tả theo các bước sau:

- Tạo danh sách module
- Bật một số module
- Kiểm tra module (nếu đang OFF thì cảnh báo)
- Thêm / xóa module
- Khi module bị lỗi nghiêm trọng
- Thực hiện safe reset bằng longjmp
- Kết thúc chương trình
