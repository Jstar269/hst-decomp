/* HSTMATCH module=hstp_trans_main.prx start=0x001c6440 end=0x001c64d4 symbol=FUN_001c6440 lang=c99 */
/* Clone of src/eboot/FUN_001b8754_001b8754.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char uchar;

extern int DAT_003eaad8;
extern void FUN_001c2384(int *, float);
extern void FUN_001c2450(int *, int);

void FUN_001c6440(int param_1, int param_2)
{
  if (param_2 != 0 && *(uchar *)(param_1 + 0x78) != 0) {
    FUN_001c2450(&DAT_003eaad8, param_2);
  }
  else if (param_2 == 0) {
    if (*(uchar *)(param_1 + 0x78) == 0) {
      FUN_001c2450(&DAT_003eaad8, param_2);
      FUN_001c2384(&DAT_003eaad8, 0.5f);
    }
  }
  *(uchar *)(param_1 + 0x78) = ((param_2 != 0) ^ 1);
}
