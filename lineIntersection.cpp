#include <iostream>

#define INFINITY 999999
using namespace std;

struct Point {
    float x, y;
};

struct Line {
    Point start, end;
};

Point intersection(Line l1, Line l2) {
    Point answer;
    answer.x = INFINITY;
    answer.y = INFINITY;

    int x1 = l1.start.x; int y1 = l1.start.y;
    int x2 = l1.end.x; int y2 = l1.end.y;
    int x3 = l2.start.x; int y3 = l2.start.y;
    int x4 = l2.end.x; int y4 = l2.end.y;

    int denom = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);
    
    int num1 = (y4 - y3) * (x3 - x1) - (x4 - x3) * (y3 - y1);
    int num2 = (y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1);

    if (denom == 0) {
        return answer;
    }

    float ua = (float)num1/denom;
    float ub = (float)num2/denom;
    
    if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1) {
        answer.x = x1 + ua * (x2 - x1);
        answer.y = y1 + ua * (y2 - y1);
        return answer;
    }
    return answer;
}

int main() {
    cout << "Enter first line start and end coordinates: ";
    Line l1;
    cin >> l1.start.x >> l1.start.y >> l1.end.x >> l1.end.y;

    cout << "Enter second line start and end coordinates: ";
    Line l2;
    cin >> l2.start.x >> l2.start.y >> l2.end.x >> l2.end.y;

    Point intersect = intersection(l1,l2);

    cout << "(" <<  intersect.x << ", " << intersect.y << ")" << endl;

    return 0;
}