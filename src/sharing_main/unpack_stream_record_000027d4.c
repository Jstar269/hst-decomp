/* HSTMATCH module=hstp_trans_main.prx start=0x000027d4 end=0x00002870 symbol=FUN_000027d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void *FUN_00001040(void *src, void *dst);

struct Stream {
    char pad[4];
    char *p;
};

struct Obj {
    char pad_0[0x14];
    int f_14; // 0x14
    int f_18; // 0x18
    char pad_1c[0x98 - 0x1c];
    int f_98; // 0x98
    char pad_9c[4];
    int f_a0; // 0xa0
    int f_a4; // 0xa4
    int f_a8; // 0xa8
    int f_ac; // 0xac
    int f_b0; // 0xb0
    int f_b4; // 0xb4
};

void FUN_000027d4(struct Obj *self, struct Stream *stream) {
    char *p = stream->p;
    char c = *p;
    int flag = c & 0x40;
    self->f_b0 = c & 0x20;
    self->f_ac = *p & 0x10;
    self->f_a8 = *p & 0xf;

    void *ret = FUN_00001040(p + 1, &self->f_a0);
    ret = FUN_00001040(ret, &self->f_a4);

    if (self->f_b0 != 0) {
        self->f_18 = self->f_98;
    } else {
        self->f_18 = self->f_14;
    }

    if (flag) {
        FUN_00001040(ret, &self->f_b4);
    } else {
        self->f_b4 = 0;
    }
}
