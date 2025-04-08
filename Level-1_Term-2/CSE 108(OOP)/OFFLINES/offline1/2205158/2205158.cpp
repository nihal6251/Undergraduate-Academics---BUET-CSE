#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Rectangle
{
    int length, width;
    char *color;

public:
    Rectangle(int a, int b, const char *p)
    {
        length = a;
        width = b;
        color=(char*)malloc(sizeof(char)*strlen(p));
        strcpy(color,p);
    }
    Rectangle()
    {
        length = 0;
        width = 0;
        color = (char*)malloc(sizeof(char)*20);
    }
    ~Rectangle()
    {
        delete[] color;
    }
    int getPerimeter()
    {
        return 2*(length+width);
    }
    int getArea()
    {
        return length*width;
    }
    char* getColor()
    {
        return color;
    }
    void setColor(const char *newColor)
    {
        free(color);
        color = (char*)malloc(sizeof(char)*strlen(newColor));
        strcpy(color,newColor);
    }
    int getlength()
    {
        return length;
    }
    int getwidth()
    {
        return width;
    }
};

class Triangle
{
    int a,b,c;
    char* color;
public:
    Triangle(int l1, int l2, int l3, const char* p)
    {
        a = l1;
        b = l2;
        c = l3;
        color = (char*)malloc(sizeof(char)*strlen(p));
        strcpy(color,p);
    }
    Triangle()
    {
        a = 0;
        b = 0;
        c = 0;
        color = (char*)malloc(sizeof(char)*20);
        //strcpy(color,p);
    }
    ~Triangle()
    {
        delete[] color;
    }

    int getPerimeter()
    {
        return a+b+c;
    }
    int getArea()
    {
        int s = (a+b+c)/2;
        int area = sqrt(s*(s-a)*(s-b)*(s-c));
        return area;
    }
    char* getColor()
    {
        return color;
    }
    void setColor(const char *newColor)
    {
        free(color);
        color = (char*)malloc(sizeof(char)*strlen(newColor));
        strcpy(color,newColor);
    }
    int geta()
    {
        return a;
    }
    int getb()
    {
        return b;
    }
    int getc()
    {
        return c;
    }
};
class Circle
{
    int radius;
    char* color;
public:
    Circle(int r, const char* p)
    {
        radius = r;
        color = (char*)malloc(sizeof(char)*strlen(p));
        strcpy(color,p);
    }
    Circle()
    {
        radius = 0;
        color = (char*)malloc(sizeof(char)*20);
    }
    ~Circle()
    {
        delete[] color;
    }
    int getPerimeter()
    {
        return 2*3.1414*radius;
    }
    int getArea()
    {
        return 3.1416*radius*radius;
    }
    char* getColor()
    {
        return color;
    }
    void setColor(const char *newColor)
    {
        free(color);
        color = (char*)malloc(sizeof(char)*strlen(newColor));
        strcpy(color,newColor);
    }

    int getradius()
    {
        return radius;
    }
    

};

class ShapeCollection
{
    Rectangle rect[100];
    Circle cir[100];
    Triangle tri[100];
    int rectcount = 0;
    int circount = 0;
    int tricount = 0;
public:

void addRectangle( Rectangle &ob)
{
    rect[rectcount] = ob;
    rectcount++;
}
void addTriangle( Triangle &ob)

{
    tri[tricount] = ob;
    tricount++;
}
void addCircle( Circle &ob)
{
    cir[circount] = ob;
    circount++;
}
int getRectCount()
{
    return rectcount;
}
int getTriCount()
{
    return tricount;
}
int getCircCount()
{
    return circount;
}
void printRectangles()
{

    for(int i = 0; i<rectcount; i++)
    {
        printf("Rectangle %d : length : %d width : %d\n", i, rect[i].getlength(), rect[i].getwidth());
    }
}
void printTriangles()
{

    for(int i = 0; i<tricount; i++)
    {
        printf("Triangle %d : a : %d b : %d c : %d\n", i, tri[i].geta(), tri[i].getb(), tri[i].getc() );
    }
}
void printCircles()
{
    for(int i = 0; i<circount; i++)
    {
        printf("Circle: %d radius: %d\n", i, cir[i].getradius());
    }
}
};

int main() {
    // Create rectangle with length, width, color
    Rectangle r1(10, 20, "Red");
    // The Color is stored using malloc, which will be freed during destruction
    cout << "Rectangle Perimeter: " << r1.getPerimeter() << endl;
    cout << "Rectangle Area: " << r1.getArea() << endl;
    cout << "Rectangle Color: " << r1.getColor() << endl;
    // When changing the color, you need to free the memory of the old color
    // and allocate new memory for the new color
    r1.setColor("Yellow");
    cout << "Rectangle Color: " << r1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    // Create triangle with a, b, c, color. (a, b, c are lengths of the sides)
    Triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    // Create circle with radius, color
    Circle c1(7, "Green");
    cout << "Circle Perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle Area: " << c1.getArea() << endl;
    cout << "Circle Color: " << c1.getColor() << endl;
    c1.setColor("Purple");
    cout << "Circle Color: " << c1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    ShapeCollection shapes;
    /*
    When constructing the ShapeCollection class, you will create static arrays for 100 
    rectangles, triangles and circles. You don’t have to dynamically allocate memory for this.
    */ 
    // ShapeCollection shapes;
    // /* IMPORTANT: You need to pass the objects by reference to the add functions
    // If you pass by value, the copy constructor will be called and the dynamically
    // allocated memory will be copied, leading to double free errors when things go 
    // out of scope. Once passed by reference, do not directly store the reference in 
    // the array. Instead, copy the data from the reference to the array element.
    // We will see better ways to handle this in the upcoming sessions.
    // */ 
    shapes.addRectangle(r1);
    shapes.addTriangle(t1);
    shapes.addCircle(c1);
 
    Rectangle r2(15, 25, "Black");
    shapes.addRectangle(r2);
    Triangle t2(5, 12, 13, "White");
    shapes.addTriangle(t2);
 
    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;
 
    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();
 
    return 0;
}