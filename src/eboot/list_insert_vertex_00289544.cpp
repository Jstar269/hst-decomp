/* HSTMATCH module=EBOOT.BIN start=0x00289544 end=0x00289654 symbol=FUN_00289544 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned size);
struct Reent_00289544 { int pad[3]; void *err; };
Reent_00289544 *FUN_0000fe3c(void);
void FUN_00286acc(void *err, char *msg);
void FUN_0000d518(void);
void FUN_00000a00(void *);
extern char DAT_002cab00[];
}
inline void *operator new(unsigned, void *p) { return p; }
struct Vec6_00289544 { float x, y, z, w, u, v; };
struct Node_00289544 { Node_00289544 *next; Node_00289544 *prev; Vec6_00289544 v; };
struct Guard_00289544 { int *p; Node_00289544 *n; ~Guard_00289544() { if (n) FUN_00000a00(n); } };
extern "C" int FUN_00289544(Node_00289544 **out, int *count, Node_00289544 **head, const Vec6_00289544 *src)
{
    int *cp = count + 1;
    Node_00289544 *n = (Node_00289544 *)FUN_00000bcc(0x20);
    if (n == 0) {
        FUN_00286acc(FUN_0000fe3c()->err, DAT_002cab00);
        FUN_0000d518();
    }
    Guard_00289544 g;
    g.p = cp;
    g.n = n;
    new (&n->v) Vec6_00289544(*src);
    g.n = 0;
    Node_00289544 *h = *head;
    h->next->prev = n;
    n->next = h->next;
    h->next = n;
    n->prev = h;
    *count = *count + 1;
    *out = n;
    return 0;
}
