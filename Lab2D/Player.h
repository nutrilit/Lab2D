#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SDL.h>
#include "GameObject.cpp"
#include "SpriteObject.h"

class Player : public GameObject, public SpriteObject
{
#pragma region Labolatorium2 - zad3
public:
	int x, y, width, height;
	SDL_Rect rect;

	/**
   * @brief Labolatorium2 - zad3
   * @brief Konstruktor domyœlny klasy Player. Inicjalizuje pocz¹tkowe wartoœci pozycji, rozmiaru i reprezentacji prostok¹tnej gracza.
   */
	Player();

	/**
   * @brief Labolatorium2 - zad3
   * @brief Metoda ustawiaj¹ca nowe wspó³rzêdne gracza i aktualizuj¹ca reprezentacjê prostok¹tn¹.
   *
   * @param nx Nowa wspó³rzêdna x gracza.
   * @param ny Nowa wspó³rzêdna y gracza.
   */
	void MoveCoordinates(int nx, int ny);

	/**
   * @brief Labolatorium2 - zad3
 * @brief Metoda przesuwaj¹ca gracza w lewo i aktualizuj¹ca reprezentacjê prostok¹tn¹.
 */
	void MoveLeft();

	/**
   * @brief Labolatorium2 - zad3
 * @brief Metoda przesuwaj¹ca gracza w prawo i aktualizuj¹ca reprezentacjê prostok¹tn¹.
 */
	void MoveRight();

public: bool movementLeft; ///< Flaga ruchu w lewo.
public: bool movementRight; ///< Flaga ruchu w prawo.
#pragma endregion
};

#endif
