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
        color=(char*)malloc(sizeof(char)*strlen(p+1));
        strcpy(color,p);
    }
    Rectangle()
    {
        length = 0;
        width = 0;
        color = NULL;
    }
    Rectangle(const Rectangle &o)
    {
        length = o.length;
        width = o.width;
        int len = strlen(o.color)+1;
        color = new char[len];
        strcpy(color,o.color);
    }
    Rectangle* clone()
    {
       Rectangle *r = new Rectangle;
       r->color = new char[strlen(color)+1];
       strcpy(r->color,color);
       r->length = length;
       r->width = width;
       return r;
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
        color = NULL;
        //strcpy(color,p);
    }
    Triangle(const Triangle &o)
    {
        a = o.a;
        b = o.b;
        c = o.c;
        int len = strlen(o.color)+1;
        color = new char[len];
        strcpy(color,o.color);
    }
    Triangle* clone()
    {
        Triangle *t = new Triangle;
        t->color = new char[strlen(color)+1];
        strcpy(t->color, color);
        t->a = a;
        t->b = b;
        t->c = c;
        return t;
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
        color = NULL;
    }
    Circle(const Circle &o)
    {
        radius = o.radius;
        int len = strlen(o.color)+1;
        color = new char[len];
        strcpy(color,o.color);
    }
    Circle* clone()
    {
        Circle *c= new Circle;
        c->color = new char[strlen(color)+1];
        strcpy(c->color, color);
        c->radius = radius;
        return c;
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
    Rectangle *rect;
    Circle *cir;
    Triangle *tri;
    int rectcount;
    int circount;
    int tricount;
    int rcapacity;
    int ccapacity;
    int tcapacity;
public:
ShapeCollection()
{
    rectcount = circount = tricount = 0; 
    rcapacity = ccapacity = tcapacity = 1;
    rect = new Rectangle[rcapacity];
    cir = new Circle[ccapacity];
    tri = new Triangle[tcapacity];
}
~ShapeCollection()
{
    delete [] rect;
    delete [] cir;
    delete [] tri;
}

void resize_r(int rcapacity)
{
    cout<<"Increasing capacity of Rectangles from "<<rcapacity<<" to "<<rcapacity*2<<endl;
    Rectangle *newR = new Rectangle[rcapacity*2];
    for(int i = 0; i<rectcount; i++)
    {   
        Rectangle *x = rect[i].clone();
        newR[i] = *x;
    }
    delete[] rect;
    rect = newR;
    rcapacity = rcapacity*2;
}
void resize_c(int ccapacity)
{
    cout<<"Increasing capacity of Circles from "<<ccapacity<<" to "<<ccapacity*2<<endl;
    Circle *newC = new Circle[ccapacity*2];
    for(int i = 0; i<circount; i++)
    {
       Circle *x = cir[i].clone();
        newC[i] = *x;
    }
    delete[] cir;
    cir = newC;
    ccapacity = ccapacity*2;
}
void resize_t(int tcapacity)
{
    cout<<"Increasing capacity of Triangles from "<<tcapacity<<" to "<<tcapacity*2<<endl;
    Triangle *newT = new Triangle[tcapacity*2];
    for(int i = 0; i<tricount; i++)
    {
        Triangle *x = tri[i].clone();
        newT[i] = *x;
    }
    delete[] tri;
    tri = newT;
    tcapacity = tcapacity*2;
}



void add( Rectangle ob)
{
    if(rectcount+1 > rcapacity)
    {
        resize_r(rcapacity);
    }
    rect[rectcount] = ob;
    rectcount++;
}
void add( Triangle ob)

{
    if(tricount+1 > tcapacity)
    {
        resize_t(tcapacity);
    }
    tri[tricount] = ob;
    tricount++;
}
void add( Circle ob)
{
    if(circount+1 > ccapacity)
    {
        resize_c(ccapacity);
    }
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
    shapes.add(r1);
    shapes.add(t1);
    shapes.add(c1);
 
    Rectangle r2(15, 25, "Black");
    shapes.add(r2);
    Triangle t2(5, 12, 13, "White");
    shapes.add(t2);
    Rectangle r3(150,225,"White");
    shapes.add(r3);
 
    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;
 
    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();
 
    return 0;
}