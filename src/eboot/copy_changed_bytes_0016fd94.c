/* HSTMATCH module=EBOOT.BIN start=0x0016fd94 end=0x0016fe64 symbol=FUN_0016fd94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: byte pointers typed unsigned char (lbu), renamed src/dst with src declared first for register choice; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/table_page.h"

extern int FUN_0016bb88();

/* Byte tables of the global store the page tables are mirrored into. */
typedef struct TableStore {
  char pad000[0x84c];
  u8 tables[TABLE_PAGE_TABLES][TABLE_PAGE_TABLE_SIZE]; /* 0x84c */
} TableStore;

/* Copies each of the page's three byte tables into the store, writing only bytes that differ. */
void FUN_0016fd94(TablePage *self)
{
  int count;
  u8 *src;
  u8 *dst;
  
  count = FUN_0016bb88();
  dst = ((TableStore *)count)->tables[0];
  src = self->tables[0];
  count = 0;
  do {
    if (*src != *dst) {
      *dst = *src;
    }
    count = count + 1;
    src = src + 1;
    dst = dst + 1;
  } while (count < TABLE_PAGE_TABLE_SIZE);
  count = FUN_0016bb88();
  dst = ((TableStore *)count)->tables[1];
  src = self->tables[1];
  count = 0;
  do {
    if (*src != *dst) {
      *dst = *src;
    }
    count = count + 1;
    src = src + 1;
    dst = dst + 1;
  } while (count < TABLE_PAGE_TABLE_SIZE);
  count = FUN_0016bb88();
  src = self->tables[2];
  dst = ((TableStore *)count)->tables[2];
  count = 0;
  do {
    if (*src != *dst) {
      *dst = *src;
    }
    count = count + 1;
    src = src + 1;
    dst = dst + 1;
  } while (count < TABLE_PAGE_TABLE_SIZE);
}
