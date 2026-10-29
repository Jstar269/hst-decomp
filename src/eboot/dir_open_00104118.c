/* HSTMATCH module=EBOOT.BIN start=0x00104118 end=0x001041dc symbol=FUN_00104118 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: constructed object kept as a pointer and passed on (null stays null, no zero-extend through uint); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d8a5c;
extern char DAT_002d8c60[];
extern void * FUN_00000bcc();
extern u32 * FUN_000149a8();
extern int FUN_00014cfc();
extern int * FUN_000649c0();
extern u32 FUN_00064bf4();
extern u32 FUN_000650e0();
extern void FUN_001006b0();
extern void FUN_001041f4();

#define DIR_OBJ_SIZE 0x10  /* allocation size of the opened-file object */
#define PATH_SIZE 256      /* directory path buffer */
#define PATH_SEPARATOR '/' /* 0x2f */

typedef struct DirLoader {
  char pad00[0x1c];
  int *file;        /* 0x1c opened file object */
  u8 *dir_path;     /* 0x20 directory part of the path (points at the caller's buffer) */
} DirLoader;

/* Open name through a new file object; when it has content, record its directory part and continue loading, else report the failure. */
void FUN_00104118(DirLoader *self,u32 name,u32 arg)
{
  int size;
  int *mem;
  u8 path[PATH_SIZE];
  
  mem = (int *)FUN_00000bcc(DIR_OBJ_SIZE);
  if (mem != 0) {
    mem = FUN_000649c0(mem);
  }
  self->file = mem;
  FUN_00064bf4(mem,name,1,&DAT_002d8a5c);
  size = FUN_000650e0(self->file);
  if (size < 1) {
    FUN_001006b0(DAT_002d8c60,name);
  }
  else {
    FUN_000149a8(path,name);
    size = FUN_00014cfc(path,PATH_SEPARATOR);
    *(u8 *)(size + 1) = 0;
    self->dir_path = path;
    FUN_001041f4(self,name,arg);
  }
}
