PKG = /home/ogura/libs/opencv-3.2_armhf_NEON_VFPV3_medium+ffmpeg/release/installed/lib/pkgconfig:/home/ogura/workbench/sdl2/final/lib/pkgconfig:/home/ogura/libs/:/home/ogura/libs/SDL2_armhf/lib/pkgconfig

ARM = /home/ogura/altera/15.1/embedded/ds-5/sw/gcc/bin/arm-linux-gnueabihf
CVL = $(shell export PKG_CONFIG_PATH=$(PKG) ; pkg-config --libs   opencv)
CVC = $(shell export PKG_CONFIG_PATH=$(PKG) ; pkg-config --cflags opencv)
SDL = $(shell export PKG_CONFIG_PATH=$(PKG) ; pkg-config --libs   sdl2)
SDC = $(shell export PKG_CONFIG_PATH=$(PKG) ; pkg-config --cflags sdl2)
TGT = uvccamera_armhf
C11 = -std=c++11 -static

$(TGT): main.o application.o sdlutil.o
	$(ARM)-g++ $^ -o $@ $(SDL) $(CVL)

application.o:application.cc
	$(ARM)-g++ -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC)

sdlutil.o:sdlutil.cc
	$(ARM)-g++ -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC)

main.o:main.cc
	$(ARM)-g++ -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC)

clean:
	rm -f *.o
	rm -f $(TGT)
