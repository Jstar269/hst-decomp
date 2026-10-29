/* HSTMATCH module=EBOOT.BIN start=0x000bcc88 end=0x000bcd8c symbol=FUN_000bcc88 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/member_session.h"

extern int FUN_0001100c(const void *a, const void *b, int n);
extern void FUN_00011090(void *dst, const void *src, int n);
extern int FUN_000bdb14(MemberSession *self, int a, char *b, unsigned short c, void *d, int e, int f, int g);
extern void FUN_000ba3ac(void *msg, ...);
extern char DAT_002d53a4[];

enum { CMD_MEMBER_QUERY = 3, MSG_SIZE = 20 };

typedef struct Msg {
    int cmd;
    int size;
    MemberPos pos;
    int idx;
} Msg;

/* Index of the used member whose name equals key, or -1. */
static inline int FindMember(MemberSession *self, MemberName *key)
{
    int idx = 0;
    while (idx < MEMBER_MAX) {
        if (self->members[idx].used != 0) {
            if (FUN_0001100c(&self->members[idx].name, key, 6) == 0)
                return idx;
        }
        idx++;
    }
    return -1;
}

void FUN_000bcc88(MemberSession *self)
{
    if (self->unk178 != 0) {
        self->flags[0] = 1;
        return;
    }
    Msg msg;
    msg.cmd = CMD_MEMBER_QUERY;
    msg.pos = self->pos;
    MemberName *key = &self->key;
    msg.idx = FindMember(self, key);
    msg.size = MSG_SIZE;
    FUN_00011090(self->packet, &msg, MSG_SIZE);
    int r = FUN_000bdb14(self, self->unk17c, self->unk3e, (unsigned)self->unk10,
                         self->packet, msg.size, 0, 1);
    if (r < 0)
        FUN_000ba3ac(DAT_002d53a4, r);
}
