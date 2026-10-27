/* HSTMATCH module=EBOOT.BIN start=0x002891f8 end=0x0028927c symbol=FUN_002891f8 lang=c++ data=0x002feb9c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002feb9c-0x002febbb) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" void FUN_00286acc(...);
struct Vec3 { float x, y, z; };

extern "C" void FUN_002891f8(int unused, Vec3 *v)
{
  FUN_00286acc("SetPosition(%.2f, %.2f, %.2f)\n", (double)v->x, (double)v->y, (double)v->z);
}
