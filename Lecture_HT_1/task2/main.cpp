#include <iostream>

void dep(int& bal) {
  int k;
  std::cin >> k;
  if (k > 0) {
    bal += k;
  } else {
    std::cout << "error\n";
  }
}

void wit(int& bal) {
  int k;
  std::cin >> k;
  if (k > 0 && bal >= k) {
    bal -= k;
  } else {
    std::cout << "error\n";
  }
}

void bl(int& bal) { std::cout << bal << '\n'; }

void res(int& bal) { bal = 0; }

void inc(int& bal) { bal += 1; }

bool Same(const char* a, const char* b) {
  while (*a != '\0' && *b != '\0') {
    if (*a != *b) {
      return false;
    }
    a++;
    b++;
  }
  return *a == *b;
}

using Operation = void (*)(int&);

struct Command {
  const char* name;
  Operation action;
};

int main() {
  int bal = 0;
  Command commands[] = {{"deposit", dep},
                        {"withdraw", wit},
                        {"balance", bl},
                        {"reset", res},
                        {"inc", inc}};
  const int count = sizeof(commands) / sizeof(commands[0]);
  char cmd[32];

  while (true) {
    std::cin.width(sizeof(cmd));
    if (!(std::cin >> cmd)) {
      break;
    }
    if (Same(cmd, "stop")) {
      break;
    }

    bool found = false;
    for (int i = 0; i < count; i++) {
      if (Same(cmd, commands[i].name)) {
        commands[i].action(bal);
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "error\n";
    }
  }
}
