PKGPATH = /home/ogura/libs/opencv-3.2_x86+ffmpeg-gtk_basic/release/installed/lib/pkgconfig:/home/ogura/libs/SDL2_x86/lib/pkgconfig:/home/ogura/libs/ffmpeg_x86_basic/lib/pkgconfig

CVL = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --libs   opencv)
CVC = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --cflags opencv)
SDL = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --libs   sdl2)
SDC = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --cflags sdl2)
FFL = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --libs   libswresample)
FFC = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --cflags libswresample)
TGT = uvccamera_x86
C11 = -std=c++11

$(TGT): main.o application.o sdlutil.o
	@echo "CVC=" $(CVC)
	@echo "CVL=" $(CVL)
	@echo "SDC=" $(SDC)
	@echo "SDL=" $(SDL)
	g++ $^ -o $@ $(FFL) $(SDL) $(CVL) $(FFL)

application.o:application.cc
	g++ -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC)

sdlutil.o:sdlutil.cc
	g++ -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC)

main.o:main.cc
	g++ -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC)

clean:
	rm -f *.o
	rm -f $(TGT)
