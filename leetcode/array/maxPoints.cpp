#include "all.h"

using namespace std;

struct Point {
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b) {}
};

double getA (Point p1, Point p2) {
    if (p1.x - p2.x != 0)
        return (p1.y - p2.y) / (p1.x - p2.x);
    else return INT_MAX;
}

double getB (double a, Point p1, Point p2) {
    if (a != INT_MAX)
        return p1.y - a * p1.x;
    else return 0;
}
bool contains(Point p, vector<Point> vec) {
    for (auto v : vec) {
        if (v.x == p.x && v.y == p.y) return true;
    }
    return false;
}

bool equal(Point p1, Point p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}
int maxPoints (vector<Point>& points) {
    if (points.size() < 3) return points.size();
    int max = 2;
    vector<Point> onTheLine;
    for (int i = 0; i < points.size() - 1; ++i) {
        int cnt = 2;
        int k = 1;
        Point p1 = points[i];
        while (i + k < points.size()) {
            if (equal(p1, points[i + k])){
                ++k;
                ++cnt;
            }
            else break;
        }
        Point p2 = points[i + k];
        double a = getA(p1, p2);
        double b = getB(a, p1, p2);
        onTheLine.push_back(p1);
        onTheLine.push_back(p2);
        for (int j = i + k + 1; j < points.size(); ++j) {
            double newA= getA(p1, points[j]);
            if (contains(points[j], onTheLine)) {
                ++cnt;
            }
            else if (newA == a && b == getB(newA, p1, points[j])) {
                ++cnt;
                onTheLine.push_back(points[j]);
            }
        }
        if (cnt > max) max = cnt;
        onTheLine.clear();
    }
    return max;
}

int main() {
    vector<Point> points;
    string x = "", y = "";
    while (true) {
        cout << "Enter points: " << endl;
        cin >> x >> y;
        if (x == "q" || y == "q") break;
        Point p = Point(stoi(x), stoi(y));
        points.push_back(p);
    }
    cout << "max points = " << maxPoints(points) << endl;
    return 0;
}
