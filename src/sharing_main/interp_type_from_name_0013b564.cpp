/* HSTMATCH module=hstp_trans_main.prx start=0x0013b564 end=0x0013b62c symbol=FUN_0013b564 lang=c++ */
/* Clone of src/eboot/interp_type_from_name_0012ffac.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map an interpolation-type name to an id with strstr (0x14d64): NORMALLINEAR 1, NORMALSECOND 2,
   VALUELINEAR 3, INSTANT 4, CROSSFADE 5, else 0; a null name gives 0 through the same if/else-if chain
   (an early return or an enclosing if(name) changes the layout). The first argument is unused. */
extern "C" {
char *FUN_00014d64(const char *s, const char *sub);
extern char DAT_00382234[];
extern char DAT_00382244[];
extern char DAT_00382254[];
extern char DAT_00382260[];
extern char DAT_00382268[];
}
extern "C" int FUN_0013b564(void *self, const char *name)
{
    int r = 0;
    if (name == 0)
        r = 0;
    else if (FUN_00014d64(name, DAT_00382234))
        r = 1;
    else if (FUN_00014d64(name, DAT_00382244))
        r = 2;
    else if (FUN_00014d64(name, DAT_00382254))
        r = 3;
    else if (FUN_00014d64(name, DAT_00382260))
        r = 4;
    else if (FUN_00014d64(name, DAT_00382268))
        r = 5;
    return r;
}
