#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm.h>
#include "about.h"

class MyWindow : public Gtk::Window {
	public :
		MyWindow();
		~MyWindow() override;

	protected :
		void on_button_clicked(const Glib::ustring &data);
		Gtk::Box m_box1;
		Gtk::Box m_box2;
		Gtk::Box m_box3;
		Gtk::Box m_box4;
		Gtk::Box m_box5;
		Gtk::Button m_button1, m_button2, m_button3, m_button4,
			m_button5, m_button6;
		Gtk::Label m_label;
		Gtk::Window *about_window;
		ImageShow Myimage;
};

