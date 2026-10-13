#include <iostream>

int main() {
  // Мини-журнал: два класса, в каждом своё число учеников и по три оценки.
  // int*** нужен для массивов классов, учеников и их оценок разного размера.
  // void* хранит вместе указатели на оценку (int*) и имя класса (char*).
  // Ввод: размеры классов, все оценки, затем число запросов.
  // Запрос 0 c — имя класса, запрос 1 c s p — оценка. Индексы с нуля.

  const int kClasses = 2;
  const int kSubjects = 3;
  char names[kClasses][2] = {"A", "B"};
  int students[kClasses];
  std::cin >> students[0] >> students[1];

  int*** grades = new int**[kClasses];
  for (int c = 0; c < kClasses; c++) {
    grades[c] = new int*[students[c]];
    for (int s = 0; s < students[c]; s++) {
      grades[c][s] = new int[kSubjects];
      for (int p = 0; p < kSubjects; p++) {
        std::cin >> grades[c][s][p];
      }
    }
  }

  int q;
  std::cin >> q;
  void** selected = new void*[q];
  int* types = new int[q];
  for (int i = 0; i < q; i++) {
    int c;
    std::cin >> types[i] >> c;
    void* field;
    if (types[i] == 0) {
      field = names[c];
    } else {
      int s;
      int p;
      std::cin >> s >> p;
      field = &grades[c][s][p];
    }
    selected[i] = field;
  }

  for (int i = 0; i < q; i++) {
    if (types[i] == 0) {
      std::cout << static_cast<char*>(selected[i]) << '\n';
    } else {
      std::cout << *static_cast<int*>(selected[i]) << '\n';
    }
  }

  delete[] selected;
  delete[] types;
  for (int c = 0; c < kClasses; c++) {
    for (int s = 0; s < students[c]; s++) {
      delete[] grades[c][s];
    }
    delete[] grades[c];
  }
  delete[] grades;
}
