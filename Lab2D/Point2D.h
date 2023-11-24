#pragma once
#ifndef POINT2D_H
#define POINT2D_H
#include <SDL.h>
#include <iostream>

#pragma region Labolatorium2 - zad4
/**
* @brief Labolatorium2 - zad4
* @brief Klasa reprezentuj�ca punkt w przestrzeni 2D.
*/
class Point2D
{
public:
	int x, y;
	SDL_Rect rect;
	//PrimitiveRenderer pik1;
	 /**
	* @brief Konstruktor domy�lny bez parametrow
	*/
	Point2D();

	/**
   * @brief Konstruktor tworz�cy obiekt Point2D na podstawie podanych wsp�rz�dnych.
   *
   * @param x Wsp�rz�dna x punktu.
   * @param y Wsp�rz�dna y punktu.
   */
	Point2D(int x, int y);

	/**
   * @brief Metoda zwracaj�ca obie wsp�rz�dne punktu.
   *
   * @param  &outX Referencja do zmiennej, w kt�rej zostanie zapisana wsp�rz�dna x.
   * @param  &outY Referencja do zmiennej, w kt�rej zostanie zapisana wsp�rz�dna y.
   */
	void print_xy(int& outX, int& outY);

	/**
   * @brief Metoda zmieniaj�ca wsp�rz�dne punktu na nowe warto�ci.
   *
   * @param newX Nowa warto�� wsp�rz�dnej x.
   * @param newY Nowa warto�� wsp�rz�dnej y.
   */
	void zmien_punkt(int newX, int newY);

	/**
   * @brief Metoda zwracaj�ca wsp�rz�dn� x punktu.
   *
   * @return Wsp�rz�dna x punktu.
  */
	int GetX() const;

	/**
   * @brief Metoda zwracaj�ca wsp�rz�dn� y punktu.
   *
   * @return Wsp�rz�dna y punktu.
   */
	int GetY() const;
	//void rys_piksel(SDL_Renderer* renderer);
};
#pragma endregion

#endif

