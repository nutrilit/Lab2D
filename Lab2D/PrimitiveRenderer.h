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
   * @param rect1 strunktura reprezentuj¹ca prostok¹t (przechowuje rozmiar oraz wspolrzedne).
   * @param color przechowuje informacje o kolorze.
   */
	void Draw(SDL_Renderer* renderer, SDL_Rect rect1, SDL_Color color) override;
#pragma endregion

#pragma region Labolatorium2 - zad3
	/**
   * @brief Labolatorium2 - zad3
   * @brief Metoda rysujaca odcinek wykorzystujaca algorytm przyrostowy
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param x0 Wspó³rzêdna x punktu pocz¹tkowego.
   * @param y0 Wspó³rzêdna y punktu pocz¹tkowego.
   * @param x1 Wspó³rzêdna x punktu koñcowego.
   * @param y1 Wspó³rzêdna y punktu koñcowego.
   * @param color Kolor odcinka.
   */
	void RysLinie(SDL_Renderer* renderer, int x0, int y0, int x1, int y1, SDL_Color color);
#pragma endregion

#pragma region Labolatorium2 - zad6
	/**
   * @brief Labolatorium2 - zad6
   * @brief Metoda rysujaca linie lamana otwarta lub zamknieta przyjujaca zbiór punktów typu Point2D
   *
   * @param renderer Wskaznik do obiektu SDL_Renderer.
   * @param points Wektor punktów Point2D do po³¹czenia odcinkami.
   * @param closed Informacja, czy lamana jest zamknieta.
   * @param color Kolor odcinkow.
   */
	void DrawPolyline(SDL_Renderer* renderer, const std::vector<Point2D>& points, bool closed = false, SDL_Color color = { 255, 255, 255, 255 });
	/**
	* @brief Labolatorium2 - zad6
	* @brief Metoda rysujaca linie lamana otwarta lub zamknieta na podstawie odcinków z wektora LineSegment.
	*
	* @param renderer WskaŸnik do obiektu SDL_Renderer.
	* @param segments Wektor odcinków LineSegment do narysowania.
	* @param closed Informacja, czy lamana jest zamknieta.
	* @param color Kolor odcinków.
	*/
	void DrawPolyline2(SDL_Renderer* renderer, const std::vector<LineSegment>& segments, bool closed, SDL_Color color = { 255, 255, 255, 255 });
#pragma endregion

#pragma region Labolatorium3 - zad1
	/**
   * @brief Labolatorium3 - zad1
   * @brief Metoda rysuj¹ca okr¹g algorytmem przedstawionym w instruckji przy u¿yciu 4-krotnej symetrii.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param x0 Wspó³rzêdna x œrodka okrêgu.
   * @param y0 Wspó³rzêdna y œrodka okrêgu.
   * @param R Promieñ okrêgu.
   * @param color Kolor okrêgu.
   */
	void DrawCircle4Symmetry(SDL_Renderer* renderer, int x0, int y0, int R, SDL_Color color = { 255, 255, 255, 255 });
#pragma endregion

#pragma region Labolatorium3 - zad2
	/**
   * @brief Labolatorium3 - zad2
   * @brief Metoda rysuj¹ca elipsê algorytmem przedstawionym w instruckji przy u¿yciu 4-krotnej symetrii.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param x0 Wspó³rzêdna x œrodka elipsy.
   * @param y0 Wspó³rzêdna y œrodka elipsy.
   * @param RX Pó³oœ wzd³u¿ osi x.
   * @param RY Pó³oœ wzd³u¿ osi y.
   * @param color Kolor elipsy.
   */
	void DrawEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color = { 255, 255, 255, 255 });
#pragma endregion

#pragma region Labolatorium3 - zad3
	/**
   * @brief Labolatorium3 - zad3
   * @brief Metoda rysuj¹ca wielok¹t na podstawie punktów Point2D.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param vertices Wektor wierzcho³ków wielok¹ta.
   * @param color Kolor wielok¹ta.
   */
	void DrawPolygon(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color = { 255, 255, 255, 255 });
	/**
   * @brief Labolatorium3 - zad3
   * @brief Metoda rysujaca wielokat na podstawie odcinkow z wektora LineSegment.
   *
   * @param renderer Wskaznik do obiektu SDL_Renderer.
   * @param segments Wektor odcinkow LineSegment do narysowania.
   * @param color Kolor odcinków.
   */
	void DrawPolygon2(SDL_Renderer* renderer, const std::vector<LineSegment>& segments, SDL_Color color = { 255, 255, 255, 255 });
#pragma endregion

