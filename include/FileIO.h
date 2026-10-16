#pragma once
#include "TaskManager.h"
#include <string>

class FileIO {
  public:
  //保存和加载
  static void saveToFile(const TaskManager& TM, const string& filename);
  static void loadFromFile(TaskManager& TM, const string& filename);
};

