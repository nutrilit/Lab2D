/**
 * @file PrimitiveRenderer.cpp
 * @brief Implementacja klasy PrimitiveRenderer.
 */
#include "PrimitiveRenderer.h"

#pragma region Labolatorium2 - zad2
void PrimitiveRenderer::Draw(SDL_Renderer* renderer, SDL_Rect rect1, SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect1);
}
#pragma endregion

#pragma region Labolatorium2 - zad3
void PrimitiveRenderer::RysLinie(SDL_Renderer* renderer, int x0, int y0, int x1, int y1, SDL_Color color)
{
	int x, y, tempX, tempY;
	float dy, dx, m;
	dy = (y1 - y0) < 0 ? -(y1 - y0) : (y1 - y0);
	dx = (x1 - x0) < 0 ? -(x1 - x0) : (x1 - x0);
	tempX = x0 < x1 ? 1 : -1;
	tempY = y0 < y1 ? 1 : -1;

	if (dx > dy)
	{
		int temp = dx / 2;
		y = y0;
		for (x = x0; x != x1; x += tempX)
		{
			SDL_Rect rect = { x, y, 3, 3 };
			SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
			SDL_RenderFillRect(renderer, &rect);
			temp -= dy;
			if (temp < 0)
			{
				y += tempY;
				temp += dx;
			}
		}
	}
	else
	{
		int temp = dy / 2;
		x = x0;
		for (y = y0; y != y1; y += tempY)
		{
			SDL_Rect rect = { x, y, 3, 3 };
			SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
			SDL_RenderFillRect(renderer, &rect);
			temp -= dx;
			if (temp < 0)
			{
				x += tempX;
				temp += dy;
			}
		}
	}
	SDL_Rect rect = { x1, y1, 3, 3 };
	//SDL_SetRenderDrawColor(renderer, 255, 100, 255, 255);
	SDL_RenderFillRect(renderer, &rect);

}
#pragma endregion

#pragma region Labolatorium2 - zad6
void PrimitiveRenderer::DrawPolyline(SDL_Renderer* renderer, const std::vector<Point2D>& points, bool closed, SDL_Color color)
{
	if (points.size() < 2) {
		return;
	}

	for (size_t i = 1; i < points.size(); ++i) {
		const Point2D& start = points[i - 1];
		const Point2D& end = points[i];
		RysLinie(renderer, start.GetX(), start.GetY(), end.GetX(), end.GetY(), color);
	}

	if (closed && !points.empty()) {
		const Point2D& first = points.front();
		const Point2D& last = points.back();
		RysLinie(renderer, last.GetX(), last.GetY(), first.GetX(), first.GetY(), color);
	}

}
void PrimitiveRenderer::DrawPolyline2(SDL_Renderer* renderer, const std::vector<LineSegment>& segments, bool closed, SDL_Color color)
{
	if (segments.empty()) {
		return;
	}

	for (size_t i = 0; i < segments.size(); ++i) {
		const LineSegment& segment = segments[i];
		RysLinie(renderer, segment.GetStartPoint().GetX(), segment.GetStartPoint().GetY(), segment.GetEndPoint().GetX(), segment.GetEndPoint().GetY(), color);
	}

	if (closed && segments.size() >= 2) {
		const LineSegment& firstSegment = segments.front();
		const LineSegment& lastSegment = segments.back();
		RysLinie(renderer, lastSegment.GetEndPoint().GetX(), lastSegment.GetEndPoint().GetY(), firstSegment.GetStartPoint().GetX(), firstSegment.GetStartPoint().GetY(), color);
	}
}
#pragma endregion

#pragma region Labolatorium3 - zad1
void PrimitiveRenderer::DrawCircle4Symmetry(SDL_Renderer* renderer, int x0, int y0, int R, SDL_Color color)
{
	float alpha;
	for (alpha = 0; alpha < M_PI / 2; alpha += 0.005) {
		int x = (x0 + R * cos(alpha));
		int y = (y0 + R * sin(alpha));
		int mirroredX = x0 - (x - x0);
		int mirroredY = y0 - (y - y0);
		Draw(renderer, { x, y, 1, 1 }, color); // Punkt w pierwszej cwiartce
		Draw(renderer, { mirroredX, y, 1, 1 }, color); // Punkt w drugiej �wiartce
		Draw(renderer, { x, mirroredY, 1, 1 }, color); // Punkt w czwartej �wiartce
		Draw(renderer, { mirroredX, mirroredY, 1, 1 }, color); // Punkt w trzeciej �wiartce
	}
}
#pragma endregion

