/* HSTMATCH module=hstp_trans_main.prx start=0x00298628 end=0x0029899c symbol=FUN_00298628 lang=c++ */
/* Clone of src/eboot/cmd_queue_run_00286f2c.cpp (hstclone.py tag c23fbop): addresses substituted; exact match verified; names and types await human review. */
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
int FUN_0029a85c(Self *);
void FUN_00299d58(Self *, int, int);
void FUN_00299d10(Self *, int, int, float);
void FUN_00299cc8(Self *, int, int, float);
void FUN_00299ba4(Self *, int, float);
void FUN_00299b48(Self *, float, int, int);
void FUN_00299a84(Self *, int, int);
void FUN_0029993c(Self *, int, int, unsigned, int);
void FUN_00299724(Self *, int, int, int, int, unsigned);
void FUN_00299518(Self *, int, int, int);
void FUN_00299394(Self *, int, int, int, float);
void FUN_00299264(Self *, int, int, int, float);
void FUN_00299114(Self *, int, float, int, int, int);
void FUN_002990b0(Self *, int, int);
void FUN_00299058(Self *, int, int);
void FUN_00299000(Self *, int, int);
void FUN_00298d9c(Self *, int, int, int);
void FUN_00298cf4(Self *, int, unsigned, int);
void FUN_00298bc0(Self *, int, int, unsigned, unsigned, int);
void FUN_0029ac70(Out *, void *, Node **);
}

extern "C" void FUN_00298628(Self *self)
{
    Node *n = self->sentinel_hdr.next;
    Node *end = &self->sentinel_hdr;
    while (n != end) {
        Cmd *c = &n->v;
        int t = c->type;
        switch (t) {
        case 0x49:
            if (FUN_0029a85c(self) != 0) {
                n = n->next;
                continue;
            }
        }
        int cnt = c->count;
        c->count = cnt - 1;
        if (cnt - 1 < 1) {
            switch (c->type) {
            case 0x24:
                FUN_00298bc0(self, c->a, c->b, c->c == 1, c->d == 1, 0);
                break;
            case 0x3d:
                FUN_00298cf4(self, c->a, c->b == 1, 0);
                break;
            case 0x39:
                FUN_00298d9c(self, c->a, c->b, 0);
                break;
            case 0x32:
                FUN_00299000(self, c->a, 0);
                break;
            case 0x33:
                FUN_00299058(self, c->a, 0);
                break;
            case 0x4c:
                FUN_002990b0(self, c->a, 0);
                break;
            case 0x49:
                FUN_00299114(self, c->a, c->fb, c->c, 0, 0);
                break;
            case 0x4f:
                if (c->a == 3) {
                    FUN_00299394(self, c->b, c->c, 0, c->fd);
                } else {
                    FUN_00299264(self, c->b, c->c, 0, c->fd);
                }
                break;
            case 0x2f:
                FUN_00299518(self, c->a, c->b, 0);
                break;
            case 0x42:
                FUN_00299724(self, c->a, 0, c->b, 0, c->c == 1);
                break;
            case 0x34:
                FUN_0029993c(self, c->a, c->b, c->c == 1, 0);
                break;
            case 0x52:
                FUN_00299a84(self, c->a, 0);
                break;
            case 0x4e:
                FUN_00299b48(self, c->fa, c->b, 0);
                break;
            case 0x55:
                FUN_00299ba4(self, 0, c->fa);
                break;
            case 0x56:
                FUN_00299cc8(self, c->a, 0, c->fb);
                break;
            case 0x57:
                FUN_00299d10(self, c->a, 0, c->fb);
                break;
            case 0x23:
                FUN_00299d58(self, c->a, 0);
                break;
            }
            Out out;
            Node *pos = n;
            FUN_0029ac70(&out, self->list, &pos);
            n = out.p;
        } else {
            n = n->next;
        }
    }
}
