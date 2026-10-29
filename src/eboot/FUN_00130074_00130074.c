/* HSTMATCH module=EBOOT.BIN start=0x00130074 end=0x00130174 symbol=FUN_00130074 lang=c99 data=0x002db068 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: ordered result tests; readability pass; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002db068-0x002db092) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern char DAT_002daf84[];
extern char DAT_002daf90[];
extern char DAT_002db01c[];
extern char * FUN_00014d64();

/* Keyword ids returned by FUN_00130074; only the ones whose literal is in this file are named. */
enum {
  KEYWORD_NONE = 0,
  KEYWORD_SERVICE = 1,
  KEYWORD_REPLAYSTART = 2,
  KEYWORD_BOUND_FIRST = 4,
  KEYWORD_FINISHCAM = 6
};

/* Maps a keyword string (substring match) to its id; null or unmatched gives 0. */
u32 FUN_00130074(u32 unused,int name)
{
  int result = KEYWORD_NONE;
  if (name == 0) result = KEYWORD_NONE;
  else if (FUN_00014d64(name,"SERVICE") != 0) result = KEYWORD_SERVICE;
  else if (FUN_00014d64(name,"REPLAYSTART") != 0) result = KEYWORD_REPLAYSTART;
  else if (FUN_00014d64(name,DAT_002daf84) != 0) result = 3;
  else if (FUN_00014d64(name,"BOUND_FIRST") != 0) result = KEYWORD_BOUND_FIRST;
  else if (FUN_00014d64(name,DAT_002daf90) != 0) result = 5;
  else if (FUN_00014d64(name,"FINISHCAM") != 0) result = KEYWORD_FINISHCAM;
  else if (FUN_00014d64(name,DAT_002db01c) != 0) result = 7;
  return result;
}
