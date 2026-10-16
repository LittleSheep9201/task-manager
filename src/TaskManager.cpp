#include "TaskManager.h"
#include <iostream>
#include <algorithm>
#include <vector>

  void TaskManager::addTask(const string& title) {
    Tasks_.emplace_back(nextId_++, title, false);
    cout << "任务已添加: " << title << endl;
  }

  void TaskManager::removeTask(int id) {
    auto it = remove_if(Tasks_.begin(), Tasks_.end(), [&id](const Task& T){
      return T.id_ == id;
    });
    
    if(it == Tasks_.end()) {
      cout << "该任务不存在，删除失败" << endl;
      return;
    }else {
      cout << "删除任务成功" << endl;
      Tasks_.erase(it, Tasks_.end());
    }
  }

  void TaskManager::renameTask(int id, const string& newTitle) {
    for(auto& T : Tasks_) {
      if(T.id_ == id) {
        T.title_ = newTitle;
        cout << "修改任务标题成功: " << newTitle << endl;
        return;
      }
    }

    cout << "该任务不存在，重命名失败" << endl;
  }

  void TaskManager::markTaskDone(int id) {
    for(auto& T : Tasks_) {
      if(T.id_ == id) {
        T.done_ = true;
        cout << "任务完成: " << T.title_ << endl;
        return;
      }
    }

    cout << "该任务不存在，标记失败" << endl;
  }

  void TaskManager::listTasks() const {
    for(const auto& T : Tasks_){
      cout << "任务ID: " << T.id_
      << "\n任务名称: " << T.title_
      << "\n任务状态: " << T.done_ << endl;
    }
  }

  void TaskManager::listUndoneTasks() const {
    for(const auto& T : Tasks_){
      if(T.done_) continue;

      cout << "任务ID: " << T.id_
      << "\n任务名称: " << T.title_
      << "\n任务状态: " << T.done_ << endl;
    }
  }

  void TaskManager::listDoneTasks() const {
    for(const auto& T : Tasks_){
      if(!T.done_) continue;

      cout << "任务ID: " << T.id_
      << "\n任务名称: " << T.title_
      << "\n任务状态: " << T.done_ << endl;
    }
  }

  void TaskManager::searchTasks(const string& keyword) const {
    vector<const Task*> results;
    for(const auto& T : Tasks_) {
      if(T.title_.find(keyword) != string::npos)
        results.push_back(&T);
    }

    if(results.empty()) {
      cout << "未找到相关任务" << endl;
      return;
    }

    for(const auto* T : results) {
      cout << "任务ID: " << T->id_
      << "\n任务名称: " << T->title_
      << "\n任务状态: " << T->done_ << endl;
    }
  }

  int TaskManager::countTasks() const {
    return Tasks_.size();
  }

  int TaskManager::countDoneTasks() const {
    return count_if(Tasks_.begin(), Tasks_.end(), [](const Task& T) {
      return T.done_;
    });
  }

  int TaskManager::countUndoneTasks() const {
    return count_if(Tasks_.begin(), Tasks_.end(), [](const Task& T) {
      return !T.done_;
    });
  }

  void TaskManager::clearTasks() {
    Tasks_.clear();
    cout << "所有任务已清空" << endl;
  }

  const vector<Task>& TaskManager::getTasks() const {
    return Tasks_;
  }

  void TaskManager::setTasks(const vector<Task>& tasks) {
    Tasks_ = tasks;
    int maxId = 0;

    for(const Task& T : tasks) {
      maxId = max(maxId, T.id_);
    }

    nextId_ = maxId + 1;
  }
