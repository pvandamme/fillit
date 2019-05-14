# Fillit

42 Algorithm Project - Tetris solver

The goal of this project is to arrange the Tetriminos among themselves to make the smallest possible square, but in some cases, this square may have holes when some given pieces won’t fit perfectly with others.

You can find the subject in the directory subjects/ on this repository.

## Compiling and running

Run `make`. An executable will compile. Currently only tested on OS X.

You can generate pieces with the generator : 
```
python3 generator.py [1 to 26] > map_test
```

Run it with `./fillit map_test`

## Example

`Input :` <img width="50" src="https://user-images.githubusercontent.com/38796098/57736525-96e9d180-76a8-11e9-9227-af9e86c93e2f.png">

`Output` : <img width="50" src="https://user-images.githubusercontent.com/38796098/57736522-96513b00-76a8-11e9-8d7c-a2a3b1e6cccd.png">
