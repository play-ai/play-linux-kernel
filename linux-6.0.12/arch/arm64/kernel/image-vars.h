/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Linker script variables to be set after section resolution, as
 * ld.lld does not like variables assigned before SECTIONS is processed.
 */
#ifndef __ARM64_KERNEL_IMAGE_VARS_H
#define __ARM64_KERNEL_IMAGE_VARS_H

#ifndef LINKER_SCRIPT
#error This file should only be included in vmlinux.lds.S
#endif

PROVIDE(__efistub_kernel_size		= _edata - _text);
PROVIDE(__efistub_primary_entry_offset	= primary_entry - _text);

/*
 * The EFI stub has its own symbol namespace prefixed by __efistub_, to
 * isolate it from the kernel proper. The following symbols are legally
 * accessed by the stub, so provide some aliases to make them accessible.
 * Only include data symbols here, or text symbols of functions that are
 * guaranteed to be safe when executed at another offset than they were
 * linked at. The routines below are all implemented in assembler in a
 * position independent manner
 */
PROVIDE(__efistub_memcmp		= __pi_memcmp);
PROVIDE(__efistub_memchr		= __pi_memchr);
PROVIDE(__efistub_memcpy		= __pi_memcpy);
PROVIDE(__efistub_memmove		= __pi_memmove);
PROVIDE(__efistub_memset		= __pi_memset);
PROVIDE(__efistub_strlen		= __pi_strlen);
PROVIDE(__efistub_strnlen		= __pi_strnlen);
PROVIDE(__efistub_strcmp		= __pi_strcmp);
PROVIDE(__efistub_strncmp		= __pi_strncmp);
PROVIDE(__efistub_strrchr		= __pi_strrchr);
PROVIDE(__efistub_dcache_clean_poc	= __pi_dcache_clean_poc);

PROVIDE(__efistub__text			= _text);
PROVIDE(__efistub__end			= _end);
PROVIDE(__efistub__edata		= _edata);
PROVIDE(__efistub_screen_info		= screen_info);
PROVIDE(__efistub__ctype		= _ctype);

/*
 * The __ prefixed memcpy/memset/memmove symbols are provided by KASAN, which
 * instruments the conventional ones. Therefore, any references from the EFI
 * stub or other position independent, low level C code should be redirected to
 * the non-instrumented versions as well.
 */
PROVIDE(__efistub___memcpy		= __pi_memcpy);
PROVIDE(__efistub___memmove		= __pi_memmove);
PROVIDE(__efistub___memset		= __pi_memset);

PROVIDE(__pi___memcpy			= __pi_memcpy);
PROVIDE(__pi___memmove			= __pi_memmove);
PROVIDE(__pi___memset			= __pi_memset);

#ifdef CONFIG_KVM

/*
 * KVM nVHE code has its own symbol namespace prefixed with __kvm_nvhe_, to
 * separate it from the kernel proper. The following symbols are legally
 * accessed by it, therefore provide aliases to make them linkable.
 * Do not include symbols which may not be safely accessed under hypervisor
 * memory mappings.
 */

/* Alternative callbacks for init-time patching of nVHE hyp code. */
KVM_NVHE_ALIAS(kvm_patch_vector_branch);
KVM_NVHE_ALIAS(kvm_update_va_mask);
KVM_NVHE_ALIAS(kvm_get_kimage_voffset);
KVM_NVHE_ALIAS(kvm_compute_final_ctr_el0);
KVM_NVHE_ALIAS(spectre_bhb_patch_loop_iter);
KVM_NVHE_ALIAS(spectre_bhb_patch_loop_mitigation_enable);
KVM_NVHE_ALIAS(spectre_bhb_patch_wa3);
KVM_NVHE_ALIAS(spectre_bhb_patch_clearbhb);

/* Global kernel state accessed by nVHE hyp code. */
KVM_NVHE_ALIAS(kvm_vgic_global_state);

/* Kernel symbols used to call panic() from nVHE hyp code (via ERET). */
KVM_NVHE_ALIAS(nvhe_hyp_panic_handler);

/* Vectors installed by hyp-init on reset HVC. */
KVM_NVHE_ALIAS(__hyp_stub_vectors);

/* Kernel symbol used by icache_is_vpipt(). */
KVM_NVHE_ALIAS(__icache_flags);

/* VMID bits set by the KVM VMID allocator */
KVM_NVHE_ALIAS(kvm_arm_vmid_bits);

/* Kernel symbols needed for cpus_have_final/const_caps checks. */
KVM_NVHE_ALIAS(arm64_const_caps_ready);
KVM_NVHE_ALIAS(cpu_hwcap_keys);

/* Static keys which are set if a vGIC trap should be handled in hyp. */
KVM_NVHE_ALIAS(vgic_v2_cpuif_trap);
KVM_NVHE_ALIAS(vgic_v3_cpuif_trap);

/* Static key checked in pmr_sync(). */
#ifdef CONFIG_ARM64_PSEUDO_NMI
KVM_NVHE_ALIAS(gic_pmr_sync);
/* Static key checked in GIC_PRIO_IRQOFF. */
KVM_NVHE_ALIAS(gic_nonsecure_priorities);
#endif

/* EL2 exception handling */
KVM_NVHE_ALIAS(__start___kvm_ex_table);
KVM_NVHE_ALIAS(__stop___kvm_ex_table);

/* Array containing bases of nVHE per-CPU memory regions. */
KVM_NVHE_ALIAS(kvm_arm_hyp_percpu_base);

/* PMU available static key */
#ifdef CONFIG_HW_PERF_EVENTS
KVM_NVHE_ALIAS(kvm_arm_pmu_available);
#endif

/* Position-independent library routines */
KVM_NVHE_ALIAS_HYP(clear_page, __pi_clear_page);
KVM_NVHE_ALIAS_HYP(copy_page, __pi_copy_page);
KVM_NVHE_ALIAS_HYP(memcpy, __pi_memcpy);
KVM_NVHE_ALIAS_HYP(memset, __pi_memset);

#ifdef CONFIG_KASAN
KVM_NVHE_ALIAS_HYP(__memcpy, __pi_memcpy);
KVM_NVHE_ALIAS_HYP(__memset, __pi_memset);
#endif

/* Kernel memory sections */
KVM_NVHE_ALIAS(__start_rodata);
KVM_NVHE_ALIAS(__end_rodata);
KVM_NVHE_ALIAS(__bss_start);
KVM_NVHE_ALIAS(__bss_stop);

/* Hyp memory sections */
KVM_NVHE_ALIAS(__hyp_idmap_text_start);
KVM_NVHE_ALIAS(__hyp_idmap_text_end);
KVM_NVHE_ALIAS(__hyp_text_start);
KVM_NVHE_ALIAS(__hyp_text_end);
KVM_NVHE_ALIAS(__hyp_bss_start);
KVM_NVHE_ALIAS(__hyp_bss_end);
KVM_NVHE_ALIAS(__hyp_rodata_start);
KVM_NVHE_ALIAS(__hyp_rodata_end);

/* pKVM static key */
KVM_NVHE_ALIAS(kvm_protected_mode_initialized);

#endif /* CONFIG_KVM */

#endif /* __ARM64_KERNEL_IMAGE_VARS_H */
