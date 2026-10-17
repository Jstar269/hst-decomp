/* HSTMATCH module=EBOOT.BIN start=0x0008d7b0 end=0x0008d8b8 symbol=FUN_0008d7b0 lang=c++ */
/* Clone of src/sharing_main/dtor_resources_0008ef48.cpp (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0c) corrected by hand: inlined array dtor double null check and member cleanup; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
typedef unsigned char undefined;

extern "C" {
extern undefined DAT_003071f4;
extern undefined4 DAT_003386c8;
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001f0f0(...);
extern int * FUN_0008c248(...);
extern int FUN_0008d6cc(...);
extern int FUN_0008d72c(...);
}

extern "C" undefined4 * FUN_0008d7b0(undefined4 *param_1, short param_2)
{
  void *s0;

  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003071f4);
    s0 = (void *)param_1[0x10];
    if (s0 != 0) {
      if (s0 != 0) {
        FUN_0008d72c((char *)s0 + 0x3078, -1);
        FUN_0008d72c((char *)s0 + 0x2c20, -1);
        FUN_00000788((char *)s0 + 0x1aa0, (void *)FUN_0008d72c, 0x458, 4);
        FUN_00000788((char *)s0 + 0x940, (void *)FUN_0008d72c, 0x458, 4);
        FUN_0008d72c((char *)s0 + 0x4e8, -1);
        FUN_0008d6cc(s0, -1);
        FUN_00000a00(s0);
      }
      param_1[0x10] = 0;
    }
    if ((void *)param_1[0xf] != 0) {
      FUN_0008c248((int *)param_1[0xf], 1);
      param_1[0xf] = 0;
    }
    DAT_003386c8 = 0;
    FUN_0001f0f0(param_1, 0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
