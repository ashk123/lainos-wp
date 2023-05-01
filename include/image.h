#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class ImageShow : public Gtk::DrawingArea
{
public:
  ImageShow();
  virtual ~ImageShow();

protected:
  void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);

  Glib::RefPtr<Gdk::Pixbuf> m_image;
};
