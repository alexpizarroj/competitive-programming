#include <message.h>
#include <cassert>
#include <cstdio>
#include <sum_all.h>

// This is a sample solution to the "Sum all integers" problem. Each node sums
// the elements that belong to it (that is, the ones with position equal to
// MyNodeId() modulo NumberOfNodes()).
//
// To showcase the communication a bit better, instead of sending all the
// results to a "master" node, each node sends its result to the next one,
// accumulating the result from the previous node. The last node prints the
// final result.
int main() {
  long long sum = 0LL;
  for (long long pos = MyNodeId(); pos < GetN(); pos += NumberOfNodes()) {
    sum += GetNumber(pos);
  }
  if (MyNodeId() > 0) {
    Receive(MyNodeId() - 1);
    sum += GetLL(MyNodeId() - 1);
  }
  if (MyNodeId() < NumberOfNodes() - 1) {
    PutLL(MyNodeId() + 1, sum);
    Send(MyNodeId() + 1);
  } else {
    printf("%lld\n", sum);
  }
  return 0;
}
