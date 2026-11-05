#include <raylib.h>

void input_handler(void);
void gamelogic(void);
void collision_det(void);
void scoring(void);
void rendering(void);
void reset_ball(float direction);
Vector2 ball_position,ball_velocity;
const float PADDLE_SPEED = 300.0f;
Rectangle left_paddle = {20, 180, 15, 90};
Rectangle right_paddle = {765.0f, 180.0f, 15.0f, 90.0f};
int left_score = 0;
int right_score = 0;



int main(void)
{
    InitWindow(800,450,"ping pong");
    SetTargetFPS(60);
    ball_position = (Vector2){400.0f, 225.0f};
    ball_velocity = (Vector2){200.0f, 120.0f};

    while (!WindowShouldClose())
    {
        input_handler();
        gamelogic();

        BeginDrawing();

        ClearBackground(BLACK);
        rendering();

        EndDrawing();

        collision_det();
        scoring();
        
    }
}

   void input_handler(void)
   {
    if (IsKeyDown(KEY_W))
    {
        left_paddle.y -= PADDLE_SPEED * GetFrameTime();
    }

    if (IsKeyDown(KEY_S))
    {
        left_paddle.y += PADDLE_SPEED * GetFrameTime();
    }

    if (IsKeyDown(KEY_UP))
    {
        right_paddle.y -= PADDLE_SPEED * GetFrameTime();
    }

    if (IsKeyDown(KEY_DOWN))
    {
        right_paddle.y += PADDLE_SPEED * GetFrameTime();
    }
    if (left_paddle.y < 0)
    {
        left_paddle.y = 0;
    }

    if (left_paddle.y + left_paddle.height > GetScreenHeight())
    {
        left_paddle.y = GetScreenHeight() - left_paddle.height;
    }

    if (right_paddle.y < 0)
    {
        right_paddle.y = 0;
    }

    if (right_paddle.y + right_paddle.height > GetScreenHeight())
    {
        right_paddle.y = GetScreenHeight() - right_paddle.height;
    }
}




void gamelogic(){
ball_position.x += ball_velocity.x * GetFrameTime();
ball_position.y += ball_velocity.y * GetFrameTime();
}

void collision_det(){
    if(ball_position.y + 10.0f >= GetScreenHeight())
    {
        ball_velocity.y = -ball_velocity.y;
    }
    if(ball_position.y - 10.0f <= 0)
    {
        ball_velocity.y = -ball_velocity.y;
    }
    if (CheckCollisionCircleRec(ball_position, 10.0f, left_paddle)
    && ball_velocity.x < 0)
{
    ball_velocity.x *= -1;
    ball_position.x = left_paddle.x + left_paddle.width + 10.0f;
}
if (CheckCollisionCircleRec(ball_position, 10.0f, right_paddle)
        && ball_velocity.x > 0)
    {
        ball_velocity.x *= -1;
        ball_position.x = right_paddle.x - 10.0f;
    }
}

void scoring(){
    if (ball_position.x + 10.0f < 0)
    {
        right_score++;
        reset_ball(1.0f);
    }
    if (ball_position.x - 10.0f > GetScreenWidth())
    {
        left_score++;
        reset_ball(-1.0f);
    }
}
void reset_ball(float direction)
{
    ball_position = (Vector2){400.0f, 225.0f};

    ball_velocity.x = 250.0f * direction;
    ball_velocity.y = 160.0f;
}

void rendering(void)
{
    DrawLine(
        GetScreenWidth() / 2,
        0,
        GetScreenWidth() / 2,
        GetScreenHeight(),
        GRAY
    );
    DrawCircleV(ball_position, 10.0f, WHITE);
    DrawRectangleRec(left_paddle, PINK);
    DrawRectangleRec(right_paddle, PINK);
    DrawText(TextFormat("%d", left_score), 340, 20, 40, WHITE);
    DrawText(TextFormat("%d", right_score), 440, 20, 40, WHITE);
    DrawText("W / S", 20, 15, 15, GRAY);
    DrawText("UP / DOWN", 700, 15, 15, GRAY);
}