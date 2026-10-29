/* Result screen widget row: five widget objects stored in consecutive words of the screen object. */
#ifndef HST_RESULT_WIDGETS_H
#define HST_RESULT_WIDGETS_H

#define RESULT_WIDGET_COUNT 5

typedef struct ResultWidget {
  char pad00[0x60];
  float unk60;                                 /* 0x60 */
} ResultWidget;

typedef struct ResultWidgetTable {
  char pad00[0x1d6c];
  ResultWidget *widget[RESULT_WIDGET_COUNT];   /* 0x1d6c */
} ResultWidgetTable;

#endif
