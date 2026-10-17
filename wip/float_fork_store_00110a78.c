/* HSTMATCH module=EBOOT.BIN start=0x00110a78 end=0x00110bb4 symbol=FUN_00110a78 lang=c99 */
typedef unsigned int undefined4;

extern float DAT_002d92b0;
extern int DAT_0034176c;
extern int FUN_00014934();
extern void FUN_0010d4a8(int);
extern undefined4 FUN_0016bc70();
extern void FUN_00197458(int, float, float);
extern int FUN_001987fc();

void FUN_00110a78(int param_1,int param_2,int param_3)
{
  int iVar1;
  float *pfVar2;
  float fVar3;  // (float)iVar1 kept in $f2 as in retail (cvt.s.w $f2)
  float local_4;

  if ((param_3 != 0) || (iVar1 = FUN_00014934(*(undefined4 *)(param_1 + 0x54)), iVar1 != 0)) {
    *(int *)(param_1 + 0x54) = param_2;
    if (param_2 != 0) {
      iVar1 = *(int *)(param_1 + 0x58);
      *(int *)(iVar1 + 0xf8) = param_2;
      *(undefined4 *)(iVar1 + 0x138) = 0;
      FUN_0010d4a8(iVar1);
      iVar1 = *(int *)(param_1 + 0x5c);
      *(undefined4 *)(iVar1 + 0xf8) = *(undefined4 *)(param_1 + 0x54);
      *(undefined4 *)(iVar1 + 0x138) = 0;
      FUN_0010d4a8(iVar1);
      iVar1 = DAT_0034176c;
      *(undefined4 *)(DAT_0034176c + 0x70) = 0x3f800000;
      *(undefined4 *)(iVar1 + 0x74) = 0;
      FUN_00197458(DAT_0034176c, 1.0f, 1.0f);
      *(undefined4 *)(DAT_0034176c + 0x84) = 0;
      iVar1 = FUN_001987fc(DAT_0034176c, *(undefined4 *)(param_1 + 0x54), 0, 0);
      fVar3 = (float)iVar1;
      *(float *)(param_1 + 0x78) = fVar3;
      local_4 = 64.0f + fVar3;
      if (local_4 < DAT_002d92b0) {
        pfVar2 = (float *)&DAT_002d92b0;
      }
      else {
        pfVar2 = &local_4;
      }
      *(float *)(param_1 + 0x74) = *pfVar2;  // near miss 5 words: retail loads *pfVar2 into $f0 (ours $f1), then mtc1 480.0f into $f1 and add.s $f0,$f1,$f0; ours is add.s $f0,$f0,$f1 with the registers swapped
      *(undefined4 *)(param_1 + 0x6c) = 0x43f00000;
      *(float *)(param_1 + 0x70) = 480.0f + *(float *)(param_1 + 0x74);  // operand/register order still differs (5 words: lwc1/mtc1/add.s registers at +0xe4..+0xf4); ruled out: fVar3 declaration order, 480.0f + x vs x + 480.0f, temp copy of *pfVar2 (same 5 words)
    }
    iVar1 = FUN_0016bc70();
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x68) = 10;
    }
    else {
      *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 100);
    }
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  return;
}
