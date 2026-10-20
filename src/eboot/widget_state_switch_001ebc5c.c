/* HSTMATCH module=EBOOT.BIN start=0x001ebc5c end=0x001ebd54 symbol=FUN_001ebc5c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad0[0x24]; int a; int b; } Widget;
typedef struct {
    unsigned char pad0[0x5c];
    void *field_5c;
    unsigned char pad1[0x68];
    Widget *field_c8;
    Widget *field_cc;
    unsigned char pad2[0x68];
    int field_138;
} Self;
extern int DAT_0034a678;
extern int DAT_002ee3bc;
extern void FUN_00102c54(void *);

void FUN_001ebc5c(Self *self, int visible, int mode)
{
    float value;
    int id;

    self->field_138 = mode;
    if (visible != 0)
        value = 0.0f;
    else
        value = 1.0f;
    *(float *)((char *)self->field_5c + 0x78) = value;
    FUN_00102c54(self->field_5c);
    switch (DAT_0034a678) {
    case 0x2a:
    case 0x31: {
        Widget *w = self->field_c8;

        w->a = 0x14;
        w->b = 0x14;
        break;
    }
    case 0x44: {
        Widget *w = self->field_c8;

        w->a = 0x17;
        w->b = 0x17;
        break;
    }
    default: {
        Widget *w = self->field_c8;

        w->a = 0x15;
        w->b = 0x15;
        break;
    }
    }
    switch (mode) {
    case 0:
        id = 0x28;
        break;
    case 1:
        id = 0x13;
        break;
    case 2:
        id = 0x12;
        break;
    }
    {
        int v = DAT_002ee3bc + id;
        Widget *w = self->field_cc;

        w->a = v;
        w->b = v;
    }
}