#pragma region Labolatorium3 - zad2
void PrimitiveRenderer::DrawEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	double alpha;
	double step = M_PI / 180; // Krok 1 stopnia

	for (alpha = 0; alpha < M_PI / 2; alpha += step)
	{
		int x = (x0 + RX * cos(alpha));
		int y = (y0 + RY * sin(alpha));
		int mirroredX = x0 - (x - x0);
		int mirroredY = y0 - (y - y0);
		Draw(renderer, { x, y, 1, 1 }, color); // Punkt w pierwszej cwiartce
		Draw(renderer, { mirroredX, y, 1, 1 }, color); // Punkt w drugiej �wiartce
		Draw(renderer, { x, mirroredY, 1, 1 }, color); // Punkt w czwartej �wiartce
		Draw(renderer, { mirroredX, mirroredY, 1, 1 }, color); // Punkt w trzeciej �wiartce
	}
}
#pragma endregion

#pragma region Labolatorium3 - zad3
void PrimitiveRenderer::DrawPolygon(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color)
{
	if (vertices.size() < 3) {
		return;  // Wielok�t musi mie� co najmniej 3 wierzcho�ki
	}


	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	for (size_t i = 0; i < vertices.size() - 1; ++i) {
		const Point2D& start = vertices[i];
		const Point2D& end = vertices[i + 1];
		SDL_RenderDrawLine(renderer, start.GetX(), start.GetY(), end.GetX(), end.GetY());
	}

	// Ostatni odcinek ��czy ostatni wierzcho�ek z pierwszym
	const Point2D& first = vertices.front();
	const Point2D& last = vertices.back();
	SDL_RenderDrawLine(renderer, last.GetX(), last.GetY(), first.GetX(), first.GetY());
}
void PrimitiveRenderer::DrawPolygon2(SDL_Renderer* renderer, const std::vector<LineSegment>& segments, SDL_Color color)
{
	// Sprawd�, czy odcinki przecinaj� si�
	for (size_t i = 0; i < segments.size(); ++i) {
		for (size_t j = i + 1; j < segments.size(); ++j) {
			if (segments[i].DoNotIntersect(segments[j])) {
				return;  // Przerwij rysowanie w przypadku przeci�cia
			}
		}
	}

	// Narysuj zamkni�ty wielok�t
	for (const LineSegment& segment : segments) {
		RysLinie(renderer, segment.GetStartPoint().GetX(), segment.GetStartPoint().GetY(),
			segment.GetEndPoint().GetX(), segment.GetEndPoint().GetY(), color);
	}

	// Dodaj ostatni odcinek ��cz�cy pocz�tek z ko�cem
	const LineSegment& firstSegment = segments.front();
	const LineSegment& lastSegment = segments.back();
	RysLinie(renderer, lastSegment.GetEndPoint().GetX(), lastSegment.GetEndPoint().GetY(),
		firstSegment.GetStartPoint().GetX(), firstSegment.GetStartPoint().GetY(), color);
}
#pragma endregion

#pragma region Labolatorium3 - zad4,5
void PrimitiveRenderer::floodFill(SDL_Renderer* renderer, int x, int y, SDL_Color targetColor, SDL_Color fillColor) {
	std::stack<std::pair<int, int>> pixelsToCheck;
	pixelsToCheck.push(std::make_pair(x, y));

	std::vector<std::vector<bool>> visited(800, std::vector<bool>(600, false));

	while (!pixelsToCheck.empty()) {
		std::pair<int, int> currentPixel = pixelsToCheck.top();
		pixelsToCheck.pop();

		int px = currentPixel.first;
		int py = currentPixel.second;
		if (visited[px][py]) {
			continue;
		}
		visited[px][py] = true;
		// Pobierz kolor piksela z renderera
		SDL_Color currentColor;
		SDL_Rect pixelRect = { px, py, 1, 1 };
		SDL_RenderReadPixels(renderer, &pixelRect, SDL_PIXELFORMAT_RGBA8888, &currentColor, sizeof(Uint32));
		//std::cout << (int)currentColor.r << (int)currentColor.g << (int)currentColor.b << (int)currentColor.a;
		// Sprawd�, czy aktualny piksel ma docelowy kolor

		if (currentColor.a == 0 && currentColor.b == 0 &&
			currentColor.g == 0 && currentColor.r == 255) {
			// Ustaw kolor wype�nienia na pikselu
			SDL_SetRenderDrawColor(renderer, fillColor.r, fillColor.g, fillColor.b, fillColor.a);
			//SDL_RenderDrawPoint(renderer, px, py);
			SDL_Rect r1 = { px,py,1,1 };
			SDL_RenderFillRect(renderer, &r1);

			// Dodaj s�siednie piksele do sprawdzenia
			pixelsToCheck.push(std::make_pair(px + 1, py));
			pixelsToCheck.push(std::make_pair(px - 1, py));
			pixelsToCheck.push(std::make_pair(px, py + 1));
			pixelsToCheck.push(std::make_pair(px, py - 1));

		}
	}
}
#pragma endregion

