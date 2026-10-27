/* HSTMATCH module=EBOOT.BIN start=0x0028927c end=0x00289300 symbol=FUN_0028927c lang=c++ data=0x002febbc */
/* Clone of src/eboot/print_vec3_debug_002891f8.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002febbc-0x002febe1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_00286acc(...);
struct Vec3 { float x, y, z; };

extern "C" void FUN_0028927c(int unused, Vec3 *v)
{
  FUN_00286acc("SetTargetPosition(%.2f, %.2f, %.2f)\n", (double)v->x, (double)v->y, (double)v->z);
}
