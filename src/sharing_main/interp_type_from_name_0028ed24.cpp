/* HSTMATCH module=hstp_trans_main.prx start=0x0028ed24 end=0x0028edec symbol=FUN_0028ed24 lang=c++ */
/* Clone of src/eboot/interp_type_from_name_0012ffac.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map an interpolation-type name to an id with strstr (0x14d64): NORMALLINEAR 1, NORMALSECOND 2,
   VALUELINEAR 3, INSTANT 4, CROSSFADE 5, else 0; a null name gives 0 through the same if/else-if chain
   (an early return or an enclosing if(name) changes the layout). The first argument is unused. */
extern "C" {
char *FUN_00014d64(const char *s, const char *sub);
extern char DAT_003a74c0[];
extern char DAT_003a74d0[];
extern char DAT_003a74e0[];
extern char DAT_003a74ec[];
extern char DAT_003a74f4[];
}
extern "C" int FUN_0028ed24(void *self, const char *name)
{
    int r = 0;
    if (name == 0)
        r = 0;
    else if (FUN_00014d64(name, DAT_003a74c0))
        r = 1;
    else if (FUN_00014d64(name, DAT_003a74d0))
        r = 2;
    else if (FUN_00014d64(name, DAT_003a74e0))
        r = 3;
    else if (FUN_00014d64(name, DAT_003a74ec))
        r = 4;
    else if (FUN_00014d64(name, DAT_003a74f4))
        r = 5;
    return r;
}
