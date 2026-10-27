/* HSTMATCH module=hstp_trans_main.prx start=0x0013b564 end=0x0013b62c symbol=FUN_0013b564 lang=c++ data=0x00382234 */
/* Clone of src/eboot/interp_type_from_name_0012ffac.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x00382234-0x00382272) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map an interpolation-type name to an id with strstr (0x14d64): NORMALLINEAR 1, NORMALSECOND 2,
   VALUELINEAR 3, INSTANT 4, CROSSFADE 5, else 0; a null name gives 0 through the same if/else-if chain
   (an early return or an enclosing if(name) changes the layout). The first argument is unused. */
extern "C" {
char *FUN_00014d64(const char *s, const char *sub);
}
extern "C" int FUN_0013b564(void *self, const char *name)
{
    int r = 0;
    if (name == 0)
        r = 0;
    else if (FUN_00014d64(name, "NORMALLINEAR"))
        r = 1;
    else if (FUN_00014d64(name, "NORMALSECOND"))
        r = 2;
    else if (FUN_00014d64(name, "VALUELINEAR"))
        r = 3;
    else if (FUN_00014d64(name, "INSTANT"))
        r = 4;
    else if (FUN_00014d64(name, "CROSSFADE"))
        r = 5;
    return r;
}
