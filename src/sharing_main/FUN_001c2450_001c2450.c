/* HSTMATCH module=hstp_trans_main.prx start=0x001c2450 end=0x001c2514 symbol=FUN_001c2450 lang=c99 */
/* Clone of src/eboot/FUN_001b4464_001b4464.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: typed helper calls include their float and mode arguments, with an explicit negative early return; exact match verified; names and types await human review. */

extern void FUN_000637a8(int param_1,int param_2);
extern void FUN_000639e0(int param_1,float param_2,int param_3);

void FUN_001c2450(int *param_1,int param_2)
{
  int self = *param_1;

  if (param_2 != 0) {
    if (*(int *)(self + 0x7ac) >= 0) {
      FUN_000639e0(*(int *)(self + 0x7ac),0.5f,0);
      *(int *)(self + 2000) = *(int *)(self + 0x7ac);
      *(float *)(self + 0x7d4) = 0.0f;
    }
    if (*(int *)(self + 0x7b4) >= 0) {
      FUN_000639e0(*(int *)(self + 0x7b4),0.0f,128);
    }
  } else {
    if (*(int *)(self + 0x7b4) >= 0) {
      FUN_000639e0(*(int *)(self + 0x7b4),0.5f,0);
    }
    if (*(int *)(self + 0x7ac) < 0) return;
    FUN_000639e0(*(int *)(self + 0x7ac),0.0f,128);
    if (*(int *)(self + 2000) >= 0) {
      FUN_000637a8(*(int *)(self + 2000),0);
      *(int *)(self + 2000) = -1;
    }
    *(float *)(self + 0x7d4) = 1.0f;
  }
}
