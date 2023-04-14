project(cpp_study_notes_codebase)
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
# 设置C++标准为11
set(CMAKE_C_STANDARD 11)

# 判断是不是windows32位系统
if (!WIN32)
    link_libraries(pthread rt m)
endif (!WIN32)

# 得到当前目录下所有的.cpp源文件，并保存为src
AUX_SOURCE_DIRECTORY(. src)
# 得到执行代码命名为chapter4
ADD_EXECUTABLE(chapter4 ${src})