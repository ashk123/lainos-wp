CC=g++
OUTPUT=lainos-info
PREFIX := /usr/local
GTKMMFLAGS=`pkg-config gtkmm-4.0 --cflags --libs`

lainos-wp :
	mkdir -p bin
	$(CC) main.cpp include/window.cpp include/about.cpp include/image.cpp -O2 -o bin/$(OUTPUT) $(GTKMMFLAGS)

install: 
	install -m 777 bin/$(OUTPUT) $(DESTDIR)$(PREFIX)/bin/
	install -m 777 media/a.svg $(DESTDIR)/usr/share/icons/
	install -m 777 lainos.desktop $(DESTDIR)/usr/share/

