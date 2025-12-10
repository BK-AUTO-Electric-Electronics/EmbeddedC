# [COMPILER PROCESS]()

---

### - Là quá trình dịch từ mã nguồn từ 1 ngôn ngữ lập trình sang ngôn ngữ mà máy tính có thể hiểu đc.

### - Gồm 4 bước:

## **_Bước 1: PREPROCESSER_**

### - Các chỉ thị tiền xử lí như `#include <thư_viện>`, `#define macro` sẽ được xử lí, các comment sẽ đc loại bỏ; thay thế các **macro**, thay thế các nội dung **file header** vào các vị trí `#include`.

### - Đầu ra quá trình này là **file extended source** (.i/.ii).

## **_Bước 2: COMPLIER_**

### - Complier dịch **file .i** thành **ASSEMBLY CODE**.

### - Chuyển các câu lệnh C thành tập lệnh Assembly phù hợp với cấu trúc vi điều khiển.

## **_Bước 3: ASSEMBLER_**

### - Các **ASSEMBLY CODE** sẽ được convert sang mã máy là các **file .o** (object). Đây là bước liên kết cầu nỗi giữa mã con người có thể đọc và mã mà máy có thể hiểu được.

## **_Bước 4: LINKING_**

### - Thực hiện các link object file lại, cũng như liên kết chúng với các thư viện và kết hợp lại thành 1 file thực thi duy nhất.

### - File thực thi có thể là **file (.exe,…)** thực hiện được trên máy tính hay **file binary (.hex, .bin,…)** để nạp vào vi điều khiển.

### => File cuối cùng chính là **firmware** để nạp vào vi điều khiển.

---
---


