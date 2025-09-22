#include <rayapp.hpp>
class MainApp : public rayapp::App
{
public:
    MainApp()
    {

    }
    ~MainApp()
    {

    }
    void OnCreate() override
    {

    }
    void OnUpdate(float fDeltaTime) override
    {
        
    }
    void OnDraw() override
    {
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    }
};

RAYAPP_MAIN(MainApp, 800, 600, "raylib [core] example - basic window")
