/* HSTMATCH module=EBOOT.BIN start=0x0028ad5c end=0x0028adc4 symbol=FUN_0028ad5c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item { char pad[8]; float f8; };
struct Node { Item *item; };
struct Sub { char pad[0xf4]; Node *node; };
struct Obj { char pad[0x74]; Sub *sub; char pad78[0xec - 0x78]; unsigned char fec; };
extern "C" {
void FUN_00058f38(Sub *, float, int);
void FUN_0005f110(Sub *, float);
void FUN_0028adc4(Obj *);
}
extern "C" void FUN_0028ad5c(Obj *param_1)
{
    FUN_0028adc4(param_1);
    param_1->fec = 1;
    Sub *s = param_1->sub;
    float f = s->node != 0 ? s->node->item->f8 : 0.0f;
    FUN_00058f38(s, f, -1);
    FUN_0005f110(s, f);
}
