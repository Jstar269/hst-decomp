/* HSTMATCH module=EBOOT.BIN start=0x0010061c end=0x001006b0 symbol=FUN_0010061c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: the result is one variable `value = r; if (r == 0 || count <= 0) value = 0;` stored once (the if/else-with-two-stores form threads the jumps differently); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00014788(void *param_1, int *param_2);
extern void FUN_000149a8(void *param_1, u32 *param_2);
extern u32 FUN_0004cad0(char *param_1, int *param_2, int param_3, int param_4);
extern void FUN_000511c4(void *param_1, u32 *param_2, u32 param_3);
extern void FUN_00051398(float param_1, void *param_2);
extern int DAT_002d8a50;

#define PATH_BUF_WORDS 64

typedef struct FileOwner {
  char pad00[0x50];
  u32 fileData;             /* 0x50 loaded file, 0 when missing or empty */
} FileOwner;

/* Sets up the base object, then loads the file named `name` plus a suffix into fileData. */
void FUN_0010061c(FileOwner *self,u32 *name,u32 arg)
{
  u32 data;
  u32 path [PATH_BUF_WORDS];
  int size;
  
  FUN_000511c4(self,name,arg);
  FUN_00051398(100000.0f,self);
  FUN_000149a8(path,name);
  FUN_00014788(path,&DAT_002d8a50);
  data = FUN_0004cad0((char *)path,&size,0x10,1);
  {
    u32 value = data;
    if (data == 0 || size <= 0) value = 0;
    self->fileData = value;
  }
}
