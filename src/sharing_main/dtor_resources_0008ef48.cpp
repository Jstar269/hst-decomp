/* HSTMATCH module=hstp_trans_main.prx start=0x0008ef48 end=0x0008f050 symbol=FUN_0008ef48 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0c) corrected by hand: inlined array dtor double null check and member cleanup; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
typedef unsigned char undefined;

extern "C" {
extern undefined DAT_003b04c0;
extern undefined4 DAT_003e1a08;
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001ed28(...);
extern int * FUN_0008d994(...);
extern int FUN_0008ee64(...);
extern int FUN_0008eec4(...);
}

extern "C" undefined4 * FUN_0008ef48(undefined4 *param_1, short param_2)
{
  void *s0;

  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b04c0);
    s0 = (void *)param_1[0x10];
    if (s0 != 0) {
      if (s0 != 0) {
        FUN_0008eec4((char *)s0 + 0x3078, -1);
        FUN_0008eec4((char *)s0 + 0x2c20, -1);
        FUN_00000788((char *)s0 + 0x1aa0, (void *)FUN_0008eec4, 0x458, 4);
        FUN_00000788((char *)s0 + 0x940, (void *)FUN_0008eec4, 0x458, 4);
        FUN_0008eec4((char *)s0 + 0x4e8, -1);
        FUN_0008ee64(s0, -1);
        FUN_00000a00(s0);
      }
      param_1[0x10] = 0;
    }
    if ((void *)param_1[0xf] != 0) {
      FUN_0008d994((int *)param_1[0xf], 1);
      param_1[0xf] = 0;
    }
    DAT_003e1a08 = 0;
    FUN_0001ed28(param_1, 0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
