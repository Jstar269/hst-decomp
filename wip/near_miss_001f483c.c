/* HSTMATCH module=EBOOT.BIN start=0x001f483c end=0x001f4900 symbol=FUN_001f483c lang=c99 */
/* Near miss: 48/49 words; loop and condition logic matched; prologue branch scheduling remaining */

extern int DAT_003313c4;
extern void FUN_00049774(void);
extern void FUN_00064194(int, void *);

struct Inner {
    char pad0[8];
    float val;
};

struct Item {
    char pad0[244];
    struct Inner **inner_ptr;
    char padf8[12];
    float val;
};

struct Container {
    char pad0[344];
    int start;
    int end;
};

struct Obj {
    char pad0[960];
    struct Container **container_ptr;
};

void FUN_001f483c(struct Obj *param_1)
{
    struct Container **cp = param_1->container_ptr;
    if (!cp) {
        return;
    }

    struct Container *c = *cp;
    int i = c->start;
    int ok;

    if (c->end < i) {
        ok = 1;
    } else {
        struct Item *item = (struct Item *)((char *)c + i * 52);
        do {
            float limit = 0.0f;
            if (item->inner_ptr != 0) {
                limit = (*item->inner_ptr)->val;
            }
            if (item->val < limit) {
                ok = 0;
                goto done;
            }
            i++;
            item = (struct Item *)((char *)item + 52);
        } while (i <= c->end);
        ok = 1;
    }

done:
    if (!ok) {
        FUN_00049774();
    }
    FUN_00064194(DAT_003313c4, param_1->container_ptr);
}
// near miss from lane u6fr1-0 (unreviewed)
