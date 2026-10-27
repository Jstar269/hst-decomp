/* HSTMATCH module=EBOOT.BIN start=0x00170744 end=0x00170820 symbol=FUN_00170744 lang=c99 */
/* Clone of src/sharing_main/cfg_turn_0017c9bc.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Two input-driven adjustments of the object at +0x178, selected by 2-bit signed fields of the config bytes at
   +0x88/+0x8c (LSB-first bitfields give retail's sll/sra pairs): FUN_0017dc14 gets +/-f2bc (only when flag is 0;
   the value is read before the tests, as retail loads it into $f12 ahead of the first branch), FUN_0017de30 gets
   +/-f2b4 converted from degrees to radians and a third argument 1 (retail reuses the compare constant in a1). */
typedef struct Cfg {
    char pad[0x88];
    signed char a0 : 2;
    signed char a1 : 2;
    signed char a2 : 2;
    signed char a3 : 2;
    char pad89[3];
    signed char b0 : 2;
    signed char b1 : 2;
    signed char b2 : 2;
    signed char b3 : 2;
} Cfg;

typedef struct Obj {
    char pad0[0x178];
    void *target;
    char pad1[0x2b4 - 0x17c];
    float f2b4;
    float f2b8;
    float f2bc;
} Obj;

extern Cfg *DAT_002cfc8c;
extern void FUN_0017dc14(void *obj, float d);
extern void FUN_0017de30(void *obj, float d, int flag);

void FUN_00170744(Obj *self, int flag)
{
    float a;
    if (flag == 0) {
        float v = self->f2bc;
        if (DAT_002cfc8c->b0 == 1) FUN_0017dc14(self->target, v);
        else if (DAT_002cfc8c->b2 == 1) FUN_0017dc14(self->target, -v);
    }
    a = self->f2b4 * 0.017453292f;
    if (DAT_002cfc8c->a0 != 0) {
        if (DAT_002cfc8c->b3 == 1) FUN_0017de30(self->target, a, 1);
        else if (DAT_002cfc8c->b1 == 1) FUN_0017de30(self->target, -a, 1);
    }
}
