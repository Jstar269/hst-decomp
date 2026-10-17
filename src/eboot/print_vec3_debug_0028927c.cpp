/* HSTMATCH module=EBOOT.BIN start=0x0028927c end=0x00289300 symbol=FUN_0028927c lang=c++ */
/* Clone of src/eboot/print_vec3_debug_002891f8.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_00286acc(...);
extern char DAT_002febbc[];
struct Vec3 { float x, y, z; };

extern "C" void FUN_0028927c(int unused, Vec3 *v)
{
  FUN_00286acc(DAT_002febbc, (double)v->x, (double)v->y, (double)v->z);
}
