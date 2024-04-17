#include <iostream>
#include <assert.h>
#include <stdlib.h>

struct Point{
    int x; int y;
};

struct Shape{
    enum EType {circle, square, rhomb};
    EType type_;
};

struct Circle{
    Shape::EType type_;
    double radius_;
    Point center_;
};

struct Square{
    Shape::EType type_;
    double side_;
    Point center_;
};

struct Rhomb{
    Shape::EType type_;
    double side_;
    Point center_;
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
        switch (s->type_){
            case Shape::square:
                drawSquare((struct Square*)s);
                break;
            case Shape::circle:
                drawCircle((struct Circle*)s);
                break;
            default:
                assert(0);
                exit(0);
        }
    }
}

void moveShapes(Shape** shapes, int n, int translationValue){
    for (int i=0; i<n; ++i){
        struct Shape* s = shapes[i];
        switch (s->type_){
            case Shape::square:
                ((struct Square*)s)->center_.x+=translationValue;
                ((struct Square*)s)->center_.y+=translationValue;
                break;
            case Shape::circle:
                ((struct Circle*)s)->center_.x+=translationValue;
                ((struct Circle*)s)->center_.y+=translationValue;
                break;
            case Shape::rhomb:
                ((struct Rhomb*)s)->center_.x+=translationValue;
                ((struct Rhomb*)s)->center_.y+=translationValue;
            default:
                assert(0);
                exit(0);
        }
    }
}

void defineCenterOfShape(Shape* shape, int x, int y){
    ((struct Square*)shape)->center_.x=x;
    ((struct Square*)shape)->center_.y=y;
}

void outputShapes(Shape** shapes, int n){
    for (int i=0; i<n; i++){
        struct Shape* s = shapes[i];
        switch (s->type_){
            case Shape::square:
                std::cerr << "Square center: (" << ((struct Square*)s)->center_.x << " " << ((struct Square*)s)->center_.y << ")\n";
                break;
            case Shape::circle:
                std::cerr << "Circle center: (" << ((struct Circle*)s)->center_.x << " " << ((struct Circle*)s)->center_.y << ")\n";
                break;
            case Shape::rhomb:
                std::cerr << "Rhomb center: (" << ((struct Rhomb*)s)->center_.x << " " << ((struct Rhomb*)s)->center_.y << ")\n";
                break;
            default:
                assert(0);
                exit(0);
        }
    }
}

int main(){
    Shape* shapes[4];
    shapes[0]=(Shape*)new Circle;
    shapes[0]->type_=Shape::circle;
    shapes[1]=(Shape*)new Square;
    shapes[1]->type_=Shape::square;
    shapes[2]=(Shape*)new Square;
    shapes[2]->type_=Shape::square;
    shapes[3]=(Shape*)new Circle;
    shapes[3]->type_=Shape::circle;

    drawShapes(shapes, 4);

    //0. task
    defineCenterOfShape(shapes[0], 0, 0);
    defineCenterOfShape(shapes[1], 1, 1);
    defineCenterOfShape(shapes[2], 2, 2);
    defineCenterOfShape(shapes[3], 3, 3);
    moveShapes(shapes, 4, 1);

    //Output
    outputShapes(shapes, 4);

    Shape* new_shapes[2];
    new_shapes[0]=(Shape*)new Circle;
    new_shapes[0]->type_=Shape::circle;
    new_shapes[1]=(Shape*)new Rhomb;
    new_shapes[1]->type_=Shape::rhomb;
    //assertion failed as there is no Rhomb case in drawShapes method
    drawShapes(new_shapes, 2);
}