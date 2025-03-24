#include<iostream>
using namespace std;

class Shape
{
    public:
    virtual void area() = 0;
};

class Circle : public Shape
{
    private:
    int radius;
    public:
    Circle(int r)
    {
        radius = r;
    }
    void area()
    {
        cout<<"Area of Circle: "<<3.14*radius*radius<<endl;
    }
};

class Rectangle : public Shape
{
    private:
    int length;
    int breadth;
    public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    void area()
    {
        cout<<"Area of Rectangle: "<<length*breadth<<endl;
    }
};

int main()
{
    Circle c(5);
    Rectangle r(5, 10);
    c.area();
    r.area();
    return 0;
}