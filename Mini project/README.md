# MINI PROJECT: QUẢN LÝ TRẠNG THÁI MODULE TRONG HỆ THỐNG Ô TÔ


## Mục tiêu
- Thiết kế và triển khai một hệ thống quản lý trạng thái các module trong ô tô, sử dụng các kỹ thuật lập trình C quan trọng như bitmask, struct & union, function pointer, setjmp/longjmp, và cấp phát động (malloc/free).

 - Giúp hiểu cách quản lý và điều khiển các module như động cơ (ECU), phanh (ABS), đèn, điều hòa, cảm biến nhiệt độ trong xe hơi.

## Cấu trúc thư mục
Automotive_Module_Manager/
- main.c
- module_manager.c / module_manager.h
- bitmask_utils.c / bitmask_utils.h
- function_handler.c / function_handler.h
- error_handler.c / error_handler.h

## Cách chạy

gcc main.c module_manager.c bitmask_utils.c function_handler.c error_handler.c -o app

./app

