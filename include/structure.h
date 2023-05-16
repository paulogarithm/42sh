/*
** EPITECH PROJECT, 2023
** structure.h
** File description:
** structure for the boostrap minishell / CPE semestre 2
*/

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

    #define UNUSED __attribute__((unused))
    #define __unused __attribute__((unused))

typedef struct s_termios    termios_t;
typedef struct s_minish     minish_t;

    #include "parser_ll.h"
    #include <stdbool.h>
    #include <termios.h>

struct s_termios {
    struct termios t;
    struct termios saved;
};

struct s_minish {
    char **env;
    char *contenue_of_the_line;
    int return_value;
    int save_i;
    char *absolute;
    char *previous_path;
    char **aliases;
    char **variables;
    char **history_parser;
};

// BASED_FUNCTION
int my_put_nbr_max(int);
int my_putstr_max(char const *);
int my_putchar_max(char);
int my_strlen_max(char const *);
char *my_strmerge_max(char *, char *);
char **my_str_to_word_array_max(char *, char);
char **my_str_to_word_array_strtok_max(char *, char );
int my_strcmp_max(char const *, char const *);
char *my_strcat_max(char *, char const *);
char *my_strndup_max(char *, int );
char *my_strcpy_max(char *, char const *);
char *my_strdup_max(char *);
int my_strncmp_max(char const *, char const *, int);
// !BASED_FUNCTION

// MAIN
int sub_main(int, char **, char **);
// !MAIN

void infinite_loop(minish_t *s, const bool is_empty);

// CD_BUILTINS
void cd_function(minish_t* , char *);
void cd_tiret(minish_t *, char *);
int slash_exeption(char **);
void change_env(minish_t *, char *, char *);
// !CD_BUILTINS

// ENV_BUILTINS
void env_function(minish_t *);
// ENV_BUILTINS

// SETENV
void setenv_function(minish_t *, char *);
int check_if_commande_have_the_good_form_part_2(char **);
// !SETENV

//PAUSE
int compteur_sig(int);
void is_pause(int);
int pause(void);
//PAUSE

// UNSETENV
void unsetenv_function(minish_t *, char *);
// !UNSETENV

// CENTRALE_UNITS
int repartition_function(minish_t *, char *);
// !CENTRALE_UNITS

// BINARY_OPERATOR
void redirection_right(minish_t *, struct binary_tree *);
void double_redirection_right(minish_t *, struct binary_tree *);
void double_redirection_left(minish_t *s, struct binary_tree *bt);
void redirection_left(minish_t *, struct binary_tree *);
void pipe_function(minish_t *, struct binary_tree *);
void separator(minish_t *s, struct binary_tree *bt);
void double_pipe(minish_t *s, struct binary_tree *bt);
void double_esperluette(minish_t *s, struct binary_tree *bt);
char *look_backsticks(char *command, minish_t *s, struct binary_tree *bt);
char *backticks(char *command, int i, minish_t *s, struct binary_tree *bt);
char *change(char *buffi);
char *tableau_to_string(char **buff);
void globbing(minish_t *s, struct binary_tree *bt);
// !BINARY_OPERATOR

//REDIRECTION LEFT
char *formatting_str(char *str);
int nb_spaces(char *);
//!REDIRECTION LEFT

// BINARY_TREE
int call_binary_tree(minish_t *s, struct binary_tree *bt, char *command);
struct binary_tree *binairy_tree_function(minish_t *s);
struct binary_tree *operation_priority(char *, int);
// !BINARY_TREE

// ERROR_HANDLING
void errno_function(char *);
void detect_signal(int, minish_t *);
// !ERROR_HANDLING

// MANAGE_ENV
int parsing_env(minish_t *, char *);
void malloc_env(minish_t *, char **);
// !MANAGE_ENV

// EXECUTION
int execution(char *, minish_t *);
// !EXECUTION

// MANAGE_COMMANDE
void replace_tab(char *);
// !MANAGE_COMMANDE






/* Gregoire Lan Tim */

