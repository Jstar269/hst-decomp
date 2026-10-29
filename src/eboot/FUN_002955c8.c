/* HSTMATCH module=EBOOT.BIN start=0x002955c8 end=0x002956e0 symbol=FUN_002955c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_002955c8.c) corrected by hand: typed the object and display-call arguments, and expressed the bounds guard as !(index < count); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c0e18;
extern u8 DAT_002c0e1c;
extern u8 DAT_002c0e20;
extern u8 DAT_002cacf0;
extern void *DAT_003415ac;
extern void FUN_000143b0();
extern char * FUN_00014d64();
extern void FUN_00115088(void *, int, void *, int, int);
extern u8 * FUN_0018c9f4();

/* Owner of the text buffer and the index of the entry whose name is shown. */
typedef struct TextOwner {
  unsigned char pad00[0x1a8];
  unsigned char text[0xeb44 - 0x1a8]; /* 0x1a8 text composed for display */
  int entry;                           /* 0xeb44 index into the name list */
} TextOwner;

/* Table of entry names (pointer array and its length). */
typedef struct NameTable {
  unsigned char pad00[0x78];
  u8 **names;                          /* 0x78 */
  int count;                           /* 0x7c */
} NameTable;

/* Count record; its word at 0x08 is compared with 0xb. */
typedef struct CountRec {
  unsigned char pad00[8];
  int count;                           /* 0x08 */
} CountRec;

/* Record returned by FUN_0018c9f4 for table 0x13. */
typedef struct TableRec {
  int pad00;
  int enabled;                         /* 0x04 */
  CountRec *counts;                    /* 0x08 */
  NameTable *table;                    /* 0x0c */
} TableRec;

/* Show `text` in slot `slot`; when it contains the marker, compose it with the current entry's name first. */
void FUN_002955c8(TextOwner *owner,int slot,char *text)
{
  int found;
  int entry;
  TableRec *rec;
  u8 *name;
  
  found = (int)(FUN_00014d64(text,&DAT_002cacf0));
  if (found == 0) {
    FUN_00115088(DAT_003415ac,slot,text,0,0);
  }
  else {
    rec = (TableRec *)(FUN_0018c9f4(0x13));
    entry = owner->entry;
    if (rec->enabled == 0) {
      name = &DAT_002c0e20;
    }
    else if (rec->counts->count < 0xb) {
      name = &DAT_002c0e1c;
    }
    else if ((entry < 0) || !(entry < rec->table->count)) {
      name = &DAT_002c0e18;
    }
    else {
      name = rec->table->names[entry];
    }
    FUN_000143b0(owner->text,text,name);
    FUN_00115088(DAT_003415ac,slot,owner->text,0,0);
  }
}
