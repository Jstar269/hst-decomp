/* HSTMATCH module=hstp_trans_main.prx start=0x00191248 end=0x00191524 symbol=FUN_00191248 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the or chain is right-nested (a | (b | (c | 0x80000000))); a left-nested chain gives 56-68 differing words. Labels 0..3 are written in ascending order (MWCC tests them in reverse). */
typedef unsigned int uint;
typedef unsigned short ushort;
extern "C" {
extern int *FUN_00177eb4();
extern int FUN_00225dec(int);
}
static inline uint PackColor(ushort r, ushort g, ushort b)
{
  return (r & 0xff) | (((g & 0xff) << 8) | (((b & 0xff) << 16) | 0x80000000));
}

extern "C" void FUN_00191248(int param_1, uint *param_2, uint *param_3, int param_4)
{
  int *puVar1 = FUN_00177eb4();
    ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  switch (param_4) {
  case 0:
    uVar2 = FUN_00225dec(puVar1[0]);
    uVar3 = FUN_00225dec(puVar1[1]);
    uVar4 = FUN_00225dec(puVar1[2]);
    uVar5 = FUN_00225dec(puVar1[12]);
    uVar6 = FUN_00225dec(puVar1[13]);
    uVar7 = FUN_00225dec(puVar1[14]);
    *param_2 = PackColor(uVar2, uVar3, uVar4);
    *param_3 = PackColor(uVar5, uVar6, uVar7);
    break;
  case 1:
    uVar2 = FUN_00225dec(puVar1[3]);
    uVar3 = FUN_00225dec(puVar1[4]);
    uVar4 = FUN_00225dec(puVar1[5]);
    uVar5 = FUN_00225dec(puVar1[15]);
    uVar6 = FUN_00225dec(puVar1[16]);
    uVar7 = FUN_00225dec(puVar1[17]);
    *param_2 = PackColor(uVar2, uVar3, uVar4);
    *param_3 = PackColor(uVar5, uVar6, uVar7);
    break;
  case 2:
    uVar2 = FUN_00225dec(puVar1[6]);
    uVar3 = FUN_00225dec(puVar1[7]);
    uVar4 = FUN_00225dec(puVar1[8]);
    uVar5 = FUN_00225dec(puVar1[18]);
    uVar6 = FUN_00225dec(puVar1[19]);
    uVar7 = FUN_00225dec(puVar1[20]);
    *param_2 = PackColor(uVar2, uVar3, uVar4);
    *param_3 = PackColor(uVar5, uVar6, uVar7);
    break;
  case 3:
    uVar2 = FUN_00225dec(puVar1[9]);
    uVar3 = FUN_00225dec(puVar1[10]);
    uVar4 = FUN_00225dec(puVar1[11]);
    uVar5 = FUN_00225dec(puVar1[21]);
    uVar6 = FUN_00225dec(puVar1[22]);
    uVar7 = FUN_00225dec(puVar1[23]);
    *param_2 = PackColor(uVar2, uVar3, uVar4);
    *param_3 = PackColor(uVar5, uVar6, uVar7);
    break;
  }
}
