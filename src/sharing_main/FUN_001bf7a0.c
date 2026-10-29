/* HSTMATCH module=hstp_trans_main.prx start=0x001bf7a0 end=0x001bf834 symbol=FUN_001bf7a0 lang=c99 */
/* Clone of src/eboot/FUN_001b177c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

#define EXT_BUFFER_SIZE 16
#define PATH_EXT_SEPARATOR 0x2e /* '.' */

extern u8 DAT_00391314;
extern u8 DAT_0039131c;
extern u8 DAT_00391320;
extern u32 * FUN_00014788();
extern u32 * FUN_000149a8();
extern char * FUN_00014b74();
extern int FUN_00014cfc();
extern char * FUN_00014d64();

/* Cut the text from the last '.' off `path`, append the string DAT_00391314 and then the cut-off part back
   (so DAT_00391314 ends up before the extension); then replace a match of DAT_0039131c by DAT_00391320 (3 characters). */
void FUN_001bf7a0(u32 path)
{
  u8 *dot;
  int match;
  u8 ext[EXT_BUFFER_SIZE];
  
  dot = (u8 *)FUN_00014cfc(path,PATH_EXT_SEPARATOR);
  if (dot != (u8 *)0x0) {
    FUN_000149a8(ext,dot);
    *dot = 0;
    FUN_00014788(path,&DAT_00391314);
    FUN_00014788(path,ext);
  }
  match = (int)(FUN_00014d64(path,&DAT_0039131c));
  if (match != 0) {
    FUN_00014b74(match,&DAT_00391320,3);
  }
}
