# CFortranTranslator
A translator between C and Fortran.

## Install
win_flex and win_bison
boost
vs2015

## fortran grammar restrictions and translate rules
for all accepted grammar please refer to for90.y
### keywords

1. no word after `END [DO|IF|CASE|...]` term

### types
1. type mapping

|for90|c++|
|:-:|:-:|
|INTEGER(all kind)|int|
|REAL(all kind)|double|
|LOGICAL|bool
|COMPLEX|struct for_complex|
|CHARACTER|std::string|

### variables
1. all variables must be **explicitly** declared

### array
