#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int crossProduct(Point A, Point B, Point C) {
    return (A.x - B.x) * (B.y - C.y) - (B.x - C.x) * (A.y - B.y);
}

string isInside(Point p, vector<Point> shape) {
    for (int i = 0; i < shape.size(); i++) {
        Point start = shape[i];
        Point end = shape[(i + 1) % shape.size()];
        int cp = crossProduct(p, start, end);
        if (cp < 0) {
            return "Outside";
        } else if (cp == 0) {
            return "On";
        }
    }

    return "Inside";
}

int main() {
    int n;
    cout << "Enter the number of points in shape: ";
    cin >> n;

    vector<Point> shape;
    cout << "Enter the points: ";
    for (int i = 0; i < n; i++) {
        Point temp;
        cin >> temp.x >> temp.y;
        shape.push_back(temp);
    }

    cout << "Enter the point: ";
    Point p;
    cin >> p.x >> p.y;
    cout << isInside(p, shape) << endl;
}