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
   * @brief Konstruktor domy�lny klasy Player. Inicjalizuje pocz�tkowe warto�ci pozycji, rozmiaru i reprezentacji prostok�tnej gracza.
   */
	Player();

	/**
   * @brief Labolatorium2 - zad3
   * @brief Metoda ustawiaj�ca nowe wsp�rz�dne gracza i aktualizuj�ca reprezentacj� prostok�tn�.
   *
   * @param nx Nowa wsp�rz�dna x gracza.
   * @param ny Nowa wsp�rz�dna y gracza.
   */
	void MoveCoordinates(int nx, int ny);

	/**
   * @brief Labolatorium2 - zad3
 * @brief Metoda przesuwaj�ca gracza w lewo i aktualizuj�ca reprezentacj� prostok�tn�.
 */
	void MoveLeft();

	/**
   * @brief Labolatorium2 - zad3
 * @brief Metoda przesuwaj�ca gracza w prawo i aktualizuj�ca reprezentacj� prostok�tn�.
 */
	void MoveRight();

public: bool movementLeft; ///< Flaga ruchu w lewo.
public: bool movementRight; ///< Flaga ruchu w prawo.
#pragma endregion
};

#endif
