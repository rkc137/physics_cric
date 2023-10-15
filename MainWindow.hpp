#pragma once

#include <gtkmm.h>
#include <cairomm/context.h>

#include "Scene.hpp"

class MainWindow : public Gtk::Window
{
protected:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Button *draw_button;
    Gtk::Entry *line_edit_1; 
    Gtk::Entry *line_edit_2; 
    Gtk::Entry *line_edit_3;
    Scene *scene;

public:
    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& _builder);
    virtual ~MainWindow();

protected: //slots
    void on_draw_button_clicked();
};