/* HSTMATCH module=EBOOT.BIN start=0x001e1614 end=0x001e185c symbol=FUN_001e1614 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Deletes the owned polymorphic objects (virtual deleting dtor, slot 0) and the POD array DAT_0034a130
// (delete[] -> __dla__FPv), nulling each pointer; `if (p) { delete p; p = 0; }` gives the two null tests.
// One VObj type stands for the members' (unknown) classes; Ghidra's DAT_0000175c is the member offset 0x175c.
struct VObj { virtual ~VObj(); };

extern "C" {
extern char *DAT_0034a130;
}

struct Self {
    char pad0[0x40];
    VObj *m40;
    char pad1[0x1f4 - 0x44];
    VObj *m1f4;
    char pad2[0x810 - 0x1f8];
    VObj *m810;
    char pad3[0x9b4 - 0x814];
    VObj *m9b4;
    char pad4[0x175c - 0x9b8];
    VObj *m175c;
    char pad5[0x1954 - 0x1760];
    VObj *m1954;
    VObj *m1958;
    VObj *m195c;
    char pad6[0x1adc - 0x1960];
    VObj *m1adc[21];
    char pad7[0x1d64 - 0x1b30];
    VObj *m1d64;
    VObj *m1d68;
    char pad8[0x25b8 - 0x1d6c];
    VObj *m25b8;
};

extern "C" void FUN_001e1614(Self *self)
{
    if (self->m40) { delete self->m40; self->m40 = 0; }
    if (DAT_0034a130) { delete[] DAT_0034a130; DAT_0034a130 = 0; }
    if (self->m9b4) { delete self->m9b4; self->m9b4 = 0; }
    if (self->m1f4) { delete self->m1f4; self->m1f4 = 0; }
    if (self->m810) { delete self->m810; self->m810 = 0; }
    if (self->m175c) { delete self->m175c; self->m175c = 0; }
    if (self->m1d68) { delete self->m1d68; self->m1d68 = 0; }
    for (int i = 0; i < 21; i++) {
        if (self->m1adc[i]) { delete self->m1adc[i]; self->m1adc[i] = 0; }
    }
    if (self->m1958) { delete self->m1958; self->m1958 = 0; }
    if (self->m195c) { delete self->m195c; self->m195c = 0; }
    if (self->m1d64) { delete self->m1d64; self->m1d64 = 0; }
    if (self->m1954) { delete self->m1954; self->m1954 = 0; }
    if (self->m25b8) { delete self->m25b8; self->m25b8 = 0; }
}
