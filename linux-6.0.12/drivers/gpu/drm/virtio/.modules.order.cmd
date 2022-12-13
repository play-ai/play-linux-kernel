cmd_drivers/gpu/drm/virtio/modules.order := {  :; } | awk '!x[$$0]++' - > drivers/gpu/drm/virtio/modules.order
