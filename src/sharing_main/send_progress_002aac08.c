/* HSTMATCH module=hstp_trans_main.prx start=0x002aac08 end=0x002aad30 symbol=FUN_002aac08 lang=c99 helpers=FUN_002a9808@0x002a9808-0x002a9834 */
/* Clone of src/eboot/send_progress_0029ba20.c (hstclone.py tag a0db26h2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/send_progress_002aac08.c, completed with its same-file static helper FUN_002a9808 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
typedef struct Bar_002aac08 {
    char pad[0x1c];
    float min_val;
    float max_val;
} Bar_002aac08;

typedef struct Screen_002aac08 {
    char pad[0x64];
    Bar_002aac08 *bar;
} Screen_002aac08;

typedef struct Obj_002aac08 {
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
} Obj_002aac08;

extern Screen_002aac08 *DAT_003ea8ec;
extern char DAT_002dba00[];
extern unsigned char FUN_000c3cd4(int, char *, int);
extern int FUN_00104c64(char *, int);
extern int FUN_00104f10(int, char *, int, int);
extern void FUN_0011d7f8(float, Bar_002aac08 *);
static void FUN_002a9808(...)
{
}

static inline void SetBarRange(float min_val, float max_val, Screen_002aac08 *scr)
{
    Bar_002aac08 *bar = scr->bar;
    bar->min_val = min_val;
    bar->max_val = max_val;
}

static inline void SetBarValue(float val, Screen_002aac08 *scr)
{
    FUN_0011d7f8(val, scr->bar);
}

void FUN_002aac08(Obj_002aac08 *self)
{
    int r;

    if (self->can_send != 0) {
        self->chunk = FUN_00104f10(self->ring, self->buf, 0x7000, 0);
    }
    if (self->chunk > 0) {
        self->can_send = FUN_000c3cd4(self->f8, self->buf, self->chunk);
        if (self->first_send != 0) {
            self->first_send = 0;
        }
    }
    if (self->can_send != 0) {
        self->sent = self->sent + self->chunk;
        if (self->total_size == 0x7fffffff) {
            r = FUN_00104c64(self->buf, self->sent);
            if (r >= 0) {
                self->total_size = r;
                FUN_002a9808(DAT_002dba00, r);
            }
        }
        SetBarRange(0.0f, (float)self->total_size, DAT_003ea8ec);
        SetBarValue((float)self->sent, DAT_003ea8ec);
    }
}
