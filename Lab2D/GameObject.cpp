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

		/**
	 * @brief Abstrakcyjna metoda, kt�ra przekszta�ca poliliniie.
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param points Wektor punkt�w Point2D do przekszta�cenia.
	 * @param closed Informacja, czy polilinia jest zamkni�ta.
	 * @param color Kolor punkt�w po przekszta�ceniu.
	 * @param x Przesuni�cie wzd�u� osi x.
	 * @param y Przesuni�cie wzd�u� osi y.
	 */
	virtual void translatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y) = 0;

		/**
	 * @brief Abstrakcyjna metoda, kt�ra przekszta�ca wielok�t.
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param vertices Wektor punkt�w Point2D do przekszta�cenia.
	 * @param color Kolor punkt�w po przekszta�ceniu.
	 * @param x Przesuni�cie wzd�u� osi x.
	 * @param y Przesuni�cie wzd�u� osi y.
	 */
	virtual void translatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y) = 0;

		/**
	 * @brief Abstrakcyjna metoda, kt�ra przekszta�ca elips�.
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param x0 Wsp�rz�dna x �rodka elipsy przed przekszta�ceniem.
	 * @param y0 Wsp�rz�dna y �rodka elipsy przed przekszta�ceniem.
	 * @param RX Promie� X elipsy przed przekszta�ceniem.
	 * @param RY Promie� Y elipsy przed przekszta�ceniem.
	 * @param color Kolor elipsy po przekszta�ceniu.
	 * @param x Przesuni�cie wzd�u� osi x.
	 * @param y Przesuni�cie wzd�u� osi y.
	 */
	virtual void translateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y) = 0;


	/**
	 * @brief Abstrakcyjna metoda, kt�ra skaluje punkty polilinii.
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param points Wektor punkt�w Point2D do przekszta�cenia.
	 * @param closed Informacja, czy polilinia jest zamkni�ta.
	 * @param color Kolor punkt�w po przekszta�ceniu.
	 * @param k Wsp�czynnik skali.
	 */
	virtual void scalePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, double k) = 0;

		/**
	 * @brief Abstrakcyjna metoda, kt�ra skaluje wielok�ta.
	 *
	 * Metoda skaluje wsp�rz�dne wierzcho�k�w wielok�ta zadanego przez wektor punkt�w Point2D.
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param vertices Wektor punkt�w Point2D reprezentuj�cych wierzcho�ki wielok�ta.
	 * @param color Kolor punkt�w po przekszta�ceniu.
	 * @param k Wsp�czynnik skali. Warto�� k wi�ksza ni� 1 zwi�ksza rozmiar, a mniejsza ni� 1 zmniejsza rozmiar.
	 */
	virtual void scalePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, double k) = 0;

		/**
	 * @brief Abstrakcyjna metoda, kt�ra skaluje elips�.
	 *
	 * Metoda skaluje elips� zdefiniowan� przez jej wsp�rz�dne �rodka (x0, y0) i promienie (RX, RY).
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param x0 Wsp�rz�dna x �rodka elipsy przed przekszta�ceniem.
	 * @param y0 Wsp�rz�dna y �rodka elipsy przed przekszta�ceniem.
	 * @param RX Promie� X elipsy przed przekszta�ceniem.
	 * @param RY Promie� Y elipsy przed przekszta�ceniem.
	 * @param color Kolor elipsy po przekszta�ceniu.
	 * @param k Wsp�czynnik skali. Warto�� k wi�ksza ni� 1 zwi�ksza rozmiar, a mniejsza ni� 1 zmniejsza rozmiar.
	 */
	virtual void scaleEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, double k) = 0;

		/**
	 * @brief Abstrakcyjna metoda, kt�ra obraca poliliniie.
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param points Wektor punkt�w Point2D do przekszta�cenia.
	 * @param closed Informacja, czy polilinia jest zamkni�ta.
	 * @param color Kolor punkt�w po przekszta�ceniu.
	 * @param x Wsp�rz�dna x punktu, wzgl�dem kt�rego obracane s� punkty polilinii.
	 * @param y Wsp�rz�dna y punktu, wzgl�dem kt�rego obracane s� punkty polilinii.
	 * @param a K�t obrotu w radianach.
	 */
	virtual void rotatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y, long double a) = 0;

		/**
	 * @brief Abstrakcyjna metoda, kt�ra obraca wielok�ta.
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param vertices Wektor punkt�w Point2D do przekszta�cenia.
	 * @param color Kolor punkt�w po przekszta�ceniu.
	 * @param x Wsp�rz�dna x punktu, wzgl�dem kt�rego obracane s� wierzcho�ki wielok�ta.
	 * @param y Wsp�rz�dna y punktu, wzgl�dem kt�rego obracane s� wierzcho�ki wielok�ta.
	 * @param a K�t obrotu w radianach.
	 */
	virtual void rotatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y, long double a) = 0;

		/**
	 * @brief Abstrakcyjna metoda, kt�ra obraca elips�.
	 *
	 * @param renderer Wska�nik do obiektu SDL_Renderer.
	 * @param x0 Wsp�rz�dna x �rodka elipsy przed przekszta�ceniem.
	 * @param y0 Wsp�rz�dna y �rodka elipsy przed przekszta�ceniem.
	 * @param RX Promie� X elipsy przed przekszta�ceniem.
	 * @param RY Promie� Y elipsy przed przekszta�ceniem.
	 * @param color Kolor elipsy po przekszta�ceniu.
	 * @param x Wsp�rz�dna x punktu, wzgl�dem kt�rego obracane jest elipsy.
	 * @param y Wsp�rz�dna y punktu, wzgl�dem kt�rego obracane jest elipsy.
	 * @param a K�t obrotu w radianach.
	 */
	virtual void rotateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y, long double a) = 0;
};
#pragma endregion

#pragma region (e) Klasa ShapeObject
/**
 * @brief Labolatorium4 - zad1 (e) Klasa ShapeObject
 * @brief Abstrakcyjna klasa ShapeObject dziedzicz�ca po DrawableObject i TransformableObject.
 *
 * Klasa reprezentuje obiekt, kt�ry mo�e by� rysowany (DrawableObject) i podlega� przekszta�ceniom geometrycznym (TransformableObject).
 */
class ShapeObject : public DrawableObject, public TransformableObject {
public:
		/**
	 * @brief Wirtualny destruktor dla klasy ShapeObject.
	 */
	virtual ~ShapeObject() {}

	// Dziedziczone metody z DrawableObject i TransformableObject
	// Metody te s� abstrakcyjne, wi�c musz� by� nadpisane przez klasy pochodne
};
#pragma endregion

#pragma endregion

