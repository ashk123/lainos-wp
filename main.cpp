#include "include/window.h"
#include <gtkmm/application.h>

int main(int argc, char* argv[]) {
	auto app = Gtk::Application::create("org.gtkmm.example");
	// Glib::RefPtr<Gtk::MediaFile> mediafile = Gtk::MediaFile::create_for_filename("a.wav");
    // mediafile->set_loop(true);
    // mediafile->play();
	return app->make_window_and_run<MyWindow>(argc, argv);
}
