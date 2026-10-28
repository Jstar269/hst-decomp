/* HSTMATCH module=EBOOT.BIN start=0x0029a660 end=0x0029a830 symbol=FUN_0029a660 lang=c99 data=0x002ffdfc */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: ordered the guarded setup calls through a shared cleanup path and typed the channel count passed to cleanup; readability pass; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x002ffdfc-0x002ffef1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002ffcb0;
extern int DAT_002ffcc8;
extern u32 DAT_0034b320;
extern u32 DAT_0034b324;
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

/* Arguments of the net library init calls (pool size / thread priority / stack size). */
enum {
  NET_POOL_SIZE = 0xb800,
  NET_THREAD_PRIO = 0x20,
  NET_THREAD_STACK = 0x1000,
  ADHOCCTL_STACK = 0x2000,
  ADHOCCTL_PRIO = 0x30,
  MATCHING_POOL_SIZE = 0x1000
};

/* Brings up the ad-hoc network stack step by step; on failure shuts down what was started and returns the error. */
int FUN_0029a660(void)
{
  int result;
  int status;
  
  DAT_0034b320 = 0;
  DAT_0034b324 = 0;
  result = FUN_002b7d98(NET_POOL_SIZE,NET_THREAD_PRIO,NET_THREAD_STACK,NET_THREAD_PRIO,NET_THREAD_STACK);
  if (result < 0) {
    FUN_0029a584("ERROR: sceNetInit() failed. ret = 0x%x\n",result);
    goto cleanup;
  }
  result = FUN_002b7e60();
  if (result < 0) {
    FUN_0029a584("ERROR: sceNetAdhocInit() failed. ret = 0x%x\n",result);
    goto cleanup;
  }
  result = FUN_002b7d80(ADHOCCTL_STACK,ADHOCCTL_PRIO,&DAT_002ffcb0);
  if (result < 0) {
    FUN_0029a584("ERROR: sceNetAdhocctlInit() failed. ret = 0x%x\n",result);
    goto cleanup;
  }
  DAT_0034b320 = 0;
  DAT_0034b324 = 0;
  result = FUN_002b7d60(FUN_0029a474,0);
  if (result < 0) {
    FUN_0029a584("ERROR: sceNetAdhocctlAddHandler() failed. ret = 0x%x\n",result);
    goto cleanup;
  }
  DAT_002ffcc8 = result; /* handler id */
  result = FUN_002b7da8(MATCHING_POOL_SIZE);
  if (result < 0) {
    FUN_0029a584("ERROR: sceNetAdhocMatchingInit() failed. ret = 0x%x\n",result);
    goto cleanup;
  }
  else {
    return 0;
  }

cleanup:
  status = DAT_002ffcc8;
  if (status <= 0) goto after_handler_cleanup;
  status = FUN_002b7d70(status);
  if (status < 0) {
    FUN_0029a584(DAT_002ffd3c,status);
  }
  DAT_002ffcc8 = -1;
after_handler_cleanup:
  status = FUN_002b7d78();
  if (status < 0) {
    FUN_0029a584(DAT_002ffd74,status);
  }
  status = FUN_002b7e40();
  if (status < 0) {
    FUN_0029a584(DAT_002ffda4,status);
  }
  status = FUN_002b7d90();
  if (status < 0) {
    FUN_0029a584(DAT_002ffdd4,status);
  }
  return result;
}
