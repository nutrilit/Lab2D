#pragma once
#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H
#include <SDL.h>
#include <iostream>
#include "Point2D.h"
#include <vector>
#include "LineSegment.h"
#include <stack>
#include <array>
#include "GameObject.cpp"

/**
 * @brief Klasa PrimitiveRenderer dziedziczaca po ShapeObject.
 */
class PrimitiveRenderer : public ShapeObject
{
public:
	SDL_Rect rect;
#pragma region  Labolatorium2 - zad2
	/**
   * @brief Labolatorium2 - zad2
   * @brief Metoda rysujaca primitywy
   *
   * @param renderer Wskaznik do obiektu SDL_Renderer.
   * @param rect1 strunktura reprezentuj�ca prostok�t (przechowuje rozmiar oraz wspolrzedne).
   * @param color przechowuje informacje o kolorze.
   */
	void Draw(SDL_Renderer* renderer, SDL_Rect rect1, SDL_Color color) override;
#pragma endregion

#pragma region Labolatorium2 - zad3
	/**
   * @brief Labolatorium2 - zad3
   * @brief Metoda rysujaca odcinek wykorzystujaca algorytm przyrostowy
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param x0 Wsp�rz�dna x punktu pocz�tkowego.
   * @param y0 Wsp�rz�dna y punktu pocz�tkowego.
   * @param x1 Wsp�rz�dna x punktu ko�cowego.
   * @param y1 Wsp�rz�dna y punktu ko�cowego.
   * @param color Kolor odcinka.
   */
	void RysLinie(SDL_Renderer* renderer, int x0, int y0, int x1, int y1, SDL_Color color);
#pragma endregion

#pragma region Labolatorium2 - zad6
	/**
   * @brief Labolatorium2 - zad6
   * @brief Metoda rysujaca linie lamana otwarta lub zamknieta przyjujaca zbi�r punkt�w typu Point2D
   *
   * @param renderer Wskaznik do obiektu SDL_Renderer.
   * @param points Wektor punkt�w Point2D do po��czenia odcinkami.
   * @param closed Informacja, czy lamana jest zamknieta.
   * @param color Kolor odcinkow.
   */
	void DrawPolyline(SDL_Renderer* renderer, const std::vector<Point2D>& points, bool closed = false, SDL_Color color = { 255, 255, 255, 255 });
	/**
	* @brief Labolatorium2 - zad6
	* @brief Metoda rysujaca linie lamana otwarta lub zamknieta na podstawie odcink�w z wektora LineSegment.
	*
	* @param renderer Wska�nik do obiektu SDL_Renderer.
	* @param segments Wektor odcink�w LineSegment do narysowania.
	* @param closed Informacja, czy lamana jest zamknieta.
	* @param color Kolor odcink�w.
	*/
	void DrawPolyline2(SDL_Renderer* renderer, const std::vector<LineSegment>& segments, bool closed, SDL_Color color = { 255, 255, 255, 255 });
#pragma endregion

#pragma region Labolatorium3 - zad1
	/**
   * @brief Labolatorium3 - zad1
   * @brief Metoda rysuj�ca okr�g algorytmem przedstawionym w instruckji przy u�yciu 4-krotnej symetrii.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param x0 Wsp�rz�dna x �rodka okr�gu.
   * @param y0 Wsp�rz�dna y �rodka okr�gu.
   * @param R Promie� okr�gu.
   * @param color Kolor okr�gu.
   */
	void DrawCircle4Symmetry(SDL_Renderer* renderer, int x0, int y0, int R, SDL_Color color = { 255, 255, 255, 255 });
#pragma endregion

#pragma region Labolatorium3 - zad2
	/**
   * @brief Labolatorium3 - zad2
   * @brief Metoda rysuj�ca elips� algorytmem przedstawionym w instruckji przy u�yciu 4-krotnej symetrii.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param x0 Wsp�rz�dna x �rodka elipsy.
   * @param y0 Wsp�rz�dna y �rodka elipsy.
   * @param RX P�o� wzd�u� osi x.
   * @param RY P�o� wzd�u� osi y.
   * @param color Kolor elipsy.
   */
	void DrawEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color = { 255, 255, 255, 255 });
#pragma endregion

#pragma region Labolatorium3 - zad3
	/**
   * @brief Labolatorium3 - zad3
   * @brief Metoda rysuj�ca wielok�t na podstawie punkt�w Point2D.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param vertices Wektor wierzcho�k�w wielok�ta.
   * @param color Kolor wielok�ta.
   */
	void DrawPolygon(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color = { 255, 255, 255, 255 });
	/**
   * @brief Labolatorium3 - zad3
   * @brief Metoda rysujaca wielokat na podstawie odcinkow z wektora LineSegment.
   *
   * @param renderer Wskaznik do obiektu SDL_Renderer.
   * @param segments Wektor odcinkow LineSegment do narysowania.
   * @param color Kolor odcink�w.
   */
	void DrawPolygon2(SDL_Renderer* renderer, const std::vector<LineSegment>& segments, SDL_Color color = { 255, 255, 255, 255 });
