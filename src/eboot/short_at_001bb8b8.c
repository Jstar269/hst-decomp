/* HSTMATCH module=EBOOT.BIN start=0x001bb8b8 end=0x001bb944 symbol=FUN_001bb8b8 lang=c99 rodata=0x002c628c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/record_info.h"

extern RecordInfo *FUN_00193474(int);

/* Returns halfword number `field` (0 to 5) of the info record for id, or 0 when there is none. */
int FUN_001bb8b8(int field, int id)
{
  RecordInfo *info = FUN_00193474(id);
  if (info != 0) {
    switch (field) {
    case 0: return info->vals[0];
    case 1: return info->vals[1];
    case 2: return info->vals[2];
    case 3: return info->vals[3];
    case 4: return info->vals[4];
    case 5: return info->vals[5];
    }
  }
  return 0;
}
