# Fillit

![Screen Shot 2019-05-15 at 3 25 18 PM](https://user-images.githubusercontent.com/38796098/57779501-795b4d00-7726-11e9-959d-46703fe4fcb0.png)

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
