binary		:= SNLS.ELF
ps2		:= 0 
debug		:= 0
flags		:= -g -DDEBUG=0
includes	:= -Iinclude -I.
libraries	:= -lSDL2 -lfreetype

ifeq ($(ps2), 1)
	source		+= src/platform/ps2
	prefix		:= mips64r5900el-ps2-elf-
	flags		+= -D_EE
	libraries	+= -L$(PS2SDK)/ee/lib -L$(PS2SDK)/ports/lib -L$(GSKIT)/lib \
			   -ldebug -lkernel -lps2_drivers -lgskit -ldma -ldmakit \
			   -lps2stuff -lps2gl  -lc -lm -lstdc++

	includes	+= -I$(PS2SDK)/ee/include -I$(PS2SDK)/common/include \
			   -I$(GSKIT)/include -I$(PS2SDK)/ports/include/GL \
			   -I$(PS2SDK)/ports/include -I$(PS2SDK)/ports/include/freetype2
	linkfile	:= -T$(PS2SDK)/ee/startup/linkfile
else
	libraries	+= -lc -lGL
	includes    	+= -I/usr/include/freetype2 \
			   -I/usr/include/ -I/usr/include/GL
	source		+= src/platform/pc
	prefix		:=
endif

ifeq  ($(debug), 1)
	flags		+= -fsanitize=address
	libraries	+= -lasan
endif

compiler	:= $(prefix)gcc
compiler_g++	:= $(prefix)g++

source		+= src \
		   src/core \
		   src/platform/cross \
		   src/emulator \
		   src/emulator/main \
		   src/tools

c_source 	+= $(foreach c_src, $(source), $(wildcard $(c_src)/*.c))
#c_source	+= $(foreach c_src, $(source), $(wildcard $(c_src)/*.cpp))
c_objects	+= $(patsubst %.c,build/%.o,$(c_source))
#c_objects	+= $(patsubst %.cpp,build/%.o,$(c_source))
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

#build/%.o: %.cpp
#	@mkdir -p $(@D)
#	@echo Building $@
#	$(compiler_g++) -c $^ -o $@ $(includes) $(flags) $(libraries)

clean:
	rm -rf build
