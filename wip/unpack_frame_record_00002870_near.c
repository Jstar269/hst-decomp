/* HSTMATCH module=EBOOT.BIN start=0x00002870 end=0x000029e8 symbol=FUN_00002870 lang=c99 */
struct Stream {
    char pad[4];
    char *p;
};

struct VM {
    char pad_0[0x14];
    int f_14;
    int f_18;
    char pad_1c[0x44];
    int slots[14];
    int f_98;
    int f_9c;
    int f_a0;
    int f_a4;
    int f_a8;
    int f_ac;
    int f_b0;
    int f_b4;
    char pad_b8[0x50];
    int fregs[12];
};

int FUN_00002870(struct VM *self, struct Stream *stream)
{
    char *p = stream->p;
    unsigned int n = self->f_a8;
    char c = *p;
    int old = self->f_a0;
    unsigned int flag = c & 0x40;
    int off = self->f_a4;
    unsigned int cnt;
    char *base;
    char *end;
    int result;

    if (flag) {
        cnt = self->f_b4;
        base = (char *)(self->f_18 + off) + ((cnt * 4 + 15) & ~15);
        if (self->f_b0)
            end = base + (((n + 2) * 4 + 15) & ~15) - 4;
        else
            end = base + (((n + 1) * 4 + 15) & ~15) - 4;
    } else {
        if (self->f_b0)
            end = (char *)(off + self->f_18 + (((n + 2) * 4 + 15) & ~15)) - 4;
        else
            end = (char *)(off + self->f_18 + (((n + 1) * 4 + 15) & ~15)) - 4;
    }
    result = *(int *)end;
    if (self->f_b0) {
        end -= 4;
        self->f_98 = *(int *)end;
    } else if (n == 9) {
        end -= 4;
        self->f_98 = *(int *)end;
        n--;
    }
    end -= n * 4;
    {
        int i;
        for (i = 0; i < n; i++) {
            self->slots[i] = *(int *)end;
            end += 4;
        }
    }
    self->f_14 = self->f_18 + old;
    if (flag) {
        base -= cnt * 4;
        {
            int i;
            for (i = 0; i < cnt; i++) {
                self->fregs[i] = *(int *)base;
                base += 4;
            }
        }
    }
    return result;
}
// near miss from lane oc4 (unreviewed)
