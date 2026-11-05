Pong Game
A simple two-player Pong game built in C using the raylib library. This project was created as a hands-on learning project to practise C programming, game loops, input handling, movement, collision detection, and scoring.
Gameplay
- Two players share one keyboard.
- The ball moves around the window and bounces off the top and bottom walls.
- Players use their paddles to return the ball.
- A player earns a point when the ball gets past the opponent's paddle and leaves the screen.
- The scoreboard displays both players' scores.
Controls
Player	Move up	Move down
Left paddle	W	S
Right paddle	↑	↓


Built With
- C
- raylib
- GCC / MinGW-w64 (Windows build)
Build and Run on Windows
1. Install the prerequisites
Install GCC through a MinGW-w64 toolchain and download the raylib package that matches your compiler. Make sure gcc is available in PowerShell and note the location of the extracted raylib folder.
2. Open PowerShell in the project folder
The folder should contain main.c.
3. Set the raylib folder path
Update the path below if you extracted raylib somewhere else:
$raylib = "$env:USERPROFILE\Downloads\raylib-6.2_win64_mingw-w64\raylib-6.2_win64_mingw-w64"
4. Compile
gcc .\main.c -o .\pingpong.exe -I"$raylib\include" -L"$raylib\lib" -lraylib -lopengl32 -lgdi32 -lwinmm
5. Run
.\pingpong.exe
Project Structure
pingpong/
└── main.c
Current Scope
This is a basic two-player version. It does not currently include a computer-controlled opponent, sound effects, a start menu, or a match-winning score limit.
Learning Goals
The project is a practical exercise in:
- C functions and program structure
- raylib window creation and drawing
- Keyboard input
- Frame-rate-independent movement using GetFrameTime()
- 2D collision detection
- Basic game state and score tracking
License
No license has been specified yet. All rights remain with the project author unless a license is added.
