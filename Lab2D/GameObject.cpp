#pragma once
#include <iostream>
#include <SDL.h>
#include <vector>
#include "Point2D.h"

#pragma region Labolatorium4 - zad1

#pragma region (a) Klasa GameObject
	/**
	 * @brief Labolatorium4 - zad1 (a) Klasa GameObject
	 * @brief Klasa reprezentuj¹ca ogólny obiekt gry.
	 *
	 */
class GameObject {
public:
	 /**
	 * @brief Wirtualny destruktor dla klasy GameObject.
	 */
	virtual ~GameObject() {}

	  /**
	 * @brief Metoda czysto wirtualna, która mo¿e byæ nadpisana w klasach pochodnych.
	 *
	 * Metoda ta jest wywo³ywana przy starcie obiektu gry.
	 */
	virtual void start() {
		std::cout << "GameObject started." << std::endl;
	}
};
#pragma endregion

#pragma region (b) Klasa UpdatableObject
	/**
	 * @brief Labolatorium4 - zad1 (b) Klasa UpdatableObject
	 * @brief Klasa abstrakcyjna reprezentuj¹ca obiekt gry, który mo¿e byæ aktualizowany.
	 */
class UpdatableObject {
public:
	  /**
	 * @brief Wirtualny destruktor dla klasy UpdatableObject.
	 */
	virtual ~UpdatableObject() {}

      /**
	 * @brief Abstrakcyjna metoda, która musi byæ zaimplementowana w klasach pochodnych.
	 *
	 * Metoda ta jest wywo³ywana podczas aktualizacji obiektu gry.
	 */
	virtual void update() = 0;
};
#pragma endregion

#pragma region (c) Klasa DrawableObject
/**
 * @brief Labolatorium4 - zad1 (c) Klasa DrawableObject
 * @brief Klasa abstrakcyjna reprezentuj¹ca obiekt gry, który mo¿e byæ rysowany.
 */

class DrawableObject {
public:
		/**
	 * @brief Wirtualny destruktor dla klasy DrawableObject.
	 */
	virtual ~DrawableObject() {}

		/**
	 * @brief Abstrakcyjna metoda, która musi byæ zaimplementowana w klasach pochodnych.
	 *
	 * Metoda ta jest odpowiedzialna za rysowanie obiektu gry.
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param rect1 Struktura reprezentuj¹ca prostok¹t (przechowuje rozmiar oraz wspó³rzêdne).
	 * @param color Kolor obiektu.
	 */
	virtual void Draw(SDL_Renderer* renderer, SDL_Rect rect1, SDL_Color color) = 0;
};
#pragma endregion

#pragma region (d) Klasa TransformableObject
	/**
	 *  @brief Labolatorium4 - zad1 (d) Klasa TransformableObject
	 * @brief Klasa abstrakcyjna reprezentuj¹ca obiekt gry, który mo¿e byæ transformowany.
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
	// Metody te s¹ abstrakcyjne, wiêc musz¹ byæ nadpisane przez klasy pochodne
};
#pragma endregion

#pragma endregion

