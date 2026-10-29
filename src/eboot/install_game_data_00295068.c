/* HSTMATCH module=EBOOT.BIN start=0x00295068 end=0x002951a0 symbol=FUN_00295068 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: pass the stored status to the variadic error formatter. */
#include "hst/types.h"
#include "hst/menu_resource.h"

extern char DAT_002cb0f8[]; /* "... sceKernelExitDeleteThread(): failed. 0x%08x" */
extern char DAT_002cb148[];
extern char DAT_002cb154[]; /* "Write OK.
" */
extern char DAT_002cb160[]; /* "... scesupGameaccInstallEnd(): failed. 0x%08x" */
extern char DAT_002cb1ac[]; /* "... scesupGameaccInstall(): failed. 0x%08x" */
extern char DAT_002cb1f4[]; /* "EBOOT.PBP" */
extern char DAT_002cb200[]; /* "... scesupGameaccInstallStart(): failed. 0x%08x" */
extern char DAT_002cb250[]; /* "... FileBundle::ReadFile(): failed. 0x%08x" */
extern char DAT_002cb298[]; /* "TRIAL.PBP" */
extern char DAT_002cb2a4[]; /* "ms0:/PSP/GAME/NPJG90047/FILE.BDL" */
extern u32 FUN_000fe448();
extern void FUN_00294684(const char *, ...);
extern int FUN_00296d60();
extern int FUN_00296ff8();
extern int FUN_002973a4();
extern int FUN_002b79b0();

/* Thread body: read the game data bundle and install it, logging each failure. */
u32 FUN_00295068(u32 arglen,MenuResource **argp)
{
  int size;
  int ret;
  MenuResource *res;
  
  res = *argp;
  size = FUN_000fe448(DAT_002cb2a4,DAT_002cb298,
                      res->unk4,0x200000);
  if (size < 0) {
    FUN_00294684(DAT_002cb250,res->result);
    res->result = -1;
  }
  else {
    ret = FUN_00296d60();
    res->result = ret;
    if (ret < 0) {
      FUN_00294684(DAT_002cb200,ret);
      goto report;
    }
    size = FUN_002973a4(DAT_002cb1f4,res->unk4,size);
    res->result = size;
    if (size < 0) {
      FUN_00294684(DAT_002cb1ac,size);
    }
    else {
      size = FUN_00296ff8();
      res->result = size;
      if (size < 0) {
        FUN_00294684(DAT_002cb160,size);
      }
    }
  }
report:
  if (res->result >= 0) {
    FUN_00294684(DAT_002cb154);
  } else {
    FUN_00294684(DAT_002cb148,res->result);
  }
  size = FUN_002b79b0(0);
  if (size < 0) {
    FUN_00294684(DAT_002cb0f8,size);
  }
  return 0;
}
