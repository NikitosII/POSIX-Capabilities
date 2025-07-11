// программа 2 просмотра и установки «возможностей»
#include <stdio.h>
#include <stdlib.h>
#include <sys/capability.h>
#include <unistd.h>

void func1(const char *path) {
    cap_t caps = cap_get_file(path);
    if (caps == NULL) {
        perror("cap_get_file");
        return;
    }
    char *text = cap_to_text(caps, NULL);
    if (text == NULL) {
        perror("cap_to_text");
        cap_free(caps);
        return;
    }
    printf("Capabilities of %s: %s\n", path, text);
    cap_free(text);
    cap_free(caps);
}

void func2(const char *path, const char *cap_text) {
    cap_t caps = cap_from_text(cap_text);
    if (caps == NULL) {
        perror("cap_from_text");
        return;
    }
    if (cap_set_file(path, caps) == -1) {
        perror("cap_set_file");
        cap_free(caps);
        return;
    }
    cap_free(caps);
    printf("Capabilities set successfully for %s\n", path);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <program_path> <cap_text>\n", argv[0]);
        return 1;
    }

    const char *program_path = argv[1];
    const char *cap_text = argv[2];

    func1(program_path);
    func2(program_path, cap_text);
    func1(program_path);

    return 0;
}
