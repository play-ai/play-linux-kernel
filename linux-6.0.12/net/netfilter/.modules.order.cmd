cmd_net/netfilter/modules.order := {   echo net/netfilter/nf_log_syslog.ko;   echo net/netfilter/xt_mark.ko;   echo net/netfilter/xt_nat.ko;   echo net/netfilter/xt_LOG.ko;   echo net/netfilter/xt_MASQUERADE.ko;   echo net/netfilter/xt_addrtype.ko; :; } | awk '!x[$$0]++' - > net/netfilter/modules.order