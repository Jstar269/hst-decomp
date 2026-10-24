/* HSTMATCH module=hstp_trans_main.prx start=0x000fe984 end=0x000febfc symbol=FUN_000fe984 lang=c++ */
/* Clone of src/eboot/status_update_000f9290.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; outer switch default-first places case 8 at fallthrough; inner switch case 3..1 lowers to ascending beq chain; 3rd arg 1 to FUN_001fa7c8 hoists li a2, 1 before switch comparison; names and types await human review. */

struct Global3386b0 {
    char pad[0x3c];
    int field_3c;
};

struct Global338b44 {
    char pad[0xb8];
    int fb8;
    int fbc;
};

struct Global2cfc8c {
    char pad[0x88];
    signed char pad_bits:6;
    signed char flag:2;
};

struct Node {
    char pad[0x24];
    int val;
    int val2;
};

struct SubObj {
    virtual void d0();
    virtual void v1();
    char pad_04[0x128 - 4];
    Node *n128;
    Node *n12c;
    char pad_130[0x138 - 0x130];
    Node *n138;
    Node *n13c;
    char pad_140[0x160 - 0x140];
    Node *n160;
    Node *n164;
    Node *n168;
    Node *n16c;
    char pad_170[0x1b8 - 0x170];
    void *p1b8;
    char pad_1bc[0x1e0 - 0x1bc];
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    char pad_1f0[0x208 - 0x1f0];
    int f208;
    int f20c;
};

struct P94 {
    char pad[0x0c];
    int f0c;
};

struct BaseObj {
    virtual void d0();
    virtual void d1();
    virtual void v2();
    char pad_04[0x54 - 4];
    SubObj *sub;
    char pad_58[0x94 - 0x58];
    P94 *p94;
    char pad_98[0x14c - 0x98];
    int f14c;
    int f150;
    char pad_154;
    unsigned char f155;
};

extern "C" {
extern Global3386b0 *DAT_003e19f0;
extern Global338b44 *DAT_003e1e84;
extern Global2cfc8c *DAT_003751d4;
extern int FUN_0008a144();
extern int FUN_0004896c();
extern int FUN_00048958();
extern void FUN_001fa7c8(...);
extern void FUN_001faf34(P94 *);
extern void FUN_00108dac(void *);
}

extern "C" void FUN_000fe984(BaseObj *self) {
    switch (DAT_003e19f0->field_3c) {
    default:
        if (DAT_003e19f0 != 0 && FUN_0008a144()) {
            if (FUN_0004896c() && self->f155 == 0) {
                FUN_001fa7c8(self->p94, 0, 1);
            }
            self->f155 = FUN_0004896c();
            break;
        }
        switch (DAT_003e19f0->field_3c) {
        case 3:
        case 2:
        case 1:
            break;
        default:
            if (self->f155 == 0) {
                if (DAT_003751d4->flag == 0) {
                    FUN_001fa7c8(self->p94, 0, 1);
                    self->f155 = 1;
                    Global2cfc8c *fb = DAT_003751d4;
                    fb->flag = -1;
                }
            } else if (self->p94->f0c == 11) {
                self->f155 = 0;
            }
            break;
        }
        break;
    case 8:
        if (self->f155 == 0) {
            FUN_001fa7c8(self->p94, DAT_003e1e84->fb8 + DAT_003e1e84->fbc, 0);
        }
        self->f155 = 1;
        break;
    }

    if (!FUN_00048958()) {
        self->v2();
        self->f150 = 0;
    } else if (DAT_003e19f0->field_3c != 4) {
        FUN_001faf34(self->p94);
    } else {
        if (self->f150 == 0) {
            FUN_00108dac(self->sub);
            FUN_00108dac(self->sub->p1b8);
            SubObj *sub = self->sub;
            sub->f1e0 = sub->n128->val;
            sub->f1e4 = sub->n12c->val;
            sub->f1e8 = sub->n138->val;
            sub->f1ec = sub->n13c->val;
            self->sub->v1();
            SubObj *sub2 = self->sub;
            int v = sub2->n168->val;
            Node *n160 = sub2->n160;
            n160->val = v;
            n160->val2 = v;
            sub2->f208 = sub2->n168->val;
            int v2 = sub2->n16c->val;
            Node *n164 = sub2->n164;
            n164->val = v2;
            n164->val2 = v2;
            sub2->f20c = sub2->n16c->val;
            self->f14c = 0;
        }
        self->v2();
        self->f150++;
    }
}
