/* HSTMATCH module=hstp_trans_main.prx start=0x0029c550 end=0x0029c5b8 symbol=FUN_0029c550 lang=c++ */
/* Clone of src/eboot/set_flag_apply_item_value_0028ad5c.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item { char pad[8]; float f8; };
struct Node { Item *item; };
struct Sub { char pad[0xf4]; Node *node; };
struct Obj { char pad[0x74]; Sub *sub; char pad78[0xec - 0x78]; unsigned char fec; };
extern "C" {
void FUN_00059c1c(Sub *, float, int);
void FUN_0005ff00(Sub *, float);
void FUN_0029c5b8(Obj *);
}
extern "C" void FUN_0029c550(Obj *param_1)
{
    FUN_0029c5b8(param_1);
    param_1->fec = 1;
    Sub *s = param_1->sub;
    float f = s->node != 0 ? s->node->item->f8 : 0.0f;
    FUN_00059c1c(s, f, -1);
    FUN_0005ff00(s, f);
}
