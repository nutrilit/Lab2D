#pragma once
#include "Point2D.h"
//#include "PrimitiveRenderer.h"
#include <SDL.h>

class LineSegment
{
public:
#pragma region Labolatorium3 - zad3
	/**
   * @brief Labolatorium3 - zad3
   * @brief Metoda sprawdzaj¹ca, czy dwa odcinki siê nie przecinaj¹.
   *
   * @param other Drugi odcinek do porównania.
   * @return true jeœli odcinki siê nie przecinaj, w przeciwnym razie false.
   */
	bool DoNotIntersect(const LineSegment& other) const;
#pragma endregion

#pragma region Labolatorium2 - zad5
	/**
   * @brief Labolatorium2 - zad5
   * @brief Konstruktor klasy LineSegment.
   *
   * Inicjalizuje odcinek przy u¿yciu podanych punktów pocz¹tkowego i koñcowego.
   *
   * @param start Punkt pocz¹tkowy odcinka.
   * @param end Punkt koñcowy odcinka.
   */
	LineSegment(Point2D start, Point2D end);

	/**
   * @brief Metoda zwracajaca punkt poczatkowy odcinka.
   *
   * @return Punkt pocz¹tkowy odcinka.
   */
	Point2D GetStartPoint() const;

	/**
   * @brief Metoda zwracaj¹ca punkt koñcowy odcinka.
   *
   * @return Punkt koñcowy odcinka.
   */
	Point2D GetEndPoint() const;

	/**
   * @brief Metoda ustawiaj¹ca punkt pocz¹tkowy odcinka na nowy punkt.
   *
   * @param new_start Nowy punkt pocz¹tkowy odcinka.
   */
	void SetStartPoint(Point2D new_start);

	/**
   * @brief Metoda ustawiaj¹ca punkt koñcowy odcinka na nowy punkt.
   *
   * @param new_end Nowy punkt koñcowy odcinka.
   */
	void SetEndPoint(Point2D new_end);

	/**
   * @brief Metoda rysuj¹ca odcinek .
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   * @param incremental Okreœla, czy ma byæ u¿ywany algorytm domyslny czy przyrostowy.
   */
	void Draw(SDL_Renderer* renderer, bool incremental = false) const;

private:
	Point2D start_point;
	Point2D end_point;
	/**
   * @brief Metoda rysuj¹ca odcinek za pomoc¹ domyœlnego algorytmu.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   */
	void DrawDefault(SDL_Renderer* renderer) const;
	/**
   * @brief Metoda rysuj¹ca odcinek za pomoc¹ algorytmu przyrostowego.
   *
   * @param renderer WskaŸnik do obiektu SDL_Renderer.
   */
	void DrawIncremental(SDL_Renderer* renderer) const;
#pragma endregion
};
