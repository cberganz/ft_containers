#!/bin/bash

CFLAGS="-Wall -Wextra -Werror -std=c++98 -g"

Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'
BYellow='\033[1;33m'
white='\033[1;37m'
green='\033[0;32m'
red='\033[0;31m'
yell='\033[0;33m'
reset='\033[0m'

tester() {
	nb_errors=0
	ft_time_total=0
	std_time_total=0
	printf "\n${BYellow}$container_to_test			FT_TIME		STD_TIME	RESULT\n${reset}"
    files=`ls ./src/$container_to_test`
	files=`echo $files | sed 's/\n/ /g'`
    nb_tests=`echo $files | wc -l`
    rm -f ft.txt std.txt
	for test in $files
	do
		trunc_test=${test:0:15}
		printf "${Cyan}${trunc_test%.*}	${Purple}${reset}"
        c++ $CFLAGS -D NAMESPACE=ft -o ${test%.*}ft ./src/$container_to_test/$test 
        c++ $CFLAGS -D NAMESPACE=std -o ${test%.*}std ./src/$container_to_test/$test 
        ./${test%.*}ft >> ft.txt
		if [ $memory_mode = 1 ]
		then
			valgrind ./${test%.*}ft 2>&1 | grep -A 25 'HEAP SUMMARY'
  	    	rm ${test%.*}ft ${test%.*}std ft.txt std.txt
		else
		    ft_time=`{ time ./${test%.*}ft >/dev/null; } 2>&1 | grep "real" | sed s/[a-z]//g`
			ft_time_total=`echo "$ft_time_total + $ft_time" | bc`
			exit_val_ft=$?
  	    	./${test%.*}std >> std.txt
  	    	std_time=`{ time ./${test%.*}std >/dev/null; } 2>&1 | grep "real" | sed s/[a-z]//g`
			std_time_total=`echo "$std_time_total + $std_time" | bc`
			exit_val_std=$?
			ret_diff=`diff ft.txt std.txt`
  	    	rm ${test%.*}ft ${test%.*}std ft.txt std.txt
			printf "${Purple}${ft_time}s	${std_time}s${reset}"
			if [ "$ret_diff" != "" ] || [ $exit_val_ft != $exit_val_std ] || [ $exit_val_ft = 127 ]
			then
				nb_errors=$(($nb_errors+1))
				echo >> debug.txt
				echo "Failed on test $test :" >> debug.txt
				echo "Your exit status: $exit_val_ft | stdlib exit status: $exit_status_std " >> debug.txt
				echo "Here is the return of the diff command :" >> debug.txt
				echo "$ret_diff" >> debug.txt
				echo "Here is the main that made you fail :\n" >> debug.txt
				cat ./src/$container_to_test/$test | sed -n '/int main/,$p' >> debug.txt
				echo >> debug.txt
  	    		printf "		❌\n"
  	      	else
  	        	printf "		✅\n"
			fi
		fi
	done
	if [ $memory_mode = 0 ]
	then
		if [ $nb_errors = 0 ]; then
			printf "${BYellow}TOTAL			0${ft_time_total}s		0${std_time_total}s		✅${reset}\n\n"
		else
			printf "${BYellow}TOTAL			0${ft_time_total}s		0${std_time_total}s		❌${reset}\n${red}(see debug.txt file for errors details)${reset}\n\n"
		fi
	fi
	echo
}

print_help() {
	printf "\n${Blue}>>> Help menu <<<${reset}\n" >&2
	printf "${white}run $>bash launch_tests.sh [optional - Container to test] :${reset}\n" >&2
	printf "${white}[Container to test]${reset} vector - stack - map - set.\n" >&2
	printf "${white}[No args]${reset} Every container is tested.\n" >&2
	printf "${white}[Memcheck mode]${reset} You can check for memory leaks and errors by running (does only work on linux with valgrind) :\n$>bash push_swap_tester --memory [optional - Container to test]\n\n" >&2
}

container_to_test=$1
memory_mode=0
if [ -f "debug.txt" ]; then
	rm debug.txt
fi
if [ $# -gt 1 ] && [ $1 != "--memory" ]; then
	printf "${red}\nToo many args ! Help menu below : ${reset}\n" >&2
	print_help
	exit
fi
if [ $# -gt 2 ]; then
	printf "${red}\nToo many args ! Help menu below : ${reset}\n" >&2
	print_help
	exit
fi
if [[ $1 = "--help" ]]; then
	print_help
	exit
fi
if [[ $1 = "--memory" ]]; then
	container_to_test=$2
	memory_mode=1
fi
if [[ $container_to_test = "all" ]]; then
    container_to_test="vector"
    tester
    container_to_test="stack"
    tester
    container_to_test="map"
    tester
    container_to_test="set"
    tester
    exit
fi
if [[ $container_to_test = "vector" ]] || [[ $container_to_test = "stack" ]] || [[ $container_to_test = "map" ]] || [[ $container_to_test = "set" ]]; then
    tester
    exit
fi
printf "$red\nUnknown command ! Help menu below : $reset\n" >&2
print_help