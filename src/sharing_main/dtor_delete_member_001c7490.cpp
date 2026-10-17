/* HSTMATCH module=hstp_trans_main.prx start=0x001c7490 end=0x001c7518 symbol=FUN_001c7490 lang=c++ */
/* Clone of src/eboot/dtor_delete_member_001b97a4.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual deleting-destructor call (struct with a 4-byte non-polymorphic base so the vptr is at +4), delete of the member; exact match verified; names and types await human review. */
extern char DAT_003b25c4;
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_0001ed28(void *, int);
struct VB_0 { int x; };
struct VC_0 : VB_0 { virtual ~VC_0(); };

extern "C" unsigned *FUN_001c7490(unsigned *param_1, short param_2)
{
  if (param_1 != 0) {
    *param_1 = (unsigned)&DAT_003b25c4;
    VC_0 *m = (VC_0 *)param_1[0xf];
    if (m != 0) {
      delete m;
      param_1[0xf] = 0;
    }
    FUN_0001ed28(param_1, 0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
