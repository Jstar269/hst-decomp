/* HSTMATCH module=EBOOT.BIN start=0x0029ba20 end=0x0029bb48 symbol=FUN_0029ba20 lang=c99 helpers=FUN_0029a584@0x0029a584-0x0029a5b0 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/send_progress_0029ba20.c, completed with its same-file static helper FUN_0029a584 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
typedef struct Bar_0029ba20 {
    char pad[0x1c];
    float min_val;
    float max_val;
} Bar_0029ba20;

typedef struct Screen_0029ba20 {
    char pad[0x64];
    Bar_0029ba20 *bar;
} Screen_0029ba20;

typedef struct Obj_0029ba20 {
    int f0;
    int f4;
    int f8;
    int fc;
    int sent;
    unsigned char can_send;
    unsigned char first_send;
    unsigned char f16;
    unsigned char f17;
    int f18;
    int ring;
    char pad20[0x7424 - 0x20];
    char buf[0x7000];
    int chunk;
    char pade428[0x15830 - 0xe428];
    int total_size;
} Obj_0029ba20;

extern Screen_0029ba20 *DAT_003415ac;
extern char DAT_002cb9b0[];
extern unsigned char FUN_000c0634(int, char *, int);
extern int FUN_000ff3cc(char *, int);
extern int FUN_000ff678(int, char *, int, int);
extern void FUN_00113580(float, Bar_0029ba20 *);
static void FUN_0029a584(...)
{
}

static inline void SetBarRange(float min_val, float max_val, Screen_0029ba20 *scr)
{
    Bar_0029ba20 *bar = scr->bar;
    bar->min_val = min_val;
    bar->max_val = max_val;
}

static inline void SetBarValue(float val, Screen_0029ba20 *scr)
{
    FUN_00113580(val, scr->bar);
}

void FUN_0029ba20(Obj_0029ba20 *self)
{
    int r;

    if (self->can_send != 0) {
        self->chunk = FUN_000ff678(self->ring, self->buf, 0x7000, 0);
    }
    if (self->chunk > 0) {
        self->can_send = FUN_000c0634(self->f8, self->buf, self->chunk);
        if (self->first_send != 0) {
            self->first_send = 0;
        }
    }
    if (self->can_send != 0) {
        self->sent = self->sent + self->chunk;
        if (self->total_size == 0x7fffffff) {
            r = FUN_000ff3cc(self->buf, self->sent);
            if (r >= 0) {
                self->total_size = r;
                FUN_0029a584(DAT_002cb9b0, r);
            }
        }
        SetBarRange(0.0f, (float)self->total_size, DAT_003415ac);
        SetBarValue((float)self->sent, DAT_003415ac);
    }
}
