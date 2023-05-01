CC=g++
OUTPUT=lainos-info
PREFIX := /usr/local

compile :
	$(CC) main.cpp include/window.cpp include/about.cpp include/image.cpp -O2 -o build/$(OUTPUT) `pkg-config gtkmm-4.0 --cflags --libs`

install: 
	install -m 777 build/$(OUTPUT) $(DESTDIR)$(PREFIX)/bin/
	install -m 777 media/a.svg $(DESTDIR)/usr/share/icons/
