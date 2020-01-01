# execute shell command in Makefile
# test for file
# -f file true if file exists and is a regular file
# -s file true if file exits and has a size greater than zero
# test -f file_name && echo file_name does exist
# test -f file_name || echo file_name does not exist
# test -e file_name && echo file_name does exist
# test -d dir_name && echo dir_name does exist
# test ! -f file_name && echo file_name does not exist
#
# the test is equivalent to [ command
# [ -f file_name ] && rm file_name ;remove file_name if it exists
#
# wildcard is also used to check existence of file
# PATH_TO_FILE=/sbin/ifconfig    #value not in double quotes
# ifneq ("$(wildcard $(PATH_TO_FILE))","")
#    FILE_EXISTS = 1
#else
#    FILE_EXISTS = 0
#endif

FILES=$(shell ls)

ls:
	echo $(FILES)

dir:
	if [ ! -d obj ]; then mkdir obj;	fi;

clean:
	if [ -d obj ]; then rm -rf obj; fi;

tdir:
	test ! -d obj && mkdir obj

tclean:
	test -d obj && rmdir obj

