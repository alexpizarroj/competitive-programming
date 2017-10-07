#!/usr/bin/env python2.7
INF = 1000000007


def find_flow(s, t, n, adj, cap):
    parent = [-1 for x in xrange(n)]
    q = [s]
    q_idx = 0

    while q_idx < len(q) and parent[t] == -1:
        u = q[q_idx]
        q_idx += 1

        for v in adj[u]:
            if cap[u][v] == 0 or parent[v] != -1:
                continue

            parent[v] = u
            q.append(v)
            if v == t:
                break

    if parent[t] == -1:
        return 0

    flow = INF

    cur = t
    while parent[cur] != -1:
        cur_parent = parent[cur]
        flow = min(flow, cap[cur_parent][cur])
        cur = cur_parent

    cur = t
    while parent[cur] != -1:
        cur_parent = parent[cur]
        cap[cur_parent][cur] -= flow
        cap[cur][cur_parent] += flow
        cur = cur_parent

    return flow


def answer(entrances, exits, path):
    nVertices = len(path) + 2
    sink = nVertices - 1
    src = sink - 1

    adj = [[] for x in xrange(nVertices)]
    cap = [[0 for x in xrange(nVertices)] for y in xrange(nVertices)]

    for i in xrange(nVertices - 2):
        for j in xrange(i + 1, nVertices - 2):
            if path[i][j] == 0 and path[j][i] == 0:
                continue

            adj[i].append(j)
            adj[j].append(i)

    for i in xrange(nVertices - 2):
        for j in xrange(nVertices - 2):
            cap[i][j] = path[i][j]

    for u in entrances:
        adj[src].append(u)
        cap[src][u] = INF

    for u in exits:
        adj[u].append(sink)
        cap[u][sink] = INF

    ans = 0
    while True:
        flow = find_flow(src, sink, nVertices, adj, cap)
        if flow == 0:
            break

        ans += flow

    return ans


def test1():
    entrances = [0]
    exits = [3]
    path = [[0, 7, 0, 0], [0, 0, 6, 0], [0, 0, 0, 8], [9, 0, 0, 0]]
    return answer(entrances, exits, path)


def test2():
    entrances = [0, 1]
    exits = [4, 5]
    path = [[0, 0, 4, 6, 0, 0], [0, 0, 5, 2, 0, 0], [0, 0, 0, 0, 4, 4],
            [0, 0, 0, 0, 6, 6], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
    return answer(entrances, exits, path)


def main():
    print test1()
    print test2()


if __name__ == "__main__":
    main()
