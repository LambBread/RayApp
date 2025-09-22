/**
 * @file Layer.hpp
 *
 * @brief Declaration of the class Layer
 *
 * @author LambBread from github.com
 *
 */
#pragma once
#include <any>
namespace rayapp
{
    /**
     * @brief A generic portion of an app that runs every frame.
     *
     * Generic class that runs every frame, running code
     * when created, destroyed, and runs code every frame before
     * drawing as well as during drawing.
     */
    class Layer
    {
    public:
        /**
         * @brief Destructor for Layer
         */
        virtual ~Layer() = default;
        /**
         * @brief Runs before InitWindow().
         *
         * Can be overridden with custom code,
         * but overriding is optional. Runs before
         * InitWindow() is called.
         * 
         * @return void This function does not return a value.
         */
        virtual void OnBeforeCreate();
        /**
         * @brief Runs before CloseWindow() but after the main loop has ended.
         *
         * Can be overridden with custom code,
         * but overriding is optional. Runs between when the
         * main loop ends and when CloseWindow() is called.
         *
         * @return void This function does not return a value.
         */
        virtual void OnDestroy();
        /**
         * @brief Runs after CloseWindow().
         *
         * Can be overridden with custom code,
         * but overriding is optional. Runs after
         * CloseWindow() is called.
         * 
         * @return void This function does not return a value.
         */
        virtual void OnAfterDestroy();
        /**
         * @brief Runs when Enable() is called.
         *
         * @return void This function does not return a value.
         */
        virtual void OnEnable();
        /**
         * @brief Runs when Disable() is called.
         *
         * @return void This function does not return a value.
         */
        virtual void OnDisable();
        /**
         * @brief Runs after InitWindow() but before the main loop.
         *
         * Must be overridden. Runs after InitWindow() but
         * before the main loop.
         *
         * @return void This function does not return a value.
         */
        virtual void OnCreate() = 0;
        /**
         * @brief Runs in the main loop, before BeginDrawing().
         *
         * Must be overridden. Runs in the main loop before BeginDrawing(). Intended
         * for things such as responding to inputs.
         *
         * @param fDeltaTime The delta time, gotten via GetFrameTime().
         *
         * @return void This function does not return a value.
         */
        virtual void OnUpdate(float fDeltaTime) = 0;
        /**
         * @brief Runs in the main loop, between BeginDrawing() and EndDrawing().
         *
         * Must be overridden. Runs in the main loop between BeginDrawing() and EndDrawing().
         * Intended for drawing onto the screen.
         *
         * @return void This function does not return a value.
         */
        virtual void OnDraw() = 0;
        /**
         * @brief Gets m_Enabled.
         *
         * @return bool m_Enabled.
         */
        bool IsEnabled() const;
        /**
         * @brief Gets a reference to m_Status.
         *
         * @return int& A reference to m_Status.
         */
        int& GetStatus();
        /**
         * @brief Gets a reference to m_Data.
         *
         * @return std::any& A reference to m_Data.
         */
        std::any& GetData();
        /**
         * @brief Enable the layer.
         *
         * @return void This function does not return a value.
         */
        void Enable();
        /**
         * @brief Disable the layer.
         * 
         * @return void This function does not return a value.
         */
        void Disable();
    protected:
        bool m_Enabled = true; ///<Flag representing if the layer is enabled.
        int m_Status = 0; ///<Data representing status.
        std::any m_Data; ///<User defined data if necessary.
        Layer() = default; ///<Constructor for Layer. Not intended for construction.
    };
}
