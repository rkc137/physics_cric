#include "MainWindow.hpp"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& _builder):
        Gtk::Window(cobject), builder(_builder)
{
    //connect widgets to ui
    builder->get_widget("draw_button_ui", draw_button);
    builder->get_widget("ui_line_edit_1", line_edit_1);
    builder->get_widget("ui_line_edit_2", line_edit_2);
    builder->get_widget("ui_line_edit_3", line_edit_3);

    builder->get_widget_derived("scene_ui", scene);
    
    //connecting signals
    draw_button->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_draw_button_clicked));
        
}

void MainWindow::on_draw_button_clicked()
{
    float x = atof(line_edit_1->get_text().c_str());
    float y = atof(line_edit_2->get_text().c_str());
    float z = atof(line_edit_3->get_text().c_str());
    
    
}

MainWindow::~MainWindow()
{
}
