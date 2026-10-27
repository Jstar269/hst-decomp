/* HSTMATCH module=hstp_trans_main.prx start=0x0006c96c end=0x0006ca68 symbol=FUN_0006c96c lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the sibling list insert src/sharing_main/list_insert_0028b678.cpp: 192-byte node whose 16-aligned 176-byte payload is built through the out-of-line placement new FUN_00002f60 and the out-of-line copy constructor FUN_0006ca68, so the guard node is re-read after those calls); exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned size);
struct Reent_0006c96c { int pad[3]; void *err; };
Reent_0006c96c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_00000a00(void *);
void *FUN_00002f60(unsigned size, void *p);
void *FUN_0006ca68(void *dst, const void *src);
extern char DAT_002cc5a0[];
}
struct Value_0006c96c { char b[176]; } __attribute__((aligned(16)));
struct Node_0006c96c { Node_0006c96c *next; Node_0006c96c *prev; Value_0006c96c v; };
struct Guard_0006c96c { int *p; Node_0006c96c *n; ~Guard_0006c96c() { if (n) FUN_00000a00(n); } };
extern "C" int FUN_0006c96c(Node_0006c96c **out, int *count, Node_0006c96c **head, const Value_0006c96c *src)
{
    int *cp = count + 1;
    Node_0006c96c *n = (Node_0006c96c *)FUN_00000bcc(0xc0);
    if (n == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc5a0);
        FUN_0000d530();
    }
    Guard_0006c96c g;
    g.p = cp;
    g.n = n;
    void *q = FUN_00002f60(sizeof(Value_0006c96c), &n->v);
    if (q != 0)
        FUN_0006ca68(q, src);
    Node_0006c96c *m = g.n;
    g.n = 0;
    Node_0006c96c *h = *head;
    h->next->prev = m;
    m->next = h->next;
    h->next = m;
    m->prev = h;
    *count = *count + 1;
    *out = m;
    return 0;
}
