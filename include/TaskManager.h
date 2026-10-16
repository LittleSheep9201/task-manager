#pragma once
#include "Task.h"
#include <vector>

class TaskManager {
public:
//增删改
  void addTask(const string& title);
  void removeTask(int id);
  void renameTask(int id, const string& newTitle);
  void markTaskDone(int id);

//查看任务状态
  void listTasks() const;
  void listUndoneTasks() const;
  void listDoneTasks() const;

//搜索
  void searchTasks(const string& keyword) const;

//统计信息
  int countTasks() const;
  int countDoneTasks() const;
  int countUndoneTasks() const;

//清空任务
  void clearTasks();


//提供Tasks_接口
  const vector<Task>& getTasks() const;
  void setTasks(const vector<Task>& tasks);

private:
  vector<Task> Tasks_; 
  int nextId_ = 1;
};
