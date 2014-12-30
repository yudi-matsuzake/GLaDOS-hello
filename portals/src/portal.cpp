#include "portal.h"
#include "debug.h"
#include <sstream>
#include <iostream>

/* PROTÓTIPOS */
void teletransporta(Portal* entrada, Portal* saida);
void move_mouse(int x, int y);

/*-----------*/

Portal::Portal(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
: Gtk::Window(cobject)
{
	//pegando do construtor o widget de imagem
	builder->get_widget("portal_image", portal_image);
	if(!portal_image)
		DEBUG("Error: could not load the image!");

	//ligando sinal
	add_events(Gdk::POINTER_MOTION_MASK);
	this->signal_motion_notify_event().connect(sigc::mem_fun(*this, &Portal::on_mouse_move));

	//ligando
	on = true;
}

Portal::~Portal(){
	delete portal_image;
}
 
Gtk::Image* Portal::get_image_widget(){
	return portal_image;
}

bool Portal::on_mouse_move(GdkEventMotion* event)
{	
	const int b_width = 60;
	const int b_height = 300;
	//se o outro portal existe
	if(another_portal != NULL){
		/* LIMITES DA ÁREA DE TELETRANSPORTE */
					   								//leia cantando: ((( ♫ )))
		int lim_l = (get_width()/2) - (b_width/2); 	//A ESQUERDA		♫♫ tuts tuts ♫♫
		int lim_r = (get_width()/2) + (b_width/2); 	//A DIREITA		♫♫ tuts tuts ♫♫
		int lim_u = (get_height()/2) - (b_height/2);//EM CIMA		♫♫ tuts tuts ♫♫
		int lim_d = (get_height()/2) + (b_height/2);//EM BAIXO		♫♫ tuts tuts ♫♫

					  								//♫♫ ♫  ♫   ♫     ♫     ♫   ♫  ♫ ♫♫

		DEBUG(get_title() << ":");
		DEBUG("x: " << event->x);
		DEBUG("y: " << event->y);

		//se está na área de teletransporte
		if(event->x > lim_l && event->x < lim_r &&
			event->y > lim_u && event->y < lim_d){
			DEBUG("I'm in the teleportation area!");
			if(this->on){
				teletransporta(this, another_portal);
			}
			
		}else{
			this->on = true;
		}
	}
}

void Portal::set_another(Portal *f){
	another_portal = f;
}

//teletransporta o cursor
void teletransporta(Portal* entrada, Portal* saida){
	DEBUG("TELEPORTS!");
	saida->on = false;

	int x, y;

	saida->get_position(x, y);

	move_mouse((x + (saida->get_width()/2)), (y + (saida->get_height()/2)));
}

//movimenta o mouse para a posição (x, y) da tela
void move_mouse(int x, int y){
	DEBUG("(" << x << ", " << "y" << ")");
	std::ostringstream cmd;
	cmd << "xdotool mousemove ";
	cmd << x;
	cmd << " ";
	cmd << y;

	system(cmd.str().c_str());
}