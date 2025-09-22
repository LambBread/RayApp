/**
 * @file App.hpp
 *
 * @brief Declaration of the class App
 *
 * @author LambBread from github.com
 */
#pragma once
#include "Layer.hpp"
#include <string>
#include <vector>
#include <raylib.h>
namespace rayapp
{
    /**
     * @brief Base class for apps.
     *
     * This is a base class for apps which inherits Layer.
     *
     */
    class App : public Layer
    {
    public:
        /**
         * @brief Destructor for App
         */
        virtual ~App() override = default;
        /**
         * @brief Start the app.
         * 
         * Start the app by initting the window and running all the
         * derived functions.
         * 
         * @param width The width of the window.
         *
         * @param height The height of the window.
         *
         * @param title The title of the window
         *
         * @return void This function does not return a value.
         */
        void Run(int width, int height, const char* title);
        /**
         * @overload void rayapp::App::Run(int width, int height, const std::string& title)
         */
        void Run(int width, int height, const std::string& title);
    protected:
        std::vector<Layer*> m_Layers; ///<Layers that may be used in derived classes.
        App() = default; ///<Constructor for App. Not intended for construction.
    };
}
/**
 * @brief Generate a main function.
 * 
 * Generate a main function including argc and argv that
 * creates an object of type mainapp and runs it with the
 * specified params
 *
 * @param mainapp The main app's class
 * 
 * @param width The width of the window
 *
 * @param height The height of the window
 *
 * @param title The title of the window
 */
#define RAYAPP_MAIN(mainapp, width, height, title)\
    int main(int argc, char** argv)\
    {\
        mainapp app;\
        app.Run((width), (height), (title));\
        return 0;\
    }
