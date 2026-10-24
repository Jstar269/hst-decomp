/* HSTMATCH module=EBOOT.BIN start=0x001bfbe8 end=0x001bfdd0 symbol=FUN_001bfbe8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char undefined1;

extern undefined1 DAT_002e9fec;
extern undefined1 DAT_002e9ff4;
extern undefined1 DAT_002e9ffc;
extern int DAT_0034174c;

extern "C" {
int FUN_0000d62c(int);
int FUN_00014d64(int, void *);
int FUN_000650e0(int);
int FUN_0006517c(int, int, int);
int FUN_001bfbe8(int param_1, int param_2);
}

int FUN_001bfbe8(int param_1, int param_2)
{
    int ret;
    int g;
    int i;
    int item;
    int idx;
    char *p;
    unsigned char val;

    ret = 0;
    g = DAT_0034174c;
    if (g != 0 && param_2 >= 0 && param_2 < FUN_000650e0(g)) {
        ret = 1;
        for (i = 0; i < 4; i++) {
            item = FUN_0006517c(g, param_2 + 1, i + 1);
            if (item != 0) {
                if (FUN_00014d64(item, &DAT_002e9fec) != 0) {
                    idx = FUN_0000d62c(item + 5);
                    val = 0;
                    if (idx >= 0) {
                        if (idx < 640) {
                            p = (char *)param_1 + idx + 0x84c;
                        } else {
                            p = 0;
                        }
                    } else {
                        p = 0;
                    }
                    if (p != 0)
                        val = *p;
                    if ((val - 4U) > 1)
                        ret = 0;
                } else if (FUN_00014d64(item, &DAT_002e9ff4) != 0) {
                    idx = FUN_0000d62c(item + 5);
                    val = 0;
                    if (idx >= 0) {
                        if (idx < 640) {
                            p = (char *)param_1 + idx + 0xacc;
                        } else {
                            p = 0;
                        }
                    } else {
                        p = 0;
                    }
                    if (p != 0)
                        val = *p;
                    if ((val - 4U) > 1)
                        ret = 0;
                } else if (FUN_00014d64(item, &DAT_002e9ffc) != 0) {
                    idx = FUN_0000d62c(item + 5);
                    val = 0;
                    if (idx >= 0) {
                        if (idx < 640) {
                            p = (char *)param_1 + idx + 0xd4c;
                        } else {
                            p = 0;
                        }
                    } else {
                        p = 0;
                    }
                    if (p != 0)
                        val = *p;
                    if ((val - 4U) > 1)
                        ret = 0;
                }
            }
        }
    }
    return ret;
}
