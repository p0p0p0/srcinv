/*
 * XXX: put all exported symbols here
 *
 * Copyright (C) 2020 zerons
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

#ifndef SI_ANALYSIS_H_N57L1QPA
#define SI_ANALYSIS_H_N57L1QPA

#include "si_core.h"

DECL_BEGIN

CLIB_MODULE_CALL_FUNC(analysis, sinode_new, struct sinode *,
		(enum sinode_type type, char *name, size_t namelen,
		 char *data, size_t datalen),
		5, type, name, namelen, data, datalen);

CLIB_MODULE_CALL_FUNC(analysis, sinode_insert, int,
		(struct sinode *node, int behavior),
		2, node, behavior);

CLIB_MODULE_CALL_FUNC(analysis, sinode_search, struct sinode *,
		(enum sinode_type type, int flag, void *arg),
		3, type, flag, arg);

CLIB_MODULE_CALL_FUNC(analysis, sinode_iter, void,
		(struct rb_node *node, void (*cb)(struct rb_node *n)),
		2, node, cb);

CLIB_MODULE_CALL_FUNC0(analysis, sibuf_new, struct sibuf *);

CLIB_MODULE_CALL_FUNC(analysis, sibuf_insert, void,
		(struct sibuf *b),
		1, b);

CLIB_MODULE_CALL_FUNC(analysis, sibuf_remove, void,
		(struct sibuf *b),
		1, b);

CLIB_MODULE_CALL_FUNC(analysis, sibuf_typenode_insert, int,
		(struct sibuf *b, struct sibuf_typenode *stn),
		2, b, stn);

CLIB_MODULE_CALL_FUNC(analysis, sibuf_typenode_search, struct type_node *,
		(struct sibuf *b, int tc, void *addr),
		3, b, tc, addr);

CLIB_MODULE_CALL_FUNC(analysis, resfile_new, struct resfile *,
		(char *path, int built_in),
		2, path, built_in);

CLIB_MODULE_CALL_FUNC(analysis, resfile_add, void,
		(struct resfile *rf),
		1, rf);

CLIB_MODULE_CALL_FUNC(analysis, resfile_read, int,
		(struct resfile *rf, struct sibuf *buf, int force),
		3, rf, buf, force);

CLIB_MODULE_CALL_FUNC(analysis, resfile_load, void,
		(struct sibuf *buf),
		1, buf);

CLIB_MODULE_CALL_FUNC(analysis, resfile_unload, void,
		(struct sibuf *buf),
		1, buf);

CLIB_MODULE_CALL_FUNC0(analysis, resfile_gc, int);

CLIB_MODULE_CALL_FUNC0(analysis, resfile_unload_all, void);

CLIB_MODULE_CALL_FUNC(analysis, resfile_get_filecnt, int,
		(struct resfile *rf, int *is_new),
		2, rf, is_new);

CLIB_MODULE_CALL_FUNC(analysis, resfile_get_offset, int,
		(char *path,unsigned long filecnt,unsigned long *offs),
		3, path, filecnt, offs);

CLIB_MODULE_CALL_FUNC(analysis, resfile_get_fc, struct file_content *,
		(char *path, char *targetfile, int *idx),
		3, path, targetfile, idx);

CLIB_MODULE_CALL_FUNC(analysis, get_func_code_paths_start, void,
		(struct code_path *codes),
		1, codes);

CLIB_MODULE_CALL_FUNC0(analysis, get_func_next_code_path, struct code_path *);

CLIB_MODULE_CALL_FUNC(analysis, trace_var, int,
		(struct sinode *fsn, void *var_parm,
		 struct sinode **target_fsn, void **target_vn),
		4, fsn, var_parm, target_fsn, target_vn);

CLIB_MODULE_CALL_FUNC(analysis, gen_func_paths, void,
		(struct sinode *from, struct sinode *to,
		 struct list_head *head, int idx),
		4, from, to, head, idx);

CLIB_MODULE_CALL_FUNC(analysis, drop_func_paths, void,
		(struct list_head *head),
		1, head);

/* XXX, for now, we only handle max to FUNC_CP_MAX paths */
#define FUNC_CP_MAX	0x100000
CLIB_MODULE_CALL_FUNC(analysis, gen_code_paths, void,
		(void *arg, struct clib_rw_pool *pool),
		2, arg, pool);

CLIB_MODULE_CALL_FUNC(analysis, drop_code_path, void,
		(struct path_list *head),
		1, head);

DECL_END

#endif /* end of include guard: SI_ANALYSIS_H_N57L1QPA */
