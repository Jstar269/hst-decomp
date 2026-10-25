/* HSTMATCH module=EBOOT.BIN start=0x001f25a4 end=0x001f2934 symbol=FUN_001f25a4 lang=c++ */
/* Hand-written reconstruction from the disassembly (generated candidate used only for the pseudocode shape); exact match verified; names and types await human review. */
struct Bits {
    signed char lo : 2;
    signed char mode : 2;
    signed char hi : 4;
};

struct Config {
    char pad[0x8b];
    Bits bits;
};

struct Panel {
    char pad[0x98];
    unsigned char shown;
};

struct Scene {
    char pad0[0x3c];
    char fade[0x44 - 0x3c];
    int started;
    char pad1[0x510 - 0x48];
    void *view;
    char pad2[0x560 - 0x514];
    void *menu;
    char pad3[0x584 - 0x564];
    Panel *panel;
    char pad4[0x58c - 0x588];
    unsigned char busy;
    char pad5[0x5a4 - 0x58d];
    unsigned char skip;
    char pad6[0x81a4 - 0x5a5];
    int state;
    int count;
    char pad7;
    unsigned char ready;
    char pad8;
    unsigned char quick;
    unsigned char alt;
};

extern "C" {
extern char DAT_0034179c[];
extern Config *DAT_002cfc8c;
extern void *DAT_00331b84;
void FUN_001e7d28(void *);
void FUN_001e2990(void *);
void FUN_001e8424(void *);
void FUN_001b1c44(void *, int);
void FUN_001e7d70(void *, int, int);
void FUN_001e84d4(void *);
void FUN_001e84c8(void *);
void FUN_001b2af0(void *, int);
void FUN_001e28e0(void *);
void FUN_001f4bbc(Scene *);
void FUN_001fb928(void *, int, int);
void FUN_00063b20(void *, int, float);
void FUN_001e075c(void *);
void FUN_00216de0(void *);
void FUN_001ff668(void);
void FUN_001f4bfc(Scene *);
void FUN_001f483c(Scene *);
}

extern "C" void FUN_001f25a4(Scene *self)
{
    if (self->started == 0) {
        self->state = 0;
        self->count = 0;
        FUN_001e7d28(self->view);
        FUN_001e2990(self->view);
        FUN_001e8424(self->view);
        FUN_001b1c44(DAT_0034179c, 8);
    }
    switch (self->state) {
    case 0:
        if (++self->count > 30) {
            self->state = 1;
            self->count = 0;
            if (self->quick == 0 && self->ready != 0) {
                FUN_001e7d70(self->view, 1, 0);
                FUN_001e84d4(self->view);
                FUN_001b2af0(DAT_0034179c, 12);
            }
        }
        break;
    case 1:
        self->count++;
        if (self->quick != 0 || self->ready == 0 || self->count > 40) {
            if (self->alt != 0) {
                self->state = 2;
                self->count = 0;
                FUN_001e7d70(self->view, 0, 1);
                FUN_001e84c8(self->view);
                FUN_001b2af0(DAT_0034179c, 12);
            } else {
                self->state = 3;
                self->count = 0;
                FUN_001e28e0(self->view);
            }
        }
        break;
    case 2:
        if (++self->count > 30) {
            self->state = 3;
            self->count = 0;
            FUN_001e28e0(self->view);
        }
        break;
    case 3: {
        bool go;
        if (self->busy != 0)
            go = false;
        else
            go = DAT_002cfc8c->bits.mode == 0;
        if (go) {
            FUN_001b1c44(DAT_0034179c, 3);
            self->state = 4;
            self->count = 0;
        }
        break;
    }
    case 4:
        if (self->skip != 0) {
            FUN_001f4bbc(self);
            FUN_001fb928(self->fade, 15, 1);
        } else {
            int n = ++self->count;
            if (n == 1)
                FUN_00063b20(DAT_00331b84, 5, 65535.0f);
            if (n == 7) {
                FUN_001f4bbc(self);
                FUN_001e075c(self->view);
                self->panel->shown = 1;
                FUN_001fb928(self->fade, 4, 1);
                FUN_00216de0(self->menu);
                FUN_001ff668();
            }
        }
        break;
    }
    FUN_001f4bfc(self);
    FUN_001f483c(self);
}
