#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <SDL_timer.h>
#include "Player.h"
#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <iostream>
#include <vector>
#include <SDL_image.h>
#include "BitmapHandler.h"

	/**
	 * @brief Klasa Engine reprezentuje g³ówny silnik gry.
	 */
class Engine
{
public:
	/**
	 * @brief Konstruktor klasy Engine.
	 * @param x Szerokoœæ okna gry.
	 * @param y Wysokoœæ okna gry.
	 */
	Engine(int x, int y);

	/**
	 * @brief Uruchamia pêtlê gry.
	 */
	void Run();

	/**
	 * @brief Destruktor klasy Engine.
	 */
	~Engine();

private:
	PrimitiveRenderer pr1, pr2;
	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Event event;
	Player p1;


	int Width, Height;
	int AniFrame = 0; //aktualna klatka animacji postaci

	std::vector<Point2D> polylinePoints;
	std::vector<LineSegment> polylineSegments;
	std::vector<Point2D> polygonPoints;
	std::vector<LineSegment> polygonSegments;

	// kolory:
	SDL_Color czerwony = { 255,0,0,255 };
	SDL_Color niebieski = { 0,0,255,255 };
	SDL_Color cyraneczka = { 0,128,128,255 };
	SDL_Color zolty = { 255,255,0,255 };
	SDL_Color marynarkawojenna = { 0,0,128, 255 };
	SDL_Color czarny = { 0,0,0, 255 };

	/**
	 * @brief Obs³uguje ruch gracza na podstawie wejœcia z klawiatury.
	 */
	void MovementHandle();
};

#endif
