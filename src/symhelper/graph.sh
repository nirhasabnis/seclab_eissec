#!/bin/bash
if (( $# != 3 )); then
    echo "Usage: $0 <in file name> <start pid> <out file name> "
    echo "This script will generate a graph of constraints based "
    echo "on pids from constraints collected in logcs file."
    exit 1
fi

logcs=$1
rootpid=$2
sfdpout="/tmp/out.dot"
consf="/tmp/cons"

#pid
create_node()
{
    #echo "Creating node for" $1
    label="\"$1\n\""
    grep $1 $logcs > $consf
    while read line
    do
        nline=`echo $line | sed -e 's/\"/\\\"/g' -`
        #label="$label + \"$nline\n\""
    done < $consf

    error=`grep $1 $logcs | grep -E "Fatal|Error|Exception" | wc -l`
    if [ $error -gt "0" ]
    then 
        color="red"
    else
        color="white"
    fi
    if [ "$1" -eq "$rootpid" ]
    then
        color="green"
    fi
    echo -e -n "\t" >> $sfdpout
    echo "$1 [shape=box, style=filled, fillcolor=$color, label=$label];" >> $sfdpout
}

#ppid pid
create_edge()
{
    #echo "Creating edge between" $1 "and" $2
    echo -e "\t$1 -> $2;" >> $sfdpout
}

#front and rear of queue
front=0
rear=0
queue=()
pid=0
declare -i front
declare -i rear
declare -a queue
declare -i pid

print_data()
{
    echo "Front:" $front " Rear:" $rear
}

enqueue()
{
    #echo "Enqueue: " $1
    (( rear++ ))
    queue[$rear]=$1
    #print_data
}

dequeue()
{
    if [ "$front" -eq "$rear" -o "$front" -gt "$rear" ]
    then pid=0
    else
        (( front++ ))
        #print_data
        pid=${queue[front]}
    fi
}

BFS()
{
    local chpids
    declare -a chpids
    while [ 1 ]
    do
        dequeue
        #echo "Dequeued pid:" $pid
        #dequeue returns 0 when queue is empty
        if [ $pid -eq 0 ]
        then
            return
        fi
        create_node $pid
        #pids of children spawned by current pid
        chpids=(`grep $pid: $logcs | grep spawned | cut -d ' ' -f 3 -`)
        for chpid in ${chpids[@]}
        do
            create_edge $pid $chpid
            enqueue $chpid
        done
    done
}

echo "Generating graph file.."
echo "diGraph G {" > $sfdpout
enqueue $2
BFS
echo "}" >> $sfdpout
echo "Graph file generated."
echo "Running sfdp to generate image.."
dot -Tpng $sfdpout -o $3
echo "Image generated."
eog $3
exit
