/* HSTMATCH module=EBOOT.BIN start=0x001e09dc end=0x001e0ab0 symbol=FUN_001e09dc lang=c++ */
/* Clone of src/sharing_main/set_mode_switch_001eec00.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Stores the mode, then for mode 0 / 1 resets the screen (FUN_001e2694), calls virtual slot 1 of the page object
   at +0x40 / +0x3c and runs the matching setup helpers; any other mode only calls FUN_00103628(fd4, 1). A switch
   with labels 0, 1 written in that order gives retail's `beq 1; beqz` tests. Names provisional. */
struct Page {
    virtual void d0();
    virtual void Open();
};

struct Menu {
    char pad0[0x3c];
    Page *page3c;
    Page *page40;
    int mode;
    char pad48[0xd4 - 0x48];
    void *fd4;
};

extern "C" {
void FUN_001e2694(Menu *self);
void FUN_001e29e0(Menu *self, int on);
void FUN_001e2990(Menu *self);
void FUN_001e28e0(Menu *self);
void FUN_001e2a54(Menu *self);
void FUN_00103628(void *obj, int flag);
}

extern "C" void FUN_001e09dc(Menu *self, int mode)
{
    self->mode = mode;
    switch (mode) {
    case 0:
        FUN_001e2694(self);
        self->page40->Open();
        FUN_001e29e0(self, 1);
        FUN_001e2990(self);
        FUN_00103628(self->fd4, 0);
        FUN_001e2a54(self);
        break;
    case 1:
        FUN_001e2694(self);
        self->page3c->Open();
        FUN_001e29e0(self, 0);
        FUN_001e28e0(self);
        FUN_00103628(self->fd4, 1);
        break;
    default:
        FUN_00103628(self->fd4, 1);
        break;
    }
}
