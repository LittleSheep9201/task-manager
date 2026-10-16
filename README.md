# Task Manager

一个用 C++17 写的命令行任务管理系统，支持任务的添加、删除、修改、标记完成、查看、搜索、统计，以及保存到文件和从文件加载。

## 功能

- 添加任务
- 删除任务
- 修改任务标题
- 标记任务完成
- 查看所有任务
- 查看未完成任务
- 查看已完成任务
- 按关键字搜索任务
- 统计任务数量（总数、已完成、未完成）
- 保存任务到文件
- 启动时自动从文件加载
- 清空所有任务

## 环境要求

- CMake 3.16+
- C++17 编译器（g++ / clang++ / MSVC）

## 编译

```bash
mkdir build
cd build
cmake ..
cmake --build .


## 运行
./task_manager

## 项目结构
TaskManager/
├── include/
│   ├── Task.h
│   ├── TaskManager.h
│   └── FileIO.h
├── src/
│   ├── main.cpp
│   ├── TaskManager.cpp
│   └── FileIO.cpp
├── CMakeLists.txt
├── .gitignore
└── README.md

## 作者
LittleSheep9201