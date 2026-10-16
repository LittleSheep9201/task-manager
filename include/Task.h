#pragma once
#include <string>
using namespace std;

class Task {
public:
  int id_;
  string title_;
  bool done_;

  Task(int id, const string& title, bool done) : id_(id), title_(title), done_(done) {}
};