int custom_echo(char **array_cmd, minish_t *minish);

int my_basic_echo(char **array, minish_t *minish);

/* not Gregoire Lan Tim */







/**
 *--------------------------------------------------------------------------*
 |      @name        Builtins                                               |
 |      @author      by Paul Parisot                                        |
 *--------------------------------------------------------------------------*
**/

/**
 *  @category   Environnement
 *  @brief      Get the position in a Keyval (KEY=value) environnement.
 *  @attention  Keyval : (KEY=value)
 *  @param      env     The environnement, an array of string with KEY=value.
 *  @param      key     The string you want to search.
 *  @return     The number in position in the array if founded, else -1.
**/
int get_envpos(const char **env, const char *key);

/**
 *  @category   Environnement
 *  @brief      Obtain the value in a Keyval environnement.
 *  @attention  Keyval : (KEY=value)
 *  @param      env     The environnement, an array of string with Keyval.
 *  @param      key     The string you want to search.
 *  @return     The value in string, or NULL.
**/
char *get_envval(const char **env, const char *key);

/**
 *  @category   Environnement
 *  @brief      Add a variable in a Keyval array.
 *              If there is 1 value in the array, the function displays the
 *              Keyval array.
 *              If there is 2 values, it's setting the key to a value with
 *              nothing in it.
 *              If there is 3 values, the Keyval will be added in the array.
 *              environnement.
 *  @attention  Keyval : (KEY=value)
 *  @param      array_0     Must be the "setenv" string.
 *  @param      array_1     Must be the KEY that must start with a letter and
 *                          containing only alphanumerical or '_' characters.
 *  @param      array_2     Must contain the value (anything).
 *  @param      env         The pointer to environnement, an array of string
 *                          with KEY=value.
 *  @return     Returns 0 if the program is not corresponding with what it
 *              needs to do, and 1 if it works or if there is an error.
**/
short custom_setenv(char **array, char ***env);

/**
 *  @category   Environnement
 *  @brief      Removes the arguments given in an array.
 *  @attention  Keyval : (KEY=value)
 *  @param      array_0     Must be the "unsetenv" string.
 *  @param      array_n     Contains the KEYs to erase from the environnement.
 *  @param      env         The pointer to environnement, an array of string
 *                          with Keyval.
 *  @return     Returns 0 if the program is not corresponding with what it
 *              needs to do, and 1 if it works or if there is an error.
**/
short custom_unsetenv(char **array, char ***env);



/**
 * @category    Alias
 * @brief       In an alias format array, obtain the position of the KEY.
 * @attention   Alias format array : (KEY value value ...)
 * @param       array   The array of alias values.
 * @param       str     The KEY string you're looking for.
 * @return      The position (between 0 and the len of the array) if its
 *              founded in the array, else -1.
**/
int get_alias_pos(char **array, const char *str);

/**
 * @category    Alias
 * @brief       Replace a splitted word's command by his alias if he have an
 *              alias value in the minishell structure.
 *              position of the KEY.
 * @attention   Alias format array : (KEY value value ...)
 * @param       array   The pointer toward an array of string with the splitted
 *                      command.
 * @param       minish  A structure that contains minish->aliases, the list of
 *                      all aliases.
 * @param       old     An empty array, given to avoid alias loops.
 * @return      Returns 0 to process searching commands, so it means it has
 *              been replaced or not been replaced, or a signed number if its
 *              an alias loop.
**/
int replace_alias(char ***array, minish_t *minish, char **old);

/**
 * @category    Alias
 * @brief       Add the alias variable you gave or display the alias.es.
 *              If array have 1 value, it just display all aliases.
 *              If array have 2 values, it displays the values of the key.
 *              If array have more than 2 values, all the strings after the
 *              second argument are the value of this one.
 * @attention   Alias format array : (KEY value value ...)
 * @param       array_0     Must be "alias" string.
 * @param       array_1     Must be an existsing key or a new key, depending
 *                          on the number of arguments given.
 * @param       array_n     Must be the values for the array_1 key.
 * @param       minish      A minishell structure that contains minish->aliases
 * @return      Return 0 if its not the alias command, 1 if its an error or if
 *              it works.
**/
short custom_alias(char **array, minish_t *minish);

