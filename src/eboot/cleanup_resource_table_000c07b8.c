/* HSTMATCH module=EBOOT.BIN start=0x000c07b8 end=0x000c092c symbol=FUN_000c07b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: pass each tested field pointer to FUN_000009e4 and keep the loop index separate from its scaled offset. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern char DAT_00307408;
extern unsigned char DAT_00338acc;
extern void FUN_000009e4(void *);
extern void FUN_00000a00(void *);
extern undefined4 * FUN_0001f0f0(void *, int);
extern void FUN_000c1aa0(void *, int);

#pragma opt_strength_reduction off

undefined4 * FUN_000c07b8(undefined4 *param_1,short param_2)
{
  int iVar1;
  uint index;
  int offset;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307408);
    DAT_00338acc = 0;
    index = 0;
    if (param_1[0x1dd] != 0) {
      do {
        int scaled = index << 2;
        offset = (scaled + index) << 4;
        void *field44 = *(void **)((char *)param_1[0x1dc] + offset + 0x44);
        if (field44 != 0) {
          if (field44 != 0) {
            FUN_000009e4(field44);
            *(void **)((char *)param_1[0x1dc] + offset + 0x44) = 0;
          }
        } else {
          void *field40 = *(void **)((char *)param_1[0x1dc] + offset + 0x40);
          if (field40 != 0) {
            if (field40 != 0) {
              FUN_000009e4(field40);
              *(void **)((char *)param_1[0x1dc] + offset + 0x40) = 0;
            }
          }
        }
        index = index + 1;
      } while (index < param_1[0x1dd]);
    }
    if (param_1[0x1cb] != 0) {
      if (param_1[0x1cb] != 0) {
        FUN_000009e4((void *)param_1[0x1cb]);
        param_1[0x1cb] = 0;
      }
    }
    iVar1 = param_1[0x1db];
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_000009e4((void *)iVar1);
      param_1[0x1db] = 0;
    }
    if ((param_1 + 0x1df) != (undefined4 *)0x0 && (param_1 + 0x1df) != (undefined4 *)0x0) {
      FUN_000c1aa0(param_1 + 0x1df,0);
    }
    if ((param_1 + 0x1dc) != (undefined4 *)0x0 && (param_1 + 0x1dc) != (undefined4 *)0x0) {
      FUN_000c1aa0(param_1 + 0x1dc,0);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
