/* HSTMATCH module=EBOOT.BIN start=0x0015474c end=0x001547dc symbol=FUN_0015474c lang=c99 data=0x002dc908 */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: typed struct params, FUN_002879e0 prototyped (int,int,float,int,int,int) for the argument-setup order, (double)cmd->volume variadic argument for the extendsfdf2 call; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc908-0x002dc925) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

typedef struct BgmVolumeCmd {
  char pad00[8];
  int track;    /* 0x08 */
  float volume; /* 0x0c */
  int fade;     /* 0x10 */
  int arg3;     /* 0x14 */
} BgmVolumeCmd;

typedef struct BgmPlayer {
  char pad00[0xc];
  int bgm; /* 0x0c */
} BgmPlayer;

extern unsigned char DAT_003402f0; /* script trace flag */
extern void FUN_0014d044(void *p);
extern void FUN_0014fd94(const char *fmt, ...);
extern void FUN_002879e0(int bgm, int track, float volume, int fade, int arg3, int d);

/* Script command "BgmVolume": trace it and set the volume of the context's BGM. */
int FUN_0015474c(BgmVolumeCmd *cmd, BgmPlayer *ctx)
{
    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("BgmVolume [%d %.2f, %d(%d)]\n", cmd->track, (double)cmd->volume, cmd->fade, cmd->arg3);
    }
    if (ctx->bgm != 0) {
        FUN_002879e0(ctx->bgm, cmd->track, cmd->volume, cmd->fade, cmd->arg3, 0);
    }
    return 0;
}
