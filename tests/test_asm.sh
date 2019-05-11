#!/bin/env sh

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
NC='\033[0m'
valid=0
total=0
timeout=3

function timeout {
    sleep $timeout
    echo ${RED} "TIMEOUT: Program took more than $timeout to be executed" ${NC}
    kill $1
}

function test {
    for file in ./*.s
    do
        timeout $$ &
        timeout_pid=$!
        echo
        echo "Testing champion : " $file
        ./../asm/asm $file &> /dev/null
        cat ${file%.*}.cor > .tmp
        ./../asm/corewar_binaries/asm/asm $file &> /dev/null
        diff .tmp ${file%.*}.cor
        if [ $? -ne 0 ] ; then
            if [ ! -f ${file%.*}.cor ]; then
                echo -ne "\t${GREEN}OK${NC}\n"
                valid=$(($valid+1))
            fi
            echo -ne "\t${RED}KO${NC}\n"
            echo "YOU:"
            hexdump -C .tmp
            echo "MOULI:"
            hexdump -C ${file%.*}.cor
        else
            echo -ne "\t${GREEN}OK${NC}\n"
            valid=$(($valid+1))
        fi
        total=$(($total+1))
        kill $timeout_pid
        rm -f .tmp ${file%.*}.cor
    done
}

function display {
    result=$((($valid * 100)/($total)))
    if [ $result -lt 25 ] ; then
        echo -ne "${RED}"
    elif [ $result -ge 25 -a $result -le 75 ] ; then
        echo -ne "${ORANGE}"
    else
        echo -ne "${GREEN}"
    fi
    echo "${result}%"
    echo -ne "${NC}"
}

function read_logs {
    echo "Read the logs ? (y/n): "
    read res
    if [[ $res == "y" ]] ; then
        cat .logs
    fi
    rm -f logs
}

test
display
# read_logs
