include Make_dirs

ifdef SystemRoot
	RM := del /Q
	FixPath = $(subst /,\,$1)
	SYS := WIN
else
	ifeq ($(shell uname), Linux)
		RM := rm -f
		FixPath = $1
		SYS := LINUX
	endif
endif

CC := $(CROSS_COMPILE)gcc
AS := $(CROSS_COMPILE)as
LD := $(CROSS_COMPILE)ld
OBJCOPY := $(CROSS_COMPILE)objcopy

Applications := FBOOT_S8500_b1x FBOOT_S8530_b1x FBOOT_S8500_b2x FBOOT_S8530_b2x
OutputFiles := $(patsubst %, $(OutDir)/%.fota, $(Applications))

application: $(OutputFiles)

rebuild: clean application

include $(SrcMake)
