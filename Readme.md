# 42sh

## Description

42sh is an [Epitech](https://www.epitech.eu/) project, where you need to re-create an entire terminal from scratch in C language, using Lib C functions.

<br>

## Requierements

You will need to have `gcc` and `make` installed on your computer. <br>
You need to be in a Linux OS.

<br>

## Installation

### Manual installation

Follow this 2 simple steps : <br>

1. Clone the repo using this command : <br>
`git clone https://github.com/EpitechPromo2027/B-PSU-200-PAR-2-1-42sh-max.houdouin`

2. Enter the repository and build the file using make : <br>
`cd B-PSU-200-PAR-2-1-42sh-max.houdouin/ && make -s re`

You can now run 42sh by executing `./42sh`.

<br>

## Grof

Grof is the 42sh scripting language (drafted). <br>

<br>

### How to code

Your code is interpreted in the terminal, it is not an external program. <br>

<br>

### Variables

Variables have types in intern, but the language is autotyped. Here are all the different types :
| Number | Type    | Description               |
|--------|---------|---------------------------|
| 0      | nil     | For no type               |
| 1      | number  | For any number (3 or 3.1) |
| 2      | boolean | true or false             |
| 3      | string  | beggins and ends with `"` |
| 4      | table   | beggins with `{`          |

To declare a variable, you need to declare it with the exp keyword, followed by Key = Value style, separated by **spaces** or **tabulations**. <br>

For example :
```
exp a = 10
```
Sets the value of a to 10.

<br>

You can also do additions :
```
exp a = 1 + 3.14 + 12
```
Will correctly sets the variable at 16.14. <br>

It also works with string (not very operationnal) :
```
exp a = "hello" + "world"
```
Will make the a's value sets to "hello""world".

> The type of the variable when you do arithmetics operations depends on the type of the first operand. <br>
> Here are some example : <br>
> 3 + "hello" :     will be a NUMBER, since the first operand is 3, it will be set at 3 + 0.<br>
> "hello" + 3 :     will be a STRING, since the first operand is "hello", it will be set at "hello"3

### Builtins functions

Builtins function are functions already coded in the language.

To call them, simply do `<builtin>(<args>...)`.

### `exec(...)`
Execute what is inside of it with the 42sh terminal :
```
exec(ls | cat)
```
Will execute the `ls | cat` command and display the result.

### `print(...)`

Will print every parameters separated by a `,` :
```
exp a = 1 print(a, "foo", a + 1, b)
```
Will print the value of a (which is 1), then "foo" string, tha a value plus 1, which is 1 + 1 which is 2, and finally, the b value that doesnt exists, so it will be set at nil.


### Loops

The for loop will execute grof code the amount given. <br>
Here is how the for loop is built :
```
for <key> = <begin>, <end>, <step?> do <code> end
```
So the key will start at the begin value, and will goes all the way up or down to the end value, jumping from step to step. <br>

- `key` : soon
- `begin` : the key origin value
- `end` : when it stops
- `step?`: this is optional. If you don't give a step, it will be 1 if `end` is greater than `begin`, and -1 otherwise. If you give a step, it will simply increment or decrement each turn.

<br>

Here are some examples :
```
for a = 1, 10 do print(a) end
> 1 2 3 5 6 7 8 9

for a = 6, 2 do print(a) end
> 6 5 4 3

for a = 0, 10, 2 do print(a) end
> 0 2 4 6 8
```

<br>

## Our Dream Team

| <img src="https://github.com/alpharone.png?size=50" width=50> | [Alexandre Odriosolo](https://github.com/alpharone) |
|-|-|

| <img src="https://github.com/paulogarithm.png?size=50" width=50> | [Paul Parisot](https://github.com/paulogarithm) |
|-|-|

| <img src="https://github.com/xcapitainex.png?size=50" width=50> | [Max Houdouin](https://github.com/xcapitainex) |
|-|-|

| <img src="https://github.com/gregoirelantim.png?size=50" width=50> | [Gregoire Lan Tim](https://github.com/gregoirelantim) |
|-|-|

| <img src="https://github.com/elisepipet.png?size=50" width=50> | [Elise Pipet](https://github.com/elisepipet) |
|-|-|
