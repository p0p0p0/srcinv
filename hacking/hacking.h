/*
 * TODO
 * Copyright (C) 2019  zerons
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef HACKING_H_IEAV6TPU
#define HACKING_H_IEAV6TPU

#include "si_core.h"

DECL_BEGIN

C_SYM struct list_head hacking_module_head;
enum hacking_flag {
	HACKING_FLAG_NONE,
	HACKING_FLAG_STATIC,
	HACKING_FLAG_FUZZ,
	HACKING_FLAG_OTHER,
};

/*
 * handle all hacking modules, fuzz type module are at last
 */
struct hacking_module {
	struct list_head	sibling;
	char			*name;
	enum hacking_flag	flag;
	void			(*callback)(void);
};

static inline struct hacking_module *hacking_module_find(struct list_head *h,
							 struct hacking_module *m)
{
	struct hacking_module *tmp;
	list_for_each_entry(tmp, h, sibling) {
		if (tmp->callback == m->callback)
			return tmp;
	}
	return NULL;
}

static inline void register_hacking_module(struct hacking_module *m)
{
	struct list_head *h = &hacking_module_head;
	if (hacking_module_find(h, m))
		return;
	if (m->flag == HACKING_FLAG_FUZZ)
		list_add_tail(&m->sibling, h);
	else
		list_add(&m->sibling, h);
}

static inline void unregister_hacking_module(struct hacking_module *m)
{
	list_del_init(&m->sibling);
}

DECL_END

#endif /* end of include guard: HACKING_H_IEAV6TPU */
