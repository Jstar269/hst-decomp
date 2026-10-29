/* HSTMATCH module=EBOOT.BIN start=0x000ff7d8 end=0x000ff98c symbol=FUN_000ff7d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: DAT_0033a6dc is an unsigned char (lbu), and iVar6 declared before iVar5 so the loop index gets s1 and the byte offset s0; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/table_reader.h"

#define ANIM_ROW_SIZE 8     /* four halfwords per row */
#define ANIM_NAME_SIZE 0x80 /* bytes per row name */

/* Table loaded from a file: row count (including the header row), the rows of four halfwords and optionally the row names. */
typedef struct AnimTable {
  int count;    /* 0x00 */
  char *rows;   /* 0x04 */
  char *names;  /* 0x08 */
} AnimTable;

extern unsigned char DAT_0033a6dc;
extern int FUN_00000a90();
extern u32 * FUN_000149a8();
extern int * FUN_000649c0();
extern int * FUN_00064a08();
extern u32 FUN_00064bf4();
extern u32 FUN_000650e0();
extern int FUN_00065104();
extern int FUN_0006517c();

/* Opens the table file and loads its rows (and the names too when DAT_0033a6dc is set). Returns 1 on success, 0 if it cannot be opened. */
u32 FUN_000ff7d8(AnimTable *table,u32 path,u32 arg3,u32 arg4)
{
  u8 opened;
  u16 value;
  int n;       /* row count; in the name loop its index */
  u32 result;
  int row;     /* row index; in the name loop the byte offset */
  int offset;  /* byte offset of the row */
  TableReader reader;
  
  FUN_000649c0(&reader);
  opened = FUN_00064bf4(&reader,path,arg3,arg4);
  if (opened == '\0') {
    table->count = 0;
    FUN_00064a08(&reader,0xffffffff);
    result = 0;
  }
  else {
    n = FUN_000650e0(&reader);
    table->count = n;
    n = FUN_00000a90((n + -1) * ANIM_ROW_SIZE);
    table->rows = (char *)n;
    n = table->count + -1;
    row = 0;
    if (0 < n) {
      offset = 0;
      do {
        value = FUN_00065104(&reader,row + 1,1);
        *(u16 *)(table->rows + offset) = value;
        value = FUN_00065104(&reader,row + 1,2);
        *(u16 *)(table->rows + offset + 2) = value;
        value = FUN_00065104(&reader,row + 1,3);
        *(u16 *)(table->rows + offset + 4) = value;
        value = FUN_00065104(&reader,row + 1,4);
        row = row + 1;
        *(u16 *)(table->rows + offset + 6) = value;
        n = table->count + -1;
        offset = offset + ANIM_ROW_SIZE;
      } while (row < n);
    }
    if (DAT_0033a6dc != '\0') {
      n = FUN_00000a90(n << 7);
      table->names = (char *)n;
      n = 0;
      if (0 < table->count + -1) {
        row = 0;
        do {
          result = FUN_0006517c(&reader,n + 1,0);
          FUN_000149a8(table->names + row,result);
          n = n + 1;
          row = row + ANIM_NAME_SIZE;
        } while (n < table->count + -1);
      }
    }
    FUN_00064a08(&reader,0xffffffff);
    result = 1;
  }
  return result;
}
