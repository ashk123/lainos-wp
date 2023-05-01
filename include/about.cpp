#include "about.h"
#include "config.h"

// init strings
strings str2;

AboutWindow::AboutWindow()
: binfor(Gtk::Orientation::VERTICAL),
  infor("")
{
	set_default_size(600, 400);
	set_title("About page");
	set_child(binfor);
	infor.set_justify(Gtk::Justification::CENTER);
	infor.set_markup("<span font='10' font-family='adler'>"+str2.about+"</span>");
	binfor.set_valign(Gtk::Align::CENTER);
	binfor.set_halign(Gtk::Align::CENTER);
	binfor.append(infor);
	binfor.append(Myimage);
}

AboutWindow::~AboutWindow() 
{

}