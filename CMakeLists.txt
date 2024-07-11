cmake_minimum_required(VERSION 3.10)

# Tên của dự án
project(Caro)

# Thư mục chứa file header
include_directories(include)

# Liệt kê tất cả các thư mục con của src
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Tạo chương trình
add_executable(Caro ${SOURCES})