#pragma region Labolatorium4 - zad2
void PrimitiveRenderer::translatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y)
{
	std::vector<Point2D> polylinePoints;
	for (size_t i = 0; i < points.size(); ++i) {
		polylinePoints.push_back(points[i]);
	}
	for (size_t i = 0; i < polylinePoints.size(); ++i) {
		polylinePoints[i].x += x;
		polylinePoints[i].y += y;
	}
	DrawPolyline(renderer, polylinePoints, closed, color);
}

void PrimitiveRenderer::translatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y)
{
	std::vector<Point2D> tmp;
	for (size_t i = 0; i < vertices.size(); ++i) {
		tmp.push_back(vertices[i]);
	}
	for (size_t i = 0; i < vertices.size(); ++i) {
		tmp[i].x += x;
		tmp[i].y += y;
	}
	DrawPolygon(renderer, tmp, color);

}

void PrimitiveRenderer::translateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y)
{
	int tmpX0 = x0 + x, tmpY0 = y0 + y, tmpRX = RX, tmpRY = RY;
	DrawEllipse(renderer, tmpX0, tmpY0, RX, RY, color);
}

void PrimitiveRenderer::scalePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, double k)
{
	std::vector<Point2D> polylinePoints;
	for (size_t i = 0; i < points.size(); ++i) {
		polylinePoints.push_back(points[i]);
	}
	for (size_t i = 0; i < polylinePoints.size(); ++i) {
		polylinePoints[i].x *= k;
		polylinePoints[i].y *= k;
	}
	int tmpX = points[0].x - polylinePoints[0].x;
	int tmpY = points[0].y - polylinePoints[0].y;
	translatePolygonPoints(renderer, polylinePoints, color, tmpX, tmpY);
	//DrawPolyline(renderer, polylinePoints, closed, color);
}

void PrimitiveRenderer::scalePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, double k)
{
	std::vector<Point2D> tmp;
	for (size_t i = 0; i < vertices.size(); ++i) {
		tmp.push_back(vertices[i]);
	}
	for (size_t i = 0; i < vertices.size(); ++i) {
		tmp[i].x *= k;
		tmp[i].y *= k;
	}
	int tmpX = vertices[0].x - tmp[0].x;
	int tmpY = vertices[0].y - tmp[0].y;
	translatePolygonPoints(renderer, tmp, color, tmpX, tmpY);
	//DrawPolygon(renderer, tmp, color);
}

void PrimitiveRenderer::scaleEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, double k)
{
	int tmpX0 = x0 * k, tmpY0 = y0 * k, tmpRX = RX * k, tmpRY = RY * k;
	DrawEllipse(renderer, x0, y0, tmpRX, tmpRY, color);
}

void PrimitiveRenderer::rotatePolylinePoints(SDL_Renderer* renderer, std::vector<Point2D>& points, bool closed, SDL_Color color, int x, int y, long double a)
{
	std::vector<Point2D> polylinePoints;
	for (size_t i = 0; i < points.size(); ++i) {
		polylinePoints.push_back(points[i]);
	}
	for (size_t i = 0; i < polylinePoints.size(); ++i) {
		polylinePoints[i].x = x + (points[i].x - x) * cos(a) - (points[i].y - y) * sin(a);
		polylinePoints[i].y = y + (points[i].x - x) * sin(a) - (points[i].y - y) * cos(a);
	}
	DrawPolyline(renderer, polylinePoints, closed, color);

}

void PrimitiveRenderer::rotatePolygonPoints(SDL_Renderer* renderer, const std::vector<Point2D>& vertices, SDL_Color color, int x, int y, long double a)
{
	std::vector<Point2D> tmp;
	for (size_t i = 0; i < vertices.size(); ++i) {
		tmp.push_back(vertices[i]);
	}
	for (size_t i = 0; i < vertices.size(); ++i) {
		tmp[i].x = x + (vertices[i].x - x) * cos(a) - (vertices[i].y - y) * sin(a);
		tmp[i].y = y + (vertices[i].x - x) * sin(a) - (vertices[i].y - y) * cos(a);
	}
	DrawPolygon(renderer, tmp, color);

}

void PrimitiveRenderer::rotateEllipse(SDL_Renderer* renderer, int x0, int y0, int RX, int RY, SDL_Color color, int x, int y, long double a)
{
	int tmpX0 = x0 + x, tmpY0 = y0 + y, tmpRX = RX, tmpRY = RY;
	DrawEllipse(renderer, tmpX0, tmpY0, RX, RY, color);
}

#pragma endregion