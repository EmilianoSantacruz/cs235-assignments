cat << EOF > efc_pre_annot.txt
E < F
E > C
C < D
C > B
B > A

A [label=<A <br/><font point-size="10">(h:1, b:0)</font>>]
B [label=<B <br/><font point-size="10">(h:2, b:-1)</font>>]
C [label=<C <br/><font point-size="10">(h:3, b:-1)</font>>]
D [label=<D <br/><font point-size="10">(h:1, b:0)</font>>]
E [label=<E <br/><font point-size="10">(h:4, b:-2)</font>>]
F [label=<F <br/><font point-size="10">(h:1, b:0)</font>>]

E -> D [color="blue" style="dotted"]
C -> E [color="blue" style="dotted"]
EOF
python3 ~/projects/btrees/btrees.py --w-scale 0.4 efc_pre_annot.txt
