#include "Scene.hpp"
#include <cairomm/context.h>

#include <cmath>

Scene::Scene(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
            Gtk::DrawingArea(cobject)
{
}

Scene::~Scene()
{
}

float Scene::math_function_1(float x)
{
    return std::cos(x);
}

float Scene::math_function_2(float x)
{
    return std::sin(x);
}

float Scene::math_function_3(float x)
{
    return std::cos(x * x);
}


bool Scene::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    //Это область окна, где мы рисуем
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();
    const int half_width = width / 2;
    const int half_height = height / 2;

    float size_coefficient = 30;
    float step = 0.1;

    cr->set_line_width(3.0);
    cr->set_source_rgb(0.8, 0.5, 0.0);

    float past_x = -1, past_y = math_function_1(past_x);
    cr->move_to(past_x, past_y);
    for(float x = 0; x < height; x += step)
    {
        float y = math_function_1(x);

        cr->line_to((x * size_coefficient) + half_width,
                    (y * size_coefficient) + half_height);

        past_x = x;
        past_y = y;
    }
    cr->stroke();
    return true;
}