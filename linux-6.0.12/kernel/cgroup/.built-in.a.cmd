cmd_kernel/cgroup/built-in.a := rm -f kernel/cgroup/built-in.a;  printf "kernel/cgroup/%s " cgroup.o rstat.o namespace.o cgroup-v1.o freezer.o legacy_freezer.o pids.o rdma.o cpuset.o misc.o debug.o | xargs ar cDPrST kernel/cgroup/built-in.a
