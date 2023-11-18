// default_value.c
#include "default_value.h"

default_value* make_def_val_num(int num) {
    default_value *dv = (default_value *)malloc(sizeof(default_value));
    if (dv) {
        dv->is_num = 1;
        dv->num_val = num;
    }
    return dv;
}

default_value* make_def_val_str(const char* str) {
    default_value *dv = (default_value *)malloc(sizeof(default_value));
    if (dv) {
        dv->is_num = 0;
        dv->str_val = strdup(str);
    }
    return dv;
}
