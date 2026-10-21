/* HSTMATCH module=EBOOT.BIN start=0x00128970 end=0x00128c94 symbol=FUN_00128970 lang=c++ rodata=0x002c146c */
/* Hand-written reconstruction from the disassembly and the Ghidra pseudocode (the error string says Avatar::Move); matching idioms: all eight Vec4 locals declared at the top (four copies c1..c4 above four out-pointer results d1..d4), the f404 != 0 arm written first, the f254 == 0 path as a single-case switch (beql + b), the default error print takes the mode as its dropped second argument, and the final reset copies field by field from a non-const global so every load is repeated; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj {
    char pad00[0x190];
    int mode;
    char pad01[0x1c];
    Vec4 pos;
    Vec4 prev;
    char pad02[0x84];
    unsigned char f254;
    char pad03[0x11b];
    char sub[0x94];
    unsigned char f404;
    char pad04[0xb];
    unsigned char f410;
};

extern Vec4 DAT_002bc440;
extern char DAT_002da908[];

extern "C" {
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
unsigned char FUN_0012c5ac(void *);
void FUN_0012c530(void *, Vec4 *);
void FUN_00128c94(Obj *, Vec4 *, int);
void FUN_0012a254(Obj *, int, int, int);
void FUN_00128d0c(void);
void FUN_00128298(Obj *);
void FUN_0012855c(void);
void FUN_00128910(Obj *);
void FUN_00126d1c(char *, ...);
}

extern "C" void FUN_00128970(Obj *self)
{
    Vec4 c1, c2, c3, c4;
    Vec4 d1, d2, d3, d4;

    self->prev = self->pos;
    if (self->f254 != 0) {
        switch (self->mode) {
        case 0: case 1: case 2: case 3: case 6: case 7: case 8: case 9: case 10: case 13:
            FUN_00128d0c();
        case 4:
        case 5:
            FUN_00128298(self);
            break;
        case 11:
            FUN_0012855c();
            break;
        case 12:
            if (self->f404 != 0) {
                FUN_0012c530(self->sub, &self->pos);
                FUN_00022434(&d1, &self->pos, &self->prev);
                c1 = d1;
                FUN_00128c94(self, &c1, 0);
                self->f410 = FUN_0012c5ac(self->sub);
            } else {
                self->f410 = FUN_0012c5ac(self->sub);
                FUN_0012c530(self->sub, &self->pos);
                FUN_00022434(&d2, &self->pos, &self->prev);
                c2 = d2;
                FUN_00128c94(self, &c2, 0);
            }
            if (self->f410 != 0) {
                FUN_0012a254(self, 0, 1, 0);
            }
            break;
        default:
            FUN_00126d1c(DAT_002da908, self->mode);
        }
    } else {
        switch (self->mode) {
        case 12:
            if (self->f404 != 0) {
                FUN_0012c530(self->sub, &self->pos);
                FUN_00022434(&d3, &self->pos, &self->prev);
                c3 = d3;
                FUN_00128c94(self, &c3, 0);
                self->f410 = FUN_0012c5ac(self->sub);
            } else {
                self->f410 = FUN_0012c5ac(self->sub);
                FUN_0012c530(self->sub, &self->pos);
                FUN_00022434(&d4, &self->pos, &self->prev);
                c4 = d4;
                FUN_00128c94(self, &c4, 0);
            }
            if (self->f410 != 0) {
                FUN_0012a254(self, 0, 1, 0);
            }
            break;
        default:
            FUN_00128d0c();
        }
    }
    FUN_00128910(self);
    if (self->pos.y > 30.0f) {
        self->pos.x = DAT_002bc440.x;
        self->pos.y = DAT_002bc440.y;
        self->pos.z = DAT_002bc440.z;
        self->pos.w = DAT_002bc440.w;
        self->prev.x = DAT_002bc440.x;
        self->prev.y = DAT_002bc440.y;
        self->prev.z = DAT_002bc440.z;
        self->prev.w = DAT_002bc440.w;
    }
}
