#pragma once
#include <iostream>
#include <SDL.h>
#include "GameObject.cpp"
#include "BitmapHandler.h"
#include <SDL_image.h>


/**
 * @brief  Labolatorium5 - zad2 (b)
 * @brief Klasa reprezentuj�ca obiekt graficzny obs�uguj�cy bitmapy.
 *
 * Klasa ta dziedziczy zar�wno po klasie DrawableObject, umo�liwiaj�cej rysowanie obiektu,
 * jak i po BitmapHandler, dostarczaj�cej funkcji obs�ugi obraz�w.
 */
class BitmapObject : public DrawableObject, public BitmapHandler
{
public:

#pragma region Labolatorium5 - zad2 (b)
	/**
* @brief  Labolatorium5 - zad2 (b)
* @brief Funkcja rysuj�ca obiekt na podstawie tekstury i prostok�ta.
*
* @param renderer Wska�nik do obiektu klasy SDL_Renderer, na kt�rym ma by� rysowany obiekt bitmapowy.
* @param Texture Tekstura, kt�r� ma u�y� obiekt do rysowania.
* @param rect Prostok�t okre�laj�cy pozycj� i rozmiar obiektu na ekranie.
*
* Funkcja ta rysuje obiekt bitmapowy na ekranie, korzystaj�c z danej tekstury i prostok�ta.
*/
	void Draw(SDL_Renderer* renderer, SDL_Texture* Texture, SDL_Rect& rect);

	/**
* @brief  Labolatorium5 - zad2 (b)
* @brief Funkcja rysuj�ca prostok�t o okre�lonym kolorze.
*
* @param renderer Wska�nik do obiektu klasy SDL_Renderer, na kt�rym ma by� rysowany prostok�t.
* @param rect1 Prostok�t okre�laj�cy pozycj� i rozmiar prostok�ta na ekranie.
* @param color Kolor prostok�ta, okre�lony jako obiekt klasy SDL_Color.
*
* Funkcja ta rysuje prostok�t o zadanym kolorze na ekranie.
*/
	void Draw(SDL_Renderer* renderer, SDL_Rect rect1, SDL_Color color) override;
#pragma endregion

};


