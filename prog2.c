/*
============================================================================
Name : 2.c
Author : Abhishek Sahu
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
			  identify all the process related information in the corresponding proc directory.
Date: 29th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main(){
	while(1){
		printf("Hello ");
		sleep(1);
	}

	return 0;
}
/*
Output:
cd proc/4363
cat status

Name:   prog2
Umask:  0002
State:  S (sleeping)
Tgid:   4363
Ngid:   0
Pid:    4363
PPid:   3723
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 24 27 30 46 120 131 132 1000 
NStgid: 4363
NSpid:  4363
NSpgid: 4363
NSsid:  3723
Kthread:        0
VmPeak:     2684 kB
VmSize:     2684 kB
VmLck:         0 kB
VmPin:         0 kB
VmHWM:      1408 kB
VmRSS:      1408 kB
RssAnon:               0 kB
RssFile:            1408 kB
RssShmem:              0 kB
VmData:      224 kB
VmStk:       136 kB
VmExe:         4 kB
VmLib:      1748 kB
VmPTE:        44 kB
VmSwap:        0 kB
HugetlbPages:          0 kB
CoreDumping:    0
THP_enabled:    1
untag_mask:     0xffffffffffffffff
Threads:        1
SigQ:   0/23152
SigPnd: 0000000000000000
ShdPnd: 0000000000000000
SigBlk: 0000000000000000
SigIgn: 0000000000000000
SigCgt: 0000000000000000
CapInh: 0000000000000000
CapPrm: 0000000000000000
CapEff: 0000000000000000
CapBnd: 000001ffffffffff
CapAmb: 0000000000000000
NoNewPrivs:     0
Seccomp:        0
Seccomp_filters:        0
Speculation_Store_Bypass:       thread vulnerable
SpeculationIndirectBranch:      conditional enabled
Cpus_allowed:   00ff
Cpus_allowed_list:      0-7
Mems_allowed:   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:      0
voluntary_ctxt_switches:        22
nonvoluntary_ctxt_switches:     0
x86_Thread_features:
x86_Thread_features_locked:
*/