#include "raylib.h"


bool is_prime(int number)
{
	if (number < 4)
	{
		return true;
	}

	for (int i = 2; (i*i) <= number; ++i) {
		if (number%i == 0)
		{
			return false;
		}
	}


	return true;
}


void draw_2d_primes(int num_cloumn, int total, int start_x, int start_y)
{
	int pad {1};
	int block_size {14};
	int step_size {pad + block_size};

	int x {start_x};
	int y {start_y};

	int cur_column {0};
	for (int i = 1; i <= total; ++i) {

		auto color = LIGHTGRAY;

		if (is_prime(i))
		{
			color = DARKGRAY;
		}

		DrawRectangle(x, y, block_size, block_size, color);

		cur_column++;
		x += step_size;

		if (cur_column>=num_cloumn)
		{
			cur_column = 0;
			x = start_x;
			y += step_size;
		}
	}
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;

    int num_column = 33;

    InitWindow(screen_width, screen_height, "2D Prime!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

    	if (IsKeyPressed(KEY_LEFT))
    	{
    		num_column--;

    		if (num_column<=0)
    		{
    			num_column=1;
    		}
    	} else if (IsKeyPressed(KEY_RIGHT))
    	{
    		num_column++;
    	}


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText(TextFormat("Press Left/Right keys. Size=%d", num_column), 10, 10, 30, GRAY);

            draw_2d_primes(num_column, 33*33, 10, 50);


            DrawFPS(10, screen_height - 20);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
