import numpy as np
import time
import os

# Thư mục chứa file .inp
input_folder = "test"

# Lưu thời gian chạy của từng file
execution_times = {}

# Lặp qua tất cả các file trong thư mục
for file_name in sorted(os.listdir(input_folder)):
    if file_name.endswith(".inp"):
        file_path = os.path.join(input_folder, file_name)
        
        # Đọc dữ liệu từ file
        with open(file_path, "r") as f:
            n = int(f.readline().strip())  # Đọc số lượng phần tử
            arr = np.array(list(map(float, f.readline().split())))  # Chuyển thành numpy array
        
        # Đo thời gian thực thi numpy.sort()
        start_time = time.time()
        sorted_arr = np.sort(arr)
        end_time = time.time()
        
        # Tính thời gian chạy (ms)
        elapsed_time = (end_time - start_time) * 1000
        execution_times[file_name] = elapsed_time

        # Xuất kết quả ra terminal
        print(f"Processed {file_name} in {elapsed_time:.4f} ms.")

# Tính trung bình thời gian thực thi
average_time = sum(execution_times.values()) / len(execution_times)
print(f"Average execution time: {average_time:.4f} ms.")
