#include <vector>
#include <algorithm>

class Solution {
private:
    typedef long long ll;
    static ll Sqr(ll a) { return a * a; }
    struct Point {
        int x;
        int y;
        Point operator+(Point other) { return { x + other.x, y + other.y }; }
        Point operator-(Point other) { return { x - other.x, y - other.y }; }
        ll Len2() { return Sqr(x) + Sqr(y); }
    };
    ll Cha(Point a, Point b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
    typedef std::vector<int> Circle;
    int x0;
    int y0;
    int n;
    bool InSquare(Point point) {
        return point.x >= 0 && point.x <= x0 && point.y >= 0 && point.y <= y0;
    }
    bool In(const Circle& circle, Point point) {
        return Point(circle[0] - point.x, circle[1] - point.y).Len2() <=
            Sqr(circle[2]);
    }
    bool SourceIn(const Circle& circle) { return In(circle, { 0, 0 }); }
    bool TargetIn(const Circle& circle) { return In(circle, { x0, y0 }); }
    bool Left(const Circle& circle) {
        // cout << "fuck" << endl;
        int x = circle[0], y = circle[1], r = circle[2];
        if (y > y0) {
            return In(circle, { 0, y0 });
        }
        if (y < 0) {
            return In(circle, { 0, 0 });
        }
        return abs(x) <= r;
    }
    bool Right(const Circle& circle) {
        int x = circle[0], y = circle[1], r = circle[2];
        if (y > y0) {
            return In(circle, { x0, y0 });
        }
        if (y < 0) {
            return In(circle, { x0, 0 });
        }
        return abs(x - x0) <= r;
    }
    bool Down(const Circle& circle) {
        int x = circle[0], y = circle[1], r = circle[2];
        if (x > x0) {
            return In(circle, { x0, 0 });
        }
        if (x < 0) {
            return In(circle, { 0, 0 });
        }
        return abs(y) <= r;
    }
    bool Up(const Circle& circle) {
        int x = circle[0], y = circle[1], r = circle[2];
        if (x > x0) {
            return In(circle, { x0, y0 });
        }
        if (x < 0) {
            // cout << "!" << endl;
            return In(circle, { 0, y0 });
        }
        return abs(y - y0) <= r;
    }
    ll Sign(ll a) {
        if (a == 0) {
            return 0;
        }
        return a / abs(a);
    }
    bool Intersect(const Circle& a, const Circle& b) {
        int x1 = a[0], y1 = a[1], r1 = a[2], x2 = b[0], y2 = b[1], r2 = b[2];
        if (Point(x1 - x2, y1 - y2).Len2() > Sqr(r1 + r2)) {
            return false;
        }
        if (InSquare({ x1, y1 }) || InSquare({ x2, y2 })) {
            return true;
        }
        ll sign1 = Sign(Cha({ x1, y1 }, { x2, y2 }));
        ll sign2 = Sign(Cha({ x1 - x0, y1 - y0 }, { x2 - x0, y2 - y0 }));
        return sign1 != sign2;
    }
public:
    bool canReachCorner(int xCorner, int yCorner,
        std::vector<std::vector<int>>& circles) {
        x0 = xCorner;
        y0 = yCorner;
        n = circles.size();
        for (const auto& circle : circles) {
            if (SourceIn(circle) || TargetIn(circle)) {
                // cout << "imp";
                return false;
            }
        }
        std::vector<bool> vis(n);
        std::vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (Up(circles[i]) || Left(circles[i])) {
                stk.push_back(i);
                vis[i] = true;
            }
        }
        while (stk.size()) {
            int solo = stk.back();
            stk.pop_back();
            if (Down(circles[solo]) || Right(circles[solo])) {
                return false;
            }
            for (int i = 0; i < n; i++) {
                if (!vis[i] && Intersect(circles[solo], circles[i])) {
                    stk.push_back(i);
                    vis[i] = true;
                }
            }
        }
        return true;
    }
};