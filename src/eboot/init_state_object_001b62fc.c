/* HSTMATCH module=EBOOT.BIN start=0x001b62fc end=0x001b63e0 symbol=FUN_001b62fc lang=c99 */
/* Clone of src/sharing_main/init_state_object_001c3fbc.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: deferred local_c assignment to call site and used symbol &DAT_0034179c; exact match verified; names and types await human review. */
typedef unsigned char uchar;

extern char DAT_0034179c;
extern void FUN_001b3e2c(void *p);
extern void FUN_001b41c8(void *p);
extern void FUN_001b94f8(void *ret, void *f0, int *p8, int **pc);

void FUN_001b62fc(char *param_1)
{
  char local_4[4];
  int local_8;
  int *local_c;
  
  FUN_001b3e2c(&DAT_0034179c);
  FUN_001b41c8(&DAT_0034179c);
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
  FUN_001b94f8(local_4, param_1 + 0xf0, &local_8, &local_c);
}
