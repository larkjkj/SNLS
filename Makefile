binary		:= SNLS.ELF
ps2		:= 0 
flags		:= -D_USESDL
includes	:= -Iinclude -I.
libraries	:= -L/usr/lib -lfreetype

ifeq ($(ps2), 1)
	source		+= src/platform/ps2
	prefix		:= mips64r5900el-ps2-elf-
	flags		+= -D_EE
	libraries	:= -L$(PS2SDK)/ee/lib -L$(PS2SDK)/ports/lib -ldebug -lkernel \
			   -lps2_drivers
	includes	+= -I$(PS2SDK)/ee/include -I$(PS2SDK)/common/include \
			   -I$(PS2SDK)/ports/include
	linkfile	:= -T$(PS2SDK)/ee/startup/linkfile
else
	libraries	+= -lc -lGL -lglfw -lGLEW
	includes    	+= -I/usr/include/freetype2 \
			   -I/usr/include/ -I/usr/include/GL
	source		+= src/platform/pc
	prefix		:=
endif

compiler	:= $(prefix)gcc
compiler_g++	:= $(prefix)g++

source		+= src \
		   src/core \
		   src/platform/cross \
		   src/emulator \
		   src/emulator/main \
		   src/tools

c_source 	:= $(foreach c_src, $(source), $(wildcard $(c_src)/*.c))
#cpp_source	:= $(foreach cpp_src, $(source), $(wildcard $(cpp_src)/*.cpp))
c_objects	:= $(patsubst %.c,build/%.o,$(c_source))
#c_objects	+= $(patsubst %.cpp,build/%.o,$(cpp_source))

# not used
# objects		:= $(c_objects)

all: $(binary)

$(binary): $(c_objects)
	$(compiler) $(linkfile) -o $@ $^ $(includes) $(libraries)

build/%.o: %.c
	@mkdir -p $(@D)
	@echo Building $@
	$(compiler) -c $^ -o $@ $(includes) $(flags) $(libraries)

build/%.o: %.cpp
	$(compiler_g++) -c $^ -o $@ $(includes) $(flags) $(libraries)

clean:
	rm -rf build
