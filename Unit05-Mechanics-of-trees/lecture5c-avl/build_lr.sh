cat << EOF > lr.txt
B < C
B > A
C < E
E > D

A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]
B [label=<B <br/><font point-size="10">(h:<font color="darkgreen">4</font>, b:<font color="red">2</font>)</font>>]
C [label=<C <br/><font point-size="10">(h:<font color="darkgreen">3</font>, b:<font color="red">2</font>)</font>>]
D [color="darkgreen" label=<D <br/><font point-size="10">(h:1, b:0)</font>>]
E [label=<E <br/><font point-size="10">(h:<font color="darkgreen">2</font>, b:<font color="darkgreen">-1</font>)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 1 lr.txt
