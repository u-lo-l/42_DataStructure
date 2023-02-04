```
============CREATED DATA==========
[A]  [C]  [D]  [G]  [H]  [J]  [L]  [N]  [Q]  [S]
-----------------------------------
ADD START : A
ADD TO ROOT

level 1 [A]

ADD START : C

level 1   [A]

level 2     [C]

ADD START : D

level 1   [C]

level 2 [A] [D]

ADD START : G

level 1       [C]

level 2   [A]     [D]

level 3             [G]

ADD START : H

level 1       [C]

level 2   [A]     [G]

level 3         [D] [H]

ADD START : J

level 1               [C]

level 2       [A]             [G]

level 3                   [D]     [H]

level 4                             [J]

ADD START : L

level 1       [G]

level 2   [C]     [J]

level 3 [A] [D] [H] [L]

ADD START : N

level 1               [G]

level 2       [C]             [J]

level 3   [A]     [D]     [H]     [L]

level 4                             [N]

ADD START : Q

level 1               [G]

level 2       [C]             [J]

level 3   [A]     [D]     [H]     [N]

level 4                         [L] [Q]

ADD START : S

level 1                               [G]

level 2               [C]                             [J]

level 3       [A]             [D]             [H]             [N]

level 4                                                   [L]     [Q]

level 5                                                             [S]

===========INSERT COMPLETE========
DEL A from tree

level 1                               [G]

level 2               [C]                             [J]

level 3                       [D]             [H]             [N]

level 4                                                   [L]     [Q]

level 5                                                             [S]

DEL C from tree

level 1                               [G]

level 2               [D]                             [J]

level 3                                       [H]             [N]

level 4                                                   [L]     [Q]

level 5                                                             [S]

DEL D from tree

level 1                               [G]

level 2                                               [J]

level 3                                       [H]             [N]

level 4                                                   [L]     [Q]

level 5                                                             [S]

DEL G from tree

level 1               [J]

level 2       [H]             [N]

level 3                   [L]     [Q]

level 4                             [S]

DEL H from tree

level 1               [J]

level 2                       [N]

level 3                   [L]     [Q]

level 4                             [S]

DEL J from tree

level 1       [N]

level 2   [L]     [Q]

level 3             [S]

DEL L from tree

level 1       [N]

level 2           [Q]

level 3             [S]

DEL N from tree

level 1   [Q]

level 2     [S]

DEL Q from tree

level 1 [S]

DEL S from tree
	Empty Tree
```
