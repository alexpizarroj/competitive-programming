// Solved by Alex Pizarro
#include <stdio.h>

int main() {
  int n, i, X[105], Y[105], W[105];

  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; ++i) {
      scanf("%d %d %d", &X[i], &Y[i], &W[i]);
    }

    int sum_x = 0, sum_y = 0, sum_w = 0, sum_xw = 0, sum_yw = 0;
    for (i = 0; i < n; ++i) {
      sum_x += X[i];
      sum_xw += X[i] * W[i];

      sum_y += Y[i];
      sum_yw += Y[i] * W[i];

      sum_w += W[i];
    }

    long long sum = 0, add;
    for (i = 0; i < n; ++i) {
      add = (sum_xw - sum_w * X[i]);
      add = add * add * W[i];
      sum += add;

      add = (sum_yw - sum_w * Y[i]);
      add = add * add * W[i];
      sum += add;
    }

    double total_cost = (double)sum / (sum_w * sum_w);
    printf("%.3lf\n", total_cost);
  }

  return 0;
}
