#include "Scene.hpp"

Scene::Scene(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
            Gtk::DrawingArea(cobject)
{
    funcs = {
        [](float x){ return std::cos(x); },
        [](float x){ return std::sin(x); },
        [](float x){ return x * x; }
    };
}

bool Scene::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();
    
    const int half_width = width / 2;
    const int half_height = height / 2;
    const float size_coefficient = 30;
    const float sized_width = width / size_coefficient;
    const float step = 0.1;


    for(int i = 0; i < funcs.size(); i++)
    {
        auto f = funcs[i];
        
        cr->set_line_width(3.0);
        cr->set_source_rgb(0.8, 0.5, 0.0);

        float past_x = -sized_width - step;
        float past_y = f(past_x);
        cr->move_to(past_x, past_y);
        for(float x = -sized_width; x < sized_width; x += step)
        {
            float y = f(x);

            cr->line_to((x * size_coefficient) + half_width,
                        (y * size_coefficient) + half_height);

            past_x = x;
            past_y = y;
        }
    }

    cr->stroke();
    return true;
}

Scene::~Scene()
{
}