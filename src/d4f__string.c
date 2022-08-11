#include <stdlib.h>
#include <string.h>

char* d4f__String_create(const char* c_str) {
    size_t c_str_len = strlen(c_str);

    char* str = malloc((c_str_len + 1) * sizeof(char));
    if (str == NULL) {
        return NULL;
    }

    memcpy(str, c_str, c_str_len);
    str[c_str_len] = 0;

    return str;
}

void d4f__String_destroy(char* self) {
    if (self == NULL) {
        return;
    }

    free(self);
}
