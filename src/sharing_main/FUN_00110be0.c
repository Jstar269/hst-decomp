/* HSTMATCH module=hstp_trans_main.prx start=0x00110be0 end=0x00110c70 symbol=FUN_00110be0 lang=c99 data=0x0037ff94 */
/* Clone of src/eboot/FUN_0010ae20.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x0037ff94-0x0037ffe3) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_00012ad0();
extern u32 FUN_0004cd8c();
extern u32 FUN_00110adc();

/* Text::Load: read the file, fail (0) when it is missing or empty, else mark the object loaded and parse the data. */
u32 FUN_00110be0(u8 *text,u32 path)
{
  int data;
  u32 result;
  int size;
  
  data = FUN_0004cd8c(path,&size,0x10,1);
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
    result = FUN_00110adc(text,data);
  }
  return result;
}
