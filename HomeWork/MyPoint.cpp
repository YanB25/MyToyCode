#include <cmath>
using namespace std;
class MyPoint
{
  protected:
    double x, y;
  public:
    // The no-arg constructor that contruccts a point with coordinates(0,0)
    MyPoint();

    MyPoint(double x, double y);
    double getX() const;
    double getY() const;

    //display the distance between two points in two-dimensional space.
    double distance(const MyPoint &point); 
};

class ThreeDPoint : public MyPoint
{
protected:
  double z;
public:
  // The no-arg constructor that contruccts a point with coordinates(0,0,0)  
  ThreeDPoint();

  ThreeDPoint(double x, double y, double z);
  double getZ() const;

  //display the distance between two points in Three-dimensional space.
  double distance(const ThreeDPoint &point);  
};

MyPoint::MyPoint() : x(0), y(0) {}
MyPoint::MyPoint(double x, double y) : x(x), y(y) {}
double MyPoint::getX() const { return x;}
double MyPoint::getY() const { return y;}
double MyPoint::distance(const MyPoint& p) {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}
ThreeDPoint::ThreeDPoint() : MyPoint(), z(0) {}
ThreeDPoint::ThreeDPoint(double x, double y, double z) : MyPoint(x, y), z(z) {}
double ThreeDPoint::getZ() const { return z;}
double ThreeDPoint::distance(const ThreeDPoint& rhs) {
    return sqrt(pow(x - rhs.x, 2) + pow(y - rhs.y, 2) + pow(z - rhs.z, 2));
}
