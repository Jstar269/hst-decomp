/* HSTMATCH module=hstp_trans_main.prx start=0x002a98e4 end=0x002a9ab4 symbol=FUN_002a98e4 lang=c99 data=0x003a8cd0 */
/* Clone of src/eboot/setup_services_0029a660.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x003a8cd0-0x003a8dc5) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: ordered the guarded setup calls through a shared cleanup path and typed the channel count passed to cleanup; exact match verified; names and types await human review. */
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

extern undefined DAT_003a8b84;
extern int DAT_003a8b9c;
extern undefined4 DAT_003f4660;
extern undefined4 DAT_003f4664;
extern char DAT_003a8c10[];
extern char DAT_003a8c48[];
extern char DAT_003a8c78[];
extern char DAT_003a8ca8[];
extern void FUN_002a9808();
extern int FUN_002c7ae8();
extern int FUN_002c7af8(int);
extern int FUN_002c7b00();
extern int FUN_002c7b08();
extern int FUN_002c7b18();
extern int FUN_002c7b20();
extern int FUN_002c7b30();
extern int FUN_002c7bc8();
extern int FUN_002c7be8();
extern void FUN_002a96f8();

int FUN_002a98e4(void)
{
  int iVar1;
  int iVar2;
  
  DAT_003f4660 = 0;
  DAT_003f4664 = 0;
  iVar1 = FUN_002c7b20(0xb800,0x20,0x1000,0x20,0x1000);
  if (iVar1 < 0) {
    FUN_002a9808("ERROR: sceNetInit() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  iVar1 = FUN_002c7be8();
  if (iVar1 < 0) {
    FUN_002a9808("ERROR: sceNetAdhocInit() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  iVar1 = FUN_002c7b08(0x2000,0x30,&DAT_003a8b84);
  if (iVar1 < 0) {
    FUN_002a9808("ERROR: sceNetAdhocctlInit() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  DAT_003f4660 = 0;
  DAT_003f4664 = 0;
  iVar1 = FUN_002c7ae8(FUN_002a96f8,0);
  if (iVar1 < 0) {
    FUN_002a9808("ERROR: sceNetAdhocctlAddHandler() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  DAT_003a8b9c = iVar1;
  iVar1 = FUN_002c7b30(0x1000);
  if (iVar1 < 0) {
    FUN_002a9808("ERROR: sceNetAdhocMatchingInit() failed. ret = 0x%x\n",iVar1);
    goto cleanup;
  }
  else {
    return 0;
  }

cleanup:
  iVar2 = DAT_003a8b9c;
  if (iVar2 <= 0) goto after_channel_cleanup;
  iVar2 = FUN_002c7af8(iVar2);
  if (iVar2 < 0) {
    FUN_002a9808(DAT_003a8c10,iVar2);
  }
  DAT_003a8b9c = -1;
after_channel_cleanup:
  iVar2 = FUN_002c7b00();
  if (iVar2 < 0) {
    FUN_002a9808(DAT_003a8c48,iVar2);
  }
  iVar2 = FUN_002c7bc8();
  if (iVar2 < 0) {
    FUN_002a9808(DAT_003a8c78,iVar2);
  }
  iVar2 = FUN_002c7b18();
  if (iVar2 < 0) {
    FUN_002a9808(DAT_003a8ca8,iVar2);
  }
  return iVar1;
}
