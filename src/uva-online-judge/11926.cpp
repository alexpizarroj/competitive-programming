#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int kTimeslots = 1000001;
using Schedule = bitset<kTimeslots>;

struct OneTimeTask {
  int start, end;
};

struct RepeatingTask {
  int start, end, repInterval;
};

Schedule buildOneTimeTaskSchedule(const OneTimeTask& task) {
  Schedule result;
  for (int i = task.start; i < task.end; ++i) {
    result.set(i);
  }
  return result;
}

Schedule buildRepeatingTaskSchedule(const RepeatingTask& task) {
  Schedule result;

  int i = task.start, currentEnding = task.end;
  while (i < kTimeslots) {
    for (int j = i; j < currentEnding && j < kTimeslots; ++j) result.set(j);

    i += task.repInterval;
    currentEnding += task.repInterval;
  }

  return result;
}

bool tasksConflict(const vector<OneTimeTask>& oneTimeTasks,
                   const vector<RepeatingTask>& repeatingTasks) {
  for (auto&& task : repeatingTasks) {
    if (task.start + task.repInterval < task.end) return true;
  }

  Schedule current;

  for (auto&& task : oneTimeTasks) {
    Schedule taskTimeline = buildOneTimeTaskSchedule(task);
    if ((current & taskTimeline).any()) return true;
    current |= taskTimeline;
  }

  for (auto&& task : repeatingTasks) {
    Schedule taskTimeline = buildRepeatingTaskSchedule(task);
    if ((current & taskTimeline).any()) return true;
    current |= taskTimeline;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m && (n != 0 || m != 0)) {
    vector<OneTimeTask> oneTimeTasks;
    for (int i = 0; i < n; ++i) {
      int start, end;
      cin >> start >> end;
      oneTimeTasks.push_back(OneTimeTask{start, end});
    }

    vector<RepeatingTask> repeatingTasks;
    for (int i = 0; i < m; ++i) {
      int start, end, repInterval;
      cin >> start >> end >> repInterval;
      repeatingTasks.push_back(RepeatingTask{start, end, repInterval});
    }

    bool ans = tasksConflict(oneTimeTasks, repeatingTasks);
    cout << (ans ? "CONFLICT" : "NO CONFLICT") << endl;
  }

  return 0;
}
