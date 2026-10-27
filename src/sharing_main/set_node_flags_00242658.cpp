/* HSTMATCH module=hstp_trans_main.prx start=0x00242658 end=0x00242760 symbol=FUN_00242658 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node {
    char pad0[0x24];
    int f24;
    int f28;

    void SetBoth(int v)
    {
        f24 = v;
        f28 = v;
    }
};

struct Panel {
    char pad0[0xbc];
    Node *fbc;
    Node *fc0;
    char pad1[0x144 - 0xc4];
    Node *f144;
    Node *f148;
    Node *f14c;
    Node *f150;
    Node *f154;
    Node *f158;
    Node *f15c;
    char pad2[0x168 - 0x160];
    Node *f168;
    char pad3[0x1d8 - 0x16c];
    bool f1d8;
    bool f1d9;
};

extern "C" {
extern int DAT_0039c598;
extern int DAT_0039c5a4;
void FUN_00105470(Node *n, bool on);
bool FUN_0023c5e0(int idx);
}

extern "C" void FUN_00242658(Panel *self, int idx)
{
    FUN_00105470(self->f144, true);
    FUN_00105470(self->f148, true);
    FUN_00105470(self->f14c, true);
    FUN_00105470(self->f150, true);
    FUN_00105470(self->f154, true);
    bool b = FUN_0023c5e0(idx);
    FUN_00105470(self->fc0, true);
    self->f1d8 = b;
    FUN_00105470(self->fbc, !b);
    FUN_00105470(self->f168, true);
    self->f1d9 = true;
    self->f158->SetBoth(DAT_0039c598 + idx);
    self->f15c->SetBoth(DAT_0039c5a4 + idx);
    FUN_00105470(self->f158, b);
    FUN_00105470(self->f15c, !b);
}
