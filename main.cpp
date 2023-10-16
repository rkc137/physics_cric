#include <gtkmm.h>

#include "MainWindow.hpp"

int main(int argc, char* argv[])
{
    Gtk::Main app(argc, argv);
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("ui.glade");
    MainWindow *mainWindow = nullptr;
    builder->get_widget_derived("main_window_ui", mainWindow);
    app.run(*mainWindow);
    delete mainWindow;
    return 0;
}
