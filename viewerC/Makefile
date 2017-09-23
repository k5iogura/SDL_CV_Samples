PKGPATH = /home/kenji/win_shared/cv/opencv/x86_linux_gcc/installed/lib/pkgconfig:/home/kenji/libs/SDL2_x86/lib/pkgconfig:/home/kenji/libs/ffmpeg_x86+x264/lib/pkgconfig
LD_LIBRARY_PATH = /home/kenji/win_shared/cv/opencv/x86_linux_gcc/installed/lib/:/home/kenji/libs/SDL2_x86/lib/:/home/kenji/libs/ffmpeg_x86+x264/lib/

CVL = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --libs   opencv)
CVC = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --cflags opencv)
SDL = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --libs   sdl2)
SDC = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --cflags sdl2)
FFL = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --libs   libswresample)
FFC = $(shell PKG_CONFIG_PATH=$(PKGPATH) pkg-config --cflags libswresample)
DRK = -I/home/kenji/win_shared/Darknet/darknet_x86/include
DLB = -L/home/kenji/win_shared/Darknet/darknet_x86/ -ldarknet
TGT = uvccameraC_x86
#C11 = -std=c++11

$(TGT): main.o sdl_image.o
#	@echo "CVC=" $(CVC)
#	@echo "CVL=" $(CVL)
#	@echo "SDC=" $(SDC)
#	@echo "SDL=" $(SDL)
	gcc $^ $(DLB) -o $@ $(FFL) $(SDL) $(CVL) $(FFL)

sdl_image.o:sdl_image.c
	gcc -c -fPIC -Wno-format-security $(C11) $< -o $@ $(SDC) $(CVC) $(DRK)

main.o:main.c
	gcc -c -fPIC $(C11) $< -o $@ $(SDC) $(CVC) $(DRK)

clean:
	rm -f *.o
	rm -f $(TGT)
