/* HSTMATCH module=hstp_trans_main.prx start=0x000c012c end=0x000c0230 symbol=FUN_000c012c lang=c99 */
/* Clone of src/eboot/send_cmd_msg_000bcc88.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_0001100c(const void *a, const void *b, int n);
extern void FUN_00011090(void *dst, const void *src, int n);
extern int FUN_000c1090(char *self, int a, char *b, unsigned short c, void *d, int e, int f, int g);
extern void FUN_000bd6f0(void *msg, ...);
extern char DAT_0037bcd8[];
struct Vec2_000c012c { float x, y; };
struct Msg_000c012c { int cmd; int size; struct Vec2_000c012c pos; int idx; };

static inline int Find_000c012c(char *p0, char *key)
{
    int idx = 0;
    char *p = p0;
    while (idx < 16) {
        if (*(unsigned char *)(p + 0x5e) != 0) {
            if (FUN_0001100c(p + 0x58, key, 6) == 0)
                return idx;
        }
        idx++;
        p += 7;
    }
    return -1;
}

void FUN_000c012c(char *self)
{
    if (*(unsigned char *)(self + 0x178) != 0) {
        *(unsigned char *)(self + 0x21c) = 1;
        return;
    }
    struct Msg_000c012c msg;
    msg.cmd = 3;
    msg.pos = *(struct Vec2_000c012c *)(self + 0x27c);
    char *key = self + 0x38;
    msg.idx = Find_000c012c(self, key);
    msg.size = 20;
    FUN_00011090(*(void **)(self + 0x184), &msg, 20);
    int r = FUN_000c1090(self, *(int *)(self + 0x17c), self + 0x3e, (unsigned)*(unsigned short *)(self + 0x10),
                         *(void **)(self + 0x184), msg.size, 0, 1);
    if (r < 0)
        FUN_000bd6f0(DAT_0037bcd8, r);
}
