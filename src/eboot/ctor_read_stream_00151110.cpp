/* HSTMATCH module=EBOOT.BIN start=0x00151110 end=0x00151204 symbol=FUN_00151110 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the flag readers 0x159ef4 return int (no andi; `!f()` gives sltu/xori), and the nested range test is `if (v < 0) {..; flag = 1;} else { if (v == 0) .. = 1; else if (v == 1) .. = 0; flag = 0; }` (one shared flag store); readability pass; exact match verified; names and types await human review. */
#include "hst/script_node.h"
#include "hst/stream_cursor.h"

/* Command read from a stream: five values, the last stored as a magnitude plus a sign flag. */
struct StreamCmd {
    ScriptNode base;
    int unk08;
    int unk0c;
    int unk10;
    int value;             /* 0x14 magnitude of the read value; 0 and 1 are swapped */
    unsigned char negated; /* 0x18 the read value was negative */
    unsigned char unk19;
    unsigned char unk1a;
};
extern "C" {
extern char DAT_0030840c;
extern char DAT_00308db8;
extern unsigned short FUN_0014f050(StreamCursor *);
extern short FUN_00159ee0(StreamCursor *);
extern int FUN_00159ef4(StreamCursor *);
}

extern "C" StreamCmd *FUN_00151110(StreamCmd *self, StreamCursor *stream)
{
    self->base.vtable = &DAT_0030840c;
    self->base.unk04 = 0;
    self->base.vtable = &DAT_00308db8;
    self->unk08 = FUN_00159ee0(stream);
    self->unk0c = FUN_00159ee0(stream);
    self->unk10 = FUN_0014f050(stream);
    self->value = FUN_00159ee0(stream);
    self->unk19 = FUN_00159ef4(stream) != 0;
    self->unk1a = !FUN_00159ef4(stream);
    int v = self->value;
    if (v < 0) {
        self->value = -v;
        self->negated = 1;
    } else {
        if (v == 0)
            self->value = 1;
        else if (v == 1)
            self->value = 0;
        self->negated = 0;
    }
    return self;
}
