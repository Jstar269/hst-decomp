/* HSTMATCH module=EBOOT.BIN start=0x0001b788 end=0x0001b880 symbol=FUN_0001b788 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: masked rotate-left-3 hash, real wrap-around scan. */
extern "C" int FUN_00014934(char *name, void *record);

struct Entry
{
    unsigned int id;
    void **data;
};

struct Table
{
    Entry *entries;
    unsigned int count;
};

extern "C" void *FUN_0001b788(Table *table, char *name)
{
    Entry *e;
    char *p = name;
    unsigned int h = 0;
    unsigned int rot;
    unsigned int home;
    unsigned int i;

    for (; *p != 0; p++) {
        rot = ((h << 3) & 0xfffffff8u) | ((h >> 29) & 7u);
        h = rot ^ (*p << 7);
    }
    i = h % table->count;
    home = i;
    for (;;) {
        e = &table->entries[i];
        if (e->id == home) {
            if (FUN_00014934(name, *e->data) == 0)
                return e->data;
        } else if (e->id == 0xffffffff) {
            return 0;
        }
        i++;
        while ((int)i >= (int)table->count)
            i = 0;
    }
}

// NEAR 21/62 words (lane dsn2, DeepSeek V4.1 Flash (Freebuff)). What matches: the whole masked rotate-left-3
// hash loop and the slot probe from +0x70 are byte-exact; `FUN_00014934(name, *e->data)` and the -1u end
// marker are right, and all registers (s3=name, s4=table, s1=home, s2=i, s0=entry) match retail.
// What is left: the wrap-around block. Retail has ONE `while (i >= count) i = 0;` whose check sits at the
// loop bottom (0x1b848), entered by `b 0x1b848` right after `mfri s1/move s2,s1` and by the ++i of the
// catch-all arm, with `b 0x1b848; move s2,zero` for the reset. So far tried, all worse or equal:
// (a) single while at the TOP of the loop body -> the check is laid out first, entry falls through (34 words);
// (b) top+bottom while -> 44 words; (c) `if (i >= count) i = 0;` at the top -> 35 words;
// (d) no top check, single while at the BOTTOM -> best: exact layout, 21 words (this file).
// Next step for (d): make the ENTRY jump to the bottom check: retail's `b 0x1b848` after computing h%count
// means the source tested i against count before the first probe as well - try `for (i = h % count; i < count; )`
// or a do/while with the test at the bottom and `if (i >= count) break;` at the top.
// near miss from lane dsn2 (unreviewed)
