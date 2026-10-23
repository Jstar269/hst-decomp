/* HSTMATCH module=EBOOT.BIN start=0x0024d808 end=0x0024d8dc symbol=FUN_0024d808 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
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

extern undefined DAT_002fbdbc;
extern undefined DAT_003070bc;
extern undefined4 DAT_0034a77c;
extern char DAT_002fbd9c[];
extern char DAT_002fbdc0[];
extern char DAT_002fbddc[];
extern char DAT_002fbde8[];
extern undefined8 FUN_00020f5c(float);
extern int * FUN_000649c0();
extern undefined4 FUN_000651b8();
extern undefined4 * FUN_0008c230();
extern void FUN_0024d8dc();
extern void FUN_0024d908();

undefined4 * FUN_0024d808(undefined4 *param_1)
{
  int iVar2;
  undefined4 *puVar1;
  undefined8 uVar3;
  
  FUN_000649c0();
  *param_1 = (unsigned int)(&DAT_003070bc);
  FUN_0008c230(param_1 + 4);
  FUN_0008c230(param_1 + 8);
  DAT_0034a77c = (unsigned int)(param_1);
  FUN_000651b8(param_1,DAT_002fbd9c,1,0,&DAT_002fbdbc);
  FUN_0024d908(param_1);
  FUN_0024d8dc(DAT_002fbdc0);
  FUN_0024d8dc(DAT_002fbddc);
  iVar2 = 0;
  puVar1 = param_1;
  do {
    uVar3 = FUN_00020f5c(*(float *)((char *)puVar1 + 0x30));
    FUN_0024d8dc(DAT_002fbde8,iVar2 + 1,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 9);
  return param_1;
}
