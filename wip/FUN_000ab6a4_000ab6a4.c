/* HSTMATCH module=EBOOT.BIN start=0x000ab6a4 end=0x000ab9c4 symbol=FUN_000ab6a4 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char bool;
#define ABS(x) ((x) < 0 ? -(x) : (x))

extern int FUN_000a8880();
extern undefined4 FUN_000a902c();
extern undefined4 FUN_000a938c();
extern undefined4 FUN_000a975c();
extern undefined4 FUN_000aa800();
extern undefined4 FUN_000a9f90();
extern undefined4 FUN_000aaae4();
extern undefined4 FUN_000ab458();
extern void FUN_00022434();
extern int FUN_000b3c68();
extern float FUN_0016442c();

undefined4 FUN_000ab6a4(int param_1, int param_2, undefined4 param_3, undefined4 param_4,
                        undefined4 param_5, undefined4 param_6, int param_7)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  float fVar4;
  float local_10;
  float local_c;

  iVar2 = FUN_000a8880();
  if (iVar2 == 0) {
    iVar2 = FUN_000a902c(param_1, param_2, param_3, param_4);
    if ((iVar2 == 0) &&
        ((param_7 != 3 || (iVar2 = FUN_000a938c(param_1, param_2, param_3, param_4), iVar2 == 0)))) {
      if ((param_7 != 4 ||
           (iVar2 = FUN_000a975c(param_1, param_2, param_3, param_4, param_5), iVar2 == 0))) {
        if ((param_7 != 0xb ||
             (iVar2 = FUN_000aa800(param_1, param_2, param_3, param_4, 1, 1), iVar2 == 0))) {
          if ((param_7 != 0xb ||
               (iVar2 = FUN_000a9f90(param_1, param_2, param_3, param_4, 1, 0), iVar2 == 0))) {
            iVar2 = FUN_000aaae4(param_1, param_2, param_3, param_4, param_5, 1, 0);
            if ((iVar2 == 0) &&
                ((param_7 != 10 ||
                  (iVar2 = FUN_000ab458(param_1, param_2, param_3, param_4), iVar2 == 0)))) {
              if (param_7 != 2) {
                return 0;
              }
              FUN_00022434(&local_10, param_2, param_3);
              uVar3 = FUN_000b3c68(param_1);
              fVar4 = (float)FUN_0016442c(uVar3, *(undefined4 *)(param_1 + 0x440));
              iVar2 = FUN_000b3c68(param_1);
              if ((1.0f - fVar4 * 0.01f) * *(float *)(iVar2 + 0x2c) * 0.01f <= ABS(local_10)) {
                bVar1 = 0;
              }
              else {
                iVar2 = FUN_000b3c68(param_1);
                if (-(*(float *)(iVar2 + 0x3c) * 0.01f) < local_c) {
                  iVar2 = FUN_000b3c68(param_1);
                  if (-(*(float *)(iVar2 + 0x24) * 0.01f) < local_c) {
                    bVar1 = local_c < 0.0f;
                  }
                  else {
                    bVar1 = 0;
                  }
                  if (bVar1 || 0.0f <= local_c) {
                    bVar1 = 0;
                  }
                  else {
                    bVar1 = 1;
                  }
                }
                else {
                  bVar1 = 0;
                }
                if (bVar1) {
                  bVar1 = 1;
                }
                else {
                  bVar1 = 0;
                }
              }
              if (!bVar1) {
                return 0;
              }
            }
          }
        }
      }
    }
    fVar4 = *(float *)(param_2 + 4);
  }
  else {
    fVar4 = *(float *)(param_2 + 4);
  }
  if (0.0f <= fVar4) {
    return 0;
  }
  return 1;
}
// near miss from lane fm10 (unreviewed)