/**
 * @category    Alias
 * @brief       Remove aliases given in parametters of the array.
 * @attention   Alias format array : (KEY value value ...)
 * @param       array_0     Must be "unalias" string.
 * @param       array_n     Must be the KEY of the alias you want to remove.
 * @return      Return 0 if its not the alias command, 1 if its an error or if
 *              it works.
**/
short custom_unalias(const char **command, minish_t *minish);









/**
 *--------------------------------------------------------------------------*
 |      @name        Usefull                                                |
 |      @author      by Paul Parisot                                        |
 *--------------------------------------------------------------------------*
**/

/**
 * @category    Usefull
 * @brief       One of the most usefull function that convert a Keyval string
 *              into an array of 2 elements : the key and the value.
 * @attention   Keyval : (KEY=value)
 * @param       str     The string with this form "key = value"
 * @return      An array of 2 elements that contains [key, value]
**/
char **keyvalue_parser(char *str);

/**
 * @category    Usefull
 * @brief       Nothing ? What does nothing means ? Nothing is when there is
 *              not a single thing, it means darkness, nil, void. But, this
 *              function, exists right ? So it's not nothing ? But his return
 *              value is nothing so it's an endpoint, after this function got
 *              executed, nothing happends for the rest of the program, it
 *              doesnt affect anything. Nothing happends. Nothing ? So we're
 *              on another question : is this function usefull if it does
 *              nothing ? Do we need nothing ?
**/
void nothing(int sig);

/**
 * @category    Usefull
 * @brief       Checks if a string starts with a specific string.
 * @param       str     The string we want to look at.
 * @param       start   The string thats begin with.
 * @return      Returns true if 'str' starts with 'start', and returns false
 *              otherwise.
**/
bool my_startswith(const char *str, const char *start);

/**
 * @category    Usefull
 * @brief       Removes every string from an array that starts with the string
 *              given.
 * @param       array   The array of string.
 * @param       start   The string thats begin with.
 * @return      Returns the new array of string that not starts with them.
**/
char **my_filter_startswith(char **array, const char *start);









/**
 *--------------------------------------------------------------------------*
 |      @name        Path                                                   |
 |      @author      by Paul Parisot                                        |
 *--------------------------------------------------------------------------*
**/

/**
 * @category    Path
 * @brief       Obtain the absolute path of a string. For example ../hello will
 *              return /home/pol/foo/hello for example.
 * @param       str     The string of your original path.
 * @return      Return the full path (pwd)
**/
char *get_absolutepath(const char *str);

/**
 * @category    Path
 * @brief       Replace the '~' character by your HOME path, in any string.
 * @param       array   Pointer toward the array of your splitted command.
 * @param       env     Array of the Keyval environnement.
 * @return      Returns 0 if it succeed, a signed number otherwise.
**/
int replace_vaguelette(char ***array, const char **env);

/**
 * @category    Path
 * @brief       Removes the file extension (file.any -> file).
 * @attention   This function returns nothing, the string is directly modified.
 * @param       file    Pointer toward the string.
**/
void remove_extension(char **file);

/**
 * @category    Path
 * @brief       Obtains the last word of a string, separated by 'sep'.
 * @param       str     The string that will contains words.
 * @param       sep     The separator.s to split words.
 * @return      The last word of the string ('hello.test.haha', '.' -> haha).
 *              Returns NULL if an error occurs.
*/
char *get_lastword(char *str, char *sep);

/**
 * @category    Path
 * @brief       Get all files from a folder.
 * @param       src         The source of the folder.
 * @param       onlyfolder  Variable to chose listing all files or just
 *                          the folders inside of the source.
 * @return      Returns the array of all instances/folders inside the
 *              src folder.
*/
char **get_allfiles(const char *src, bool onlyfolder);

