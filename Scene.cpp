#include "Scene.hpp"

Scene::Scene(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
            Gtk::DrawingArea(cobject)
{
    update_parametrs({1, 1, 1});
}

void Scene::update_parametrs(std::array<float, 3> p)
{
    funcs = {
        [p](float x){ return p[0] * std::cos(x); },
        [p](float x){ return p[1] * std::sin(x); },
        [p](float x){ return p[2] * std::cos(std::sin(x)); }
    };
}

void Scene::update_coefficients(float zoom, float side)
{
    size_coefficient = zoom;
    side_size = side;
}

bool Scene::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();
    
    const int half_width = width / 2;
    const int half_height = height / 2;
    
    float sized_width = width / size_coefficient;
    float step = 0.01;


    //axis
    cr->set_source_rgb(0, 0, 0);
    cr->set_line_width(1);
    cr->move_to(0,          half_height);
    cr->line_to(width,      half_height);
    cr->move_to(half_width, 0);
    cr->line_to(half_width, height);
    cr->stroke();
    

    cr->set_line_width(3.0);
    for(int i = 0; i < funcs.size(); i++)
    {
        auto f = funcs[i];

        cr->set_source_rgb(1 / float(i + 1), 1 / float(funcs.size() - i), 0);

        float past_x = -sized_width - step;
        float past_y = f(past_x);
        cr->move_to(past_x, past_y);
        for(float x = -sized_width, y; x < sized_width; x += step)
        {
            y = f(x);

            cr->line_to((x * size_coefficient) + half_width,
                        (y * size_coefficient * side_size) + half_height);

            past_x = x;
            past_y = y;
        }
        cr->stroke();
    }
    return true;
}

Scene::~Scene()
{
}
