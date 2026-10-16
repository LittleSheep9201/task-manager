#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <sstream>


  void FileIO::saveToFile(const TaskManager& TM, const string& filename) {
    ofstream ofs(filename);
    if(!ofs) {
      cout << "文件打开失败!" << endl;
      return;
    }
  
    for(const Task& T : TM.getTasks()) {
      ofs << T.id_ << "," << T.title_ << "," << T.done_ << endl;
    }
    
    cout << "保存成功！" << endl;
  }

  void FileIO::loadFromFile(TaskManager& TM, const string& filename) {
    ifstream ifs(filename);
    if(!ifs) {
      cout << "历史文件不存在!" << endl;
      return;
    }
    
    string line;
    vector<Task> loadedTasks;

    while(getline(ifs, line)) {
      istringstream iss(line);
      string idStr, title, doneStr;
        
      if(getline(iss, idStr, ',') && getline(iss, title, ',') && getline(iss, doneStr)) {
        loadedTasks.emplace_back(stoi(idStr), title, doneStr == "1");
      }
    }

    TM.setTasks(loadedTasks);
    cout << "加载成功！" << endl;
  }