#include "MainWindow.hpp"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& _builder):
        Gtk::Window(cobject), builder(_builder)
{
    //connect widgets to ui
    builder->get_widget("line_edit_1_ui", line_edits[0]);
    builder->get_widget("line_edit_2_ui", line_edits[1]);
    builder->get_widget("line_edit_3_ui", line_edits[2]);
    builder->get_widget("draw_button_ui", draw_button);
    builder->get_widget("scale_bar_ui", scale_bar);
    builder->get_widget("scroll_bar_ui", scroll_bar);
    builder->get_widget_derived("scene_ui", scene);

    scale_bar->set_value(50);
    scroll_bar->set_value(50);
    
    
    //connecting signals
    draw_button->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::update_parametrs));
    // for(auto &le : line_edits)
    //     le->signal_changed().connect(sigc::mem_fun(*this, &MainWindow::update_parametrs));
}

void MainWindow::update_parametrs()
{
    scene->update_parametrs({
        atof(line_edits[0]->get_text().c_str()),
        atof(line_edits[1]->get_text().c_str()),
        atof(line_edits[2]->get_text().c_str())
    });

    scene->m_side_size = scale_bar->get_value();
    scene->m_offset_x = scroll_bar->get_value();
}

MainWindow::~MainWindow()
{
}