/**
 * @category    Path
 * @brief       Check if an instance is a Folder or a File.
 * @param       path    The path toward the instance.
 * @param       mode    Can be used as the enum, 1 for regular file (M_REG),
 *                      2 for folder (M_DIR)
 * @return      Returns 0 if the instance is indeed the one selected, 1 if not
 *              and -1 if its an error.
**/
int get_filemode(char *path, int mode);









/**
 *--------------------------------------------------------------------------*
 |      @name        Termios                                                |
 |      @author      by Paul Parisot                                        |
 *--------------------------------------------------------------------------*
**/

/**
 * @category    Termios
 * @brief       Get a termios structure ready to be used.
 * @return      Returns a structur termios_t that contains the current termios
 *              config you can edit (t) and the one saved that is the basic one
 *              (saved).
**/
termios_t *termios_setup(void);

/**
 * @category    Termios
 * @brief       Handle the arrow real time input.
 * @param       input           The pointer toward the real time input string.
 * @param       cursorpos       The pointer toward the cursor position in the X
 *                              axis, 0 is the end of the string.
 * @param       minish          The minishell structure with everything needed,
 *                              specially the history parsing.
 * @param       historypos      The pointer toward the position in the history.
 * @return      In theory, it returns 0 if it works and 1 if there is an error,
 *              but on the paper, it's only returning 0, since it's only
 *              checking if the right keys are pressed and changes pointers.
**/
short termios_arrow
(char **input, int *cursorpos, minish_t *minish, long *historypos);

/**
 * @category    Termios
 * @brief       Handle any input and redirect toward the right functions.
 * @param       input           The pointer toward the real time input string.
 * @param       cursorpos       The pointer toward the cursor position in the X
 *                              axis, 0 is the end of the string.
 * @param       historypos      The pointer toward the position in the history.
 * @param       minish          The minishell structure with everything needed,
 *                              specially the history parsing.
 * @return      Returns -1 to leave the program, 1 to process the line and 0 to
 *              continue getting input from user.
**/
short termios_getinput
(char **input, int *cursorpos, long *historypos, minish_t *minish);

/**
 * @category    Termios
 * @brief       Function to obtain the user's final input, while executing
 *              actions while getting real time input.
 * @param       showing     The string to display while getting the input.
 * @param       status      The pointer toward status of the input. If the
 *                          status is -1, it exits the program. If the status
 *                          is annything else, the input line is executed.
 * @param       minish      The minishell structure with everything needed.
 * @return      Returns the string that the user gives in input after pressing
 *              enter. It returns NULL if its an error.
**/
char *termios_scanf(const char *showing, int *status, minish_t *minish);

/**
 * @category    Termios
 * @brief       Function to process tabulation for autocompletion.
 * @param       input   The pointer toward the input string.
 * @param       minish  The minishell structure with anything needed.
 * @return      Returns 1 in case of error, and 0 otherwise.
**/
bool termios_tab(char **input, minish_t *minish);

short termios_history(char **input, minish_t *minish, bool realtime);

bool n_command(char **input, minish_t *minish, bool realtime);







/**
 *--------------------------------------------------------------------------*
 |      @name        Terminal Stuff                                         |
 |      @author      by Paul Parisot                                        |
 *--------------------------------------------------------------------------*
**/


char *get_show(const int is_empty, minish_t *minish);

int custom(char ***array, minish_t *minish);

void write_hs(char *command, minish_t *minish);
void read_rc(minish_t *minish);
minish_t *setup_minishell(char **env, char *absolute);
char *my_getlinescanf(char *show, int *status);


void replace_var(char **array, minish_t *minish);

// !FILE_MANIP.C


bool grof(char *line, minish_t *minish);



// HISTORY.C
char *history_setcommand(char *command, minish_t *minish);
char *history_getcommand(int pos, minish_t *minish);
unsigned int history_lastnum(minish_t *minish);
// HISTORY.C



#endif /* !STRUCTURE_H_ */
