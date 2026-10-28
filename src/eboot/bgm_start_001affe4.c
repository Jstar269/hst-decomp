/* HSTMATCH module=EBOOT.BIN start=0x001affe4 end=0x001b0130 symbol=FUN_001affe4 lang=c99 data=0x002e9598 */
/* Hand-written reconstruction from the disassembly; exact match verified (83/83 words).
   Court-sound/BGM start: tears down the three sub-entries at 0x79c+0xe/0x5c/0x70, allocates
   the 0x100000-byte buffer, loads 0x002e9598 into the 0x30ebf4 sound bank, starts the three
   entries (only the first gets the optional BGM name from DAT_002c5a64 when param_3 bit 0 is
   set), records param_2 and frees the buffer. Names and types await human review. Data: its string literals (1 strings, 0x002e9598-0x002e95b8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/slot_table.h"

extern char DAT_0030ab9c[];
extern char DAT_0030ebf4[];
extern char *DAT_002c5a64;
extern int FUN_00010184(int, int);
extern void FUN_0001bfb4(char *, int, int);
extern int FUN_0001ca58(char *, char *, int);
extern void FUN_001b04d0(SlotTable *, int);
extern void FUN_001b0ef8(SlotTable *, int, int, int, char *);
extern void FUN_0001cb88(char *);
extern int FUN_0001cbfc(void);
extern int FUN_0001cc54(void);
extern void FUN_000104e0(int);

/* Offsets of the three sound entries within the slot table, relative to the court sound index. */
enum { BGM_ENTRY_A = 0xe, BGM_ENTRY_B = 0x5c, BGM_ENTRY_C = 0x70 };
#define SOUND_BUF_SIZE 0x100000
#define BGM_FLAG_NAMED 1 /* start the first entry with the BGM name */

void FUN_001affe4(SlotTable *self, int court, unsigned flags)
{
    int buf;
    char *bgm;
    int bank_ptr;
    int bank_size;

    if (self->court_sound >= 0) {
        FUN_001b04d0(self, self->court_sound + BGM_ENTRY_A);
        FUN_001b04d0(self, self->court_sound + BGM_ENTRY_B);
        FUN_001b04d0(self, self->court_sound + BGM_ENTRY_C);
        self->court_sound = -1;
    }
    buf = FUN_00010184(0x40, SOUND_BUF_SIZE);
    FUN_0001bfb4(DAT_0030ab9c, buf, SOUND_BUF_SIZE);
    FUN_0001ca58(DAT_0030ebf4, "game/900_sound/020_court%02d.xb", court + 1);
    bgm = 0;
    if ((flags & BGM_FLAG_NAMED) != 0)
        bgm = DAT_002c5a64;
    FUN_001b0ef8(self, court + BGM_ENTRY_A, 0, 0, bgm);
    FUN_001b0ef8(self, court + BGM_ENTRY_B, 0, 0, 0);
    self->unk7c0 = court + BGM_ENTRY_C;
    FUN_001b0ef8(self, court + BGM_ENTRY_C, 0, 0, 0);
    self->court_sound = court;
    FUN_0001cb88(DAT_0030ebf4);
    bank_ptr = FUN_0001cbfc();
    bank_size = FUN_0001cc54();
    FUN_0001bfb4(DAT_0030ab9c, bank_ptr, bank_size);
    FUN_000104e0(buf);
}
