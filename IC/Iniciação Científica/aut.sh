#!/bin/bash

cd SOs
#testes FlawFinder
for i in *
do 
	echo "Analisando $i"
	flawfinder --csv "$i/" > ../Testes/flawfinder/"$i.csv"

done

( speaker-test -t sine -f 1000 )& pid=$! ; sleep 20s ; kill -9 $pid
