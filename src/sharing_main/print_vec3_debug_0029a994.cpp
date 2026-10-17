/* HSTMATCH module=hstp_trans_main.prx start=0x0029a994 end=0x0029aa18 symbol=FUN_0029a994 lang=c++ */
/* Clone of src/eboot/print_vec3_debug_002891f8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_00297e90(...);
extern char DAT_003a7ac4[];
struct Vec3 { float x, y, z; };

extern "C" void FUN_0029a994(int unused, Vec3 *v)
{
  FUN_00297e90(DAT_003a7ac4, (double)v->x, (double)v->y, (double)v->z);
}