#pragma endregion

#pragma region Labolatorium3 - zad4,5
	/**
   * @brief Labolatorium3 - zad4,5
   * @brief Metoda wype�niaj�ca obszar algorytmem przez spojnosc FloodFill.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param x Wsp�rz�dna x punktu startowego.
   * @param y Wsp�rz�dna y punktu startowego.
   * @param targetColor Kolor obszaru do zast�pienia.
   * @param fillColor Kolor, kt�rym ma zosta� wype�niony obszar.
   */
	void floodFill(SDL_Renderer* renderer, int x, int y, SDL_Color targetColor, SDL_Color fillColor);
#pragma endregion

#pragma region Labolatorium4 - zad2
	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda (Translacja) przesuwaj�ca punkty o wektor (x, y) i rysuj�ca przesuni�t� polilini�.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param points Wektor punkt�w polilinii do przesuni�cia.
   * @param closed Informacja, czy polilinia jest zamkni�ta.
   * @param color Kolor polilinii.
   * @param x Warto�� przesuni�cia w osi x.
   * @param y Warto�� przesuni�cia w osi y.
   */
	void translatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y) override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda przesuwaj�ca punkty wielok�ta o wektor (x, y) i rysuj�ca przesuni�ty wielok�t.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param vertices Wektor punkt�w wielok�ta do przesuni�cia.
   * @param color Kolor wielok�ta.
   * @param x Warto�� przesuni�cia w osi x.
   * @param y Warto�� przesuni�cia w osi y.
   */
	void translatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda przesuwaj�ca i rysuj�ca elips� o wektor (x, y).
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param x0 Wsp�rz�dna x �rodka elipsy.
   * @param y0 Wsp�rz�dna y �rodka elipsy.
   * @param RX Promie� elipsy w osi x.
   * @param RY Promie� elipsy w osi y.
   * @param color Kolor elipsy.
   * @param x Warto�� przesuni�cia w osi x.
   * @param y Warto�� przesuni�cia w osi y.
   */
	void translateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda skaluj�ca punkty polilinii o wsp�czynnik k i rysuj�ca skalowan� polilini�.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param points Wektor punkt�w polilinii do skalowania.
   * @param closed Informacja, czy polilinia jest zamkni�ta.
   * @param color Kolor polilinii.
   * @param k Wsp�czynnik skali.
   */
	void scalePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, double k)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda skaluj�ca punkty wielok�ta o wsp�czynnik k i rysuj�ca skalowany wielok�t.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param vertices Wektor punkt�w wielok�ta do skalowania.
   * @param color Kolor wielok�ta.
   * @param k Wsp�czynnik skali.
   */
	void scalePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, double k)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda skaluj�ca i rysuj�ca elips� o wsp�czynniku k.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param x0 Wsp�rz�dna x �rodka elipsy.
   * @param y0 Wsp�rz�dna y �rodka elipsy.
   * @param RX Promie� elipsy w osi x.
   * @param RY Promie� elipsy w osi y.
   * @param color Kolor elipsy.
   * @param k Wsp�czynnik skali.
   */
	void scaleEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, double k)override;


	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda obracaj�ca punkty polilinii o dany k�t a i rysuj�ca obr�con� polilini�.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param points Wektor punkt�w polilinii do obr�cenia.
   * @param closed Informacja, czy polilinia jest zamkni�ta.
   * @param color Kolor polilinii.
   * @param x Wsp�rz�dna x punktu obrotu.
   * @param y Wsp�rz�dna y punktu obrotu.
   * @param a K�t obrotu w radianach.
   */
	void rotatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y, long double a)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda obracaj�ca punkty wielok�ta o dany k�t a i rysuj�ca obr�cony wielok�t.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param vertices Wektor punkt�w wielok�ta do obr�cenia.
   * @param color Kolor wielok�ta.
   * @param x Wsp�rz�dna x punktu obrotu.
   * @param y Wsp�rz�dna y punktu obrotu.
   * @param a K�t obrotu w radianach.
   */
	void rotatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y, long double a)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda obracaj�ca i rysuj�ca elips� o dany k�t a.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param x0 Wsp�rz�dna x �rodka elipsy.
   * @param y0 Wsp�rz�dna y �rodka elipsy.
   * @param RX Promie� elipsy w osi x.
   * @param RY Promie� elipsy w osi y.
   * @param color Kolor elipsy.
   * @param x Wsp�rz�dna x punktu obrotu.
   * @param y Wsp�rz�dna y punktu obrotu.
   * @param a K�t obrotu w radianach.
   */
	void rotateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y, long double a)override;
#pragma endregion
};
#endif