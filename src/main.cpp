#include <raylib.h>
using namespace std;

class Ball{
public:
    float x,y;
    int speed_x, speed_y;
    int radius;
    void Draw(){
        DrawCircle(x, y, radius, WHITE);
    }
    void Update(){
        x += speed_x;
        y += speed_y;
    }

};

Ball ball;


int main(){

    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "First Game");
    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    while(WindowShouldClose() == false){

        BeginDrawing();

        //Updating
        ball.Update();

        //Drawing
        ClearBackground(BLACK); //Clears Ball Trace

        ball.Draw();

        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
        DrawRectangle(10, screen_height/2 - 60, 25, 120, WHITE);
        DrawRectangle(screen_width - 35, screen_height/2 - 60, 25, 120, WHITE);

        EndDrawing();

    }
    CloseWindow();

    return 0;
}
