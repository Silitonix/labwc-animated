#ifndef RCXML_H
#define RCXML_H

#include <stdio.h>
#include <stdbool.h>
#include <wlr/types/wlr_keyboard.h>
#include <wayland-server-core.h>
#include <xkbcommon/xkbcommon.h>

#include "buf.h"

struct keybind {
        uint32_t modifiers;
        xkb_keysym_t *keysyms;
        size_t keysyms_len;
        char *action;
        struct wl_list link;
};

void keybind_add(struct wl_list *keybinds, const char *keybind, const char *action);
void keybind_init();
void keybind_print();

struct rcxml {
	bool client_side_decorations;
	struct wl_list keybinds;
};

extern struct rcxml rc;

void rcxml_init();
void rcxml_parse_xml(struct buf *b);
void rcxml_read(const char *filename);
void rcxml_get_nodenames(struct buf *b);

#endif /* RCXML_H */