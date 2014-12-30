#ifndef _PORTAL_H_
#define _PORTAL_H_
#include <gtkmm.h>

class Portal : public Gtk::Window{
public:
	Portal(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
	virtual ~Portal();

	Gtk::Image* get_image_widget();
	bool on_mouse_move(GdkEventMotion* event);

	void set_another(Portal *f);

	bool on;

private:
	Gtk::Image *portal_image;
	Portal* another_portal;

};

#endif