/* HSTMATCH module=hstp_trans_main.prx start=0x00193860 end=0x001939b8 symbol=FUN_00193860 lang=c++ */
/* Clone of src/eboot/layout_panes_00187114.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane ds10 near miss reworked); exact match verified; names and types await human review. */
struct Item {
    int a;
    int b;
    short x, y;      /* 0x08 */
    int c, d;
    short x2, y2;    /* 0x14 */
    char pad[0x8c - 0x18];
};
struct Pos {
    char pad[0x60];
    float x;         /* 0x60 */
    float y;         /* 0x64 */
};
struct Cfg {
    char pad[0x3d];
    unsigned char flag;
};
struct Info {
    char pad[0x64];
    int t;
};
struct Screen {
    char pad0[0x20];
    Pos *pos20;
    int pad24;
    Pos *pos28;
    char pad2c[0x1254 - 0x2c];
    Item items[9];
};
extern "C" Info *FUN_00177ea4();
extern "C" Cfg *FUN_00177e98();
extern "C" void FUN_0022687c(Item *e, int x, int y, int x2, int y2, int t);

extern "C" void FUN_00193860(Screen *self) {
    int t = FUN_00177ea4()->t;
    if (FUN_00177e98()->flag != 0) {
        FUN_0022687c(&self->items[0], self->items[0].x, self->items[0].y, self->items[0].x - 480, self->items[0].y, t);
    } else {
        FUN_0022687c(&self->items[1], self->items[1].x2, self->items[1].y2, self->items[1].x2 - 480, self->items[1].y2, t);
    }
    FUN_0022687c(&self->items[2], self->items[2].x, (int)self->pos20->y, self->items[2].x - 480, (int)self->pos20->y, t);
    FUN_0022687c(&self->items[5], self->items[5].x, self->items[5].y, self->items[5].x - 480, self->items[5].y, t);
    FUN_0022687c(&self->items[3], self->items[3].x, self->items[3].y, self->items[3].x - 480, self->items[3].y, t);
    FUN_0022687c(&self->items[4], (int)self->pos28->x, self->items[4].y, (int)self->pos28->x - 480, self->items[4].y, t);
    FUN_0022687c(&self->items[6], self->items[6].x, self->items[6].y, self->items[6].x + 480, self->items[6].y, t);
    FUN_0022687c(&self->items[7], self->items[7].x, self->items[7].y, self->items[7].x + 480, self->items[7].y, t);
    FUN_0022687c(&self->items[8], self->items[8].x, self->items[8].y, self->items[8].x + 480, self->items[8].y, t);
}
