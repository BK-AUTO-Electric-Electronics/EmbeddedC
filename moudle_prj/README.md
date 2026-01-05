
1. **Biên dịch chương trình**
   Dùng Makefile hoặc GCC để biên dịch các file nguồn:

   ```bash
   mingw32-make        # trên Windows
   make                # trên Linux/macOS
   ```

   File thực thi sẽ được tạo ra (Windows: `app.exe`, Linux: `app`).

2. **Chạy chương trình**

   ```bash
   ./app       # Linux/macOS
   app.exe     # Windows
   ```

3. **Nhập thông tin module**
   Chương trình sẽ yêu cầu nhập ID và tên của module mới, ví dụ động cơ, ABS, đèn,…

4. **Gán hành động cho module**
   Mỗi module sẽ có 3 chức năng chính:

   * `on` → bật module
   * `off` → tắt module
   * `check` → kiểm tra trạng thái (OK / WARNING / ERROR)

5. **Theo dõi trạng thái**

   * Module bật/tắt và các cảnh báo lỗi được lưu bằng **bitmask**.
   * Nếu xảy ra lỗi, chương trình sử dụng **setjmp/longjmp** để nhảy về trạng thái an toàn mà không dừng toàn bộ hệ thống.

6. **Dọn dẹp**
   Khi muốn xóa file thực thi:

   ```bash
   mingw32-make clean   # Windows
   make clean           # Linux/macOS
   ```

---
