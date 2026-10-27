/* HSTMATCH module=EBOOT.BIN start=0x0029a660 end=0x0029a830 symbol=FUN_0029a660 lang=c99 data=0x002ffdfc */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: ordered the guarded setup calls through a shared cleanup path and typed the channel count passed to cleanup; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x002ffdfc-0x002ffef1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined DAT_002ffcb0;
extern int DAT_002ffcc8;
extern undefined4 DAT_0034b320;
extern undefined4 DAT_0034b324;
extern char DAT_002ffd3c[];
extern char DAT_002ffd74[];
extern char DAT_002ffda4[];
extern char DAT_002ffdd4[];
extern void FUN_0029a584();
extern int FUN_002b7d60();
extern int FUN_002b7d70(int);
extern int FUN_002b7d78();
extern int FUN_002b7d80();
extern int FUN_002b7d90();
extern int FUN_002b7d98();
extern int FUN_002b7da8();
extern int FUN_002b7e40();
extern int FUN_002b7e60();
extern void FUN_0029a474();

int FUN_0029a660(void)
{
  int iVar1;
  int iVar2;
  
  DAT_0034b320 = 0;
  DAT_0034b324 = 0;
  iVar1 = FUN_002b7d98(0xb800,0x20,0x1000,0x20,0x1000);
  if (iVar1 < 0) {
    FUN_0029a584("ERROR: sceNetInit() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  iVar1 = FUN_002b7e60();
  if (iVar1 < 0) {
    FUN_0029a584("ERROR: sceNetAdhocInit() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  iVar1 = FUN_002b7d80(0x2000,0x30,&DAT_002ffcb0);
  if (iVar1 < 0) {
    FUN_0029a584("ERROR: sceNetAdhocctlInit() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  DAT_0034b320 = 0;
  DAT_0034b324 = 0;
  iVar1 = FUN_002b7d60(FUN_0029a474,0);
  if (iVar1 < 0) {
    FUN_0029a584("ERROR: sceNetAdhocctlAddHandler() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  DAT_002ffcc8 = iVar1;
  iVar1 = FUN_002b7da8(0x1000);
  if (iVar1 < 0) {
    FUN_0029a584("ERROR: sceNetAdhocMatchingInit() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  else {
    return 0;
  }

cleanup:
  iVar2 = DAT_002ffcc8;
  if (iVar2 <= 0) goto after_channel_cleanup;
  iVar2 = FUN_002b7d70(iVar2);
  if (iVar2 < 0) {
    FUN_0029a584(DAT_002ffd3c,iVar2);
  }
  DAT_002ffcc8 = -1;
after_channel_cleanup:
  iVar2 = FUN_002b7d78();
  if (iVar2 < 0) {
    FUN_0029a584(DAT_002ffd74,iVar2);
  }
  iVar2 = FUN_002b7e40();
  if (iVar2 < 0) {
    FUN_0029a584(DAT_002ffda4,iVar2);
  }
  iVar2 = FUN_002b7d90();
  if (iVar2 < 0) {
    FUN_0029a584(DAT_002ffdd4,iVar2);
  }
  return iVar1;
}
