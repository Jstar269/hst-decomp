/* HSTMATCH module=hstp_trans_main.prx start=0x0008ade4 end=0x0008af28 symbol=FUN_0008ade4 lang=c++ rodata=0x002ce7f4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Per-frame scene update: applies a pending state change (FUN_0008a19c(self, 0), src/sharing_main/scene_set_state_0008a19c.cpp), runs the per-state handler through the 10-entry jump table (rodata=), clears the HUD at DAT_003daec8 when its timer is zero, and on the +0x5a request flag starts transition 25 and sets the next state to 9. Field names follow the Scene struct of 0x8a19c. */
struct Obj;
struct Score { char pad0[0x1e0]; int value; };
struct Hud { char pad0[0xc]; float time; char pad10[0x52 - 0x10]; unsigned char shown; };

struct Scene {
    char pad0[0x3c];
    int state;
    int next;
    char pad44[0x5a - 0x44];
    unsigned char m5a;
    unsigned char m5b;
    char pad5c[0xa0 - 0x5c];
    Score *score;
};

extern Hud *DAT_003daec8;

extern "C" {
void FUN_0001f4a0(Scene *, int, int, int);
void FUN_0008a19c(Scene *, int);
void FUN_0008af28(Scene *);
void FUN_0008b034(Scene *);
void FUN_0008b104(Scene *);
void FUN_0008b17c(Scene *);
void FUN_0008b34c(Scene *);
void FUN_0008b55c(Scene *);
void FUN_0008b870(Scene *);
void FUN_0008ba68(Scene *);
void FUN_0008bcf4(Scene *);
}

extern "C" void FUN_0008ade4(Scene *self)
{
    FUN_0008a19c(self, 0);
    switch (self->state) {
    case 1:
        FUN_0008af28(self);
        break;
    case 2:
        FUN_0008b034(self);
        break;
    case 3:
        FUN_0008b104(self);
        break;
    case 4:
        FUN_0008b17c(self);
        self->score->value++;
        break;
    case 5:
        FUN_0008b34c(self);
        break;
    case 6:
        FUN_0008b55c(self);
        break;
    case 7:
        FUN_0008b870(self);
        break;
    case 8:
        FUN_0008ba68(self);
        break;
    case 9:
        FUN_0008bcf4(self);
        break;
    }
    Hud *hud = DAT_003daec8;
    if (hud->time == 0.0f) {
        hud->time = 0.0f;
        hud->shown = 0;
    }
    if (self->m5a) {
        self->m5a = 0;
        self->m5b = 1;
        FUN_0001f4a0(self, 25, 0, 0);
        self->next = 9;
    }
}
