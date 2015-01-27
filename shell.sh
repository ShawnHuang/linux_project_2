./cpu_bound &
ping 140.115.51.88 > /dev/null &
cpu_pid=`ps -a|grep cpu_bound|awk '{print $1}'`
io_pid=`ps -a|grep ping|awk '{print $1}'`
sleep 185
./main $cpu_pid $io_pid
sleep 5
./main $cpu_pid $io_pid
kill $cpu_pid
kill $io_pid
