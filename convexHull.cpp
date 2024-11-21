#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Point
{
    int x, y;
};

bool swapCheck(Point a, Point b, Point c) {
    int cross = (b.y - a.y) * (a.x - c.x) - (b.x - a.x) * (a.y - c.y);

    if (cross == 0) {
        if (b.x + b.y < c.x + c.y) {
            return false;
        } else {
            return true;
        }
    }

    if (cross < 0) {
        return true;
    }
    return false;
}

int cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

void grahamScan(vector<Point> points) {
    if (points.size() < 3) {
        cout << "Cannot make hull for 1d shapes." << endl;
        return;
    }

    int lowest = 0;
    for (int i = 0; i < points.size(); i++) {
        if (points[i].y < points[lowest].y || (points[i].y == points[lowest].y && points[i].x < points[lowest].y)) {
            lowest = i;
        }
    }

    swap(points[0], points[lowest]);

    for (int i = 1; i < points.size(); i++) {
        for (int j = 1; j < points.size() - i; j++) {
            if (swapCheck(points[0], points[j], points[j + 1])) {
                swap(points[j], points[j + 1]);
            }
        }
    }

    vector<Point> finalPoints;
    finalPoints.push_back(points[0]);
    for (int i = 1; i < points.size(); i++) {
        int cross = (points[i].y - points[0].y) * (points[0].x - points[i + 1].x) - (points[i].x - points[0].x) * (points[0].y - points[i + 1].y);
        if (cross != 0) {
            finalPoints.push_back(points[i]);
        }
    }

    stack<Point> hull;
    hull.push(finalPoints[0]);
    hull.push(finalPoints[1]);
    hull.push(finalPoints[2]);

    for (int i = 3; i < finalPoints.size(); i++) {
        Point temp = hull.top();
        hull.pop();
        Point temp2 = hull.top();
        hull.push(temp);
        while (hull.size() > 1 && cross(temp, temp2, finalPoints[i]) > 0) {
            hull.pop();
        }
        hull.push(finalPoints[i]);
    }

    while (hull.size()) {
        Point i = hull.top();
        hull.pop();
        cout << "(" << i.x << ", " << i.y << ") ";
    }
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points;
    for (int i = 0; i < n; i++) {
        Point temp;
        cin >> temp.x >> temp.y;
        points.push_back(temp);
    }

    grahamScan(points);

    // Point a, b, c;
    // a.x = 1; a.y = 0; b.x = 0; b.y = 0; c.x = 0; c.y = 1;
    // cout << cross(a, b, c);
    return 0;
}