#pragma region Labolatorium3 - zad4,5
	/**
   * @brief Labolatorium3 - zad4,5
   * @brief Metoda wype³niaj¹ca obszar algorytmem przez spojnosc FloodFill.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param x Wspó³rzêdna x punktu startowego.
   * @param y Wspó³rzêdna y punktu startowego.
   * @param targetColor Kolor obszaru do zast¹pienia.
   * @param fillColor Kolor, którym ma zostaæ wype³niony obszar.
   */
	void floodFill(SDL_Renderer* renderer, int x, int y, SDL_Color targetColor, SDL_Color fillColor);
#pragma endregion

#pragma region Labolatorium4 - zad2
	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda (Translacja) przesuwaj¹ca punkty o wektor (x, y) i rysuj¹ca przesuniêt¹ poliliniê.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param points Wektor punktów polilinii do przesuniêcia.
   * @param closed Informacja, czy polilinia jest zamkniêta.
   * @param color Kolor polilinii.
   * @param x Wartoœæ przesuniêcia w osi x.
   * @param y Wartoœæ przesuniêcia w osi y.
   */
	void translatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y) override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda przesuwaj¹ca punkty wielok¹ta o wektor (x, y) i rysuj¹ca przesuniêty wielok¹t.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param vertices Wektor punktów wielok¹ta do przesuniêcia.
   * @param color Kolor wielok¹ta.
   * @param x Wartoœæ przesuniêcia w osi x.
   * @param y Wartoœæ przesuniêcia w osi y.
   */
	void translatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda przesuwaj¹ca i rysuj¹ca elipsê o wektor (x, y).
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param x0 Wspó³rzêdna x œrodka elipsy.
   * @param y0 Wspó³rzêdna y œrodka elipsy.
   * @param RX Promieñ elipsy w osi x.
   * @param RY Promieñ elipsy w osi y.
   * @param color Kolor elipsy.
   * @param x Wartoœæ przesuniêcia w osi x.
   * @param y Wartoœæ przesuniêcia w osi y.
   */
	void translateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda skaluj¹ca punkty polilinii o wspó³czynnik k i rysuj¹ca skalowan¹ poliliniê.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param points Wektor punktów polilinii do skalowania.
   * @param closed Informacja, czy polilinia jest zamkniêta.
   * @param color Kolor polilinii.
   * @param k Wspó³czynnik skali.
   */
	void scalePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, double k)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda skaluj¹ca punkty wielok¹ta o wspó³czynnik k i rysuj¹ca skalowany wielok¹t.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param vertices Wektor punktów wielok¹ta do skalowania.
   * @param color Kolor wielok¹ta.
   * @param k Wspó³czynnik skali.
   */
	void scalePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, double k)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda skaluj¹ca i rysuj¹ca elipsê o wspó³czynniku k.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param x0 Wspó³rzêdna x œrodka elipsy.
   * @param y0 Wspó³rzêdna y œrodka elipsy.
   * @param RX Promieñ elipsy w osi x.
   * @param RY Promieñ elipsy w osi y.
   * @param color Kolor elipsy.
   * @param k Wspó³czynnik skali.
   */
	void scaleEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, double k)override;


	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda obracaj¹ca punkty polilinii o dany k¹t a i rysuj¹ca obrócon¹ poliliniê.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param points Wektor punktów polilinii do obrócenia.
   * @param closed Informacja, czy polilinia jest zamkniêta.
   * @param color Kolor polilinii.
   * @param x Wspó³rzêdna x punktu obrotu.
   * @param y Wspó³rzêdna y punktu obrotu.
   * @param a K¹t obrotu w radianach.
   */
	void rotatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y, long double a)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda obracaj¹ca punkty wielok¹ta o dany k¹t a i rysuj¹ca obrócony wielok¹t.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param vertices Wektor punktów wielok¹ta do obrócenia.
   * @param color Kolor wielok¹ta.
   * @param x Wspó³rzêdna x punktu obrotu.
   * @param y Wspó³rzêdna y punktu obrotu.
   * @param a K¹t obrotu w radianach.
   */
	void rotatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y, long double a)override;

	/**
   * @brief Labolatorium4 - zad2
   * @brief Metoda obracaj¹ca i rysuj¹ca elipsê o dany k¹t a.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param x0 Wspó³rzêdna x œrodka elipsy.
   * @param y0 Wspó³rzêdna y œrodka elipsy.
   * @param RX Promieñ elipsy w osi x.
   * @param RY Promieñ elipsy w osi y.
   * @param color Kolor elipsy.
   * @param x Wspó³rzêdna x punktu obrotu.
   * @param y Wspó³rzêdna y punktu obrotu.
   * @param a K¹t obrotu w radianach.
   */
	void rotateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y, long double a)override;
#pragma endregion
};
#endif