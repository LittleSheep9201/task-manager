#include "TaskManager.h"
#include "FileIO.h"
#include <iostream>
using namespace std;


void showMenu() {
  cout << 
"\n===== 任务管理系统 =====\n"
"1. 添加任务\n"
"2. 删除任务\n"
"3. 修改任务\n"
"4. 标记完成\n"
"5. 查看所有任务\n"
"6. 查看未完成任务\n"
"7. 查看已完成任务\n"
"8. 搜索任务\n"
"9. 统计信息\n"
"10. 保存到文件\n"
"11. 清空所有\n"
"0. 退出\n"
"请选择: \n "   << endl;
}

int main(){
  TaskManager taskManager;
  FileIO::loadFromFile(taskManager, "task.txt");

  while(1){
    showMenu();

    int choice;
    cin >> choice;

    switch (choice) {
      case 1: {
        cout << "请输入任务标题: ";
        string title;
        cin.ignore();
        getline(cin, title);
        taskManager.addTask(title);
        break;
      }
      case 2: {
        taskManager.listTasks();
        cout << "请输入任务ID: ";
        int id;
        cin >> id;
        taskManager.removeTask(id);
        break;
      }
      case 3: {
        taskManager.listTasks();
        cout << "请输入任务ID: ";
        int id;
        cin >> id;
        cout << "请输入新的任务标题: ";
        string newTitle;
        cin.ignore();
        getline(cin, newTitle);
        taskManager.renameTask(id, newTitle);
        break;
      }
      case 4: {
        taskManager.listTasks();
        cout << "请输入任务ID: ";
        int id;
        cin >> id;
        taskManager.markTaskDone(id);
        break;
      }
      case 5:
        taskManager.listTasks();
        break;
      case 6:
        taskManager.listUndoneTasks();
        break;
      case 7:
        taskManager.listDoneTasks();
        break;
      case 8: {
        cout << "请输入搜索关键字: ";
        string keyword;
        cin.ignore();
        getline(cin, keyword);
        taskManager.searchTasks(keyword);
        break;
      }
      case 9: {
        cout << "请输入要查询的信息：\n"
        "1. 总任务数\n"
        "2. 已完成任务数\n"
        "3. 未完成任务数\n"
        "请选择: \n " << endl;

        int statChoice;
        cin >> statChoice;

        switch (statChoice) {
          case 1:
            cout << "总任务数: " << taskManager.countTasks() << endl;
            break;
          case 2:
            cout << "已完成任务数: " << taskManager.countDoneTasks() << endl;
            break;
          case 3:
            cout << "未完成任务数: " << taskManager.countUndoneTasks() << endl;
            break;
          default:
            cout << "无效的选择，请重新输入。" << endl;
        }
        break;
      }
      case 10:
        FileIO::saveToFile(taskManager, "task.txt");
        break;
      case 11:
        taskManager.clearTasks();
        break;
      case 0:
        cout << "退出程序" << endl;
        return 0;
      default:
        cout << "无效的选择，请重新输入。" << endl;
    }
  }

  return 0;
}