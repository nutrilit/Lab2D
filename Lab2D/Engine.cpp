#include "Engine.h"

Engine::Engine(int x, int y)
{
    this->Width = x;
    this->Height = y;
    p1.MoveCoordinates(this->Width / 2, this->Height - (p1.height + 5));

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        exit(1);
    }

    window = SDL_CreateWindow("Space Intruders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, 0);

    if (!window)
    {
        exit(1);
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        exit(1);
    }
}

void Engine::Run()
{
    // obiekt  Point2D
    Point2D point(5, 5);

    //obiekty Point2D ale do LineSegment
    Point2D point1(5, 5);
    Point2D point2(10, 10);

    // Tworzenie obiektu LineSegment
    LineSegment line(point1, point2);

    //fpsy
    const int FPS = 30;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    float old_time = SDL_GetTicks();
    bool isRunning = true;
    Point2D nazwa[3] = { Point2D(200,150),Point2D(20,20) ,Point2D(200,30) };

    
    polylinePoints.push_back(Point2D(100, 100));
    polylinePoints.push_back(Point2D(200, 200));
    polylinePoints.push_back(Point2D(300, 100));
    polylinePoints.push_back(Point2D(400, 200));

    polylineSegments.push_back(LineSegment(Point2D(150, 100), Point2D(250, 200)));
    polylineSegments.push_back(LineSegment(Point2D(250, 200), Point2D(350, 100)));
    polylineSegments.push_back(LineSegment(Point2D(350, 100), Point2D(450, 200)));

    polygonPoints.push_back(Point2D(300, 600));
    polygonPoints.push_back(Point2D(200, 400));
    polygonPoints.push_back(Point2D(200, 300));
    polygonPoints.push_back(Point2D(300, 600));

    polygonSegments.push_back(LineSegment(Point2D(450, 350), Point2D(500, 300)));
    polygonSegments.push_back(LineSegment(Point2D(500, 280), Point2D(450, 260)));
    polygonSegments.push_back(LineSegment(Point2D(370, 420), Point2D(400, 350)));

    BitmapHandler bh1 = BitmapHandler();
    //³adownie tekstur i animacji z folderu
    SDL_Texture* Tex1 = bh1.LoadTexture("Textury/alien1.png", renderer);
    SDL_Texture* Tex2 = bh1.LoadTexture("Textury/alien2.png", renderer);
    SDL_Texture* Stay = bh1.LoadTexture("Textury/stay.png", renderer);
    SDL_Texture** Animation1 = bh1.LoadAnimation("Animacja/Alien%d.png", renderer, 4);
    SDL_Texture** Animation2 = bh1.LoadAnimation("Animacja1/move%d.png", renderer, 6);
    SDL_Texture* t1 = Tex1;
    
    int tmpI = 0;
    while (isRunning)
    {
        //tworzenie obiektów 
        AnimatedObject a1 = AnimatedObject();
        BitmapObject b1 = BitmapObject();
        SpriteObject s1 = SpriteObject();
        SDL_Rect tmp1 = { 50,50, 25,25 };
        SDL_Rect tmp2 = { 200,50, 25,25 };
        
        //licznik ¿eby wywo³ywaæ animacje
        tmpI++;
        if (tmpI == 5)
            tmpI = 0;
        //narysuj teksture i animacje
        s1.Draw(renderer, Tex2, tmp1); 
        s1.animate(renderer, Animation2, tmp2, tmpI);

        //cos tam cos tam
        // klatki
        frameStart = SDL_GetTicks();
        /*gracz*/
        //poruszanie sie gracza
        MovementHandle();
        // rysowanie gracza
        //pr1.Draw(renderer, p1.rect, czerwony);
        if (p1.movementLeft == false && p1.movementRight == false) //jeœli nie ma ruchu narysuj jak stoi w miejscu 
            p1.Draw(renderer, Stay, p1.rect); //narysuj gracza
        //SDL_RenderCopy(renderer, Tex1, NULL, &p1.rect); 
        if (p1.movementLeft == true || p1.movementRight == true) //gdy siê porusza wyœwietl animacje chodzenia
            p1.animate(renderer, Animation2, p1.rect, AniFrame);
        //SDL_RenderCopy(renderer, Animation1[AniFrame], NULL, &p1.rect);

        /* koniec gracz*/
        // rysowanie piksela w lewym gornym rogu
        //point.rys_piksel(renderer);
        // piksel narysowany wyzej zostaje przeniesiony na prawy gorny rog
        point.zmien_punkt(750, 20);

        //test czy dzia³aj¹ ró¿ne k¹ty do zad3 lab2
        pr1.RysLinie(renderer, 50, 1, 50, 47, marynarkawojenna);

        //zad5 lab2 - lineSegment
        //rysowanie odcinka przy pomocy Point2D
        line.Draw(renderer, true);
        // Odczytanie wspó³rzêdnych poszczególnych koñców odcinka
        Point2D start = line.GetStartPoint();
        Point2D end = line.GetEndPoint();
        /*koniec rysowania do linesegment*/ 

        /* Wypisanie wspó³rzêdnych poszczególnych koñców odcinka ale nie w petli zrobic
        //int startX, startY, endX, endY;
        //start.print_xy(startX, startY);
        //end.print_xy(endX, endY);
        //std::cout << "Start point: x=" << startX << ", y=" << startY << std::endl;
        //std::cout << "End point: x=" << endX << ", y=" << endY << std::endl;
        */

        /*modyfikacja odcinka do lineSegment*/
        // Modyfikacja wspó³rzêdnych poszczególnych koñców odcinka
        start.zmien_punkt(1, 50);
        end.zmien_punkt(799, 50);
        // Ustawienie zmodyfikowanych punktów w odcinku
        line.SetStartPoint(start);
        line.SetEndPoint(end);
        //rysowanie nowego odcinka
        line.Draw(renderer, true);
        /*koniec zad5 lab2 - lineSegment*/

        // otwarta linia robiona na tablicy - chyba wywalic 
        //pr1.Otwarta(renderer, nazwa);

        // lab2 zad6
        //linia ³amana otwarta na podstawie punktów
        //pr1.DrawPolyline(renderer, polylinePoints, false);

        // linia ³amana zamkniêta na podstawie punktów
        pr1.DrawPolyline(renderer, polylinePoints, true, cyraneczka);

        // linia ³amana otwarta na podstawie linii
        //pr1.DrawPolyline2(renderer, polylineSegments, false);

        // linia ³amana zamkniêta na podstawie linii
        pr1.DrawPolyline2(renderer, polylineSegments, true, zolty);

        // rysowanie okregu 4sem
        pr1.DrawCircle4Symmetry(renderer, 500, 500, 30, zolty);

        // rysowanie elipsy zad2 lab2
        pr1.DrawEllipse(renderer, 600, 500, 30, 10, cyraneczka);

        // rysowanie wielok¹ta zad3 lab3
        pr1.DrawPolygon(renderer, polygonPoints, czerwony);

        pr1.DrawPolygon2(renderer, polygonSegments, zolty);

        //
        //translate
        pr1.translatePolylinePoints(renderer, polylinePoints, true, czerwony, 50, 50);
        pr1.translatePolygonPoints(renderer, polygonPoints, cyraneczka,50,50);
        pr1.translateEllipse(renderer, 600, 500, 30, 10, czerwony,50,50);
        //scale
       pr1.scalePolylinePoints(renderer, polylinePoints, true, czerwony, 0.5);
        pr1.scalePolygonPoints(renderer, polygonPoints, czerwony, 0.5);
        pr1.scaleEllipse(renderer, 600, 500, 30, 10, czerwony , 0.5);
        //rotate
        pr1.rotatePolylinePoints(renderer, polylinePoints, true, czerwony, 300, 500, 10);
        pr1.rotatePolygonPoints(renderer, polygonPoints, czerwony, 300, 500, 10);

        // zad5 lab3
        //pr1.floodFill(renderer, 601, 501, czarny, zolty);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    point.print_xy(p1.x, p1.y);
}

void Engine::MovementHandle()
{
        const Uint8* state = SDL_GetKeyboardState(NULL);

        if (state[SDL_SCANCODE_LEFT])
        {
            p1.MoveLeft();
            if (AniFrame == 5) //index tablicy do animacji
            {
                AniFrame = 0;
            }
            else AniFrame++;
        }
        else
            p1.movementLeft = false;

        if (state[SDL_SCANCODE_RIGHT])
        {
            p1.MoveRight();
            if (AniFrame == 5) //index tablicy do animacji
            {
                AniFrame = 0;
            }
            else AniFrame++;
        }
        else
            p1.movementRight = false;
}

Engine::~Engine()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
