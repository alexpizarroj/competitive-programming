#!/usr/bin/env python2.7
PATH = 0
WALL = 1
NOT_SEEN = 999999999
AVAILABLE_SIDE_MOVES = [[0, 1], [0, -1], [1, 0], [-1, 0]]


def answer(maze):
    n = len(maze)
    m = len(maze[0])

    dist = [[[NOT_SEEN for i in xrange(2)]
             for j in xrange(m)] for z in xrange(n)]
    dist[0][0][1] = 1
    q = [(0, 0, 1)]

    q_index = 0
    while q_index < len(q):
        cx, cy, wl = q[q_index]

        for sm in AVAILABLE_SIDE_MOVES:
            x, y = cx + sm[0], cy + sm[1]
            if x < 0 or x >= n or y < 0 or y >= m:
                continue

            if maze[x][y] == WALL:
                if wl > 0 and dist[x][y][wl - 1] == NOT_SEEN:
                    q.append((x, y, wl - 1))
                    dist[x][y][wl - 1] = dist[cx][cy][wl] + 1
            else:
                if dist[x][y][wl] == NOT_SEEN:
                    q.append((x, y, wl))
                    dist[x][y][wl] = dist[cx][cy][wl] + 1

        q_index += 1

    return min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1])


def main():
    print answer([
        [0, 1, 1, 0],
        [0, 0, 0, 1],
        [1, 1, 0, 0],
        [1, 1, 1, 0]
    ])
    print answer([
        [0, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 1, 1, 1, 1, 1],
        [0, 1, 1, 1, 1, 1],
        [0, 0, 0, 0, 0, 0]
    ])


if __name__ == '__main__':
    main()
