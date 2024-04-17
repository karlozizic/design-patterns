#include <iostream>
#include <assert.h>
#include <stdlib.h>

struct Point{
    int x; int y;
};

class Shape{
    public:
        Point center_;
        virtual void draw()=0;
};

class Circle : public Shape{
    public:
        double radius_;
        void draw(){
            std::cerr <<"in drawCircle\n";
        }

};

class Square : public Shape{
    public:
        double side_;
        void draw(){
            std::cerr <<"in drawSquare\n";
        }
};

class Rhomb : public Shape{
    public:
        double side_;
        void draw(){
            std::cerr <<"in drawRhomb\n";
        }
};


void drawSquare(struct Square*){
    std::cerr <<"in drawSquare\n";
}

void drawCircle(struct Circle*){
    std::cerr <<"in drawCircle\n";
}

void drawRhomb(struct Rhomb*){
    std::cerr <<"in drawRhomb\n";
}

void drawShapes(Shape** shapes, int n){
    for (int i=0; i<n; ++i){
        struct Shape* s = shapes[i];
        s->draw();
    }
}

void moveShapes(Shape** shapes, int n, int translationValue){
    for (int i=0; i<n; ++i){
        struct Shape* s = shapes[i];
        s->center_.x+=translationValue;
        s->center_.y+=translationValue;
    }
}

void defineCenterOfShape(Shape* shape, int x, int y){
    ((struct Square*)shape)->center_.x=x;
    ((struct Square*)shape)->center_.y=y;
}

void outputShapes(Shape** shapes, int n){
    for (int i=0; i<n; i++){
        struct Shape* s = shapes[i];
        std::cerr << "Shape " << i << " center: (" << s->center_.x << " " << s->center_.y << ")\n";
    }
}

int main(){
    Shape* shapes[5];
    shapes[0]=(Shape*)new Circle;
    shapes[1]=(Shape*)new Square;
    shapes[2]=(Shape*)new Square;
    shapes[3]=(Shape*)new Circle;
    shapes[4]=(Shape*)new Rhomb;
    drawShapes(shapes, 5);

    //0. task
    defineCenterOfShape(shapes[0], 0, 0);
    defineCenterOfShape(shapes[1], 1, 1);
    defineCenterOfShape(shapes[2], 2, 2);
    defineCenterOfShape(shapes[3], 3, 3);
    moveShapes(shapes, 4, 1);
    outputShapes(shapes, 4);
}