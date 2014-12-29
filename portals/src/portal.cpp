#include "portal.h"
#include <iostream>

Portal::Portal(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
: Gtk::Window(cobject)
{
	builder->get_widget("portal_image", portal_image);
	if(!portal_image)
		std::cout << "Erro ao carregar layout;";

	add_events(Gdk::POINTER_MOTION_MASK);
	this->signal_motion_notify_event().connect(sigc::mem_fun(*this, &Portal::on_mouse_move));
}

Portal::~Portal(){
	delete portal_image;
}

Gtk::Image* Portal::get_image_widget(){
	return portal_image;
}

bool Portal::on_mouse_move(GdkEventMotion* event)
{
  std::cout << "mouse_move()" << std::endl;
}