/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof
*/

#ifndef GROF_H_
    #define GROF_H_

    #include "structure.h"
    #include <stddef.h>

enum mode_e {
    G_NIL = 0,
    G_NUMBER,
    G_BOOLEAN,
    G_STRING,
    G_TABLE,
};

typedef struct s_var {
    char *name;
    unsigned short type;
    char *value;
} var_t;

typedef struct s_grof {
    var_t **variables;
    char **words;
    minish_t *minish;
} grof_t;

typedef struct s_tabgrof_actions {
    char *flag;
    bool (*function)(grof_t *, unsigned long *);
} tabgrof_actions_t;

typedef struct s_tabgrof_builtins {
    char *flag;
    bool (*function)(grof_t *, char **);
} tabgrof_builtins_t;

typedef struct s_tabgrof_operations {
    char *operation;
    void (*function)(grof_t *, char ***, size_t);
} tabgrof_operations_t;

#endif /* !GROF_H_ */
