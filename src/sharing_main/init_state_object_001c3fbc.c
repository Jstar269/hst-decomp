/* HSTMATCH module=hstp_trans_main.prx start=0x001c3fbc end=0x001c40a0 symbol=FUN_001c3fbc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: deferred local_c assignment to call site and used symbol &DAT_003eaad8; exact match verified; names and types await human review. */
typedef unsigned char uchar;

extern char DAT_003eaad8;
extern void FUN_001c20b8(void *p);
extern void FUN_001c230c(void *p);
extern void FUN_001c71e4(void *ret, void *f0, int *p8, int **pc);

void FUN_001c3fbc(char *param_1)
{
  char local_4[4];
  int local_8;
  int *local_c;
  
  FUN_001c20b8(&DAT_003eaad8);
  FUN_001c230c(&DAT_003eaad8);
  *(int *)(param_1 + 0x4c) = -1;
  *(int *)(param_1 + 0x50) = -1;
  *(int *)(param_1 + 0x54) = -1;
  *(int *)(param_1 + 0x58) = -1;
  **(int **)(param_1 + 0x5c) = -1;
  **(uchar **)(param_1 + 0x60) = 0;
  *(int *)(*(int *)(param_1 + 0x5c) + 4) = -1;
  *(uchar *)(*(int *)(param_1 + 0x60) + 1) = 0;
  *(int *)(*(int *)(param_1 + 0x5c) + 8) = -1;
  *(uchar *)(*(int *)(param_1 + 0x60) + 2) = 0;
  *(int *)(*(int *)(param_1 + 0x5c) + 0xc) = -1;
  *(uchar *)(*(int *)(param_1 + 0x60) + 3) = 0;
  *(int *)(param_1 + 100) = -1;
  *(int *)(param_1 + 0x68) = -1;
  *(int *)(param_1 + 0x6c) = 0;
  *(uchar *)(param_1 + 0x70) = 0;
  *(uchar *)(param_1 + 0x78) = 1;
  *(uchar *)(param_1 + 0x79) = 1;
  *(uchar *)(param_1 + 0x7a) = 1;
  *(int *)(param_1 + 0x80) = 0;
  *(int *)(param_1 + 0x7c) = 0;
  *(int *)(param_1 + 0x84) = 0;
  *(int *)(param_1 + 0x88) = 0;
  *(int *)(param_1 + 0x8c) = 0;
  local_c = (int *)(param_1 + 0xf4);
  local_8 = *(int *)(param_1 + 0xf8);
  FUN_001c71e4(local_4, param_1 + 0xf0, &local_8, &local_c);
}
