#include <iostream>
#include <cmath>

int n;
using namespace std;

struct Point{
    double x;
    double y;
};

void koch(Point p1, Point p2){

    constexpr double pi =  3.141592653589793;
    double d1 = p2.x - p1.x;

    if(n == 0) return;

    cout << p1.x << " " << p1.y << endl;
    cout << p2.x << " " << p2.y << endl;
    
    Point s { d1/3, p1.x };
    Point t { 2*d1/3, p1.x};

    Point u{ d1/2, d1/3*sin(pi/3)};

    cout << s.x << " " << s.y << endl;
    cout << u.x << " " << u.y << endl;
    cout << t.x << " " << t.y << endl;
    
    n--;
    koch(s, u);
    koch(u, t);
}

int main(){
    Point p1 {0.0f, 0.0f};
    Point p2 {100.0f, 0.0f};

    cin >> n;
    koch(p1, p2);
}

