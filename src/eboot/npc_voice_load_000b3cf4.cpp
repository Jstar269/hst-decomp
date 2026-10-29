/* HSTMATCH module=EBOOT.BIN start=0x000b3cf4 end=0x000b3f20 symbol=FUN_000b3cf4 lang=c++ data=0x002d4780 */
/* LoadNpcVoicePack: data/chara/parameter/npc_voicepack.csv; see docs/DATA-TABLES.md Data: its string literals (2 strings, 0x002d4780-0x002d47aa) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/npc_voice.h"

struct Tag {};
typedef NpcVoiceRow Name18;
typedef NpcVoiceVec Vec;

struct CsvTable;

extern "C" void FUN_0008b1d8(void *, int, Tag);
extern "C" {
void FUN_000649c0(void *);
void FUN_0008c230(void *);
int FUN_000651b8(CsvTable *, const char *, int, int, const char *);
int FUN_000650e0(CsvTable *);
int FUN_0006517c(CsvTable *, int, int);
int FUN_00014d64(const char *, const char *);
void FUN_000114c0(void *, int, int);
int FUN_00065104(CsvTable *, unsigned int, unsigned int);
void FUN_000b4360(Vec *, Name18 *, Tag);
void FUN_00066338(void *, int);
void FUN_00064a08(void *, int);
extern int DAT_003070bc;
extern char DAT_002d47ac[];
}

struct Str {
  int w[4];
  Str() { FUN_0008c230(this); }
  ~Str() { FUN_00066338(this, 0); }
};

struct Base16 {
  int w[4];
  Base16() {
    FUN_000649c0(this);
    *(char **)this = (char *)&DAT_003070bc;
  }
  ~Base16() { FUN_00064a08(this, 0); }
};

struct CsvTable : Base16 {
  Str a;
  Str b;
  ~CsvTable() { *(char **)this = (char *)&DAT_003070bc; }
};

/* Load the NPC voice pack csv: each record is a label row plus 6 rows of 3 values, appended to the vector of its kind. */
extern "C" void FUN_000b3cf4(Vec *voices)
{
  int row;
  unsigned int group;
  unsigned int col;
  char *out;
  unsigned int i;
  int rows;
  int kind;
  Name18 *dst;

  for (i = 0; i < 2; i++) {
    FUN_0008b1d8(&voices[i], voices[i].count, Tag());
  }
  CsvTable table;
  Name18 name;
  if (FUN_000651b8(&table, "data/chara/parameter/npc_voicepack.csv", 0, 0, ",") != 0) {
    rows = FUN_000650e0(&table);
    row = 0;
    while (row < rows) {
      i = FUN_0006517c(&table, row, 0);
      kind = !FUN_00014d64((const char *)i, DAT_002d47ac);
      row = row + 1;
      FUN_000114c0(&name, 0, NPC_VOICE_ROW_SIZE);
      group = 0;
      out = name.c;
      do {
        for (col = 0; col < NPC_VOICE_COLS; col++) {
          out[col] = FUN_00065104(&table, row, col);
        }
        row = row + 1;
        out = out + NPC_VOICE_COLS;
      } while (++group < NPC_VOICE_GROUPS);
      if (voices[kind].count < voices[kind].cap) {
        dst = voices[kind].base + voices[kind].count;
        if (dst != 0) {
          *dst = name;
        }
        voices[kind].count = voices[kind].count + 1;
      } else {
        FUN_000b4360(&voices[kind], &name, Tag());
      }
    }
  }
}
