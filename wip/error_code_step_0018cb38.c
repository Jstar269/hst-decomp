/* HSTMATCH module=EBOOT.BIN start=0x0018cb38 end=0x0018cd90 symbol=FUN_0018cb38 lang=c99 */
extern void FUN_0018cd90(const char *fmt, ...);
extern char DAT_002e11d4[];
extern char DAT_002e1208[];

int FUN_0018cb38(unsigned int code)
{
    int r = 0;

    switch (code) {
    case 0:
        break;
    case 0x80110301:
    case 0x80110381:
    case 0x80110341:
    case 0x801103c1:
    case 1:
        r = 1;
        break;
    case 2:
        r = 1;
        break;
    case 0x80110302:
    case 0x80110382:
    case 0x80110342:
    case 0x801103c2:
        r = 2;
        break;
    case 0x80110383:
        r = 3;
        break;
    case 0x80110384:
        r = 4;
        break;
    case 0x80110344:
        r = 4;
        break;
    case 0x80110305:
    case 0x80110385:
    case 0x80110345:
    case 0x801103c5:
        r = 5;
        break;
    case 0x80110306:
    case 0x80110386:
    case 0x801103c6:
        r = 6;
        break;
    case 0x80110307:
    case 0x80110347:
    case 0x801103c7:
        r = 7;
        break;
    case 0x80110308:
    case 0x80110388:
    case 0x80110348:
    case 0x801103c8:
        r = 8;
        break;
    case 0x8011030b:
    case 0x8011038b:
    case 0x8011034b:
        r = 9;
        break;
    case 0x801103cb:
        r = 9;
        break;
    case 0x80110309:
        r = 10;
        break;
    default:
        FUN_0018cd90(DAT_002e11d4, code);
        break;
    }
    FUN_0018cd90(DAT_002e1208, code, r);
    return r;
}
// NEAR 66/150 words, function 0x0018cb38 (batch fm4-00 #24). Only branch TARGETS differ; the whole
// compare chain is instruction-identical.
// Shape: a SWITCH on the 32-bit code, not an if/else chain (an if/else chain gives inline arms with
// `bne ... next`; the switch gives retail's linear `beq s1,v1,ARM` chain). MWCC tests the labels in the
// REVERSE of the source order and lays the case bodies out in source order, so the cases are written
// with the group labels listed as 0x...30b, 0x...38b, 0x...34b (plus a separate 0x...3cb case before
// them) to obtain retail's test order 3cb,34b,38b,30b. Codes: 0x80110309 -> 10; {3cb,34b,38b,30b} -> 9;
// {3c8,348,388,308} -> 8; {3c7,347,307} -> 7; {3c6,386,306} -> 6; {3c5,345,385,305} -> 5; {344,384} -> 4;
// {383} -> 3; {3c2,342,382,302} -> 2; {2,1,3c1,341,381,301} -> 1; 0 -> leave 0; default -> the
// "unhandled TransErrorCode" print. Then one always-executed print of code+step and `return r`.
// Still different: retail keeps a block per value 1..10 (ascending) including an UNREFERENCED one for 3,
// and the first label of each group uses `beql JOIN; li s0,k` (value in the delay slot) while ours points
// that branch at the value block instead; the resulting block offsets shift every target.
// near miss from lane fm4 (unreviewed)
