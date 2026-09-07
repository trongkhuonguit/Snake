# Đồ án Game Snake (C++)

> 🐍 *"Keep Coding, Keep Slithering – Conquer the Maze, Never Bite Your Tail!"*

Đây là bài tập SS004.9 của lớp SS004.F31.CN1.2026.  
Chúc các thành viên trong nhóm (Khương, Lợi, Hiếu) phối hợp thật ăn ý, code mượt mà và hoàn thành xuất sắc đồ án Snake Game đạt điểm tối đa! 🔥✨

---

## Phân công nhiệm vụ thành viên:

| MSSV | Họ và tên | GitHub | Nhiệm vụ đảm nhiệm | Chi tiết công việc |
| :---: | :--- | :---: | :--- | :--- |
| **26730037** | **Nguyễn Trọng Khương** | [@trongkhuonguit](https://github.com/trongkhuonguit) | **Bộ khung cốt lõi (Core Engine)** | - Xây dựng Game Loop chính.<br>- Khởi tạo cấu trúc dữ liệu con rắn.<br>- Xử lý di chuyển, xóa vết đuôi và vẽ rắn.<br>- Bắt phím điều khiển (W, A, S, D). |
| **26730044** | **Trần Minh Lợi** | | **Vẽ Khung & Va chạm (Map & Wall)** | - Viết hàm vẽ khung viền sân chơi (`VeKhung`).<br>- Giới hạn tọa độ bản đồ.<br>- Xử lý sự kiện va chạm tường (Game Over).<br>- Xử lý tự cắn vào đuôi. |
| **26730021** | **Trần Minh Hiếu** | | **Ăn Mồi & Điểm số (Food & Score)** | - Khởi tạo tọa độ quả mồi.<br>- Hàm sinh mồi ngẫu nhiên không trùng thân rắn.<br>- Vẽ mồi ra màn hình.<br>- Xử lý ăn mồi: tăng độ dài rắn và cộng điểm. |

---

## Hướng dẫn chạy dự án

### Yêu cầu môi trường
* Hệ điều hành: Windows
* Trình biên dịch C++ (g++/MinGW) hoặc IDE (Code::Blocks, Dev-C++, VS Code).

---

### Cách 1: Chạy bằng Terminal / PowerShell (Khuyên dùng)

1. Mở **PowerShell** hoặc **Command Prompt** tại thư mục dự án:
   ```powershell
   cd c:\Workspace\Snake-main
   ```

2. Biên dịch mã nguồn bằng `g++`:
   ```powershell
   g++ main.cpp -o snake.exe
   ```

3. Khởi chạy game trong cửa sổ Console riêng biệt:
   ```powershell
   start .\snake.exe
   ```
   *(Lưu ý: Dùng lệnh `start` để bật cửa sổ console chuẩn, tránh lỗi trôi màn hình trong terminal tích hợp).*

---

### Cách 2: Chạy bằng Code::Blocks

1. Mở file dự án `Snake.cbp` bằng **Code::Blocks**.
2. Nhấn phím tắt **F9** (hoặc chọn menu **Build** -> **Build and run**).

---

## Hướng dẫn điều khiển trong game

| Phím | Chức năng |
| :---: | :--- |
| **W** | Di chuyển lên trên |
| **S** / **X** | Di chuyển xuống dưới |
| **A** | Di chuyển sang trái |
| **D** | Di chuyển sang phải |
| **Ctrl + C** / Đóng cửa sổ | Thoát game |
