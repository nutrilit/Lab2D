#pragma once
#include <SDL.h>
#include "AnimatedObject.h"
#include "BitmapObject.h"

#pragma region Labolatorium5 - zad2 (c)
/**
 * @brief Labolatorium5 - zad2 (c)
 * @brief Klasa reprezentująca obiekt sprite'a.
 *
 * Klasa ta dziedziczy zarówno po klasie AnimatedObject, umożliwiającej animowanie obiektów,
 * jak i po BitmapObject, obsługującej obiekty graficzne korzystające z bitmap.
 */
class SpriteObject : public AnimatedObject,public BitmapObject
{
};
#pragma endregion

