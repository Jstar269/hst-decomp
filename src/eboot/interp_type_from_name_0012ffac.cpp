/* HSTMATCH module=EBOOT.BIN start=0x0012ffac end=0x00130074 symbol=FUN_0012ffac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map an interpolation-type name to an id with strstr (0x14d64): NORMALLINEAR 1, NORMALSECOND 2,
   VALUELINEAR 3, INSTANT 4, CROSSFADE 5, else 0; a null name gives 0 through the same if/else-if chain
   (an early return or an enclosing if(name) changes the layout). The first argument is unused. */
extern "C" {
char *FUN_00014d64(const char *s, const char *sub);
extern char DAT_002db028[];
extern char DAT_002db038[];
extern char DAT_002db048[];
extern char DAT_002db054[];
extern char DAT_002db05c[];
}
extern "C" int FUN_0012ffac(void *self, const char *name)
{
    int r = 0;
    if (name == 0)
        r = 0;
    else if (FUN_00014d64(name, DAT_002db028))
        r = 1;
    else if (FUN_00014d64(name, DAT_002db038))
        r = 2;
    else if (FUN_00014d64(name, DAT_002db048))
        r = 3;
    else if (FUN_00014d64(name, DAT_002db054))
        r = 4;
    else if (FUN_00014d64(name, DAT_002db05c))
        r = 5;
    return r;
}
