/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** fun_grof
*/

#ifndef FUN_GROF_H_
    #define FUN_GROF_H_

    #include "./grof.h"

unsigned short grof_get_type(grof_t *grof, const char *str);
bool grof_process(grof_t *grof);
char *grof_arithmetics(grof_t *grof, char *str);
bool grof_isfunction(grof_t *grof, size_t *n);

bool grof_create_var(grof_t *grof, unsigned long *n);
bool grof_for_loop(grof_t *grof, size_t *n);

short grof_tabpos_actions
(const char *str, const tabgrof_actions_t *TAB_GROF);
short grof_tabpos_builtins
(const char *str, const tabgrof_builtins_t *TAB_GROF);

bool grof_replacevar(grof_t *grof, char ***array);
char *grof_get_varvalue(grof_t *grof, const char *varname);

bool grof_builtins_print(grof_t *grof, char **keyval);
bool grof_builtins_exec(grof_t *grof, char **keyval);

bool grof_append_var(grof_t *grof, var_t *var);
bool grof_autovar(grof_t *grof, char *keyval_str);

bool grof_simulate(grof_t *grof, char *str);
bool grof(char *line, minish_t *minish);

#endif /* !FUN_GROF_H_ */
