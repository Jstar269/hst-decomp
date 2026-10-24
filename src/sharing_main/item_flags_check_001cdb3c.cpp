/* HSTMATCH module=hstp_trans_main.prx start=0x001cdb3c end=0x001cdd24 symbol=FUN_001cdb3c lang=c++ */
/* Clone of src/eboot/item_flags_check_001bfbe8.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char undefined1;

extern undefined1 DAT_00391c44;
extern undefined1 DAT_00391c4c;
extern undefined1 DAT_00391c54;
extern int DAT_003eaa8c;

extern "C" {
int FUN_0000d644(int);
int FUN_00014d64(int, void *);
int FUN_00065fa4(int);
int FUN_000661a8(int, int, int);
int FUN_001cdb3c(int param_1, int param_2);
}

int FUN_001cdb3c(int param_1, int param_2)
{
    int ret;
    int g;
    int i;
    int item;
    int idx;
    char *p;
    unsigned char val;

    ret = 0;
    g = DAT_003eaa8c;
    if (g != 0 && param_2 >= 0 && param_2 < FUN_00065fa4(g)) {
        ret = 1;
        for (i = 0; i < 4; i++) {
            item = FUN_000661a8(g, param_2 + 1, i + 1);
            if (item != 0) {
                if (FUN_00014d64(item, &DAT_00391c44) != 0) {
                    idx = FUN_0000d644(item + 5);
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
                } else if (FUN_00014d64(item, &DAT_00391c4c) != 0) {
                    idx = FUN_0000d644(item + 5);
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
                } else if (FUN_00014d64(item, &DAT_00391c54) != 0) {
                    idx = FUN_0000d644(item + 5);
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
