/* HSTMATCH module=EBOOT.BIN start=0x00100a1c end=0x00100b24 symbol=FUN_00100a1c lang=c99 data=0x002d8a84 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: if/else order restored (param_4 != 0 first, then the empty-string test, null case last); readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d8a84-0x002d8a9b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

#define PATH_BUF_SIZE 256
#define PREFIX_LEN 4 /* length of the compared name prefix */

extern u8 DAT_002d8a54;
extern u32 * FUN_00014788();
extern u32 * FUN_000149a8();
extern int FUN_00014a58();
extern void FUN_001006dc();

typedef struct PathOwner {
  char pad00[0x59];
  char name[1];             /* 0x59 copy of the first name */
} PathOwner;

/* Joins the directory with one or two names and passes the paths on; the first name is then kept in the owner. */
void FUN_00100a1c(PathOwner *self,char *dir,u32 name,char *name2,u32 arg)
{
  int cmp;
  u8 path[PATH_BUF_SIZE];
  u8 path2[PATH_BUF_SIZE];
  
  cmp = FUN_00014a58(name,&DAT_002d8a54,PREFIX_LEN);
  if (cmp == 0) {
    dir = "data/menu/menu_common/";
  }
  FUN_000149a8(path,dir);
  FUN_00014788(path,name);
  if (name2 != (char *)0x0) {
    if (*name2 == 0) {
      FUN_001006dc(self,path,name2,arg);
    }
    else {
      FUN_000149a8(path2,dir);
      FUN_00014788(path2,name2);
      FUN_001006dc(self,path,path2,arg);
    }
  }
  else {
    FUN_001006dc(self,path,0,arg);
  }
  FUN_000149a8(self->name,name);
}
