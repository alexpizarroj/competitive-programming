#!/usr/bin/env python2.7
from collections import deque
from fractions import gcd

DIRECTION_NONE = 0b00000000
DIRECTION_NORTH = 0b00000001
DIRECTION_EAST = 0b00000010
DIRECTION_WEST = 0b00000100
DIRECTION_SOUTH = 0b00001000
DIRECTION_NORTHWEST = 0b00010000
DIRECTION_NORTHEAST = 0b00100000
DIRECTION_SOUTHWEST = 0b01000000
DIRECTION_SOUTHEAST = 0b10000000

DIRECTION_ALL = 0b11111111
DIRECTION_TOP_RIGHT = DIRECTION_NORTH | DIRECTION_WEST | DIRECTION_NORTHWEST
DIRECTION_TOP_LEFT = DIRECTION_NORTH | DIRECTION_EAST | DIRECTION_NORTHEAST
DIRECTION_BOT_RIGHT = DIRECTION_SOUTH | DIRECTION_WEST | DIRECTION_SOUTHWEST
DIRECTION_BOT_LEFT = DIRECTION_SOUTH | DIRECTION_EAST | DIRECTION_SOUTHEAST

ALL_DIRECTIONS = [
    DIRECTION_NORTH,
    DIRECTION_SOUTH,
    DIRECTION_WEST,
    DIRECTION_EAST,
    DIRECTION_NORTHWEST,
    DIRECTION_NORTHEAST,
    DIRECTION_SOUTHWEST,
    DIRECTION_SOUTHEAST
]


class Point:
    def __init__(self, x, y, right, top, adj):
        self.x = x
        self.y = y
        self.right = right
        self.top = top
        self.adj = adj

    def translate(self, room, direction):
        if direction == DIRECTION_NORTH:
            x = self.x
            y = self.y + 2 * (self.top - self.y)
            right = self.right
            top = self.top + room.H
            adj = DIRECTION_NORTH
            return Point(x, y, right, top, adj)

        elif direction == DIRECTION_SOUTH:
            x = self.x
            y = self.y - 2 * (room.H - (self.top - self.y))
            right = self.right
            top = self.top - room.H
            adj = DIRECTION_SOUTH
            return Point(x, y, right, top, adj)

        elif direction == DIRECTION_WEST:
            x = self.x + 2 * (self.right - self.x)
            y = self.y
            right = self.right + room.W
            top = self.top
            adj = DIRECTION_WEST
            return Point(x, y, right, top, adj)

        elif direction == DIRECTION_EAST:
            x = self.x - 2 * (room.W - (self.right - self.x))
            y = self.y
            right = self.right - room.W
            top = self.top
            adj = DIRECTION_EAST
            return Point(x, y, right, top, adj)

        elif direction == DIRECTION_NORTHWEST:
            point = self.translate(room, DIRECTION_NORTH).translate(
                room, DIRECTION_WEST)
            point.adj = DIRECTION_TOP_RIGHT
            return point

        elif direction == DIRECTION_NORTHEAST:
            point = self.translate(room, DIRECTION_NORTH).translate(
                room, DIRECTION_EAST)
            point.adj = DIRECTION_TOP_LEFT
            return point

        elif direction == DIRECTION_SOUTHWEST:
            point = self.translate(room, DIRECTION_SOUTH).translate(
                room, DIRECTION_WEST)
            point.adj = DIRECTION_BOT_RIGHT
            return point

        elif direction == DIRECTION_SOUTHEAST:
            point = self.translate(room, DIRECTION_SOUTH).translate(
                room, DIRECTION_EAST)
            point.adj = DIRECTION_BOT_LEFT
            return point

        return None

    def squared_distance_to(self, other):
        x, y = (other.x - self.x), (other.y - self.y)
        return x * x + y * y

    def equals(self, other):
        return (self.x == other.x and self.y == other.y and self.adj == other.adj)


class RoomShowdown:
    def __init__(self, dimensions, captain_position, badguy_position, distance):
        self.L = distance
        self.L2 = distance * distance
        self.W = dimensions[0]
        self.H = dimensions[1]
        self.captain_pos = captain_position
        self.bad_guy_pos = badguy_position

    def solve(self):
        captain = Point(
            self.captain_pos[0], self.captain_pos[1], self.W, self.H, DIRECTION_ALL)
        bad_guy = Point(
            self.bad_guy_pos[0], self.bad_guy_pos[1], self.W, self.H, DIRECTION_ALL)

        captain_slopes = self.__find_slopes_given_start_point(captain, captain)
        # print "Captain"
        # print captain_slopes

        bad_guy_slopes = self.__find_slopes_given_start_point(captain, bad_guy)
        # print "Bad Guy"
        # print bad_guy_slopes

        # print "Count"
        ans = 0
        for (key_x, key_y) in bad_guy_slopes:
            key = (key_x, key_y)
            bad_guy_hit_dist2 = bad_guy_slopes[key]
            captain_hit_dist2 = captain_slopes.get(key, bad_guy_hit_dist2 + 1)

            if bad_guy_hit_dist2 < captain_hit_dist2:
                ans += 1

        return ans

    def __find_slopes_given_start_point(self, origin, starting_point):
        results = dict()

        q = deque()
        q.append(starting_point)
        if not origin.equals(starting_point):
            dist2 = origin.squared_distance_to(starting_point)
            if dist2 <= self.L2:
                self.__add_point_slope_to_dict(
                    results, origin, starting_point, dist2)

        while len(q) > 0:
            cur_point = q.popleft()
            # print cur_point.x, cur_point.y, cur_point.adj

            for direction in ALL_DIRECTIONS:
                is_heading_to_direction = (cur_point.adj & direction)
                if not is_heading_to_direction:
                    continue

                next_point = cur_point.translate(self, direction)
                if next_point == None:
                    continue

                dist2 = origin.squared_distance_to(next_point)
                if dist2 <= self.L2:
                    q.append(next_point)
                    self.__add_point_slope_to_dict(
                        results, origin, next_point, dist2)

        return results

    def __add_point_slope_to_dict(self, dict, origin, point, dist2):
        x = point.x - origin.x
        y = point.y - origin.y
        g = abs(gcd(x, y))
        slope = (x / g, y / g)
        dict[slope] = min(dict.get(slope, dist2), dist2)


def answer(dimensions, captain_position, badguy_position, distance):
    s = RoomShowdown(dimensions, captain_position, badguy_position, distance)
    return s.solve()


def main():
    print answer([3, 2], [1, 1], [2, 1], 4)
    print answer([300, 275], [150, 150], [185, 100], 500)


if __name__ == '__main__':
    main()
