/* HSTMATCH module=EBOOT.BIN start=0x001d9cfc end=0x001d9eb0 symbol=FUN_001d9cfc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034a7ec;
extern int DAT_00341ccc;
extern int FUN_0027ee08(int);
extern int FUN_0027ee10(int, int);
extern unsigned FUN_001c02e0(int, int, int);

/* Collect modes (param 2). */
enum {
    COLLECT_ALL = 0,       /* every entry */
    COLLECT_MATCHING = 1,  /* entries whose FUN_001c02e0 lookup result is 4 or 5 */
    COLLECT_FLAGGED = 2    /* entries with the flag byte set */
};

/* Table entry: a flag byte and a halfword id. */
struct Entry {
    char pad[0x25];
    unsigned char flag;  /* 0x25 */
    short id;            /* 0x26 */
};

/* Writes the ids of the entries selected by mode into out and returns how many were written. */
int FUN_001d9cfc(int *out, int mode)
{
    int count;
    int i;
    int size;
    struct Entry *e;

    count = 0;
    if (mode == COLLECT_MATCHING) {
        i = 0;
        size = FUN_0027ee08(DAT_0034a7ec);
        if (size >= 1) {
            do {
                e = (struct Entry *)FUN_0027ee10(DAT_0034a7ec, i);
                if (e != 0) {
                    if (((FUN_001c02e0(DAT_00341ccc, 5, e->id) & 0xff) - 4) < 2) {
                        count++;
                        *out = e->id;
                        out++;
                    }
                }
                i++;
                size = FUN_0027ee08(DAT_0034a7ec);
            } while (i < size);
        }
    } else if (mode == COLLECT_ALL) {
        i = 0;
        size = FUN_0027ee08(DAT_0034a7ec);
        if (size > 0) {
            do {
                e = (struct Entry *)FUN_0027ee10(DAT_0034a7ec, i);
                if (e != 0) {
                    count++;
                    *out = e->id;
                    out++;
                }
                i++;
                size = FUN_0027ee08(DAT_0034a7ec);
            } while (i < size);
        }
    } else if (mode == COLLECT_FLAGGED) {
        i = 0;
        size = FUN_0027ee08(DAT_0034a7ec);
        if (size > 0) {
            do {
                e = (struct Entry *)FUN_0027ee10(DAT_0034a7ec, i);
                if (e != 0 && e->flag != 0) {
                    count++;
                    *out = e->id;
                    out++;
                }
                i++;
                size = FUN_0027ee08(DAT_0034a7ec);
            } while (i < size);
        }
    }
    return count;
}
