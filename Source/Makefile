vpath %.c $(SrcDir)

AppObjects := 	FOTA.o \
               s5pc110.o \
               BL3.o \
               string.o \
               footer.o \
               header.o \
               crc32.o \
               sha1.o \
               atag.o \

            
AppObjectsWithPath := $(patsubst %, $(ObjDir)/%, $(AppObjects))

#
$(OutDir)/%.fota: $(AppObjectsWithPath) $(ObjDir)/BL3_%.o $(ObjDir)/RAW_%.o
	$(LD) -T $*.lds $(AppObjectsWithPath) $(ObjDir)/RAW_$*.o $(ObjDir)/BL3_$*.o -o $(ObjDir)/$*.elf
	$(OBJCOPY) -O binary $(ObjDir)/$*.elf $@
   
$(ObjDir)/%.o: $(SrcDir)/%.c
	$(CC) -c -Os $^ -o $@
   
$(ObjDir)/%.o: $(SrcDir)/%.s
	$(AS) $^ -o $@

clean:
	$(RM) -f $(OutDir)/*.fota
	$(RM) -f $(ObjDir)/*.elf