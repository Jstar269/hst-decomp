/* HSTMATCH module=hstp_trans_main.prx start=0x0020dbac end=0x0020dc70 symbol=FUN_0020dbac lang=c99 */
/* Clone of src/eboot/check_id_match_001ff3dc.c (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char u8;

extern void *DAT_003e1a08;
extern void *DAT_003e1e04;
extern int FUN_000c1e54(void *arg);

int FUN_0020dbac(int param_1) {
    int res = 0;
    if (DAT_003e1a08 != 0) {
        if (DAT_003e1e04 != 0) {
            if (FUN_000c1e54(DAT_003e1e04) != 0) {
                char *sub = 0;
                if (DAT_003e1a08 != 0) {
                    if (DAT_003e1e04 != 0) {
                        char *base = *(char **)((char *)DAT_003e1a08 + 0x40);
                        if (*(u8 *)((char *)DAT_003e1e04 + 0x178) != 0) {
                            sub = base + 0x1ef8;
                        } else {
                            sub = base + 0x1aa0;
                        }
                    }
                }
                if (*(u8 *)(sub + 0x12d) != 0 && param_1 != 0 && param_1 == *(int *)(sub + 0x3b0) && param_1 == *(int *)(sub + 0x3b4)) {
                    res = 1;
                }
            }
        }
    }
    return res;
}
