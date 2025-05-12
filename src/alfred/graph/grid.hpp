#ifndef AFGR_GRID
#define AFGR_GRID

#include <array>

enum Direction {
    up = 0,
    right = 1,
    down = 2,
    left = 3
};

const int _dx[] = {-1, 0, 1, 0};
const int _dy[] = {0, 1, 0, -1};

Direction clockwise(Direction d) {
    return static_cast<Direction>((static_cast<int>(d) + 1) % 4);
}

Direction counter_clockwise(Direction d) {
    return static_cast<Direction>((static_cast<int>(d) + 3) % 4);
}

Direction opposite(Direction d) {
    return static_cast<Direction>((static_cast<int>(d) + 2) % 4);
}

struct GridPoint {
    int x, y, dis;
    GridPoint() : x(0), y(0), dis(0) {}
    GridPoint(int x, int y) : x(x), y(y), dis(0) {}
    GridPoint(int x, int y, int dis) : x(x), y(y), dis(dis) {}
    inline bool operator==(const GridPoint &other) const {
        return x == other.x && y == other.y && dis == other.dis;
    }
    inline bool in_range(int n, int m) const noexcept {
        return 1 <= x && x <= n && 1 <= y && y <= m;
    }
    GridPoint move(Direction d) noexcept {
        return GridPoint(x + _dx[d], y + _dy[d], dis + 1);
    }
    std::array<GridPoint, 4> adj(void) noexcept {
        std::array<GridPoint, 4> result;
        for (int i = 0; i < 4; ++i) {
            result[i] = GridPoint(x + _dx[i], y + _dy[i], dis + 1);
        }
        return result;
    }
    std::array<std::pair<GridPoint, Direction>, 4> adj_with_dir(void) noexcept {
        std::array<std::pair<GridPoint, Direction>, 4> result;
        for (int i = 0; i < 4; ++i) {
            result[i] = {
                GridPoint(x + _dx[i], y + _dy[i], dis + 1),
                static_cast<Direction>(i)
            };
        }
        return result;
    }
};

#endif
