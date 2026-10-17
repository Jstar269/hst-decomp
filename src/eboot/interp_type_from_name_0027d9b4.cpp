/* HSTMATCH module=EBOOT.BIN start=0x0027d9b4 end=0x0027da7c symbol=FUN_0027d9b4 lang=c++ */
/* Clone of src/eboot/interp_type_from_name_0012ffac.cpp (hstclone.py tag c42): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map an interpolation-type name to an id with strstr (0x14d64): NORMALLINEAR 1, NORMALSECOND 2,
   VALUELINEAR 3, INSTANT 4, CROSSFADE 5, else 0; a null name gives 0 through the same if/else-if chain
   (an early return or an enclosing if(name) changes the layout). The first argument is unused. */
extern "C" {
char *FUN_00014d64(const char *s, const char *sub);
extern char DAT_002fe740[];
extern char DAT_002fe750[];
extern char DAT_002fe760[];
extern char DAT_002fe76c[];
extern char DAT_002fe774[];
}
extern "C" int FUN_0027d9b4(void *self, const char *name)
{
    int r = 0;
    if (name == 0)
        r = 0;
    else if (FUN_00014d64(name, DAT_002fe740))
        r = 1;
    else if (FUN_00014d64(name, DAT_002fe750))
        r = 2;
    else if (FUN_00014d64(name, DAT_002fe760))
        r = 3;
    else if (FUN_00014d64(name, DAT_002fe76c))
        r = 4;
    else if (FUN_00014d64(name, DAT_002fe774))
        r = 5;
    return r;
}
