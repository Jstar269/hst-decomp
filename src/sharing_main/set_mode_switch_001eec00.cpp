/* HSTMATCH module=hstp_trans_main.prx start=0x001eec00 end=0x001eecd4 symbol=FUN_001eec00 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Stores the mode, then for mode 0 / 1 resets the screen (FUN_001f08e8), calls virtual slot 1 of the page object
   at +0x40 / +0x3c and runs the matching setup helpers; any other mode only calls FUN_00108f54(fd4, 1). A switch
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
void FUN_001f08e8(Menu *self);
void FUN_001f0c34(Menu *self, int on);
void FUN_001f0be4(Menu *self);
void FUN_001f0b34(Menu *self);
void FUN_001f0ca8(Menu *self);
void FUN_00108f54(void *obj, int flag);
}

extern "C" void FUN_001eec00(Menu *self, int mode)
{
    self->mode = mode;
    switch (mode) {
    case 0:
        FUN_001f08e8(self);
        self->page40->Open();
        FUN_001f0c34(self, 1);
        FUN_001f0be4(self);
        FUN_00108f54(self->fd4, 0);
        FUN_001f0ca8(self);
        break;
    case 1:
        FUN_001f08e8(self);
        self->page3c->Open();
        FUN_001f0c34(self, 0);
        FUN_001f0b34(self);
        FUN_00108f54(self->fd4, 1);
        break;
    default:
        FUN_00108f54(self->fd4, 1);
        break;
    }
}
