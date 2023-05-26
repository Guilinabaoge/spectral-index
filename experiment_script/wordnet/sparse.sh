#!/bin/bash 

byobu kill-session -t sparse
byobu new-session -d -s sparse
byobu select-pane -t 0
byobu split-window -v
byobu select-pane -t 1
byobu split-window -h
byobu select-pane -t 0
byobu split-window -h
byobu select-pane -t 0
byobu split-window -h
byobu select-pane -t 0
byobu split-window -v

arr=("LDF" "NLF" "GQL" "TSO" "CFL" "DPiso")
counter=0;
 
for element in ${arr[@]}
do
	byobu select-pane -t $counter
	byobu send-keys "./performance20.sh 1 200 human sparse $element" Enter
	((counter++))
done	
