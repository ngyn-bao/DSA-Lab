#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero x-y coordinate
         */
        this->x = 0;
        this->y = 0;
    }

    Point(double x, double y)
    {
        /*
         * STUDENT ANSWER
         */
        this->x = x;
        this->y = y;
    }

    void setX(double x)
    {
        /*
         * STUDENT ANSWER
         */
        this->x = x;
    }

    void setY(double y)
    {
        /*
         * STUDENT ANSWER
         */
        this->y = y;
    }

    double getX() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->x;
    }

    double getY() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->y;
    }

    double distanceToPoint(const Point &pointA)
    {
        /*
         * STUDENT ANSWER
         * TODO: calculate the distance from this point to point A in the coordinate plane
         */
        return sqrt(pow(this->x - pointA.x, 2) + pow(this->y - pointA.y, 2));
    }
};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero center's x-y and radius
         */
        center = Point(0, 0);
    }

    Circle(Point center, double radius)
    {
        /*
         * STUDENT ANSWER
         */
        this->center = center;
        this->radius = radius;
    }

    Circle(const Circle &circle)
    {
        /*
         * STUDENT ANSWER
         */
        this->center = circle.center;
        this->radius = circle.radius;
    }

    void setCenter(Point point)
    {
        /*
         * STUDENT ANSWER
         */
        this->center = point.center;
    }

    void setRadius(double radius)
    {
        /*
         * STUDENT ANSWER
         */
    }

    Point getCenter() const
    {
        /*
         * STUDENT ANSWER
         */
    }

    double getRadius() const
    {
        /*
         * STUDENT ANSWER
         */
    }

    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};