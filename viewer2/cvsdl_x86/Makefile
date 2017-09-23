PKGPATH = /home/kenji/libs/opencv-3.2_x86+ffmpeg+x264-gtk/release/installed/lib/pkgconfig:/home/kenji/libs/SDL2_x86/lib/pkgconfig:/home/kenji/libs/ffmpeg_x86+x264/lib/pkgconfig
LD_LIBRARY_PATH = /home/kenji/libs/opencv-3.2_x86+ffmpeg+x264-gtk/release/installed/lib/:/home/kenji/libs/SDL2_x86/lib/:/home/kenji/libs/ffmpeg_x86+x264/lib/

CVL = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --libs   opencv)
CVC = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --cflags opencv)
SDL = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --libs   sdl2)
SDC = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --cflags sdl2)
FFL = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --libs   libswresample)
FFC = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --cflags libswresample)
TGT = uvccamera2_x86
C11 = -std=c++11

$(TGT): main.o application.o sdlutil.o
	@echo "CVC=" $(CVC)
	@echo "CVL=" $(CVL)
	@echo "SDC=" $(SDC)
	@echo "SDL=" $(SDL)
	g++ $^ -o $@ $(FFL) $(SDL) $(CVL) $(FFL)

application.o:application.cc application.h
	g++ -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC)

sdlutil.o:sdlutil.cc sdlutil.h
	g++ -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC)

main.o:main.cc
	g++ -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC)

clean:
	rm -f *.o
	rm -f $(TGT)
