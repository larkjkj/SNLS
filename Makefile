binary		:= SNLS.ELF
ps2		?= 0
flags		:= -D_USESDL
includes	:= -Iinclude -I.
libraries	:= -L/usr/lib -lSDL2 -lSDL2main

ifeq ($(ps2), 1)
	source		+= source/ps2
	prefix		:= mips64r5900el-ps2-elf-
	flags		+= -D_EE
	libraries	+= -L$(PS2SDK)/ee/lib -L$(PS2SDK)/ports/lib -ldebug -lkernel \
			   -lps2_drivers
	includes	+= -I$(PS2SDK)/ee/include -I$(PS2SDK)/common/include \
			   -I$(PS2SDK)/ports/include
	linkfile	:= -T$(PS2SDK)/ee/startup/linkfile
else
	prefix		:=
	libraries	+= -lc
	includes    += -I/usr/include/
endif

compiler	:= $(prefix)gcc
compiler_g++	:= $(prefix)g++

source		:= source

c_source 	:= $(foreach c_src, $(source), $(wildcard $(c_src)/*.c))
cpp_source	:= $(foreach cpp_src, $(source), $(wildcard $(cpp_src)/*.cpp))
c_objects	:= $(patsubst %.c,build/%.o,$(c_source))
#c_objects	+= $(patsubst %.cpp,build/%.o,$(cpp_source))

objects		:= $(c_objects)

all: $(binary)

$(binary): $(objects)
	$(compiler) $(linkfile) -o $@ $^ $(includes) $(libraries)

build/%.o: %.c
	@mkdir -p $(@D)
	$(compiler) -c $^ -o $@ $(includes) $(flags) $(libraries)

build/%.o: %.cpp
	$(compiler_g++) -c $^ -o $@ $(includes) $(flags) $(libraries)

clean:
	rm -rf $(binary) $(objects)
