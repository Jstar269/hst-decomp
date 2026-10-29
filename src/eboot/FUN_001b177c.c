/* HSTMATCH module=EBOOT.BIN start=0x001b177c end=0x001b1810 symbol=FUN_001b177c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define EXT_BUFFER_SIZE 16
#define PATH_EXT_SEPARATOR 0x2e /* '.' */

extern u8 DAT_002e97fc;
extern u8 DAT_002e9804;
extern u8 DAT_002e9808;
extern u32 * FUN_00014788();
extern u32 * FUN_000149a8();
extern char * FUN_00014b74();
extern int FUN_00014cfc();
extern char * FUN_00014d64();

/* Cut the text from the last '.' off `path`, append the string DAT_002e97fc and then the cut-off part back
   (so DAT_002e97fc ends up before the extension); then replace a match of DAT_002e9804 by DAT_002e9808 (3 characters). */
void FUN_001b177c(u32 path)
{
  u8 *dot;
  int match;
  u8 ext[EXT_BUFFER_SIZE];
  
  dot = (u8 *)FUN_00014cfc(path,PATH_EXT_SEPARATOR);
  if (dot != (u8 *)0x0) {
    FUN_000149a8(ext,dot);
    *dot = 0;
    FUN_00014788(path,&DAT_002e97fc);
    FUN_00014788(path,ext);
  }
  match = (int)(FUN_00014d64(path,&DAT_002e9804));
  if (match != 0) {
    FUN_00014b74(match,&DAT_002e9808,3);
  }
}
