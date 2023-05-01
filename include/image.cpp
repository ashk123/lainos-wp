#include "image.h"
#include <cairomm/context.h>
#include <giomm/resource.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>

ImageShow::ImageShow()
{
  // bottom line can't run
  m_image = Gdk::Pixbuf::create_from_file("/usr/share/icons/a.svg");
  set_content_width(m_image->get_width());
  set_content_height(m_image->get_height());  
  set_draw_func(sigc::mem_fun(*this, &ImageShow::on_draw));
}

ImageShow::~ImageShow()
{
}

void ImageShow::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
  if (!m_image)
    return;

  // // Draw the image in the middle of the drawing area, or (if the image is
  // // larger than the drawing area) draw the middle part of the image.
  // Gdk::Cairo::set_source_pixbuf(cr, m_image,
  //   (width - m_image->get_width())/2, (height - m_image->get_height())/2);
  // cr->paint();
  

  Gdk::Cairo::set_source_pixbuf(cr, m_image, (width - m_image->get_width())/2, (height - m_image->get_height())/2);

  //cr->rectangle(50, 50, m_image->get_width()-20, m_image->get_height()-20);
  //cr->fill();
  cr->paint();
}
