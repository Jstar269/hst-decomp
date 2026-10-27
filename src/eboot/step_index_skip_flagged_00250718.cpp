/* HSTMATCH module=EBOOT.BIN start=0x00250718 end=0x00250788 symbol=FUN_00250718 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item {
    char pad[8];
    unsigned char flag;
};

struct Self {
    char pad[0x308];
    int count;
    char pad2[0x350 - 0x30c];
    Item **items;
};

/* Steps idx by step past items whose flag is set; leaving the range restores the start index and stops.
   The two range tests carry separate (identical) bodies: one `idx < 0 || idx >= count` test lays out differently. */
extern "C" int FUN_00250718(Self *self, int idx, int step)
{
    bool wrapped = false;
    int start = idx;
    int count = self->count;

    do {
        idx += step;
        if (idx < 0) {
            idx = start;
            wrapped = true;
        } else if (idx >= count) {
            idx = start;
            wrapped = true;
        }
    } while (self->items[idx]->flag != 0 && !wrapped);
    return idx;
}
