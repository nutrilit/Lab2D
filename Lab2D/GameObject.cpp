#pragma once
#include <iostream>
#include <SDL.h>
#include <vector>
#include "Point2D.h"

#pragma region Labolatorium4 - zad1

#pragma region (a) Klasa GameObject
	/**
	 * @brief Labolatorium4 - zad1 (a) Klasa GameObject
	 * @brief Klasa reprezentuj�ca og�lny obiekt gry.
	 *
	 */
class GameObject {
public:
	 /**
	 * @brief Wirtualny destruktor dla klasy GameObject.
	 */
	virtual ~GameObject() {}

	  /**
	 * @brief Metoda czysto wirtualna, kt�ra mo�e by� nadpisana w klasach pochodnych.
	 *
	 * Metoda ta jest wywo�ywana przy starcie obiektu gry.
	 */
	virtual void start() {
		std::cout << "GameObject started." << std::endl;
	}
};
#pragma endregion

#pragma region (b) Klasa UpdatableObject
	/**
	 * @brief Labolatorium4 - zad1 (b) Klasa UpdatableObject
	 * @brief Klasa abstrakcyjna reprezentuj�ca obiekt gry, kt�ry mo�e by� aktualizowany.
	 */
class UpdatableObject {
public:
	  /**
	 * @brief Wirtualny destruktor dla klasy UpdatableObject.
	 */
	virtual ~UpdatableObject() {}

      /**
	 * @brief Abstrakcyjna metoda, kt�ra musi by� zaimplementowana w klasach pochodnych.
	 *
	 * Metoda ta jest wywo�ywana podczas aktualizacji obiektu gry.
	 */
	virtual void update() = 0;
};
#pragma endregion

#pragma region (c) Klasa DrawableObject
/**
 * @brief Labolatorium4 - zad1 (c) Klasa DrawableObject
 * @brief Klasa abstrakcyjna reprezentuj�ca obiekt gry, kt�ry mo�e by� rysowany.
 */

class DrawableObject {
public:
		/**
	 * @brief Wirtualny destruktor dla klasy DrawableObject.
	 */
	virtual ~DrawableObject() {}

		/**
	 * @brief Abstrakcyjna metoda, kt�ra musi by� zaimplementowana w klasach pochodnych.
	 *
	 * Metoda ta jest odpowiedzialna za rysowanie obiektu gry.
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param rect1 Struktura reprezentuj�ca prostok�t (przechowuje rozmiar oraz wsp�rz�dne).
	 * @param color Kolor obiektu.
	 */
	virtual void Draw(SDL_Renderer* renderer, SDL_Rect rect1, SDL_Color color) = 0;
};
#pragma endregion

#pragma region (d) Klasa TransformableObject
	/**
	 *  @brief Labolatorium4 - zad1 (d) Klasa TransformableObject
	 * @brief Klasa abstrakcyjna reprezentuj�ca obiekt gry, kt�ry mo�e by� transformowany.
	 */
class TransformableObject {
public:
	/**
	 * @brief Wirtualny destruktor dla klasy TransformableObject.
	 */
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
#pragma endregion

#pragma region (e) Klasa ShapeObject
// (e) Klasa ShapeObject
class ShapeObject : public DrawableObject, public TransformableObject {
public:
	virtual ~ShapeObject() {}

	// Dziedziczone metody z DrawableObject i TransformableObject
	// Metody te s� abstrakcyjne, wi�c musz� by� nadpisane przez klasy pochodne
};
#pragma endregion

#pragma endregion

