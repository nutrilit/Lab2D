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
   * @brief Metoda sprawdzaj�ca, czy dwa odcinki si� nie przecinaj�.
   *
   * @param other Drugi odcinek do por�wnania.
   * @return true je�li odcinki si� nie przecinaj, w przeciwnym razie false.
   */
	bool DoNotIntersect(const LineSegment& other) const;
#pragma endregion

#pragma region Labolatorium2 - zad5
	/**
   * @brief Labolatorium2 - zad5
   * @brief Konstruktor klasy LineSegment.
   *
   * Inicjalizuje odcinek przy u�yciu podanych punkt�w pocz�tkowego i ko�cowego.
   *
   * @param start Punkt pocz�tkowy odcinka.
   * @param end Punkt ko�cowy odcinka.
   */
	LineSegment(Point2D start, Point2D end);

	/**
   * @brief Metoda zwracajaca punkt poczatkowy odcinka.
   *
   * @return Punkt pocz�tkowy odcinka.
   */
	Point2D GetStartPoint() const;

	/**
   * @brief Metoda zwracaj�ca punkt ko�cowy odcinka.
   *
   * @return Punkt ko�cowy odcinka.
   */
	Point2D GetEndPoint() const;

	/**
   * @brief Metoda ustawiaj�ca punkt pocz�tkowy odcinka na nowy punkt.
   *
   * @param new_start Nowy punkt pocz�tkowy odcinka.
   */
	void SetStartPoint(Point2D new_start);

	/**
   * @brief Metoda ustawiaj�ca punkt ko�cowy odcinka na nowy punkt.
   *
   * @param new_end Nowy punkt ko�cowy odcinka.
   */
	void SetEndPoint(Point2D new_end);

	/**
   * @brief Metoda rysuj�ca odcinek .
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   * @param incremental Okre�la, czy ma by� u�ywany algorytm domyslny czy przyrostowy.
   */
	void Draw(SDL_Renderer* renderer, bool incremental = false) const;

private:
	Point2D start_point;
	Point2D end_point;
	/**
   * @brief Metoda rysuj�ca odcinek za pomoc� domy�lnego algorytmu.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   */
	void DrawDefault(SDL_Renderer* renderer) const;
	/**
   * @brief Metoda rysuj�ca odcinek za pomoc� algorytmu przyrostowego.
   *
   * @param renderer Wska�nik do obiektu SDL_Renderer.
   */
	void DrawIncremental(SDL_Renderer* renderer) const;
#pragma endregion
};
