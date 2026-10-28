/* HSTMATCH module=hstp_trans_main.prx start=0x0024c6b8 end=0x0024c700 symbol=FUN_0024c6b8 lang=c++ */
/* Clone of src/eboot/FUN_0023c520.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_0024c6b8(int param_1)
{
  ((VC_0 *)(*(int **)(param_1 + 8)))->m((int)(0));
  ((VC_1 *)(*(int **)(param_1 + 0x28)))->m((int)(0));
}
