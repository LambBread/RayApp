# RayApp

This is a library adding a class "App" for [raylib](https://github.com/raysan5/raylib) apps, as well as a class Layer for inheriting App-like components.

## Example

```cpp
#include <rayapp.hpp>
class MainApp : public rayapp::App
{
public:
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
```

## Documentation

See [the docs](https://lambbread.github.io/rayapp-docs)
