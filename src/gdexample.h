#pragma once

#include <Godot.hpp>
#include <Sprite.hpp>

namespace godot {

    class GDExample : public Sprite {
        GODOT_CLASS(GDExample, Sprite)

    public:
        static void _register_methods();

        GDExample();
        ~GDExample();

        void _init(); // our initializer called by Godot

        void _process(float delta);

    private:
        float time_passed;
    };

}