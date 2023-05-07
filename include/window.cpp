#include "window.h"
#include <iostream>
#include "config.h"
#include <filesystem>
#include <cstdlib>

#define NORM " "
#define HOV ":hover "
#define AC ":active "


// init config.h
strings str;

std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";

struct CSS {
  Glib::ustring data;
};

// if you have deleted function you can use a refrence of that function :)
void SetStyle(Gtk::Button& btn, std::string style, std::string cc, std::string base = NORM) {
  CSS cstyle;
  cstyle.data = "." + cc + base + style;
  std::cout << cstyle.data << std::endl;
  auto provider = Gtk::CssProvider::create();
  provider->load_from_data(cstyle.data);
  auto ctx = btn.get_style_context();
  ctx->add_class(cc);
  ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void SetStyle(Gtk::Box& btn, std::string style, std::string cc, std::string base = NORM) {
  CSS cstyle;
  cstyle.data = "." + cc + base + style;
  std::cout << cstyle.data << std::endl;
  auto provider = Gtk::CssProvider::create();
  provider->load_from_data(cstyle.data);
  auto ctx = btn.get_style_context();
  ctx->add_class(cc);
  ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
}
void SetStyle(Gtk::CheckButton& btn, std::string style, std::string cc, std::string base = NORM) {
  CSS cstyle;
  cstyle.data = "." + cc + base + style;
  std::cout << cstyle.data << std::endl;
  auto provider = Gtk::CssProvider::create();
  provider->load_from_data(cstyle.data);
  auto ctx = btn.get_style_context();
  ctx->add_class(cc);
  ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
}


MyWindow::MyWindow() 
: m_button1(str.btn1),
  m_button2(str.btn2),
  m_button3(str.au),
  m_button4(str.gits),
  m_button5(str.git1),
  m_button6(str.git2),
  
  startup("Don't show me on each boot"),
  
  m_label(str.title),
  m_box1(Gtk::Orientation::VERTICAL, 0),
  m_box2(Gtk::Orientation::HORIZONTAL, 0),
  m_box4(Gtk::Orientation::HORIZONTAL, 0),
  m_box3(Gtk::Orientation::VERTICAL, 0),
  m_box5(Gtk::Orientation::VERTICAL, 0)
{
	set_default_size(800, 600);
	set_title("welcome to LainOS");
	//set_child(m_box1);
	set_child(m_box2);
	m_box1.set_margin(10);
	
	m_box1.append(m_button1);
	m_button1.set_margin(20);
	m_button1.set_expand();
 
	m_box1.append(m_button2);
	m_button2.set_margin(20);
	m_button2.set_expand();
	
	m_box2.append(m_box1);
	m_box1.set_expand();
	
	m_box2.append(m_box5);
	m_box5.append(m_label);
	m_box5.append(Myimage);
	startup.set_valign(Gtk::Align::CENTER);
	startup.set_halign(Gtk::Align::CENTER);
	SetStyle(startup, "{font-size: 15px; margin-top: 10px;}", "strup1");
	m_box5.append(startup);
	m_box5.set_valign(Gtk::Align::CENTER);
	m_box5.set_halign(Gtk::Align::CENTER);
	m_label.set_justify(Gtk::Justification::CENTER);
	m_label.set_markup("<span font='15' font-family='adler'>\n\n\n"+str.title+"</span>");
	m_label.set_expand();


	m_box3.set_margin(10);
	
	m_box3.append(m_button3);
	m_button3.set_margin(20);
	m_button3.set_expand();
	
	m_box3.append(m_button4);
	m_button4.set_margin(20);
	//m_button4.set_halign(Gtk::Align::START);
	m_button4.set_expand();

	// SetStyle(m_box3, "{background-color: green;}", "btn3");
	// SetStyle(m_box2, "{background-color: red;}", "btn4");
	// SetStyle(m_box1, "{background-color: blue;}", "btn6");
	SetStyle(m_button3, "{padding-left: 40px;padding-right: 40px;}", "btn3");
	SetStyle(m_button4, "{padding-left: 40px;padding-right: 40px;}", "btn4");	
	m_button4.signal_clicked().connect(
			[this]() {
				m_button4.set_visible(false);
				
				m_box4.append(m_button5);
				m_box4.append(m_button6);
				m_box4.set_margin(15);
				m_button5.set_margin(5);
				m_button6.set_margin(5);
				//m_button5.set_halign(Gtk::Align::FILL);
				//m_button5.set_valign(Gtk::Align::CENTER);
				
				//m_button6.set_halign(Gtk::Align::CENTER);
				//m_button6.set_valign(Gtk::Align::CENTER);

				SetStyle(m_button1, "{padding: 30px;}", "button1");
				SetStyle(m_button2, "{padding: 30px;}", "button1");
				m_button5.set_expand();
				m_button6.set_expand();
				m_box3.append(m_box4);
				m_box4.set_expand();
			}

		);
		m_button1.signal_clicked().connect(
			[this]() {
				about_window = new AboutWindow();
				about_window->show();
			}

		);
		m_button2.signal_clicked().connect(
			[this]() {
				system("firefox https://lainos.org &");
			}

		);
		m_button3.signal_clicked().connect(
			[this]() {
			}
		);
		m_button5.signal_clicked().connect(
			[this]() {
				system("firefox https://github.com/ashk123 &");
			}

		);
		m_button6.signal_clicked().connect(
			[this]() {
				system("firefox https://gitlab.com/LainOS &");
			}

		);

		startup.signal_toggled().connect(
			[this]() {
					// std::cout << startup.property_active() << std::endl;
				  if (startup.property_active() == 0) {
						std::filesystem::copy("/usr/share/lainos.desktop", HOME + "/.config/autostart");
				  } 
				  else if (startup.property_active() == 1) {
				  	std::filesystem::remove_all(HOME + "/.config/autostart/lainos.desktop");
				  }
				}
			);

		

	m_box2.append(m_box3);
	//m_box2.append(m_box4);
	m_box3.set_expand();
	m_box2.set_expand();

	// play();

}

MyWindow::~MyWindow(){
}
