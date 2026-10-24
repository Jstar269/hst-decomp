/* HSTMATCH module=EBOOT.BIN start=0x0017d910 end=0x0017dab8 symbol=FUN_0017d910 lang=c99 */
#pragma opt_strength_reduction off

typedef struct Inner { char pad[0x68]; void *f68; } Inner;
typedef struct Obj { char pad[8]; Inner **f8; char pad1[0x2d8]; int f2e4; } Obj;

int FUN_0016bb88(void);
int FUN_0016bc70(void);
int FUN_001fe984(void *param_1, int param_2, int param_3);
void FUN_000931ec(void *param_1, int param_2, const unsigned char *flags, unsigned char flag);
float FUN_0017dab8(void *param_1, int param_2);
void FUN_00093484(void *param_1, float param_2);
void FUN_000575fc(void *param_1, int param_2, unsigned char flag);
void FUN_0017d910(Obj *self, int param_2);

void FUN_0017d910(Obj *self, int param_2)
{
    int i;
    unsigned char flag = 0;
    int base = FUN_0016bb88();
    unsigned char c = 1;
    if (param_2 < 0) {
        c = 1;
    } else if (param_2 < 15) {
        c = *(unsigned char *)(param_2 + base + 0x1025);
    } else {
        c = 1;
    }
    if (c == 2) {
        flag = 1;
    }

    i = 0;
    do {
        int ctx = FUN_0016bc70();
        int itemInfo = ((int (*)(int, int))(*(int *)(ctx + 0x3ec)))(param_2, i);
        unsigned char b1 = (*(unsigned char *)(itemInfo + 10) != 0);
        unsigned char b2 = (*(unsigned char *)(itemInfo + 9) != 0);

        if (FUN_001fe984(&self->f2e4, i, 0) == 0) {
            unsigned char flags[2];
            flags[0] = 0;
            flags[1] = 0;
            flags[0] = b2;
            flags[1] = b1;

            void *item = self->f8[i];
            FUN_000931ec((char *)item + 0x10, 1, flags, flag);
            float f = FUN_0017dab8(self, i);
            FUN_00093484((char *)item + 0x10, f);
            ((void (*)(void *))(*(int *)(*(int *)((char *)item + 0x10) + 0xc)))((char *)item + 0x10);
        }

        if (FUN_001fe984(&self->f2e4, i, 0) == 0) {
            void *item = self->f8[i];
            void *sub68 = ((Inner *)item)->f68;
            if (sub68 != 0) {
                int k = 0;
                do {
                    FUN_000575fc(sub68, k, flag);
                    k++;
                } while (k < 6);
            }
        }
        i++;
    } while (i < 4);
}
// near miss from lane ag3 (unreviewed)
