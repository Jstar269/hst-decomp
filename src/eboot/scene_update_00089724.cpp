/* HSTMATCH module=EBOOT.BIN start=0x00089724 end=0x00089868 symbol=FUN_00089724 lang=c++ rodata=0x002be8bc */
/* Clone of src/sharing_main/scene_update_0008ade4.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Per-frame scene update: applies a pending state change (FUN_00088a44(self, 0), src/sharing_main/scene_set_state_00088a44.cpp), runs the per-state handler through the 10-entry jump table (rodata=), clears the HUD at DAT_00331b88 when its timer is zero, and on the +0x5a request flag starts transition 25 and sets the next state to 9. Field names follow the Scene struct of 0x8a19c. */
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

extern Hud *DAT_00331b88;

extern "C" {
void FUN_0001f558(Scene *, int, int, int);
void FUN_00088a44(Scene *, int);
void FUN_00089868(Scene *);
void FUN_00089974(Scene *);
void FUN_00089a44(Scene *);
void FUN_00089abc(Scene *);
void FUN_00089c8c(Scene *);
void FUN_00089e9c(Scene *);
void FUN_0008a1b0(Scene *);
void FUN_0008a3a8(Scene *);
void FUN_0008a634(Scene *);
}

extern "C" void FUN_00089724(Scene *self)
{
    FUN_00088a44(self, 0);
    switch (self->state) {
    case 1:
        FUN_00089868(self);
        break;
    case 2:
        FUN_00089974(self);
        break;
    case 3:
        FUN_00089a44(self);
        break;
    case 4:
        FUN_00089abc(self);
        self->score->value++;
        break;
    case 5:
        FUN_00089c8c(self);
        break;
    case 6:
        FUN_00089e9c(self);
        break;
    case 7:
        FUN_0008a1b0(self);
        break;
    case 8:
        FUN_0008a3a8(self);
        break;
    case 9:
        FUN_0008a634(self);
        break;
    }
    Hud *hud = DAT_00331b88;
    if (hud->time == 0.0f) {
        hud->time = 0.0f;
        hud->shown = 0;
    }
    if (self->m5a) {
        self->m5a = 0;
        self->m5b = 1;
        FUN_0001f558(self, 25, 0, 0);
        self->next = 9;
    }
}
