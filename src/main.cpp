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

        if (y + radius >= GetScreenHeight() || y - radius <= 0){
            speed_y *= -1;
        }
        if (x + radius >= GetScreenWidth() || x - radius <= 0){
            speed_x *= -1;
        }
    }

};
class Paddle{
public:
    float x,y;
    float width, height;
    int speed;

    void Draw(){
        DrawRectangle(x, y, width, height, WHITE);
    }
    void Update(){
        if(IsKeyDown(KEY_UP)){
            y = y - speed;
        }
        if(IsKeyDown(KEY_DOWN)){
            y = y + speed;
        }

        if(y <= 0){
            y = 0;
        }
        if(y + height >= GetScreenHeight()){
            y = GetScreenHeight() - height;
        }
    }

};

class CpuPaddle: public Paddle{
public:
    void Update(int ball_y){
        if(y + height/2  > ball_y){
            y = y - speed;
        }
        if(y + height/2 <= ball_y){
            y = y + speed;
        }
    }
};

Ball ball;
Paddle player;
CpuPaddle cpu;


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

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height/2 - player.height/2;
    player.speed = 6;

    cpu.width = 25;
    cpu.height = 120;
    cpu.x = 10;
    cpu.y = screen_height/2 - cpu.height/2;
    cpu.speed = 6;

    while(WindowShouldClose() == false){

        BeginDrawing();

        //Updating
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        //Drawing
        ClearBackground(BLACK); //Clears Ball Trace

        ball.Draw();
        player.Draw();
        cpu.Draw();

        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);

        EndDrawing();

    }
    CloseWindow();

    return 0;
}
