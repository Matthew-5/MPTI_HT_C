#include <iomanip>
#include <iostream>
float mean(const int* a, const int N) {
  int s = *a;
  for (int i = 1; i < N; i++) {
    s += a[i];
  }
  return static_cast<float>(s) / N;
}
struct MinMax {
  int min;
  int max;
};
MinMax maxmin(const int* a, const int N) {
  int min = *a;
  int max = *a;
  for (int i = 1; i < N; i++) {
    if (min > a[i]) {
      min = a[i];
    }
    if (max < a[i]) {
      max = a[i];
    }
  }
  MinMax M;
  M.min = min;
  M.max = max;
  return M;
}
int dbz(const int* a, const int N) {
  int s = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] < 0) {
      s += 1;
    }
  }
  return s;
}
int main() {
  int N;
  std::cin >> N;
  int* a;
  a = new int[N];
  for (int i = 0; i < N; i++) {
    std::cin >> a[i];
  }
  MinMax m = maxmin(a, N);
  std::cout << std::fixed << std::setprecision(1) << mean(a, N) << '\n'
            << m.min << ' ' << m.max << '\n'
            << dbz(a, N) << '\n';
  delete[] a;
}
