/* HSTMATCH module=EBOOT.BIN start=0x0010a900 end=0x0010aa08 symbol=FUN_0010a900 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the function returns int (the stripped print call is declared int and its result is stored back into the checked value, which is returned: `if (r) r = print(fmt, r); return r;`), which keeps r in v0 and gives retail beqzl/move a1,v0 shape; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/utility_params.h"

extern u8 DAT_002d8fcc;  /* 8-character name copied into the block */
extern char DAT_002d8fd0[];
extern char DAT_002d8fdc[];
extern u32 * FUN_000114c0();
extern char * FUN_00014b74();
extern int FUN_0010a4a8(const char *, ...);
extern void FUN_00199280();
extern int FUN_002b7cb0();

/* Start the game-sharing dialog for a memory block; logs the first four bytes of data and any start-up error. */
int FUN_0010a900(GameSharingParams *params,char *data,u32 dataSize)
{
  int result;
  
  FUN_000114c0(params,0,sizeof(GameSharingParams));
  params->base.size = sizeof(GameSharingParams);
  params->base.language = 0;
  params->base.buttonSwap = 0;
  params->base.graphicsThread = UTILITY_PRIO_GRAPHICS;
  params->base.accessThread = UTILITY_PRIO_ACCESS;
  params->base.fontThread = UTILITY_PRIO_FONT;
  params->base.soundThread = UTILITY_PRIO_SOUND;
  FUN_00199280(params);
  params->base.graphicsThread = 0x27;
  params->base.accessThread = 0x29;
  params->base.fontThread = 0x28;
  params->base.soundThread = 0x26;
  FUN_00014b74(params->name,&DAT_002d8fcc,8);
  params->mode = GAMESHARING_MODE_SINGLE;
  params->datatype = GAMESHARING_DATA_MEMORY;
  params->data = data;
  params->datasize = dataSize;
  params->filepath = 0;
  FUN_0010a4a8(DAT_002d8fd0,(int)*data,(int)data[1],(int)data[2],(int)data[3]);
  result = FUN_002b7cb0(params);
  if (result != 0) {
    result = FUN_0010a4a8(DAT_002d8fdc,result);
  }
  return result;
}
