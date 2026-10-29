/* HSTMATCH module=EBOOT.BIN start=0x00295208 end=0x00295298 symbol=FUN_00295208 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag t0, refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_00295208.c) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/menu_resource.h"

extern char DAT_002cad8c[]; /* "Start Thread [0x%08x]" */
extern char DAT_002cada4[]; /* "MenuResource::CreateThread(): sceKernelStartThread(): failed. 0x%08x" */
extern char DAT_002cadec[]; /* "MenuResource::CreateThread(): sceKernelCreateThread(): failed. 0x%08x" */
extern char DAT_002cae34[]; /* "supGameacc_func" */
extern void FUN_00294684();
extern int FUN_002b78d8();
extern int FUN_002b7920();

#define MENU_THREAD_PRIORITY 0x29
#define MENU_THREAD_STACK_SIZE 0x4000

/* Create and start the resource's worker thread; the thread receives a pointer to the resource. */
void FUN_00295208(MenuResource *res,u32 entry)
{
  int ret;
  MenuResource *start_arg;
  u32 thread;
  
  ret = FUN_002b7920(DAT_002cae34,entry,MENU_THREAD_PRIORITY,MENU_THREAD_STACK_SIZE,0,0);
  res->thread = ret;
  if (ret < 0) {
    FUN_00294684(DAT_002cadec,ret);
  }
  start_arg = res;
  ret = FUN_002b78d8(res->thread,4,&start_arg);
  if (ret < 0) {
    FUN_00294684(DAT_002cada4,res->thread);
    thread = res->thread;
  }
  else {
    thread = res->thread;
  }
  FUN_00294684(DAT_002cad8c,thread);
}
