all: 	portal

portal:	src/*.cpp headers/*.h
		g++ src/*.cpp -o portal -Iheaders/  `pkg-config gtkmm-3.0 --cflags --libs`

debug:	src/*.cpp headers/*.h
		g++ src/*.cpp -o dportal -Iheaders/  `pkg-config gtkmm-3.0 --cflags --libs` -DDEBUG

both:	portal debug
