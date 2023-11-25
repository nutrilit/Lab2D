#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_timer.h>
#include <stdbool.h>
#include <SDL_image.h>

class BitmapHandler
{
#pragma region Labolatorium5 - zad1
	  /**
     * @brief Labolatorium5 - zad1
     * @brief �aduje pojedyncz� tekstur� z pliku graficznego.
     *
     * @param NameOfTexture �cie�ka do pliku tekstury.
     * @param renderer Wska�nik do SDL_Renderer u�ywanego do tworzenia tekstury.
     * @return Wska�nik do za�adowanej tekstury SDL_Texture.
     */
#pragma endregion

#pragma region Labolatorium5 - zad3
public: SDL_Texture* LoadTexture(const char* NameOfTexture, SDL_Renderer* renderer);

        /**
       * @brief  Labolatorium5 - zad3
       * @brief  �aduje animacj� jako tablic� wska�nik�w SDL_Texture.
       * 
       * Funkcja zak�ada, �e klatki animacji s� nazwane sekwencyjnie z indeksem jako cz�ci� nazwy pliku.
       * Na przyk�ad, je�li NameOfTexture to "animacja/klatka_", zostan� za�adowane "animacja/klatka_0", "animacja/klatka_1", itd.
       *
       * @param NameOfTexture Bazowa nazwa klatek animacji.
       * @param renderer Wska�nik do SDL_Renderer u�ywanego do tworzenia tekstury.
       * @param Frames Liczba klatek w animacji.
       * @return Tablica wska�nik�w SDL_Texture reprezentuj�ca klatki animacji.
       */
public: SDL_Texture** LoadAnimation(const char* NameOfTexture, SDL_Renderer* renderer, int Frames);
#pragma endregion

};
