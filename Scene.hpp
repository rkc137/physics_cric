#pragma once

#include <gtkmm.h>
#include <cairomm/context.h>

#include <array>
#include <functional>
#include <cmath>

class Scene : public Gtk::DrawingArea
{
public:
    Scene(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    virtual ~Scene();

    void update_parametrs(std::array<float, 3> p);
    void update_coefficients(float zoom, float side);

private:
    float size_coefficient = 30;
    float side_size = 1;
    std::array<std::function<float(float)>, 3> funcs;

protected: //slots
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};