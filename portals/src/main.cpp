#include <iostream>
#include "portal.h"

using namespace std;



int main(int argc, char* argv[]){
	//aplicação
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "yudi.portal");

	//criando os construtores
	Glib::RefPtr<Gtk::Builder> or_builder = Gtk::Builder::create();
	Glib::RefPtr<Gtk::Builder> bl_builder = Gtk::Builder::create();
	
	//construindo duas janelas apartir do arquivo
	Portal* o, *b;
	or_builder->add_from_file("layout/portal.glade");
	bl_builder->add_from_file("layout/portal.glade");

	//pegando o widget
	or_builder->get_widget_derived("portal", o);
	bl_builder->get_widget_derived("portal", b);

	//setando as imagens e o titulo
	o->get_image_widget()->set("images/laranja.gif");
	o->set_title("Laranja");

	b->get_image_widget()->set("images/azul.png");
	b->set_title("Azul");

	//pega a tela
	Glib::RefPtr<Gdk::Screen>  screen = b->get_screen();

	//setando a gravidade das janelas
	o->move(0, 0);
	b->move(screen->get_width() - b->get_width(), screen->get_height() - b->get_height());

	//linkando o sinal
	o->show();

	app->run(*b);

	return 0;
}