/* HSTMATCH module=EBOOT.BIN start=0x002891f8 end=0x0028927c symbol=FUN_002891f8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_00286acc(...);
extern char DAT_002feb9c[];
struct Vec3 { float x, y, z; };

extern "C" void FUN_002891f8(int unused, Vec3 *v)
{
  FUN_00286acc(DAT_002feb9c, (double)v->x, (double)v->y, (double)v->z);
}
