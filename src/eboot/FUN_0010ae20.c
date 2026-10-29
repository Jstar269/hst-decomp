/* HSTMATCH module=EBOOT.BIN start=0x0010ae20 end=0x0010aeb0 symbol=FUN_0010ae20 lang=c99 data=0x002d91c0 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d91c0-0x002d920f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_00012ad0();
extern u32 FUN_0004cad0();
extern u32 FUN_0010ad1c();

/* Text::Load: read the file, fail (0) when it is missing or empty, else mark the object loaded and parse the data. */
u32 FUN_0010ae20(u8 *text,u32 path)
{
  int data;
  u32 result;
  int size;
  
  data = FUN_0004cad0(path,&size,0x10,1);
  if (data == 0) {
    FUN_00012ad0("ERROR: Text::Load(%s): file not found.\n",path);
    result = 0;
  }
  else if (size < 1) {
    FUN_00012ad0("ERROR: Text::Load(%s): file is empty.\n",path);
    result = 0;
  }
  else {
    *text = 1;
    result = FUN_0010ad1c(text,data);
  }
  return result;
}
