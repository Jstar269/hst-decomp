/* HSTMATCH module=EBOOT.BIN start=0x00152948 end=0x00152a58 symbol=FUN_00152948 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed struct instead of pointer arithmetic, the mode is an unsigned int (masked ushort result) tested by `switch (m) { case 2: ...; case 0: ... }` (case 2 body first), goto removed; readability pass; exact match verified; names and types await human review. */
#include "hst/stream_cursor.h"

/* Record read from a stream: five header values, then two flag bytes derived from the mode value. */
struct StreamRecord {
    const void *vtable; /* 0x00 */
    unsigned char unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    int unk14;          /* signed value read from the stream, made positive; 0 and 1 are swapped */
    unsigned int unk18;
    unsigned char unk1c, unk1d; /* flags set from the mode value */
};
extern "C" {
extern char DAT_0030840c;
extern char DAT_00308bb0;
extern unsigned short FUN_0014f050(StreamCursor *);
extern int FUN_00159ee0(StreamCursor *);
}

extern "C" StreamRecord *FUN_00152948(StreamRecord *self, StreamCursor *stream)
{
    unsigned int mode;
    self->vtable = &DAT_0030840c;
    self->unk04 = 0;
    self->vtable = &DAT_00308bb0;
    self->unk08 = FUN_0014f050(stream);
    self->unk0c = 0;
    self->unk10 = FUN_0014f050(stream);
    mode = FUN_0014f050(stream);
    self->unk14 = (short)FUN_00159ee0(stream);
    self->unk18 = FUN_0014f050(stream);
    self->unk1c = 0;
    self->unk1d = 0;
    switch (mode) {
    case 2:
        self->unk1c = 1;
        self->unk1d = 1;
        break;
    case 0:
        self->unk1d = 1;
        break;
    }
    if (self->unk14 < 0) {
        self->unk14 = -self->unk14;
    }
    int v = self->unk14;
    if (v == 0) {
        self->unk14 = 1;
    } else if (v == 1) {
        self->unk14 = 0;
    }
    return self;
}
