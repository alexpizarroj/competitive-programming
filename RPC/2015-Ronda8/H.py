N = int(input())

def is_program(meth):
    return meth.split('::')[-1] == 'PROGRAM'

graph = dict()

for TC in range(N):
    meth, _ = input().split(' ')
    callers = input().split(' ')
    if meth not in graph:
        graph[meth] = []
    for caller in callers:
        if caller == '':
            continue
        if caller not in graph:
            graph[caller] = []
        graph[caller].append(meth)

q = list(filter(is_program, graph.keys()))
visited = set(q);

while len(q) > 0:
    meth = q.pop()
    for callee in graph[meth]:
        if callee in visited:
            continue
        q.append(callee)
        visited.add(callee);

count = 0
for meth in graph.keys():
    if meth in visited:
        continue
    count += 1

print(count)
