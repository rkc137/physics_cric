#pragma once

#include <gtkmm.h>

class Scene : public Gtk::DrawingArea
{
public:
    Scene(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
    virtual ~Scene();

private:
    float math_function_1(float x);
    float math_function_2(float x);
    float math_function_3(float x);

protected: //slots
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};