/*Koch Curve
//Write a program which reads an integer n 
//and draws a Koch curve based on recursive 
//calles of depth n.
*/

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;
constexpr double pi =  3.141592653589793;

struct Point{
    double x;
    double y;
};

void koch(int n, const Point& p1, const Point& p2){

    if(n == 0) return;

    Point s, t, u;

    //splits the line p2-p1 by 2 : 1 
    s.x = (2*p1.x + p2.x) / 3;
    s.y = (2*p1.y + p2.y) / 3;
    //likewise by 1:2
    t.x = (p1.x + 2*p2.x) / 3;
    t.y = (p1.y + 2*p2.y) / 3;
    
    //multiply by a matrix to rotate t by 60 degrees
    u.x = (t.x - s.x) * cos(pi/3) - (t.y - s.y) * sin(pi/3) + s.x;
    u.y = (t.x - s.x) * sin(pi/3) + (t.y - s.y) * cos(pi/3) + s.y;

    cout << fixed;
    koch(n-1, p1, s);
    cout << s.x << " " << s.y << endl;
    koch(n-1, s, u);
    cout << u.x << " " << u.y << endl;
    koch(n-1, u, t);
    cout << t.x << " " << t.y << endl;
    koch(n-1, t, p2);

}

int main(){
    
    int n;

    Point p1 {0.0f, 0.0f};
    Point p2 {100.0f, 0.0f};

    cout << fixed;
    
    cin >> n;
    cout << p1.x << " " << p1.y << endl;
    koch(n, p1, p2);
    cout << p2.x << " " << p2.y << endl;

    return 0;

}

