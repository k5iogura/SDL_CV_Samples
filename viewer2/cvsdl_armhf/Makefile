PKG = /home/kenji/libs/opencv-3.2_armhf_NEON_VFPV3_medium+ffmpeg/release/installed/lib/pkgconfig:/home/kenji/workbench/sdl2/final/lib/pkgconfig:/home/kenji/libs/:/home/kenji/libs/SDL2_armhf/lib/pkgconfig
LD_LIBRARY_PATH = /home/kenji/libs/opencv-3.2_armhf_NEON_VFPV3_medium+ffmpeg/release/installed/lib/:/home/kenji/workbench/sdl2/final/lib/:/home/kenji/libs/:/home/kenji/libs/SDL2_armhf/lib/:/home/kenji/ffmpeg_armhf+x264/lib

ARM = /home/kenji/altera/15.1/embedded/ds-5/sw/gcc/bin/arm-linux-gnueabihf
CVL = $(shell export PKG_CONFIG_PATH=$(PKG) ; pkg-config --libs   opencv)
CVC = $(shell export PKG_CONFIG_PATH=$(PKG) ; pkg-config --cflags opencv)
SDL = $(shell export PKG_CONFIG_PATH=$(PKG) ; pkg-config --libs   sdl2)
SDC = $(shell export PKG_CONFIG_PATH=$(PKG) ; pkg-config --cflags sdl2)
TGT = uvccamera2_armhf
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
