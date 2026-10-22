/* HSTMATCH module=EBOOT.BIN start=0x00286f2c end=0x002872a0 symbol=FUN_00286f2c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Cmd {
    int type;
    int count;
    union { int a; float fa; };
    union { int b; float fb; };
    union { int c; float fc; };
    union { int d; float fd; };
};

struct Node {
    Node *prev;
    Node *next;
    Cmd v;
};

struct Out {
    Node *p;
    int pad;
};

struct Self {
    char pad0[0x64];
    char list[4];
    Node sentinel_hdr;
};

extern "C" {
int FUN_002890c0(Self *);
void FUN_00288624(Self *, int, int);
void FUN_002885dc(Self *, int, int, float);
void FUN_00288594(Self *, int, int, float);
void FUN_00288470(Self *, int, float);
void FUN_00288414(Self *, float, int, int);
void FUN_00288350(Self *, int, int);
void FUN_00288208(Self *, int, int, unsigned, int);
void FUN_00287ff0(Self *, int, int, int, int, unsigned);
void FUN_00287de4(Self *, int, int, int);
void FUN_00287c60(Self *, int, int, int, float);
void FUN_00287b30(Self *, int, int, int, float);
void FUN_002879e0(Self *, int, float, int, int, int);
void FUN_0028797c(Self *, int, int);
void FUN_00287924(Self *, int, int);
void FUN_002878cc(Self *, int, int);
void FUN_002876a0(Self *, int, int, int);
void FUN_002875f8(Self *, int, unsigned, int);
void FUN_002874c4(Self *, int, int, unsigned, unsigned, int);
void FUN_002894d4(Out *, void *, Node **);
}

extern "C" void FUN_00286f2c(Self *self)
{
    Node *n = self->sentinel_hdr.next;
    Node *end = &self->sentinel_hdr;
    while (n != end) {
        Cmd *c = &n->v;
        int t = c->type;
        switch (t) {
        case 0x49:
            if (FUN_002890c0(self) != 0) {
                n = n->next;
                continue;
            }
        }
        int cnt = c->count;
        c->count = cnt - 1;
        if (cnt - 1 < 1) {
            switch (c->type) {
            case 0x24:
                FUN_002874c4(self, c->a, c->b, c->c == 1, c->d == 1, 0);
                break;
            case 0x3d:
                FUN_002875f8(self, c->a, c->b == 1, 0);
                break;
            case 0x39:
                FUN_002876a0(self, c->a, c->b, 0);
                break;
            case 0x32:
                FUN_002878cc(self, c->a, 0);
                break;
            case 0x33:
                FUN_00287924(self, c->a, 0);
                break;
            case 0x4c:
                FUN_0028797c(self, c->a, 0);
                break;
            case 0x49:
                FUN_002879e0(self, c->a, c->fb, c->c, 0, 0);
                break;
            case 0x4f:
                if (c->a == 3) {
                    FUN_00287c60(self, c->b, c->c, 0, c->fd);
                } else {
                    FUN_00287b30(self, c->b, c->c, 0, c->fd);
                }
                break;
            case 0x2f:
                FUN_00287de4(self, c->a, c->b, 0);
                break;
            case 0x42:
                FUN_00287ff0(self, c->a, 0, c->b, 0, c->c == 1);
                break;
            case 0x34:
                FUN_00288208(self, c->a, c->b, c->c == 1, 0);
                break;
            case 0x52:
                FUN_00288350(self, c->a, 0);
                break;
            case 0x4e:
                FUN_00288414(self, c->fa, c->b, 0);
                break;
            case 0x55:
                FUN_00288470(self, 0, c->fa);
                break;
            case 0x56:
                FUN_00288594(self, c->a, 0, c->fb);
                break;
            case 0x57:
                FUN_002885dc(self, c->a, 0, c->fb);
                break;
            case 0x23:
                FUN_00288624(self, c->a, 0);
                break;
            }
            Out out;
            Node *pos = n;
            FUN_002894d4(&out, self->list, &pos);
            n = out.p;
        } else {
            n = n->next;
        }
    }
}
