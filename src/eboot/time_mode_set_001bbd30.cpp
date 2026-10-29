/* HSTMATCH module=EBOOT.BIN start=0x001bbd30 end=0x001bbe8c symbol=FUN_001bbd30 lang=c++ */
/* Hand-written reconstruction from the disassembly (starting from the ds10 near miss in wip/time_mode_set_001bbd30.cpp); exact match verified; names and types await human review. */
/* Matching idioms: a small `switch (mode)` with the cases written 4, 5, 0 (retail tests 0, 5, 4 with `beql`/delay-slot stores; the if/else chain gave 71 words off); the local `Date` is 16 bytes (six halfwords + a word, the layout of a PSP RTC datetime that the callee fills; month/day/hour/minute value ranges agree) so it sits at sp+16, a 10-byte struct would sit at sp+20; `> 1` gives `sltiu at`. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern unsigned DAT_00310fc8;
struct Date {
    u16 year;
    s16 month;
    s16 day;
    s16 hour;
    s16 minute;
    s16 second;
    unsigned microsecond;
};
struct Clock {
    u8 mode;
    u8 pad[3];
    Date date;
};
extern "C" void FUN_002b7d28(Date *p);

static inline int Rand() {
    DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
    return (DAT_00310fc8 >> 16) & 0x7fff;
}

extern "C" void FUN_001bbd30(Clock *c, int mode, int flag) {
    switch (mode) {
    case 4:
        if ((unsigned)(c->mode - 4) > 1) {
            c->mode = 4;
            if (flag != 0) {
                Date d;
                FUN_002b7d28(&d);
                c->date.year = d.year;
                c->date.month = Rand() % 12 + 1;
                c->date.day = Rand() % 28 + 1;
                c->date.hour = Rand() % 24;
                c->date.minute = Rand() % 60;
            } else {
                FUN_002b7d28(&c->date);
            }
        }
        break;
    case 5:
        c->mode = 5;
        break;
    case 0:
        c->mode = 0;
        break;
    }
}
