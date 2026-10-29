/* HSTMATCH module=EBOOT.BIN start=0x0016bb98 end=0x0016bc30 symbol=FUN_0016bb98 lang=c99 data=0x002e04c8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e04c8-0x002e04cc) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

#define ROW_TABLE_NPC 1   /* index of the table used for names that start with "Npc" */
#define ROW_TABLE_BASE 0

typedef struct Row {          /* size 0x22c */
  char pad00[0x14];
  signed char unk14;          /* 0x14 */
  char pad15[0x22c - 0x15];
} Row;

typedef struct RowTable {     /* size 0x18 */
  Row *rows;                  /* 0x00 */
  char pad04[0x14];
} RowTable;

typedef struct RowTables {
  RowTable tables[2];         /* base table, then the Npc table */
} RowTables;

extern RowTables *DAT_00341508;
int FUN_00014d64(char *, char *);
int FUN_00165004(void *, char *);

/* Looks up a row by name in the Npc table (names starting with "Npc") or the base table and returns its byte at +0x14. */
int FUN_0016bb98(int unused, char *name)
{
  int idx;
  int kind;
  if (FUN_00014d64(name, "Npc") != 0) {
    kind = ROW_TABLE_NPC;
    idx = FUN_00165004(&DAT_00341508->tables[ROW_TABLE_NPC], name);
  } else {
    kind = ROW_TABLE_BASE;
    idx = FUN_00165004(DAT_00341508, name);
  }
  return ((Row *)((char *)DAT_00341508->tables[kind].rows + idx * sizeof(Row)))->unk14;
}
