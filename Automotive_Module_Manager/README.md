# Miniproject
## Giải thích cách chạy chương trình
- trong file module_manager.h ta định nghĩa 1 kiểu dữ liệu cấu trúc Module với các thông số ID, tên, và các hành động điều khiển của module, khai báo con trỏ hàm Module Action để thực hiện lệnh điều khiển bật/tắt, kiểm tra, cảnh báo lỗi
- Trong file bitmask_utils.h có 3 hàm để quản lí trạng thái và làm việc với các bit của biến status để có thể thực hiện các hành động điều khiển
- Trong file function_handler.h có các hàm dựa vào trạng thái của các module để thực hiện hành động bật tắt module hay kiểm tra
- Trong file module_manager.c ta có các hàm thêm và xóa module khỏi danh sách và lấy module ra từ danh sách
# Chương trình chạy theo các bước ở file main.c
- B1: Add module vào danh sách với các thông số là ID và tên
- B2: thực hiện các lệnh điều khiển bật tắt với các hàm trong function_handler.handler
- B3: Kiểm tra trạng thái module
- B4: nếu gặp lỗi sẽ trở về trạng thái an toàn