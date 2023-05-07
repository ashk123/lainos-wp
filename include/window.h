#include <gtkmm.h>
#include "about.h"

class MyWindow : public Gtk::Window {
	public :
		MyWindow();
		~MyWindow() override;

	protected :
		Gtk::Box m_box1;
		Gtk::Box m_box2;
		Gtk::Box m_box3;
		Gtk::Box m_box4;
		Gtk::Box m_box5;
		Gtk::CheckButton startup;
		Gtk::Button m_button1, m_button2, m_button3, m_button4,
			m_button5, m_button6;
		Gtk::Label m_label;
		Gtk::Window *about_window;
		ImageShow Myimage;
};

