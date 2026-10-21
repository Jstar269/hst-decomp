/* HSTMATCH module=EBOOT.BIN start=0x00286f2c end=0x002872a0 symbol=FUN_00286f2c lang=c++ */
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
void FUN_00288414(Self *, int, int, float);
void FUN_00288350(Self *, int, int);
void FUN_00288208(Self *, int, int, unsigned, int);
void FUN_00287ff0(Self *, int, int, int, int, unsigned);
void FUN_00287de4(Self *, int, int, int);
void FUN_00287c60(Self *, int, int, int, float);
void FUN_00287b30(Self *, int, int, int, float);
void FUN_002879e0(Self *, int, int, int, int, float);
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
        if (t == 0x49) {
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
                FUN_002879e0(self, c->a, c->c, 0, 0, c->fb);
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
                FUN_00288414(self, c->b, 0, c->fa);
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
// Near miss (sn5; 219 vs 221 words, dispatch body right): the command-queue runner. Everything after the head matches word for word apart from the 2-word shift.
// Idioms found: the node is {prev, next, Cmd v} and the commands are read through `Cmd *c = &n->v` (retail keeps s2 = node, s0 = node + 8), `Node *end = &self->sentinel` held in a
// register (s1), the 17-way type dispatch is a SWITCH written in reverse of retail's test order (0x24 first ... 0x23 last: tests then come out 0x23, 0x57, ...) with the
// float arguments of the callees (n->0x10/0x14/0x1c) loaded into $f12, `Out out; Node *pos = n; FUN_002894d4(&out, self->list, &pos); n = out.p;` with an 8-byte Out declared before pos.
// Open: the head. Retail: `beq type,0x49,L1 ; slot addiu s0,s2,8 ; b DEC ; slot lw v1,4(s0)` then L1: `jal 2890c0 ; beqz v0,DEC0 ; nop ; b END ; slot lw s2,4(s2)` with DEC0 = `lw v1,4(s0)`
// and DEC = `addiu v1,v1,-1`; ours converts the post-call branch to a likely branch (`beqzl v0,..; slot lw v1,4(s0)`) and tests `bne` first (2 words shorter).
// Ruled out: && / || / nested / continue / goto spellings of the 0x49 test.
// near miss from lane sn5 (unreviewed)
