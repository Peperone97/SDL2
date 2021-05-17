#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#endif
#ifdef unix
    #include <SDL2/SDL.h>
#endif
//#include "SDL2/include/SDL.h"

#include <stdio.h>
#include <stdlib.h>
#include <exception>

#include "baseWindow.h"
#include "core.h"
#include "texture.h"
#include "phrase.h"

#ifndef WINDOW
#define WINDOW
 

namespace Window{
    class Window : public BaseWindow{
    public:
        Window( const char *title, int width, int height, int numberOfTiles );
        ~Window();
        void run();
    private:
        int previous_x, previous_y; //previous x/y used for slide the map
        bool slide, draw, ctrl_combination;

        SDL_Event e;
        SDL_Thread *update_thread, *render_thread;

        Core *core;
        Phrase *dinamicText;
        
        static void render_wrapper( void* obj ){
            static_cast<Window*>(obj)->render();
        }
        static void update_wrapper( void *obj ){
            static_cast<Window*>(obj)->update();
        }

        void render();
        void update();
        void eventManager();
        void close();

    };
}

#endif
