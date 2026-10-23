/* HSTMATCH module=EBOOT.BIN start=0x001c19e4 end=0x001c1c50 symbol=FUN_001c19e4 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern int DAT_003415a8;
extern uchar DAT_003417b8;
extern uchar DAT_003417b9;
extern uchar DAT_003417ba;
extern uchar DAT_003417bb;
extern uchar DAT_003417bc;
extern uchar DAT_003417bf;
extern uchar DAT_003417c0;
extern uchar DAT_003417c1;
extern uchar DAT_003417c2;
extern uchar DAT_003417cc;
extern uchar DAT_00341c50;
extern uchar DAT_00341c51;
extern uchar DAT_00341c52;
extern uchar DAT_00341ccc[];
extern undefined4 DAT_00341cec;
extern undefined4 DAT_00341cf0;
extern undefined4 DAT_00341cf4;
extern undefined4 DAT_00341cf8;
extern undefined4 DAT_00341cfc;
extern undefined4 DAT_00341d00;
extern undefined4 DAT_00341d04;
extern undefined4 DAT_00341d08;
extern undefined4 DAT_0034a77c;
extern char DAT_002ea298[];
extern char DAT_002ea2a4[];
extern int FUN_0016bb98(int,int);
extern int FUN_00193474(int);
extern void FUN_001be424(char *,int);
extern void FUN_001c1c50(int,void *,int,ushort,ushort,ushort,ushort,int,int,int,int,void *,int,int,int,void *,int,int,int,int,int,int,int,int,int);
extern int FUN_0024dd40(float param_1,int param_2);
}

extern "C" void FUN_001c19e4(int param_1,void *param_2,int param_3,uchar param_4,uchar param_5)
{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined1 uVar10;
  
  uVar4 = DAT_00341d04;
  iVar2 = DAT_003415a8;
  if (param_1 < 0) {
    iVar9 = 0;
  }
  else if (param_1 < 0xf) {
    iVar9 = (int)(DAT_00341ccc + param_1 * 0x38 + 4);
  }
  else {
    iVar9 = 0;
  }
  sVar1 = *(short *)(iVar9 + 2);
  iVar5 = iVar9 + (uint)*(byte *)(iVar9 + 1) * 0xc;
  iVar6 = FUN_00193474(param_1);
  iVar3 = DAT_003415a8;
  if (param_1 < 0) {
    uVar10 = 1;
  }
  else if (param_1 < 0xf) {
    uVar10 = *(undefined1 *)(param_1 + DAT_003415a8 + 0x10a5);
  }
  else {
    uVar10 = 1;
  }
  uVar7 = FUN_0016bb98(param_1,iVar6 + 0x68);
  uVar8 = FUN_0024dd40(*(float *)(iVar9 + 4),DAT_0034a77c);
  FUN_001c1c50(0,(void *)(iVar3 + 0x20),param_1,*(undefined2 *)(iVar5 + 8),*(undefined2 *)(iVar5 + 10),
               *(undefined2 *)(iVar5 + 0xc),*(undefined2 *)(iVar5 + 0xe),(int)sVar1,
               *(char *)(iVar5 + 0x11) != '\0',*(char *)(iVar5 + 0x12) != '\0',
               *(char *)(iVar5 + 0x10) != '\0',param_2,*(undefined4 *)(iVar3 + 0x10d4),uVar7,param_1
               ,(void *)(iVar6 + 0x68),uVar10,*(undefined1 *)(iVar2 + 0x86bcc),0,uVar8,0,uVar4,0,0,iVar6);
  DAT_003417cc = (undefined1)*(undefined2 *)(DAT_00341ccc + 0x1038);
  DAT_00341c52 = 0;
  DAT_00341c50 = param_3;
  DAT_00341c51 = param_4;
  FUN_001be424(DAT_002ea298,DAT_00341cfc);
  FUN_001be424(DAT_002ea2a4,DAT_00341d00);
  DAT_003417bc = param_5;
  DAT_003417bf = (char)DAT_00341d04;
  DAT_003417c2 = (char)DAT_00341cf4;
  DAT_003417c0 = (char)DAT_00341d08;
  DAT_003417bb = (char)DAT_00341cf8;
  DAT_003417ba = (char)DAT_00341d00;
  DAT_003417c1 = (char)DAT_00341cf0;
  DAT_003417b9 = (char)DAT_00341cfc;
  DAT_003417b8 = (char)DAT_00341cec;
  return;
}

// NEAR: 172/155 words, 156 differ. The frame is 16 bytes smaller than retail;
// retail keeps self in s5 and param_2 in s8, while this source keeps them in
// s0 and s6. The long FUN_001c1c50 argument setup and the first table/record
// address calculations still differ. Tried GCC 171/131 profiles, typed byte
// globals, array and pointer forms for DAT_00341ccc, a shared global-record
// layout, byte versus int parameters, and a full callee prototype.
// near miss from lane km4 (unreviewed)
