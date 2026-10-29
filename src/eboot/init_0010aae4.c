/* HSTMATCH module=EBOOT.BIN start=0x0010aae4 end=0x0010abe8 symbol=FUN_0010aae4 lang=c99 data=0x002d90b4 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the function returns int (the stripped print call is declared int and its result is stored back into the checked value, which is returned: `if (r) r = print(fmt, r); return r;`), which keeps r in v0 and gives retail beqzl/move a1,v0 shape; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d90b4-0x002d90e9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/utility_params.h"

/* Game-data install block (size 0x590): five text fields copied from the source. */
typedef struct GamedataInstallParams {
  UtilityDialogCommon base; /* 0x000 */
  int unk30;                /* 0x030 set to 1 */
  char text34[0x10];        /* 0x034 */
  char text44[0x14];        /* 0x044 */
  char text58[0x80];        /* 0x058 */
  char textd8[0x80];        /* 0x0d8 */
  char text158[0x400];      /* 0x158 */
  u8 unk558;                /* 0x558 */
  char pad559[0x590 - 0x559];
} GamedataInstallParams;    /* size 0x590 */

/* Five strings and a flag byte describing the data to install. */
typedef struct GamedataInstallSource {
  const char *text[5];
  u8 flag;                  /* 0x14 */
} GamedataInstallSource;

extern u32 * FUN_000114c0();
extern char * FUN_00014b74();
extern int FUN_0010a4a8(const char *, ...);
extern void FUN_00199280();
extern int FUN_002b7c10();

/* Start the game-data install; logs the start-up result when it fails. */
int FUN_0010aae4(GamedataInstallParams *params,GamedataInstallSource *source)
{
  int result;
  
  FUN_000114c0(params,0,sizeof(GamedataInstallParams));
  params->base.size = sizeof(GamedataInstallParams);
  params->base.language = 0;
  params->base.buttonSwap = 0;
  params->base.graphicsThread = UTILITY_PRIO_GRAPHICS;
  params->base.accessThread = UTILITY_PRIO_ACCESS;
  params->base.fontThread = UTILITY_PRIO_FONT;
  params->base.soundThread = UTILITY_PRIO_SOUND;
  FUN_00199280(params);
  params->unk30 = 1;
  FUN_00014b74(params->text34,source->text[0],12);
  params->text34[12] = 0;
  FUN_00014b74(params->text44,source->text[1],sizeof(params->text44) - 1);
  params->text44[sizeof(params->text44) - 1] = 0;
  FUN_00014b74(params->text58,source->text[2],sizeof(params->text58) - 1);
  params->text58[sizeof(params->text58) - 1] = 0;
  FUN_00014b74(params->textd8,source->text[3],sizeof(params->textd8) - 1);
  params->textd8[sizeof(params->textd8) - 1] = 0;
  FUN_00014b74(params->text158,source->text[4],sizeof(params->text158) - 1);
  params->text158[sizeof(params->text158) - 1] = 0;
  params->unk558 = source->flag;
  result = FUN_002b7c10(params);
  if (result != 0) {
    result = FUN_0010a4a8("ERROR: sceUtilityGamedataInstallInitStart(): 0x%08x\n",result);
  }
  return result;
}
