/* HSTMATCH module=EBOOT.BIN start=0x000b9450 end=0x000b94b8 symbol=FUN_000b9450 lang=c99 data=0x002d4a40 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the sign test written as >= 0 (bltzl); readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d4a40-0x002d4a5a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

#define PATH_BUF_SIZE 256
#define CAMERA_FILE_SIZE 0x120 /* bytes written to the file */

extern u8 DAT_002d4848;
extern void FUN_000143b0();
extern int FUN_0004ccb8();
extern u32 FUN_0004cfd0();
extern void FUN_0004d028();

/* Write the camera data block to the numbered camera file when it can be opened. */
void FUN_000b9450(u32 unused,u32 number)
{
  int file;
  u8 path [PATH_BUF_SIZE];
  
  FUN_000143b0(path,"data/camera/play_%02d.dat",number);
  file = FUN_0004ccb8(path,1,1);
  if (file >= 0) {
    FUN_0004d028(file,&DAT_002d4848,CAMERA_FILE_SIZE);
    FUN_0004cfd0(file);
  }
}
