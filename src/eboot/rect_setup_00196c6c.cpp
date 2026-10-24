/* HSTMATCH module=EBOOT.BIN start=0x00196c6c end=0x00196ef4 symbol=FUN_00196c6c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct RectParams {
    int f0;
    int x;
    int y;
    float w;
    float h;
};

struct Elem {
    int f0;
    short x;
    short y;
    short x2;
    short y2;
    char pad[0x24 - 12];
    int f24;
    int f28;
};

struct Quad { int v[4]; };
extern const Quad DAT_002e17d0;
extern "C" void FUN_000ffb3c(void *, int);

inline void SetupRect(Elem *elem, const RectParams *p) {
    elem->x = (short)p->x;
    elem->y = (short)(p->y - 3);
    elem->x2 = elem->x + (int)(p->w * 20.0f);
    elem->y2 = elem->y + (int)(p->h * 20.0f);
}

extern "C" void FUN_00196c6c(void *param_1, int *param_2, int *param_3, int param_4, const RectParams *param_5) {
    if (*param_2 < 6) {
        int off = *param_2 * 4;
        Elem *elem = *(Elem **)((char *)off + (int)param_1 + 4);
        FUN_000ffb3c(elem, 0);
        SetupRect(elem, param_5);
        (*param_2)++;
    }

    if (param_4 == 10) {
        Quad local = DAT_002e17d0;
        int i = 0;
        int *p_val = local.v;
        do {
            if (*param_3 < 12) {
                char *base = (char *)param_1 + (*param_3 + 18) * 4;
                Elem *elem = *(Elem **)(base + 4);
                FUN_000ffb3c(elem, 0);
                int val = *(int *)(base + 0x7c) + *p_val;
                elem->f24 = val;
                elem->f28 = val;
                SetupRect(elem, param_5);
                (*param_3)++;
            }
            i++;
            p_val++;
        } while (i < 4);
    } else if (param_4 != 9 && *param_3 < 12) {
        int off = (*param_3 + 18) * 4;
        Elem *elem = *(Elem **)((char *)off + (int)param_1 + 4);
        FUN_000ffb3c(elem, 0);
        int val = *(int *)(off + (int)param_1 + 124);
        val = val + param_4;
        elem->f24 = val;
        elem->f28 = val;
        SetupRect(elem, param_5);
        (*param_3)++;
    }
}
