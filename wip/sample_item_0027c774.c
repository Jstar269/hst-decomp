/* HSTMATCH module=EBOOT.BIN start=0x0027c774 end=0x0027c8a0 symbol=FUN_0027c774 lang=c99 */
/* WIP Near-miss: 75/75 words; 33 differ.
 * The second half (sampling loop, random calculation, return epilogue at 0x27c828 - 0x27c89c)
 * matches retail 100%. The remaining difference is register scheduling in the prologue and
 * zeroing loops: retail reuses $v1 for the pointer in both zeroing loops and allocates $a1-$a3
 * in a specific sequence for the item table collection loop.
 */

extern int DAT_0034a7e4;
extern int FUN_0001342c(void);

int FUN_0027c774(int param_1, int param_2)
{
    int indices[128];
    int weights[128];
    int target;
    int count;
    int *entry;
    int *piVar1;
    int *piVar2;
    int *piVar3;
    int *p_ind;
    int *p_wt;
    int total_weight;
    int entry_ptr;
    int i;
    int rand_val;
    int j;

    target = DAT_0034a7e4;
    entry = (int *)(target + param_2 * 64);
    target = entry[12];
    count = entry[15];

    piVar2 = (int *)0x200;
    piVar3 = indices;
    piVar1 = piVar3;
    while (piVar1 != (int *)0x0) {
        *(char *)piVar3 = 0;
        piVar3 = (int *)((int)piVar3 + 1);
        piVar2 = (int *)((int)piVar2 - 1);
        piVar1 = piVar2;
    }

    piVar2 = (int *)0x200;
    piVar3 = weights;
    piVar1 = piVar3;
    while (piVar1 != (int *)0x0) {
        *(char *)piVar3 = 0;
        piVar3 = (int *)((int)piVar3 + 1);
        piVar2 = (int *)((int)piVar2 - 1);
        piVar1 = piVar2;
    }

    total_weight = 0;
    i = 0;
    p_ind = indices;
    p_wt = weights;
    entry_ptr = DAT_0034a7e4;
    do {
        if (target == *(int *)(entry_ptr + 0x30)) {
            *p_ind = i;
            *p_wt = 100;
            total_weight += *p_wt;
            p_ind++;
            p_wt++;
        }
        i++;
        entry_ptr += 64;
    } while (i < 128);

    if (total_weight < 1) {
        return -1;
    }

    rand_val = FUN_0001342c();
    rand_val = rand_val % total_weight;
    j = 0;
    if (count > 0) {
        p_wt = weights;
        do {
            if (rand_val < *p_wt) {
                param_2 = indices[j];
                break;
            }
            rand_val -= *p_wt;
            j++;
            p_wt++;
        } while (j < count);
    }

    return param_2;
}
// near miss from lane u5fr4-0 (unreviewed)
