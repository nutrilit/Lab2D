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

		/**
	 * @brief Abstrakcyjna metoda, która przekszta³ca poliliniie.
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param points Wektor punktów Point2D do przekszta³cenia.
	 * @param closed Informacja, czy polilinia jest zamkniêta.
	 * @param color Kolor punktów po przekszta³ceniu.
	 * @param x Przesuniêcie wzd³u¿ osi x.
	 * @param y Przesuniêcie wzd³u¿ osi y.
	 */
	virtual void translatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y) = 0;

		/**
	 * @brief Abstrakcyjna metoda, która przekszta³ca wielok¹t.
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param vertices Wektor punktów Point2D do przekszta³cenia.
	 * @param color Kolor punktów po przekszta³ceniu.
	 * @param x Przesuniêcie wzd³u¿ osi x.
	 * @param y Przesuniêcie wzd³u¿ osi y.
	 */
	virtual void translatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y) = 0;

		/**
	 * @brief Abstrakcyjna metoda, która przekszta³ca elipsê.
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param x0 Wspó³rzêdna x œrodka elipsy przed przekszta³ceniem.
	 * @param y0 Wspó³rzêdna y œrodka elipsy przed przekszta³ceniem.
	 * @param RX Promieñ X elipsy przed przekszta³ceniem.
	 * @param RY Promieñ Y elipsy przed przekszta³ceniem.
	 * @param color Kolor elipsy po przekszta³ceniu.
	 * @param x Przesuniêcie wzd³u¿ osi x.
	 * @param y Przesuniêcie wzd³u¿ osi y.
	 */
	virtual void translateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y) = 0;


	/**
	 * @brief Abstrakcyjna metoda, która skaluje punkty polilinii.
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param points Wektor punktów Point2D do przekszta³cenia.
	 * @param closed Informacja, czy polilinia jest zamkniêta.
	 * @param color Kolor punktów po przekszta³ceniu.
	 * @param k Wspó³czynnik skali.
	 */
	virtual void scalePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, double k) = 0;

		/**
	 * @brief Abstrakcyjna metoda, która skaluje wielok¹ta.
	 *
	 * Metoda skaluje wspó³rzêdne wierzcho³ków wielok¹ta zadanego przez wektor punktów Point2D.
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param vertices Wektor punktów Point2D reprezentuj¹cych wierzcho³ki wielok¹ta.
	 * @param color Kolor punktów po przekszta³ceniu.
	 * @param k Wspó³czynnik skali. Wartoœæ k wiêksza ni¿ 1 zwiêksza rozmiar, a mniejsza ni¿ 1 zmniejsza rozmiar.
	 */
	virtual void scalePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, double k) = 0;

		/**
	 * @brief Abstrakcyjna metoda, która skaluje elipsê.
	 *
	 * Metoda skaluje elipsê zdefiniowan¹ przez jej wspó³rzêdne œrodka (x0, y0) i promienie (RX, RY).
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param x0 Wspó³rzêdna x œrodka elipsy przed przekszta³ceniem.
	 * @param y0 Wspó³rzêdna y œrodka elipsy przed przekszta³ceniem.
	 * @param RX Promieñ X elipsy przed przekszta³ceniem.
	 * @param RY Promieñ Y elipsy przed przekszta³ceniem.
	 * @param color Kolor elipsy po przekszta³ceniu.
	 * @param k Wspó³czynnik skali. Wartoœæ k wiêksza ni¿ 1 zwiêksza rozmiar, a mniejsza ni¿ 1 zmniejsza rozmiar.
	 */
	virtual void scaleEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, double k) = 0;

		/**
	 * @brief Abstrakcyjna metoda, która obraca poliliniie.
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param points Wektor punktów Point2D do przekszta³cenia.
	 * @param closed Informacja, czy polilinia jest zamkniêta.
	 * @param color Kolor punktów po przekszta³ceniu.
	 * @param x Wspó³rzêdna x punktu, wzglêdem którego obracane s¹ punkty polilinii.
	 * @param y Wspó³rzêdna y punktu, wzglêdem którego obracane s¹ punkty polilinii.
	 * @param a K¹t obrotu w radianach.
	 */
	virtual void rotatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y, long double a) = 0;

		/**
	 * @brief Abstrakcyjna metoda, która obraca wielok¹ta.
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param vertices Wektor punktów Point2D do przekszta³cenia.
	 * @param color Kolor punktów po przekszta³ceniu.
	 * @param x Wspó³rzêdna x punktu, wzglêdem którego obracane s¹ wierzcho³ki wielok¹ta.
	 * @param y Wspó³rzêdna y punktu, wzglêdem którego obracane s¹ wierzcho³ki wielok¹ta.
	 * @param a K¹t obrotu w radianach.
	 */
	virtual void rotatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y, long double a) = 0;

		/**
	 * @brief Abstrakcyjna metoda, która obraca elipsê.
	 *
	 * @param renderer WskaŸnik do obiektu SDL_Renderer.
	 * @param x0 Wspó³rzêdna x œrodka elipsy przed przekszta³ceniem.
	 * @param y0 Wspó³rzêdna y œrodka elipsy przed przekszta³ceniem.
	 * @param RX Promieñ X elipsy przed przekszta³ceniem.
	 * @param RY Promieñ Y elipsy przed przekszta³ceniem.
	 * @param color Kolor elipsy po przekszta³ceniu.
	 * @param x Wspó³rzêdna x punktu, wzglêdem którego obracane jest elipsy.
	 * @param y Wspó³rzêdna y punktu, wzglêdem którego obracane jest elipsy.
	 * @param a K¹t obrotu w radianach.
	 */
	virtual void rotateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y, long double a) = 0;
};
#pragma endregion

#pragma region (e) Klasa ShapeObject
/**
 * @brief Labolatorium4 - zad1 (e) Klasa ShapeObject
 * @brief Abstrakcyjna klasa ShapeObject dziedzicz¹ca po DrawableObject i TransformableObject.
 *
 * Klasa reprezentuje obiekt, który mo¿e byæ rysowany (DrawableObject) i podlegaæ przekszta³ceniom geometrycznym (TransformableObject).
 */
class ShapeObject : public DrawableObject, public TransformableObject {
public:
		/**
	 * @brief Wirtualny destruktor dla klasy ShapeObject.
	 */
	virtual ~ShapeObject() {}

	// Dziedziczone metody z DrawableObject i TransformableObject
	// Metody te s¹ abstrakcyjne, wiêc musz¹ byæ nadpisane przez klasy pochodne
};
#pragma endregion

#pragma endregion

