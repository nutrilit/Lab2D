#pragma once
#include <iostream>
#include <SDL.h>
#include <vector>
#include "Point2D.h"
// (a) Klasa GameObject
class GameObject {
public:
    virtual ~GameObject() {}

    // Metody czysto wirtualne
   // virtual void update() = 0;
   // virtual void draw() const = 0;
    // Metoda z cia³em (mo¿e byæ nadpisana)
    virtual void start() {
        std::cout << "GameObject started." << std::endl;
    }
};

// (b) Klasa UpdatableObject
class UpdatableObject  {
public:
    virtual ~UpdatableObject() {}

    // Abstrakcyjna metoda update()
    virtual void update() = 0;
};

// (c) Klasa DrawableObject
class DrawableObject  {
public:
    virtual ~DrawableObject() {}

    // Abstrakcyjna metoda draw()
    virtual void Draw(SDL_Renderer* renderer, SDL_Rect rect1, SDL_Color color)= 0;
};

// (d) Klasa TransformableObject
class TransformableObject {
public:
    virtual ~TransformableObject() {}
   

    // Abstrakcyjne metody translate(), rotate() i scale()
    virtual void translatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y) = 0;
    virtual void translatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y) = 0;
    virtual void translateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y) = 0;
    //scale
    virtual void scalePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, double k) = 0;
    virtual void scalePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, double k) = 0;
    virtual void scaleEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, double k) = 0;
    //rotate
    virtual void rotatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y, long double a) = 0;
    virtual void rotatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y, long double a) = 0;
    virtual void rotateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y, long double a) = 0;
};

// (e) Klasa ShapeObject
class ShapeObject : public DrawableObject, public TransformableObject {
public:
    virtual ~ShapeObject() {}

    // Dziedziczone metody z DrawableObject i TransformableObject
    // Metody te s¹ abstrakcyjne, wiêc musz¹ byæ nadpisane przez klasy pochodne
};

