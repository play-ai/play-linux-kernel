cmd_fs/netfs/modules.order := {  :; } | awk '!x[$$0]++' - > fs/netfs/modules.order
