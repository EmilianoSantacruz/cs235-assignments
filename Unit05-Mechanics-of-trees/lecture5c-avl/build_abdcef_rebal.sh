cat << EOF > abdcef_rebal.txt
D < E
E < F
D > B [color="darkgreen"]
B > A
B < C [color="darkgreen"]

D [color="darkgreen" label=<D <br/><font point-size="10">(h:3, b:<font color="darkgreen">0</font>)</font>>]

B [label=<B <br/><font point-size="10">(h:<font color="darkgreen">2</font>, b:<font color="darkgreen">0</font>)</font>>]
A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]

C [label=<C <br/><font point-size="10">(h:1, b:0)</font>>]
E [label=<E <br/><font point-size="10">(h:2, b:1)</font>>]

F [label=<F <br/><font point-size="10">(h:1, b:0)</font>>]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.7 abdcef_rebal.txt
