#include <iostream>

const int kRows = 5;
const int kCols = 10;

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

bool Inside(int x, int y) { return x >= 0 && x < kCols && y >= 0 && y < kRows; }

void Clear(char** board) {
  for (int y = 0; y < kRows; y++) {
    for (int x = 0; x < kCols; x++) {
      board[y][x] = ' ';
    }
  }
}

bool Put(char** board, int x, int y, char c) {
  if (!Inside(x, y)) {
    return false;
  }
  board[y][x] = c;
  return true;
}

bool Text(char** board, int x, int y, const char* word) {
  int length = 0;
  while (word[length] != '\0') {
    length++;
  }
  if (!Inside(x, y) || length > kCols - x) {
    return false;
  }
  for (int i = 0; i < length; i++) {
    Put(board, x + i, y, word[i]);
  }
  return true;
}

void Print(char** board) {
  for (int y = 0; y < kRows; y++) {
    for (int x = 0; x < kCols; x++) {
      std::cout << board[y][x];
    }
    std::cout << '\n';
  }
}

int main() {
  char cells[kRows][kCols];
  char* rows[kRows];
  for (int y = 0; y < kRows; y++) {
    rows[y] = cells[y];
  }
  char** board = rows;
  Clear(board);

  char command[64];
  while (true) {
    std::cin.width(sizeof(command));
    if (!(std::cin >> command)) {
      break;
    }
    if (Same(command, "quit")) {
      break;
    }
    if (Same(command, "clear")) {
      Clear(board);
    } else if (Same(command, "put")) {
      int x;
      int y;
      char c;
      std::cin >> x >> y >> c;
      if (!Put(board, x, y, c)) {
        std::cout << "error\n";
      }
    } else if (Same(command, "text")) {
      int x;
      int y;
      char word[kCols + 1];
      std::cin >> x >> y;
      std::cin.width(sizeof(word));
      std::cin >> word;
      if (!Text(board, x, y, word)) {
        std::cout << "error\n";
      }
    } else if (Same(command, "print")) {
      Print(board);
    } else {
      std::cout << "error\n";
    }
  }
}
