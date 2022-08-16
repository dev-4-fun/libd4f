#include <stdlib.h>
#include <string.h>

#define D4F__STRING_IMPORT
#include "d4f__string.h"
#undef D4F__STRING_IMPORT

d4f__String d4f__String_create(const char* string) {
    size_t length = strlen(string);

    char* self = malloc((length + 1) * sizeof(char));
    if (self == NULL) {
        return NULL;
    }

    memcpy(self, string, length);
    self[length] = 0;

    return self;
}

void d4f__String_destroy(d4f__String self) {
    if (self == NULL) {
        return;
    }

    free(self);
    self = NULL;
}

const char* d4f__String_get(const d4f__String self) {
    return self;
}

d4f__BOOL d4f__String_equals(const d4f__String self, const d4f__String string) {
    return (strcmp(self, string) == 0);
}
