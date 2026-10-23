/* HSTMATCH module=EBOOT.BIN start=0x001d9cfc end=0x001d9eb0 symbol=FUN_001d9cfc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034a7ec;
extern int DAT_00341ccc;
extern int FUN_0027ee08(int);
extern int FUN_0027ee10(int, int);
extern unsigned FUN_001c02e0(int, int, int);

struct Entry {
    char pad[0x25];
    unsigned char f25;
    short f26;
};

int FUN_001d9cfc(int *param_1, int param_2)
{
    int n;
    int i;
    int lim;
    struct Entry *e;

    n = 0;
    if (param_2 == 1) {
        i = 0;
        lim = FUN_0027ee08(DAT_0034a7ec);
        if (lim >= 1) {
            do {
                e = (struct Entry *)FUN_0027ee10(DAT_0034a7ec, i);
                if (e != 0) {
                    if (((FUN_001c02e0(DAT_00341ccc, 5, e->f26) & 0xff) - 4) < 2) {
                        n++;
                        *param_1 = e->f26;
                        param_1++;
                    }
                }
                i++;
                lim = FUN_0027ee08(DAT_0034a7ec);
            } while (i < lim);
        }
    } else if (param_2 == 0) {
        i = 0;
        lim = FUN_0027ee08(DAT_0034a7ec);
        if (lim > 0) {
            do {
                e = (struct Entry *)FUN_0027ee10(DAT_0034a7ec, i);
                if (e != 0) {
                    n++;
                    *param_1 = e->f26;
                    param_1++;
                }
                i++;
                lim = FUN_0027ee08(DAT_0034a7ec);
            } while (i < lim);
        }
    } else if (param_2 == 2) {
        i = 0;
        lim = FUN_0027ee08(DAT_0034a7ec);
        if (lim > 0) {
            do {
                e = (struct Entry *)FUN_0027ee10(DAT_0034a7ec, i);
                if (e != 0 && e->f25 != 0) {
                    n++;
                    *param_1 = e->f26;
                    param_1++;
                }
                i++;
                lim = FUN_0027ee08(DAT_0034a7ec);
            } while (i < lim);
        }
    }
    return n;
}
