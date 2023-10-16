#pragma once

#include <gtkmm.h>
#include <cairomm/context.h>

#include <array>

#include "Scene.hpp"

class MainWindow : public Gtk::Window
{
protected:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Button *draw_button;

    Glib::RefPtr<Gtk::Adjustment> scroll_bar_adjustment;
    Glib::RefPtr<Gtk::Adjustment> scale_bar_adjustment;
    Gtk::Scrollbar *scroll_bar;
    Gtk::Scale *scale_bar;
    
    std::array<Gtk::Entry*, 3> line_edits;
    Scene *scene;

public:
    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& _builder);
    virtual ~MainWindow();

protected: //slots
    void update_parametrs();
};