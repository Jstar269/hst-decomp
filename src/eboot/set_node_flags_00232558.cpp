/* HSTMATCH module=EBOOT.BIN start=0x00232558 end=0x00232660 symbol=FUN_00232558 lang=c++ */
/* Clone of src/sharing_main/set_node_flags_00242658.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_002f3cd4;
extern int DAT_002f3ce0;
void FUN_000ffb3c(Node *n, bool on);
bool FUN_0022c988(int idx);
}

extern "C" void FUN_00232558(Panel *self, int idx)
{
    FUN_000ffb3c(self->f144, true);
    FUN_000ffb3c(self->f148, true);
    FUN_000ffb3c(self->f14c, true);
    FUN_000ffb3c(self->f150, true);
    FUN_000ffb3c(self->f154, true);
    bool b = FUN_0022c988(idx);
    FUN_000ffb3c(self->fc0, true);
    self->f1d8 = b;
    FUN_000ffb3c(self->fbc, !b);
    FUN_000ffb3c(self->f168, true);
    self->f1d9 = true;
    self->f158->SetBoth(DAT_002f3cd4 + idx);
    self->f15c->SetBoth(DAT_002f3ce0 + idx);
    FUN_000ffb3c(self->f158, b);
    FUN_000ffb3c(self->f15c, !b);
}
