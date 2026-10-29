/* HSTMATCH module=EBOOT.BIN start=0x00286f2c end=0x002872a0 symbol=FUN_00286f2c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/cmd_actor.h"

/* One queued command: type id, remaining delay in frames, and four argument words (int or float by type). */
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

struct EraseResult {
    Node *p;
    int pad;
};

/* Command type ids that have a handler. */
enum {
    CMD_DIALOGUE_ACTION = 0x34,
    CMD_BGM_VOLUME = 0x49,
    CMD_MODE_REQUEST = 0x52
};

extern "C" {
int FUN_002890c0(CmdActor *);
void FUN_00288624(CmdActor *, int, int);
void FUN_002885dc(CmdActor *, int, int, float);
void FUN_00288594(CmdActor *, int, int, float);
void FUN_00288470(CmdActor *, int, float);
void FUN_00288414(CmdActor *, float, int, int);
void FUN_00288350(CmdActor *, int, int);
void FUN_00288208(CmdActor *, int, int, unsigned, int);
void FUN_00287ff0(CmdActor *, int, int, int, int, unsigned);
void FUN_00287de4(CmdActor *, int, int, int);
void FUN_00287c60(CmdActor *, int, int, int, float);
void FUN_00287b30(CmdActor *, int, int, int, float);
void FUN_002879e0(CmdActor *, int, float, int, int, int);
void FUN_0028797c(CmdActor *, int, int);
void FUN_00287924(CmdActor *, int, int);
void FUN_002878cc(CmdActor *, int, int);
void FUN_002876a0(CmdActor *, int, int, int);
void FUN_002875f8(CmdActor *, int, unsigned, int);
void FUN_002874c4(CmdActor *, int, int, unsigned, unsigned, int);
void FUN_002894d4(EraseResult *, void *, Node **);
}

/* Runs the queued commands: each tick counts a command's delay down and, once it reaches zero,
   calls the handler for its type and removes it from the list. */
extern "C" void FUN_00286f2c(CmdActor *self)
{
    Node *n = (Node *)self->head.next;
    Node *end = (Node *)&self->head;
    while (n != end) {
        Cmd *c = &n->v;
        int t = c->type;
        switch (t) {
        case CMD_BGM_VOLUME:
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
            case CMD_BGM_VOLUME:
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
            case CMD_DIALOGUE_ACTION:
                FUN_00288208(self, c->a, c->b, c->c == 1, 0);
                break;
            case CMD_MODE_REQUEST:
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
            EraseResult out;
            Node *pos = n;
            FUN_002894d4(&out, self->alloc64, &pos);
            n = out.p;
        } else {
            n = n->next;
        }
    }
}
