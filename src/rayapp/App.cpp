/**
 * @file App.cpp
 *
 * @brief Definition of the class App
 *
 * @author LambBread from github.com
 */
#include "App.hpp"
#include <raylib.h>
#define LOOP_THROUGH(x)\
    for(auto& e : m_Layers)\
    {\
        if(e.IsEnabled())\
        {\
            x\
        }\
    }
namespace rayapp
{
    void App::Run(int width, int height, const char* title)
    {
        OnBeforeCreate();
        LOOP_THROUGH(e.OnBeforeCreate();)
        InitWindow(width, height, title);
        OnCreate();
        LOOP_THROUGH(e.OnCreate();)
        while(!WindowShouldClose())
        {
            OnUpdate(GetFrameTime());
            LOOP_THROUGH(e.OnUpdate(GetFrameTime());)
            BeginDrawing();
            OnDraw();
            LOOP_THROUGH(e.OnDraw();)
            EndDrawing();
        }
        OnDestroy();
        LOOP_THROUGH(e.OnDestroy();)
        CloseWindow();
        OnAfterDestroy();
        LOOP_THROUGH(e.OnAfterDestroy();)
    }
    void App::Run(int width, int height, const std::string& title)
    {
        Run(width, height, title.c_str());
    }
}
