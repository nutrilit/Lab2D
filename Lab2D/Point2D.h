#pragma once
#ifndef POINT2D_H
#define POINT2D_H
#include <SDL.h>
#include <iostream>

#pragma region Labolatorium2 - zad4
/**
* @brief Labolatorium2 - zad4
* @brief Klasa reprezentuj¹ca punkt w przestrzeni 2D.
*/
class Point2D
{
public:
	int x, y;
	SDL_Rect rect;
	//PrimitiveRenderer pik1;
	 /**
	* @brief Konstruktor domyœlny bez parametrow
	*/
	Point2D();

	/**
   * @brief Konstruktor tworz¹cy obiekt Point2D na podstawie podanych wspó³rzêdnych.
   *
   * @param x Wspó³rzêdna x punktu.
   * @param y Wspó³rzêdna y punktu.
   */
	Point2D(int x, int y);

	/**
   * @brief Metoda zwracaj¹ca obie wspó³rzêdne punktu.
   *
   * @param  &outX Referencja do zmiennej, w której zostanie zapisana wspó³rzêdna x.
   * @param  &outY Referencja do zmiennej, w której zostanie zapisana wspó³rzêdna y.
   */
	void print_xy(int& outX, int& outY);

	/**
   * @brief Metoda zmieniaj¹ca wspó³rzêdne punktu na nowe wartoœci.
   *
   * @param newX Nowa wartoœæ wspó³rzêdnej x.
   * @param newY Nowa wartoœæ wspó³rzêdnej y.
   */
	void zmien_punkt(int newX, int newY);

	/**
   * @brief Metoda zwracaj¹ca wspó³rzêdn¹ x punktu.
   *
   * @return Wspó³rzêdna x punktu.
  */
	int GetX() const;

	/**
   * @brief Metoda zwracaj¹ca wspó³rzêdn¹ y punktu.
   *
   * @return Wspó³rzêdna y punktu.
   */
	int GetY() const;
	//void rys_piksel(SDL_Renderer* renderer);
};
#pragma endregion

#endif

