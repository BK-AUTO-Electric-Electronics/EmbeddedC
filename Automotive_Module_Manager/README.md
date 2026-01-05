# [Hệ Thống Quản Lý Module Ô Tô (Automotive Module Manager)]()
### Dự án này mô phỏng hệ thống quản lý các thiết bị điện tử trên ô tô (ECU) sử dụng ngôn ngữ C. Hệ thống áp dụng các kỹ thuật lập trình nâng cao như quản lý bộ nhớ động, thao tác bit (Bitmask) và cơ chế xử lý lỗi phi cục bộ (Non-local jumps).

## **1. Tính năng chính:**
- **Quản lý danh sách động:** Thêm/Xóa các module (Động cơ, Phanh, Điều hòa...) bằng `malloc` và `realloc`.

- **Tối ưu trạng thái:** Sử dụng **Bitmask** để quản lý các trạng thái ON/OFF, Lỗi (Error), Cảnh báo (Warning) chỉ trong 1 byte.

- **Cơ chế an toàn (Safe Mode):** Sử dụng `setjmp` và `longjmp` để tự động đưa hệ thống về trạng thái an toàn khi phát hiện lỗi nghiêm trọng.

- **Kiểm tra trạng thái:** Cung cấp các hàm truy vấn trạng thái module theo thời gian thực.

## **2. Cấu trúc thư mục:**
```Plaintext
├── Makefile             # File cấu hình biên dịch
├── main.c               # Luồng điều khiển chính của chương trình
├── module_manager.c/h   # Quản lý danh sách mảng động các module
├── bitmask_utils.c/h    # Các hàm thao tác logic Bitwise
├── function_handler.c/h # Các hàm điều khiển Bật/Tắt/Cảnh báo
└── error_handler.c/h    # Cơ chế xử lý lỗi khẩn cấp (Setjmp/Longjmp)
```
## **3. Hướng dẫn cài đặt và chạy:**
### Tiền đề
- Máy tính đã cài đặt GCC Compiler.

- Công cụ Make (Dành cho Windows: MinGW hoặc Linux: Build-essential).

### Các bước thực hiện
#### **1. Biên dịch chương trình:** Mở Terminal/Command Prompt tại thư mục dự án và gõ:

```Bash
make
```
*Lệnh này sẽ tạo ra file thực thi `app.exe`.*

#### **2. Chạy chương trình:** Sau khi biên dịch thành công, chạy lệnh:

```Bash
make run
```
*Hoặc chạy trực tiếp file: `./app.exe`*

#### **3. Dọn dẹp các file tạm:** Để xóa file thực thi và các file đối tượng sau khi kiểm tra:

```Bash
make clean
```
## **4. Kịch bản mô phỏng trong chương trình**
Khi chạy, chương trình sẽ thực hiện các bước sau:

1. Khởi tạo 5 module hệ thống.

2. Bật module Động cơ và Phanh ABS.

3. Phát hiện cảnh báo nhiệt độ (Hiển thị WARNING).

4. Xóa module Điều hòa (Mô phỏng bảo trì).

5. **Giả lập lỗi phanh nghiêm trọng:** Hệ thống sẽ kích hoạt lệnh `longjmp`, thoát khỏi luồng thực thi bình thường và nhảy vào chế độ **SAFE MODE** để tắt toàn bộ các module đang chạy nhằm đảm bảo an toàn.

## **5. Lưu ý kỹ thuật:**
- **Bitmask:** Trạng thái lỗi được ưu tiên kiểm tra hàng đầu.

- **Memory:** Luôn gọi `cleanup_modules()` cuối chương trình để giải phóng bộ nhớ, tránh rò rỉ (Memory leak).